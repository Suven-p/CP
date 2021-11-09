#include <bits/stdc++.h>

#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vll vector<int>
#define ll long long
using namespace std;



const int N = 1e5 + 10, mod = 1e9 + 7, MOD = 998244353, INF = 1e18;


struct SegmentTree {
    /********************* CHANGE DEF AND MERGING STEP *************************/
    int n;
    vll t;
    vll lazy;
    ll def = 0;

    // l, r are the query points
    // lo, hi are the array ranges
    // in is the index in the segment tree
    // in == 0 refers to the root node
    void build(int n) {
        this -> n = n;
        t.assign(4 * n + 5, def);
        lazy.assign(4 * n + 5, 0);
    }

    void push(int v) {
        t[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int addend) {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), addend);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return -INF;
        if (l <= tl && tr <= r)
            return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    // query for arr[l..r]
    ll query(int left, int right) {
        return query(1, 1, n, left, right);
    }

    void update(int left, int right, ll val) {
        update(1, 1, n, left, right, val);
    }
};



struct game {
    int l, r, profit;
};

void solve() {

    int n, k; cin >> n >> k;
    std::vector<game> v(n);
    set<int>y_value;
    for (auto &x : v) {
        cin >> x.l >> x.r >> x.profit;
        y_value.insert(x.r);
    }

    SegmentTree seg;
    int curr_id = 1;
    map<int, int>y_mapped;

    seg.build(y_value.size());
    for (auto y : y_value) {
        seg.update(curr_id, curr_id, -k * y);
        y_mapped[y] = curr_id++;
    }

    int ans = 0;

    sort(all(v), [&](game a, game b)->bool{
        return a.l < b.l;
    });

    for (int i = n - 1; i >= 0; i--) {
        int x = v[i].l, y = v[i].r, profit = v[i].profit;
        seg.update(y_mapped[y], y_value.size(), profit);
        int query_id = y_mapped.lower_bound(x)->second;
        ans = max(ans, x * k + seg.query(query_id, y_value.size()));
    }

    cout << ans << "\n";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;

}