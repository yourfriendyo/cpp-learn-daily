#include <iostream>
#include <memory>
using namespace std;

namespace test
{
    template <class T>
    class auto_ptr
    {
    public:
        auto_ptr(T* ptr) : _ptr(ptr)
        {}

        auto_ptr(auto_ptr& sp)
            : _ptr(sp._ptr)
        {
            sp._ptr = nullptr;
        }

        T& operator*()
        {
            return *_ptr;
        }
        T& operator->()
        {
            return _ptr;
        }

        auto_ptr& operator++()
        {
            ++_ptr;
        }
        auto_ptr& operator--()
        {
            --_ptr;
        }

        ~auto_ptr()
        {
            if (_ptr)
            {
                cout << "delete :" << _ptr << endl;
                delete _ptr;
            }
        }

    private:
        T* _ptr;
    };

    void test_auto_ptr()
    {
        test::auto_ptr<int> p1(new int);
        *p1 = 0;

        test::auto_ptr<int> p2(p1); // 管理权转移

        cout << *p2 << endl;
        cout << *p1 << endl; //程序崩溃

    }

    template <class T>
    class unique_ptr
    {
    public:
        unique_ptr(T* ptr) : _ptr(ptr)
        {}

        unique_ptr(const unique_ptr<T>& sp) = delete;

        T& operator*()
        {
            return *_ptr;
        }
        T& operator->()
        {
            return _ptr;
        }

        unique_ptr& operator++()
        {
            ++_ptr;
        }
        unique_ptr& operator--()
        {
            --_ptr;
        }

        ~unique_ptr()
        {
            cout << "delete :" << _ptr << endl;
            delete _ptr;
        }

    private:
        T* _ptr;
    };

    void test_unique_ptr()
    {
        std::unique_ptr<int> up1(new int);
        //std::unique_ptr<int> up2(up1); // 编译报错
    }

    //template<class T>
    //class shared_ptr
    //{
    //public:
    //    shared_ptr(T* ptr)
    //        : _ptr(new int)
    //    {
    //        _useCount = 1;
    //    }
    //
    //    shared_ptr(const shared_ptr<T>& sp)
    //        : _ptr(sp._ptr)
    //    {
    //        _useCount++;
    //    }
    //
    //    T* operator->()
    //    {
    //        return _ptr;
    //    }
    //    T& operator*()
    //    {
    //        return *_ptr;
    //    }
    //
    //    ~shared_ptr()
    //    {
    //        if (--_useCount == 0) // 最后一个管理对象
    //            delete _ptr;
    //    }
    //
    //private:
    //    T* _ptr;
    //    static int _useCount; // 引用计数
    //};
    //
    //template <class T>
    //int shared_ptr<T>::_useCount = 0;

    template<class T>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr)
            : _ptr(new int(0))
            , _pUseCount(new int(1)) // 为资源配一个引用计数
        {}

        shared_ptr(const shared_ptr<T>& sp)
            : _ptr(sp._ptr)
            , _pUseCount(sp._pUseCount)
        {
            (*_pUseCount)++;
        }

        T* operator->()
        {
            return _ptr;
        }
        T& operator*()
        {
            return *_ptr;
        }

        ~shared_ptr()
        {
            if (--(*_pUseCount) == 0) // 最后一个管理对象
            {
                cout << "delete" << _ptr << endl;
                delete _ptr;
                delete _pUseCount;
            }
        }

    private:
        T* _ptr;
        int* _pUseCount; // 引用计数
    };

    void test_shared_ptr()
    {
        shared_ptr<int> sp1(new int);
        shared_ptr<int> sp2(sp1);
        shared_ptr<int> sp3(sp2);

        shared_ptr<int> sp4(new int);

    }

}