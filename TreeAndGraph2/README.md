# 树和图

## 二叉树用栈实现中序遍历

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

## DFS模板
  
```cpp

class Solution
{
public:
  bool isOk(vector<vector<char>> &grid, int i, int j)
  {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
      return false;
    if (grid[i][j] == '0')
      return false;
    if (grid[i][j] == -1)
      return false;
    return true;
  }

  void findOne(vector<vector<char>> &grid, int i, int j)
  {
    if (isOk(grid, i, j))
    {
      grid[i][j] = -1;

      findOne(grid, i + 1, j);
      findOne(grid, i - 1, j);
      findOne(grid, i, j + 1);
      findOne(grid, i, j - 1);
    }
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int m = grid.size();
    if (m == 0)
      return 0;
    int n = grid[0].size();
    if (n == 0)
      return 0;
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (isOk(grid, i, j))
        {
          findOne(grid, i, j);
          res++;
        }
    return res;
  }
};

```

## BFS模板

```cpp

class Solution
{
public:
  inline bool isOk(vector<vector<char>> &grid, int i, int j)
  {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
      return false;
    if (grid[i][j] == '0')
      return false;
    if (grid[i][j] == -1)
      return false;
    return true;
  }

  void BFS(vector<vector<char>> &grid, int i, int j)
  {
    //广搜
    queue<pair<int, int>> qc;
    pair<int, int> pr(i, j);
    qc.push(pr);
    while (!qc.empty())
    {
      pr = qc.front();
      grid[pr.first][pr.second] = -1;
      qc.pop();

      i = pr.first;
      j = pr.second;

      if (isOk(grid, i + 1, j))
        qc.push(make_pair(i + 1, j));
      if (isOk(grid, i - 1, j))
        qc.push(make_pair(i - 1, j));
      if (isOk(grid, i, j + 1))
        qc.push(make_pair(i, j + 1));
      if (isOk(grid, i, j - 1))
        qc.push(make_pair(i, j - 1));
    }
  }
  int numIslands(vector<vector<char>> &grid)
  {
    int m = grid.size();
    if (m == 0)
      return 0;
    int n = grid[0].size();
    if (n == 0)
      return 0;
    int res = 0;
    //-1表示已经计算
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (isOk(grid, i, j))
        {
          BFS(grid, i, j);
          res++;
        }
    return res;
  }
};

```