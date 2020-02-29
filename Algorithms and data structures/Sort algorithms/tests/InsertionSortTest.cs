using System;
using Xunit;

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
            Random random = new Random();

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }
                        
            var result = array.InsertionSort();
            Assert.Equal(0, result.CountInversion());
        }

        [Theory]
        [InlineData(10, 3)]        
        public void CorrectPartialInsertionSortTest(uint count, int step)
        {
            Random random = new Random();

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }

            var result = array.PartialInsertionSort(step);
        }
    }
}
