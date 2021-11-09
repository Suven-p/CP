#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i = j; i < k; i += inc)
#define REP(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

// TODO
constexpr int MAXN = 20; //1e5 + 9;
int N, K;
vi tree[MAXN], leaves[MAXN], path[MAXN];
int depth[MAXN], ROOT;

void reset()
{
    for (int i = 0; i <= N; i++)
    {
        tree[i].clear();
        leaves[i].clear();
        path[i].clear();
        depth[i] = 0;
        ROOT = INT_MAX;
    }
}

void dfs1(int current, int parent)
{
    depth[current] = depth[parent] + 1;
    path[current] = vi(path[parent].begin(), path[parent].end());
    path[current].pb(current);
    if (tree[current].size() == 1 && tree[current][0] == parent)
    {
        leaves[current].pb(current);
    }
    for (auto c : tree[current])
    {
        if (c == parent)
        {
            continue;
        }
        dfs1(c, current);
        leaves[current].insert(leaves[current].end(), leaves[c].begin(), leaves[c].end());
    }
    auto depthComp = [](const auto &lhs, const auto &rhs)
    {
        return depth[lhs] > depth[rhs];
    };
    sort(leaves[current].begin(), leaves[current].end(), depthComp);
}

int deepestNode(int root)
{
    return leaves[root][0];
}

int solve()
{
    // all nodes are in straight line
    if (ROOT == INT_MAX)
    {
        return 2;
    }
    dfs1(ROOT, 0);
    // There is at least one branching so all leaf nodes must be
    // included
    if (K == N)
    {
        return leaves[ROOT].size();
    }

    int max1 = 0,
        max2 = 0;
    for (auto c : tree[ROOT])
    {
        if (depth[leaves[c][0]] >= depth[max1])
        {
            max2 = max1;
            max1 = leaves[c][0];
        }
        else if (depth[leaves[c][0]] > depth[max2])
        {
            max2 = leaves[c][0];
        }
    }

    set<int> processed;
    processed.insert(max1);
    processed.insert(max2);
    int currentK = depth[max1] + depth[max2] - 1; // root node is included twice

    auto depthComp = [](const auto &lhs, const auto &rhs)
    {
        return depth[lhs] > depth[rhs];
    };
    set<int, decltype(depthComp)> toProcess(depthComp);
    // keep track of which nodes have unprocessed leaves
    toProcess.insert(path[max1].begin(), path[max1].end());
    toProcess.insert(path[max2].begin(), path[max2].end());
    toProcess.erase(max1);
    toProcess.erase(max2);

    while (currentK < K)
    {
        // select ndoe which gives maximum increment
        int maxIncrement = 0, selectedNode = 0, selectedParent = 0;
        // if all leaves of a node has been processed remove it
        set<int> toRemove;
        for (auto c : toProcess)
        {
            bool hasUnprocessed = false;
            for (auto it = leaves[c].begin(); it != leaves[c].end(); it++)
            {
                if (processed.find(*it) == processed.end())
                {
                    hasUnprocessed = true;
                    int increment = depth[*it] - depth[c];
                    if (increment > maxIncrement)
                    {
                        maxIncrement = increment;
                        selectedNode = *it;
                        selectedParent = c;
                    }
                }
            }
            if (!hasUnprocessed)
                toRemove.insert(c);
        }
        processed.insert(selectedNode);
        for (auto it = ++(path[selectedNode].rbegin()); it != path[selectedNode].rend(); it++)
        {
            if (*it == selectedParent)
                break;
            toProcess.insert(*it);
        }
        toProcess.erase(toRemove.begin(), toRemove.end());
        currentK += maxIncrement;
    }
    return processed.size();
}

int main()
{
#ifdef TEST
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        cin >> N >> K;
        reset();
        REP(i, N - 1)
        {
            int u, v;
            cin >> u >> v;
            tree[u].pb(v);
            tree[v].pb(u);
            if (tree[u].size() > 1)
                ROOT = min(ROOT, u);
            if (tree[v].size() > 1)
                ROOT = min(ROOT, v);
        }
        auto ans = solve();
        // TODO
        cout << ans << "\n";
    }

#ifdef TEST
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}