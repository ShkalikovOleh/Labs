using System;
using Xunit;
using Xunit.Abstractions;

namespace tests
{
    public class ShellSortTest
    {
        private readonly ITestOutputHelper output;

        public ShellSortTest(ITestOutputHelper output)
        {
            this.output = output;
        }

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

        [Fact]
        public void CalculateComparationAndMoveCount10000()
        {
            var array = RandomGenerator.Generate(10000);
            
            var array2 = new int[10000];
            array.CopyTo(array2, 0);
            var array3 = new int[10000];
            array.CopyTo(array3, 0);

            var comparer = new MockComparer();

            array.ShellSort(comparer, new KnuthSequence());
            output.WriteLine($"Shell sort(Knuth): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 10000");
            comparer.Reset();
            
            array2.ShellSort(comparer, new HibbardSequence());
            output.WriteLine($"Shell sort(Hibbard): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 10000");
            comparer.Reset();
            
            array3.ShellSort(comparer, new ShellSequence());
            output.WriteLine($"Shell sort(Shell): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 10000");
            comparer.Reset();

            Assert.Equal(0, array.CountInversion());
            Assert.Equal(0, array2.CountInversion());
            Assert.Equal(0, array3.CountInversion());
        }

        [Fact]
        public void CalculateComparationAndMoveCount1000()
        {
            var array = RandomGenerator.Generate(1000);
            
            var array2 = new int[1000];
            array.CopyTo(array2, 0);
            var array3 = new int[1000];
            array.CopyTo(array3, 0);

            var comparer = new MockComparer();

            array.ShellSort(comparer, new KnuthSequence());
            output.WriteLine($"Shell sort(Knuth): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 1000");
            comparer.Reset();
            
            array2.ShellSort(comparer, new HibbardSequence());
            output.WriteLine($"Shell sort(Hibbard): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 1000");
            comparer.Reset();
            
            array3.ShellSort(comparer, new ShellSequence());
            output.WriteLine($"Shell sort(Shell): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 1000");
            comparer.Reset();

            Assert.Equal(0, array.CountInversion());
            Assert.Equal(0, array2.CountInversion());
            Assert.Equal(0, array3.CountInversion());
        }

        [Fact]
        public void CalculateComparationAndMoveCount100()
        {
            var array = RandomGenerator.Generate(100);
            
            var array2 = new int[100];
            array.CopyTo(array2, 0);
            var array3 = new int[100];
            array.CopyTo(array3, 0);

            var comparer = new MockComparer();

            array.ShellSort(comparer, new KnuthSequence());
            output.WriteLine($"Shell sort(Knuth): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 100");
            comparer.Reset();
            
            array2.ShellSort(comparer, new HibbardSequence());
            output.WriteLine($"Shell sort(Hibbard): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 100");
            comparer.Reset();
            
            array3.ShellSort(comparer, new ShellSequence());
            output.WriteLine($"Shell sort(Shell): Comparation count = {comparer.ComparationCount}. Move count = {comparer.MoveCount}  for 100");
            comparer.Reset();

            Assert.Equal(0, array.CountInversion());
            Assert.Equal(0, array2.CountInversion());
            Assert.Equal(0, array3.CountInversion());
        }
    }
}
