#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head)
{
  int num = head -> val;
  cout << num << endl;
  return head;
}

int main(){
  ListNode* head = new ListNode(0);
  ListNode dummy(0);
  head -> val = 2;
  dummy.next = head;
  vector<int> hey;
  hey.push_back(1);
  hey.push_back(2);
  hey.push_back(3);
  int i = hey[0];
  cout << "i = " << i << endl;
  sortList(dummy.next);
  return 0;
}