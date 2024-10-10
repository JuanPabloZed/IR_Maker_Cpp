/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *sweep_box;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QPushButton *browsesweep_button;
    QCheckBox *fullrangebox;
    QWidget *freqwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *begfreq;
    QLineEdit *endfreq;
    QPushButton *sweepgen_button;
    QGroupBox *response_box;
    QHBoxLayout *horizontalLayout_10;
    QSplitter *splitter_2;
    QTreeView *treeView;
    QListView *files_list;
    QGroupBox *output_box;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *autosave_radio;
    QRadioButton *customsave_radio;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *browseout_button;
    QHBoxLayout *horizontalLayout_3;
    QLabel *srate_label;
    QCheckBox *autosr_check;
    QLineEdit *srate;
    QCheckBox *irlengthbox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *irlength;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_2;
    QLineEdit *irlengthSamples;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *bitdepth_label;
    QComboBox *bitdepth_combo;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *trimbox;
    QCheckBox *CutTailBox;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *about_button;
    QPushButton *createir_button;
    QPushButton *playir_button;
    QPushButton *testsound;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *testir;
    QCheckBox *showgraphsbox;
    QSplitter *splitter;
    QCustomPlot *ir_plot;
    QCustomPlot *freq_plot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1060, 747);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 610));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background : #303030;\n"
"color : #8bc34a;\n"
"}\n"
"\n"
"Line {\n"
"background: #8bc34a;\n"
"color: #8bc34a;\n"
"}\n"
"\n"
"QGroupBox{\n"
"color : #8bc34a;\n"
"font: bold 13px;\n"
"border: 1px solid #8bc34a;\n"
"border-radius: 2px;\n"
"margin-top: 1ex;\n"
"background: #343536;\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
"padding: 0 3px;\n"
"}\n"
"\n"
"QMessageBox{\n"
"background: #343536;\n"
"alternate-background-color: #545556;\n"
"}\n"
"\n"
"QLabel{\n"
"color : #8bc34a;\n"
"font: bold;\n"
"}\n"
"\n"
"QLineEdit:enabled{\n"
"color : #8bc34a;\n"
"border: 1px solid #8bc34a;\n"
"border-radius: 2px;\n"
"padding: 2px;\n"
"background : #242526;\n"
"font: bold;\n"
"}\n"
"\n"
"QLineEdit:!enabled{\n"
"color: #b5b5b5;\n"
"border: 1px solid #858585;\n"
"border-radius: 3px;\n"
"padding: 2px;\n"
"background : #444546;\n"
"font: bold;\n"
"}\n"
"\n"
"QPushButton[flat=\"true\"]{\n"
"color : #8bc34a;\n"
"}\n"
"\n"
"QPushButton[flat=\"false\"]:enable"
                        "d{\n"
"color : #8bc34a;\n"
"font: bold 14px;\n"
"background : #303030;\n"
"border-radius: 2px;\n"
"border-style: outset;\n"
"border-width: 1px;\n"
"border-color: rgb(119, 175, 54);\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover:enabled{\n"
"background: #37400b;\n"
"}\n"
"\n"
"QPushButton[flat=\"false\"]:!enabled{\n"
"font: bold;\n"
"color: #858585;\n"
"background : #444546;\n"
"border-radius: 2px;\n"
"border-style: outset;\n"
"border-width: 1px;\n"
"border-color: #656565;\n"
"padding: 5px;\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"border: 2px solid;\n"
"border-radius: 3px; \n"
"}\n"
"\n"
"QCheckBox:enabled{\n"
"color: #8bc34a;\n"
"}\n"
"\n"
"QCheckBox::indicator:enabled{\n"
"border: 2px solid #8bc34a;\n"
"}\n"
"\n"
"QCheckBox::indicator:!enabled{\n"
"border: 2px solid #656565;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked{\n"
"background: #8bc34a;\n"
"border-color: #8bc34a;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:!enabled{\n"
"background: #656565;\n"
"border-color: #656565;\n"
"}\n"
"\n"
"QRadioButton:che"
                        "cked{\n"
