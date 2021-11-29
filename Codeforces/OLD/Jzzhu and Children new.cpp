#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> v(n);

    //vector of pair to store element and their indices in input order
    vector< pair <int,int> > vp;

    //input array
    for(int &e:v)
    {
        cin>>e;
    }

    //pushback element and their indices in input order
    for(int i=0;i<v.size();i++)
    {
        vp.push_back(make_pair(v[i],i+1));
    }


/*---------------Printing vector of pair---------------------

    cout<<"Before\n";
    for (int i=0; i<vp.size(); i++)
    {
        // "first" and "second" are used to access
        // 1st and 2nd element of pair respectively
        cout << vp[i].first << " "
             << vp[i].second << endl;
    }

-------------------------------------------------------------*/

    //stores last element's index
    int last;

    //while vector of pair is not empty
    while(!vp.empty())
    {

        int first_element =vp[0].first;
        last=vp[0].second;

        int position;

        if(m>=first_element)
        {
            vp.erase(vp.begin());
        }
        else
        {
            first_element=first_element-m;
            position=vp[0].second;

            //pushback updated pair
            vp.push_back(make_pair(first_element,position));

            //erase it at the front
            vp.erase(vp.begin());
        }
    }

    //print last index just before erasing
    cout<<last<<"\n";
}


int main()
{

    solve();
    return 0;
}
