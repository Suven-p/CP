#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int num_query = 0;
map<pair<int, int>, int> store;
int make_query(int l, int r) {
    assert(num_query<=20);
    if (store.find(mp(l, r)) != store.end()) {
        return store[mp(l, r)];
    }
    cout << "? " << l << " " << r << endl;
    int ans;
    cin >> ans;
    if (ans == -1) {
        exit(0);
    }
    store[mp(l, r)] = ans;
    return ans;
}

int solve(int start, int end, int k) {
    int full_range = make_query(start, end);
    int mid = start + (end-start)/2;
    int first_range = make_query(start, mid);
    store[mp(mid+1, end)] = full_range - first_range;

    // Number of 0 in first half
    int num_0 = mid-start+1-first_range;
    // If range consists of all 0's
    if (num_0 == (mid-start+1) && k <= num_0) {
        return end;
    }
    if (num_0 >= k) {
        return solve(start, mid, k);
    }
    else {
        return solve(mid+1, end, k-num_0);
    }
}

int main() {
#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    for(int i=0; i < t; i++) {
        int k;
        cin >> k;
        int ans = solve(1, n, k);
        cout << "! " << ans << endl;
    }


#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}