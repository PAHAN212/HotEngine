#include <iostream>
#include <vector>
#include "Engine.h"
#include "TestStand.h"


using namespace std;

int main()
{
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
    std::cout << TestStand::GetTimeToOverheating(engine, Tenv, SamStepT);

    return 0;
}



