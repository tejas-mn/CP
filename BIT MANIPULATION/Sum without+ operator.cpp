#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int sum(int a , int b)
    {
        //Simple
        return a-(-b);

        //Using ++ and --
        while(b--) a++;
        return a;

        //Half Adder Logic
        int sum;
        int carry;
        while(b!=0)
        {
            sum  = a^b;
            carry = (a&b)<<1;

            a=sum;b=carry;
        }
        return sum;

    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;

        Solution ob;
        cout<< ob.sum(a,b) <<"\n";

    }
    return 0;
}
