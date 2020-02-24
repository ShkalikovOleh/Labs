using System;
using Xunit;

namespace tests
{
    public class FibonacciTests
    {
        [Theory]
        [InlineData(0,1)]
        [InlineData(1,1)]
        [InlineData(2,2)]
        [InlineData(5,8)]
        public void FibonacciCorrect(uint number, uint correct)
        {            
            Assert.Equal(correct, Fibonacci.Calculate(number));
        }
    }
}