/*
初步认识虚函数表指针后，我们开始解剖虚函数继承的内存结构（单继承）

派生类在继承有虚函数的基类的时候会继承它的虚指针
同时派生类自己有特有的虚函数时，会把虚函数放到基类的虚函数指针后面，而不是在创建一个虚函数指针

多重继承就是单继承的套娃，没啥好说的

但是多继承就不同了，由于继承的基类是不同的（假设他们是没有关系的），那么对于派生类来说它就不止有一个虚指针（为什么这么设计，多态会说）
所以对于多继承的派生类来说，虚指针是看基类的个数了
*/

#include <iostream>

using namespace std;

//case 1 
class Base{
    virtual void show() { }
};

class Derived : public Base {
    virtual void show(){}
    // 在覆写虚函数时，如果在前面再加上一个virtual关键字，它使用的还是基类的虚指针
    // virtual void show() {} 
    virtual void Dshow() {}
};

// 多重继承
class DDerived : public  Derived {
    void show() {}
    void Dshow() {}
    virtual void DDshow() {}
};

// 多继承
class Base1{
    virtual void show() { }
};

class Mul_Derived : public Base , public Base1 {
    // 啥也不干 , 看一下是不是有两个虚指针的大小
};


void getClassSize() {

    printf("Base = %d\n", sizeof(Base));        // 8 
    printf("Derived = %d\n", sizeof(Derived));  // 8 (沿用基类的虚函数指针)
    printf("DDerived = %d\n", sizeof(DDerived));// 8 (沿用基类的虚函数指针)
    printf("Mul_Derived = %d\n", sizeof(Mul_Derived));  // 16 (有两个虚函数指针)
}

int main() {

    getClassSize();

}