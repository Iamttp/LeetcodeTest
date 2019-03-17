# 数学

* 数字转字符串

可以用:

```cpp
string to_string (int val);
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

