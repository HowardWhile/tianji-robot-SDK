#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FXCommon.h"
#include "FXErrorCode.h"
#include <QDebug>
#include "TrajTable.h"

#define OneBeat 1
#define halfBeat 0.5
#define twoBeat 2
#define up 10
#define down 11
double left_set_halfbeat[150][2000];
int    left_set_half_num[150];
double left_set_onebeat[150][2000];
int    left_set_one_num[150];
double left_set_twobeat[150][2000];
int    left_set_two_num[150];
double left_set_oneandhalfbeat[150][2000];
int    left_set_oneandhalf_num[150];

double right_set_halfbeat[170][2000];
int    right_set_half_num[170];
double right_set_onebeat[170][2000];
int    right_set_one_num[170];
double right_set_twobeat[170][2000];
int    right_set_two_num[170];
double right_set_oneandhalfbeat[170][2000];
int    right_set_oneandhalf_num[170];
static  int song_num = 0;
static bool m_bRunTraj;
static FX_MotionHandle handle;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    memset(left_set_halfbeat, 0, sizeof(left_set_halfbeat));
    memset(left_set_onebeat, 0, sizeof(left_set_onebeat));
    memset(left_set_twobeat, 0, sizeof(left_set_twobeat));
    memset(left_set_oneandhalfbeat, 0, sizeof(left_set_oneandhalfbeat));
    memset(right_set_halfbeat, 0, sizeof(right_set_halfbeat));
    memset(right_set_onebeat, 0, sizeof(right_set_onebeat));
    memset(right_set_twobeat, 0, sizeof(right_set_twobeat));
    memset(right_set_oneandhalfbeat, 0, sizeof(right_set_oneandhalfbeat));

    m_Timer = new QTimer(this);
    m_bRunTraj = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void FillInverseKinematicsInput(FX_InvKineSolvePara *ik_params,
                                       double ref_joints[7],
                                       double target_pose[4][4],
                                       int zsp_type = 0,
                                       const double *zsp_para = nullptr)
{
    int row = 0;
    int col = 0;
    FX_InvKineSolvePara zero_ik_params;
    memset(&zero_ik_params, 0, sizeof(FX_InvKineSolvePara));

    *ik_params = zero_ik_params;
    /* Set reference joints */
    for (row = 0; row < 7; ++row)
    {
        ik_params->m_Input_IK_RefJoint[row] = ref_joints[row];
    }

    /* Set target pose matrix*/
    for (row = 0; row < 4; ++row)
    {
        for (col = 0; col < 4; ++col)
        {
            ik_params->m_Input_IK_TargetTCP[row][col] = target_pose[row][col];
        }
    }

    /* Set ZSP parameters */
    ik_params->m_Input_IK_ZSPType = zsp_type;
    if (zsp_para != nullptr)
    {
        for (row = 0; row < 6; ++row)
        {
            ik_params->m_Input_IK_ZSPPara[row] = zsp_para[row];
        }
    }
}


void PrintJointPosition(const char *name, double joints[7])
{
    QString str;
    for (int i = 0; i < 7; ++i)
    {
        if (i > 0)
            str += ", ";
        str += QString::number(joints[i], 'f', 4);
    }
    qDebug() << QString("%1 %2").arg(name).arg(str);
}

void PrintJointPosition14(const char *name, double joints[14])
{
    QString str;
    for (int i = 0; i < 14; ++i)
    {
        if (i > 0)
            str += ", ";
        str += QString::number(joints[i], 'f', 4);
    }
    qDebug() << QString("{%1}").arg(str);
}

void MainWindow::on_pushButton_8_clicked()
{
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[0].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }


    PrintJointPosition("ARM1",left_pos[0].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[0].jointpos, left_pos[0].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }
}

void MainWindow::on_pushButton_7_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[1].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[1].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[1].jointpos, left_pos[1].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);        
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[2].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[2].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[2].jointpos, left_pos[2].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }  
}

void MainWindow::on_pushButton_5_clicked()
{  
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[3].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[3].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[3].jointpos, left_pos[3].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[4].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[4].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[4].jointpos, left_pos[4].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }   
}

void MainWindow::on_pushButton_3_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[5].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[5].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[5].jointpos, left_pos[5].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();    

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[6].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[6].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[6].jointpos, left_pos[6].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }
}

void MainWindow::on_pushButton_clicked()
{ 
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();
    //结构体清零

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[0].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[0].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[0].jointpos, right_pos[0].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_10_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT(); 

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[1].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[1].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[1].jointpos, right_pos[1].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_12_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[2].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[2].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[2].jointpos, right_pos[2].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_9_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[3].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[3].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[3].jointpos, right_pos[3].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }   
}

void MainWindow::on_pushButton_14_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();
    //结构体清零

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[4].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[4].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[4].jointpos, right_pos[4].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }
}

void MainWindow::on_pushButton_13_clicked()
{  
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();  

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[5].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[5].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[5].jointpos, right_pos[5].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        printf("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }   
}

void MainWindow::on_pushButton_15_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[6].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[6].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[6].jointpos, right_pos[6].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_11_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[7].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[7].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[7].jointpos, right_pos[7].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }   
}

void MainWindow::on_pushButton_16_clicked()
{
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();    

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[7].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[7].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[7].jointpos, left_pos[7].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_17_clicked()
{
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();    

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[8].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[8].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[8].jointpos, left_pos[8].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_18_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();    

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[9].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[9].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[9].jointpos, left_pos[9].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_19_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();    

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[10].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[10].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[10].jointpos, left_pos[10].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_20_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         left_pos[11].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",left_pos[11].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[11].jointpos, left_pos[11].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }
}

void MainWindow::on_pushButton_21_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[8].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[8].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[8].jointpos, right_pos[8].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_22_clicked()
{    
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[9].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[9].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[9].jointpos, right_pos[9].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        printf("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }    
}

void MainWindow::on_pushButton_23_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();    

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[10].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[10].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[10].jointpos,right_pos[10].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        printf("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);        
    }    
}

void MainWindow::on_pushButton_24_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[11].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[11].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[11].jointpos, right_pos[11].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        printf("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);       
    }    
}

void MainWindow::on_pushButton_25_clicked()
{   
    int err_code = 0;
    const ROBOT_RT * rt  = FX_L1_Fbk_GetRT();   

    for(FX_INT32 i =0; i<7;i++)
    {
         right_pos[12].jointpos[i] = rt->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
    }
    PrintJointPosition("ARM1",right_pos[12].jointpos);
    FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[12].jointpos, right_pos[12].startcp);
    if (err_code != FUNC_RET_SUCCESS)
    {
        printf("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);        
    }    
}

