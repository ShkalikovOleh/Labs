using BenchmarkDotNet.Running;

namespace Bencmarks
{
    class Program
    {
        static void Main(string[] args)
        {
            var summary = BenchmarkSwitcher.FromAssembly(typeof(Program).Assembly).Run(args);
        }
    }
}
