#include<iostream>
#include<vector>

using namespace std;

struct node{
    int val;
    int flag;
    node* left;
    node* right;
    node(int x):left(NULL),right(NULL),val(x), flag(0){}
    node():left(NULL),right(NULL){}
};


//返回的是构造的二叉排序树的根结点
node* build_BST(node* root, int val)
{
    if(root==NULL){
        return new node(val);
    }

    if(root->val > val)
    {
        root->left = build_BST(root->left, val);
    }else{
        root->right = build_BST(root->right, val);
    }
}

vector<int> inorder;

void InOrder(node* root)
{
    if(root == NULL)return;

    InOrder(root->left);
    inorder.push_back(root->val);
    InOrder(root->right);

}

#include<stack>
stack<node*> s;
vector<int> inorder_iter;
void InOrderIter(node* root)
{
    node* p = root;

    while(!s.empty() || p!=NULL)
    {
        while(p != NULL){
            s.push(p);
            p = p->left;
        }

        if(!s.empty()){
            p = s.top();
            s.pop();
            inorder_iter.push_back(p->val);
            p = p->right;
        }
    }
}

vector<int> post_order_unrec;


void PostOrderUnRec(node* root)
{
    stack<node*> s2;
    node* p = root;
    while(p!=NULL || !s2.empty())
    {
        while(p!=NULL)
        {
            s2.push(p);
            p = p->left;
        }

        if(!s2.empty())
        {
            p = s2.top();
            if(p->flag)
            {
                post_order_unrec.push_back(p->val);
                s2.pop();
                p=NULL;
            }else{
                p->flag = 1;
                p = p->right;
            }
        }
    }
}


vector<int> levelorder;
#include<queue>
void LevelOrder(node* root)
{
    queue<node*> q;
    node* p = NULL;
    q.push(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        levelorder.push_back(p->val);

        if(p->left!=NULL)q.push(p->left);
        if(p->right!=NULL)q.push(p->right);

    }
}


int main()
{
    freopen("list_val.txt","r",stdin);

    node* root = NULL;
    int val = 0;
    while(cin>>val)
    {
        root = build_BST(root, val);
    }

    InOrder(root);
    for(int i=0;i<inorder.size();i++)
    {
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    InOrderIter(root);
    for(int i=0;i<inorder_iter.size();i++){
        cout<<inorder_iter[i]<<" ";
    }
    cout<<endl;

    PostOrderUnRec(root);
    for(int i=0;i<post_order_unrec.size();i++)
    {
        cout<<post_order_unrec[i]<<" ";
    }
    cout<<endl;


    LevelOrder(root);
    for(int i=0;i<levelorder.size();i++)
    {
        cout<<levelorder[i]<<" ";
    }
    cout<<endl;
    return 0;
}
