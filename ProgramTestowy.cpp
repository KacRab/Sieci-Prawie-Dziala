#include "GenWartZadana.h"
#include "Manager.h"
#include "ModelARX.h"
#include "RegulatorPID.h"
#include "SprzezenieZwrotne.h"
#include <iomanip>
#include <iostream>
#include <vector>

#define PROGRAM

#ifdef DEBUG

void raportBleduSekwencji(std::vector<double> &spodz, std::vector<double> &fakt)
{
    constexpr size_t PREC = 3;
    std::cerr << std::fixed << std::setprecision(PREC);
    std::cerr << "  Spodziewany:\t";
    for (auto &el : spodz)
        std::cerr << el << ", ";
    std::cerr << "\n  Faktyczny:\t";
    for (auto &el : fakt)
        std::cerr << el << ", ";
    std::cerr << std::endl << std::endl;
}

bool porownanieSekwencji(std::vector<double> &spodz, std::vector<double> &fakt)
{
    constexpr double TOL = 1e-3; // tolerancja dla por�wna� zmiennoprzecinkowych
    bool result = fakt.size() == spodz.size();
    for (int i = 0; result && i < fakt.size(); i++)
        result = fabs(fakt[i] - spodz[i]) < TOL;
    return result;
}

void test_RegulatorP_brakPobudzenia()
{
    //Sygnatura testu:
    std::cerr << "RegP (k = 0.5) -> test zerowego pobudzenia: ";
    try {
        // Przygotowanie danych:
        PID instancjaTestowa(0.5);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja modelu:

        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SumU(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_RegulatorP_skokJednostkowy()
{
    //Sygnatura testu:
    std::cerr << "RegP (k = 0.5) -> test skoku jednostkowego: ";

    try {
        // Przygotowanie danych:
        PID instancjaTestowa(0.5);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0.0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
                      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SumU(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_RegulatorPI_skokJednostkowy_1()
{
    //Sygnatura testu:
    std::cerr << "RegPI (k = 0.5, TI = 1.0) -> test skoku jednostkowego nr 1: ";

    try {
        // Przygotowanie danych:
        PID instancjaTestowa(0.5, 1.0);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0,    1.5,  2.5,  3.5,  4.5,  5.5,  6.5,  7.5,  8.5,  9.5,
                      10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 19.5,
                      20.5, 21.5, 22.5, 23.5, 24.5, 25.5, 26.5, 27.5, 28.5, 29.5};

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SumU(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_RegulatorPI_skokJednostkowy_2()
{
    //Sygnatura testu:
    std::cerr << "RegPI (k = 0.5, TI = 10.0) -> test skoku jednostkowego nr 2: ";

    try {
        // Przygotowanie danych:
        PID instancjaTestowa(0.5, 10.0);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0, 0.6, 0.7, 0.8, 0.9, 1,   1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
                      2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3,   3.1, 3.2, 3.3, 3.4};

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SumU(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_RegulatorPID_skokJednostkowy()
{
    //Sygnatura testu:
    std::cerr << "RegPID (k = 0.5, TI = 10.0, TD = 0.2) -> test skoku jednostkowego: ";

    try {
        // Przygotowanie danych:
        PID instancjaTestowa(0.5, 10.0, 0.2);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0, 0.8, 0.7, 0.8, 0.9, 1,   1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
                      2, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3,   3.1, 3.2, 3.3, 3.4};

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SumU(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_ModelARX_brakPobudzenia()
{
    //Sygnatura testu:
    std::cerr << "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test zerowego pobudzenia: ";
    try {
        // Przygotowanie danych:
        ModelARX instancjaTestowa({-0.4}, {0.6}, 1, 0);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SimY(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_ModelARX_skokJednostkowy_1()
{
    //Sygnatura testu:
    std::cerr << "ModelARX (-0.4 | 0.6 | 1 | 0 ) -> test skoku jednostkowego nr 1: ";

    try {
        // Przygotowanie danych:
        ModelARX instancjaTestowa({-0.4}, {0.6}, 1, 0);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0,        0,        0.6,      0.84,     0.936,    0.9744,
                      0.98976,  0.995904, 0.998362, 0.999345, 0.999738, 0.999895,
                      0.999958, 0.999983, 0.999993, 0.999997, 0.999999, 1,
                      1,        1,        1,        1,        1,        1,
                      1,        1,        1,        1,        1,        1};

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SimY(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_ModelARX_skokJednostkowy_2()
{
    //Sygnatura testu:
    std::cerr << "ModelARX (-0.4 | 0.6 | 2 | 0 ) -> test skoku jednostkowego nr 2: ";

    try {
        // Przygotowanie danych:
        ModelARX instancjaTestowa({-0.4}, {0.6}, 2, 0);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu,
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0,        0,        0,        0.6,      0.84,     0.936,
                      0.9744,   0.98976,  0.995904, 0.998362, 0.999345, 0.999738,
                      0.999895, 0.999958, 0.999983, 0.999993, 0.999997, 0.999999,
                      1,        1,        1,        1,        1,        1,
                      1,        1,        1,        1,        1,        1};

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SimY(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_ModelARX_skokJednostkowy_3()
{
    //Sygnatura testu:
    std::cerr << "ModelARX (-0.4, 0.2 | 0.6, 0.3 | 2 | 0 ) -> test skoku jednostkowego nr 3: ";
    try {
        // Przygotowanie danych:
        ModelARX instancjaTestowa({-0.4, 0.2}, {0.6, 0.3}, 2, 0);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu,
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0,       0,       0,       0.6,     1.14,    1.236,   1.1664,  1.11936,
                      1.11446, 1.12191, 1.12587, 1.12597, 1.12521, 1.12489, 1.12491, 1.12499,
                      1.12501, 1.12501, 1.125,   1.125,   1.125,   1.125,   1.125,   1.125,
                      1.125,   1.125,   1.125,   1.125,   1.125,   1.125};

        // Symulacja modelu:
        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SimY(sygWe[i]);

        // Weryfikacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_UAR_1_skokJednostkowy()
{
    //Sygnatura testu:
    std::cerr << "UAR_1 -> test skoku jednostkowego: ";
    try {
        // Przygotowanie danych:
        PID testPID(0.5, 5.0, 0.2);
        ModelARX testARX({-0.4}, {0.6});
        SprzezenieZwrotne instancjaTestowa(testARX, testPID);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0.0,      0.0,      0.54,     0.756,    0.6708,   0.64008,
                      0.729,    0.810437, 0.834499, 0.843338, 0.8664,   0.8936,
                      0.911886, 0.923312, 0.93404,  0.944929, 0.954065, 0.961042,
                      0.966815, 0.971965, 0.97642,  0.980096, 0.983143, 0.985741,
                      0.987964, 0.989839, 0.991411, 0.992739, 0.993865, 0.994818};

        // Symulacja UAR:

        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SimUAR(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_UAR_2_skokJednostkowy()
{
    //Sygnatura testu:
    std::cerr << "UAR_2 (k = 2) -> test skoku jednostkowego: ";
    try {
        // Przygotowanie danych:
        PID testPID(0.5, 5.0, 0.2);
        ModelARX testARX({-0.4}, {0.6}, 2);
        SprzezenieZwrotne instancjaTestowa(testARX, testPID);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0.0,      0.0,      0.0,      0.54,     0.756,    0.9624,
                      0.87336,  0.841104, 0.771946, 0.821644, 0.863453, 0.93272,
                      0.952656, 0.965421, 0.954525, 0.955787, 0.957472, 0.969711,
                      0.978075, 0.985968, 0.987821, 0.989149, 0.989053, 0.990645,
                      0.992248, 0.994403, 0.995707, 0.996677, 0.997024, 0.997388};
        // Symulacja UAR:

        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SimUAR(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

void test_UAR_3_skokJednostkowy()
{
    //Sygnatura testu:
    std::cerr << "UAR_3 (kP=1.0,Ti=2.0) -> test skoku jednostkowego: ";
    try {
        // Przygotowanie danych:
        PID testPID(1.0, 2.0, 0.2);
        ModelARX testARX({-0.4}, {0.6}, 1);
        SprzezenieZwrotne instancjaTestowa(testARX, testPID);
        constexpr size_t LICZ_ITER = 30;
        std::vector<double> sygWe(LICZ_ITER);      // pobudzenie modelu (tu same 0)
        std::vector<double> spodzSygWy(LICZ_ITER); // spodziewana sekwencja wy (tu same 0)
        std::vector<double> faktSygWy(LICZ_ITER);  // faktyczna sekwencja wy

        // Symulacja skoku jednostkowego w chwili 1. (!!i - daje 1 dla i != 0);
        for (int i = 0; i < LICZ_ITER; i++)
            sygWe[i] = !!i;
        spodzSygWy = {0.0,      0.0,      1.02,     1.608,    1.1028,   0.41736,
                      0.546648, 1.20605,  1.43047,  0.999176, 0.615056, 0.799121,
                      1.21304,  1.26025,  0.939289, 0.748507, 0.927166, 1.17292,
                      1.14155,  0.921616, 0.843258, 0.990018, 1.12577,  1.068,
                      0.927024, 0.908125, 1.01702,  1.08484,  1.02618,  0.941508};
        // Symulacja UAR:

        for (int i = 0; i < LICZ_ITER; i++)
            faktSygWy[i] = instancjaTestowa.SimUAR(sygWe[i]);

        // Walidacja poprawno�ci i raport:
        if (porownanieSekwencji(spodzSygWy, faktSygWy))
            std::cerr << "OK!\n";
        else {
            std::cerr << "FAIL!\n";
            raportBleduSekwencji(spodzSygWy, faktSygWy);
        }
    } catch (...) {
        std::cerr << "INTERUPTED! (niespodziwany wyjatek)\n";
    }
}

int main()
{
    test_RegulatorP_brakPobudzenia();
    test_RegulatorP_skokJednostkowy();
    test_RegulatorPI_skokJednostkowy_1();
    test_RegulatorPI_skokJednostkowy_2();
    test_RegulatorPID_skokJednostkowy();

    test_ModelARX_brakPobudzenia();
    test_ModelARX_skokJednostkowy_1();
    test_ModelARX_skokJednostkowy_2();
    test_ModelARX_skokJednostkowy_3();

    test_UAR_1_skokJednostkowy();
    test_UAR_2_skokJednostkowy();
    test_UAR_3_skokJednostkowy();
}

#endif

#ifdef PROGRAM

void main()
{
    setlocale(LC_ALL, "");
    std::vector<double> A = {-0, 4};
    std::vector<double> B = {0, 6};
    int delay = 0;

    constexpr size_t PREC = 2;
    std::cout << std::fixed << std::setprecision(PREC);

    try {
        PID testPID(0.5, 5.0, 0.2);
        ModelARX testARX({-0.4}, {0.6});
        SprzezenieZwrotne instancjaTestowa({-0.4}, {0.6}, 1, 0.5, 5.0, 0.2);
        GenWartZadana gen(Sygnal::Sin, 0.0, 1.0, 1.0, 0.5);

        /*for (double i = 0.0; i < 10.0; i += 0.01) {
            double wart = gen.GenerujSygnal(i);
            std::vector<double> wynik = instancjaTestowa.SimUAR(wart);
            std::cout << "\tCzas: " << wynik[0] << "\t|EI: " << wynik[1]
                      << "\t | UI_P: " << wynik[2] << "\t | UI_I: " << wynik[3]
                      << "\t | UI_D: " << wynik[4] << "\t | U: " << wynik[5]
                      << "\t | Y: " << wynik[6] << "\n";
        };*/
    } catch (const std::invalid_argument &e) {
        std::cerr << "B��d: " << e.what() << "\n";
    }
}

#endif
