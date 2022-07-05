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

constexpr int MAXN = 2e5 + 5;
vi tree[MAXN];
int level[MAXN], parent[MAXN];
int maxLevel = 0;
int N;

void reset()
{
    REP(i, MAXN)
    {
        tree[i].clear();
        level[i] = -1;
        parent[i] = -1;
    }
    level[0] = 0;
}

void dfs1(int node, int parent)
{
    level[node] = level[parent] + 1;
    maxLevel = max(maxLevel, level[node]);
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs1(child, node);
        }
    }
}

int main()
{
#ifdef TEST
    freopen("/media/lubuntu_nevus/Home_image/CP/input.in", "r", stdin);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stdout);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stderr);
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
            int temp;
            cin >> temp;
            tree[i + 2].push_back(temp);
            tree[temp].push(i + 2);
            parent[i + 2] = temp;
        }
        dfs(1, 0);
        ll ans = maxLevel;
        for (int i = 1; i <= N; i++)
        {
            ll numChildren = tree[i].size();
            if (i == 1)
            {
                numChildren--;
            }
        }
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
