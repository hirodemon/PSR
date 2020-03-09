int main(int argc, char *argv[])
// ./prog     3
// argv[0] argv[1]
{
    int cp = 0, i = atoi(argv[1]); //Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.
    while (cp < i)
    {
        if (fork() > 0)
            cp++;
        else
            cp = 3;
    }
}