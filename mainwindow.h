#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include "Manager.h"
#include "networksettings.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Manager *manager, QWidget *parent = nullptr);
    ~MainWindow();

    void configureRegulatorMode();
    void configureObjectMode();
    void configureLocalMode();

private slots:
    // Przyciski:
    void on_Start_Button_clicked();
    void on_Reset_Button_clicked();
    void on_Stop_Button_clicked();
    void on_Conf_Button_clicked();
    void on_Reset_pid_clicked();
    void on_saveButton_clicked();
    void on_readButton_clicked();

    //Pomocnicze:
    void initCharts();
    void updateChart();
    void confRegPID();
    void confGen();
    void resizeCharts();
    void resizeEvent(QResizeEvent *event) override;

    //Koniec Edycji:
    void on_st_calk_editingFinished();
    void on_st_rozn_editingFinished();
    void on_interval_editingFinished();
    void on_wzmocn_editingFinished();
    void on_wej_t_editingFinished();
    void on_wej_Amp_editingFinished();
    void on_wej_T_editingFinished();
    void on_wej_p_editingFinished();

    // Radio buttony:
    void on_sin_toggled(bool checked);
    void on_prost_toggled(bool checked);
    void on_skok_toggled(bool checked);
    void on_Tryb_pod_toggled(bool checked);
    void on_Tryb_przed_toggled(bool checked);

    void on_war_stala_editingFinished();

    void on_pushButtonKonfiguracjaSieci_clicked();
    //void onModeChanged(bool isNetworkMode);

private:
    NetworkSettings *networkSettings;

    std::vector<double> A;
    std::vector<double> B;
    double zaklucenie;
    int opoznienie;

    Ui::MainWindow *ui;
    Manager *manager;

    QCustomPlot *chart;
    QCustomPlot *chart2;
    QCustomPlot *chart3;

    QTimer *timer;

    double timeStep = 0.0;
    Sygnal ksztalt = Sygnal::Nieustawiony;

    std::vector<double> WY;
};
