using System;
using System.Collections.Generic;
using BenchmarkDotNet.Attributes;

namespace Bencmarks
{           
    [SimpleJob(targetCount:15)]
    public class InsertionSortBenchmark
    {

        [Benchmark]        
        [ArgumentsSource(nameof(Data))]
        public void BenchmarkInsertionSort(int[] collection, int count)
        {
            collection.InsertionSort();
        }
                
        public static (int,int) CalculateComparationAndMoveCount(int count)
        {
            var array = RandomGenerator.Generate(count);
            
            var comparer = new MockComparer();
            array.InsertionSort(comparer);  

            return (comparer.ComparationCount, comparer.MoveCount);
        }

        public IEnumerable<object[]> Data()
        {   
            yield return new object[] {RandomGenerator.Generate(100), 100};
            yield return new object[] {RandomGenerator.Generate(1000), 1000};
            yield return new object[] {RandomGenerator.Generate(10000), 10000};
        }
    }
}