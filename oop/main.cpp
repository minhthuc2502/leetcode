#include <iostream>

class A {
public:
    A() {
        std::cout << "Constructor of A" << std::endl;
    }
    virtual ~A() {
        std::cout << "Destructor of A" << std::endl;
    }

    virtual void getInstance(int& index) {
        std::cout << "Get instance A" << std::endl;
        index = 0;
    }

    const void virtual foo() const {
        std::cout << "Foo of A" << std::endl;
    }
};

class A1 : public A {
public:
    void getInstance(int& index) {
        std::cout << "Get instance A1" << std::endl;
        index = 1;
    }
    const void foo() const {
        std::cout << "Foo of A1" << std::endl;
    }
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
        a.foo();
        std::cout << "B1&A" << std::endl;
    } 
    void operator()(const A1& a1) {
        a1.foo();
        std::cout << "B1&A1" << std::endl;
    } 
};

template<class T>
void func(B&& b, T&& a) {
    b(std::forward<T>(a));
}

void func(B& b, A& a) {
    int index;
    a.getInstance(index);
    if (index == 1) {
        A1 tmp = static_cast<A1&>(a);
        return b(tmp);
    }
    b(a);
}
void func(B1& b, A1& a) {
    b(a);
}

int main() {
    B b;
    B1 b1;
    A a;
    A1 a1;
    // b(a);
    // b(a1);
    // b1(a);
    // b1(a1);
    A& aref = a1;
    B& bref = b1;

    // B* bb = new B1();
    // A* aa = new A1();
    // (*bb)(*aa);
    func(bref, aref);
    func(b1, a);

    // delete bb;
    // delete aa;
    return 0;
}

