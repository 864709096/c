# c
**************************************************

Difference between i++ and ++i

++i will increment the value of i, and then return the incremented value.

 i = 1;
 j = ++i;
 (i is 2, j is 2)
 
i++ will increment the value of i, but return the original value that i held before being incremented.

 i = 1;
 j = i++;
 (i is 2, j is 1)







**************************************************

区分不同进制数字的一个简单办法就是，在输出时带上特定的前缀。在格式控制符中加上#即可输出前缀，例
如 %#x、%#o、%#lX、%#ho 等


**************************************************

当赋值的元素少于数组总体元素的时候，剩余的元素自动初始化为 0：  对于 short、int、long，就是整数 0；  对于 char，就是字符 '\0'；  对于 float、double，就是小数 0.0。


**************************************************

需要注意的是，逐个字符地给数组赋值并不会自动添加'\0'，例如：
char str[] = {'a', 'b', 'c'};
数组 str 的长度为 3，而不是 4，因为最后没有'\0'。
当用字符数组存储字符串时，要特别注意'\0'，要为'\0'留个位置；这意味着，字符数组的长度至少要比字符串的长
度大 1。请看下面的例子：
char str[7] = "abc123";
"abc123"看起来只包含了 6 个字符，我们却将 str 的长度定义为 7，就是为了能够容纳最后的'\0'。如果将 str 的
长度定义为 6，它就无法容纳'\0'了。

**************************************************

在函数内部定义的变量、数组、结构体、共用体等都称为局部数据。在很多编译器下，局部数据的初始值都是随机
的、无意义的，而不是我们通常认为的“零”值。这一点非常重要，大家一定要谨记，否则后面会遇到很多奇葩的






**************************************************

将数组的所有元素都初始化为“零”值
char str[30] = { 0 }; //将所有元素都初始化为 0，或者说 '\0'
错误。



**************************************************

注意，结构体变量名和数组名不同，数组名在表达式中会被转换为数组指针，而结构体变量名不会，无论在任何表
达式中它表示的都是整个集合本身，要想取得结构体变量的地址，必须在前面加&

通过结构体指针可以获取结构体成员，一般形式为：
(*pointer).memberName
或者：
pointer->memberName


int len = sizeof(stus) / sizeof(struct stu);

结构体指针作为函数参数
结构体变量名代表的是整个集合本身，作为函数参数时传递的整个集合，也就是所有成员，而不是像数组一样被编
译器转换成一个指针。如果结构体成员较多，尤其是成员为数组时，传送的时间和空间开销会很大，影响程序的运
行效率。所以最好的办法就是使用结构体指针，这时由实参传向形参的只是一个地址，非常快速。

**************************************************

还应该注意，结构体和结构体变量是两个不同的概念：结构体是一种数据类型，是一种创建变量的模板，编译器不
会为它分配内存空间，就像 int、float、char 这些关键字本身不占用内存一样；结构体变量才包含实实在在的数据，
才需要内存来存储。



**************************************************

case 关键字后面必须是一个整数，或者是结果为整数的表达式，
但不能包含任何变量，正是由于 Mon、Tues、Wed 这些名字最终会被替换成一个整数，所以它们才能放在 case 后
面。



**************************************************

共同体Union
共用体也是一种自定义类型
结构体和共用体的区别在于：结构体的各个成员会占用不同的内存，互相之间没有影响；而共用体的所有成员占用
同一段内存，修改一个成员会影响其余所有成员。
结构体占用的内存大于等于所有成员占用的内存的总和（成员之间可能会存在缝隙），共用体占用的内存等于最长
的成员占用的内存。共用体使用了内存覆盖技术，同一时刻只能保存一个成员的值，如果对新的成员赋值，就会把
原来成员的值覆盖掉。

union data a;
printf("%d, %d\n", sizeof(a), sizeof(union data) );


包含共用体的结构体

struct{
char name[20];
int num;
char sex;
char profession;
union{
    float score;
    char course[20];
     } sc;
} bodys[TOTAL];



**************************************************

有些数据在存储时并不需要占用一个完整的字节，只需要占用一个或几个二进制位即可。例如开关只有通电和断电
两种状态，用 0 和 1 表示足以，也就是用一个二进位。正是基于这种考虑，C 语言又提供了一种叫做位域的数据
结构

