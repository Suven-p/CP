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

bool solve2(vector<int> &weights, int to_avoid, int start) {
    if (start >= weights.size()) {
        return true;
    }
    auto first = weights[start];
    if (first == to_avoid) {
        if (start + 1 < weights.size()) {
            swap(weights[start], weights[start+1]);
            return true;
        }
        else {
            return false;
        }
    }
    if (first > to_avoid) {
        return true;
    }
    auto ans = solve2(weights, to_avoid - first, start+1);
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
        int n, k;
        cin >> n >> k;
        vi data;
        REP(i, n) {
            int temp;
            cin >> temp;
            data.push_back(temp);
        }
        bool is_possible = solve2(data, k, 0);
        if (is_possible) {
            cout << "YES\n";
            for (auto c: data) {
                cout << c << ' ';
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
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