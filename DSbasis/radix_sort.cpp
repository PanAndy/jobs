#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int find_max(vector<int> &nums)
{
    int n = nums.size();
    int m = 0;
    for(int i=0;i<n;i++)m = max(m, nums[i]);
    return m;
}

int digit_number(int number){
    int digit = 0;
    while(number!=0){
        digit++;
        number/=10;
    }
    return digit;
}

int kth_digit(int number, int kth)
{
    number /= pow(10, kth);
    return number % 10;
}

void radix_sort(vector<int>& nums)
{
    vector<vector<int> > temp(10);
    int n = nums.size();
    int m = find_max(nums);
    int maxDigit = digit_number(m);

    for(int i=0;i<maxDigit;i++)
    {
        for(int j=0;j<10;j++)temp[j].clear();

        for(int j=0;j<n;j++)
        {
            int xx = kth_digit(nums[j], i);
            temp[xx].push_back(nums[j]);
        }
        int index = 0;
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<temp[j].size();k++)
            {
                nums[index++] = temp[j][k];
            }
        }
    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    radix_sort(nums);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
