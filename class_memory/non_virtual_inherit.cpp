/*
计算没有虚函数以及继承情况下类内存的计算
*/

/*
类内存的规则
1. 内存对齐， 按照
*/
#include <iostream>

using namespace std;

// 空类
// 空类编译器还是会为其对象分配一个一字节的内存，主要用来标记该对象内存上的位置。
class EmptyClass{ };

// 存在单变量的类
class intElemClass {
    int x;
};

class charElemClass {
    char c;
};

// 存在函数以及静态变量的情况
// 函数和静态变量不占内存，但是编译器会为"空类"设置一个字节用来占位, 对象调用成员函数回去相应存放函数的内存寻找，静态变量类似
class funClass {
    static int x;
    void show() {}
};


void getBasicSize() {
    // 获得本机内置类型的size
    printf("sizeof(int) = %d\n", sizeof(int));      // 4
    printf("sizeof(void*) = %d\n", sizeof(void*));  // 8 
    printf("sizeof(char) = %d\n", sizeof(char));    // 1
}

void getClassSize() {
    printf("EmptyClass = %d\n", sizeof(EmptyClass));        // 1
    printf("intElemClass = %d\n", sizeof(intElemClass));    // 4
    printf("charElemClass = %d\n", sizeof(charElemClass));    // 1
    printf("funClass = %d\n", sizeof(funClass));            // 1 
}


int main(){
    getBasicSize();    
    getClassSize();
}
