/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QSpacerItem *topSpacer;
    QHBoxLayout *topControlsLayout;
    QSpacerItem *topLeftSpacer;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *pushButton_33;
    QPushButton *pushButton_31;
    QPushButton *pushButton_28;
    QPushButton *pushButton_26;
    QSpacerItem *topRightSpacer;
    QHBoxLayout *comboLayout;
    QSpacerItem *comboLeftSpacer;
    QComboBox *comboBox;
    QPushButton *pushButton_32;
    QSpacerItem *comboRightSpacer;
    QHBoxLayout *numberRow1Layout;
    QSpacerItem *row1LeftSpacer;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QSpacerItem *row1RightSpacer;
    QHBoxLayout *numberRow2Layout;
    QSpacerItem *row2LeftSpacer;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QPushButton *pushButton_15;
    QPushButton *pushButton_11;
    QSpacerItem *row2RightSpacer;
    QHBoxLayout *finishRowLayout;
    QSpacerItem *finishLeftSpacer;
    QPushButton *pushButton_27;
    QSpacerItem *finishRightSpacer;
    QSpacerItem *bottomSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1230, 817);
        MainWindow->setMinimumSize(QSize(800, 500));
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralWidget {\n"
"    background-color: #eef1f6;\n"
"    background-image: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #eef1f6, stop:1 #e3e9f5);\n"
"}\n"
"QMainWindow {\n"
"    background-color: #eef1f6;\n"
"}\n"
"\n"
"/* ===== \351\200\232\347\224\250\346\214\211\351\222\256 ===== */\n"
"QPushButton {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ffffff, stop:1 #f5f7fa);\n"
"    color: #2c3e50;\n"
"    border: 1px solid #d6dae3;\n"
"    border-radius: 10px;\n"
"    padding: 8px 18px;\n"
"    font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #eaf2ff, stop:1 #d6e6ff);\n"
"    border-color: #4a90e2;\n"
"    color: #1a73e8;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #d0e0ff;\n"
"    border-color: #1a73e8;\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color"
                        ": #eceef1;\n"
"    color: #9aa0a6;\n"
"    border-color: #d6dae3;\n"
"}\n"
"\n"
"/* ===== \344\270\273\346\223\215\344\275\234\346\214\211\351\222\256\357\274\210\346\270\220\345\217\230\350\223\235\357\274\211 ===== */\n"
"QPushButton#pushButton_26,\n"
"QPushButton#pushButton_30,\n"
"QPushButton#pushButton_32,\n"
"QPushButton#pushButton_27,\n"
"QPushButton#pushButton_33 {\n"
"    color: #ffffff;\n"
"    border: 1px solid #2a5cd6;\n"
"    border-radius: 10px;\n"
"    font-weight: 600;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #4a90e2, stop:0.5 #1a73e8, stop:1 #1557b8);\n"
"}\n"
"QPushButton#pushButton_26:hover,\n"
"QPushButton#pushButton_30:hover,\n"
"QPushButton#pushButton_32:hover,\n"
"QPushButton#pushButton_27:hover,\n"
"QPushButton#pushButton_33:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #5aa0f2, stop:0.5 #2a83f0, stop:1 #1a67c8);\n"
"    border-color: #1557b8;\n"
"}\n"
"QPushButton#pushButton_26:pressed,\n"
"QPush"
                        "Button#pushButton_30:pressed,\n"
"QPushButton#pushButton_32:pressed,\n"
"QPushButton#pushButton_27:pressed,\n"
"QPushButton#pushButton_33:pressed {\n"
"    background-color: #0f44a0;\n"
"}\n"
"\n"
"/* ===== \345\215\261\351\231\251\346\214\211\351\222\256\357\274\210\345\201\234\346\255\242\346\222\255\346\224\276 - \347\272\242\350\211\262\350\260\203\357\274\211 ===== */\n"
"QPushButton#pushButton_33 {\n"
"    color: #ffffff;\n"
"    border: 1px solid #b03a3a;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #ff7a7a, stop:0.5 #e84c4c, stop:1 #c93838);\n"
"}\n"
"QPushButton#pushButton_33:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #ff8a8a, stop:0.5 #f05a5a, stop:1 #d34848);\n"
"    border-color: #b03a3a;\n"
"}\n"
"QPushButton#pushButton_33:pressed {\n"
"    background-color: #a02828;\n"
"}\n"
"\n"
"/* ===== \346\254\241\350\246\201\345\212\250\344\275\234\346\214\211\351\222\256\357\274\210\346\217\217\350\276\271\357\274\211"
                        " ===== */\n"
"QPushButton#pushButton_28,\n"
"QPushButton#pushButton_31,\n"
"QPushButton#pushButton_29 {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ffffff, stop:1 #eef4ff);\n"
"    color: #1a73e8;\n"
"    border: 1px solid #1a73e8;\n"
"    border-radius: 10px;\n"
"    font-weight: 600;\n"
"}\n"
"QPushButton#pushButton_28:hover,\n"
"QPushButton#pushButton_31:hover,\n"
"QPushButton#pushButton_29:hover {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #eaf2ff, stop:1 #d6e6ff);\n"
"    color: #0f44a0;\n"
"    border-color: #0f44a0;\n"
"}\n"
"QPushButton#pushButton_28:pressed,\n"
"QPushButton#pushButton_31:pressed,\n"
"QPushButton#pushButton_29:pressed {\n"
"    background-color: #d0e0ff;\n"
"}\n"
"\n"
"/* ===== \351\222\242\347\220\264\351\273\221\351\224\256\357\274\210\347\254\254\344\270\200\346\216\222 1-5 1-5\357\274\211 ===== */\n"
"QPushButton#pushButton_16,\n"
"QPushButton#pushButton_17,\n"
"QPushButton#pushButton_18,\n"
"QPushB"
                        "utton#pushButton_19,\n"
"QPushButton#pushButton_20,\n"
"QPushButton#pushButton_21,\n"
"QPushButton#pushButton_22,\n"
"QPushButton#pushButton_23,\n"
"QPushButton#pushButton_24,\n"
"QPushButton#pushButton_25 {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #3a3f4b, stop:1 #1f2329);\n"
"    color: #f5f7fa;\n"
"    border: 1px solid #0d1014;\n"
"    border-radius: 10px;\n"
"    min-height: 44px;\n"
"    min-width: 44px;\n"
"    font-weight: 700;\n"
"}\n"
"QPushButton#pushButton_16:hover,\n"
"QPushButton#pushButton_17:hover,\n"
"QPushButton#pushButton_18:hover,\n"
"QPushButton#pushButton_19:hover,\n"
"QPushButton#pushButton_20:hover,\n"
"QPushButton#pushButton_21:hover,\n"
"QPushButton#pushButton_22:hover,\n"
"QPushButton#pushButton_23:hover,\n"
"QPushButton#pushButton_24:hover,\n"
"QPushButton#pushButton_25:hover {\n"
"    color: #ffffff;\n"
"    border-color: #1557b8;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #4a90e2, stop:1 #1a73e8)"
                        ";\n"
"}\n"
"QPushButton#pushButton_16:pressed,\n"
"QPushButton#pushButton_17:pressed,\n"
"QPushButton#pushButton_18:pressed,\n"
"QPushButton#pushButton_19:pressed,\n"
"QPushButton#pushButton_20:pressed,\n"
"QPushButton#pushButton_21:pressed,\n"
"QPushButton#pushButton_22:pressed,\n"
"QPushButton#pushButton_23:pressed,\n"
"QPushButton#pushButton_24:pressed,\n"
"QPushButton#pushButton_25:pressed {\n"
"    background-color: #0f44a0;\n"
"    border-color: #0f44a0;\n"
"}\n"
"\n"
"/* ===== \351\222\242\347\220\264\347\231\275\351\224\256\357\274\210\347\254\254\344\272\214\346\216\222 1-7 1-8\357\274\211 ===== */\n"
"QPushButton#pushButton,\n"
"QPushButton#pushButton_2,\n"
"QPushButton#pushButton_3,\n"
"QPushButton#pushButton_4,\n"
"QPushButton#pushButton_5,\n"
"QPushButton#pushButton_6,\n"
"QPushButton#pushButton_7,\n"
"QPushButton#pushButton_8,\n"
"QPushButton#pushButton_9,\n"
"QPushButton#pushButton_10,\n"
"QPushButton#pushButton_11,\n"
"QPushButton#pushButton_12,\n"
"QPushButton#pushButton_13,\n"
"QPushButton#pu"
                        "shButton_14,\n"
"QPushButton#pushButton_15 {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ffffff, stop:1 #f0f2f5);\n"
"    color: #2c3e50;\n"
"    border: 1px solid #c8ccd4;\n"
"    border-radius: 10px;\n"
"    min-height: 44px;\n"
"    min-width: 44px;\n"
"    font-weight: 700;\n"
"}\n"
"QPushButton#pushButton:hover,\n"
"QPushButton#pushButton_2:hover,\n"
"QPushButton#pushButton_3:hover,\n"
"QPushButton#pushButton_4:hover,\n"
"QPushButton#pushButton_5:hover,\n"
"QPushButton#pushButton_6:hover,\n"
"QPushButton#pushButton_7:hover,\n"
"QPushButton#pushButton_8:hover,\n"
"QPushButton#pushButton_9:hover,\n"
"QPushButton#pushButton_10:hover,\n"
"QPushButton#pushButton_11:hover,\n"
"QPushButton#pushButton_12:hover,\n"
"QPushButton#pushButton_13:hover,\n"
"QPushButton#pushButton_14:hover,\n"
"QPushButton#pushButton_15:hover {\n"
"    color: #ffffff;\n"
"    border-color: #1557b8;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"        stop:0 #4a90e2, stop"
                        ":1 #1a73e8);\n"
"}\n"
"QPushButton#pushButton:pressed,\n"
"QPushButton#pushButton_2:pressed,\n"
"QPushButton#pushButton_3:pressed,\n"
"QPushButton#pushButton_4:pressed,\n"
"QPushButton#pushButton_5:pressed,\n"
"QPushButton#pushButton_6:pressed,\n"
"QPushButton#pushButton_7:pressed,\n"
"QPushButton#pushButton_8:pressed,\n"
"QPushButton#pushButton_9:pressed,\n"
"QPushButton#pushButton_10:pressed,\n"
"QPushButton#pushButton_11:pressed,\n"
"QPushButton#pushButton_12:pressed,\n"
"QPushButton#pushButton_13:pressed,\n"
"QPushButton#pushButton_14:pressed,\n"
"QPushButton#pushButton_15:pressed {\n"
"    background-color: #0f44a0;\n"
"    border-color: #0f44a0;\n"
"}\n"
"\n"
"/* ===== \344\270\213\346\213\211\346\241\206 ===== */\n"
"QComboBox {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ffffff, stop:1 #f5f7fa);\n"
"    color: #2c3e50;\n"
"    border: 1px solid #d6dae3;\n"
"    border-radius: 10px;\n"
"    padding: 6px 14px;\n"
"    min-height: 28px;\n"
"    min-width: 180px;\n"
""
                        "    font-family: \"Microsoft YaHei\", \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"}\n"
