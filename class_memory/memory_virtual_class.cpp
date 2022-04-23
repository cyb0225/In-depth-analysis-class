/*
前面我一直在回避父类中包含虚函数的继承这个条件，因为加上这个条件之后，会引入一些新的内容，并且改变了类中的内存结构
下面我将尽可能理清思路，带你拨开虚函数继承神秘的面纱（虚函数继承不等于虚继承，虚继承会涉及更复杂的内容，本次RTTI的探索之旅暂且不会提及）
*/

/*
在剖析虚函数继承类的内存结构前，我们需要向你介绍什么虚函数关于内存的提出的虚函数表和虚指针的内容
（有关虚函数实现多态的剖析不放在这里讲解，尽量保持内容的独立性，虚函数的相关语法这里也不讲了）



*/