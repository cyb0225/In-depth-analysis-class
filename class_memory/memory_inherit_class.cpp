/*
接下来是对没有虚函数的继承的内存结构的剖析
这里同样去考虑继承的父类是以整体的结构存放的还是散装分布的，同时剖析它的内存查看父类的元素存放在哪里
*/

#include <iostream>

using namespace std;

/*通过对内存的打印，我发现继承和包含的内存结构是不一样的。
在默认补齐块为8的情况下，下面基类和派生类的打印结果是都是16 基类:(8 + 4 + (4)) 派生类(8 + 4 + 4)
继承不会像包含一样将被包含的类封装起来，而是将派生类和基类的元素排在一块，而要得到结果说明元素的顺序是 double + int + int （也可能是反过来 i i d）
这里我将Base里的double和int变化一下位置（即形成memory_Alignment_case文件里说的对照模型）从而得到我们上面提出问题的答案
得到结果是24(4 + (4) + 8 + 4 + (4)) ，所以我们可以得出结论，继承关系是里父类元素对子类是没有隔阂的，并且父类的元素会放在内存靠前的位置
*/

class Base {
    double d;       
    int x;
};

class Subclass : public Base{
    int y;
};

// 2. 对照组

class Base1 {
    int x;
    double d;       
};

class Subclass1 : public Base1{
    int y;
};

void getClassSize() {
    printf("Base = %d\n", sizeof(Base)); // 8 + 4 + (4) = 16
    printf("Subclass = %d\n", sizeof(Subclass)); // 16
    
    printf("Base1 = %d\n", sizeof(Base1)); // 8 + 4 + (4) = 16
    printf("Subclass1 = %d\n", sizeof(Subclass1)); // 4 + (4) + 8 + 4 + (4) = 24
}

int main() {

    getClassSize();

}
