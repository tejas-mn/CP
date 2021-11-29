#include<iostream>
using namespace std;

// argc-count of arguments
//argv-List/vector of arguments
int main(int argc,char *argv[])
{
    cout<<"Program name "<<argv[0]<<endl;

    if(argc==2)
    {
        cout<<"The argument supplied is "<<argv[1]<<endl;
    }
    else if(argc>2)
    {
        cout<<"Too many arguments supplied"<<endl;
    }
    else
    {
        cout<<"One argument expected"<<endl;
    }
    return 0;
}