"color: #8bc34a;\n"
"font: bold;\n"
"}\n"
"\n"
"QRadioButton{\n"
"color: #858585;\n"
"font: bold;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked{\n"
"background: #252525;\n"
"border: 4px solid #8bc34a;\n"
"border-radius:6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:!checked{\n"
"background: #252525;\n"
"border: 2px solid #858585;\n"
"border-radius:6px;\n"
"}\n"
"\n"
"QComboBox{\n"
"background: #353535;\n"
"color: #8bc34a;\n"
"border: 2px solid #8bc34a;\n"
"border-radius: 3px;\n"
"}\n"
"\n"
"QTreeView{\n"
"background: #252525;\n"
"border-radius: 6px;\n"
"color: #8bc34a;\n"
"}\n"
"\n"
"QTreeView::branch:open {\n"
"    image: url(:img/img/branch-open2.png);\n"
"}\n"
"\n"
"QTreeView::branch:closed:has-children {\n"
"    image: url(:img/img/branch-closed2.png);\n"
"}\n"
"\n"
"QHeaderView::section{\n"
"color: #8bc34a;\n"
"background-color: #444546;\n"
"font: bold;\n"
"}\n"
"\n"
"QListView:enabled{\n"
"background: #252525;\n"
"border-radius: 2px;\n"
"color: #8bc34a;\n"
"\n"
"}\n"
"\n"
"QListView:!enabled{\n"
""
                        "background: #454545;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QListView::item:selected{\n"
