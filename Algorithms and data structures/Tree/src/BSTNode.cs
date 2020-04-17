using System;

namespace Tree
{
    public class BSTNode<TKey, TValue> where TKey : IComparable<TKey>
    {    
        public BSTNode(TKey key, TValue value)
        {
            this.Key = key;
            this.Value = value;
        }

        public TKey Key { get; private set; }

        public TValue Value { get; private set; }

        public BSTNode<TKey, TValue> Parent { get; internal set; }

        public BSTNode<TKey, TValue> Right { get; internal set; }

        public BSTNode<TKey, TValue> Left { get; internal set; }

        public int Depth
        {
            get
            {
                var current = Parent;
                int depth = 0;
                while(current != null)
                {
                    depth++;
                    current = current.Parent;
                }
                return depth;
            }
        }

        public override string ToString()
        {
            return $"( {Key.ToString()} , {Value.ToString()} )";
        }
    }
}