//void MainWindow::on_pushButton_26_clicked()
//{
//    unsigned int log_level = FX_LOG_DEBG_FLAG;
//    int ret=FX_L1_System_Link(6,6,7,190,log_level);
//    if (ret < 0)
//    {
//        qDebug("Failed to link system\n");
//    }else
//    {
//        qDebug("Success to link system\n");
//    }
//    handle = FX_L1_Kinematics_Create();
//    if (!handle)
//    {
//        qDebug("Failed to create kinematics context\n");
//    }
//    FX_L1_Kinematics_SetLogLevel(FX_LOG_DEBG_FLAG);
//    int err_code = FX_L1_Kinematics_InitSingleArm_ByIniConfig(handle, 1);
//    if (err_code != FUNC_RET_SUCCESS)
//    {
//        qDebug("Failed to initialize ARM1 kinematics from ini configuration. Error code: %d\n", err_code);
//        FX_L1_Kinematics_Destroy(handle);
//    }
//}

void MainWindow::on_pushButton_26_clicked()
{
    unsigned int log_level = FX_LOG_DEBG_FLAG;
    int ret=FX_L1_System_Link(6,6,7,190,log_level);
    if (ret < 0)
    {
        qDebug("Failed to link system\n");
        // 连接失败：按钮变红色
        ui->pushButton_26->setStyleSheet("QPushButton{background-color:#e74c3c; color:white; border-radius:8px; padding:8px 16px;}");
        QMessageBox::critical(this, "连接失败", "无法连接到系统，请检查:\n1. 设备是否开机\n2. 网络是否正常\n3. IP/端口是否正确");
        return;
    }else
    {
        qDebug("Success to link system\n");
        // 连接成功：按钮变绿色
        ui->pushButton_26->setStyleSheet(
            "QPushButton{background-color:#27ae60; color:white; border-radius:8px; padding:8px 16px;}"
            "QPushButton:hover{background-color:#2ecc71;}");
        QMessageBox::information(this, "连接成功", "系统连接成功！");
    }
    handle = FX_L1_Kinematics_Create();
    if (!handle)
    {
        qDebug("Failed to create kinematics context\n");
        // 运动学上下文创建失败：按钮变橙色警告
        ui->pushButton_26->setStyleSheet("QPushButton{background-color:#e67e22; color:white; border-radius:8px; padding:8px 16px;}");
        QMessageBox::warning(this, "警告", "连接成功，但创建运动学上下文失败");
        return;
    }
    FX_L1_Kinematics_SetLogLevel(FX_LOG_DEBG_FLAG);
    int err_code = FX_L1_Kinematics_InitSingleArm_ByIniConfig(handle, 1);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to initialize ARM1 kinematics from ini configuration. Error code: %d\n", err_code);
        FX_L1_Kinematics_Destroy(handle);
        // 初始化失败：按钮变橙色警告
        ui->pushButton_26->setStyleSheet( "QPushButton{background-color:#e67e22; color:white; border-radius:8px; padding:8px 16px;}");
        QMessageBox::warning(this, "警告", QString("连接成功，但运动学初始化失败，错误码: %1").arg(err_code));
    }
}


int PlanLinearMove_MultiPoints(FX_MotionHandle handle, int robot_serial, popos pos_start, popos pos_end, double allow_range, int zsp_type,
                               double zsp_para[6],double vel, double acc, int freq, double* pontset, int& point_num, int i, int k)
{
    int err_code = 0;
    if(i == k)
    {
        err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_SetStart(handle, robot_serial, pos_start.up_jointpos, pos_start.up_xyzabc, pos_end.down_xyzabc,
                                                                         allow_range, zsp_type, zsp_para, vel, acc, freq);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to set ARM1 start trajectory. Error code: %d\n", err_code);
        }

        allow_range = 0;
        err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_SetNextPoints(handle, robot_serial, pos_end.up_xyzabc, allow_range, zsp_type, zsp_para,
                                                                              vel, acc);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to plan multi-segment MoveL segment 3. Error code: %d\n", err_code);
            return -1;
        }

        err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_GetPoints(handle, pontset, &point_num);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to export multi-segment MoveL trajectory points. Error code: %d\n", err_code);
            return -1;
        }

    }else
    {
        err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_SetStart(handle, robot_serial, pos_start.up_jointpos, pos_start.up_xyzabc, pos_end.up_xyzabc,
                                                                         allow_range, zsp_type, zsp_para, vel, acc, freq);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to set ARM0 start trajectory. Error code: %d\n", err_code);
        }

        allow_range = 0;
        err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_SetNextPoints(handle, robot_serial, pos_end.down_xyzabc, allow_range, zsp_type, zsp_para,
                                                                                 vel, acc);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to plan multi-segment MoveL segment 2. Error code: %d\n", err_code);
            return -1;
        }

        err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_SetNextPoints(handle, robot_serial, pos_end.up_xyzabc, allow_range, zsp_type, zsp_para,
                                                                              vel, acc);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to plan multi-segment MoveL segment 3. Error code: %d\n", err_code);
            return -1;
        }
        err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_GetPoints(handle, pontset, &point_num);
        if (err_code != FUNC_RET_SUCCESS)
        {
            printf("Failed to export multi-segment MoveL trajectory points. Error code: %d\n", err_code);
            return -1;
        }
    }
    //qDebug() << "A_left_set_half_num traj num" << point_num;
    return 1;
}


