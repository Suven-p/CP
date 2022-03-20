// https://www.codechef.com/DEC21B/problems/LISTLIST

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
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)
#define REP(i, n) for(int i=0; i < n; i++)
#ifdef TEST
    #define debug(x...) cerr << #x << x << endl;
#else
    #define debug(x...)
#endif


int main() {
#ifdef TEST
    freopen("/media/nevus/Data/CP/input.in", "r", stdin);
    freopen("/media/nevus/Data/CP/output.out", "w", stdout);
    freopen("/media/nevus/Data/CP/output.out", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int n;
        cin >> n;
        vi v(n);
        map<int, int> histogram;
        REP(i, n) {
            cin >> v[i];
            ++histogram[v[i]];
        }
        if (histogram.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        int max_val = 0;
        for(auto it = histogram.rbegin(); it != histogram.rend(); it++) {
            if (it->second > max_val) {
                max_val = it->second;
            }
        }
        if (max_val < 2) {  // need first and last element to be same
            cout << -1 << endl;
            continue;
        }
        int remaining = n - max_val;
        if (remaining == 0) {
            cout << 0 << endl;
            continue;
        }
        // It is always more efficient to collect them into single string
        // (remaining - 1) steps to collect them into single string and 2
        // more steps to concatenate them to number with highest frequency
        cout << remaining + 1 << endl;
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
