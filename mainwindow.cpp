#include "mainwindow.h"
#include <QMessageBox>
#include "Manager.h"
#include "qcustomplot.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Manager *manager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , manager(manager)
    , timer(nullptr)
    , timeStep(0)
{
    ui->setupUi(this);

    // Ustawianie zakresów
    ui->st_calk->setRange(0, 9999.0);
    ui->st_rozn->setRange(0, 9999.0);
    ui->wzmocn->setRange(0.01, 9999.0);
    ui->wej_t->setRange(0, 9999.0);
    ui->wej_Amp->setRange(0, 9999.0);
    ui->wej_T->setRange(0.5, 9999.0);
    ui->wej_p->setRange(0.01, 0.99);
    ui->interval->setRange(1, 9999);
    ui->war_stala->setRange(-9999.9, 9999.9);

    // Ustawianie wartości początkowych
    ui->st_calk->setValue(5.00);
    ui->st_rozn->setValue(0.20);
    ui->wzmocn->setValue(0.50);
    ui->wej_t->setValue(1);
    ui->wej_Amp->setValue(1);
    ui->wej_T->setValue(1);
    ui->wej_p->setValue(0.5);

    A = {-0.4, 0, 0};
    B = {0.6, 0, 0};
    opoznienie = 1;
    zaklucenie = 0;
    // Inicjalizacja wykresów
    initCharts();

    // NetworkSettings *networkSettings = new NetworkSettings(manager, this);

    networkSettings = new NetworkSettings(manager, this);

    connect(networkSettings,
            &NetworkSettings::regulatorModeActivated,
            this,
            &MainWindow::configureRegulatorMode);
    connect(networkSettings,
            &NetworkSettings::objectModeActivated,
            this,
            &MainWindow::configureObjectMode);
    connect(networkSettings,
            &NetworkSettings::networkModeDisabled,
            this,
            &MainWindow::configureLocalMode);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Conf_Button_clicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Ustawienia Modelu ARX");
    QVBoxLayout form(&dialog);

    // Współczynniki wektora A:
    QGroupBox *groupA = new QGroupBox("Współczynniki wektora A", &dialog);
    QHBoxLayout *layoutA = new QHBoxLayout(groupA);
    QDoubleSpinBox Aa, Ab, Ac;
    Aa.setRange(-9999.0, 9999.0);
    Ab.setRange(-9999.0, 9999.0);
    Ac.setRange(-9999.0, 9999.0);
    Aa.setValue(A[0]);
    Ab.setValue(A[1]);
    Ac.setValue(A[2]);
    layoutA->addWidget(&Aa);
    layoutA->addWidget(&Ab);
    layoutA->addWidget(&Ac);

    // Współczynniki wektora B:
    QGroupBox *groupB = new QGroupBox("Współczynniki wektora B", &dialog);
    QHBoxLayout *layoutB = new QHBoxLayout(groupB);
    QDoubleSpinBox Ba, Bb, Bc;
    Ba.setRange(-9999.0, 9999.0);
    Bb.setRange(-9999.0, 9999.0);
    Bc.setRange(-9999.0, 9999.0);
    Ba.setValue(B[0]);
    Bb.setValue(B[1]);
    Bc.setValue(B[2]);
    layoutB->addWidget(&Ba);
    layoutB->addWidget(&Bb);
    layoutB->addWidget(&Bc);

    // Opóźnienie i Zakłócenia:
    QGroupBox *groupC = new QGroupBox("Opóźnienie i Zakłócenia", &dialog);
    QFormLayout *layoutC = new QFormLayout(groupC);
    QDoubleSpinBox opoznienieSpinBox, zaklucenieSpinBox;
    opoznienieSpinBox.setRange(1, 9999.0);
    zaklucenieSpinBox.setRange(0, 9999.0);
    zaklucenieSpinBox.setSingleStep(0.01);
    opoznienieSpinBox.setDecimals(0);
    opoznienieSpinBox.setValue(opoznienie);
    zaklucenieSpinBox.setValue(zaklucenie);
    layoutC->addRow("Opóźnienie:", &opoznienieSpinBox);
    layoutC->addRow("Zakłócenia:", &zaklucenieSpinBox);

    form.addWidget(groupA);
    form.addWidget(groupB);
    form.addWidget(groupC);

    QDialogButtonBox buttons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    form.addWidget(&buttons);

    connect(&buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        A = {Aa.value(), Ab.value(), Ac.value()};
        B = {Ba.value(), Bb.value(), Bc.value()};
        opoznienie = static_cast<int>(opoznienieSpinBox.value());
        zaklucenie = zaklucenieSpinBox.value();
        manager->setModelARX(A, B, opoznienie, zaklucenie);
    }
}

