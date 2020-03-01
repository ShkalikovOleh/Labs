using System;
using Xunit;

namespace tests
{
    public class ShellSortTest
    {
        [Theory]
        [InlineData(10)]
        [InlineData(100)]
        [InlineData(1000)]
        public void ShellSortShellSequenceCorrectTest(int count)
        {
            Random random = new Random();

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }
                        
            var result = array.ShellSort(new ShellSequence());
            Assert.Equal(0, result.CountInversion());
        }

        [Theory]
        [InlineData(10)]
        [InlineData(100)]
        [InlineData(1000)]
        public void ShellSortHibbardSequenceCorrectTest(int count)
        {
            Random random = new Random();

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }
                        
            var result = array.ShellSort(new HibbardSequence());
            Assert.Equal(0, result.CountInversion());
        }

        [Theory]
        [InlineData(10)]
        [InlineData(100)]
        [InlineData(1000)]
        public void ShellSortKnuthSequenceCorrectTest(int count)
        {
            Random random = new Random();

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }
                        
            var result = array.ShellSort(new KnuthSequence());
            Assert.Equal(0, result.CountInversion());
        }
    }
}
