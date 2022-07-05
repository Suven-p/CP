#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    vector<Node *> visited;
    set<Node *> parent[105];
    Node *cloneGraph(Node *node)
    {
        visited = vector<Node *>(105, nullptr);
        for (int i = 0; i < 105; i++)
        {
            parent[i].clear();
        }
        if (!node)
        {
            return node;
        }
        dfs(node);
        for (int i = 1; i < 105; i++)
        {
            if (visited[i] == nullptr)
            {
                break;
            }
            for (Node *p : parent[i])
            {
                visited[i]->neighbors.push_back(visited[p->val]);
            }
        }
        return visited[node->val];
    }

    void dfs(Node *current)
    {
        if (visited[current->val])
        {
            return;
        }
        Node *ans = new Node(current->val);
        visited[current->val] = ans;
        for (Node *neighbor : current->neighbors)
        {
            dfs(neighbor);
            parent[neighbor->val].insert(ans);
        }
    }
};

int main()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);
    Solution S;
    Node *ans = S.cloneGraph(n1);
}