"QComboBox:hover {\n"
"    border-color: #4a90e2;\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ffffff, stop:1 #eaf2ff);\n"
"}\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 28px;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 6px solid #5a6473;\n"
"    margin-right: 10px;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    color: #2c3e50;\n"
"    border: 1px solid #d6dae3;\n"
"    border-radius: 8px;\n"
"    outline: none;\n"
"    selection-background-color: #1a73e8;\n"
"    selection-color: #ffffff;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"/* ===== \350\217\234\345\215\225\346\240\217 / \345\267\245\345\205\267\346\240\217 / \347\212\266\346\200\201\346\240\217 ===== */\n"
"QMenuBar {\n"
"    background-color: qlin"
                        "eargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #ffffff, stop:1 #f5f7fa);\n"
"    color: #2c3e50;\n"
"    border-bottom: 1px solid #e6e9ef;\n"
"    padding: 3px;\n"
"}\n"
"QMenuBar::item {\n"
"    background: transparent;\n"
"    padding: 6px 14px;\n"
"    border-radius: 6px;\n"
"    margin: 0 2px;\n"
"}\n"
"QMenuBar::item:selected {\n"
"    background-color: #eaf2ff;\n"
"    color: #1a73e8;\n"
"}\n"
"QToolBar {\n"
"    background-color: #ffffff;\n"
"    border-bottom: 1px solid #e6e9ef;\n"
"    spacing: 4px;\n"
"}\n"
"QStatusBar {\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f5f7fa, stop:1 #ffffff);\n"
"    color: #5a6473;\n"
"    border-top: 1px solid #e6e9ef;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(18);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(40, 30, 40, 30);
        topSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(topSpacer);

        topControlsLayout = new QHBoxLayout();
        topControlsLayout->setSpacing(6);
        topControlsLayout->setObjectName(QStringLiteral("topControlsLayout"));
        topLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topControlsLayout->addItem(topLeftSpacer);

        pushButton_29 = new QPushButton(centralWidget);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_29->sizePolicy().hasHeightForWidth());
        pushButton_29->setSizePolicy(sizePolicy);
        pushButton_29->setMinimumSize(QSize(80, 41));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei,Segoe UI,sans-serif"));
        font.setBold(true);
        font.setWeight(75);
        pushButton_29->setFont(font);

        topControlsLayout->addWidget(pushButton_29);

        pushButton_30 = new QPushButton(centralWidget);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        sizePolicy.setHeightForWidth(pushButton_30->sizePolicy().hasHeightForWidth());
        pushButton_30->setSizePolicy(sizePolicy);
        pushButton_30->setMinimumSize(QSize(80, 41));
        pushButton_30->setFont(font);

        topControlsLayout->addWidget(pushButton_30);

        pushButton_33 = new QPushButton(centralWidget);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);
        pushButton_33->setMinimumSize(QSize(96, 41));
        pushButton_33->setFont(font);

        topControlsLayout->addWidget(pushButton_33);

        pushButton_31 = new QPushButton(centralWidget);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setMinimumSize(QSize(80, 41));
        pushButton_31->setFont(font);

        topControlsLayout->addWidget(pushButton_31);

        pushButton_28 = new QPushButton(centralWidget);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        sizePolicy.setHeightForWidth(pushButton_28->sizePolicy().hasHeightForWidth());
        pushButton_28->setSizePolicy(sizePolicy);
        pushButton_28->setMinimumSize(QSize(80, 41));
        pushButton_28->setFont(font);

        topControlsLayout->addWidget(pushButton_28);

        pushButton_26 = new QPushButton(centralWidget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        sizePolicy.setHeightForWidth(pushButton_26->sizePolicy().hasHeightForWidth());
        pushButton_26->setSizePolicy(sizePolicy);
        pushButton_26->setMinimumSize(QSize(80, 41));
        pushButton_26->setFont(font);

        topControlsLayout->addWidget(pushButton_26);

        topRightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topControlsLayout->addItem(topRightSpacer);


        mainLayout->addLayout(topControlsLayout);

        comboLayout = new QHBoxLayout();
        comboLayout->setSpacing(6);
        comboLayout->setObjectName(QStringLiteral("comboLayout"));
        comboLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        comboLayout->addItem(comboLeftSpacer);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(210, 42));

        comboLayout->addWidget(comboBox);

        pushButton_32 = new QPushButton(centralWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);
        pushButton_32->setMinimumSize(QSize(80, 41));
        pushButton_32->setFont(font);

        comboLayout->addWidget(pushButton_32);

        comboRightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        comboLayout->addItem(comboRightSpacer);


        mainLayout->addLayout(comboLayout);

        numberRow1Layout = new QHBoxLayout();
        numberRow1Layout->setSpacing(6);
        numberRow1Layout->setObjectName(QStringLiteral("numberRow1Layout"));
        row1LeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        numberRow1Layout->addItem(row1LeftSpacer);

        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei,Segoe UI,sans-serif"));
        font1.setBold(true);
        font1.setWeight(87);
        pushButton_16->setFont(font1);

        numberRow1Layout->addWidget(pushButton_16);

        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy1.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy1);
        pushButton_17->setFont(font1);

        numberRow1Layout->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy1.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy1);
        pushButton_18->setFont(font1);

        numberRow1Layout->addWidget(pushButton_18);

        pushButton_19 = new QPushButton(centralWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy1.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy1);
        pushButton_19->setFont(font1);

        numberRow1Layout->addWidget(pushButton_19);

        pushButton_20 = new QPushButton(centralWidget);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        sizePolicy1.setHeightForWidth(pushButton_20->sizePolicy().hasHeightForWidth());
        pushButton_20->setSizePolicy(sizePolicy1);
        pushButton_20->setFont(font1);

        numberRow1Layout->addWidget(pushButton_20);

        pushButton_21 = new QPushButton(centralWidget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        sizePolicy1.setHeightForWidth(pushButton_21->sizePolicy().hasHeightForWidth());
        pushButton_21->setSizePolicy(sizePolicy1);
        pushButton_21->setFont(font1);

        numberRow1Layout->addWidget(pushButton_21);

        pushButton_22 = new QPushButton(centralWidget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        sizePolicy1.setHeightForWidth(pushButton_22->sizePolicy().hasHeightForWidth());
        pushButton_22->setSizePolicy(sizePolicy1);
        pushButton_22->setFont(font1);

        numberRow1Layout->addWidget(pushButton_22);

        pushButton_23 = new QPushButton(centralWidget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        sizePolicy1.setHeightForWidth(pushButton_23->sizePolicy().hasHeightForWidth());
        pushButton_23->setSizePolicy(sizePolicy1);
        pushButton_23->setFont(font1);

        numberRow1Layout->addWidget(pushButton_23);

        pushButton_24 = new QPushButton(centralWidget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        sizePolicy1.setHeightForWidth(pushButton_24->sizePolicy().hasHeightForWidth());
        pushButton_24->setSizePolicy(sizePolicy1);
        pushButton_24->setFont(font1);

        numberRow1Layout->addWidget(pushButton_24);

        pushButton_25 = new QPushButton(centralWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        sizePolicy1.setHeightForWidth(pushButton_25->sizePolicy().hasHeightForWidth());
        pushButton_25->setSizePolicy(sizePolicy1);
        pushButton_25->setFont(font1);

        numberRow1Layout->addWidget(pushButton_25);

        row1RightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        numberRow1Layout->addItem(row1RightSpacer);


        mainLayout->addLayout(numberRow1Layout);

        numberRow2Layout = new QHBoxLayout();
        numberRow2Layout->setSpacing(6);
        numberRow2Layout->setObjectName(QStringLiteral("numberRow2Layout"));
        row2LeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        numberRow2Layout->addItem(row2LeftSpacer);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setFont(font1);

        numberRow2Layout->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setFont(font1);

        numberRow2Layout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setFont(font1);

        numberRow2Layout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setFont(font1);

        numberRow2Layout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setFont(font1);

        numberRow2Layout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setFont(font1);

        numberRow2Layout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setFont(font1);

        numberRow2Layout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setFont(font1);

        numberRow2Layout->addWidget(pushButton);

        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setFont(font1);

        numberRow2Layout->addWidget(pushButton_10);

        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setFont(font1);

        numberRow2Layout->addWidget(pushButton_12);

        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setFont(font1);

        numberRow2Layout->addWidget(pushButton_9);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy1.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy1);
        pushButton_14->setFont(font1);

        numberRow2Layout->addWidget(pushButton_14);

        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy1.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy1);
        pushButton_13->setFont(font1);

        numberRow2Layout->addWidget(pushButton_13);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy1.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy1);
        pushButton_15->setFont(font1);

        numberRow2Layout->addWidget(pushButton_15);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setFont(font1);

        numberRow2Layout->addWidget(pushButton_11);

        row2RightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        numberRow2Layout->addItem(row2RightSpacer);


        mainLayout->addLayout(numberRow2Layout);

        finishRowLayout = new QHBoxLayout();
        finishRowLayout->setSpacing(6);
        finishRowLayout->setObjectName(QStringLiteral("finishRowLayout"));
        finishLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        finishRowLayout->addItem(finishLeftSpacer);

        pushButton_27 = new QPushButton(centralWidget);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        sizePolicy.setHeightForWidth(pushButton_27->sizePolicy().hasHeightForWidth());
        pushButton_27->setSizePolicy(sizePolicy);
        pushButton_27->setMinimumSize(QSize(100, 36));
        pushButton_27->setFont(font);

        finishRowLayout->addWidget(pushButton_27);

        finishRightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        finishRowLayout->addItem(finishRightSpacer);


        mainLayout->addLayout(finishRowLayout);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(bottomSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1230, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_29->setText(QApplication::translate("MainWindow", "\345\276\252\347\216\257\346\222\255\346\224\276", Q_NULLPTR));
        pushButton_30->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\222\255\346\224\276", Q_NULLPTR));
        pushButton_33->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\346\222\255\346\224\276", Q_NULLPTR));
        pushButton_31->setText(QApplication::translate("MainWindow", "PUT", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("MainWindow", "DRAG", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1\343\200\201\346\254\242\344\271\220\351\242\202", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2\343\200\201\345\217\213\350\260\212\345\234\260\344\271\205\345\244\251\351\225\277", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3\343\200\201\345\260\217\346\230\237\346\230\237", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4\343\200\201\346\211\276\346\234\213\345\217\213", Q_NULLPTR)
         << QString()
        );
        pushButton_32->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
