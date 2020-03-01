using System;
using System.Collections.Generic;
using Xunit;
using Xunit.Abstractions;

namespace tests
{
    public class InsertionSortTest
    {
        private readonly ITestOutputHelper output;

        public InsertionSortTest(ITestOutputHelper output)
        {
            this.output = output;
        }

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

        [Theory]
        [InlineData(100)]
        [InlineData(1000)]
        [InlineData(10000)]
        public void CalculateComparationAndMoveCount(uint count)
        {
            var array = RandomGenerator.Generate(count);
            
            var comparer = new MockComparer();
            array.InsertionSort(comparer);
            
            Assert.Equal(0, array.CountInversion());
            output.WriteLine($"Insertion sort: Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for {count}");
        }
    }
}
