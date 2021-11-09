#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int selected;

struct node
{
    vector<int> adjacent;
    node() :  depth(0), special(0), closest(0) {}
    int depth;
    int special;
    int closest;
};

const int N = 3e5+45;
node tree[N];
bool special[N];


void populate(int current, int parent)
{
    tree[current].depth = tree[parent].depth + 1;

    int temp = 0;
    bool is_special = special[current];
    if (is_special) {
        tree[current].special = current;
    }
    for (auto child: tree[current].adjacent)
    {
        if (child == parent)
        {
            continue;
        }
        populate(child, current);
        if (tree[child].special) {
            temp = tree[child].special;
        }
    }
    if (!is_special && temp){
        tree[current].special = temp;
    }
}

void populate2(int current, int parent) {
    if (tree[current].special) {
        tree[current].closest = current;
    }
    else {
        tree[current].closest = tree[parent].closest;
    }
    for (auto c: tree[current].adjacent) {
        if (c != parent) {
            populate2(c, current);
        }
    }
}

void solve(int num_nodes) {
    populate(selected, 0);
    populate2(selected, 0);
    for (int i=1; i <= num_nodes; i++) {
        cout << (2 * tree[tree[i].closest].depth) - tree[i].depth << ' ';
    }
    cout << endl;
    for (int i=1; i <= num_nodes; i++) {
        cout << tree[tree[i].closest].special << ' ';
    }
    cout << endl;
}

int main()
{
    // freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    // freopen("/media/psuv/Data/CP/output.out", "w", stdout);
#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int num_nodes, num_special;
        cin >> num_nodes >> num_special >> selected;

        for (int i=1; i <= num_nodes; i++) {
            tree[i] = node();
        }
        tree[0].depth = -1;
        memset(special, 0, sizeof(special));

        for (int i = 0; i < num_special; i++)
        {
            int node;
            cin >> node;
            special[node] = true;
        }

        for (int i = 1; i <= num_nodes - 1; i++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            tree[n1].adjacent.push_back(n2);
            tree[n2].adjacent.push_back(n1);
        }

        solve(num_nodes);

    }

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
    cout << endl << endl;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}