//Naive Solution
bool powerof2(int n)
{
    if(n==0)
        return false;

    while(n!=1)
    {
        //If n is odd other than 1 (2^0) then return false
        if(n%2!=0) return false;
        n/=2;
    }
    return true;
}

//if countSetBits in number is 1==>power of 2
bool powerof2(int n)
{
    if(countSetBits(n)==1)
        return true;
    else
        return false;
}

//If number is non-zero turnoff RSB then if number becomes 0==>power of 2
bool powerof2(int n)
{
    return ( (n!=0) and (n&(n-1))==0);
}