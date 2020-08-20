#include<iostream>

using namespace std;

struct DbNode
{

    int val;
    DbNode* left;
    DbNode* right;

    DbNode(){left = this;right = this;}
    DbNode(int x):val(x){left=this;right=this;}
};

int GetLength(DbNode* head)
{
    int len = 0;
    if(head == NULL)return 0;
    DbNode* cur = head->right;
    while(cur!=NULL)
    {
        cur=cur->right;
        len++;
    }
    return len;
}

void print_dblist(DbNode* head)
{
    if(head->right == NULL){
        cout<<"Empty!"<<endl;
        return ;
    }

    DbNode* cur = head->right;
    while(cur!=NULL)
    {
        cout<<cur->val<<" ";
        cur = cur->right;
    }
    cout<<endl;
}

int main()
{
    freopen("list_val.txt","r",stdin);

    DbNode* head = new DbNode(0);

    cout<<head<<endl;
    cout<<head->left<<endl;
    cout<<head->right<<endl;

    int val = 0;
    DbNode* cur = head;
    while(cin>>val)
    {
        DbNode* tmp = new DbNode(val);
        cur->right = tmp;
        tmp->left = cur;
        tmp->right = NULL;
        cur = cur->right;
    }
    print_dblist(head);

    cout<<GetLength(head)<<endl;
    return 0;
}
