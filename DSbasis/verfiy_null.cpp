#include<iostream>

#define NULL nullptr

using namespace std;

struct BinaryTreeNode{
    double val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode():val(0),left(NULL),right(NULL){};
    BinaryTreeNode(int v):val(v),left(NULL),right(NULL){};
};

int main(){
    BinaryTreeNode* node = new BinaryTreeNode(2);

    cout<<"node->vale:"<<node->val<<endl;
    if(node->left == NULL){
        cout<<"left is null"<<endl;
    }else{
        cout<<"left is not null"<<endl;
    }

    if(node->right == NULL){
        cout<<"right is null"<<endl;
    }else{
        cout<<"right is not null"<<endl;
    }
    return 0;
}
