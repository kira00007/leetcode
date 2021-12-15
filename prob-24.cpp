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
    ListNode* swapPairs(ListNode* head) {
		ListNode *temp = head;
		while(temp && temp->next) {
			int tmp_val = temp->next->val;
			temp->next->val = temp->val;
			temp->val = tmp_val;
			temp = temp->next->next;
		}
		return head;
    }
};

void print(ListNode *head) {
	ListNode *temp = head;
	while(temp) {
		std::cout << temp->val << ' ';
		temp = temp->next;
	}
	std::cout << '\n';
}

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	print(head);
	head = Solution().swapPairs(head);
	print(head);
	return 0;
}