/*
岛屿的个数

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1

示例 2:

输入:
11000
11000
00100
00011

输出: 3

*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;

//BFS 38 / 47 个通过测试用例 超时QAQ

// class Solution
// {
// public:
//   inline bool isOk(vector<vector<char>> &grid, int i, int j)
//   {
//     if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
//       return false;
//     if (grid[i][j] == '0')
//       return false;
//     if (grid[i][j] == -1)
//       return false;
//     return true;
//   }

//   void BFS(vector<vector<char>> &grid, int i, int j)
//   {
//     //广搜
//     queue<pair<int, int>> qc;
//     pair<int, int> pr(i, j);
//     qc.push(pr);
//     while (!qc.empty())
//     {
//       pr = qc.front();
//       grid[pr.first][pr.second] = -1;
//       qc.pop();

//       i = pr.first;
//       j = pr.second;

//       if (isOk(grid, i + 1, j))
//         qc.push(make_pair(i + 1, j));
//       if (isOk(grid, i - 1, j))
//         qc.push(make_pair(i - 1, j));
//       if (isOk(grid, i, j + 1))
//         qc.push(make_pair(i, j + 1));
//       if (isOk(grid, i, j - 1))
//         qc.push(make_pair(i, j - 1));
//     }
//   }
//   int numIslands(vector<vector<char>> &grid)
//   {
//     int m = grid.size();
//     if (m == 0)
//       return 0;
//     int n = grid[0].size();
//     if (n == 0)
//       return 0;
//     int res = 0;
//     //-1表示已经计算
//     for (int i = 0; i < m; i++)
//       for (int j = 0; j < n; j++)
//         if (isOk(grid, i, j))
//         {
//           BFS(grid, i, j);
//           res++;
//         }
//     return res;
//   }
// };

//DFS 通过
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

int main()
{
  vector<char> vc1{'1', '1', '1'};
  vector<char> vc2{'0', '1', '0'};
  vector<char> vc3{'0', '1', '0'};

  vector<vector<char>> vvc{vc1, vc2, vc3};
  Solution s;
  cout << s.numIslands(vvc);
  return 0;
}
