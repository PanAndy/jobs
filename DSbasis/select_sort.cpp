#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

void select_sort(vector<int>& nums)
{
    int n = nums.size();

    for(int i=0;i<n;i++)
    {
        int m_idx = i;

        for(int j=i+1;j<n;j++)
        {
            if(nums[j] < nums[m_idx]){
                m_idx = j;
            }
        }
        swap(nums[i], nums[m_idx]);
    }
}



int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    select_sort(nums);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
