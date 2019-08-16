/*
 三数之和

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
// #include <iostream>
// #include <algorithm>
// #include <cstdio>
// #include <vector>
// #include <set>
// #include <string>
// #include <map>
// #include <utility>

// using namespace std;

// class Solution
// {
// public:
//   inline vector<vector<int>> twoSum(vector<int> nums2, int nowThree, int sum)
//   {
//     vector<vector<int>> res;
//     int l = 0, r = nums2.size() - 1;
//     while (l < r)
//     {
//       if (nums2[l] + nums2[r] < sum)
//       {
//         l++;
//       }
//       else if (nums2[l] + nums2[r] > sum)
//       {
//         r--;
//       }
//       else
//       {
//         vector<int> temp;
//         temp.push_back(nums2[l]);
//         temp.push_back(nums2[r]);
//         temp.push_back(nowThree);
//         res.push_back(temp);
//         l++;
//         r--;
//       }
//     }
//     return res;
//   }

//   vector<vector<int>> threeSum(vector<int> &nums)
//   {
//     vector<vector<int>> res;
//     if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
//     {
//       return res;
//     }

//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size() - 2; i++)
//     {
//       if (nums[i] != 0)
//       {
//         if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
//         {
//           nums.erase(nums.begin() + i);
//         }
//       }
//     }

//     for (int i = 0; i < nums.size() / 2; i++)
//     {
//       vector<int> temp = nums;
//       temp.erase(temp.begin() + i);
//       vector<vector<int> > vvt = twoSum(temp, nums[i], -nums[i]);
//       res.insert(res.end(), vvt.begin(), vvt.end());
//     }

//     //TODO:去重失败QAQ
//     // set<vector<int> > sv;
//     // for(auto var : res)
//     // {
//     //   sv.insert(var);
//     // }
//     // for(auto var : sv)
//     // {
//     //   res.push_back(var);
//     // }
//     //TODO

//     // vector<vector<int>> res2;
//     // vector<pair<int, int>> vp;
//     // for (auto var : res)
//     // {
//     //   pair<int, int> pa;
//     //   pa.first = max(max(var[0], var[1]), var[2]);
//     //   pa.second = min(min(var[0], var[1]), var[2]);
//     //   vp.push_back(pa);
//     // }
//     // for (auto var : res)
//     // {
//     //   for (auto var2 : vp)
//     //   {
//     //     if (var2.first == pa.first && var2.second == pa.second)
//     //     {
//     //       vp.push_back(pa);
//     //     }
//     //     else
//     //     {
//     //       vp.push_back(pa);
//     //       res2.push_back(var);
//     //     }
//     //   }
//     // }
//     return res;
//   }
// };

// int main()
// {
//   Solution s;
//   vector<int> x{-1, 0, 1, 0};
//   s.threeSum(x);
//   return 0;
// }


// 使用暴力法,不过超时了,291 / 313 个通过测试用例
// 原理是递归回朔,遍历出所有情况,然后剪枝

class Solution {
public:
    void generate(int i, int sum, int target, int count, vector<int> &nums,
                  vector<int> &location, set<vector<int>> &res) {
        if (i >= nums.size() || count >= 3) {
            return;
        }

        location.push_back(nums[i]);
        sum += nums[i];
        count++;
        if (sum == target && count == 3) {
            //sort(location.begin(), location.end());
            res.insert(location);
        }
        generate(i + 1, sum, target, count, nums, location, res);

        location.pop_back();
        sum -= nums[i];
        count--;
        generate(i + 1, sum, target, count, nums, location, res);
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> location;
        set<vector<int> > res;
        vector<vector<int> > result;
        generate(0, 0, 0, 0, nums, location, res);

        result.reserve(res.size());
        for (const auto &item:res) {
            result.push_back(item);
        }
        return result;
    }
};