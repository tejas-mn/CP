#include<iostream>
#include<strings.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    //lowercase char a to z ranges from 97 to 122
    //uppercase char A to Z ranges from 65 to 92
    //subtracting 32 from the ASCII value of input char.
    if(s[0]>=97 && s[0]<=122){
        s[0]=s[0]-32;
    }

    cout<<s;
    return 0;
}
