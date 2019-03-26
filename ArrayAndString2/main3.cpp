/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,

// 超时了QAQ

// class Solution {
// public:
// 	vector<vector<string>> groupAnagrams(vector<string>& strs) {

// 		unordered_map<char, long long> mp;
// 		int p[] = { 3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,
// 			71,73,79,83,89,97,101,103,107,109,113,127 };
// 		for (int i = 0; i < 27; i++)
// 		{
// 			mp['a' + i] = p[i];
// 		}

// 		unordered_map<string, long long> mp2;
// 		for (int i = 0; i < strs.size(); i++)
// 		{
// 			string x = strs[i];
// 			long long sum = 1;
// 			for (auto var : x)
// 			{
// 				sum *= mp[var];
// 				if (sum> 100000007)
// 				{
// 					sum %= 100000007;
// 				}
// 			}
// 			mp2[x] = sum;
// 		}

// 		vector<vector<string>> vvsRes;
// 		unordered_map<long long, bool> mpflag;

// 		for (int i = 0; i < strs.size(); i++)
// 		{
// 			long long llx = mp2[strs[i]];
// 			if (mpflag[llx] == false)
// 			{
// 				mpflag[llx] = true;
// 			}
// 			else
// 			{
// 				continue;
// 			}

// 			vector<string> vsRes;
// 			for (int j = 0; j < strs.size(); j++)
// 			{
// 				if (llx == mp2[strs[j]])
// 					vsRes.push_back(strs[j]);
// 			}
// 			vvsRes.push_back(vsRes);
// 		}
// 		return vvsRes;
// 	}
// };


//参考大神的
class Solution {
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs) {
		vector<vector<string> >re;
		int index = 0;  //返回结果的字母异位词索引（表示该字母异位词出现的顺序号）
		unordered_map<string, int> myunordered_map;   //用于保存排序后的单词及其字母异位词索引      
		string str;
		for (int i = 0; i < strs.size(); ++i) {
			str = strs[i];
			sort(str.begin(), str.end());
			if (myunordered_map.find(str) == myunordered_map.end()) {
				myunordered_map[str] = index;    //第index个出现的异位词
				++index;
				re.push_back(vector<string>{});  //返回结果多加一行
			}
			re[myunordered_map[str]].push_back(strs[i]);
		}
		return re;
	}
};
int main()
{
	Solution s;
	string x1 = "abc";
	string x2 = "acb";
	string x3 = "abcd";
	string x4 = "abdc";
	string x5 = "adbc";
	vector<string> vs{x1,x2,x3,x4,x5};
	s.groupAnagrams(vs);
	system("pause");
	return 0;
}
