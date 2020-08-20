#include<iostream>
#include<vector>

using namespace std;


void insert_sort(vector<int> & nums)
{
    int n = nums.size();
    if(n <= 1)return;

    for(int i=1;i<n;i++)
    {
        int val = nums[i];
        int j = i - 1;
        for(;j >= 0 && val < nums[j]; j--){ //
            nums[j+1] = nums[j];
        }
        nums[j+1] = val;
    }
}


int main()
{
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    insert_sort(nums);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
