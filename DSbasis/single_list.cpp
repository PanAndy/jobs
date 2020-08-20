#include<iostream>

using namespace std;


struct node
{
    int val;
    node* next;
    node(){next = NULL;}
    node(int x):val(x),next(NULL){}
};

void print_list(node* head)
{
    node* cur = head->next;

    if(cur == NULL)cout<<"link is empty.";
    while(cur!=NULL)
    {
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}

node* find(node* head, int val)
{
    node* cur = head->next;

    while(cur != NULL)
    {
        if(cur->val == val){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}


//将data插入到第pos个节点后面
node* insert_node(node* head, int pos, int data)
{
    node* cur = head->next;
    node* tmp = new node(data);
    if(pos == 0)
    {
        tmp->next = cur;
        head->next = tmp;
    }

    while(pos-- && cur!=NULL)
    {
        cur = cur->next;
    }

    if(cur!=NULL)
    {
        tmp->next = cur->next;
        cur->next = tmp;
    }else{
        cout<<"index out of range."<<endl;
    }
    return head;
}

node* delete_list(node* head, int pos)
{
    node* cur = head->next;
    if(cur == NULL){
        cout<<"link is empty!"<<endl;
    }

    while(pos-- && cur!=NULL)
    {
        cur = cur->next;
    }

    if(cur!=NULL && cur->next!=NULL)
    {
        node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
    }
    return head;
}


node* reverse(node* head)
{
    node* cur = head->next;

    node* pre = NULL;
    node* next = NULL;
    while(cur!=NULL)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    head->next = pre;
    return head;
}

node* search_middle(node* head)
{
    node* fast = head->next;
    node* slow = head->next;

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }else{
            break;
        }
        slow = slow->next;
    }
    return slow;
}

node* Partition(node* pBegin, node* pEnd)
{
    int key = pBegin->val;
    node* pSlow = pBegin;
    node* pFast = pSlow->next;
    node* temp = pBegin;

    while(pFast!=NULL && pFast != pEnd->next)
    {
        //这等于就是直接向前搬运较小的数，用slow记录要搬运去的位置。
        if(pFast->val < key)
        {
            temp = pSlow;
            pSlow = pSlow->next;
            swap(pSlow->val, pFast->val);
        }
        pFast = pFast->next;
    }

    swap(pSlow->val, pBegin->val);
    return temp;
}

void QuickSortList(node* pHead, node* pEnd)
{
    if(pHead!=pEnd)
    {
        node* pivot = Partition(pHead, pEnd);
        QuickSortList(pHead, pivot);
        QuickSortList(pivot->next, pEnd);
    }
}

bool IsLoop(node* head, node** start)
{
    node* p1 = head;
    node* p2 = head;
    if(head==NULL || head->next==NULL)return false;
    while(p2!=NULL && p2->next!=NULL && p1)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if(p1 == p2)return true;
    return false;
}


int main()
{
    freopen("list_val.txt","r", stdin);

    node* head = new node();

    int val = 0;
    node *cur = head;
    while(cin>>val)
    {
        cur->next = new node(val);
        cur = cur->next;
    }
    cur->next = NULL;

    print_list(head);

    node *res = find(head, 9);
    cout<<res <<endl;
    cout<<find(head, 10)<<endl;

    cur = insert_node(head, 8, 10);
    print_list(cur);


    cur = delete_list(head, 8);
    print_list(cur);

    cur = reverse(head);
    print_list(cur);


    cur = search_middle(head);
    cout<<cur->val<<endl;


    node* pEnd = head->next;
    while(pEnd->next!=NULL)
    {
       pEnd = pEnd->next;
    }
    QuickSortList(head->next, pEnd);
    print_list(head);
    return 0;

}
