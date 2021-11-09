#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int main() {
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto start = chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll X, R, M;
        cin >> X >> R >> M;
        R *= 60;
        M *= 60;
        ll total_cycles = int(R/X);
        ll total_rest;
        if (total_cycles) {
            total_rest = (((total_cycles - 1)*X)) + (R-(X*total_cycles));
        }
        else {
            total_rest = 0;
        }
        ll total_time = total_rest + R;
        bool possible = total_time <= M;
        cout << ((possible)?"YES":"NO") << endl;
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