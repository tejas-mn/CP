#include<iostream>
using namespace std;

int m[4][4];
int input[4][4];

void change_state(int i,int j,int m[4][4])
{
    if((i>=0 && i<3) && (j>=0 && j<3))
    {
        if(m[i][j]==1)
        {
            m[i][j]=0;
        }
        else
        {
            m[i][j]=1;
        }
    }
}

int main()
{

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            m[i][j]=1;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&input[i][j]);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if( (input[i][j]>0) && (input[i][j]%2!=0))
            {
                change_state(i,j,m);
                change_state(i,j+1,m);
                change_state(i+1,j,m);
                change_state(i-1,j,m);
                change_state(i,j-1,m);
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
                cout<<m[i][j];
        }
        printf("\n");
    }

    return 0;
}