void MainWindow::on_pushButton_27_clicked()
{
    //生成轨迹信息
    FX_InvKineSolvePara ik_params ={0};
    FX_InvKineSolvePara ik_params2 = {0};
    double arm1_start_xyzabc[6]={0};
    double arm1_zsp_para[6] = {1, 1, -1, 0, 0, 0};
    int arm1_zsp_type = 1;
    double allow_error_ = 1.0;
    double arm1_pln_vel = 100.0;
    double arm1_pln_acc = 500.0;
    int arm1_pln_freq = 50;
    int err_code = 0;

    for(FX_INT32 i = 0;i < 12; i++)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int index = 0; index < 4; ++index)
            {
                left_pos[i].up_targetcp[j][index] = left_pos[i].startcp[j][index];
                left_pos[i].down_targetcp[j][index] = left_pos[i].startcp[j][index];
            }
        }
        FX_L1_Matrix2XYZABC(left_pos[i].startcp, arm1_start_xyzabc);
        for (int index = 0; index < 6; ++index)
        {
            left_pos[i].up_xyzabc[index] = arm1_start_xyzabc[index];
            left_pos[i].down_xyzabc[index] = arm1_start_xyzabc[index];
        }
        left_pos[i].up_xyzabc[1] += up;
        left_pos[i].down_xyzabc[1] -= down;
        left_pos[i].up_targetcp[1][3] += up;
        left_pos[i].down_targetcp[1][3] -= down;
        FillInverseKinematicsInput(&ik_params, left_pos[i].jointpos, left_pos[i].up_targetcp, arm1_zsp_type, arm1_zsp_para);
        FillInverseKinematicsInput(&ik_params2, left_pos[i].jointpos, left_pos[i].down_targetcp, arm1_zsp_type, arm1_zsp_para);
        err_code = FX_L1_Kinematics_InverseKinematics(handle, 1, &ik_params);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug() << "Failed to solve ARM1 inverse up kinematics. Error code:" << err_code;
            return ;
        }
        if (ik_params.m_Output_IsOutRange)
        {
            qDebug() << "The ARM1 inverse kinematics result is marked as out of range. Error code:" << err_code;
            return ;
        }
        err_code = FX_L1_Kinematics_InverseKinematics(handle,1, &ik_params2);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug() << "Failed to solve ARM1 inverse down kinematics. Error code:" << err_code;
            return ;
        }
        if (ik_params2.m_Output_IsOutRange)
        {
            qDebug("The ARM1 inverse kinematics result is marked as out of range. Error code: %d\n", err_code);
            return ;
        }
        for (int index = 0; index < 7; ++index)
        {
           left_pos[i].up_jointpos[index] = ik_params.m_Output_RetJoint[index];
           left_pos[i].down_jointpos[index] = ik_params2.m_Output_RetJoint[index];
        }
        //PrintJointPosition("ARM1_left_up_inver",left_pos[i].up_jointpos);
        //PrintJointPosition("ARM1_left_down_inver",left_pos[i].down_jointpos);
    }

    for(FX_INT32 i = 0;i < 13; i++)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int index = 0; index < 4; ++index)
            {
                right_pos[i].up_targetcp[j][index] = right_pos[i].startcp[j][index];
                right_pos[i].down_targetcp[j][index] = right_pos[i].startcp[j][index];
            }
        }
        FX_L1_Matrix2XYZABC(right_pos[i].startcp, arm1_start_xyzabc);

        for (int index = 0; index < 6; ++index)
        {
            right_pos[i].up_xyzabc[index] = arm1_start_xyzabc[index];
            right_pos[i].down_xyzabc[index] = arm1_start_xyzabc[index];
        }
        right_pos[i].up_xyzabc[1] += up;
        right_pos[i].down_xyzabc[1] -= down;
        right_pos[i].up_targetcp[1][3] += up;
        right_pos[i].down_targetcp[1][3] -= down;
        FillInverseKinematicsInput(&ik_params, right_pos[i].jointpos, right_pos[i].up_targetcp, arm1_zsp_type, arm1_zsp_para);
        FillInverseKinematicsInput(&ik_params2, right_pos[i].jointpos, right_pos[i].down_targetcp, arm1_zsp_type, arm1_zsp_para);
        err_code = FX_L1_Kinematics_InverseKinematics(handle,1, &ik_params);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to solve ARM1 inverse kinematics. Error code: %d\n", err_code);
            return ;
        }
        if (ik_params.m_Output_IsOutRange)
        {
            qDebug("The ARM1 inverse kinematics result is marked as out of range. Error code: %d\n", err_code);
            return ;
        }
        err_code = FX_L1_Kinematics_InverseKinematics(handle,1, &ik_params2);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to solve ARM1 inverse kinematics. Error code: %d\n", err_code);
            return ;
        }
        if (ik_params2.m_Output_IsOutRange)
        {
            qDebug("The ARM1 inverse kinematics result is marked as out of range. Error code: %d\n", err_code);
            QMessageBox::critical(this, "错误", QString("The ARM1 inverse kinematics result is marked as out of range. Error code: %1\n").arg(err_code));
            return ;
        }
        for (int index = 0; index < 7; ++index)
        {
           right_pos[i].up_jointpos[index] = ik_params.m_Output_RetJoint[index];
           right_pos[i].down_jointpos[index] = ik_params2.m_Output_RetJoint[index];
        }
        //PrintJointPosition("ARM1_right_up_inver",right_pos[i].up_jointpos);
        //PrintJointPosition("ARM1_right_down_inver",right_pos[i].down_jointpos);
    }

    //plan traj
    for(int i = 0; i<12; i++)
    {
        for(int k = 0; k<12; k++)
        {
            //halfbeat
            arm1_pln_vel =300;
            int ret = PlanLinearMove_MultiPoints(handle, 1, left_pos[i], left_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel,arm1_pln_acc, arm1_pln_freq, left_set_halfbeat[(i*12) + k], left_set_half_num[(i*12) + k],i,k);

            qDebug() << "left_set_half_num traj num" << left_set_half_num[(i*12) + k];
            if(ret < 0)
            {
                qDebug("plan left halfbeat error!");
            }
            //onebeat
            arm1_pln_vel =100;
            ret = PlanLinearMove_MultiPoints(handle, 1, left_pos[i], left_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel,arm1_pln_acc, arm1_pln_freq, left_set_onebeat[ i*12+ k],left_set_one_num[i*12 + k], i, k);
            if(ret < 0)
            {
                 qDebug("plan left onebeat error!");
            }

            //twobeat
            arm1_pln_vel =50;
            ret = PlanLinearMove_MultiPoints(handle, 1, left_pos[i], left_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel,arm1_pln_acc, arm1_pln_freq, left_set_twobeat[ i*12+ k],left_set_two_num[i*12 + k], i, k);
            if(ret < 0)
            {
                 qDebug("plan left two baet error!");
            }
            arm1_pln_vel = 67;
            ret = PlanLinearMove_MultiPoints(handle, 1, left_pos[i], left_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel,arm1_pln_acc, arm1_pln_freq, left_set_oneandhalfbeat[ i*12+ k],left_set_oneandhalf_num[i*12 + k], i, k);
            if(ret < 0)
            {
                 qDebug("plan left two baet error!");
            }
        }
    }

    for(int i = 0; i<13; i++)
    {
        for(int k = 0; k<13; k++)
        {
            //halfbeat
            arm1_pln_vel = 200;
            int idx = i * 13 + k;
            int ret = PlanLinearMove_MultiPoints(handle, 1, right_pos[i], right_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel, arm1_pln_acc, arm1_pln_freq, right_set_halfbeat[idx], right_set_half_num[idx], i, k);

            //qDebug() << "right_set_half_num traj num" << right_set_half_num[i*13 + k];
            if(ret < 0)
            {
                printf("plan right halfbeat error!");
            }
            //onebeat
            arm1_pln_vel =100;
            ret = PlanLinearMove_MultiPoints(handle, 1, right_pos[i], right_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel,arm1_pln_acc, arm1_pln_freq, right_set_onebeat[idx], right_set_one_num[idx], i, k);
            if(ret < 0)
            {
                printf("plan right onebeat error!");
            }

            //twobeat
            arm1_pln_vel =50;
            ret = PlanLinearMove_MultiPoints(handle, 1, right_pos[i], right_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel,arm1_pln_acc, arm1_pln_freq, right_set_twobeat[idx], right_set_two_num[idx], i, k);
            if(ret < 0)
            {
                printf("plan right twobeat error!");
            }

            //twobeat
            arm1_pln_vel = 67;
            ret = PlanLinearMove_MultiPoints(handle, 1, right_pos[i], right_pos[k], allow_error_, arm1_zsp_type, arm1_zsp_para,
                                                 arm1_pln_vel,arm1_pln_acc, arm1_pln_freq, right_set_oneandhalfbeat[idx], right_set_oneandhalf_num[idx], i, k);
            if(ret < 0)
            {
                printf("plan right oneandhalfbeat error!");
            }
        }
    }

    QString  dirPath = QCoreApplication::applicationDirPath();
    QString filePath = dirPath + "/joints.txt";
    QFile file(filePath);
    if (file.exists())
    {
        if (!file.resize(0))
        {

        qDebug() << "清空文件失败:" << file.errorString();
        return ;

        }
        qDebug() << "文件内容已成功清空！";

    }
    QTextStream out(&file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        out.setCodec("UTF-8"); // 确保编码正确

        for(int i = 0; i < 25; i++)
        {
            // 使用循环将 7 个 double 数据写入文件
            if(i < 12)
            {
                for (int k = 0; k < 7; ++k)
                {
                    out << QLocale::c().toString(left_pos[i].jointpos[k], 'f', 5);
                    if (k < 6)
                    {
                        out << ",";
                    }
                }
                out << "\n";
            }
            else
            {
                for (int k = 0; k < 7; ++k)
                {
                    out << QLocale::c().toString(right_pos[i - 12].jointpos[k], 'f', 5);
                    if (k < 6)
                    {
                        out << ",";
                    }
                }
                out << "\n";
            }
        }
        out.flush();
        file.close();
        qDebug() << "写入完成，共 25 行";
    } else
    {
        qDebug() << "文件打开失败:" << file.errorString();
    }
}

