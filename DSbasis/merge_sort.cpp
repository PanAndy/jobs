#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<int>& nums, int l_begin, int l_end, int r_begin, int r_end)
{
    vector<int> temp(nums.begin(), nums.end());

    int i = l_begin;
    int j = r_begin;
    int idx = i;
    while(i <= l_end && j <= r_end)
    {
        if(temp[i] < temp[j])
        {
            nums[idx++] = temp[i++];
        }else{
            nums[idx++] = temp[j++];
        }
    }
    while(i<=l_end)nums[idx++] = temp[i++];
    while(j<=r_end)nums[idx++] = temp[j++];
}

void merge_sort(vector<int>& nums, int beg, int end)
{

    if(beg >= end) return;

    int mid = beg + ((end - beg) >> 1);

    merge_sort(nums, beg, mid);
    merge_sort(nums, mid+1, end);

    merge(nums, beg, mid, mid + 1, end);
}


int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    merge_sort(nums, 0, n - 1);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
