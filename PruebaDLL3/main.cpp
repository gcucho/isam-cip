#include "main.h"
#include <fstream>
#include "opencv2/opencv_modules.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/detail/autocalib.hpp"
#include "opencv2/stitching/detail/blenders.hpp"
#include "opencv2/stitching/detail/camera.hpp"
#include "opencv2/stitching/detail/exposure_compensate.hpp"
#include "opencv2/stitching/detail/matchers.hpp"
#include "opencv2/stitching/detail/motion_estimators.hpp"
#include "opencv2/stitching/detail/seam_finders.hpp"
#include "opencv2/stitching/detail/util.hpp"
#include "opencv2/stitching/detail/warpers.hpp"
#include "opencv2/stitching/warpers.hpp"

using namespace std;
using namespace cv;
using namespace cv::detail;

Stitching::Stitching()
{}

Stitching::~Stitching()
{}

bool Stitching::SetParameters(DataParam * dataparamsQT)
{
    //Copying params from QT
    dataParamDLL.wmpx_f       = dataparamsQT->wmpx_f;
    dataParamDLL.matchconf_f  = dataparamsQT->matchconf_f;
    dataParamDLL.confthres_f  = dataparamsQT->confthres_f;
    dataParamDLL.seam_mpx     = dataparamsQT->seam_mpx;
    dataParamDLL.compsmpx_f   = dataparamsQT->compsmpx_f;
    dataParamDLL.blendstrn_f  = dataparamsQT->blendstrn_f;
    dataParamDLL.output_s     = (std::string)dataparamsQT->output_s;
    dataParamDLL.bamask_s     = (std::string)dataparamsQT->bamask_s;
    dataParamDLL.savegrph_s   = (std::string)dataparamsQT->savegrph_s;
    dataParamDLL.try_gpu_i    = dataparamsQT->try_gpu_i;
    dataParamDLL.bundleadj_i  = dataparamsQT->bundleadj_i;
    dataParamDLL.wavecorr_i   = dataparamsQT->wavecorr_i;
    dataParamDLL.blend_i      = dataparamsQT->blend_i;
    dataParamDLL.expcomp_i    = dataparamsQT->expcomp_i;
    dataParamDLL.seam_i       = dataparamsQT->seam_i;
    dataParamDLL.warp_i       = dataparamsQT->warp_i;
    dataParamDLL.imgfiles_names = (std::vector<std::string>) dataparamsQT->imgfiles_names;

    //Logging parameters data//
    SaveParameters();

    return true;
}

bool Stitching::SaveParameters(void)
{
    FILE *pfile;
    pfile = fopen("log_parameters.txt","w");
    fprintf(pfile,"wmpx_f: %f\n",dataParamDLL.wmpx_f);
    fprintf(pfile,"matchconf_f: %f\n",dataParamDLL.matchconf_f);
    fprintf(pfile,"confthres_f: %f\n",dataParamDLL.confthres_f);
    fprintf(pfile,"seam_mpx: %f\n",dataParamDLL.seam_mpx);
    fprintf(pfile,"compsmpx_f: %f\n",dataParamDLL.compsmpx_f);
    fprintf(pfile,"blendstrn_f: %f\n",dataParamDLL.blendstrn_f);
    fprintf(pfile,"output_s: %s\n",dataParamDLL.output_s.c_str());
    fprintf(pfile,"bamask_s: %s\n",dataParamDLL.bamask_s.c_str());
    fprintf(pfile,"savegrph_s: %s\n",dataParamDLL.savegrph_s.c_str());
    fprintf(pfile,"try_gpu_i: %d\n",dataParamDLL.try_gpu_i);
    fprintf(pfile,"bundleadj_i: %d\n",dataParamDLL.bundleadj_i);
    fprintf(pfile,"wavecorr_i: %d\n",dataParamDLL.wavecorr_i);
    fprintf(pfile,"blend_i: %d\n",dataParamDLL.blend_i);
    fprintf(pfile,"expcomp_i: %d\n",dataParamDLL.expcomp_i);
    fprintf(pfile,"seam_i: %d\n",dataParamDLL.seam_i);
    fprintf(pfile,"warp_i: %d\n",dataParamDLL.warp_i);
    fprintf(pfile,"Images to process:\n");

    for (int i=0;i<dataParamDLL.imgfiles_names.size();i++)
    {
      fprintf(pfile,"%s\n",dataParamDLL.imgfiles_names.at(i).c_str());
    }


    fclose(pfile);

    return true;
}

