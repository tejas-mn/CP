#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void solve()
{

    int n,m;
    cin>>n>>m;
    vector<int> v(n);
  unordered_multimap<int, int> hashtable;
    for(int &e:v)
    {
        cin>>e;
    }

    for(int i=0;i<v.size();i++)
    {
    hashtable.insert({v[i],i+1});
    }

    cout << "Before:\n"
         << "\tKEY\tELEMENT\n";
    for (auto it = hashtable.begin();
         it != hashtable.end(); it++){

        cout << "\t" << it->first << "\t" << it->second << '\n';
         }

    while(hashtable.empty())
    {
        int first_element=hashtable.begin()->first;
        cout<<first_element;
        int position;
        if(m>=first_element)
        {
            hashtable.erase(first_element);
        }
        else
        {
            first_element=first_element-m;
            position=hashtable.find(first_element)->second;
            hashtable.insert({first_element,position});
            hashtable.erase(first_element);
        }
    }

    cout << "After:\n"
         << "\tKEY\tELEMENT\n";
    for (auto it = hashtable.begin();
         it != hashtable.end(); it++){

        cout << "\t" << it->first << "\t" << it->second << '\n';
         }
}


int main()
{

    solve();
    return 0;
}
