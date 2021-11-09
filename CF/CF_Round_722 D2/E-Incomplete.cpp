// Incomplete

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
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

const int NMAX = 3e5 + 7;
int N;
vi tree1[NMAX], tree2[NMAX];
set<int> graph[NMAX];
set<int> paths1[NMAX], paths2[NMAX];
ll max_clique;

void reset()
{
    REP(i, NMAX)
    {
        tree1[i].clear();
        tree2[i].clear();
        graph[i].clear();
        paths1[i].clear();
        paths2[i].clear();
    }
}

void dfs1(int current, int parent, int tree)
{
    if (tree == 1)
    {
        paths1[current] = paths1[parent];
        paths1[current].insert(current);
        for (auto c : tree1[current])
        {
            if (c != parent)
            {
                dfs1(c, current, tree);
            }
        }
    }
    else if (tree = 2)
    {
        paths2[current] = paths2[parent];
        paths2[current].insert(current);
        for (auto c : tree2[current])
        {
            if (c != parent)
            {
                dfs1(c, current, tree);
            }
        }
    }
}
int solve()
{
    dfs1(1, 0, 2);
    dfs1(1, 0, 1);
    for (int i = 2; i <= N; i++)
    {
        for (auto c : paths1[i])
        {
            if (c == i)
                continue;
            if (paths2[i].find(c) == paths2[i].end())
            {
                graph[i].insert(c);
                graph[c].insert(i);
            }
        }
    }
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
        REP(i, N - 1)
        {
            int u;
            cin >> u;
            tree1[u].push_back(i + 1);
            tree1[i + 1].push_back(u);
        }
        REP(i, N - 1)
        {
            int u;
            cin >> u;
            tree2[u].push_back(i + 1);
            tree2[i + 1].push_back(u);
        }
        auto ans = solve();
        cout << ans << endl;
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