void MainWindow::on_pushButton_28_clicked()
{
    unsigned int system_errorcode = 0;    ///< Last system error code
    FXStateType obj_state = FX_STATE_UNKNOWN;
    double k[7] = { 3, 3, 3, 2, 1, 1, 1 };
    double d[7] = { 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 };

    /* Check current arm state */
    obj_state = FX_L1_Fbk_CurrentState(FX_OBJ_ARM1);
    if (obj_state == FX_STATE_ERROR)
    {
        qDebug("Arm1 is in STATE_ERROR state now, press any key to reset error\n");
        if (FX_L1_State_ResetError(FX_OBJ_ARM1, 1000, &system_errorcode) == FUNC_RET_SUCCESS)
        {
            qDebug("Reset arm1 error success, arm0 is now in STATE_IDLE state\n");
        }
        else
        {
            printf("Failed to reset arm1 error, errorcode = 0x%08x\n", system_errorcode);
            return;
        }
    }
    else if (obj_state != FX_STATE_IDLE)
    {
        qDebug("Arm0 is not in STATE_IDLE state now, press any key to transfer to STATE_IDLE state\n");
        if (FX_L1_State_SwitchToIdle(FX_OBJ_ARM1, 1000) != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to transfer arm1 to STATE_IDLE state\n");

        }
    }
     /* Switch to joint drag mode */
    qDebug("Arm0 is in STATE_IDLE state now, press any key to transfer to STATE_DRAG_JOINT state\n");
    if (FX_L1_State_SwitchToDragJoint(FX_OBJ_ARM1, 2000, k, d) != FUNC_RET_SUCCESS)
    {
       qDebug("Failed to transfer arm0 to STATE_DRAG_JOINT state\n");
       return;
    }
}

void MainWindow::on_pushButton_29_clicked()
{
    DWORD id;
    m_bRunTraj = true;
    HANDLE reth = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&MainWindow::TrajRun2, this, 0, &id);
    if (reth == INVALID_HANDLE_VALUE)
    {
        printf("OnLinkTo ERR4\n");
        return ;
    }
    CloseHandle(reth);

}

int  MoveLStartPos(FX_MotionHandle handle, double start_pos[7], double end_pos[7])
{
    double arm1_start_matrix[4][4] = {{0}};
    double arm1_end_matrix[4][4] = {{0}};
    double arm1_end_xyzabc[6] = {0};
    double arm1_start_xyzabc[6]={0};
    double zsp_para[6] = {1, 1, -1, 0, 0, 0};
    int zsp_type = 1;
    double allow_error_ = 0;
    double vel = 150.0;
    double acc = 500.0;
    int freq = 50;
    static double arm1_planned_points[FX_MOTION_MAX_POINT_NUM * 7] = {0};
    int err_code = FX_L1_Kinematics_InitSingleArm_ByIniConfig(handle, 1);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to initialize ARM1 kinematics from ini configuration. Error code: %d\n", err_code);
        FX_L1_Kinematics_Destroy(handle);
        return -1;
    }

    err_code = FX_L1_Kinematics_ForwardKinematics(handle, 1, start_pos, arm1_start_matrix);
    const ROBOT_SG *sg_ptr = FX_L1_Fbk_GetSG();
    int point_num = 0;
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM0 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }

    err_code = FX_L1_Kinematics_ForwardKinematics(handle, 1, end_pos, arm1_end_matrix);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to solve ARM0 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
    }

    /* Set start postion and end position. */
    FX_L1_Matrix2XYZABC(arm1_start_matrix, arm1_start_xyzabc);
    FX_L1_Matrix2XYZABC(arm1_end_matrix, arm1_end_xyzabc);

    /* Plan the MoveL_KeepJ trajectories for Arm0. */
    err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_SetStart(handle, 1, start_pos, arm1_start_xyzabc, arm1_end_xyzabc,
                                                                     allow_error_, zsp_type, zsp_para, vel, acc, freq);
    if (err_code != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to set ARM0 start trajectory. Error code: %d\n", err_code);
    }
    err_code = FX_L1_Kinematics_PlanLinearMove_MultiPoints_GetPoints(handle, arm1_planned_points, &point_num);
    if (err_code != FUNC_RET_SUCCESS)
    {
        printf("Failed to export multi-segment MoveL trajectory points. Error code: %d\n", err_code);
        return -1;
    }
    qDebug("Plan ARM0 MoveL trajectory success, points = %d\n", point_num);

    double points[300][7]={{0}};
    for(int i=0;i< point_num;i++)
    {
        for(int k=0;k < 7;k++)
        {
            points[i][k] = arm1_planned_points[i*7 + k];
        }
    }
    int pos_array_count = 0;
    while (pos_array_count < point_num)
    {
       if (FX_L1_Runtime_SetJointPosPDCmd(1, FX_OBJ_ARM1, points[pos_array_count]) != FUNC_RET_SUCCESS)
       {
           qDebug("Failed to send trajectory point %d\n", pos_array_count);
       }
       SLEEP_MS(10);
       pos_array_count ++;
    }
    qDebug("Trajectory move done!\n");

    /* Switch state to STATE_IDLE. */
    qDebug("After Arm0 finishes the MoveL_KeepJ trajectory, press any key to transfer to STATE_IDLE state\n");
    return 1;
}

