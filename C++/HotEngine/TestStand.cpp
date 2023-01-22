#include <iostream>

#include "TestStand.h"
#include "IEngine.h"

using namespace std;

float TestStand::GetTimeToOverheating(IEngine & engine, float Tenv, float SamStepT)
{
    engine.SetTeng(Tenv);
    float Teng = Tenv;
    float time = 0;
    float V = 0;
    float M;

    while (true)
    {
        float Tadd = engine.GetTadd(V) * SamStepT;
        float Tsub = engine.GetTsub(Tenv) * SamStepT;
        engine.SetTeng(engine.GetTeng() + Tadd - Tsub);
        V += engine.GetAcceleration(V) * SamStepT;

        time += SamStepT;
        std::cout << "t = " << time << " Teng = " << engine.GetTeng() << endl;
        if (engine.GetTeng() > engine.GetTmax()) return time;
    }
}