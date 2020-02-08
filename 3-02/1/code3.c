int main()
{
    int cp = 0;
    while (cp < 3) // create 3 sons then leave for father (cp = 3 for son instant leave)
    {
        if (fork() > 0) // if father -> create son
            cp++;
        else // if son
            cp = 3;
    }
}