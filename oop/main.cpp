#include <iostream>

class A {
public:
    A() {
        std::cout << "Constructor of A" << std::endl;
    }
    virtual ~A() {
        std::cout << "Destructor of A" << std::endl;
    }
    // A virtual operator()() {
    //     return *this;
    // }
};

class A1 : public A {
public:
        // A1 virtual operator()() override {
        //     return *this;
        // }
};

class B{
public:
    B() {
        std::cout << "Constructor of B" << std::endl;
    }
    ~B() {
        std::cout << "Destructor of B" << std::endl;
    }
    void virtual operator()(const A& a) {
        std::cout << "B&A" << std::endl;
    } 
    void virtual operator()(const A1& a1) {
        std::cout << "B&A1" << std::endl;
    } 
};

class B1: public B {
public:
    void operator()(const A& a) {
        std::cout << "B1&A" << std::endl;
    } 
    void operator()(const A1& a1) {
        std::cout << "B1&A1" << std::endl;
    } 
};

template<class T>
void func(B&& b, T&& a) {
    b(std::forward<T>(a));
}

void func(B& b, A& a) {
    b(a);
}

int main() {
    // B b;
    B1 b1;
    // A a;
    A1 a1;
    // b(a);
    // b(a1);
    // b1(a);
    // b1(a1);

    B* bb = new B1();
    A* aa = new A1();
    (*bb)(*aa);
    func(b1, a1);

    delete bb;
    delete aa;
    return 0;
}

