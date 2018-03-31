//
//  notes.h
//  study notes.
//
//  Created by czf on 18/02/2018.
//  Copyright © 2018 czf. All rights reserved.
//

#ifndef notes_h
#define notes_h

#endif /* notes_h */

/**
 字节 ==> 字符，机器字 ==> 整型。
 bool变量可寻址，所以它至少占1个字节。
 
 signed char, unsigned char, char(dependent on impl)
 int == signed int == signed
 float, double(default), long double: 1.2, 1.2f, 1.2L. F和L大小写均可。
 sizeof(N) == sizeof(signed N) == sizeof(unsigned N)
 
 后缀_t就是为了区分标准类型和typedef。
 
 送到cout的输出值都将被转化为字符的序列。
 cout << 10; 这里是把字符1然后是字符0送到输出流里。
 
 任何描述了初始值的声明都是一个定义。extern int def_a = 1; // wrong.
 
 声明的结构：描述符(可选)，基础类型，声明符，初始式(可选)。
 
 除了函数和名字空间，其他声明都需要[分号]结束。
 
 作用域和重复定义不冲突，比如两个文件定义了相同变量(重复定义)，每个变量的作用域都是文件。
 
 ::是作用域解析运算符。
 被遮蔽的全局变量可以用::去引用，局部变量没办法。
 
 函数参数被当作在函数最外层的块中声明的变量。
 void function(int x) {//这里就是函数最外层的块。}
 
 静态变量：全局的，名字空间的，局部静态的，类中的静态的。会进行默认初始化，清零；
 自动变量，动态分配的变量，不会进行默认初始化。注：不初始化也可通过编译。
 
 Point p(1, 2); // 通过构造函数完成初始化；
 int i(); // 但是，在声明中写一对空的括号总意味着是函数。
 
 对于内部类型而言，T(e)等价于(T)e。
 
 数组的大小必须常量表达式，即编译时可求值。
 {}形式只能给数组初始化，不能赋值。
 
 因为不允许赋值，所以常量必须进行进行初始化。
 const int arr[] = {1, 2}; // arr[i]是常量。
 
 逗号(,)是序列运算符。
 字符串[字面量]是静态分配的，所以让函数返回他们是安全的。
 字符串[字面量]的类型是[适当个数的const字符数组]。
 空字符串""类型是const char[1];
 
 空白字符：空格，换行符，制表符。
 按照默认方式，一个空白字符将结束一次<输入>。
 
 使用指针时涉及到两个对象：指针本身和它所指向的变量。
 
 可以显示的将void*转换为另一个类型(不必是指针)。
 不能对void*进行简介访问，也不能进行增减量(不知道被指对象大小)。
 到函数的指针和到成员的指针都不能赋给void*。
 
 struct是class的简单形式。struct的成员默认是public。
 
 函数参数传递的语意 == 初始化的语意。
 
 函数默认参数的类型在声明时检查，调用时求值。只能对最后一个参数提供默认参数。
 
 static变量为函数提供了一种存储器，避免了全局变量的引入。
 
 对一个函数只能做2件事：调用它，取它的地址。
 
 不允许在名字空间之外，通过限定词前缀的方式引进新的成员。
 名字空间是可以重复定义的，这时可以加入新成员。
 一个名字空间也是一个作用域。常规的局部、全局作用域和类也都是也都是名字空间。
 
 main函数必须不能在名字空间内。
 
 使用声明：using std::cout; 之后直接使用cout.
 使用指令：using namespace std; 之后直接使用cout.
 
 重载可以跨名字空间工作。
 定义函数时最好采用名字空间前缀的方式。
 名字空间别名可以用作前缀限定词，但无法重新打开名字空间。
 无名名字空间：编译单位内使用。
 
 inline函数必须在使用它的每个编译单位里，都有<完全一样>的定义。
 const,typedef都是内部连接。
 为了保证一致性，一般应该把全局的const和inline都仅仅放在头文件里。
 static也用于表示内部连接，但不要用。它只用于函数内部（全局存储），类内部（同java）。
 
 存在着一些实现，它们根本不把程序存储为源文件。（直接在内存里？烧写在主板上？）
 
 缺少声明将无法编译，缺少定义将无法连接。
 
 不同语言或同一语言的不同实现可能在以下方面存在差异：
 1、使用寄存器保存参数的方式；
 2、将参数放入堆栈的顺序；
 3、整数或字符串等内部类型的布局；
 4、编译器传递给连接器的名字；
 5、对连接器所要求的类型检查的量；
 
 extern "C" char * strcpy(char*, const char*);
 extern char * strcpy(char*, const char*);
 以上两个声明的差异仅仅在于调用strcpy的连接约定不同。extern "C"中的C是一种连接约定，
 而不是一种语言。
 
 Obj obj(); stack mem. Obj obj = new Obj(); heap mem.
 
 公历中没有0年，公元前1年（-1）后，就是公元1年（1）。
 
 以存储角度看：静态成员是类的一部分，<不是>对象的一部分。
 
 this并不是一个常规变量，不能取得它的地址或者给它赋值。
 
 void func() const {}; const_cast; mutable.
 
 原本非const变量，可以用const_cast转；原本就是const变量，用const_cast转可能出问题。
 
 枚举是一种用户定义类型。其范围：[0, 2^k - 1] or [-2^k, 2^k - 1].
 
 生成的默认构造函数，将隐式的为它的类类型成员和基类调用有关的默认构造函数。
 
 区分类类型和内部类型是为了与C的兼容性，也为了避免运行时开销。
 如果成员是内部类型的常量或引用，则必须提供构造函数。
 
 和c一样，c++不区分指向单个对象的指针和指向数组中起始元素的指针。

 从继承角度看，子类将具有父类的全部操作(私有除外)，子类更强大。但从容器角度来看(容器的操作)，
 它的元素的继承关系将不具有这种性质。例如，对于add操作，list<Fu>既可以添加fu，也可以添加
 zi，但是list<zi>只能添加zi。这里并没有'子类更强大'。

 友元：可以访问类中的私有部分，不在类的作用域，static性质。相当于：在类外定义的函数，
 类对象通过参数传入，函数里可以访问对象的私有部分。一个友元可以同时存在于多个类中，访问
 多个类的私有部分。
 */






