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
            var result = new int[count];

            if(cashe.ContainsKey(count))
            {
                cashe[count].CopyTo(result, 0);
            }                
            else
            {
                var array = new int[count];
                for(int i = 0; i < count; i++)
                {
                    array[i] = random.Next();
                }
                cashe.Add(count, array);
                array.CopyTo(result, 0);
            }                            
            return result;
        }
    }    
}