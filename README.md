# c

Difference between i++ and ++i

++i will increment the value of i, and then return the incremented value.

 i = 1;
 j = ++i;
 (i is 2, j is 2)
 
i++ will increment the value of i, but return the original value that i held before being incremented.

 i = 1;
 j = i++;
 (i is 2, j is 1)








区分不同进制数字的一个简单办法就是，在输出时带上特定的前缀。在格式控制符中加上#即可输出前缀，例
如 %#x、%#o、%#lX、%#ho 等
