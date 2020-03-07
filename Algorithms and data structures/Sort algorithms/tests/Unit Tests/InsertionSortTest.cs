using System;
using System.Collections.Generic;
using Xunit;
using Xunit.Abstractions;

namespace tests
{
    public class InsertionSortTest
    {
        [Theory]
        [InlineData(10)]
        [InlineData(100)]
        [InlineData(1000)]
        public void CorrectSortTest(uint count)
        {
            var array = RandomGenerator.Generate(count);
                        
            var result = array.InsertionSort();
            Assert.Equal(0, result.CountInversion());
        }

        [Theory]
        [InlineData(10, 3)]
        [InlineData(100, 7)]
        [InlineData(1000, 23)]
        public void CorrectPartialInsertionSortTest(uint count, int step)
        {            
            var array = RandomGenerator.Generate(count);
            var result = array.PartialInsertionSort(step);
            
            List<List<int>> subarrays = new List<List<int>>();
            for(int i = 0; i < step; i++)
            {
                var subarray = new List<int>();
                for(int j = i; j < result.Count; j += step)
                    subarray.Add(result[j]);
                subarrays.Add(subarray);
            }

            foreach(var subarray in subarrays)
            {
                Assert.Equal(0, subarray.CountInversion());
            }
        }
    }
}