在结构体定义时，我们可以指定某个成员变量所占用的二进制位数（Bit），这就是位域。

struct bs{
unsigned m;
unsigned n: 4;
unsigned char ch: 6;
};



**************************************************

C 语言中不能直接使用二进制，&两边的操作数可以是十进制、八进制、十六进制，它们在内存中最终都是以二进
制形式存储


数据在内存中的存储

整数在内存中都是以补码的形式存放的
正数：正数的原码、反码、补码都相同。
负数：
原码 符号位是1，其余位和绝对值对应的正数相同。
反码 除符号位以外按位取反。
补码 反码加1。（所以负数在内存中的存储是对应的正数按位取反然后加1）


(32位操作系统)
5
原码  0000 0000 0000 0000 0000 0000 0000 0101
反码  0000 0000 0000 0000 0000 0000 0000 0101
补码  0000 0000 0000 0000 0000 0000 0000 0101

-5
原码  1000 0000 0000 0000 0000 0000 0000 0101
反码  1111 1111 1111 1111 1111 1111 1111 1010
补码  1111 1111 1111 1111 1111 1111 1111 1011
十六进制为
FFFFFFFB




**************************************************

 %f 以十进制形式输出 float 类型；
 %lf 以十进制形式输出 double 类型；
 %e 以指数形式输出 float 类型，输出结果中的 e 小写；
 %E 以指数形式输出 float 类型，输出结果中的 E 大写；
 %le 以指数形式输出 double 类型，输出结果中的 e 小写；
 %lE 以指数形式输出 double 类型，输出结果中的 E 大写。




%g 会对比小数的十进制形式和指数形式，以最短的方式
来输出小数，让输出结果更加简练。所谓最短，就是输出结果占用最少的字符。

 %g 默认最多保留六位有效数字，包括整数部分和小数部分；%f 和 %e 默认保留六位小数，只包括小数部分。


大家只需要死记硬背下面的两种表示形式即可：
1. char str1[] = "http://c.biancheng.net";
2. char *str2 = "C语言中文网";

**************************************************

escape character
转义字符以\或者\x 开头，以\开头表示后跟八进制形式的编码值，以\x 开头表示后跟十六进制形式的编码值。对于
转义字符来说，只能使用八进制或者十六进制。

1. char a = '\61'; //字符1
2. char b = '\141'; //字符a
3. char c = '\x31'; //字符1
4. char d = '\x61'; //字符a
5. char *str1 = "\x31\x32\x33\x61\x62\x63"; //字符串"123abc"
6. char *str2 = "\61\62\63\141\142\143"; //字符串"123abc"
7. char *str3 = "The string is: \61\62\63\x61\x62\x63" //混用八进制和十六进制形式

puts("C\tC++\tJava\n\"C\" first appeared!");
"C" first appeared!




关键字（Keywords）是由 C 语言规定的具有特定意义的字符串，通常也称为保留字，例如 int、char、long、float、
unsigned 等。

 多行注释以/*开头，以*/结尾，注释内容可以有一行或多行。


printf要手动添加换行符
puts不用


**************************************************

 当除数和被除数都是整数时，运算结果也是整数；如果不能整除，那么就直接丢掉小数部分，只保留整数部分，
这跟将小数赋值给整数类型是一个道理。
 一旦除数和被除数中有一个是小数，那么运算结果也是小数，并且是 double 类型的小数。


另外，余数可以是正数也可以是负数，由 % 左边的整数决定：
 如果 % 左边是正数，那么余数也是正数；
 如果 % 左边是负数，那么余数也是负数。



#include <stdio.h>
int main()
{
printf(
 "100%%12=%d \n100%%-12=%d \n-100%%12=%d \n-100%%-12=%d \n",
  100 % 12, 100 % -12, -100 % 12, -100 % -12
);
return 0;
}

运行结果：
100%12=4
100%-12=4
-100%12=-4 -100%-12=-4



# 表示 +、-、*、/、% 中的任何一种运算符。
注意：a #= b 仅是一种简写形式，不会影响程序的执行效率。

需要重点说明的是，++ 在变量前面和后面是有区别的：
 ++ 在前面叫做前自增（例如 ++a）。前自增先进行自增运算，再进行其他操作。
 ++ 在后面叫做后自增（例如 a++）。后自增先进行其他操作，再进行自增运算。


