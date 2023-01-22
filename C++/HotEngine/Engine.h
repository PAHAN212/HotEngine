#include <iostream>
#include <vector>
#include "IEngine.h"

using namespace std;

class Engine : public IEngine
{
public:
    float I;
    vector <float> M;
    vector <float> V;
    float Tmax;
    float Teng;
    float Hm;
    float Hv;
    float C;

    Engine(float I, vector <float> M, vector <float> V, float Tmax, float Hm, float Hv, float C)
    {
        this->I = I; this->M = M; this->V = V; this->Tmax = Tmax;
        this->Hm = Hm; this->Hv = Hv; this->C = C;
    }

    float GetValueM(vector <float> M, vector <float> V, float Vcurrent);

    // Унаследовано через IEngine
    float GetTadd(float V) override;

    float GetTsub(float V) override;

    float GetAcceleration(float V) override;

    void SetTeng(float Teng) override;

    virtual float GetTeng() override;

    virtual float GetTmax() override;










};
