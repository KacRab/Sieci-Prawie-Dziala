/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *wzmocnienie;
    QLabel *rozniczkowanie;
    QLabel *calkowanie;
    QDoubleSpinBox *wzmocn;
    QDoubleSpinBox *st_calk;
    QDoubleSpinBox *st_rozn;
    QPushButton *Reset_pid;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout;
    QRadioButton *Tryb_pod;
    QRadioButton *Tryb_przed;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QPushButton *Conf_Button;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *wej_p;
    QLabel *label;
    QDoubleSpinBox *wej_t;
    QLabel *label_2;
    QDoubleSpinBox *wej_Amp;
    QDoubleSpinBox *wej_T;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QDoubleSpinBox *war_stala;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *sin;
    QRadioButton *prost;
    QRadioButton *skok;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *interval;
    QHBoxLayout *Buttons_layout;
    QPushButton *Start_Button;
    QPushButton *Reset_Button;
    QPushButton *Stop_Button;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_5;
    QPushButton *saveButton;
    QPushButton *readButton;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonKonfiguracjaSieci;
    QWidget *widget1;
    QWidget *widget2;
    QWidget *widget3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::WindowModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1500, 866);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1500, 730));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1500, 730));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        wzmocnienie = new QLabel(groupBox);
        wzmocnienie->setObjectName("wzmocnienie");
        wzmocnienie->setStyleSheet(QString::fromUtf8("font: 15pt \"Calibri\";\n"
                                                     "color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(wzmocnienie, 0, 0, 1, 1);

        rozniczkowanie = new QLabel(groupBox);
        rozniczkowanie->setObjectName("rozniczkowanie");
        rozniczkowanie->setStyleSheet(QString::fromUtf8("font: 15pt \"Calibri\";\n"
                                                        "color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(rozniczkowanie, 2, 0, 1, 1);

        calkowanie = new QLabel(groupBox);
        calkowanie->setObjectName("calkowanie");
        calkowanie->setStyleSheet(QString::fromUtf8("font: 15pt \"Calibri\";\n"
                                                    "color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(calkowanie, 1, 0, 1, 1);

        wzmocn = new QDoubleSpinBox(groupBox);
        wzmocn->setObjectName("wzmocn");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wzmocn->sizePolicy().hasHeightForWidth());
        wzmocn->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(wzmocn, 0, 1, 1, 1);

        st_calk = new QDoubleSpinBox(groupBox);
        st_calk->setObjectName("st_calk");
        sizePolicy2.setHeightForWidth(st_calk->sizePolicy().hasHeightForWidth());
        st_calk->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(st_calk, 1, 1, 1, 1);

        st_rozn = new QDoubleSpinBox(groupBox);
        st_rozn->setObjectName("st_rozn");
        sizePolicy2.setHeightForWidth(st_rozn->sizePolicy().hasHeightForWidth());
        st_rozn->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(st_rozn, 2, 1, 1, 1);

        verticalLayout_3->addLayout(gridLayout_3);

        Reset_pid = new QPushButton(groupBox);
        Reset_pid->setObjectName("Reset_pid");

        verticalLayout_3->addWidget(Reset_pid);

        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName("groupBox_7");
        horizontalLayout = new QHBoxLayout(groupBox_7);
        horizontalLayout->setObjectName("horizontalLayout");
        Tryb_pod = new QRadioButton(groupBox_7);
        Tryb_pod->setObjectName("Tryb_pod");
        Tryb_pod->setChecked(true);

        horizontalLayout->addWidget(Tryb_pod);

        Tryb_przed = new QRadioButton(groupBox_7);
        Tryb_przed->setObjectName("Tryb_przed");

        horizontalLayout->addWidget(Tryb_przed);

        verticalLayout_3->addWidget(groupBox_7);

        verticalLayout_2->addWidget(groupBox);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName("gridLayout_2");
        Conf_Button = new QPushButton(groupBox_4);
        Conf_Button->setObjectName("Conf_Button");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Conf_Button->sizePolicy().hasHeightForWidth());
        Conf_Button->setSizePolicy(sizePolicy3);
        Conf_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                     "color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(Conf_Button, 0, 0, 1, 1);

        verticalLayout_2->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        wej_p = new QDoubleSpinBox(groupBox_2);
        wej_p->setObjectName("wej_p");

        gridLayout_4->addWidget(wej_p, 3, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"Calibri\";\n"
                                               "color: rgb(0, 0, 0);"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        wej_t = new QDoubleSpinBox(groupBox_2);
        wej_t->setObjectName("wej_t");
        wej_t->setEnabled(true);
        sizePolicy2.setHeightForWidth(wej_t->sizePolicy().hasHeightForWidth());
        wej_t->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(wej_t, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"Calibri\";\n"
                                                 "color: rgb(0, 0, 0);"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        wej_Amp = new QDoubleSpinBox(groupBox_2);
        wej_Amp->setObjectName("wej_Amp");

        gridLayout_4->addWidget(wej_Amp, 1, 1, 1, 1);

        wej_T = new QDoubleSpinBox(groupBox_2);
        wej_T->setObjectName("wej_T");

        gridLayout_4->addWidget(wej_T, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"Calibri\";\n"
                                                 "color: rgb(0, 0, 0);"));

        gridLayout_4->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"Calibri\";\n"
                                                 "color: rgb(0, 0, 0);"));

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";\n"
                                                 "color: rgb(0, 0, 0);"));

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

        war_stala = new QDoubleSpinBox(groupBox_2);
        war_stala->setObjectName("war_stala");

        gridLayout_4->addWidget(war_stala, 4, 1, 1, 1);

        verticalLayout_4->addLayout(gridLayout_4);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        sin = new QRadioButton(groupBox_3);
        sin->setObjectName("sin");
        sin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sin->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";\n"
                                             "color: rgb(0, 0, 0);\n"
                                             ""));

        verticalLayout_6->addWidget(sin);

        prost = new QRadioButton(groupBox_3);
        prost->setObjectName("prost");
        prost->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        prost->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                               "color: rgb(0, 0, 0);\n"
                                               ""));

        verticalLayout_6->addWidget(prost);

        skok = new QRadioButton(groupBox_3);
        skok->setObjectName("skok");
        skok->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        skok->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                              "color: rgb(0, 0, 0);\n"
                                              ""));

        verticalLayout_6->addWidget(skok);

        verticalLayout_4->addWidget(groupBox_3);

        verticalLayout_2->addWidget(groupBox_2);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        sizePolicy2.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy2);
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName("label_7");
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                 "color: rgb(0, 0, 0);\n"
                                                 ""));

        horizontalLayout_2->addWidget(label_7);

        interval = new QSpinBox(groupBox_5);
        interval->setObjectName("interval");
        sizePolicy2.setHeightForWidth(interval->sizePolicy().hasHeightForWidth());
        interval->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(interval);

        verticalLayout_7->addLayout(horizontalLayout_2);

        Buttons_layout = new QHBoxLayout();
        Buttons_layout->setObjectName("Buttons_layout");
        Start_Button = new QPushButton(groupBox_5);
        Start_Button->setObjectName("Start_Button");
        sizePolicy2.setHeightForWidth(Start_Button->sizePolicy().hasHeightForWidth());
        Start_Button->setSizePolicy(sizePolicy2);
        Start_Button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Start_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                      "color: rgb(0, 0, 0);\n"
                                                      ""));

        Buttons_layout->addWidget(Start_Button);

        Reset_Button = new QPushButton(groupBox_5);
        Reset_Button->setObjectName("Reset_Button");
        Reset_Button->setEnabled(true);
        sizePolicy2.setHeightForWidth(Reset_Button->sizePolicy().hasHeightForWidth());
        Reset_Button->setSizePolicy(sizePolicy2);
        Reset_Button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Reset_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                      "color: rgb(0, 0, 0);\n"
                                                      ""));

        Buttons_layout->addWidget(Reset_Button);

        Stop_Button = new QPushButton(groupBox_5);
        Stop_Button->setObjectName("Stop_Button");
        Stop_Button->setEnabled(true);
        sizePolicy2.setHeightForWidth(Stop_Button->sizePolicy().hasHeightForWidth());
        Stop_Button->setSizePolicy(sizePolicy2);
        Stop_Button->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Stop_Button->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                     "color: rgb(0, 0, 0);\n"
                                                     ""));

        Buttons_layout->addWidget(Stop_Button);

        verticalLayout_7->addLayout(Buttons_layout);

        verticalLayout_2->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName("groupBox_6");
        sizePolicy1.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(groupBox_6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        saveButton = new QPushButton(groupBox_6);
        saveButton->setObjectName("saveButton");
        saveButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                    "color: rgb(0, 0, 0);\n"
                                                    ""));

        verticalLayout_5->addWidget(saveButton);

        readButton = new QPushButton(groupBox_6);
        readButton->setObjectName("readButton");
        readButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                    "color: rgb(0, 0, 0);\n"
                                                    ""));

        verticalLayout_5->addWidget(readButton);

        verticalLayout_2->addWidget(groupBox_6);

        groupBox_8 = new QGroupBox(centralwidget);
        groupBox_8->setObjectName("groupBox_8");
        verticalLayout = new QVBoxLayout(groupBox_8);
        verticalLayout->setObjectName("verticalLayout");
        pushButtonKonfiguracjaSieci = new QPushButton(groupBox_8);
        pushButtonKonfiguracjaSieci->setObjectName("pushButtonKonfiguracjaSieci");
        pushButtonKonfiguracjaSieci->setStyleSheet(QString::fromUtf8("font: 11pt \"Calibri\";\n"
                                                                     "color: rgb(0, 0, 0);\n"
                                                                     ""));

        verticalLayout->addWidget(pushButtonKonfiguracjaSieci);

        verticalLayout_2->addWidget(groupBox_8);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 2, 1);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy4);
        widget1->setMinimumSize(QSize(1000, 300));

        gridLayout->addWidget(widget1, 0, 1, 1, 2);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        sizePolicy4.setHeightForWidth(widget2->sizePolicy().hasHeightForWidth());
        widget2->setSizePolicy(sizePolicy4);
        widget2->setMinimumSize(QSize(500, 300));

        gridLayout->addWidget(widget2, 1, 1, 1, 1);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName("widget3");
        sizePolicy4.setHeightForWidth(widget3->sizePolicy().hasHeightForWidth());
        widget3->setSizePolicy(sizePolicy4);
        widget3->setMinimumSize(QSize(500, 300));

        gridLayout->addWidget(widget3, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(skok, &QRadioButton::clicked, wej_t, &QDoubleSpinBox::setEnabled);
        QObject::connect(skok, &QRadioButton::clicked, wej_Amp, &QDoubleSpinBox::setDisabled);
        QObject::connect(skok, &QRadioButton::clicked, wej_T, &QDoubleSpinBox::setDisabled);
        QObject::connect(skok, &QRadioButton::clicked, wej_p, &QDoubleSpinBox::setDisabled);
        QObject::connect(sin, &QRadioButton::clicked, wej_t, &QDoubleSpinBox::setDisabled);
        QObject::connect(sin, &QRadioButton::clicked, wej_Amp, &QDoubleSpinBox::setEnabled);
        QObject::connect(sin, &QRadioButton::clicked, wej_T, &QDoubleSpinBox::setEnabled);
        QObject::connect(sin, &QRadioButton::clicked, wej_p, &QDoubleSpinBox::setDisabled);
        QObject::connect(prost, &QRadioButton::clicked, wej_t, &QDoubleSpinBox::setDisabled);
        QObject::connect(prost, &QRadioButton::clicked, wej_Amp, &QDoubleSpinBox::setEnabled);
        QObject::connect(prost, &QRadioButton::clicked, wej_T, &QDoubleSpinBox::setEnabled);
        QObject::connect(prost, &QRadioButton::clicked, wej_p, &QDoubleSpinBox::setEnabled);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(
            QCoreApplication::translate("MainWindow", "USTAWIENIA REGULATORA PID", nullptr));
        wzmocnienie->setText(
            QCoreApplication::translate("MainWindow",
                                        "<html><head/><body><p><span style=\" "
                                        "font-size:12pt;\">Wzmocnienie:</span></p></body></html>",
                                        nullptr));
        rozniczkowanie->setText(QCoreApplication::translate(
            "MainWindow",
            "<html><head/><body><p><span style=\" font-size:12pt;\">Sta\305\202a "
            "r\303\263\305\274niczkowania:</span></p></body></html>",
            nullptr));
        calkowanie->setText(QCoreApplication::translate(
            "MainWindow",
            "<html><head/><body><p><span style=\" font-size:12pt;\">Sta\305\202a "
            "ca\305\202kowania:</span></p></body></html>",
            nullptr));
        Reset_pid->setText(
            QCoreApplication::translate("MainWindow", "RESET PAMI\304\230CI", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow",
                                                         "Sposobu liczenia skumulowanego uchybu",
                                                         nullptr));
        Tryb_pod->setText(
            QCoreApplication::translate("MainWindow", "POD CA\305\201K\304\204", nullptr));
        Tryb_przed->setText(
            QCoreApplication::translate("MainWindow", "PRZED CA\305\201K\304\204", nullptr));
        groupBox_4->setTitle(
            QCoreApplication::translate("MainWindow", "USTAWIENIA MODELU ARX", nullptr));
        Conf_Button->setText(
            QCoreApplication::translate("MainWindow", "ZMIE\305\203 KONFIGURACJE", nullptr));
        groupBox_2->setTitle(
            QCoreApplication::translate("MainWindow", "USTAWIENIA GENERATORA", nullptr));
        label->setText(QCoreApplication::translate(
            "MainWindow",
            "<html><head/><body><p><span style=\" font-size:12pt;\">Chwila "
            "aktywacji:</span></p></body></html>",
            nullptr));
        label_2->setText(
            QCoreApplication::translate("MainWindow",
                                        "<html><head/><body><p><span style=\" "
                                        "font-size:12pt;\">Amplituda:</span></p></body></html>",
                                        nullptr));
        label_4->setText(QCoreApplication::translate(
            "MainWindow",
            "<html><head/><body><p><span style=\" "
            "font-size:12pt;\">Wype\305\202nienie:</span></p></body></html>",
            nullptr));
        label_3->setText(
            QCoreApplication::translate("MainWindow",
                                        "<html><head/><body><p><span style=\" "
                                        "font-size:12pt;\">Okres:</span></p></body></html>",
                                        nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow",
                                                     "Warto\305\233\304\207 sta\305\202a",
                                                     nullptr));
        groupBox_3->setTitle(
            QCoreApplication::translate("MainWindow", "KSZTA\305\201T GENERATORA", nullptr));
        sin->setText(QCoreApplication::translate("MainWindow", "Sinusoida", nullptr));
        prost->setText(QCoreApplication::translate("MainWindow", "Prostok\304\205t", nullptr));
        skok->setText(QCoreApplication::translate("MainWindow", "Skok jednostkowy", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "SYMULACJA", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202:", nullptr));
        Start_Button->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        Reset_Button->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        Stop_Button->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "PLIKI", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Zapisz do pliku", nullptr));
        readButton->setText(QCoreApplication::translate("MainWindow", "Odczytaj z pliku", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Sie\304\207", nullptr));
        pushButtonKonfiguracjaSieci->setText(
            QCoreApplication::translate("MainWindow", "Konfiguracja Sieci", nullptr));
#if QT_CONFIG(whatsthis)
        widget1->setWhatsThis(
            QCoreApplication::translate("MainWindow",
                                        "<html><head/><body><p><br/></p></body></html>",
                                        nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow
{};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
