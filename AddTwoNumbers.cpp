#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Addition = l1;
        ListNode* head = Addition;
        int sum, carry = 0;
        while(l1 || l2 || Addition)
        {
            sum = carry + l1 -> val + l2 -> val;
            Addition -> val = sum % 10;
            if(sum >= 10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            Addition = Addition -> next;
        }
        Addition -> next = NULL;
        return head;
    }
};

int main()
{
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    l1 = [2,4,3];
    l2 = [5,6,4];
    Solution::addTwoNumbers(l1,l2);
    return 0;
}
