#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

void solve(int sz) {
    if (sz == 1) {
        cout << 1 << endl;
        return;
    }
    if (sz == 2) {
        cout << -1 << endl;
        return;
    }
    if (sz == 3) {
        cout << "2 9 7\n4 6 3\n1 8 5" << endl;
        return;
    }
    int ans[sz][sz];
    memset(ans, 0, sizeof(ans));
    int row_num = 0, count = 1, col_num = 0;
    bool processing_odd = true;
    while(count <= sz*sz) {
        assert((ans[row_num][col_num]==0));
        ans[row_num][col_num] = count;
        count++;
        if (row_num+2 < sz) {
            row_num += 2;
        }
        else {
            row_num = (processing_odd)?0:1;
            if (col_num + 1 < sz) {
                col_num++;
            }
            else {
                if (processing_odd) {
                    row_num = 1;
                    col_num = 0;
                    processing_odd = false;
                }
            }
        }
    }

    for (int i=0; i < sz; i++) {
        for (int j=0; j < sz; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
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
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int sz;
        cin >> sz;
        solve(sz);
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