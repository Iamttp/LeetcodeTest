/**
中序遍历二叉树

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>

using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution
// {
// public:
//   void inorderTree(TreeNode *root, vector<int> res)
//   {
//     if (root == NULL)
//     {
//       return;
//     }
//     inorderTree(root->left,res);
//     res.push_back(root->val);
//     inorderTree(root->right,res);
//   }

//   vector<int> inorderTraversal(TreeNode *root)
//   {
//     vector<int> res;
//     inorderTree(root, res);
//     return res;
//   }
// };

class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> sk;
    vector<int> res;
    TreeNode *now = root;
    while (now || sk.size())
    {
      if (now)
      {
        sk.push(now);
        now = now->left;
      }
      else
      {
        now = sk.top();
        res.push_back(now->val);
        sk.pop();
        now = now->right;
      }
    }
    return res;
  }
};
int main()
{
  Solution s;
  TreeNode *tn = new TreeNode(10);
  tn->left = new TreeNode(11);
  tn->right = new TreeNode(12);
  auto res = s.inorderTraversal(tn);
  for (auto x : res)
  {
    cout << x << endl;
  }
  return 0;
}
