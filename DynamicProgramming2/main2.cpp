/*
不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

例如，上图是一个7 x 3 的网格。有多少可能的路径？

说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

示例 2:

输入: m = 7, n = 3
输出: 28

*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 机器人一定会走m+n-2步，
// 即从m+n-2中挑出m-1步向下走不就行了吗？即C（（m+n-2），（m-1））。
// class Solution
// {
// public:
//   long long C(long long m, long long n)
//   {
//     long long ans = 1;
//     for (long long i = 1; i <= m; i++)
//     {
//       ans = ans * (n - m + i) / i;
//     }
//     return ans;
//   }

//   int uniquePaths(int m, int n)
//   {
//     if (m == 0)
//       return 0;
//     if (n == 0)
//       return 0;
//     int res = C(min(m - 1, n - 1), m + n - 2);
//     return res;
//   }
// };

//dp方程
//太妙了
class Solution
{
public:
  int dp[101][101];
  int uniquePaths(int m, int n)
  {
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
      {
        //到原位置为1种走法
        if (i == 1 || j == 1)
          dp[i][j] = 1;
        else{
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
    return dp[m][n];
  }
};

int main()
{
  Solution s;
  cout << s.uniquePaths(3, 2);
  return 0;
}
