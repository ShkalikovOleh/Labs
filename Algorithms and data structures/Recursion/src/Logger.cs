using System;

public interface IHanoiLogger
{
    void Log(uint index, uint source, uint destination);
}

public class ConsoleHanoiLogger : IHanoiLogger
{
    public void Log(uint index, uint source, uint destination)
    {
        Console.WriteLine($"Move {index} item from {source} tower to {destination} tower");
    }
}