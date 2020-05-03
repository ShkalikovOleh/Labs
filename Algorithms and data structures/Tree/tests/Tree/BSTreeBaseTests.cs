using Xunit;
using Tree;

namespace tests
{
    public class BSTreeBaseTests
    {
        private SimpleBSTree<int, int> tree = new SimpleBSTree<int, int>();

        public BSTreeBaseTests()
        {
            tree.Add(4, 4);
            tree.Add(9, 9);
            tree.Add(10, 10);
            tree.Add(8, 8);
            tree.Add(1, 1);
        }

        [Fact]
        public void Height()
        {
            Assert.Equal(2, tree.Height);
        }


        [Fact]
        public void HeightEmpty()
        {
            var tree = new SimpleBSTree<int, int>();
            Assert.Equal(0, tree.Height);
        }

        [Fact]
        public void SearchByExistingKey()
        {
            Assert.Equal(4, tree.Search(4));
            Assert.Equal(9, tree.Search(9));
            Assert.Equal(10, tree.Search(10));
            Assert.Equal(8, tree.Search(8));
            Assert.Equal(1, tree.Search(1));
        }

        [Fact]
        public void SearchByIncorrectKey()
        {
            Assert.Equal(default(int), tree.Search(0));
            Assert.Equal(default(int), tree.Search(56));
        }

        [Fact]
        public void FindByExistingKey()
        {
            Assert.Equal(4, tree.Find(4).Value);
            Assert.Equal(10, tree.Find(10).Value);
            Assert.Equal(1, tree.Find(1).Value);
            Assert.Equal(9, tree.Find(9).Value);
            Assert.Equal(8, tree.Find(8).Value);
        }

        [Fact]
        public void FindByIncorrectKey()
        {
            Assert.Null(tree.Find(0));
            Assert.Null(tree.Find(56));
        }

        [Fact]
        public void Contains()
        {
            Assert.True(tree.Contains(8));
            Assert.True(tree.Contains(1));
            Assert.True(tree.Contains(10));
            Assert.True(tree.Contains(4));
            Assert.True(tree.Contains(9));

            Assert.False(tree.Contains(56));
            Assert.False(tree.Contains(0));
        }

        [Fact]
        public void Empty()
        {
            Assert.False(tree.Empty());
            Assert.True(new SimpleBSTree<int, int>().Empty());
        }

        [Fact]
        public void Min()
        {
            Assert.Equal(1, tree.Min().Key);
        }

        [Fact]
        public void Max()
        {
            Assert.Equal(10, tree.Max().Key);
        }
    }
}