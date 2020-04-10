using Xunit;
using Tree;

namespace tests
{
    public class BSTNodeTests
    {
        [Fact]
        public void Depth()
        {
            var tree = new SimpleBSTree<int, int>();
            tree.Add(4, 4);
            tree.Add(9, 9);
            tree.Add(10, 10);
            tree.Add(8, 8);
            tree.Add(1, 1);

            Assert.Equal(0, tree.Root.Depth);
            Assert.Equal(1, tree.Root.Left.Depth);
            Assert.Equal(1, tree.Root.Right.Depth);
            Assert.Equal(2, tree.Root.Right.Right.Depth);
            Assert.Equal(2, tree.Root.Right.Left.Depth);
        }
    }
}