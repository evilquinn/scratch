#include <iostream>
#include <memory>

class A
{
public:
    A() : size_(new size_t(10))
    {
        std::cout << "A ctor" << std::endl;
    }
    ~A(){};
    void destroy()
    {
        delete size_;
    }

private:
    size_t* size_;

};

class B
{
public:
    B() : mem_(new char[100]) {}
    ~B(){}
    void destroy()
    {
        delete[] mem_;
    }
private:
    char* mem_;
};


template<typename T>
void custom_deleter(T* const t)
{
    std::cout << "deleter" << std::endl;
    t->destroy();
}

template<typename T>
struct custom_unique_ptr : public std::unique_ptr<T, void(*)(T*)>
{
public:
    custom_unique_ptr(T* const t) :
        std::unique_ptr<T, void(*)(T*)>(t, custom_deleter<T>)
    {}
};


int main(int argc, char* argv[])
{

    A a;
    custom_unique_ptr<A> ap(&a);
    std::unique_ptr<B> bp(std::make_unique<B>());
    custom_unique_ptr<B> bpc(bp.get());



    return 0;
}
