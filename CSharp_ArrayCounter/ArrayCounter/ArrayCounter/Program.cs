using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayCounter
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] ary = new int[] { 3, 4, 3, 7, 3, 6, 7 };

            // this is manually performing the acumulation without using a for loop
            int[] acumAryManual = new int[10];

            acumAryManual[3]++;
            acumAryManual[4]++;
            acumAryManual[3]++;
            acumAryManual[7]++;
            acumAryManual[3]++;
            acumAryManual[6]++;
            acumAryManual[7]++;

            PrintArray(acumAryManual);

            // this is using a for loop
            int[] acumAryLoop = new int[10];

            for (int i = 0; i < ary.Length; i++)
            {
                int curVal = ary[i];
                acumAryLoop[curVal]++;
            }

            Console.WriteLine("--------------");

            PrintArray(acumAryLoop);

            Console.ReadKey();
        }

        static void PrintArray(int[] abcarray)
        {
            for (int i = 0; i < abcarray.Length; i++)
            {
                Console.WriteLine(i + " - " + abcarray[i]);
            }
        }
    }
}
