/*
既然我们已经知道了普通类的内存计算，那么后面继承的内存也会变得简单起来了。 （这里也还没有设计到虚函数的内容）
1.首先类还是需要满足内存对齐的原则
但还要考虑下面几个问题：1.如果一个类存在内存补齐（也就是它其实有没有利用的空间），那么它作为其他类的成员时，这块空间能否继续被利用

*/
#include <iostream>
// #pragma pack(4)

using namespace std;

// 普通的对照组
class Base_D {
    double x;
};

class Subclass_D {
    Base_D bd;
    char c;
};

// 解释问题1
/*编译器不会拆开类里面的东西，而是把它看成一个整体（16），作为一个内存大小与默认位进行对比，所以是16 + 8 （默认补齐位大小）
所以为了引证这个猜想， 我们可以改变默认补齐大小来确定。首先我改变pack为4，得到的结果是16 (12 + 4)  12 是因为补齐块大小变成4，Base类的大小也变了
很好，是我想要的结果，再次将pack改变为2， 得到14(12 + 2), pack(1) 得到 13（12 + 1），那么我们基本可以确认是这种情况了， 类是作为对象放入的*/

class Base_Mul {
    double d;
    int x;
};

class Subclass_Mul {
public:
    Base_Mul bm;
    char c;
};



void getClassSize() {
    printf("Base_D = %d\n", sizeof(Base_D));            // 8
    printf("Subclass_D = %d\n", sizeof(Subclass_D));    // 8 + 1 + (7)

    printf("Base_Mul = %d\n", sizeof(Base_Mul));            // 8 + 4 + (4) = 16
    printf("Subclass_Mul = %d\n", sizeof(Subclass_Mul));    // pack(8): 16 + 1 + (7) = 24   pack(4): 16 + 1 + (3) = 20
}   

int main() {
    
    getClassSize();
}