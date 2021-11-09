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

int N;
constexpr int maxN = 60;
long long caveGold[maxN];
long long maxUptoTerminal[maxN];
vector<int> tree[maxN];
void reset() {
    N = 0;
    REP(i, maxN) {
        caveGold[i] = 0;
        maxUptoTerminal[i] = 0;
        tree[i].clear();
    }
}

void dfs(int current, int parent) {
    long long currentNodeValue = caveGold[current];
    long long childMax = 0;
    for (auto child : tree[current]) {
        if (child == parent)
            continue;
        dfs(child, current);
        childMax = max(childMax, maxUptoTerminal[child]);
    }
    maxUptoTerminal[current] = currentNodeValue + childMax;
}

int main() {
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

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        reset();
        cin >> N;
        REP(i, N) { cin >> caveGold[i + 1]; }
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        // Apply dfs
        // goal obtainable at each cave
        // goldObtainable[i] = gold at ith cave + one of its descendants
        dfs(1, 0);
        // select a direct child of node 1
        // traverse to a terminal node
        // dig tunnel to a terminal node such that terminal node has a parent which is direct child
        // of 1 move up to direct child of 1
        long long ans;
        vector<long long> childrenOf1;
        for (auto child : tree[1]) {
            childrenOf1.push_back(maxUptoTerminal[child]);
        }
        sort(childrenOf1.rbegin(), childrenOf1.rend());
        switch (childrenOf1.size()) {
            case 0:
                ans = caveGold[1];
                break;
            case 1:
                ans = caveGold[1] + childrenOf1[0];
                break;
            default:
                ans = caveGold[1] + childrenOf1[0] + childrenOf1[1];
                break;
        }
        cout << "Case #" << numTest << ": " << ans << endl;
    }

    return 0;
}