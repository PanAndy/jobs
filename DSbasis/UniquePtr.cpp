#include<iostream>

using namespace std;


template<class T>
class UniquePtr
{
public:
    UniquePtr(T * pResource = NULL):m_Presource(pResource){}
    ~UniquePtr(){del();}

    void reset(T* pResource){
        del();
        m_pResource = pResource;
    }

    T* release()
    {
        T* pTemp = m_pResource;
        m_pResource = NULL;
        return pTemp;
    }

    T* get()
    {
        return m_pResource;
    }

    operator bool() const
    {
        return m_pResource != NULL;
    }

    T& operator *()
    {
        return *m_pResource;
    }
    T* operator -> ()
    {
        return m_pResource;
    }

private:
    void del()
    {
        if(m_pResource == NULL)return;
        delete m_pResource;
        m_pResource = NULL;
    }

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator = (const UniquePtr&) = delete;

    T* m_pResource; // 这个形式和单例模式很像呀。

};
