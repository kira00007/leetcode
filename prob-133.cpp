#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	vector<Node*> neighbors;
	Node()
		: val(0), neighbors(vector<Node*>())
	{

	}
	Node(int _val)
		: val(_val), neighbors(vector<Node*>())
	{

	}
	Node(int _val, const vector<Node*> &_neighbors)
		: val(_val), neighbors(_neighbors)
	{

	}
};

class Solution {
public:
    map<int, Node*> mp;
    bool vis[101];
    void dfs(Node *node) {
        if(vis[node->val]) return;
        vis[node->val] = true;
        mp[node->val] = new Node(node->val);
        for(auto it : node->neighbors) {
            dfs(it);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        memset(vis, 0, sizeof(vis));
        mp.clear();
        dfs(node);
        // return nullptr;
        Node *newGraph = mp[node->val];
        queue<Node*> bfs;
        bfs.push(node);
        bool another_vis[101];
        memset(another_vis, 0, sizeof(another_vis));
        while(!bfs.empty()) {
            Node *temp1 = bfs.front();
            Node *temp2 = mp[temp1->val];
            bfs.pop();
            if(another_vis[temp1->val]) continue;
            else another_vis[temp1->val] = true;
            for(auto it : temp1->neighbors) {
                bfs.push(it);
                temp2->neighbors.push_back(mp[it->val]);
            }
        }
        return newGraph;
    }
};