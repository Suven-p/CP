#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)
#define REP(i, n) for(int i=0; i < n; i++)
#ifdef TEST
    #define debug(x...) cerr << #x << x << endl;
#else
    #define debug(x...)
#endif

const int N_MAX = (int)3e5 + 7;
const ll mod = 1e9 + 7;
int N;
ll X;
vector<ll> tree[N_MAX];
int num_children[N_MAX];
ll value[N_MAX];
ll sum_value[N_MAX];
ll max_value[N_MAX];

void reset() {
    for(auto &v:tree) {
        v.clear();
    }
    memset(num_children, 0, sizeof(num_children));
    memset(value, 0, sizeof(value));
    memset(sum_value, 0, sizeof(value));
    memset(max_value, 0, sizeof(max_value));
}

void populate(ll current, ll parent) {
    // For leaf node
    sum_value[current] = 1;
    if (current != 1 && tree[current].size() == 1) {
        max_value[current] = 1;
        return;
    }
    for (auto c: tree[current]) {
        if (c != parent) {
            populate(c, current);
        }
    }
    sort(tree[current].begin(), tree[current].end(), [](ll a, ll b) {
        return sum_value[a] > sum_value[b];
        if (value[a] > value[b]) return true;
        else if (value[a] == value[b]) return (sum_value[a] > sum_value[b]);
        else return false;
    });
    // Count is used to keep track of childrens accounted for
    // i is not used because i can include parents
    // i cannot be started from 1  because i should start from 0 for
    // root node
    ll count = 0;
    for (ll i=0; i < tree[current].size(); i++) {
        auto temp = tree[current][i];
        if (temp == parent) {
            continue;
        }
        max_value[current] = max(max_value[current], (i+1) * max_value[temp]);
        sum_value[current] += (count+1) * sum_value[temp];
        count++;
    }
}

void dfs(ll current, ll parent, ll &ans) {
    for (ll i=0; i < tree[current].size(); i++) {
        auto child = tree[current][i];
        if (child == parent) {
            continue;
        }
        auto current_val = value[current];
        value[child] = (i+1) * current_val;
        ans += value[child];
        ans %= mod;
        dfs(child, current, ans);
    }
}

ll solve() {
    populate(1, 0);
    sum_value[1] %= mod;
    X %= mod;
    return (sum_value[1] * X) % mod;
    value[1] = X;
    ll ans = X;
    dfs(1, 0, ans);
    return ans;
}

int main() {
#ifdef TEST
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        reset();
        cin >> N >> X;
        REP(i, N-1) {
            ll u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        auto ans = solve();
        cout << ans << endl;
    }

#ifdef TEST
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}