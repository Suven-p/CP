#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

bool canSum(ll req, vector<ll> arr) {
    ll sum = 0;
    for (auto c: arr) {
        sum += c;
        if (sum >= req) {
            return true;
        }
    }
    return false;
}

int main() {
    #if defined(LOCALCODE) || !defined(ONLINE_JUDGE)
        auto start = chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll N, W, Wr;
        cin >> N >> W >> Wr;
        ll weights[N];
        map<ll, ll> freq;
        bool possible = false;
        for (ll i=0; i < N; i++) {
            cin >> weights[i];
            freq[weights[i]]++;
        }
        if (W <= Wr) {
            cout << "YES" << endl;
            continue;
        }
        else {
            ll required_weight = W - Wr;
            vector<ll> available;
            for (auto &c: freq) {
                if (c.second > 1) {
                    for (ll i=0; i < (c.second / 2); i++) {
                        available.push_back(c.first);
                    }
                }
            }
            possible = canSum((ll)((required_weight+1)/2), available);
        }

        cout << ((possible)?"YES":"NO") << endl;
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