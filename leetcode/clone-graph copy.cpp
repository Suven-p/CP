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

map<int, Node *> visited;
stack<pair<Node *, Node *>> toVisit;
vector<Node *> original;
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        visited = map<int, Node *>();
        toVisit = stack<pair<Node *, Node *>>();
        original = vector<Node *>(100, nullptr);
        if (!node)
        {
            return node;
        }
        toVisit.push(make_pair(node, nullptr));
        dfs();
        vector<bool> temp(100, false);
        dfs0(node, temp);
        // this->dfs2(node, temp);
        for (int i = 1; i < 5; i++)
        {
            cout << i << " " << original[i] << " " << visited[i] << endl;
            for (auto j : visited[i]->neighbors)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl
             << endl;
        return visited[node->val];
    }

    void dfs0(Node *node, vector<bool> &vis)
    {
        if (vis[node->val])
        {
            return;
        }
        vis[node->val] = true;
        original[node->val] = node;
        for (Node *ch : node->neighbors)
        {
            dfs0(ch, vis);
        }
    }

    void dfs2(Node *node, vector<bool> &vis)
    {
        if (vis[node->val])
        {
            return;
        }
        vis[node->val] = true;
        cout << node->val << endl;
        for (Node *ch : node->neighbors)
        {
            cout << ch->val << " ";
        }
        cout << endl;
        for (Node *ch : node->neighbors)
        {
            dfs2(ch, vis);
        }
    }

    void dfs()
    {
        while (!toVisit.empty())
        {
            auto top = toVisit.top();
            Node *current = top.first;
            Node *parent = top.second;
            toVisit.pop();
            if (!current)
            {
                throw "Something horrible went wrong";
            }
            if (visited.find(current->val) != visited.end())
            {
                parent->neighbors.push_back(visited[current->val]);
                continue;
            }
            Node *ans = new Node(current->val);
            if (parent != nullptr)
            {
                parent->neighbors.push_back(ans);
                // cout << "Adding " << ans->val << " to parent " << parent->val << endl;
            }
            visited[current->val] = ans;
            for (Node *neighbor : current->neighbors)
            {
                if (visited.find(neighbor->val) == visited.end())
                {
                    toVisit.push(make_pair(neighbor, ans));
                }
                else
                {
                    ans->neighbors.push_back(visited[neighbor->val]);
                }
            }
        }
    }
};

vector<bool> visited2;
void DFS(Node *node)
{
    if (visited2[node->val])
    {
        return;
    }
    visited2[node->val] = true;
    cout << node->val << " has neighbors: ";
    for (auto n : node->neighbors)
    {
        cout << n->val << " ";
    }
    cout << endl;
    for (auto n : node->neighbors)
    {
        DFS(n);
    }
}

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
    visited2 = vector<bool>(100, false);
    DFS(n1);
    cout << endl;
    Solution S;
    Node *ans = S.cloneGraph(n1);
    visited2 = vector<bool>(100, false);
    DFS(ans);
}
