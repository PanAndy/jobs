#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main()
{

    string s;
    cin>>s;

    int n = s.size();

    vector<int> dp(n+1, 0);

    dp[0] = 1;

    for(int i=1;i<n;i++)
    {
        if(s[i] != '0')
        {
            dp[i] = dp[i-1];
        }
        int num = 10 * (s[i-1] - '0') + (s[i] - '0');
        if(num >=10 && num <= 26)
        {
            dp[i] += (i-2 >=0 ? dp[i-2] : 1);
        }

    }

    cout<<dp[n-1]<<endl;

    return 0;
}
