#include <iostream>
#include <vector>


using namespace std;

class Engine
{
public:
    float I;
    vector <float> M;
    vector <float> V;
    float Tmax;
    float Hm;
    float Hv;
    float C;

    Engine(float I, vector <float> M, vector <float> V, float Tmax, float Hm, float Hv, float C)
    {
        this->I = I; this->M = M; this->V = V; this->Tmax = Tmax;
        this->Hm = Hm; this->Hv = Hv; this->C = C;
    }

    float GetTimeToOverheating(float Tenv, float SamStepT)
    {
        float Teng = Tenv;
        float time = 0;
        float V = 0;
        float M;

        while (true)
        {
            M = GetValueM(this->M, this->V, V);
            float Tadd = (M * this->Hm + V * V * this->Hv) * SamStepT;
            float Tsub = (this->C * (Tenv - Teng)) * SamStepT;
            Teng = Teng + Tadd - Tsub;
            V += this->I * M * SamStepT;
            time += SamStepT;
            std::cout << "t = " << time << " Teng = " << Teng << endl;
            if (Teng > this->Tmax) return time;

        }
    }

    float GetValueM(vector <float> M, vector <float> V, float Vcurrent)
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
            if (Vcurrent <  V[i]) {
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

};

int main()
{
    const int n = 6; // Длинна массива точек  кусочно-линейной 

    // Задаем зависимость мощьности от оборотов и остальные параметры двигателя
    vector <float> M = { 20, 75, 100, 105, 75, 0 };
    vector <float> V = { 0, 75, 150, 200, 250, 300 };
    
    Engine engine = Engine(0.1f, M, V, 110.0f, 0.01f, 0.0001f, 0.1f);
    
    float Tenv;
    std::cout << "Enter the ambient temperature: ";
    std::cin >> Tenv;

    // Шаг дискретизации симуляции процесса по времени.
    // Чем меньше шаг тем точнее, но требуется больше вычеслений. 
    float SamStepT = 0.1f;
    std::cout << engine.GetTimeToOverheating(Tenv, SamStepT);

    return 0;
}



