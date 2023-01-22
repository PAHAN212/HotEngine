
using HotEngine;
using System.Globalization;

internal class Program
{
    private static void Main(string[] args)
    {
        // Задаем зависимость мощьности от оборотов и остальные параметры двигателя
        SortedList<float, float> MfromT = new SortedList<float, float>();
        MfromT.Add(0, 20);
        MfromT.Add(75, 75);
        MfromT.Add(150, 100);
        MfromT.Add(200, 105);
        MfromT.Add(250, 75);
        MfromT.Add(300, 0);
        Engine engine = new Engine(0.1f, MfromT, 110f, 0.01f, 0.0001f, 0.1f);

        float Tenv;
        float.TryParse(Console.ReadLine(), out Tenv);

        // Шаг дискретизации симуляции процесса по времени.
        // Чем меньше шаг тем точнее, но требуется больше вычеслений. 
        float SamStepT = 0.1f; 
        Console.WriteLine(engine.GetTimeToOverheating(Tenv, SamStepT));
    }
}