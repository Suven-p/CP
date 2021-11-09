#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

ll solve(set<ll> taken, ll K) {

    pair<ll, ll> greatest[2] = {{0, 0}, {0, 0}};
    ll greatest_length[2] = {0, 0};

    vector<pair<ll, ll>> ranges;
    ll prev = 0;
    for (auto c: taken) {
        auto range = mp(prev+1, c-1);
        prev = c;
        auto length = range.second - range.first + 1;
        if (length < 1) {
            continue;
        }
        ranges.push_back(range);
    }
    for (auto range: ranges) {
        auto length = range.second - range.first + 1;
        if (length >= greatest_length[0]) {
            greatest[1] = greatest[0];
            greatest_length[1] = greatest_length[0];
            greatest[0] = range;
            greatest_length[0] = length;
        }
        else if (length >= greatest_length[1]) {
            greatest[1] = range;
            greatest_length[1] = length;
        }
    }

    ll ans = 0;
    ll ans1 = (greatest_length[0]+1)/2;
    ll ans2 = (greatest_length[1]+1)/2;
    if (prev != K) {
        auto length = K - prev;
        if (length > ans2) {
            ans2 = length;
        }
    }
    return ans1 + ans2;
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
        int N;
        ll K;
        cin >> N >> K;
        set<ll> taken;
        for (int i=0; i < N; i++) {
            ll temp;
            cin >> temp;
            taken.insert(temp);
        }

        double ans = 0.0;
        if (taken.size() != K) {
            ll max_winning = solve(taken, K);
            // cout << max_winning << endl;
            ans = (double)max_winning / (K);
        }
        cout << "Case #" << numTest << ": " << ans << endl;
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