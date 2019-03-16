# 动态规划

> 题目来源：leetcode 初级算法 动态规划
>
> 编程环境：ubuntu vscode
>  
> 注意：可以将代码复制粘贴到Test/main.cpp文件中，并在该路径下make
>

* 简介

> 动态规划：
>
> 通过把原问题分解为相对简单的子问题的方式求解复杂问题的方法。
>
> 动态规划常常适用于有重叠子问题和最优子结构性质的问题，动态规划方法所耗时间往往远少于朴素解法。
>

* 个人总结的简单代码模板

```cpp
class Solution
{
  public:
    int template(vector<int> &nums)
    {
        //判断nums.size()等可能的特殊情况
        if(nums.size()==0)
            return 0;

        //根据输入数组定义相同大小的数组
        int *dp = new int[nums.size()];

        //根据题意对dp方程进行初始化
        dp[0] = nums[0];

        //根据题意循环dp方程
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }

        //返回最值dp
        return *max_element(dp,dp+nums.size());
    }
};
```