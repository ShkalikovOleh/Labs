using System;

public static class HanoiTower
{
    public static void Solve(uint count, IHanoiLogger logger)
    {
        if(count < 1)
            throw new ArgumentOutOfRangeException();
        Move(count, 1, 3, 2, logger);
    }

    private static void Move(uint count ,uint source, uint destination, uint independent, IHanoiLogger logger)
    {
        if(count == 0)
            return;
        Move(count - 1, source, independent, destination, logger);        
        logger.Log(count, source, destination);
        Move(count - 1, independent, destination, source, logger);
    }
}