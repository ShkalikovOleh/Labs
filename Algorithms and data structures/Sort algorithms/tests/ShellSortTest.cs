using System;
using Xunit;

namespace tests
{
    public class ShellSortTest
    {
        [Theory]
        [InlineData(10)]        
        public void CorrectPartialInsertionSortTest(uint count)
        {
            Random random = new Random();

            var array = new int[count];
            for(int i = 0; i < count; i++)
            {
                array[i] = random.Next(-100,100);
            }
                        
            var result = array.PartialInsertionSort(3);
        }
    }
}
