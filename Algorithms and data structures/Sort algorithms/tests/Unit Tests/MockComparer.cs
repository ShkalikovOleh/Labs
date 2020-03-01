using System.Collections.Generic;

namespace tests
{
    public class MockComparer : IComparer<int>
    {
        int compareCount = 0;
        private int moveCount = 0;

        public int ComparationCount => compareCount;

        public int MoveCount => moveCount;

        public void Reset()
        {
            moveCount = 0;
            compareCount = 0;
        }

        public int Compare(int x, int y)
        {
            compareCount++;
            var result = x.CompareTo(y);
            if(result < 0)
                moveCount++;
            return result;
        }
    }
}