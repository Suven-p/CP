#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int main() {
    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto start = chrono::high_resolution_clock::now();
    #endif
    // freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    // freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int N;
        cin >> N;
        ll sum = 0;
        int ans = -1;
        ll temp;
        for (int i=0; i < N; i++) {
            cin >> temp;
            sum += temp;
            if (temp == 2) {
                ans = 1;
            }
        }
        ans = (sum % 2 == 0)? 0: ans;


        cout << ans << endl;
    }

    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
    #endif
    return 0;
}