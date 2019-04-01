# 树和图

二叉树用栈实现中序遍历

```cpp
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
```