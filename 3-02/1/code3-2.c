int main(int argc, char *argv[])
// ./prog     3
// argv[0] argv[1]
{
    int cp = 0, i = atoi(argv[1]);
    while (cp < i)
    {
        if (fork() > 0)
            cp++;
        else
            cp = 3;
    }
}