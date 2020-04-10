using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Linq;

namespace Tree
{
    public static class Tasks
    {
        public static string GetConsolePrintString<TKey, TValue>(this IBSTree<TKey, TValue> tree)
                    where TKey : IComparable<TKey>
        {
            if (tree == null)
                throw new ArgumentNullException("Tree is null");
            if (tree.Root == null)
                throw new ArgumentException("Tree is empty");

            if (tree is DuplicableSimpleBSTree<TKey, TValue>)
                return GetConsolePrintNodeString(tree.Root, tree as DuplicableSimpleBSTree<TKey, TValue>);
            else
                return GetConsolePrintNodeString(tree.Root);
        }

        public static string GetConsolePrintNodeString<TKey, TValue>(BSTNode<TKey, TValue> node)
                        where TKey : IComparable<TKey>
        {
            var builder = new StringBuilder(new string(' ', 2 * node.Depth));

            builder.Append("-");
            builder.AppendLine(node.ToString());

            if (node.Left != null)
                builder.Append(GetConsolePrintNodeString(node.Left));
            else if (node.Right != null)
                builder.AppendLine(new string(' ', 2 * node.Depth + 2) + '-');

            if (node.Right != null)
                builder.Append(GetConsolePrintNodeString(node.Right));
            else if (node.Left != null)
                builder.AppendLine(new string(' ', 2 * node.Depth + 2) + '-');

            return builder.ToString();
        }

        public static string GetConsolePrintNodeString<TKey, TValue>(BSTNode<TKey, TValue> node, DuplicableSimpleBSTree<TKey, TValue> tree)
                        where TKey : IComparable<TKey>
        {
            var builder = new StringBuilder(new string(' ', 2 * node.Depth));

            builder.Append("-");
            builder.AppendLine(node.ToString() + $" - {tree.GetKeyCount(node.Key)}");

            if (node.Left != null)
                builder.Append(GetConsolePrintNodeString(node.Left, tree));
            else if (node.Right != null)
                builder.AppendLine(new string(' ', 2 * node.Depth + 2) + '-');

            if (node.Right != null)
                builder.Append(GetConsolePrintNodeString(node.Right, tree));
            else if (node.Left != null)
                builder.AppendLine(new string(' ', 2 * node.Depth + 2) + '-');

            return builder.ToString();
        }

        public static IBSTree<char, char> GenerateFromString(string text)
        {
            var tree = new DuplicableSimpleBSTree<char, char>();
            foreach (var symbol in text)
            {
                tree.Add(symbol, symbol);
            }

            return tree;
        }

        public static IBSTree<string, string> GenerateFromText(string text)
        {
            var tree = new DuplicableSimpleBSTree<string, string>();
            foreach (var symbol in text.Split(' ', '\t', '\n'))
            {
                tree.Add(symbol, symbol);
            }

            return tree;
        }

        public static IBSTree<int, char> GenerateLabExpressionTree()
        {
            var tree = new SimpleBSTree<int, char>(1, '+');
            tree.Add(0, '9');
            tree.Add(3, '*');
            tree.Add(2, '8');
            tree.Add(5, '+');
            tree.Add(4, '7');
            tree.Add(15, '+');
            tree.Add(16, '1');
            tree.Add(11, '-');
            tree.Add(13, '-');
            tree.Add(12, '3');
            tree.Add(14, '2');
            tree.Add(7, '*');
            tree.Add(6, '6');
            tree.Add(9, '+');
            tree.Add(8, '5');
            tree.Add(10, '4');

            return tree;
        }

        public static IEnumerable<BSTNode<string, string>> GetAllStartWith(this IBSTree<string, string> tree, char letter)
        {
            if (tree == null)
                throw new ArgumentNullException("Tree is null");
            if (tree.Root == null)
                throw new ArgumentException("Tree is empty");

            var stash = new Queue<BSTNode<string, string>>();
            var temp = tree.Root;
            while (temp != null)
            {
                if (temp.Key[0] > letter)
                    temp = temp.Left;
                else if (temp.Key[0] < letter)
                    temp = temp.Right;
                else
                {
                    stash.Enqueue(temp);
                    break;
                }
            }

            while (stash.Count > 0)
            {
                temp = stash.Dequeue();
                if (temp.Left != null && temp.Left.Key[0] == letter)
                {
                    stash.Enqueue(temp.Left);
                }
                if (temp.Right != null && temp.Right.Key[0] == letter)
                {
                    stash.Enqueue(temp.Right);
                }
                yield return temp;
            }
        }

        public static void WriteText(this IBSTree<string, string> tree, Stream stream)
        {
            using (var writer = new StreamWriter(stream))
            {
                foreach (var item in new BFSTraversal<string, string>(tree))
                {
                    writer.WriteLine(item.Value);
                }
            }
        }

        public static string GetTraversalConsolePrintString<TKey, TValue>(this ITraversal<TKey, TValue> traversal)
                        where TKey : IComparable<TKey>
        {
            if (traversal == null)
                throw new ArgumentNullException();

            if (traversal.tree is DuplicableSimpleBSTree<TKey, TValue>)
            {
                var tree = traversal.tree as DuplicableSimpleBSTree<TKey, TValue>;
                return string.Join(" -> ", traversal.Select((n) => n.ToString() + $" - {tree.GetKeyCount(n.Key)}"));
            }
            else
            {
                return string.Join("->", traversal.Select((n) => n.ToString()));
            }
        }
    }
}