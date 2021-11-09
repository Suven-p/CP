#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int main() {
    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto start = chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int N, X;
        cin >> N >> X;
        vector<pair<ll, ll>> data;
        for (int i=0; i < N; i++) {
            ll S, R;
            cin >> S >> R;
            data.push_back({R, S});
        }

        sort(data.rbegin(), data.rend());
        auto it = find_if(data.begin(), data.end(), [X](auto movie){return movie.second <= X;});
        cout << it->first << endl;
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