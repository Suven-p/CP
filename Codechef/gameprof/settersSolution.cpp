#include<bits/stdc++.h>
using namespace std;

const long long INF = 2e18;

const int maxN = 1e5 + 69;

struct items {
    int x, y, v;
    bool operator < (const items& oth) const {
        return y < oth.y;
    }
};

struct SegmentTree {
    int n;
    vector<long long> st;
    vector<long long> lazy;

    SegmentTree(int n) : n(n), st(n * 4, -INF), lazy(n * 4) {}
    SegmentTree() {}

    void change(long long v, int id) {
        st[id] += v;
        lazy[id] += v;
    }

    void push(int id) {
        change(lazy[id], id * 2);
        change(lazy[id], id * 2 + 1);

        lazy[id] = 0;
    }

    // (L, R represent query params) id represents position
    void update(int L, int R, long long v, int id, int l, int r) {
        // no overlap
        if (R < l || r < L) return;

        // complete overlap
        if (L <= l && r <= R) {
            change(v, id);
            return;
        }

        // partial overlap
        push(id);

        int mid = (l + r) / 2;
        update(L, R, v, id * 2, l, mid);
        update(L, R, v, id * 2 + 1, mid + 1, r);

        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    void update(int L, int R, long long v) {
        update(L, R, v, 1, 0, n);
    }
};

int n, k;
int m;
items a[maxN];
vector<int> vals;
SegmentTree st;

int main() {
    #define filename "BAI6"
              //     freopen("0.in.txt","r",stdin);
//  std::ofstream outfile("output5.009", std::ios_base::binary | std::ios_base::out );
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].v;

        vals.push_back(a[i].x);
        vals.push_back(a[i].y);
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    m = vals.size();

    sort(a + 1, a + 1 + n);

    st = SegmentTree(m);

    long long ans = 0;
    int cur = 0;

    for (int r = 0; r < m; r++) {
        st.update(r, r, INF + 1ll * k * vals[r]);

        while (cur + 1 <= n && a[cur + 1].y <= vals[r]) {
            cur++;

            if (a[cur].v > 0) {
                int id = lower_bound(vals.begin(), vals.end(), a[cur].x) - vals.begin();
                st.update(0, id, a[cur].v);
            }
        }

        ans = max(ans, st.st[1] - 1ll * k * vals[r]);
    }

    cout << ans<<"\n";
}