#include <iostream>
using namespace std;
class Base
{
    public:
        Base() { std::cout << "Base constructor\n"; }
        virtual void f() { std::cout << "Base f\n"; }
        virtual ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public virtual Base
{
    public:
        Derived() { std::cout << "Derived constructor\n"; }
        void f() override { std::cout << "Derived f\n"; }
        ~Derived() override { std::cout << "Derived destructor\n"; }
};

class Child : public virtual Base
{
    public:
        Child() { std::cout << "Child constructor\n"; }
        void f() override { std::cout << "Child f\n"; }
        ~Child() override { std::cout << "Child destructor\n"; }
};

int main()
{
    {
        std::cout << "===============\n";
        Base* p = new Derived;
        p->f();
        delete p;
        std::cout << "===============\n";
    }
    {
        std::cout << "===============\n";
        Base* p = new Child;
        p->f();
        delete p;
        std::cout << "===============\n";
    }
    std::cin.get();
}