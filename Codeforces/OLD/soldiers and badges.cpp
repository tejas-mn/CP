#include<iostream>
#include<vector>

using namespace std;



    vector<int> clist;
    int count=0;

    void fun(vector<int> a);
int main()
{
    vector<int> arr;
        int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        arr.push_back(c);
    }



    fun(arr);
    if (clist.size()==0)
    {
        printf("%d\n",0);
    }
    else
    {
        printf("%d\n",clist[0]);
    }
    return 0;
}

void fun(vector<int> a)
    {
int        n=a.size();
        printf("ok");
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    a[i]+=1;
                    count+=1;
                    fun(a);
                    clist.push_back(count);
                }
            }

        }
    }
