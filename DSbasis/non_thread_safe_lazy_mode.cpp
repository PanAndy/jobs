#include<iostream>
#include<vector>

using namespace std;

class Singleton
{
public:
    static Singleton* getInstance();
    ~Singleton(){}
    int GetI(){return i;}
private:
    int i = 0;
    Singleton(){i++;}
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& obj) = delete;

    static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{

    if(m_pSingleton == NULL){
        m_pSingleton = new Singleton();
    }
    return m_pSingleton;
}

int main()
{
    Singleton *s = Singleton::getInstance();

    cout<<s->GetI()<<endl;
    for(int i=0;i<10;i++){
        Singleton *s2 = Singleton::getInstance();
        cout<<s2->GetI()<<endl;
    }
    return 0;
}