DWORD WINAPI MainWindow::TrajRun2(LPVOID pParam)
{
    //MainWindow* pthis = (MainWindow*)pParam;
    //double k[7] = { 3, 3, 2, 2, 1, 1, 1};   ///< PD proportional gains
    double k[7] = { 18,18, 16,16, 14, 14, 14};
    double d[7] = { 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7}; ///< PD derivative gains
    double vel_ratio = 100.0;             ///< Velocity scaling ratio (%)
    double acc_ratio = 100.0;             ///< Acceleration scaling ratio (%)
    int comm_quality = 0;                 ///< Current PD command quality
    int statistics_comm_quality_average = 0;
    int statistics_comm_quality_worst = 0;
    int pd_cycle_time = 10;
    unsigned int system_errorcode = 0;
    const ROBOT_SG* sg_ptr = FX_L1_Fbk_GetSG();

    FXStateType obj_state = FX_L1_Fbk_CurrentState(FX_OBJ_ARM1);
    if (obj_state == FX_STATE_ERROR)
    {
        qDebug("Arm0 is in STATE_ERROR, press any key to reset error\n");
        //getchar();
        if (FX_L1_State_ResetError(FX_OBJ_ARM1, 1000, &system_errorcode) != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to reset arm0 error, errorcode = 0x%08x\n", system_errorcode);
        }
    }
    else if (obj_state != FX_STATE_IDLE)
    {
        qDebug("Arm0 is not in STATE_IDLE, press any key to switch to IDLE\n");
        //getchar();
        if (FX_L1_State_SwitchToIdle(FX_OBJ_ARM1, 1000) != FUNC_RET_SUCCESS)
        {
           qDebug("Failed to switch arm0 to IDLE state\n");
        }
    }

    /* Configure PD cycle time */
    qDebug("Press any key to set PD command cycle time to %d ms\n", pd_cycle_time);
    //getchar();
    if (FX_L1_Config_SetPDCmdCycleTime(pd_cycle_time) != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to set PD command cycle time\n");
    }

    /* Enter PD mode */
    qDebug("Press any key to switch arm0 to STATE_PD\n");
    //getchar();
    if (FX_L1_State_SwitchToPDMode(
        FX_OBJ_ARM1,
        2000,
        vel_ratio,
        acc_ratio,
        k,
        d) != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to switch arm0 to STATE_PD\n");
    }


   statistics_comm_quality_average = 0;
   statistics_comm_quality_worst = 100;
   double item[8000][8];
   int count = 0;
   int track_total = 0;
   switch(song_num)
   {
       case 0:
       {
            track_total = (sizeof(robot_track_arry) / sizeof(TrackPoint));
            break;
       }
       case 1:
       {
            track_total = (sizeof(robot_track_arry2) / sizeof(TrackPoint));
            break;
       }
       case 2:
       {
            track_total = (sizeof(robot_track_arry3) / sizeof(TrackPoint));
            break;
       }
       case 3:
       {
            track_total = (sizeof(robot_track_arry4) / sizeof(TrackPoint));
            break;
       }
       default: // 兜底，防止song_num越界
            track_total = (sizeof(robot_track_arry2) / sizeof(TrackPoint));
            break;
   }
   qDebug("track_total=%d \n",track_total);
   double* tp;
   int point_num;
   for(int i = 0; i < track_total; i++)
   {
       // 取当前轨迹结构体指针
       switch(song_num)
       {
           case 0:
           {
                tp = robot_track_arry[i].points;
                point_num = *robot_track_arry[i].length;
                break;
           }
           case 1:
           {
                tp = robot_track_arry2[i].points;
                point_num = *robot_track_arry2[i].length;
                break;
           }
           case 2:
           {
                tp = robot_track_arry3[i].points;
                point_num = *robot_track_arry3[i].length;
                break;
           }
           case 3:
           {
                tp = robot_track_arry4[i].points;
                point_num = *robot_track_arry4[i].length;
                break;
           }
           default: // 兜底，防止song_num越界
               tp = robot_track_arry[i].points;
               point_num = *robot_track_arry[i].length;
               break;
       }

       for(int j=0; j< point_num; j++)
       {
           for(int k = 0; k < 7; k++)
           {
               item[count+j][k] = tp[j*7 + k];
           }
           switch(song_num)
           {
               case 0:
               {
                    item[count+j][7] = robot_track_arry[i].distance;
                    break;
               }
               case 1:
               {
                   item[count+j][7] = robot_track_arry2[i].distance;
                    break;
               }
               case 2:
               {
                    item[count+j][7] = robot_track_arry3[i].distance;
                    break;
               }
               case 3:
               {
                    item[count+j][7] = robot_track_arry4[i].distance;
                    break;
               }
               default: // 兜底，防止song_num越界
                   item[count+j][7]=robot_track_arry[i].distance;
                   break;
           }
           //item[count+j][7]=robot_track_arry[i].distance;
           //memcpy(item[count + j*7], tp + j*7, copy_size);
       }
       count += point_num;
   }
   int pos = item[0][0];
   if(pos == 0)
   {      
      qDebug( "播放失败请检查操作是否正确");
      return 0;
   }
   bool running = true;
   while (running)
   {
       qDebug() << "当前运行标记：" << m_bRunTraj;
       double start_pos[7]={0};
       double end_pos[7]={0};
       const ROBOT_RT* rt_ptr = FX_L1_Fbk_GetRT();
       int erro_count = 0;
       for(int i = 0; i < 7;i++)
       {
            start_pos[i] = rt_ptr->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
            end_pos[i] = item[0][i];
            if(abs(start_pos[i]- end_pos[i]) >0.0001)
            {
                erro_count ++;
            }
       }

       if(erro_count > 0)
       {
           MoveLStartPos(handle, start_pos, end_pos);
       }
       //PrintJointPosition("2ARM1_startpos",item[0]);
       SLEEP_MS(1000);

       int pos_array_count = 0;
       double fb[14]={0};
       double joints[7]={0};
       while (pos_array_count < count)
       {
           //PrintJointPosition("AAARM1_startpos,",item[pos_array_count]);
           for(int i=0;i<7; i++)
           {
               //fb[i] = rt_ptr->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
               //fb[7+i] = item[pos_array_count][i];
               joints[i] = item[pos_array_count][i];
           }
           //PrintJointPosition14("AAARM1_CM,",fb);

           if (FX_L1_Runtime_SetJointPosPDCmd(1, FX_OBJ_ARM1, joints) != FUNC_RET_SUCCESS)
           {
               qDebug("Failed to send trajectory point %d\n", pos_array_count);
           }

           comm_quality = sg_ptr->m_ARMS[1].m_ARM_GET.m_ARM_FBK_PD_CmdQuality;
           if (comm_quality < statistics_comm_quality_worst)
           {
               statistics_comm_quality_worst = comm_quality;
           }
           statistics_comm_quality_average += comm_quality;

    //       /* Store command and feedback data */
    //       for (int j = 0; j < 7; j++)
    //       {
    //           sample_pos_array[pos_array_count][j] = pos_array[pos_array_count][j];
    //           sample_pos_array[pos_array_count][7 + j] = rt_ptr->m_ARMS[0].m_ARM_OUT.m_ARM_FBK_Joint_Pos[j];
    //           sample_pos_array[pos_array_count][14 + j] = rt_ptr->m_ARMS[0].m_ARM_OUT.m_ARM_FBK_Joint_Vel[j];
    //       }
           int time = 10;
           if(item[pos_array_count][7] == 1)
           {
               time = 10;
           }else if(item[pos_array_count][7] == 2 ||item[pos_array_count][7] == 3)
           {
               time = 4;
           }else if(item[pos_array_count][7] == 0)
           {
                time = 14;
           }else if(item[pos_array_count][7] == 4||item[pos_array_count][7] == 5)
           {
               time = 10;
           }
           SLEEP_MS(time);
           pos_array_count++;
       }
       SLEEP_MS(1000);

       running = m_bRunTraj;
   }
   qDebug("Press any key to switch back to IDLE state\n");
   FX_L1_State_SwitchToIdle(FX_OBJ_ARM0, 1000);
   return 0;
}

