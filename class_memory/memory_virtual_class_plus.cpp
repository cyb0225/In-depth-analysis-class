/*
这里来解决上面关于多继承遗留下来的问题
主要有两个：
1.多继承后对于派生类来说，两个虚函数指针是都放前面还是简单的将两个类的内存合起来，(合起来中间是否有隔阂)
2.多继承的话，派生类如果有虚函数，它会安插到哪里呢？ 
    答：如果子类改写了父类的虚函数，那么就会用子类自己的虚函数覆盖相应的父类虚函数；如果子类有新的虚函数，那么就添加到第一个虚函数表的末尾。
*/

#include <iostream>

using namespace std;

/*通过下面这个例子可以得出多继承里面的内存结构是简单的将两个类结合起来
vptr(b1)    8
int x       4
vptr(b2)    8
int x       4
*/
class Base1 {
    virtual void show() {}
    int x; 
};

class Base2 {
    virtual void show() {}
    int x; 
};

class Drived : public Base1, public Base2 {
    void show() {}  // 分别覆写两个基类里面的虚函数
    virtual void Dshow() {} // 会写到第一个继承的基类里的虚函数表里
};
 
void getClassSize() {
    printf("Base1 = %d\n", sizeof(Base1));  //8 + 4 + (4) = 16
    printf("Base2 = %d\n", sizeof(Base2));  //16
    printf("Drived = %d\n", sizeof(Drived));// 8 + 4 + (4) + 8 + 4 + (4) = 32
}

int main() {

    getClassSize();

}