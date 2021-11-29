bool kthBit_SetorNot_leftshift(int n, int k)
{
        if(n&(1<<k)!=0)         //left shift 1 by k and perform bitwise and with n
            return true;
        else
            return false;
}

bool kthBit_SetorNot_rightshift(int n, int k)
{
        if(((n>>k)&1)!=0)       //right shift n by k and perform bitwise and with 1
            return true;
        else
            return false;
}