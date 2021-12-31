#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insert(ListNode *head, int val) {
	if(!head) {
		head = new ListNode(val);
		return head;
	}
	ListNode *temp = head;
	while(temp->next) temp = temp->next;
	temp->next = new ListNode(val);
	return head;
}

void print(ListNode *head) {
	while(head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << '\n';
}

ListNode* init() {
	ListNode *head = nullptr;
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	return head;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
		if(!head || (left == right)) return head;
		--left, --right;
		ListNode *temp = head;
		ListNode *bli = 0;
		for(int i = 0; i < left; i++) bli = temp, temp = temp->next;
		ListNode *li = temp;
		ListNode *prev = temp, *nxt = temp->next;
		int cnt = 0;
		while(nxt && cnt != (right-left)) {
			temp = nxt;
			nxt = nxt->next;
			temp->next = prev;
			prev = temp;
			cnt++;
		}
		ListNode *ri = temp;
		li->next = nxt;
		if(bli) bli->next = ri;
		if(!left) head = ri;
		return head;
    }
};



int main() {
	ListNode *head = init();
	print(Solution().reverseBetween(head, 1, 5));
	return 0;
}