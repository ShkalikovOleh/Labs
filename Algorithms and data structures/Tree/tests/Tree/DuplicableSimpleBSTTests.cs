using Xunit;
using Tree;

namespace tests
{
    public class DuplicableBSTreeTests
    {
        private DuplicableSimpleBSTree<int, int> tree = new DuplicableSimpleBSTree<int, int>();

        public DuplicableBSTreeTests()
        {
            tree.Add(4, 4);
            tree.Add(9, 9);
            tree.Add(10, 10);
            tree.Add(8, 8);
            tree.Add(1, 1);            
        }        

        [Fact]
        public void Add()
        {
            tree.Add(4,4);
            tree.Add(1,1);
            tree.Add(1,1);
            Assert.Equal(2, tree.GetKeyCount(4));
            Assert.Equal(3, tree.GetKeyCount(1));
            Assert.Equal(1, tree.GetKeyCount(8));
            Assert.Equal(1, tree.GetKeyCount(9));
            Assert.Equal(1, tree.GetKeyCount(10));
        }

        [Fact]
        public void Remove()
        {
            tree.Add(4,4);
            tree.Add(1,1);
            tree.Add(1,1);

            tree.Remove(4);
            tree.Remove(1);
            tree.Remove(8);

            Assert.Equal(9, tree.Root.Key);     
            Assert.Equal(10, tree.Root.Right.Key);
            Assert.Null(tree.Root.Left);
            Assert.Null(tree.Root.Right.Left);
            Assert.Null(tree.Root.Right.Right);
        }    
    }
}