void MainWindow::initCharts()
{
    // Wykres 1: Wartości
    chart = new QCustomPlot(ui->widget1);
    chart->setGeometry(ui->widget1->rect());
    chart->addGraph();
    chart->graph(0)->setPen(QPen(Qt::blue));
    chart->graph(0)->setName("Wartość Zadana");
    chart->addGraph();
    chart->graph(1)->setPen(QPen(Qt::red));
    chart->graph(1)->setName("Wartość Regulowana");
    chart->xAxis->setLabel("Czas");
    chart->yAxis->setLabel("Wartość");
    chart->legend->setVisible(true);
    chart->legend->setBrush(QBrush(QColor(255, 255, 255, 150)));
    chart->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    chart->setParent(ui->widget1);
    chart->show();

    // Wykres 2: Uchyb
    chart2 = new QCustomPlot(ui->widget2);
    chart2->setGeometry(ui->widget2->rect());
    chart2->addGraph();
    chart2->graph(0)->setPen(QPen(Qt::blue));
    chart2->graph(0)->setName("Uchyb");
    chart2->graph(0)->setPen(QPen(Qt::blue));
    chart2->xAxis->setLabel("Czas");
    chart2->yAxis->setLabel("Uchyb");
    chart2->legend->setVisible(true);
    chart2->legend->setBrush(QBrush(QColor(255, 255, 255, 150)));
    chart2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    chart2->setParent(ui->widget2);
    chart2->show();

    // Wykres 3: Sterowanie
    chart3 = new QCustomPlot(ui->widget3);
    chart3->setGeometry(ui->widget3->rect());
    chart3->addGraph();
    chart3->graph(0)->setPen(QPen(Qt::blue));
    chart3->graph(0)->setName("Sterowanie");
    chart3->addGraph();
    chart3->graph(1)->setPen(QPen(Qt::red));
    chart3->graph(1)->setName("Część proporcjonalna sterowania");
    chart3->addGraph();
    chart3->graph(2)->setPen(QPen(Qt::green));
    chart3->graph(2)->setName("Część całkująca sterowania");
    chart3->addGraph();
    chart3->graph(3)->setPen(QPen(Qt::magenta));
    chart3->graph(3)->setName("Część różniczkująca sterowania");
    chart3->xAxis->setLabel("Czas");
    chart3->yAxis->setLabel("Sterowanie");
    chart3->legend->setVisible(true);
    chart3->legend->setBrush(QBrush(QColor(255, 255, 255, 150)));
    chart3->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    chart3->setParent(ui->widget3);
    chart3->show();

    resizeCharts();
}

void MainWindow::resizeCharts()
{
    chart->setGeometry(ui->widget1->rect());
    chart2->setGeometry(ui->widget2->rect());
    chart3->setGeometry(ui->widget3->rect());
    chart->replot();
    chart2->replot();
    chart3->replot();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    resizeCharts();
}

