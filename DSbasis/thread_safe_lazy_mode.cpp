#include<iostream>
#include<mutex>

using namespace std;

std::mutex mt;

class Singleton
{
public :
    static Singleton* getInstance();
    int GetI(){return i;}
private:
    int i = 0;
    Singleton(){i++;}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
    if(m_pSingleton == NULL)
    {
        mt.lock();
        if(m_pSingleton == NULL)
        {
            m_pSingleton = new Singleton();
        }
        mt.unlock();
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
