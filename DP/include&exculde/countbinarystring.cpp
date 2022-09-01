//Binary Strings with no consecutive 0's 
int countstring(int n)
{
    int oczeros=1;
    int ocone=1;
    for(int i=2; i<=n; i++)
    {
        int nczeros=ocone;
        int ncones=ocone+oczeros;
        ocone=ncones;
        oczeros=nczeros;
    }
}