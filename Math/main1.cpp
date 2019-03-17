/*
 Fizz Buzz

写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
  vector<string> fizzBuzz(int n)
  {
    vector<string> vs;
    for (int i = 1; i <= n; i++)
    {
      string temp;
      if (i % 3 == 0 && i % 5 == 0)
      {
        temp = "FizzBuzz";
        vs.push_back(temp);
      }
      else if (i % 3 == 0)
      {
        temp = "Fizz";
        vs.push_back(temp);
      }
      else if (i % 5 == 0)
      {
        temp = "Buzz";
        vs.push_back(temp);
      }
      else
      {
        stringstream tmp;
        tmp << i;
        tmp >> temp;
        vs.push_back(temp);
      }
    }
    return vs;
  }
};

int main()
{
  //TODO 直接提交的，未调试
  return 0;
}
