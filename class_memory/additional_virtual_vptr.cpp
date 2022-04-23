/*
通过内存，把虚函数拿出来看看
*/

#include <iostream>

typedef void (*func)(void);// 这里先预设一个函数指针类型

using namespace std;
typedef void(*Fun)(void);

class Foo {
public:
    virtual void show() { cout << "hello world" << endl; }
    int x;
};  

void test() {
    Foo foo;
    foo.x = 10;
    // 指针和取地址可以说是进入内存世界的大门
    long long *p = (long long*)&foo;  // 我是64位系统跑的，所以这里用longlong来保存(int只有4位不能作为函数指针的参数传入)
    // int* p = (int*)&foo;
    // 可以把虚函数表看成一个存放虚函数的数组，所以我们可以像数组一样把里面的虚函数拿出来用


    /*我上面说了像操作数组一样去操作一个虚函数表，但是还记得我之前说的吗，class里面存的不是虚函数表，而是指向虚函数表的指针，
    所以我们上面得到的虚指针解引用才是虚函数表的头结点，还有一次解引用是通过虚函数表解引用去找虚函数的地址
    知道这个后下面的操作部分在关于指针的文件讲解了*/
	func vTable_f = (func) * (long long*)(*p);
    vTable_f();

    cout << "Foo::x = " << *((int*)p + 2)  << endl; 
}


int main() {
    // printf("sizeof(void*)%d, sizeof(double*)%d\n", sizeof(void*), sizeof(double*));
    test();
}