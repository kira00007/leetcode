#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode *temp = head;
        while(temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        const int N = nodes.size();
        int rm = N - n;
        if(rm == 0) return head->next;
        nodes[rm - 1]->next = nodes[rm]->next;
        return head;
    }
};