void MainWindow::updateChart()
{
    WY = manager->Symuluj(timeStep);

    double wartZad = WY[0];
    double wartReg = WY[6];
    double EI = WY[1];
    double u = WY[5];
    double uip = WY[2];
    double uii = WY[3];
    double uid = WY[4];

    int LimitDanych = 300;

    auto PrzytnijWykres = [&](QCPGraph *graph) {
        if (graph->data()->size() > LimitDanych) {
            graph->data()->removeBefore(timeStep - LimitDanych * 0.01);
        }
    };

    // Dodanie danych do wykresów
    chart->graph(0)->addData(timeStep, wartZad);
    chart->graph(1)->addData(timeStep, wartReg);
    chart2->graph(0)->addData(timeStep, EI);
    chart3->graph(0)->addData(timeStep, u);
    chart3->graph(1)->addData(timeStep, uip);
    chart3->graph(2)->addData(timeStep, uii);
    chart3->graph(3)->addData(timeStep, uid);

    // Przycięcie wykresów
    PrzytnijWykres(chart->graph(0));
    PrzytnijWykres(chart->graph(1));
    PrzytnijWykres(chart2->graph(0));
    PrzytnijWykres(chart3->graph(0));
    PrzytnijWykres(chart3->graph(1));
    PrzytnijWykres(chart3->graph(2));
    PrzytnijWykres(chart3->graph(3));

    //Dopasowanie skali osi Y na podstawie wszystkich serii na wykresie
    auto rescaleYAxis = [](QCustomPlot *plot) {
        double minVal = std::numeric_limits<double>::max();
        double maxVal = std::numeric_limits<double>::lowest();

        for (int i = 0; i < plot->graphCount(); ++i) {
            QCPGraph *graph = plot->graph(i);
            if (!graph->data()->isEmpty()) {
                for (auto it = graph->data()->begin(); it != graph->data()->end(); ++it) {
                    minVal = std::min(minVal, it->value);
                    maxVal = std::max(maxVal, it->value);
                }
            }
        }

        if (minVal >= maxVal || (fabs(minVal) < 0.1 && fabs(maxVal) < 0.1)) {
            plot->yAxis->setRange(-0.1, 0.1);
        } else {
            plot->yAxis->setRange(minVal - 0.1 * fabs(minVal), maxVal + 0.1 * fabs(maxVal));
        }
    };

    rescaleYAxis(chart);
    rescaleYAxis(chart2);
    rescaleYAxis(chart3);

    // Ustawienie zakresu X:
    double xMin, xMax;
    if (timeStep < 3.0) {
        xMin = (timeStep > 3) ? (timeStep - 3) : 0.0;
        xMax = 3.0;
    } else {
        xMin = (timeStep > 3) ? (timeStep - 3) : 0.0;
        xMax = timeStep;
    }

    chart->xAxis->setRange(xMin, xMax);
    chart2->xAxis->setRange(xMin, xMax);
    chart3->xAxis->setRange(xMin, xMax);

    chart->replot();
    chart2->replot();
    chart3->replot();

    timeStep += 0.01;
}

void MainWindow::on_Start_Button_clicked()
{
    ksztalt = (ui->sin->isChecked() == true) ? Sygnal::Sin : ksztalt;
    ksztalt = (ui->prost->isChecked() == true) ? Sygnal::Prostokat : ksztalt;
    ksztalt = (ui->skok->isChecked() == true) ? Sygnal::Skok : ksztalt;
    if (ksztalt == Sygnal::Nieustawiony) {
        QMessageBox::critical(this, "Zła wartość!", "Nie wybrano kształtu sygnału.");
        return;
    } else {
        confGen();
        if (!timer) {
            timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &MainWindow::updateChart);
        }
        timer->start(ui->interval->value());
    }
}

void MainWindow::on_Stop_Button_clicked()
{
    if (timer) {
        timer->stop();
    }
}

void MainWindow::on_Reset_Button_clicked()
{
    chart->graph(0)->data()->clear();
    chart->graph(1)->data()->clear();
    chart->replot();

    chart2->graph(0)->data()->clear();
    chart2->replot();

    chart3->graph(0)->data()->clear();
    chart3->graph(1)->data()->clear();
    chart3->graph(2)->data()->clear();
    chart3->graph(3)->data()->clear();
    chart3->replot();

    manager->ResetSim();
    ui->interval->setValue(1);
    timeStep = 0.0;

    on_Stop_Button_clicked();
}

void MainWindow::confRegPID()
{
    std::vector<double> ParametryPID = {ui->wzmocn->value(),
                                        ui->st_calk->value(),
                                        ui->st_rozn->value()};
    manager->setRegulatorPID(ParametryPID);
}

void MainWindow::confGen()
{
    ksztalt = (ui->sin->isChecked() == true) ? Sygnal::Sin : ksztalt;
    ksztalt = (ui->prost->isChecked() == true) ? Sygnal::Prostokat : ksztalt;
    ksztalt = (ui->skok->isChecked() == true) ? Sygnal::Skok : ksztalt;

    std::vector<double> ParametryGen = {ui->wej_t->value(),
                                        ui->wej_Amp->value(),
                                        ui->wej_T->value(),
                                        ui->wej_p->value(),
                                        ui->war_stala->value()};
    manager->setGenerator(ksztalt, ParametryGen);
}

