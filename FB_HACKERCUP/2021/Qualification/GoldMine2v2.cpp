// Attempt2: Using diameter for N-ary tree
// Doesn't work for test case 6

#include <bits/stdc++.h>
#include <type_traits>

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

int N, K;
constexpr int maxN = 15;
long long caveGold[maxN];
int parentNode[maxN];
vector<int> tree[maxN];

long long maxUptoTerminal[maxN];
int included1 = 0;
void reset() {
    N = 0;
    K = 0;
    REP(i, maxN) {
        caveGold[i] = 0;
        parentNode[i] = 0;
        tree[i].clear();

        maxUptoTerminal[i] = 0;
    }
    included1 = 0;
}

pair<ll, ll> dfs(int current, int parent) {
    parentNode[current] = parent;
    long long childMaxTerminal = 0;  // maximum value from current to one of terminal nodes
    long long childMaxDiameter = 0;  // maximum diameter including one of child nodes of current
    long long max1 = 0, max2 = 0;    // two highest values of maxTerminal
    long long childWithMaxDiameter;
    for (auto child : tree[current]) {
        if (child == parent)
            continue;
        auto res = dfs(child, current);
        if (res.first > childMaxDiameter) {
            childMaxDiameter = res.first;
            childWithMaxDiameter = child;
        }
        childMaxTerminal = max(childMaxTerminal, maxUptoTerminal[child]);
        if (maxUptoTerminal[child] > max1) {
            max2 = max1;
            max1 = maxUptoTerminal[child];
        } else if (maxUptoTerminal[child] > max2) {
            max2 = maxUptoTerminal[child];
        }
    }
    maxUptoTerminal[current] = caveGold[current] + childMaxTerminal;
    long long value1 = caveGold[current] + max1 + max2;
    long long value2 = childMaxDiameter;
    if (value1 > value2) {
        if (current == 1) {
            included1++;
        }
        return {value1, current};
    }
    return {value2, childWithMaxDiameter};
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
        cin >> N >> K;
        REP(i, N) { cin >> caveGold[i + 1]; }
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        if (K == 0) {
            cout << "Case #" << numTest << ": " << caveGold[0] << endl;
            continue;
        }

        long long ans = 0;
        REP(i, K - 1) {
            auto res = dfs(1, 0);
            ans += res.first;
            auto maxNode = res.second;
            auto parent = parentNode[maxNode];
            (void)remove(tree[parent].begin(), tree[parent].end(), maxNode);
        }
        ans -= (included1 * caveGold[1]);
        dfs(1, 0);
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