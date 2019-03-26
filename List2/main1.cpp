/*
两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    //头结点
    ListNode *res = new ListNode(0);
    ListNode *temp1 = l1,*temp2 = l2,*tempr = res;
    while(temp1&&temp2){
      ListNode *tempp = new ListNode(temp1->val + temp2->val);
      tempr->next = tempp;
      temp1 = temp1->next;
      temp2 = temp2->next;
      tempr = tempr->next;
    }
    
    if (temp2) {
      tempr->next = temp2;
    }
    if (temp1) {
      tempr->next = temp1;
    }
    

    tempr = res;
    while (tempr)
    {
      if(tempr->val>=10){
        tempr->val -= 10;
        if(tempr->next)
          tempr->next->val++;
        else
          tempr->next = new ListNode(1);
      }       
      tempr = tempr->next;
    }
    return res->next;
  }
};

int main()
{
  // ListNode *l1 = new ListNode(2);
  // ListNode *l2 = new ListNode(4);
  // ListNode *l3 = new ListNode(3);
  // ListNode *r1 = new ListNode(5);
  // ListNode *r2 = new ListNode(6);
  // ListNode *r3 = new ListNode(4);
  // l1->next = l2;
  // l2->next = l3;
  // r1->next = r2;
  // r2->next = r3;
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(8);
  l1->next = l2;
  ListNode *r1 = new ListNode(0);
  Solution s;
  s.addTwoNumbers(l1, r1);
  return 0;
}
