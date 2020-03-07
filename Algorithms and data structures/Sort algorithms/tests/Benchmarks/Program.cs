using System.Collections.Generic;
using System.IO;
using System.Text;
using BenchmarkDotNet.Running;

namespace Bencmarks
{
    class Program
    {
        static void SaveOperationsCount(string path, IDictionary<int, (int, int)> counts)
        {
            using(var file = new FileStream(path, FileMode.Create))
            {
                foreach (var value in counts)
                {                                    
                    var line = string.Join(',', new object[] { value.Key, value.Value.Item1, value.Value.Item2}) + "\n";
                    byte[] buffer = Encoding.UTF8.GetBytes(line);
                    file.Write(buffer, 0, buffer.Length);
                }
            }
        }

        static void Main(string[] args)
        {                                    
            var insertionSummary = BenchmarkRunner.Run<InsertionSortBenchmark>();
            var shellSumarry = BenchmarkRunner.Run<ShellSortBenchmark>();

            var insertionOperations = new Dictionary<int, (int, int)>();
            var shellOperations = new Dictionary<int, (int, int)>();
            var knuthOperations = new Dictionary<int, (int, int)>();
            var hibbardOperations = new Dictionary<int, (int, int)>();
            foreach (var count in new[]{100,1000,10000})
            {
                insertionOperations.Add(count, InsertionSortBenchmark.CalculateComparationAndMoveCount(count));
                knuthOperations.Add(count, ShellSortBenchmark.CalculateComparationAndMoveCount(count, new KnuthSequence()));
                shellOperations.Add(count, ShellSortBenchmark.CalculateComparationAndMoveCount(count, new ShellSequence()));
                hibbardOperations.Add(count, ShellSortBenchmark.CalculateComparationAndMoveCount(count, new HibbardSequence()));
            }
                                                          
            SaveOperationsCount(args[0] + "/ShellOperation.csv", shellOperations);            
            SaveOperationsCount(args[0] + "/HibbardOperation.csv", hibbardOperations);
            SaveOperationsCount(args[0] + "/KnuthOperation.csv", knuthOperations);
            SaveOperationsCount(args[0] + "/InsertionOperation.csv", insertionOperations);
        }
    }
}
