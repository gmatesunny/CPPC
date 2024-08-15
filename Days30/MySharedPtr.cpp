
#include <iostream>

using namespace std;



template<typename T>
class MySharedPtr
{
private:

    struct MySharedPtrCntData
    {
        T* pointee;
        int refCnt;
    };

    MySharedPtrCntData* mySharedPtrCntDataPtr;
    
    void release()
    {
        mySharedPtrCntDataPtr->refCnt--;
        if(!mySharedPtrCntDataPtr->refCnt)
        {
            delete mySharedPtrCntDataPtr->pointee;
            delete mySharedPtrCntDataPtr;
        }
    }

public:
    explicit MySharedPtr<T>(T* pointee) : mySharedPtrCntDataPtr(new MySharedPtrCntData())
    {
        mySharedPtrCntDataPtr->pointee = pointee;
        mySharedPtrCntDataPtr->refCnt++;
    }

    explicit MySharedPtr<T>(const MySharedPtr<T>& source) : mySharedPtrCntDataPtr(source.mySharedPtrCntDataPtr)
    {
        mySharedPtrCntDataPtr->refCnt++;
    }

    ~MySharedPtr<T>()
    {
        release();
    }

    MySharedPtr<T>& operator=(const MySharedPtr<T>& source)
    {
        release();
        mySharedPtrCntDataPtr = source.mySharedPtrCntDataPtr;
        mySharedPtrCntDataPtr->refCnt++;
        return *this;
    }

    T* operator->()
    {
        return mySharedPtrCntDataPtr->pointee;
    }

    T& operator*()
    {
        return *mySharedPtrCntDataPtr->pointee;
    }

};

int main()
{
    const MySharedPtr<int> i1(new int(5));
    MySharedPtr<int> i2(new int(10));
    MySharedPtr<int> j(i1);

    cout << *j << endl;
}
