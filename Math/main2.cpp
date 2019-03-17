/*
计数质数

统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;

//一般解法1500000超时

// class Solution
// {
// public:
//   bool isP(int n)
//   {
//     int mysqrt = pow(n * 1.0, 0.5);
//     for (int i = 2; i <= mysqrt; i++)
//     {
//       if (n % i == 0)
//       {
//         return false;
//       }
//     }
//     return true;
//   }

//   int countPrimes(int n)
//   {
//     int res = 0;
//     for (int i = 2; i < n; i++)
//     {
//       if (isP(i))
//       {
//         res++;
//       }
//     }
//     return res;
//   }
// };


//筛选法
class Solution
{
public:
  bool isPrime[10000000];
  int countPrimes(int n)
  {
    int count = 0;
    for (int i = 2; i < n; i++)
    {
      if (isPrime[i] == false)
      {
        count++;
        for (int j = i + i; j < n; j += i)
        {
          isPrime[j] = true;
        }
      }
    }
    return count;
  }
};

int main()
{
  Solution s;
  s.countPrimes(1500000);
  return 0;
}