int Stitching::test(int x)
{
//   printf("D:%d\n",x+2);
   return x;
}

 bool Stitching::MainProcess(int * err)
 {

    // 1st Part //
    bool do_wave_correct=true;
    WaveCorrectKind wave_correct = detail::WAVE_CORRECT_HORIZ;
    int expos_comp_type = ExposureCompensator::GAIN_BLOCKS;
    int blend_type = Blender::MULTI_BAND;

    //WaveCorrect
    if(dataParamDLL.wavecorr_i == 0)
    {
        do_wave_correct = false;
    }
    else if(dataParamDLL.wavecorr_i == 1)
    {
        do_wave_correct = true;
        wave_correct = detail::WAVE_CORRECT_HORIZ;
    }
    else
    {
        do_wave_correct = true;
        wave_correct = detail::WAVE_CORRECT_VERT;
    }

    //Expo Comp
    if(dataParamDLL.expcomp_i == 0) expos_comp_type = ExposureCompensator::GAIN_BLOCKS;
    else if(dataParamDLL.expcomp_i == 1) expos_comp_type = ExposureCompensator::GAIN;
    else expos_comp_type = ExposureCompensator::NO;

    //Blender Type
    if(dataParamDLL.blend_i == 0) blend_type = Blender::MULTI_BAND;
    else if(dataParamDLL.blend_i == 1) blend_type = Blender::FEATHER;
    else blend_type = Blender::NO;

    //// 2nd Part ///
    int num_images = static_cast<int> (dataParamDLL.imgfiles_names.size());

    double work_scale = 1, seam_scale=1,compose_scale=1;
    bool is_work_scale_set=false,is_seam_scale_set=false,is_compose_scale_set=false;
    bool save_graph=true;


    Ptr<FeaturesFinder> finder;
    finder = new OrbFeaturesFinder();

    Mat full_img, img;
    vector<ImageFeatures> features(num_images);
    vector<Mat> images(num_images);
    vector<Size> full_img_sizes(num_images);
    double seam_work_aspect=1;

    for(int i=0;i<num_images;++i)
    {
        full_img = imread(dataParamDLL.imgfiles_names[i]);
        full_img_sizes[i]=full_img.size();

        if(full_img.empty())
        {
            return false;
        }

        // Setting WMPX
        if(dataParamDLL.wmpx_f<0)
        {
            img = full_img;
            work_scale = 1;
            is_work_scale_set = true;
        }
        else
        {
            if(!is_work_scale_set)
            {
                work_scale=min(1.0,sqrt(dataParamDLL.wmpx_f*1e6/full_img.size().area()));
                is_work_scale_set=true;
            }
            resize(full_img,img,Size(),work_scale,work_scale);
        }

        // Setting SEAM
        if(!is_seam_scale_set)
        {
            seam_scale = min(1.0,sqrt(dataParamDLL.seam_mpx*1e6/full_img.size().area()));
            seam_work_aspect = seam_scale/work_scale;
            is_seam_scale_set = true;
        }

        (*finder)(img,features[i]);
        features[i].img_idx = i;

        resize(full_img,img,Size(),seam_scale,seam_scale);
        images[i]=img.clone();
    }

    finder->collectGarbage();
    full_img.release();
    img.release();

    vector<MatchesInfo> pairwise_matches;
    BestOf2NearestMatcher matcher(false,dataParamDLL.matchconf_f);
    matcher(features, pairwise_matches);
    matcher.collectGarbage();

    if(save_graph)
    {
        ofstream f(dataParamDLL.savegrph_s.c_str());
        f<<matchesGraphAsString(dataParamDLL.imgfiles_names,pairwise_matches,dataParamDLL.confthres_f);
    }

    //Leave only images we are sure are from the same panorama//
    vector<int> indices = leaveBiggestComponent(features,pairwise_matches,dataParamDLL.confthres_f);
    vector<Mat> img_subset;
    vector<string> img_names_subset;
    vector<Size> full_img_sizes_subset;

    for(size_t i=0; i<indices.size();++i)
    {
        img_names_subset.push_back(dataParamDLL.imgfiles_names[indices[i]]);
        img_subset.push_back(images[indices[i]]);
        full_img_sizes_subset.push_back(full_img_sizes[indices[i]]);
    }

    images = img_subset;
    dataParamDLL.imgfiles_names = img_names_subset;
    full_img_sizes = full_img_sizes_subset;

    //Check if we still have enough images
    num_images = static_cast<int>(dataParamDLL.imgfiles_names.size());
    if(num_images<2)
    {
       *err = 1; // There is not enough images.
       return false;
    }

    HomographyBasedEstimator estimator;
    vector<CameraParams> cameras;
    estimator(features,pairwise_matches,cameras);

    for(size_t i=0; i<cameras.size();++i)
    {
        Mat R;
        cameras[i].R.convertTo(R,CV_32F);
        cameras[i].R = R;
    }

    Ptr<detail::BundleAdjusterBase> adjuster;
    if( dataParamDLL.bundleadj_i == 0 )
        adjuster = new detail::BundleAdjusterRay();
    else
        adjuster = new detail::BundleAdjusterReproj();

    adjuster->setConfThresh(dataParamDLL.confthres_f);
    Mat_<uchar> refine_mask = Mat::zeros(3,3,CV_8U);
    if(dataParamDLL.bamask_s[0] == 'X') refine_mask(0,0)=1;
    if(dataParamDLL.bamask_s[1] == 'X') refine_mask(0,1)=1;
    if(dataParamDLL.bamask_s[2] == 'X') refine_mask(0,2)=1;
    if(dataParamDLL.bamask_s[3] == 'X') refine_mask(1,1)=1;
    if(dataParamDLL.bamask_s[4] == 'X') refine_mask(1,2)=1;
    adjuster->setRefinementMask(refine_mask);
    (*adjuster)(features, pairwise_matches, cameras);

    //Find median focal legth

    vector<double> focals;
    for (size_t i=0; i<cameras.size();++i)
    {
        focals.push_back(cameras[i].focal);
    }

    sort(focals.begin(),focals.end());
    float warped_image_scale;
    if(focals.size()%2 == 1)
        warped_image_scale=static_cast<float>(focals[focals.size()/2]);
    else
        warped_image_scale=static_cast<float>(focals[focals.size()/2-1]+focals[focals.size()/2])*0.5f;

    if(do_wave_correct)
    {
        vector<Mat> rmats;
        for(size_t i=0; i< cameras.size();++i)
            rmats.push_back(cameras[i].R);
        waveCorrect(rmats,wave_correct);
        for(size_t i=0; i<cameras.size();++i)
            cameras[i].R = rmats[i];
    }

    vector<Point> corners(num_images);
    vector<Mat> masks_warped(num_images);
    vector<Mat> images_warped(num_images);
    vector<Size> sizes(num_images);
    vector<Mat> masks(num_images);

    // Preapre images masks
    for (int i = 0; i < num_images; ++i)
    {
        masks[i].create(images[i].size(), CV_8U);
        masks[i].setTo(Scalar::all(255));
    }

    Ptr<WarperCreator> warper_creator;

    if(dataParamDLL.warp_i == 0) warper_creator = new cv::PlaneWarper();
    else if (dataParamDLL.warp_i == 1) warper_creator = new cv::CylindricalWarper();
    else if (dataParamDLL.warp_i == 2) warper_creator = new cv::SphericalWarper();
    else if (dataParamDLL.warp_i == 3) warper_creator = new cv::FisheyeWarper();
    else warper_creator = new cv::StereographicWarper();

    if (warper_creator.empty())
    {
        *err = 2;
        return false;
    }

    Ptr<RotationWarper> warper = warper_creator->create(static_cast<float>(warped_image_scale * seam_work_aspect));

    for (int i = 0; i < num_images; ++i)
    {
        Mat_<float> K;
        cameras[i].K().convertTo(K, CV_32F);
        float swa = (float)seam_work_aspect;
        K(0,0) *= swa; K(0,2) *= swa;
        K(1,1) *= swa; K(1,2) *= swa;

        corners[i] = warper->warp(images[i], K, cameras[i].R, INTER_LINEAR, BORDER_REFLECT, images_warped[i]);
        sizes[i] = images_warped[i].size();

        warper->warp(masks[i], K, cameras[i].R, INTER_NEAREST, BORDER_CONSTANT, masks_warped[i]);
    }

    vector<Mat> images_warped_f(num_images);
    for (int i = 0; i < num_images; ++i)
        images_warped[i].convertTo(images_warped_f[i], CV_32F);

    Ptr<ExposureCompensator> compensator = ExposureCompensator::createDefault(expos_comp_type);
    compensator->feed(corners, images_warped, masks_warped);

    Ptr<SeamFinder> seam_finder;
    if(dataParamDLL.seam_i == 0) seam_finder = new detail::GraphCutSeamFinder(GraphCutSeamFinderBase::COST_COLOR);
    else if(dataParamDLL.seam_i == 1) seam_finder = new detail::GraphCutSeamFinder(GraphCutSeamFinderBase::COST_COLOR_GRAD);
    else if(dataParamDLL.seam_i == 2) seam_finder = new detail::VoronoiSeamFinder();
    else seam_finder = new detail::NoSeamFinder();

    if (seam_finder.empty())
    {
        *err = 3;
        return false;
    }

    seam_finder->find(images_warped_f, corners, masks_warped);

     // Release unused memory
    images.clear();
    images_warped.clear();
    images_warped_f.clear();
    masks.clear();

    // COMPOSITING
    Mat img_warped, img_warped_s;
    Mat dilated_mask, seam_mask, mask, mask_warped;
    Ptr<Blender> blender;
    //double compose_seam_aspect = 1;
    double compose_work_aspect = 1;

    for (int img_idx = 0; img_idx < num_images; ++img_idx)
    {
        full_img = imread(dataParamDLL.imgfiles_names[img_idx]);
        if (!is_compose_scale_set)
        {
            if (dataParamDLL.compsmpx_f > 0)
                compose_scale = min(1.0, sqrt(dataParamDLL.compsmpx_f * 1e6 / full_img.size().area()));
            is_compose_scale_set = true;

            // Compute relative scales
            //compose_seam_aspect = compose_scale / seam_scale;
            compose_work_aspect = compose_scale / work_scale;

            // Update warped image scale
            warped_image_scale *= static_cast<float>(compose_work_aspect);
            warper = warper_creator->create(warped_image_scale);

            // Update corners and sizes
            for (int i = 0; i < num_images; ++i)
            {
                // Update intrinsics
                cameras[i].focal *= compose_work_aspect;
                cameras[i].ppx *= compose_work_aspect;
                cameras[i].ppy *= compose_work_aspect;

                // Update corner and size
                Size sz = full_img_sizes[i];
                if (std::abs(compose_scale - 1) > 1e-1)
                {
                    sz.width = cvRound(full_img_sizes[i].width * compose_scale);
                    sz.height = cvRound(full_img_sizes[i].height * compose_scale);
                }

                Mat K;
                cameras[i].K().convertTo(K, CV_32F);
                Rect roi = warper->warpRoi(sz, K, cameras[i].R);
                corners[i] = roi.tl();
                sizes[i] = roi.size();
            }
        }

        if (abs(compose_scale - 1) > 1e-1)
            resize(full_img, img, Size(), compose_scale, compose_scale);
        else
            img = full_img;
        full_img.release();
        Size img_size = img.size();

        Mat K;
        cameras[img_idx].K().convertTo(K, CV_32F);

        // Warp the current image
        warper->warp(img, K, cameras[img_idx].R, INTER_LINEAR, BORDER_REFLECT, img_warped);

        // Warp the current image mask
        mask.create(img_size, CV_8U);
        mask.setTo(Scalar::all(255));
        warper->warp(mask, K, cameras[img_idx].R, INTER_NEAREST, BORDER_CONSTANT, mask_warped);

        // Compensate exposure
        compensator->apply(img_idx, corners[img_idx], img_warped, mask_warped);

        img_warped.convertTo(img_warped_s, CV_16S);
        img_warped.release();
        img.release();
        mask.release();

        dilate(masks_warped[img_idx], dilated_mask, Mat());
        resize(dilated_mask, seam_mask, mask_warped.size());
        mask_warped = seam_mask & mask_warped;

        if(blender.empty())
        {
            blender = Blender::createDefault(blend_type,false);
            Size dst_sz = resultRoi(corners,sizes).size();
            float blend_width = sqrt(static_cast<float>(dst_sz.area())) * dataParamDLL.blendstrn_f / 100.f;
            if (blend_width < 1.f)
                blender = Blender::createDefault(Blender::NO, false);
            else if (blend_type == Blender::MULTI_BAND)
            {
                MultiBandBlender* mb = dynamic_cast<MultiBandBlender*>(static_cast<Blender*>(blender));
                mb->setNumBands(static_cast<int>(ceil(log(blend_width)/log(2.)) - 1.));
            }
            else if (blend_type == Blender::FEATHER)
            {
                FeatherBlender* fb = dynamic_cast<FeatherBlender*>(static_cast<Blender*>(blender));
                fb->setSharpness(1.f/blend_width);
            }
            blender->prepare(corners, sizes);
        }

        //Blend the current image
        blender->feed(img_warped_s,mask_warped,corners[img_idx]);
    }

    Mat result,result_mask;
    blender->blend(result,result_mask);
    imwrite(dataParamDLL.output_s,result);

    return true;
 }

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
