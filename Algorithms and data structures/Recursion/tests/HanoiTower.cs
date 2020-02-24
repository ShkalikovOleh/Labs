using System;
using System.Collections.Generic;
using Xunit;

namespace tests
{
    public class MockLogger : IHanoiLogger
    {
        List<Stack<int>> towers;

        public MockLogger(int count)
        {
            towers = new List<Stack<int>>();
            towers.Add(new Stack<int>());
            for(int i = count; i > 0; i--)
                towers[0].Push(i);
            towers.Add(new Stack<int>());
            towers.Add(new Stack<int>());      
        }

        public void Log(uint index, uint source, uint destination)
        {   
            if(towers[(int)destination - 1].Count != 0)            
            {
                if(towers[(int)destination - 1].Peek() < index)
                {
                    throw new Exception();   
                }                
            }
            var tor = towers[(int)source - 1].Pop();
            towers[(int)destination - 1].Push(tor);
        }
    }

    public class HanoiTests
    {
        [Fact]        
        public void HanoiCorrect()
        {            
            HanoiTower.Solve(3, new MockLogger(3));
            HanoiTower.Solve(3, new ConsoleHanoiLogger());
        }
    }
}