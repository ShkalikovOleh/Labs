using System;
using Xunit;

namespace tests
{
    public class GCDTests
    {
        [Theory]
        [InlineData(78,45,3)]
        [InlineData(24,-12,12)]
        [InlineData(-24,-12,12)]
        [InlineData(198, 65, 1)]
        [InlineData(19, 0, 19)]
        public void GCDCorrect(int a, int b, int correct)
        {
            var result = GCD.Calculate(a, b);
            Assert.Equal(correct, result);
        }

        [Fact]
        public void ThrowIfNull()
        {            
            Assert.Throws<ArgumentOutOfRangeException>(()=>GCD.Calculate(0, 0));
        }
    }
}
