#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int main()
{

    string s;
    vector<string> str;
    string input;
    getline(cin, input);

    stringstream ss(input);
    while(ss>>s)
    {
        str.push_back(s);
    }

    for(int i=0;i<str.size();i++)
    {

        if(str[i].size() % 2 == 1)
        {
            reverse(str[i].rbegin(), str[i].rend());
        }
    }
    for(int i=0;i<str.size();i++)
    {
        cout<<str[i]<<" ";
    }
    return 0;
}