"background: #3a541c\n"
"}\n"
"\n"
"QGraphicsView{\n"
"background: #252525;\n"
"border: none;\n"
"}\n"
"\n"
"QSplitter::handle{\n"
"color: #343536;\n"
"background-color: #343536;\n"
"border: none;\n"
"}\n"
"\n"
"QScrollBar{\n"
"background: #353535;\n"
"border: none;\n"
"}\n"
"\n"
"QScrollBar::add-page, QScrollBar::sub-page{\n"
"background: none;\n"
"border: none;\n"
"}\n"
"\n"
"QScrollBar::handle{\n"
"background-color: #555555;\n"
"}\n"
"\n"
"QScrollBar:left-arrow, QScrollBar::right-arrow{\n"
"border: none;\n"
"width: 4px;\n"
"height: 4px;\n"
"background: #8bc34a;\n"
"}\n"
"\n"
"QScrollBar:up-arrow, QScrollBar::down-arrow{\n"
"border: none;\n"
"width: 4px;\n"
"height: 4px;\n"
"background: #8bc34a;\n"
"}\n"
"\n"
"QScrollBar::add-line, QScrollBar::sub-line{\n"
"border: none;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(0, 290));
        widget_3->setMaximumSize(QSize(16777215, 290));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 10, 0);
        sweep_box = new QGroupBox(widget_3);
        sweep_box->setObjectName("sweep_box");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sweep_box->sizePolicy().hasHeightForWidth());
        sweep_box->setSizePolicy(sizePolicy1);
        sweep_box->setMinimumSize(QSize(210, 0));
        sweep_box->setMaximumSize(QSize(210, 16777215));
        horizontalLayout_9 = new QHBoxLayout(sweep_box);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        browsesweep_button = new QPushButton(sweep_box);
        browsesweep_button->setObjectName("browsesweep_button");
        browsesweep_button->setMinimumSize(QSize(0, 60));
        browsesweep_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(browsesweep_button);

        fullrangebox = new QCheckBox(sweep_box);
        fullrangebox->setObjectName("fullrangebox");
        fullrangebox->setChecked(true);

        verticalLayout_5->addWidget(fullrangebox);

        freqwidget = new QWidget(sweep_box);
        freqwidget->setObjectName("freqwidget");
        freqwidget->setEnabled(false);
        freqwidget->setMaximumSize(QSize(16777215, 60));
        formLayoutWidget = new QWidget(freqwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 0, 203, 65));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        begfreq = new QLineEdit(formLayoutWidget);
        begfreq->setObjectName("begfreq");
        begfreq->setMaximumSize(QSize(65, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, begfreq);

        endfreq = new QLineEdit(formLayoutWidget);
        endfreq->setObjectName("endfreq");
        endfreq->setMaximumSize(QSize(65, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, endfreq);


        verticalLayout_5->addWidget(freqwidget);

        sweepgen_button = new QPushButton(sweep_box);
        sweepgen_button->setObjectName("sweepgen_button");
        sweepgen_button->setEnabled(true);
        sweepgen_button->setMinimumSize(QSize(0, 80));
        sweepgen_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_5->addWidget(sweepgen_button);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(3, 3);

        horizontalLayout_9->addLayout(verticalLayout_5);


        horizontalLayout->addWidget(sweep_box);

        response_box = new QGroupBox(widget_3);
        response_box->setObjectName("response_box");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(response_box->sizePolicy().hasHeightForWidth());
        response_box->setSizePolicy(sizePolicy2);
        response_box->setMinimumSize(QSize(300, 0));
        response_box->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_10 = new QHBoxLayout(response_box);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        splitter_2 = new QSplitter(response_box);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter_2);
        treeView->setObjectName("treeView");
        splitter_2->addWidget(treeView);
        treeView->header()->setVisible(false);
        files_list = new QListView(splitter_2);
        files_list->setObjectName("files_list");
        files_list->setEnabled(false);
        files_list->setSelectionMode(QAbstractItemView::ExtendedSelection);
        splitter_2->addWidget(files_list);

        horizontalLayout_10->addWidget(splitter_2);


        horizontalLayout->addWidget(response_box);

        output_box = new QGroupBox(widget_3);
        output_box->setObjectName("output_box");
        sizePolicy1.setHeightForWidth(output_box->sizePolicy().hasHeightForWidth());
        output_box->setSizePolicy(sizePolicy1);
        output_box->setMinimumSize(QSize(220, 0));
        output_box->setMaximumSize(QSize(220, 16777215));
        verticalLayout_2 = new QVBoxLayout(output_box);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        autosave_radio = new QRadioButton(output_box);
        autosave_radio->setObjectName("autosave_radio");
        autosave_radio->setMinimumSize(QSize(0, 0));
        autosave_radio->setCursor(QCursor(Qt::PointingHandCursor));
        autosave_radio->setChecked(true);

        verticalLayout_2->addWidget(autosave_radio);

        customsave_radio = new QRadioButton(output_box);
        customsave_radio->setObjectName("customsave_radio");
        customsave_radio->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(customsave_radio);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        browseout_button = new QPushButton(output_box);
        browseout_button->setObjectName("browseout_button");
        browseout_button->setEnabled(false);
        browseout_button->setMinimumSize(QSize(80, 0));
        browseout_button->setMaximumSize(QSize(180, 16777215));
        browseout_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_5->addWidget(browseout_button);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        srate_label = new QLabel(output_box);
        srate_label->setObjectName("srate_label");

        horizontalLayout_3->addWidget(srate_label);

        autosr_check = new QCheckBox(output_box);
        autosr_check->setObjectName("autosr_check");
        autosr_check->setCursor(QCursor(Qt::PointingHandCursor));
        autosr_check->setChecked(true);

        horizontalLayout_3->addWidget(autosr_check);

        srate = new QLineEdit(output_box);
        srate->setObjectName("srate");
        srate->setEnabled(false);
        srate->setMinimumSize(QSize(80, 0));
        srate->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(srate);


        verticalLayout_2->addLayout(horizontalLayout_3);

        irlengthbox = new QCheckBox(output_box);
        irlengthbox->setObjectName("irlengthbox");
        irlengthbox->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(irlengthbox->sizePolicy().hasHeightForWidth());
        irlengthbox->setSizePolicy(sizePolicy3);
        irlengthbox->setMaximumSize(QSize(115, 16777215));
        irlengthbox->setCursor(QCursor(Qt::PointingHandCursor));
        irlengthbox->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(irlengthbox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(output_box);
        label->setObjectName("label");
        label->setEnabled(true);

        horizontalLayout_6->addWidget(label);

        irlength = new QLineEdit(output_box);
        irlength->setObjectName("irlength");
        irlength->setEnabled(false);

        horizontalLayout_6->addWidget(irlength);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_2 = new QLabel(output_box);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);

        horizontalLayout_12->addWidget(label_2);

        irlengthSamples = new QLineEdit(output_box);
        irlengthSamples->setObjectName("irlengthSamples");
        irlengthSamples->setEnabled(false);

        horizontalLayout_12->addWidget(irlengthSamples);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        bitdepth_label = new QLabel(output_box);
        bitdepth_label->setObjectName("bitdepth_label");
        bitdepth_label->setMaximumSize(QSize(70, 16777215));
        bitdepth_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(bitdepth_label);

        bitdepth_combo = new QComboBox(output_box);
        bitdepth_combo->addItem(QString());
        bitdepth_combo->addItem(QString());
        bitdepth_combo->addItem(QString());
        bitdepth_combo->setObjectName("bitdepth_combo");
        bitdepth_combo->setMinimumSize(QSize(60, 0));
        bitdepth_combo->setMaximumSize(QSize(60, 16777215));
        bitdepth_combo->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_4->addWidget(bitdepth_combo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        trimbox = new QCheckBox(output_box);
        trimbox->setObjectName("trimbox");
        trimbox->setCursor(QCursor(Qt::PointingHandCursor));
        trimbox->setCheckable(true);
        trimbox->setChecked(true);

        verticalLayout_2->addWidget(trimbox);

        CutTailBox = new QCheckBox(output_box);
        CutTailBox->setObjectName("CutTailBox");
        CutTailBox->setChecked(true);

        verticalLayout_2->addWidget(CutTailBox);


        horizontalLayout->addWidget(output_box);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy4);
        widget_2->setMinimumSize(QSize(150, 0));
        widget_2->setMaximumSize(QSize(220, 16777215));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, -1, 0, -1);
        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);
        widget->setMinimumSize(QSize(0, 25));
        widget->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(800, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        about_button = new QPushButton(widget);
        about_button->setObjectName("about_button");
        about_button->setMinimumSize(QSize(0, 25));
        about_button->setMaximumSize(QSize(50, 25));
        QFont font;
        font.setUnderline(true);
        about_button->setFont(font);
        about_button->setCursor(QCursor(Qt::PointingHandCursor));
        about_button->setFlat(true);

        horizontalLayout_2->addWidget(about_button);


        verticalLayout->addWidget(widget);

        createir_button = new QPushButton(widget_2);
        createir_button->setObjectName("createir_button");
        createir_button->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(createir_button->sizePolicy().hasHeightForWidth());
        createir_button->setSizePolicy(sizePolicy6);
        createir_button->setMinimumSize(QSize(0, 50));
        createir_button->setMaximumSize(QSize(16777215, 50));
        createir_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(createir_button);

        playir_button = new QPushButton(widget_2);
        playir_button->setObjectName("playir_button");
        playir_button->setEnabled(false);
        playir_button->setMinimumSize(QSize(0, 50));
        playir_button->setMaximumSize(QSize(16777215, 50));
        playir_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(playir_button);

        testsound = new QPushButton(widget_2);
        testsound->setObjectName("testsound");
        testsound->setEnabled(false);
        testsound->setMinimumSize(QSize(0, 20));
        testsound->setMaximumSize(QSize(16777215, 25));
        testsound->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(testsound);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy7);
        widget_4->setMinimumSize(QSize(0, 35));
        widget_4->setMaximumSize(QSize(16777215, 35));
        horizontalLayout_11 = new QHBoxLayout(widget_4);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        testir = new QPushButton(widget_4);
        testir->setObjectName("testir");
        testir->setEnabled(false);
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(testir->sizePolicy().hasHeightForWidth());
        testir->setSizePolicy(sizePolicy8);
        testir->setMinimumSize(QSize(0, 35));
        testir->setMaximumSize(QSize(16777215, 35));
        testir->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_11->addWidget(testir);

        horizontalLayout_11->setStretch(0, 1);

        verticalLayout->addWidget(widget_4);

        showgraphsbox = new QCheckBox(widget_2);
        showgraphsbox->setObjectName("showgraphsbox");
        showgraphsbox->setEnabled(true);
        sizePolicy8.setHeightForWidth(showgraphsbox->sizePolicy().hasHeightForWidth());
        showgraphsbox->setSizePolicy(sizePolicy8);
        showgraphsbox->setMinimumSize(QSize(0, 21));
        showgraphsbox->setMaximumSize(QSize(16777215, 21));
        showgraphsbox->setCursor(QCursor(Qt::PointingHandCursor));
        showgraphsbox->setChecked(true);

        verticalLayout->addWidget(showgraphsbox);


        horizontalLayout->addWidget(widget_2);


        verticalLayout_3->addWidget(widget_3);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        ir_plot = new QCustomPlot(splitter);
        ir_plot->setObjectName("ir_plot");
        ir_plot->setMinimumSize(QSize(0, 100));
        splitter->addWidget(ir_plot);
        freq_plot = new QCustomPlot(splitter);
        freq_plot->setObjectName("freq_plot");
        freq_plot->setMinimumSize(QSize(0, 100));
        splitter->addWidget(freq_plot);

        verticalLayout_3->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        bitdepth_combo->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "IR Maker", nullptr));
        sweep_box->setTitle(QCoreApplication::translate("MainWindow", "SWEEP", nullptr));
        browsesweep_button->setText(QCoreApplication::translate("MainWindow", "Browse sweep file", nullptr));
        fullrangebox->setText(QCoreApplication::translate("MainWindow", "Full frequency range sweep", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Beginning frequency", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ending frequency", nullptr));
        begfreq->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        endfreq->setText(QCoreApplication::translate("MainWindow", "24000", nullptr));
        sweepgen_button->setText(QCoreApplication::translate("MainWindow", "SWEEP GENERATOR", nullptr));
        response_box->setTitle(QCoreApplication::translate("MainWindow", "SELECT YOUR RECORDING FILE(S)", nullptr));
        output_box->setTitle(QCoreApplication::translate("MainWindow", "OUTPUT", nullptr));
        autosave_radio->setText(QCoreApplication::translate("MainWindow", "Automatic output (creates \"IR\"\n"
"folder in recordings folder)", nullptr));
        customsave_radio->setText(QCoreApplication::translate("MainWindow", "Custom output", nullptr));
        browseout_button->setText(QCoreApplication::translate("MainWindow", "Browse output", nullptr));
        srate_label->setText(QCoreApplication::translate("MainWindow", "Sample rate", nullptr));
        autosr_check->setText(QCoreApplication::translate("MainWindow", "Auto", nullptr));
        srate->setPlaceholderText(QCoreApplication::translate("MainWindow", "in Hz", nullptr));
        irlengthbox->setText(QCoreApplication::translate("MainWindow", "Custom IR length", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Milliseconds", nullptr));
        irlength->setPlaceholderText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Samples", nullptr));
        irlengthSamples->setPlaceholderText(QCoreApplication::translate("MainWindow", "samples", nullptr));
        bitdepth_label->setText(QCoreApplication::translate("MainWindow", "Bit depth", nullptr));
        bitdepth_combo->setItemText(0, QCoreApplication::translate("MainWindow", "16 bit", nullptr));
        bitdepth_combo->setItemText(1, QCoreApplication::translate("MainWindow", "24 bit", nullptr));
        bitdepth_combo->setItemText(2, QCoreApplication::translate("MainWindow", "32 bit", nullptr));

        trimbox->setText(QCoreApplication::translate("MainWindow", "Cut pre-ringing", nullptr));
        CutTailBox->setText(QCoreApplication::translate("MainWindow", "Auto cut tail", nullptr));
        about_button->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        createir_button->setText(QCoreApplication::translate("MainWindow", "Create IR", nullptr));
        playir_button->setText(QCoreApplication::translate("MainWindow", "Play IR", nullptr));
        testsound->setText(QCoreApplication::translate("MainWindow", "Browse test sound", nullptr));
        testir->setText(QCoreApplication::translate("MainWindow", "Test IR", nullptr));
        showgraphsbox->setText(QCoreApplication::translate("MainWindow", "Show graphs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
