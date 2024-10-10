/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName("About");
        About->resize(375, 280);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        About->setMinimumSize(QSize(375, 280));
        About->setMaximumSize(QSize(375, 280));
        About->setStyleSheet(QString::fromUtf8("QDialog {\n"
"background : #343536;\n"
"color : #8bc34a;\n"
"}\n"
"\n"
"QGroupBox{\n"
"color : #8bc34a;\n"
"font: bold 13px;\n"
"border: 1px solid #8bc34a;\n"
"border-radius: 2px;\n"
"margin-top: 3ex;\n"
"background: #252525;\n"
"}\n"
"\n"
"QGroupBox::title{\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
"padding: 0 3px;\n"
"}\n"
"\n"
"QLabel{\n"
"color : #8bc34a;\n"
"font: bold;\n"
"}\n"
"\n"
"QLabel#label_5{\n"
"color : #00cccc;\n"
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
"background : #343536;\n"
"border-radius: 3px;\n"
""
                        "border-style: outset;\n"
"border-width: 1px;\n"
"border-color: rgb(119, 175, 54);\n"
"padding: 5px;\n"
"}\n"
"\n"
"QPushButton[flat=\"false\"]:!enabled{\n"
"font: bold;\n"
"color: #858585;\n"
"background : #444546;\n"
"border-radius: 4px;\n"
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
"border: 4px solid #8bc34a;\n"
"border-radius:6px;\n"
"}\n"
"\n"
"QRadioButton::indicator"
                        ":!checked{\n"
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
"background-color: #343536;\n"
"border: none;\n"
"}\n"
"\n"
"QScrollBar{\n"
"background: #353535;"
                        "\n"
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
        label_2 = new QLabel(About);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 8, 121, 120));
        label_2->setPixmap(QPixmap(QString::fromUtf8("irmaker.png")));
        label_2->setScaledContents(true);
        label_6 = new QLabel(About);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 168, 380, 34));
        label_6->setAlignment(Qt::AlignCenter);
        label = new QLabel(About);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 258, 375, 16));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(About);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 130, 375, 16));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(About);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(5, 220, 89, 16));
        label_5 = new QLabel(About);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(92, 221, 281, 16));
        QPalette palette;
        QBrush brush(QColor(0, 204, 204, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 157, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush2(QColor(2, 145, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush2);
        QBrush brush3(QColor(0, 204, 204, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_5->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setKerning(false);
        label_5->setFont(font);
        label_5->setText(QString::fromUtf8("https://github.com/JuanPabloZed/IR_Maker_Cpp"));
        label_5->setTextFormat(Qt::MarkdownText);
        label_5->setOpenExternalLinks(true);

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "About", nullptr));
        label_2->setText(QString());
        label_6->setText(QCoreApplication::translate("About", "Copyright (c) 2024 Nathan Zwahlen", nullptr));
        label->setText(QCoreApplication::translate("About", "v1.0.3", nullptr));
        label_3->setText(QCoreApplication::translate("About", "IR Maker", nullptr));
        label_4->setText(QCoreApplication::translate("About", "Git repository :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
