using System.Collections.Generic;

namespace Bencmarks
{
    public class MockComparer : IComparer<int>
    {
        int compareCount = 0;
        int moveCount = 0;

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