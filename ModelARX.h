#pragma once
#include <deque>
#include <random>
#include <vector>

class ModelARX
{
public:
    ModelARX(const std::vector<double> &A,
             const std::vector<double> &B,
             int opoznienie = 1,
             double zaklucenia = 0)
        : A(A)
        , B(B)
        , opoznienie(opoznienie)
        , zaklucenia(zaklucenia)
    {
        Queue_U = std::deque<double>(B.size() + opoznienie, 0.0);
        Queue_Y = std::deque<double>(A.size(), 0.0);
    }
    ~ModelARX() {}

    double SimY(double sygnal)
    {
        std::random_device rng_seed;
        std::mt19937 rng;
        rng.seed(rng_seed());

        Queue_U.push_front(sygnal);
        Queue_U.pop_back();

        double Y = 0.0;

        for (size_t i = 0; i < B.size(); i++) {
            Y += B[i] * Queue_U[i + opoznienie];
        }
        for (size_t i = 0; i < A.size(); i++) {
            Y -= A[i] * Queue_Y[i];
        }
        if (zaklucenia != 0) {
            std::normal_distribution<double> gausDist(-zaklucenia, zaklucenia);
            Y += gausDist(rng);
        }

        Queue_Y.push_front(Y);
        Queue_Y.pop_back();

        return Y;
    }

    void setARX(std::vector<double> &A,
                std::vector<double> &B,
                int opoznienie = 0,
                double zaklucenia = 0)
    {
        this->A = A;
        this->B = B;
        this->opoznienie = opoznienie;
        this->zaklucenia = zaklucenia;
        Queue_U.resize(B.size() + opoznienie, 0.0);
        Queue_Y.resize(A.size(), 0.0);
    }

    void ResetARX()
    {
        for (size_t i = 0; i < B.size() + opoznienie; i++) {
            Queue_U.push_front(0.0);
            Queue_U.pop_back();
        }
        for (size_t i = 0; i < A.size(); i++) {
            Queue_Y.push_front(0.0);
            Queue_Y.pop_back();
        }
    }

private:
    std::vector<double> A, B;
    int opoznienie;
    double zaklucenia;
    std::deque<double> Queue_U, Queue_Y;
};
