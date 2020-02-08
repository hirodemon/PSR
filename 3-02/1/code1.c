#include <stdio.h>
int main()
{
    fork(); // create son (2)
    fork(); // create son for each (4)
    fork(); // (8)
    sleep(10);
}