int a = 10, b = 20, c = 30, d = 40;
int a1 = ++a, b1 = b++, c1 = --c, d1 = d--;

输出结果：
a=11, a1=11
b=21, b1=20
c=29, c1=29
d=39, d1=40




**************************************************

在不同类型的混合运算中，编译器也会自动地转换数据类型，将参与运算的所有数据先转换为同一种类型，然后
再进行计算。转换的规则如下：
 转换按数据长度增加的方向进行，以保证数值不失真，或者精度不降低。例如，int 和 long 参与运算时，先把
int 类型的数据转成 long 类型后再进行运算。
 所有的浮点运算都是以双精度进行的，即使运算中只有 float 类型，也要先转换为 double 类型，才能进行运
算。
 char 和 short 参与运算时，必须先转换成 int 类型。


**************************************************

在这段代码中，有两点需要注意：
 对于除法运算，如果除数和被除数都是整数，那么运算结果也是整数，小数部分将被直接丢弃；如果除数和被
除数其中有一个是小数，那么运算结果也是小数。这一点已在《C 语言加减乘除运算》中进行了详细说明。
 ( )的优先级高于/，对于表达式(double) sum / count，会先执行(double) sum，将 sum 转换为 double 类型，
然后再进行除法运算，这样运算结果也是 double 类型，能够保留小数部分。注意不要写作(double) (sum /
count)，这样写运算结果将是 3.000000，仍然不能保留小数部分。


**************************************************

%c 输出一个单一的字符
%hd、%d、%ld 以十进制、有符号的形式输出 short、int、long 类型的整数
%hu、%u、%lu 以十进制、无符号的形式输出 short、int、long 类型的整数
%ho、%o、%lo 以八进制、不带前缀、无符号的形式输出 short、int、long 类型的整数
%#ho、%#o、%#lo 以八进制、带前缀、无符号的形式输出 short、int、long 类型的整数
%hx、%x、%lx
%hX、%X、%lX
以十六进制、不带前缀、无符号的形式输出 short、int、long 类型的整数。如果 x 小写，那
么输出的十六进制数字也小写；如果 X 大写，那么输出的十六进制数字也大写。
%#hx、%#x、%#lx
%#hX、%#X、%#lX
以十六进制、带前缀、无符号的形式输出 short、int、long 类型的整数。如果 x 小写，那么
输出的十六进制数字和前缀都小写；如果 X 大写，那么输出的十六进制数字和前缀都大写。
%f、%lf 以十进制的形式输出 float、double 类型的小数
%e、%le
%E、%lE
以指数的形式输出 float、double 类型的小数。如果 e 小写，那么输出结果中的 e 也小写；
如果 E 大写，那么输出结果中的 E 也大写。
%g、%lg
%G、%lG
以十进制和指数中较短的形式输出 float、double 类型的小数，并且小数部分的最后不会添加
多余的 0。如果 g 小写，那么当以指数形式输出时 e 也小写；如果 G 大写，那么当以指数
形式输出时 E 也大写。
%s 输出一个字符串



**************************************************

printf("%-9d %-9d %-9d %-9d\n", a1, a2, a3, a4);

%-9d 中，d 表示以十进制输出，9 表示最少占 9 个字符的宽度，宽度不足以空格补齐，-表示左对齐。综合起来，%-
9d 表示以十进制输出，左对齐，宽度最小为 9 个字符。

%[flag][width][.precision]type
width 表示最小输出宽度，也就是至少占用几个字符的位置；例如，%-9d 中 width 对应 9，表示输出结果最少
占用 9 个字符的宽度。
当输出结果的宽度不足 width 时，以空格补齐（如果没有指定对齐方式，默认会在左边补齐空格）；当输出结果的
宽度超过 width 时，width 不再起作用，按照数据本身的宽度来输出。


.precision 表示输出精度，也就是小数的位数。
 当小数部分的位数大于 precision 时，会按照四舍五入的原则丢掉多余的数字；
 当小数部分的位数小于 precision 时，会在后面补 0。

另外，.precision 也可以用于整数和字符串，但是功能却是相反的：
 用于整数时，.precision 表示最小输出宽度。与 width 不同的是，整数的宽度不足时会在左边补 0，而不是补
