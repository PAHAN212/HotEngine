using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace HotEngine
{
    internal class Engine
    {

        public float I { get; set; }
        public SortedList<float, float> MfromT { get; set; }
        public float Tmax { get; set; }
        public float Hm { get; set; } 
        public float Hv { get; set; }
        public float C { get; set; }
        
        public Engine(float I, SortedList<float, float> MfromT, float Tmax, float Hm, float Hv, float C)
        {
            this.I = I;
            this.MfromT = MfromT;
            this.Tmax = Tmax;
            this.Hm = Hm;
            this.Hv = Hv;
            this.C = C;
        }

        public float GetTimeToOverheating (float Tenv, float SamStepT)
        {
            float Teng = Tenv;
            float time = 0;
            float V = 0;
            float M;


            while (true)
            {
                M = GetValueM(this.MfromT, V);
                float Tadd = (M * this.Hm + V * V * this.Hv) * SamStepT;
                float Tsub = (this.C * (Tenv - Teng)) * SamStepT;
                Teng = Teng + Tadd - Tsub;
                V += this.I * M * SamStepT;
                time += SamStepT;
                Console.WriteLine("t = {0} Teng = {1}", time, Teng);
                if (Teng > this.Tmax) return time;

                // Проверка на вечную работу
                if (V > this.MfromT.Last().Key * 0.95)
                {
                    var lastPoint = this.MfromT.Last();
                    float TaddMax = lastPoint.Value * this.Hm + lastPoint.Key * lastPoint.Key * this.Hv;
                    float TsubMax = this.C * (Tenv - this.Tmax);
                    if (TsubMax > TaddMax) { return -1; }
                }
            }
        }

        public float GetValueM(SortedList<float, float> MfromT, float Vcurrent)
        {
            float m1 = 0;
            float v1 = 0;
            float m2;
            float v2;

            //Здесь Key - значение V, Value - значение M
            foreach ( var point in MfromT)
            {
                if (Vcurrent >= point.Key)
                {
                    m1 = point.Value;
                    v1 = point.Key;
                }
                if (Vcurrent < point.Key)
                {
                    m2 = point.Value;
                    v2 = point.Key;

                    float k = (m1 - m2) / (v1 - v2);
                    float b = m2 - k * v2;
                    return (k * Vcurrent + b);
                }
                else { continue; }
            }

            return 0f;
        }
    }
}
