#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>&);
void shell_sort(vector<int> & nums)
{
    int h, i, j, temp;
    int n = nums.size();

    //ϣ������ĺ����ǣ�������d�����ݽ��з��飬ʹÿ�������򣬵�d=1ʱ�����������������ġ�
    for(h=n/2;h>0;h/=2)
    {
        for(i=h;i<n;i++)
        {
            temp = nums[i];
            for(j=i-h;j>=0&&temp<nums[j];j-=h)
            {
                nums[j+h] = nums[j];
            }
            nums[j+h] = temp;
            print(nums);
        }
    }
}

void print(vector<int>& nums)
{
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for(int i=0;i<n;i++)cin>>nums[i];

    shell_sort(nums);

    for(int i=0;i<n;i++)cout<<nums[i]<<endl;
    return 0;
}
