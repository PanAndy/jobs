#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int h, w;
    cin>>h>>w;
    vector<vector<int> > g(h, vector<int>(w, 0));

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>g[i][j];
        }
    }
    int m;
    cin>>m;
    vector<vector<double> > kernel(m, vector<double>(m, 0));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>kernel[i][j];
        }
    }
    int t_h = h - m + 1, t_w = w - m + 1;
    if(t_h <= 0|| t_w <= 0)cout<<endl;
    else{
        vector<vector<int> > conv(t_h, vector<int>(t_w, 0));

        for(int i=0;i<t_h;i++)
        {
            for(int j=0;j<t_w;j++)
            {
                double temp = 0;
                for(int r=i;r<i+m;r++)
                {
                    for(int s=j;s<j+m;s++)
                    {
                        temp += g[r][s] * kernel[r - i][s - j];
                    }
                }
                conv[i][j] = temp;
            }
        }
        for(int i=0;i<t_h;i++)
        {
            for(int j=0;j<t_w;j++)
            {
                cout<<conv[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
