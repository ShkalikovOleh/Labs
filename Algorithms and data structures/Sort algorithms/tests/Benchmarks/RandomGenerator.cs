using System;
using System.Collections.Generic;

namespace Bencmarks
{
    public static class RandomGenerator
    {
        private static IDictionary<int, int[]> cashe = new Dictionary<int, int[]>();

        public static IList<int> Generate(int count)
        {
            Random random = new Random();

            if(cashe.ContainsKey(count))
                return cashe[count];

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }
            cashe.Add(count, array);

            return array;
        }
    }    
}