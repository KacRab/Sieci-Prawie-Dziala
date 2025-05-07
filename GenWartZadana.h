#pragma once
#include <QDebug>
#include <cmath>
#include <vector>
//#define M_PI       3.14159265358979323846   // pi

enum class Sygnal { Skok, Prostokat, Sin, Nieustawiony };

class GenWartZadana
{
public:
    GenWartZadana(Sygnal typ = Sygnal::Skok,
                  double t = 0.0,
                  double Amp = 1.0,
                  double T = 1.0,
                  double p = 0.5,
                  double S = 0)
        : typ(typ)
        , t(t)
        , Amp(Amp)
        , T(T)
        , p(p)
    {}
    ~GenWartZadana() {};

    double GenerujSygnal(double czas)
    {
        switch (typ) {
        case Sygnal::Skok:
            return (czas <= t) ? S : 0.0;
        case Sygnal::Prostokat:
            return (fmod(czas, T) < p * T) ? Amp + S : S;
        case Sygnal::Sin:
            return Amp * std::sin(2 * M_PI * (fmod(czas, T) / T)) + S;
        default:
            return 0.0;
        }
    }
    void setGen(Sygnal typ, std::vector<double> &ParametryGen)
    {
        this->typ = typ;
        t = ParametryGen[0];
        Amp = ParametryGen[1];
        T = ParametryGen[2];
        p = ParametryGen[3];
        S = ParametryGen[4];
    }

private:
    Sygnal typ; // typ generowanego sygnalu
    double t;   // chwila aktywacji
    double Amp; // wart stala
    double T;   // okres
    double p;   // wypelnienie
    double S;   // wartosc stala
};
