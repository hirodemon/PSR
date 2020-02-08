#include <stdio.h>
int main()
{
    if (fork() > 0) // create son (2)
    {
        fork(); // create son if father (another son) -> (3)
        sleep(5); // pstree -p (pid)
    }
}