空格。
 用于字符串时，.precision 表示最大输出宽度，或者说截取字符串。当字符串的长度大于 precision 时，会截掉多余的字符；当字符串的长度小于 precision 时，.precision 就不再起作用。


int m = 192, n = -943;
float f = 84.342;
printf("m=%10d, m=%-10d\n", m, m); //演示 - 的用法
printf("m=%+d, n=%+d\n", m, n); //演示 + 的用法
printf("m=% d, n=% d\n", m, n); //演示空格的用法
printf("f=%.0f, f=%#.0f\n", f, f); //演示#的用法

对输出结果的说明：
 当以%10d 输出 m 时，是右对齐，所以在 192 前面补七个空格；当以%-10d 输出 m 时，是左对齐，所以在
192 后面补七个空格。
 m 是正数，以%+d 输出时要带上正号；n 是负数，以%+d 输出时要带上负号。
 m 是正数，以% d 输出时要在前面加空格；n 是负数，以% d 输出时要在前面加负号。
 %.0f 表示保留 0 位小数，也就是只输出整数部分，不输出小数部分。默认情况下，这种输出形式是不带小数点
的，但是如果有了#标志，那么就要在整数的后面“硬加上”一个小数点，以和纯整数区分开。
**************************************************

Windows 下，想让程序暂停可以使用 Windows.h 头文件中的 Sleep() 函数（S 要大写）

**************************************************

int a;会在内存中分配四个字节的空间，我们将第一个字节的地址称为变量 a 
的地址，也就是&a 的值。

注意：这里看到的地址都是假的，是虚拟地址，并不等于数据在物理内存中的地址。虚拟地址是现代计算机因内存
管理的需要才提出的概念



从本质上讲，我们从键盘输入的数据并没有直接交给 scanf()，而是放入了缓冲区中，直到我们按下回车键，scanf() 
才到缓冲区中读取数据。如果缓冲区中的数据符合 scanf() 的要求，那么就读取结束；如果不符合要求，那么就继
续等待用户输入，或者干脆读取失败。



**************************************************

只使用 if 语句
有的时候，我们需要在满足某种条件时进行一些操作，而不满足条件时就不进行任何操作，这个时候我们可以只使
用 if 语句。也就是说，if else 不必同时出现。

C 语言规定，else 总是与它前面最近的 if 配对


再看一个例子，统计从键盘输入的一行字符的个数：
while (getchar() != '\n') n++;


do{
 语句块
}while(表达式);


for (i = 0, j = 100; i <= 100; i++, j--) k = i + j;


**************************************************

但是，scanf() 和 gets() 是有区别的：
 scanf() 读取字符串时以空格为分隔，遇到空格就认为当前字符串结束了，所以无法读取含有空格的字符串。
 gets() 认为空格也是字符串的一部分，只有遇到回车键时才认为字符串输入结束，所以，不管输入了多少个空
格，只要不按下回车键，对 gets() 来说就是一个完整的字符串。换句话说，gets() 用来读取一整行字符串。


注意，scanf() 在读取数据时需要的是数据的地址，这一点是恒定不变的，所以对于 int、char、float 等类型的变量
都要在前边添加&以获取它们的地址。但是在本段代码中，我们只给出了字符串的名字，却没有在前边添加&，这
是为什么呢？因为字符串名字或者数组名字在使用的过程中一般都会转换为地址，所以再添加&就是多此一举，甚
至会导致错误了。


**************************************************

strcat() 将把 arrayName2 连接到 arrayName1 后面，并删除原来 arrayName1 最后的结束标志'\0'。这意味着，
arrayName1 必须足够长，要能够同时容纳 arrayName1 和 arrayName2，否则会越界（超出范围）。


strcpy() 会把 arrayName2 中的字符串拷贝到 arrayName1 中，字符串结束标志'\0'也一同拷贝。
另外，strcpy() 要求 arrayName1 要有足够的长度，否则不能全部装入所拷贝的字符串。


返回值：若 arrayName1 和 arrayName2 相同，则返回 0；若 arrayName1 大于 arrayName2，则返回大于 0 的
值；若 arrayName1 小于 arrayName2，则返回小于 0 的值.


所谓返回值，就是函数的执行结果。

