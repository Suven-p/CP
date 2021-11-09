#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

ll to_ll(string num) {
    stringstream ss;
    ss << num;
    ll ans;
    ss >> ans;
    return ans;
}

string solve(string num) {
    ll len = num.size() / 2;
    string ans = "";
    while(num.size() % len) {
        len--;
    }
    vector<ll> ranges;
    ll count = num.size() / len;
    string initial;
    for (int i=0; i < count; i++) {
        ranges.push_back(to_ll(num.substr(i*len, len)));
    }
    for (int i=1; i < count;) {
        if (i == 0)
            break;
        if (ranges[i] > ranges[i-1]) {
            ranges[i-1]++;
            i--;
        }
        else {
            i++;
        }
    }

    ll prev = ranges[0];
    // cout << prev << endl;
    while(ans.size() < num.size() || ans < num) {
        ans += to_string(prev);
        prev++;
    }
    return ans;
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
        string num;
        cin >> num;
        auto ans = solve(num);
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