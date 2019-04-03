# 数组和字符串

## 三数之和(main1.cpp)

1. `pair`
用`first`和`second`访问数据
定义在头文件`#include <utility>`中。

1. `two pointers`
双指针解法，
典型：先对序列排序，定义两个变量进行扫描
以降低复杂度

## 字谜分组(main3.cpp)

1. C++11时可以考虑unordered_map代替map
2. 用map来去重

```cpp
unordered_map<long long, bool> mpflag;
for (int i = 0; i < strs.size(); i++)
{
  long long llx = mp2[strs[i]];
  //mpflag不存在llx;
  if (mpflag[llx] == false)
  {
    mpflag[llx] = true;
  }
  else
  {
    continue;
  }

  //TODO :当前llx已经不重复
}
```