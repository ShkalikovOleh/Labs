using Xunit;
using Xunit.Abstractions;
using System.Linq;

using Tree;

namespace tests
{
    public class TasksTests
    {
        private readonly ITestOutputHelper outputHelper;

        public TasksTests(ITestOutputHelper outputHelper)
        {
            this.outputHelper = outputHelper;
        }

        [Fact]
        public void ConsolePrint()
        {
            var tree = Tasks.GenerateFromString("tasty");

            var consolePrintString = tree.GetConsolePrintString();
            var correct = "-( t , t ) - 2\n  -( a , a ) - 1\n    -\n    -( s , s ) - 1\n  -( y , y ) - 1\n";
            Assert.Equal(correct, consolePrintString);

            outputHelper.WriteLine(" ");
            outputHelper.WriteLine(consolePrintString);
        }

        [Fact]
        public void GenerateFromString()
        {
            var tree = Tasks.GenerateFromString("tasty");
            
            Assert.Equal('t', tree.Root.Key);
            Assert.Equal('a', tree.Root.Left.Key);
            Assert.Equal('s', tree.Root.Left.Right.Key);
            Assert.Equal('y', tree.Root.Right.Key);            
        }

        [Fact]
        public void GetTraversalConsolePrintString()
        {
            var tree = Tasks.GenerateFromString("tasty");
            var traversal = new BFSTraversal<char, char>(tree);

            var result = Tasks.GetTraversalConsolePrintString(traversal);
            var correct = "( t , t ) - 2 -> ( a , a ) - 1 -> ( y , y ) - 1 -> ( s , s ) - 1";

            Assert.Equal(correct, result);            
            outputHelper.WriteLine(result);
        }

        [Fact]
        public void GenerateFromText()
        {
            var tree = Tasks.GenerateFromText("tasty test data structure\nhello");

            Assert.Equal("tasty", tree.Root.Key);
            Assert.Equal("test", tree.Root.Right.Key);
            Assert.Equal("data", tree.Root.Left.Key);
            Assert.Equal("structure", tree.Root.Left.Right.Key);
            Assert.Equal("hello", tree.Root.Left.Right.Left.Key);
        }

        [Fact]
        public void GetAllStartWith()
        {
            var tree = Tasks.GenerateFromText("tasty test data structure\nhello");
            
            var tResult = Tasks.GetAllStartWith(tree, 't').Count();
            var dResult = Tasks.GetAllStartWith(tree, 'd').Count();
            var hResult = Tasks.GetAllStartWith(tree, 'h').Count();
            var sResult = Tasks.GetAllStartWith(tree, 's').Count();

            Assert.Equal(2, tResult);
            Assert.Equal(1, dResult);
            Assert.Equal(1, hResult);
            Assert.Equal(1, sResult);
        }
    }
}