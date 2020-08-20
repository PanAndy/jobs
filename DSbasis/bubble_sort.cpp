#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/*
bubble_sort的核心是：小的元素不断上浮
*/
void bubble_sort(vector<int> & nums)
{
    int n = nums.size();

    for(int i=0;i<n-1;i++)
    {
        for(int j=n-2;j>=i;j--)
        {
            if(nums[j+1] < nums[j])
            {
                swap(nums[j+1], nums[j]);
            }
        }
    }
}


int main()
{
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    bubble_sort(nums);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
