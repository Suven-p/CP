// use F2.cpp

#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#else
#pragma GCC optimize "O3"
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

#ifdef TEST
constexpr int MAXN = 1e5 + 9;
#else
constexpr int MAXN = 1e5 + 9;
#endif

int N, K;
vi tree[MAXN];
int ROOT;

void reset()
{
    for (int i = 0; i <= N; i++)
    {
        tree[i].clear();
    }
    ROOT = INT_MAX;
}

vi dfs1(int current, int parent)
{
    if (tree[current].size() == 1 && current != ROOT)
    {
        return {1};
    }
    // if (tree[current].size() == 2 && current != ROOT)
    // {
    //     return {1};
    // }
    vi values;
    int maxi = 0, maxiIndex = -1;
    for (auto c : tree[current])
    {
        if (c == parent)
        {
            continue;
        }
        auto res = dfs1(c, current);
        if (res[0] > maxi)
        {
            maxi = res[0];
            maxiIndex = res.size();
        }
        values.insert(values.end(), res.begin(), res.end());
    }
    if (maxiIndex > 0)
    {
        iter_swap(values.begin(), values.begin() + maxiIndex);
    }
    values[0]++;
    return values;
}

void setRoot()
{
    int currentMax = 0, selected = 0;

    vector<bool> visited(N, false);
    pair<int, int> node = mp(1, 0);
    stack<pair<int, int>> stack;
    stack.push(node);
    while (!stack.empty())
    {

        node = stack.top();
        stack.pop();
        if (node.second > currentMax)
        {
            currentMax = node.second;
            selected = node.first;
        }
        visited[node.first] = true;

        for (auto c : tree[node.first])
        {
            if (!visited[c])
            {
                stack.push(mp(c, node.second + 1));
            }
        }
    }
    ROOT = selected;
}

int solve()
{
    if (K == 1)
    {
        return 1;
    }

    setRoot();
    int ans = 1;
    auto res = dfs1(ROOT, 0);
    for (auto c : res)
    {
        if (K <= 0)
            break;
        if (c == 1)
        {
            ans += K;
            break;
        }
        K -= c;
        ans++;
    }

    return max(ans, 2);
}

int main()
{
#ifdef TEST
    freopen("/media/nevus/data/CP/input2.in", "r", stdin);
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