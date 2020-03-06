using System;
using Xunit;
using Xunit.Abstractions;

namespace tests
{
    public class ShellSortTest
    {
        [Theory]
        [InlineData(10)]
        [InlineData(100)]
        [InlineData(1000)]
        public void ShellSortShellSequenceCorrectTest(uint count)
        {
            var array = RandomGenerator.Generate(count);
                        
            var result = array.ShellSort(new ShellSequence());
            Assert.Equal(0, result.CountInversion());
        }

        [Theory]
        [InlineData(10)]
        [InlineData(100)]
        [InlineData(1000)]
        public void ShellSortHibbardSequenceCorrectTest(uint count)
        {
            var array = RandomGenerator.Generate(count);
                        
            var result = array.ShellSort(new HibbardSequence());
            Assert.Equal(0, result.CountInversion());
        }

        [Theory]
        [InlineData(10)]
        [InlineData(100)]
        [InlineData(1000)]
        public void ShellSortKnuthSequenceCorrectTest(uint count)
        {
            var array = RandomGenerator.Generate(count);
                        
            var result = array.ShellSort(new KnuthSequence());
            Assert.Equal(0, result.CountInversion());
        }        
    }
}