DWORD WINAPI MainWindow::TrajRun(LPVOID pParam)
{
    MainWindow* pthis = (MainWindow*)pParam;
    //double k[7] = { 3, 3, 2, 2, 1, 1, 1};   ///< PD proportional gains
    double k[7] = { 18,18, 16,16, 14, 14, 14};
    double d[7] = { 0.7, 0.7, 0.7, 0.7, 0.7, 0.7, 0.7}; ///< PD derivative gains
    double vel_ratio = 100.0;             ///< Velocity scaling ratio (%)
    double acc_ratio = 100.0;             ///< Acceleration scaling ratio (%)
    int comm_quality = 0;                 ///< Current PD command quality
    int statistics_comm_quality_average = 0;
    int statistics_comm_quality_worst = 0;
    int pd_cycle_time = 10;
    unsigned int system_errorcode = 0;
    const ROBOT_SG* sg_ptr = FX_L1_Fbk_GetSG();

    FXStateType obj_state = FX_L1_Fbk_CurrentState(FX_OBJ_ARM1);
    if (obj_state == FX_STATE_ERROR)
    {
        qDebug("Arm0 is in STATE_ERROR, press any key to reset error\n");
        //getchar();
        if (FX_L1_State_ResetError(FX_OBJ_ARM1, 1000, &system_errorcode) != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to reset arm0 error, errorcode = 0x%08x\n", system_errorcode);
        }
    }
    else if (obj_state != FX_STATE_IDLE)
    {
        qDebug("Arm0 is not in STATE_IDLE, press any key to switch to IDLE\n");
        //getchar();
        if (FX_L1_State_SwitchToIdle(FX_OBJ_ARM1, 1000) != FUNC_RET_SUCCESS)
        {
           qDebug("Failed to switch arm0 to IDLE state\n");
        }
    }

    /* Configure PD cycle time */
    qDebug("Press any key to set PD command cycle time to %d ms\n", pd_cycle_time);
    //getchar();
    if (FX_L1_Config_SetPDCmdCycleTime(pd_cycle_time) != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to set PD command cycle time\n");

    }

    /* Enter PD mode */
    qDebug("Press any key to switch arm0 to STATE_PD\n");
    //getchar();
    if (FX_L1_State_SwitchToPDMode(
        FX_OBJ_ARM1,
        2000,
        vel_ratio,
        acc_ratio,
        k,
        d) != FUNC_RET_SUCCESS)
    {
        qDebug("Failed to switch arm0 to STATE_PD\n");
    }


   statistics_comm_quality_average = 0;
   statistics_comm_quality_worst = 100;
   double item[8000][8];
   int count = 0;
   int track_total = 0;
   switch(song_num)
   {
       case 0:
       {
            track_total = (sizeof(robot_track_arry) / sizeof(TrackPoint));
            break;
       }
       case 1:
       {
            track_total = (sizeof(robot_track_arry2) / sizeof(TrackPoint));
            break;
       }
       case 2:
       {
            track_total = (sizeof(robot_track_arry3) / sizeof(TrackPoint));
            break;
       }
       case 3:
       {
            track_total = (sizeof(robot_track_arry4) / sizeof(TrackPoint));
            break;
       }
       default: // 兜底，防止song_num越界
            track_total = (sizeof(robot_track_arry2) / sizeof(TrackPoint));
            break;
   }
   qDebug("track_total=%d \n",track_total);
   double* tp;
   int point_num;
   for(int i = 0; i < track_total; i++)
   {
       // 取当前轨迹结构体指针
       switch(song_num)
       {
           case 0:
           {
                tp = robot_track_arry[i].points;
                point_num = *robot_track_arry[i].length;
                break;
           }
           case 1:
           {
                tp = robot_track_arry2[i].points;
                point_num = *robot_track_arry2[i].length;
                break;
           }
           case 2:
           {
                tp = robot_track_arry3[i].points;
                point_num = *robot_track_arry3[i].length;
                break;
           }
           case 3:
           {
                tp = robot_track_arry4[i].points;
                point_num = *robot_track_arry4[i].length;
                break;
           }
           default: // 兜底，防止song_num越界
               tp = robot_track_arry[i].points;
               point_num = *robot_track_arry[i].length;
               break;
       }

       for(int j=0; j< point_num; j++)
       {
           for(int k = 0; k < 7; k++)
           {
               item[count+j][k] = tp[j*7 + k];
           }
           switch(song_num)
           {
               case 0:
               {
                    item[count+j][7] = robot_track_arry[i].distance;
                    break;
               }
               case 1:
               {
                   item[count+j][7] = robot_track_arry2[i].distance;
                    break;
               }
               case 2:
               {
                    item[count+j][7] = robot_track_arry3[i].distance;
                    break;
               }
               case 3:
               {
                    item[count+j][7] = robot_track_arry4[i].distance;
                    break;
               }               
               default: // 兜底，防止song_num越界
                   item[count+j][7]=robot_track_arry[i].distance;
                   break;
           }
           //item[count+j][7]=robot_track_arry[i].distance;
           //memcpy(item[count + j*7], tp + j*7, copy_size);
       }
       count += point_num;
   }
   int pos = item[0][0];
   if(pos == 0)
   {
      qDebug("播放失败,请检查操作是否正确");
      return 0;
   }
   double start_pos[7]={0};
   double end_pos[7]={0};
   const ROBOT_RT* rt_ptr = FX_L1_Fbk_GetRT();
   int erro_count = 0;
   for(int i = 0; i < 7;i++)
   {
        start_pos[i] = rt_ptr->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
        end_pos[i] = item[0][i];
        if(abs(start_pos[i]- end_pos[i]) >0.0001)
        {
            erro_count ++;
        }
   }

   if(erro_count > 0)
   {
       MoveLStartPos(handle, start_pos, end_pos);
   }
   //PrintJointPosition("2ARM1_startpos",item[0]);
   SLEEP_MS(1000);
   int pos_array_count = 0;
   double fb[14]={0};
   double joints[7]={0};
   while (pos_array_count < count)
   {
       //PrintJointPosition("AAARM1_startpos,",item[pos_array_count]);
       for(int i=0;i<7; i++)
       {
           //fb[i] = rt_ptr->m_ARMS[1].m_ARM_OUT.m_ARM_FBK_Joint_Pos[i];
           //fb[7+i] = item[pos_array_count][i];
           joints[i] = item[pos_array_count][i];
       }
       //PrintJointPosition14("AAARM1_CM,",fb);

       if (FX_L1_Runtime_SetJointPosPDCmd(1, FX_OBJ_ARM1, joints) != FUNC_RET_SUCCESS)
       {
           qDebug("Failed to send trajectory point %d\n", pos_array_count);
       }

       comm_quality = sg_ptr->m_ARMS[1].m_ARM_GET.m_ARM_FBK_PD_CmdQuality;
       if (comm_quality < statistics_comm_quality_worst)
       {
           statistics_comm_quality_worst = comm_quality;
       }
       statistics_comm_quality_average += comm_quality;

//       /* Store command and feedback data */
//       for (int j = 0; j < 7; j++)
//       {
//           sample_pos_array[pos_array_count][j] = pos_array[pos_array_count][j];
//           sample_pos_array[pos_array_count][7 + j] = rt_ptr->m_ARMS[0].m_ARM_OUT.m_ARM_FBK_Joint_Pos[j];
//           sample_pos_array[pos_array_count][14 + j] = rt_ptr->m_ARMS[0].m_ARM_OUT.m_ARM_FBK_Joint_Vel[j];
//       }
       int time = 10;
       if(item[pos_array_count][7] == 1)
       {
           time = 10;
       }else if(item[pos_array_count][7] == 2 ||item[pos_array_count][7] == 3)
       {
           time = 4;
       }else if(item[pos_array_count][7] == 0)
       {
            time = 14;
       }else if(item[pos_array_count][7] == 4||item[pos_array_count][7] == 5)
       {
           time = 10;
       }
       SLEEP_MS(time);
       pos_array_count++;
   }
   qDebug("Press any key to switch back to IDLE state\n");
   FX_L1_State_SwitchToIdle(FX_OBJ_ARM0, 1000);
   return 0;
}

