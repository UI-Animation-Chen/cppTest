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
 typedef定义(重命名)了一种类型，而不是一个变量。
 
 送到cout的输出值都将被转化为字符的序列。
 cout << 10; 这里是把字符1然后是字符0送到输出流里。
 
 任何描述了初始值的声明都是一个定义。extern int def_a = 1; // wrong.
 
 声明的结构：描述符(可选)，基础类型，声明符，初始式(可选)。
 
 除了函数和名字空间，其他声明都需要[分号]结束。
 
 作用域和重复定义不冲突，比如两个文件定义了相同变量(重复定义)，每个变量的作用
 域都是文件。
 
 ::是作用域解析运算符。
 被遮蔽的全局变量可以用::去引用，局部变量没办法。
 当::前面没有前缀时，表示从全局作用域寻找变量，如：
     int a = 10;
     namespace N
     {
         int a = 100;
         void f()
         {
              int a = 1000;
              std::cout << a << std::endl;    //prints 1000
              std::cout << N::a << std::endl; //prints 100 
              std::cout << ::a << std::endl;  //prints 10
         }
     }
 
 函数参数被当作在函数最外层的块中声明的变量。
 void function(int x) {//这里就是函数最外层的块。}
 
 静态变量：全局的，名字空间的，局部静态的，类中的静态的。会进行默认初始化，清零；
 自动变量，动态分配的变量，不会进行默认初始化。注：不初始化也可通过编译。
 
 Point p(1, 2); // 通过构造函数完成初始化；
 int i(); // 但是，在声明中写一对空的括号总意味着是函数。
 
 对于内部类型而言，T(e)等价于(T)e。
 
 在几乎所有的[表达式]中，数组名都是一个指针[常量]，指向第一个元素。
 &:     对数组名取地址，得到一个[指向数组的指针]。
 sizeof:返回整个数组的长度，而不是指向数组的指针的长度。
 
 数组的大小必须常量表达式，即编译时可求值。
 {}形式只能给数组初始化，不能赋值。
 
 一维数组做函数参数时，编译器总是把它解析成一个指向其首元素的指针(不是常量)。
 实际传递的数组大小与形参指定的数组大小没关系。
 function(int arr[]) {}
 这里编译器把arr解析为指向int的指针，方括号中的数字根本不看，等价于int *arr
 
 因为不允许赋值，所以常量必须进行进行初始化。
 const int arr[] = {1, 2}; // arr[i]是常量。arr本身就是常量。
 
 逗号(,)是序列运算符。
 字符串[字面量]是静态分配的，所以让函数返回他们是安全的。
 字符串[字面量]的类型是[适当个数的const字符数组]。
 空字符串""类型是const char[1];
 
 空白字符：空格，换行符，制表符。
 按照默认方式，一个空白字符将结束一次<输入>。
 
 使用指针时涉及到两个对象：指针本身和它所指向的变量。
 
 可以显示的将void*转换为另一个类型(不必是指针)。
 不能对void*进行间接访问，也不能进行增减量(不知道被指对象大小)。
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
 
 存在着一些实现，它们根本不把程序存储为源文件。
 
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

 公历中没有0年，公元前1年（-1）后，就是公元1年（1）。
 
 以存储角度看：静态成员是类的一部分，<不是>对象的一部分。
 
 this并不是一个常规变量，不能取得它的地址或者给它赋值。
 
 void func() const {}; const_cast; mutable.
 
 原本非const变量，可以用const_cast转；原本就是const变量，用const_cast转可能出问题。
 
 枚举是一种用户定义类型。其范围：[0, 2^k - 1] or [-2^k, 2^k - 1].
 
 生成的默认构造函数，将隐式的为它的类类型成员和基类调用有关的默认构造函数。

 class A {
 public:
	A();
	A(int a = 0); // 编译错误，参数有默认值，调用可不传值，有歧义。
 };
 
 Obj obj(); stack mem. Obj obj = new Obj(); heap mem.
 调用构造函数后面加不加括号的区别：
 a, 在栈中
	A a; // 实例化对象，调用无参构造函数。
	A a(); // 声明了一个函数。
 b, 在堆中
	1，编译器自动生成的构造函数：
		A *a = new A; // 不会进行初始化
		A *a = new A(); // 初始化为0
	2，自己定义了构造函数
		A *a = new A;
		A *a = new A(); // 两者无区别。
 
 区分类类型和内部类型是为了与C的兼容性，也为了避免运行时开销。
 如果成员是内部类型的常量或引用，则必须提供构造函数。
 
 和c一样，c++不区分指向单个对象的指针和指向数组中起始元素的指针。

 从继承角度看，子类将具有父类的全部操作(私有除外)，子类更强大。但从容器角度来看(容
 器的操作)， 它的元素的继承关系将不具有这种性质。例如，对于add操作，list<Fu>既可以
 添加fu，也可以添加zi，但是list<zi>只能添加zi。这里并没有'子类更强大'。

 友元：可以访问类中的私有部分，不在类的作用域，static性质。相当于：在类外定义的函数，
 类对象通过参数传入，函数里可以访问对象的私有部分。一个友元可以同时存在于多个类中，
 访问多个类的私有部分。
 
 以下运算符不能重载：
    :: . .* ?: sizeof typeid
 不允许引入新的运算符。
 
 c++里，++a的意思是a+=1，其结果是一个左值。后缀则是右值。c里前缀后缀的结果都是右值。
 
 =(赋值) &(取地址) ,(序列)运算符应用于类对象时已经有了预先定义的意义，可以将其定义
 为私用来禁止使用他们，也可以重新定义新的意义。
 
 在使用指针或者引用时，才能使用多态。
 
 用一个类作为基类，相当于声明一个该类的（匿名）对象，所以基类必须先定义，而不只是声
 明。同理，子类也必须调用基类的构造函数，显示或隐式地，默认构造函数可以被隐式地调用。
 
 类中的私有成员：本类中的成员函数，友元函数可访问。
 
 Zi zi;
 Fu fu = zi; 这种情况称为切割。所以要使用指针或者引用。
 
 如果没有定义赋值运算符，编译器会生成一个。这也意味着赋值运算符是不继承的。构造函
 数也不。

 a、int i; i = 1;
 b、int i = 1; 
 a和b这2种情况是有区别的。
 a情况中首先调用构造函数，然后再调用赋值构造函数，
 b情况中直接调用了复制构造函数。
 因此，也说明了赋值构造函数中是要处理前对象资源的，而复制构造函数压根没有前对象。

 c++ 11中新增的右值引用特性
 template<typename T>
 std::move(T &&t) { ... }
 函数move的形参并不表示右值引用，因为模版T是啥还不确定，比如T本身就是左值、右值引用
 因此就有了”引用折叠“:
 T& &, T& &&, T&& &都折叠成T&, T&& &&折叠成T&&，即：
 一个引用的引用折叠成左值引用，右值引用的右值引用折叠成右值引用。
 
 在虚函数第一个声明所在的类里，该虚函数也必须给予定义，除非被声明为纯虚函数。
 
 通过作用域解析运算符::去调用函数，就可以不使用虚函数机制(多态)。
 另外，如果virtual函数也是inline的，那么带限定词就可以使用在线替换。
 
 虚函数：运行时多态；
 模板：编译时多态或参数式多态。
 
 在堆栈回退过程中，会对所有构造起来(完成构造)的局部对象调用析构函数。
 如果在构造函数里申请了资源后才抛出异常，那么该资源就不会被释放。
 
 X *x = new X; 在X构造函数里出现异常，new会负责内存释放。
 new的放置语法则不是这种处理方式。
 
 void fn(); 可能抛出任何异常
 void fn() throw (); 不会抛出异常
 void fn() throw (X); 只会抛出X异常，以及由X派生的异常。
 
 函数的异常描述可能导致掉用unexpected()，这是由于函数抛出了描述之外的异常。	
 
 如果一个异常抛出后没有被捕获，标准库函数uncaught_exception()就会返回true。
 可以在析构函数里利用这一点，来区分对待是正常销毁还是因为堆栈回退。
 
 异常描述并不是[函数类型]的一部分，typedef不能带有异常描述。
 
 重复基类层次结构
  普通继承     虚基类继承
  S    S         S
  |    |      /    \
  X    Y      X    Y
  \    /      \    /
    XY          XY
 右边的也称为钻石型继承结构。
 普通继承中，基类的对象将有对应的分数。
 虚继承中，所有的虚继承共享同一个基类对象。
 两种情况都有时，所有的虚继承共享一个基类对象，普通继承都有自己的基类对象。
 
 
 */






