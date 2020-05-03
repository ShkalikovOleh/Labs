using Xunit;
using Tree;

namespace tests
{
    public class PostOrderTraversalTests
    {
        [Fact]
        public void Traverse()
        {
            var tree = new SimpleBSTree<int, int>();
            tree.Add(4, 4);
            tree.Add(9, 9);
            tree.Add(10, 10);
            tree.Add(8, 8);
            tree.Add(1, 1);
            tree.Add(3, 3);

            int[] correct = { 3, 1, 8, 10, 9, 4 };
            int i = 0;
            foreach (var node in new PostOrderTraversal<int, int>(tree))
            {
                Assert.Equal(correct[i], node.Key);
                i++;
            }
        }

        [Fact]
        public void TraverseEmpty()
        {
            var tree = new SimpleBSTree<int, int>();
            var traversal = new PostOrderTraversal<int, int>(tree);

            int i = 0;
            foreach (var node in traversal)
            {                
                i++;
            }
            Assert.Equal(0, i);

            tree.Add(4,4);            
            foreach (var node in traversal)
            {                
                Assert.Equal(4, node.Key);
            }
        }
    }
}