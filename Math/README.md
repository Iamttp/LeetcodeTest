# 数学

## 数字字符串相互转换

* 数字转字符串

可以用:

```cpp
(c++11)string to_string (int val);
```

也可以用：

```cpp
#include <string>
#include <sstream>
int main()
{
  double a = 123.32;
  string res;
  stringstream ss;
  ss << a;
  ss >> res;
  return 0;
}
```

* 字符串转数字

```cpp
int main(){
    string a = "123.32";
    double res;
    stringstream ss;
    ss << a;
    ss >> res;
    return 0;
}
```

## 质数

判断质数可参考main2.cpp
用筛选法可以更快的判断

* [main2.cpp](/Math/main2.cpp)