void MainWindow::on_pushButton_30_clicked()
{
    DWORD id;
    HANDLE reth = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&MainWindow::TrajRun, this, 0, &id);
    if (reth == INVALID_HANDLE_VALUE)
    {
        printf("OnLinkTo ERR4\n");
        return ;
    }
    CloseHandle(reth);
}

void MainWindow::on_pushButton_31_clicked()
{
    int err_code;

    // ==================== left_pos[0] ~ left_pos[11] 12组 ====================
//    double tmp0[7]  = {-78.7943, -67.0030, 53.3989, -91.3056, -65.4462, 11.2248, -11.1535};
//    memcpy(left_pos[0].jointpos, tmp0, sizeof(tmp0));

//    double tmp1[7]  = {-79.9541, -65.4171, 54.7678, -92.2357, -65.2622, 11.2303, -11.7452};
//    memcpy(left_pos[1].jointpos, tmp1, sizeof(tmp1));

//    double tmp2[7]  = {-80.8070, -64.3893, 56.3682, -92.4946, -65.0042, 11.2559, -11.9579};
//    memcpy(left_pos[2].jointpos, tmp2, sizeof(tmp2));

//    double tmp3[7]  = {-81.5002, -63.6586, 57.8842, -92.4964, -64.6538, 11.3940, -12.0624};
//    memcpy(left_pos[3].jointpos, tmp3, sizeof(tmp3));

//    double tmp4[7]  = {-82.4246, -62.9562, 59.7051, -92.6609, -64.5165, 11.4388, -12.3390};
//    memcpy(left_pos[4].jointpos, tmp4, sizeof(tmp4));

//    double tmp5[7]  = {-83.5539, -61.9429, 61.3830, -92.7988, -64.2952, 11.4624, -13.1457};
//    memcpy(left_pos[5].jointpos, tmp5, sizeof(tmp5));

//    double tmp6[7]  = {-84.5341, -61.1975, 63.1704, -92.8695, -63.9836, 11.4637, -13.4754};
//    memcpy(left_pos[6].jointpos, tmp6, sizeof(tmp6));

//    double tmp7[7]  = {-74.6365, -71.0958, 54.7974, -84.0847, -63.6683, 11.3601, -13.6060};
//    memcpy(left_pos[7].jointpos, tmp7, sizeof(tmp7));

//    double tmp8[7]  = {-76.0528, -69.6842, 56.6466, -84.8581, -63.2740, 11.4309, -14.6508};
//    memcpy(left_pos[8].jointpos, tmp8, sizeof(tmp8));

//    double tmp9[7]  = {-77.4635, -68.1888, 59.4217, -85.1731, -63.0498, 11.4287, -15.2787};
//    memcpy(left_pos[9].jointpos, tmp9, sizeof(tmp9));

//    double tmp10[7] = {-78.5260, -67.2065, 61.3744, -85.3870, -62.5453, 11.4168, -16.0799};
//    memcpy(left_pos[10].jointpos, tmp10, sizeof(tmp10));

//    double tmp11[7] = {-79.4015, -66.4236, 63.1803, -85.3397, -62.3127, 11.4575, -16.2642};
//    memcpy(left_pos[11].jointpos, tmp11, sizeof(tmp11));

//    // ==================== right_pos[0] ~ right_pos[12] 13组 ====================
//    double tmp12[7] = {-86.1561, -58.4322, 68.2841, -90.4452, -62.1094, 0.3108, -17.0317};
//    memcpy(right_pos[0].jointpos, tmp12, sizeof(tmp12));

//    double tmp13[7] = {-86.8631, -57.6778, 69.8478, -90.2110, -62.0230, 0.2990, -17.3971};
//    memcpy(right_pos[1].jointpos, tmp13, sizeof(tmp13));

//    double tmp14[7] = {-86.9193, -57.3349, 71.1732, -89.3991, -61.8792, 0.3459, -17.5218};
//    memcpy(right_pos[2].jointpos, tmp14, sizeof(tmp14));

//    double tmp15[7] = {-87.5108, -56.7663, 72.6701, -89.0668, -61.6969, 0.3438, -17.5476};
//    memcpy(right_pos[3].jointpos, tmp15, sizeof(tmp15));

//    double tmp16[7] = {-88.0025, -56.2583, 74.3133, -88.4478, -61.2766, 0.2650, -17.5640};
//    memcpy(right_pos[4].jointpos, tmp16, sizeof(tmp16));

//    double tmp17[7] = {-88.3876, -55.8066, 75.8278, -87.8794, -61.1153, 0.3128, -17.6336};
//    memcpy(right_pos[5].jointpos, tmp17, sizeof(tmp17));

//    double tmp18[7] = {-88.6491, -55.5175, 77.3852, -87.0706, -60.8781, 0.2775, -17.6223};
//    memcpy(right_pos[6].jointpos, tmp18, sizeof(tmp18));

//    double tmp19[7] = {-88.8430, -55.2869, 78.9629, -86.1625, -60.8229, 0.3114, -17.6610};
//    memcpy(right_pos[7].jointpos, tmp19, sizeof(tmp19));

//    double tmp20[7] = {-80.0253, -62.0420, 67.9644, -83.5419, -60.8413, 0.4701, -17.0236};
//    memcpy(right_pos[8].jointpos, tmp20, sizeof(tmp20));

//    double tmp21[7] = {-80.6712, -61.0757, 69.6045, -83.3899, -60.8323, 0.4812, -17.1633};
//    memcpy(right_pos[9].jointpos, tmp21, sizeof(tmp21));

//    double tmp22[7] = {-81.2187, -60.2730, 72.0538, -82.5413, -60.8124, 1.0905, -17.2331};
//    memcpy(right_pos[10].jointpos, tmp22, sizeof(tmp22));

//    double tmp23[7] = {-81.7003, -59.6968, 73.7476, -82.0420, -60.8182, 1.1309, -17.2131};
//    memcpy(right_pos[11].jointpos, tmp23, sizeof(tmp23));

//    double tmp24[7] = {-81.8278, -59.4301, 75.4067, -81.0135, -60.8175, 1.1532, -17.3297};
//    memcpy(right_pos[12].jointpos, tmp24, sizeof(tmp24));

    QString dirPath = QCoreApplication::applicationDirPath();
    QString filePath = dirPath + "/joints.txt";

    QFile file(filePath);
    double dataArray[7] = {0}; // 准备一个数组用于接收数据

    // 2. 以只读和文本模式打开文件
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        in.setCodec("UTF-8"); // 保持与写入时一致的编码
        QString line;
        int currentRow = 0;
        int num = 0;
        while(currentRow < 25 && !in.atEnd())
        {
            // 读取文件的第一行内容
            line = in.readLine();
            // Qt 默认会忽略分割后产生的空字符串，这能防止末尾多写一个逗号导致的问题
            QStringList strList = line.split(",", QString::SkipEmptyParts);

            // 取 strList.size() 和 7 中的较小值，防止文件里数据多于7个导致数组越界
            int count = qMin(strList.size(), 7);
            for (int i = 0; i < count; ++i)
            {
                bool ok;
                dataArray[i] = strList[i].toDouble(&ok);

                // 检查转换是否成功
                if (!ok)
                {
                    qDebug() << "警告: 第" << i + 1 << "个数据转换失败，原始字符串为:" << strList[i];
                }
            }
            if(currentRow < 12)
            {
                memcpy(left_pos[currentRow].jointpos, dataArray, sizeof(dataArray));
            }else
            {
                num = currentRow - 12;
                memcpy(right_pos[num].jointpos, dataArray, sizeof(dataArray));
            }
            currentRow ++;

        }
    } else
    {
        qDebug() << "文件打开失败:" << file.errorString();
    }
    file.close(); // 读取完毕后关闭文件

    // 左臂0~11 正向运动学求解
    for(int k = 0; k < 12; k++)
    {
        PrintJointPosition("ARM1", left_pos[k].jointpos);
        err_code = FX_L1_Kinematics_ForwardKinematics(handle, 1, left_pos[k].jointpos, left_pos[k].startcp);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
        }
    }

    // 右臂0~12 正向运动学求解（共13组）
    for(int k = 0; k < 13; k++)
    {
        PrintJointPosition("ARM1", right_pos[k].jointpos);
        err_code = FX_L1_Kinematics_ForwardKinematics(handle, 1, right_pos[k].jointpos, right_pos[k].startcp);
        if (err_code != FUNC_RET_SUCCESS)
        {
            qDebug("Failed to solve ARM1 forward kinematics for the MoveL start pose. Error code: %d\n", err_code);
        }
    }
}

void MainWindow::on_pushButton_32_clicked()
{
    song_num = ui->comboBox->currentIndex();
    qDebug()<< "send"<< ui->comboBox->currentText() << ui->comboBox->currentIndex();
}

void MainWindow::on_pushButton_33_clicked()
{
    if (!m_bRunTraj)
    {
        qDebug("线程未在运行\n");
        return;
    }
    m_bRunTraj = false;
    qDebug("set to stop move!");
}

