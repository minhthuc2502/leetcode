#include <iostream>

class A
{
    public:
        A() { std::cout << "Constructor A " << std::endl; }
        A(int value):m_value(value){};
        ~A() = default;
        friend class B;
        friend void foo(A a);
        
    private:
        void Increase();
        int m_value;
};

void A::Increase() {
    m_value++;
}

void foo(A a) {
    a.Increase();
}

class B: public A
{
    public:
        B(int value):A(value) {}
        ~B() = default;
        void Access()
        {
            Increase();
            std::cout << m_value << std::endl;
        }
};

int main() {
    B b(15);
    b.Access();

    return 0;
}