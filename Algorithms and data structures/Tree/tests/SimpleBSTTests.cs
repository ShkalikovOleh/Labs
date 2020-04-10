using Xunit;
using Tree;

namespace tests
{
    public class SimpleBSTreeTests
    {
        private SimpleBSTree<int, int> tree = new SimpleBSTree<int, int>();

        public SimpleBSTreeTests()
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
            Assert.Equal(4, tree.Root.Key);
            Assert.Equal(1, tree.Root.Left.Key);
            Assert.Equal(9, tree.Root.Right.Key);
            Assert.Equal(8, tree.Root.Right.Left.Key);
            Assert.Equal(10, tree.Root.Right.Right.Key);
        }

        [Fact]
        public void AddNull()
        {
            var tree = new SimpleBSTree<string, string>();
            Assert.Throws<System.ArgumentNullException>(()=>tree.Add(null, "smt"));
            Assert.Throws<System.ArgumentNullException>(()=>tree.Add("smt", null));
            Assert.Throws<System.ArgumentNullException>(()=>tree.Add(null, null));
        }

        [Fact]
        public void Remove()
        {
            tree.Add(12, 12);
            tree.Add(6, 6);
            tree.Add(3, 3);

            tree.Remove(10);
            tree.Remove(8);
            tree.Remove(9);
            tree.Remove(3);

            Assert.Equal(4, tree.Root.Key);
            Assert.Equal(1, tree.Root.Left.Key);
            Assert.Equal(12, tree.Root.Right.Key);
            Assert.Equal(6, tree.Root.Right.Left.Key);
        }

        [Fact]
        public void RemoveNullKey()
        {
            var tree = new SimpleBSTree<string, string>();
            Assert.Throws<System.ArgumentNullException>(() => tree.Remove(null));
        }        
    }
}