#include "dialog.h"
#include "ui_dialog.h"
#include "main.h"
#include "thread.h"
#include "structures.h"

#include <QMessageBox>
#include <QFileDialog>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Initialize combo boxes
    ui->cb_trygpu->addItem("No");
    ui->cb_trygpu->addItem("Yes");

    ui->cb_bundleadj->addItem("Ray");
    ui->cb_bundleadj->addItem("Reproj");

    ui->cb_wavecorrect->addItem("No");
    ui->cb_wavecorrect->addItem("Horiz");
    ui->cb_wavecorrect->addItem("Vert");

    ui->cb_warp->addItem("Plane");
    ui->cb_warp->addItem("Cylindrical");
    ui->cb_warp->addItem("Spherical");
    ui->cb_warp->addItem("Fisheye");
    ui->cb_warp->addItem("Stereographic");

    ui->cb_seam->addItem("Gc_color");
    ui->cb_seam->addItem("Gc_colorgrad");
    ui->cb_seam->addItem("Voronoi");
    ui->cb_seam->addItem("No");

    ui->cb_expocomp->addItem("Gain_blocks");
    ui->cb_expocomp->addItem("Gain");
    ui->cb_expocomp->addItem("No");

    ui->cb_blend->addItem("Multiband");
    ui->cb_blend->addItem("Feather");
    ui->cb_blend->addItem("No");

    // Initialize Font Title
    QFont font = ui->l_title->font();
    font.setPointSize(16);
    font.setBold(true);
    ui->l_title->setFont(font);

    // Initialize Graphics
    scene = new QGraphicsScene(this);

    // Initialize ListView
    ui->lst_imagefile->setModel(new QStringListModel(m_slData));

    // Initialize Thread
    mythread = new Thread(this);

    // Initialize Data Param struct
    dataParam = new DataParam();

    // Initialize connection between Dialog and Qthread
    connect(this,SIGNAL(ParamsChanged(DataParam*)),mythread,SLOT(UpdateParams(DataParam*))); // For Updating
    connect(mythread,SIGNAL(valueDisplayChanged(int)),this,SLOT(UpdateDisplay(int))); // For Display text box

    // Initialize Show Result Button
    ui->pb_showresult->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_addimage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Files"),"",tr("BMP(*.bmp);;JPEG(*.jpg *.jpeg);;All file (*.*)"));
    if(fileName!="")
    {
        m_slData.append(fileName);
        ((QStringListModel*) ui->lst_imagefile->model())->setStringList(m_slData);
    }
}

void Dialog::on_pb_deleteitem_clicked()
{

    QModelIndexList index = ui->lst_imagefile->selectionModel()->selectedIndexes();
    if(!index.isEmpty())
    {
        ui->lst_imagefile->model()->removeRow(index.at(0).row()); //Remover en el listview
        m_slData.removeAt(index.at(0).row());                     // Remover en la lista de strings
    }
    scene->clear();
}

void Dialog::on_pb_deleteall_clicked()
{
    int cont_data = m_slData.count();

    if(cont_data>0)
    {
        for(int i=0;i<cont_data;i++)
        {
            m_slData.removeLast();
        }
        ((QStringListModel*) ui->lst_imagefile->model())->setStringList(m_slData);
    }

    scene->clear();
}

void Dialog::on_pb_generate_clicked()
{
    //ui->te_display->clear();

    // Obtaining values from parameter's section
    dataParam->wmpx_f       = ui->le_wmpx->text().toFloat();
    dataParam->matchconf_f  = ui->le_match->text().toFloat();
    dataParam->confthres_f  = ui->le_confthrsh->text().toFloat();
    dataParam->seam_mpx     = ui->le_seammpx->text().toFloat();
    dataParam->compsmpx_f   = ui->le_compsmpx->text().toFloat();
    dataParam->blendstrn_f  = ui->le_blendstrn->text().toFloat();
    dataParam->output_s     = ui->le_output->text().toStdString();
    dataParam->bamask_s     = ui->le_bamask->text().toStdString();
    dataParam->savegrph_s   = ui->le_savegrph->text().toStdString();
    dataParam->try_gpu_i    = ui->cb_trygpu->currentIndex();
    dataParam->bundleadj_i  = ui->cb_bundleadj->currentIndex();
    dataParam->wavecorr_i   = ui->cb_wavecorrect->currentIndex();
    dataParam->blend_i      = ui->cb_blend->currentIndex();
    dataParam->expcomp_i    = ui->cb_expocomp->currentIndex();
    dataParam->seam_i       = ui->cb_seam->currentIndex();
    dataParam->warp_i       = ui->cb_warp->currentIndex();

    dataParam->imgfiles_names.clear();
    // Obtaining image files
    if(m_slData.isEmpty()|| m_slData.count()<2)
    {
        QMessageBox::warning(this,"Warning","The process needs more than 1 image",QMessageBox::Ok);
        return;
    }
    else
    {
        for(int i=0;i<m_slData.count();i++)
        {
            dataParam->imgfiles_names.push_back(m_slData.at(i).toStdString());
        }
    }

    // Update Params in Thread
    emit ParamsChanged(dataParam);

    //Delay!

    // Start Thread **run()**
    mythread->start();
}

void Dialog::on_lst_imagefile_clicked(const QModelIndex &index)
{
    QString filename;
    QPixmap pixmp;
    filename = m_slData.at(index.row());
    pixmp = QPixmap(filename);
    scene->clear();
    scene->addPixmap(pixmp);
    scene->setSceneRect(0,0,pixmp.width(),pixmp.height());
    ui->graphicsView->setScene(scene);
//    QRectF bounds = scene->itemsBoundingRect();
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::IgnoreAspectRatio);
}

void Dialog::UpdateDisplay(int disp)
{
    switch (disp)
    {
        case 0: ui->te_display->append(QString ("Loading data from GUI form ... Done!"));
                break;
        case 1: ui->te_display->append(QString ("Log file saved with parameters ...Done!"));
                break;
        case 2: ui->te_display->append(QString ("Wait for processing ..... "));
                break;
        case 3: ui->te_display->append(QString ("Image stitching Succesful!"));
                ui->te_display->append(QString ("Saving results .. done!"));
                ui->pb_showresult->setEnabled(true);
                break;
        case 10: ui->te_display->append(QString ("ERROR 10: Not enough correlated images!"));
                break;
        case 11: ui->te_display->append(QString ("ERROR 11:"));
                break;
        case 12: ui->te_display->append(QString ("ERROR 12:"));
                break;
        case 13: ui->te_display->append(QString ("ERROR 13:"));
                break;
        case 14: ui->te_display->append(QString ("ERROR 14: General Error!"));
                break;
    }
}

void Dialog::on_pb_showresult_clicked()
{

    QString filename;
    QPixmap pixmp;
    //filename = m_slData.at(index.row());
    pixmp = QPixmap(ui->le_output->text());
    scene->clear();
    scene->addPixmap(pixmp);
    scene->setSceneRect(0,0,pixmp.width(),pixmp.height());
    ui->graphicsView->setScene(scene);
//    QRectF bounds = scene->itemsBoundingRect();
    ui->graphicsView->fitInView(scene->sceneRect(),Qt::IgnoreAspectRatio);

}
