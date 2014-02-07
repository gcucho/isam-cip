#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <vector>
#include <string>

struct DataParam {
    float wmpx_f;
    float matchconf_f;
    float confthres_f;
    float seam_mpx;
    float compsmpx_f;
    float blendstrn_f;
    std::string output_s;
    std::string bamask_s;
    std::string savegrph_s;
    int try_gpu_i;
    int bundleadj_i;
    int wavecorr_i;
    int blend_i;
    int expcomp_i;
    int seam_i;
    int warp_i;
    std::vector<std::string> imgfiles_names;
};

#endif // STRUCTURES_H
