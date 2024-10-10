/********************************************************************************
** Form generated from reading UI file 'sweepgenerator.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWEEPGENERATOR_H
#define UI_SWEEPGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_SweepGenerator
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *params_box;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *srate;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *duration;
    QLineEdit *beg_freq;
    QComboBox *bitdepth;
    QLineEdit *end_freq;
    QCheckBox *fullspectrumbox;
    QCheckBox *fadebox;
    QLabel *label_5;
    QPushButton *save_button;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *gen_button;
    QPushButton *play_button;
    QSpacerItem *verticalSpacer;
    QCustomPlot *sweep_plot;

    void setupUi(QDialog *SweepGenerator)
    {
        if (SweepGenerator->objectName().isEmpty())
            SweepGenerator->setObjectName("SweepGenerator");
        SweepGenerator->resize(563, 444);
        SweepGenerator->setStyleSheet(QString::fromUtf8("QDialog {\n"
"background : #303030;\n"
"color : #8bc34a;\n"
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
"QPushButton[flat=\"false\"]:enabled{\n"
"color : #8bc34a;\n"
"font: bold 14px;\n"
"background : #303030;\n"
""
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
"QRadioButton:checked{\n"
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
""
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
"    image: url(:img/img/branch-open.png);\n"
"}\n"
"\n"
"QTreeView::branch:closed:has-children {\n"
"    image: url(:img/img/branch-closed.png);\n"
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
"}\n"
"\n"
"QListView:!enabled{\n"
"background: #454545;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QGraphicsView{\n"
"background: #252525;\n"
"border-radius: 12px;\n"
"}\n"
"\n"
"QSplitter::handle{\n"
"color: #343536;\n"
"backgrou"
                        "nd-color: #343536;\n"
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
        verticalLayout_3 = new QVBoxLayout(SweepGenerator);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget = new QWidget(SweepGenerator);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 260));
        widget->setMaximumSize(QSize(16777215, 260));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        params_box = new QGroupBox(widget);
        params_box->setObjectName("params_box");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(params_box->sizePolicy().hasHeightForWidth());
        params_box->setSizePolicy(sizePolicy);
        params_box->setMinimumSize(QSize(160, 250));
        params_box->setMaximumSize(QSize(250, 250));
        verticalLayout_2 = new QVBoxLayout(params_box);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        srate = new QComboBox(params_box);
        srate->addItem(QString());
        srate->addItem(QString());
        srate->addItem(QString());
        srate->addItem(QString());
        srate->addItem(QString());
        srate->addItem(QString());
        srate->setObjectName("srate");
        srate->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(srate, 4, 1, 1, 1);

        label_4 = new QLabel(params_box);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(0, 25));
        label_4->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(params_box);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 25));
        label_3->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(params_box);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 25));
        label->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_6 = new QLabel(params_box);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(params_box);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        duration = new QLineEdit(params_box);
        duration->setObjectName("duration");

        gridLayout->addWidget(duration, 3, 1, 1, 1);

        beg_freq = new QLineEdit(params_box);
        beg_freq->setObjectName("beg_freq");
        beg_freq->setEnabled(false);

        gridLayout->addWidget(beg_freq, 1, 1, 1, 1);

        bitdepth = new QComboBox(params_box);
        bitdepth->addItem(QString());
        bitdepth->addItem(QString());
        bitdepth->addItem(QString());
        bitdepth->setObjectName("bitdepth");

        gridLayout->addWidget(bitdepth, 5, 1, 1, 1);

        end_freq = new QLineEdit(params_box);
        end_freq->setObjectName("end_freq");
        end_freq->setEnabled(false);

        gridLayout->addWidget(end_freq, 2, 1, 1, 1);

        fullspectrumbox = new QCheckBox(params_box);
        fullspectrumbox->setObjectName("fullspectrumbox");
        fullspectrumbox->setEnabled(true);
        fullspectrumbox->setMinimumSize(QSize(0, 0));
        fullspectrumbox->setCheckable(true);
        fullspectrumbox->setChecked(true);

        gridLayout->addWidget(fullspectrumbox, 0, 0, 1, 1);

        fadebox = new QCheckBox(params_box);
        fadebox->setObjectName("fadebox");

        gridLayout->addWidget(fadebox, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        label_5 = new QLabel(params_box);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(0, 25));
        label_5->setMaximumSize(QSize(16777215, 25));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        save_button = new QPushButton(params_box);
        save_button->setObjectName("save_button");
        save_button->setMinimumSize(QSize(0, 30));
        save_button->setMaximumSize(QSize(16777215, 30));
        save_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout_2->addWidget(save_button);


        horizontalLayout->addWidget(params_box);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        gen_button = new QPushButton(widget);
        gen_button->setObjectName("gen_button");
        gen_button->setEnabled(false);
        gen_button->setMinimumSize(QSize(0, 50));
        gen_button->setMaximumSize(QSize(16777215, 50));
        gen_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(gen_button);

        play_button = new QPushButton(widget);
        play_button->setObjectName("play_button");
        play_button->setEnabled(false);
        play_button->setMinimumSize(QSize(0, 50));
        play_button->setMaximumSize(QSize(16777215, 50));
        play_button->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(play_button);

        verticalSpacer = new QSpacerItem(10, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_3->addWidget(widget);

        sweep_plot = new QCustomPlot(SweepGenerator);
        sweep_plot->setObjectName("sweep_plot");
        sweep_plot->setMinimumSize(QSize(0, 160));
        sweep_plot->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(sweep_plot);


        retranslateUi(SweepGenerator);

        srate->setCurrentIndex(1);
        bitdepth->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SweepGenerator);
    } // setupUi

    void retranslateUi(QDialog *SweepGenerator)
    {
        SweepGenerator->setWindowTitle(QCoreApplication::translate("SweepGenerator", "Sweep generator", nullptr));
        params_box->setTitle(QCoreApplication::translate("SweepGenerator", "Sweep parameters", nullptr));
        srate->setItemText(0, QCoreApplication::translate("SweepGenerator", "44100", nullptr));
        srate->setItemText(1, QCoreApplication::translate("SweepGenerator", "48000", nullptr));
        srate->setItemText(2, QCoreApplication::translate("SweepGenerator", "88200", nullptr));
        srate->setItemText(3, QCoreApplication::translate("SweepGenerator", "96000", nullptr));
        srate->setItemText(4, QCoreApplication::translate("SweepGenerator", "176400", nullptr));
        srate->setItemText(5, QCoreApplication::translate("SweepGenerator", "192000", nullptr));

        srate->setPlaceholderText(QCoreApplication::translate("SweepGenerator", "in Hz", nullptr));
        label_4->setText(QCoreApplication::translate("SweepGenerator", "Sample rate (Hz)", nullptr));
        label_3->setText(QCoreApplication::translate("SweepGenerator", "Duration (sec)", nullptr));
        label->setText(QCoreApplication::translate("SweepGenerator", "Beginning freq. (Hz)", nullptr));
        label_6->setText(QCoreApplication::translate("SweepGenerator", "Bit depth", nullptr));
        label_2->setText(QCoreApplication::translate("SweepGenerator", "Ending freq. (Hz)", nullptr));
        duration->setText(QCoreApplication::translate("SweepGenerator", "10", nullptr));
        duration->setPlaceholderText(QCoreApplication::translate("SweepGenerator", "in sec", nullptr));
        beg_freq->setText(QCoreApplication::translate("SweepGenerator", "20", nullptr));
        beg_freq->setPlaceholderText(QCoreApplication::translate("SweepGenerator", "in Hz", nullptr));
        bitdepth->setItemText(0, QCoreApplication::translate("SweepGenerator", "16 bit", nullptr));
        bitdepth->setItemText(1, QCoreApplication::translate("SweepGenerator", "24 bit", nullptr));
        bitdepth->setItemText(2, QCoreApplication::translate("SweepGenerator", "32 bit", nullptr));

        end_freq->setText(QCoreApplication::translate("SweepGenerator", "24000", nullptr));
        end_freq->setPlaceholderText(QCoreApplication::translate("SweepGenerator", "in Hz", nullptr));
        fullspectrumbox->setText(QCoreApplication::translate("SweepGenerator", "Full frequency range", nullptr));
        fadebox->setText(QCoreApplication::translate("SweepGenerator", "Apply fades", nullptr));
        label_5->setText(QCoreApplication::translate("SweepGenerator", "Saving location", nullptr));
        save_button->setText(QCoreApplication::translate("SweepGenerator", "Browse...", nullptr));
        gen_button->setText(QCoreApplication::translate("SweepGenerator", "Generate sweep", nullptr));
        play_button->setText(QCoreApplication::translate("SweepGenerator", "Play sweep", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SweepGenerator: public Ui_SweepGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWEEPGENERATOR_H
