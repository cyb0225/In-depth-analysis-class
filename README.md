# In-depth-analysis-class 深入剖析c++类

首先，我认为深入研究c++类的结构的意义。虽然这部分内容聊不了解对于以后敲代码没什么影响，我越往后整理越能感觉到这些东西其实无关痛痒，但是这并不是没有意义的。C/C++是一门接触到内存的语言，可以说它被人喜欢和讨厌的原因都是指针（内存），可以随意使用内存可以使我们编写代码更加自由，但其也是C/C++语言不安全的主要原因，作为一个合格的C++程序员，熟练掌握指针和内存的是必要的技能。所以，本文的主要目的是使我们对内存的了解更深刻，在下次写类时能够游刃有余。


---


### 我将从以下几个方面一步步剖析类的内部结构。

* ### 类的内存结构
* ### 继承与多态
* ### RTTI机制



----
# 类的内存结构
##### C/C++是一门能够访问内存的语言，所以我们要充分利用它的特点，将类的内部构造透明的展现出来。 但是做什么事都不能急于求成，所以我从最简单的类的内存结构开始介绍，虽说是最简单的，里面也有很多门道。

我习惯把描述的文字写在代码旁边或代码文件的开头，所以可以直接按下面的顺序打开源文件进行阅读。

在开始之前，我们先学习一下关于指针的内容，指针转换起来可别被绕晕了。（还没写好）


ps：该块内容的文件放在class_memory文件夹下， 下面是对不同文件的描述以及观看顺序。

|  文件名   | 文件描述  |
|  :---  | ----  |
| non_virtual_inherit  | 最基础的类的内存结构及内存大小计算 |
| memory_Alignment      | 内存对齐下获取内存大小，改变默认内存对齐字节数，获取本机默认内存大小 |
| memory_Alignment_case | 内存对齐相关例子及类中内存是怎么布置的 |
| travel_class_memory   | 通过指针使类对象透明化 |
| memory_include        | 类在包含一个类的情况下的内存结构 |
| memory_inherit_class  | 类在普通继承下的内存结构 |
| memory_virtual_vptr   | 引入虚函数表和虚函数指针 |
| memory_virtual_class  | 类在虚函数继承下的内存结构 |
| memory_virtual_class_plus | 类在多继承下的内存结构 |
| additional_virtual_vptr | 剖析虚函数表，使用内存提取并使用里面的虚函数 |

ps：关于虚继承（区别于虚函数继承）的内容以后再加。。(虚继承就要考虑虚基类的内存了)



单继承的视图

<img src="../../Myblogs/cyb.github.io/_posts/picture/image-20220423183616037.png" alt="image-20220423183616037" style="zoom:33%;" />

![image-20220423183933173](../../Myblogs/cyb.github.io/_posts/picture/image-20220423183933173.png)



TODO:

1.  为什么需要一个虚函数表来存放虚函数，虚函数表对于在继承和多态时发挥了什么作用。
2. 



