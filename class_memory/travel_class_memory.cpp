/*
上一个程序说了内存对齐时是根据类里面变量声明的顺序进行插入/创建内存块的， 是不是真是这样，我们可以做个简单的小实验，把类对象里面的内存呈现出来看看
这里使用的是没有继承和虚函数的类，有了他们内存结构还会发生一些微秒的变化，后面会提及。 
对于普通的类，对象的地址其实也是第一个元素的地址

同时，这里你会更加深刻的体会到c/c++对于内存操作魔幻的魅力。你是否还觉得类的private是外界不可访问的？no，no，no，只要知道了这块的内存，你可以做任何事情。
*/


#include <iostream>

using namespace std;

class Foo {
public:
    Foo(int _x, double _y) : x(_x), y(_y) {}
    int x;
private:
    double y;
};


void travelClass() {
    Foo tmp(10, 10.0);
    void* p = &tmp;
    // 把p指针转为int*(虽然对于void 和 int 之间来说没区别)
    printf("tmp.x = %d\n", *((int*)p)); 

    /* 这里先把指针转成第一个元素的类型, +1 跳到第二个元素的位置，再转化成第二个元素的类型
    但是这里打印出来居然是0， 这也和y的值不一样啊， 这里其实是因为内存补齐的问题， int后面补齐了4位，
    所以我们现在访问的内存只用到y的前四位和空的4位，这里， p应该先转化补齐块的大小再进行 + 1*/
    printf("false tmp.y = %lf\n", *(double*)((int*)p + 1));  

    printf("true tmp.y = %lf\n", *(double*)((double*)p + 1)); // 这样就正确了， 同时也证明了前面内存补齐的猜想

    // 既然都可以访问类里面的私有成员了，那我们用内存来改变它不是轻而易举
    *(double*)((double*)p + 1) = 20;
    printf("new tmp.y = %lf\n", *(double*)((double*)p + 1));
}


int main() {

    travelClass();


}