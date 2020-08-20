#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int>&, int, int);

void quick_sort(vector<int> & nums, int start, int edn)
{
    if(start == edn)return;
    int pivot = partition(nums, start, edn);
    if(pivot > start){
        quick_sort(nums, start, pivot - 1);
    }
    if(pivot < edn){
        quick_sort(nums, pivot + 1, edn);
    }
}


int partition(vector<int>&nums, int start, int edn)
{
    int pivot = start;

    swap(nums[pivot], nums[edn]);

    int small = start-1;

    for(int i=start;i<edn;i++)
    {
        if(nums[i] < nums[edn])
        {
            ++small;
            if(small != i) // 如果small != i，那么small就还停留在上一个刚好大于nums[end]的地方，这时，将小的这个数和那个那的数交换。
            {
                swap(nums[i], nums[small]);
            }
        }
    }
    ++small;
    swap(nums[small], nums[edn]);
    return small;

}

int main()
{
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    quick_sort(nums, 0, n-1);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
