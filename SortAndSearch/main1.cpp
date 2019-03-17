/*
合并两个有序数组

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]


*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//   /*输入:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// 输出: [1,2,2,3,5,6]*/
//   void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//   {
//     int p1 = 0, p2 = 0;
//     vector<int> res;
//     while (p1 < m && p2 < n)
//     {
//       if (nums1[p1] <= nums2[p2])
//       {
//         res.push_back(nums1[p1]);
//         p1++;
//       }
//       if (nums1[p1] > nums2[p2])
//       {
//         res.push_back(nums2[p2]);
//         p2++;
//       }
//     }
//     int temp1=p1;
//     int temp2=p2;
//     if (p1==m) {
//       while(temp2!=n){
//         res.push_back(nums2[temp2]);
//         temp2++;
//       }
//     }
//     if (p2==n) {
//       while(temp1!=m){
//         res.push_back(nums1[temp1]);
//         temp1++;
//       }
//     }
//     nums1 = res;

//   }
// };

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 || j >= 0)
    {
      if (j < 0 || i >= 0 && nums1[i] >= nums2[j])
        nums1[k--] = nums1[i--];
      else
        nums1[k--] = nums2[j--];
    }
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  s.merge(nums1, 3, nums2, 3);
  return 0;
}