void MainWindow::on_wzmocn_editingFinished()
{
    confRegPID();
}
void MainWindow::on_st_calk_editingFinished()
{
    confRegPID();
}
void MainWindow::on_st_rozn_editingFinished()
{
    confRegPID();
}

void MainWindow::on_saveButton_clicked()
{
    qDebug() << "Zapis: A =" << A;
    qDebug() << "Zapis: B =" << B;
    qDebug() << "Zapis: opoznienie =" << opoznienie << " zaklucenie =" << zaklucenie;

    manager->zapisz({ui->wzmocn->value(), ui->st_calk->value(), ui->st_rozn->value()},
                    A,
                    B,
                    opoznienie,
                    zaklucenie,
                    {ui->wej_t->value(),
                     ui->wej_Amp->value(),
                     ui->wej_T->value(),
                     ui->wej_p->value(),
                     ui->war_stala->value()});
}

void MainWindow::on_readButton_clicked()
{
    std::vector<double> ParametryPID, ParametryGen;

    manager->odczyt(ParametryPID, A, B, opoznienie, zaklucenie, ParametryGen);
    if (ParametryPID.size() == 3 && A.size() == 3 && B.size() == 3 && ParametryGen.size() == 5) {
        ui->wzmocn->setValue(ParametryPID[0]);
        ui->st_calk->setValue(ParametryPID[1]);
        ui->st_rozn->setValue(ParametryPID[2]);
        ui->wej_t->setValue(ParametryGen[0]);
        ui->wej_Amp->setValue(ParametryGen[1]);
        ui->wej_T->setValue(ParametryGen[2]);
        ui->wej_p->setValue(ParametryGen[3]);
        ui->war_stala->setValue(ParametryGen[4]);
    }
}

void MainWindow::on_interval_editingFinished()
{
    if (timer) {
        timer->setInterval(ui->interval->value());
    }
}

void MainWindow::on_wej_t_editingFinished()
{
    confGen();
}
void MainWindow::on_wej_Amp_editingFinished()
{
    confGen();
}
void MainWindow::on_wej_T_editingFinished()
{
    confGen();
}
void MainWindow::on_wej_p_editingFinished()
{
    confGen();
}

void MainWindow::on_sin_toggled(bool checked)
{
    Q_UNUSED(checked);
    confGen();
}

void MainWindow::on_prost_toggled(bool checked)
{
    Q_UNUSED(checked);
    confGen();
}

void MainWindow::on_skok_toggled(bool checked)
{
    Q_UNUSED(checked);
    confGen();
}

void MainWindow::on_Reset_pid_clicked()
{
    manager->ResetPID();
}

void MainWindow::on_Tryb_pod_toggled(bool checked)
{
    Q_UNUSED(checked);
    manager->setTrybPID(true);
}

void MainWindow::on_Tryb_przed_toggled(bool checked)
{
    Q_UNUSED(checked);
    manager->setTrybPID(false);
}

void MainWindow::on_war_stala_editingFinished()
{
    confGen();
}

void MainWindow::on_pushButtonKonfiguracjaSieci_clicked()
{
    if (!networkSettings) {
        networkSettings = new NetworkSettings(manager, this); // Przekazanie głównego managera
    }
    networkSettings->show();
    networkSettings->raise(); // Przesunięcie na pierwszy plan
    networkSettings->activateWindow();
}

void MainWindow::configureRegulatorMode()
{
    ui->Conf_Button->setEnabled(false);

    qDebug() << "Tryb sieciowy regulatora: ARX zablokowany, sterowanie odblokowane.";
}

void MainWindow::configureObjectMode()
{
    ui->groupBox->setEnabled(false);   //Ustawienia regulatora PID
    ui->groupBox_2->setEnabled(false); //Ustawienia generatora
    ui->groupBox_5->setEnabled(false); //Pzyciski start stop reset

    qDebug() << "Tryb sieciowy obiektu: sterowanie zablokowane, ARX odblokowany.";
}

void MainWindow::configureLocalMode()
{
    ui->groupBox->setEnabled(true);    //Ustawienia regulatora PID
    ui->Conf_Button->setEnabled(true); // Odblokowanie ARX
    ui->groupBox_2->setEnabled(true);  //Ustawienia generatora
    ui->groupBox_5->setEnabled(true);  //Pzyciski start stop reset

    qDebug() << "Tryb lokalny: wszystkie kontrolki odblokowane.";
}
