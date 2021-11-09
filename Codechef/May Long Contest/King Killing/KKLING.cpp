#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i = j; i < k; i += inc)
#define REP(i, n) for (int i = 0; i < n; i++)
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

const int N_MAX = 2e5 + 7;
int N;
vi tree[N_MAX], paths[N_MAX];
set<int> leaves[N_MAX], all_leaves;
int depth[N_MAX], answers[N_MAX], leaf_pos[N_MAX], parent[N_MAX];

void reset()
{
    REP(i, N_MAX)
    {
        tree[i].clear();
        leaves[i].clear();
        paths[i].clear()
    }
    all_leaves.clear();
    memset(depth, 0, sizeof(depth));
}

void populate(int current, int par)
{
    if (current == 1)
    {
        depth[current] = 0;
        paths[current].push_back(current);
    }
    else
    {
        depth[current] = depth[par] + 1;
        paths[current] = paths[par];
        paths[current].push_back(current);
    }
    parent[current] = par;

    if (tree[current].size() == 1 && current != 1)
    {
        leaves[current].insert(current);
        all_leaves.insert(current);
        leaf_pos[current] = current;
    }
    for (auto c : tree[current])
    {
        if (c == par)
            continue;
        populate(c, current);
        leaves[current].insert(leaves[c].begin(), leaves[c].end());
    }
}

int computeLca(int a, int b)
{
    int dep1 = depth[a], dep2 = depth[b];
    while (dep1 > dep2)
    {
        a = parent[a];
        dep1--;
    }
    while (dep2 > dep1)
    {
        b = parent[b];
        dep2--;
    }
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

void dfs(vi childrens)
{
    for (auto current : childrens)
    {
        auto subLeaves = leaves[current];
        if (!subLeaves.size())
        {
            continue;
        }
        map<int, vi> depthMap, deviation;
        for (auto c : subLeaves)
        {
            depthMap[depth[c]].push_back(c);
        }
        if (depthMap.size() == 1)
        {
            auto elem = (depthMap.begin())->second;
            for (auto c : elem)
            {
                answers[c] = depth[c];
            }
        }
        auto maxDep = ((depthMap.rbegin())->second)[0];
        for (auto c : subLeaves)
        {
            auto lc = computeLca(c, maxDep);
            auto len = paths[c].size() - paths[lc].size();
            deviation[len].push_back(c);
        }
    }
}

auto solve()
{
    vector<int> assasins;
    int numDays;
    populate(1, 0);
    dfs(tree[1]);

    return mp(assasins, numDays);
}

int main()
{
#ifdef TEST
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        reset();
        cin >> N;
        REP(i, N)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        auto ans = solve();
        auto assasins = ans.first;
        auto numDays = ans.second;
        cout << assasins.size() << "\n"
             << numDays << "\n";
        for (auto c : assasins)
        {
            cout << c << " ";
        }
        cout << endl;
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