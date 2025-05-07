#pragma once
#include <vector>

class PID
{
public:
    PID(double wzmocnienie, double stala_calkowania = 0.0, double stala_rozniczkowania = 0.0)
        : wzmocnienie(wzmocnienie)
        , stala_calkowania(stala_calkowania)
        , stala_rozniczkowania(stala_rozniczkowania)
        , Sum_EI(0.0)
        , EI_ost(0.0)
        , U(0.0)
        , Tryb(true) {};

    ~PID() {};

    std::vector<double> SumU(double EI)
    {
        double UI_P = wzmocnienie * EI;
        double UI_I = 0.0;
        if (stala_calkowania != 0.0) {
            if (Tryb) { // Pod calka
                this->Sum_EI += EI / stala_calkowania;
                UI_I = Sum_EI;
            } else { // Przed calka
                this->Sum_EI += EI;
                UI_I = Sum_EI / stala_calkowania;
            }
        }
        double UI_D = stala_rozniczkowania * (EI - EI_ost);
        U = UI_P + UI_I + UI_D;
        EI_ost = EI;

        return {UI_P, UI_I, UI_D, U};
    };
    void ResetPID()
    {
        Sum_EI = 0.0;
        EI_ost = 0.0;
    }
    void setTryb(const bool Tryb) { this->Tryb = Tryb; }
    void setPID(const std::vector<double> &ParametryPID)
    {
        this->wzmocnienie = ParametryPID[0];
        this->stala_calkowania = ParametryPID[1];
        this->stala_rozniczkowania = ParametryPID[2];
    }

private:
    double wzmocnienie, stala_calkowania, stala_rozniczkowania, Sum_EI, EI_ost, U;
    bool Tryb;
};
