using System;
using System.Collections.Generic;

namespace tests
{
    public static class RandomGenerator
    {
        public static IList<int> Generate(uint count)
        {
            Random random = new Random();

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }

            return array;
        }
    }    
}