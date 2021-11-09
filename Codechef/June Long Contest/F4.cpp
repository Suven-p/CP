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

typedef vi dummy;
// typedef multiset<int, std::greater<int>> dummy;
dummy dfs1(int current, int parent)
{
    if (tree[current].size() == 1 && current != ROOT)
    {
        dummy res = {1};
        return res;
    }
    // multiset<int, std::greater<int>> values2;
    vi values;
    int currentMax = -1e9, maxIndex = -1;
    for (auto c : tree[current])
    {
        if (c == parent)
        {
            continue;
        }
        auto res = dfs1(c, current);
        if (res[0] > currentMax)
        {
            currentMax = res[0];
            maxIndex = values.size();
        }
        values.insert(values.end(), res.begin(), res.end());
        // values2.insert(res.begin(), res.end());
    }
    swap(values[0], values[maxIndex]);
    values[0]++;
    // auto it = values2.begin();
    // auto val = *it;
    // values2.erase(val);
    // values2.insert(it, val + 1);
    return values;
}

int maxLength = 0, maxNode = 0, maxNodeParent = 0;
vi memo;
vi dfs0(int current, int parent)
{
    if (tree[current].size() == 1 && current != ROOT)
    {
        return {1};
    }
    vi values;
    int max1 = 0, max2 = 0;
    for (auto c : tree[current])
    {
        if (c == parent)
        {
            continue;
        }
        auto res = dfs0(c, current);
        values.insert(values.end(), res.begin(), res.end());
        if (res[0] > max1)
        {
            max2 = max1;
            max1 = res[0];
        }
        else if (res[0] > max2)
        {
            max2 = res[0];
        }
    }
    sort(values.rbegin(), values.rend());
    values[0]++;
    if (max1 > 0 && max2 > 0)
    {
        if (max1 + max2 + 1 >= maxLength)
        {
            maxLength = max1 + max2 + 1;
            maxNode = current;
            maxNodeParent = parent;
            memo = values;
        }
    }
    return values;
}

vi dfs01(int current, int parent)
{
    if (parent == 0)
    {
        return {};
    }
    if (tree[current].size() == 1 && current != ROOT)
    {
        return {1};
    }
    vi values;
    for (auto c : tree[current])
    {
        if (c == parent)
        {
            continue;
        }
        auto res = dfs01(c, current);
        values.insert(values.end(), res.begin(), res.end());
    }
    sort(values.rbegin(), values.rend());
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

    int ans = 1;

    ROOT = 1;
    // Iterate from 1 using dfs and keep track of maximum path
    // that can be formed over the tree
    vi res = dfs0(1, 0);
    // When iterating over nodes if there is one leaf node
    // under the root then root and leaf node can be selected
    // to make subree of size N
    // edge case of 1 node is handled above
    if (res.size() == 1)
        return 2;
    // res might not have optimal heights but it includes all leaves
    // return all leaf nodes including root node if it is one
    if (K == N)
    {
        // root node has only one child so its a leaf node
        if (tree[1].size() == 1)
            return res.size() + 1;
        else
            return res.size();
    }

    // If res[0] >= maxLength then root node is an endpoint to
    // one of the nodes and hence all the depths are valid
    // Else: select the node in longest path that is nearest to 1
    // Use the edge between selected node and its parent to separate
    // the two nodes; then calculate the values for only the second
    // tree
    if (res[0] < maxLength)
    {
        res = memo;
        res[1] += res[0];
        res[0] = 0;
        ROOT = maxNodeParent;
        // If 1 lies in in maximum path no adjusting is necessary
        // initial 0 in res array is disregarded by if-check below
        if (maxNode != 1)
        {
            auto res1 = dfs01(maxNodeParent, maxNode);
            res.insert(res.end(), res1.begin(), res1.end());
            sort(res.rbegin(), res.rend());
        }
    }

    for (auto c : res)
    {
        if (K <= 0)
            break;
        if (c == 0)
            continue;
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