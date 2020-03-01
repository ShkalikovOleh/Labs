using System;
using System.Collections.Generic;
using BenchmarkDotNet.Attributes;

namespace Bencmarks
{        
    public class ShellSortBenchmark
    {
        private IStepSequenceGenerator knuth = new KnuthSequence();

        private IStepSequenceGenerator hibbard = new HibbardSequence();

        private IStepSequenceGenerator shell = new ShellSequence();

        [Benchmark]        
        [ArgumentsSource(nameof(Data))]
        public void BenchmarkShellSequence(int[] collection, int count)
        {
            collection.ShellSort(shell);
        }

        [Benchmark]        
        [ArgumentsSource(nameof(Data))]
        public void BenchmarkHibbardSequence(int[] collection, int count)
        {
            collection.ShellSort(hibbard);
        }

        [Benchmark]        
        [ArgumentsSource(nameof(Data))]
        public void BenchmarkKnuthSequence(int[] collection, int count)
        {
            collection.ShellSort(knuth);
        }

        public IEnumerable<object[]> Data()
        {   
            yield return new object[] {GetRandom(100), 100};
            yield return new object[] {GetRandom(1000), 1000};
            yield return new object[] {GetRandom(10000), 10000};
        }

        private int[] GetRandom(int count)
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