/*
爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

*/


#include<cstdio>

class Solution {
public:
//原始方法：超时
    // int res = 0;
    // inline void fun(int n,int tempx)
    // {
    //     if(tempx > n)
    //         return;
    //     if(tempx==n)
    //     {
    //         res++;
    //         return;
    //     }
    //     fun(n,tempx+1);
    //     fun(n,tempx+2);  
    // }

    // inline int climbStairs(int n) {
    //     int tempx = 0;
    //     fun(n,tempx+1);
    //     fun(n,tempx+2);   
    //     return res;     
    // }

};

//改进方法：斐波拉契数列，非递归形式
class Solution1 {
public:
    int climbStairs(int n) {
        
        int *sum = new int [n + 1];
        sum[0] = 0;
        sum[1] = 1;
        sum[2] = 2;
        
        for(int i = 3; i <= n; i++)
            sum[i] = sum[i - 1] + sum[i - 2];
        
        return sum[n];
        
    }
};
int main()
{
    int x;
    Solution1 s;
    printf("%d",s.climbStairs(44));
    return 0;
}