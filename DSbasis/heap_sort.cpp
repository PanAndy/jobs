#include<iostream>
#include<vector>

using namespace std;

int heapSize = 0;

int Left(int index){return ((index << 1) + 1);}
int Right(int index){return ((index << 1) + 2);}


void maxHeapify(vector<int> &nums, int index)
{
    int largest = 0;
    int left = Left(index);
    int right = Right(index);

    if(left <= heapSize && nums[left] > nums[index]){
        largest = left;
    }else{
        largest = index;
    }

    if(right <= heapSize && nums[right] > nums[largest]){
        largest = right;
    }

    if(largest != index)
    {
        swap(nums[index], nums[largest]);
        maxHeapify(nums, largest);
    }
}

// 从后往前构造
void buildMaxHeap(vector<int> &nums)
{
    heapSize = nums.size() - 1;

    for(int i = (heapSize >> 1); i>=0; i--)
    {
        maxHeapify(nums, i);
    }
}

void heap_sort(vector<int> &nums)
{
    int n = nums.size();
    buildMaxHeap(nums);

    for(int i=n-1;i>=1;i--)
    {
        swap(nums[0], nums[i]);
        heapSize--;
        maxHeapify(nums, 0);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    heap_sort(nums);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
