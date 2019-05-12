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
            int[] ary = new int[] { 3, 4, 5, 6, 7, 8, 9, 10, 11, 3, 7 };
            int[] countAry = new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

            for (int i = 0; i < ary.Length; i++)
            {
                int curVal = ary[i];
                countAry[curVal]++;
            }

            PrintArray(countAry);

            Console.ReadKey();
        }

        static void PrintArray(int[] ary)
        {
            for (int i = 0; i < ary.Length; i++)
            {
                Console.WriteLine(i + " - " + ary[i]);
            }
        }
    }
}
