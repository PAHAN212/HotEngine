#include "Engine.h"

float Engine::GetTadd(float V)
{
    float M = GetValueM(this->M, this->V, V);
    return M * this->Hm + V * V * this->Hv;
}

float Engine::GetTsub(float Tenv)
{
    return this->C * (this->Teng - Tenv);
}

float Engine::GetAcceleration(float V)
{
    float M = GetValueM(this->M, this->V, V);
    return this->I * M;
}

float Engine::GetTeng()
{
    return this->Teng;
}

void Engine::SetTeng(float Teng)
{
    this->Teng = Teng;
}

float Engine::GetTmax()
{
    return this->Tmax;
}


float Engine::GetValueM(vector <float> M, vector <float> V, float Vcurrent)
{
    float m1 = 0;
    float v1 = 0;
    float m2;
    float v2;

    for (int i = 0; i < M.size(); i++)
    {
        if (Vcurrent >= V[i]) {
            m1 = M[i];
            v1 = V[i];
        }
        if (Vcurrent < V[i]) {
            m2 = M[i];
            v2 = V[i];

            float k = (m1 - m2) / (v1 - v2);
            float b = m2 - k * v2;
            return (k * Vcurrent + b);
        }
        else { continue; }
    }

    return 0;
}




