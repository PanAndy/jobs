#include<iostream>
#include<vector>

using namespace std;


class Singleton
{
public:
    static Singleton* getInstance();
    int GetI(){return i;}
private:
    int i = 0;
    Singleton(){i++;}
    Singleton(const Singleton&) = delete;

    Singleton & operator=(const Singleton&) = delete;

    static Singleton* m_pSingleton;

};

Singleton* Singleton::m_pSingleton = new Singleton();

Singleton* Singleton::getInstance()
{
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
