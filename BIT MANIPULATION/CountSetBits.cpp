//Iterative --O(bits count)
int countSetBits(int n)
{
    int cnt=0;
    while(n)
    {
       cnt+=(n&1);
       n>>=1;
    }
    return cnt;
}

//Recursive --O(bits count)
int countSetBits(int n){
    if(n==0)
        return 0;
    else
        return (n&1) + count_SetBits(n>>1);
}

//Brian-Karnighan-Algorithm --O(set bit count)
int countSetBits_Brian(int n)
{
        int cnt=0;
        while(n)
        {
            //turnoff rightmost set bit and increment count while number > 0
            n = n & (n-1);
            cnt+=1;
        }
        return cnt;
}
