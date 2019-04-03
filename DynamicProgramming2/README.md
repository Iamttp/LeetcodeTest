# 动态规划

## 组合数

```cpp
long long C(long long m, long long n)
{
  long long ans = 1;
  for (long long i = 1; i <= m; i++)
  {
    ans = ans * (n - m + i) / i;
  }
  return ans;
}
```

## 动态规划dp方程

```cpp
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
```