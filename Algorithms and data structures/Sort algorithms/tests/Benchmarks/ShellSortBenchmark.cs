using System;
using System.Collections.Generic;
using BenchmarkDotNet.Attributes;

namespace Bencmarks
{
    [SimpleJob(targetCount:15)]
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

        public static (int,int) CalculateComparationAndMoveCount(int count, IStepSequenceGenerator generator)
        {
            var array = RandomGenerator.Generate(count);
            
            var comparer = new MockComparer();
            array.ShellSort(comparer, generator);

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