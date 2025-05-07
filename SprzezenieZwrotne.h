#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

class SprzezenieZwrotne
{
public:
    SprzezenieZwrotne(const std::vector<double> &A = {0.0},
                      const std::vector<double> &B = {0.0},
                      int opoznienie = 0,
                      double wzmocienie = 0.0,
                      double stala_calkowania = 0.0,
                      double stala_rozniczkowania = 0.0)
        : pid(wzmocienie, stala_calkowania, stala_rozniczkowania)
        , model(A, B, opoznienie)
        , wartRegulowana(0.0) {};

    ~SprzezenieZwrotne() {};

    std::vector<double> SimUAR(double wartZadana)
    {
        double uchyb = wartZadana - wartRegulowana;
        std::vector<double> sterowanie = pid.SumU(uchyb);
        wartRegulowana = model.SimY(sterowanie[3]);

        return {wartZadana,
                uchyb,
                sterowanie[0],
                sterowanie[1],
                sterowanie[2],
                sterowanie[3],
                wartRegulowana};
    }

    std::vector<double> SimPIDOnline(double wartZadana)
    {
        double uchyb = wartZadana - wartRegulowana;
        std::vector<double> sterowanie = pid.SumU(uchyb);

        return {wartZadana,
                uchyb,
                sterowanie[0],
                sterowanie[1],
                sterowanie[2],
                sterowanie[3],
                wartRegulowana};
    }

    double zwrocY(double sygnal)
    {
        double wynik = model.SimY(sygnal);
        wartRegulowana = wynik;
        return wynik;
    }

    void setRegulowana(double regulowana) { wartRegulowana = regulowana; }

    void setPID(std::vector<double> &ParametryPID) { pid.setPID(ParametryPID); }
    void setTrybPID(const bool Tryb) { pid.setTryb(Tryb); }
    void ResetPID() { pid.ResetPID(); }
    void ResetSim()
    {
        wartRegulowana = 0.0;
        pid.ResetPID();
        model.ResetARX();
    }
    void setARX(std::vector<double> &A,
                std::vector<double> &B,
                int opoznienie = 0,
                double zaklucenia = 0)
    {
        model.setARX(A, B, opoznienie, zaklucenia);
    }

private:
    PID pid;
    ModelARX model;
    double wartRegulowana;
};
