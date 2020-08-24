#include <iostream>

using namespace std;

int getNext(int i, int m, int n)
{

    return (i % n) * m + i / n;
}

int getPre(int i, int m, int n)
{

    return (i % m) * n + i / m;
}

void movedata(int *mtx, int i, int m, int n)
{

    int temp = mtx[i];
    int cur = i;
    int pre = getPre(cur, m, n);
    while(pre != i)
    {
        mtx[cur] = mtx[pre];
        cur = pre;
        pre = getPre(cur, m, n);

    }
    mtx[cur] = temp;
}

void transpose(int *mtx, int m, int n)
{

    for(int i=0;i<m*n;i++)
    {

        int next = getNext(i, m, n);
        while(next > i)
        {
            next = getNext(next, m, n);
        }
        if(next == i)
        {
            movedata(mtx, i, m, n);
        }
    }
}

/* Êä³ö¾ØÕó */
void print(int *mtx, int m, int n)
{
  for(int i=0; i<m*n; ++i)
  {
    if((i+1)%n == 0)
      cout << mtx[i] << "\n";
    else
      cout << mtx[i] << " ";
  }
}

/* ²âÊÔ */
int main()
{
  int matrix[4*2] = {1,2,3,4,5,6,7,8};
  cout << "Before matrix transposition:" << endl;
  print(matrix, 4, 2);
  transpose(matrix, 4, 2);
  cout << "After matrix transposition:" << endl;
  print(matrix, 2, 4);
  return 0;
}
