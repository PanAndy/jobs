#include<iostream>
#include<vector>

using namespace std;

const int maxn = 10000;

//https://www.cnblogs.com/fyqq0403/p/10500396.html

class myqueue{
private:
    int max_size;
    int front; //需要注意的是这里的模型，front 指的是真实的队头的前一个下标，front + 1才是真实值
    int rear;
    int * array;

public:
    myqueue(){
        max_size = maxn;
        front = rear = 0;
        array = new int[max_size + 1];
    }
    ~myqueue(){
        delete [] array;
    }

    bool full(){
        return (rear + 1) % (max_size + 1) == front;
    }

    bool empty(){
        return front == rear;
    }

    int push(int value){
        if(this->full()){
            return -1;
        }
        rear = (rear+1)%(max_size+1);
        array[rear] = value;
        return rear;
    }

    int front_(){
        if(this->empty()){
            return -1;
        }
        return array[(this->front + 1) % (max_size + 1)];
    }

    int pop(){
        if(this->empty()){
            return array[this->front];
        }
        front = (front + 1)%(max_size + 1);
        return array[this->front];
    }
};

int main(){

    return 0;
}
