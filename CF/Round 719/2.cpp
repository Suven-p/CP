#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

ll to_ll(string num_str) {
    stringstream ss(num_str);
    ll num;
    ss >> num;
    return num;
}

vector<string> get_ordinary(size_t num_digit) {
    vector<string>res;
    for (ll j=1; j <= 9; j++) {
        ll num = 0;
        for (ll i = num_digit-1; i >= 0; i--) {
            num += j * pow(10ll, i);
        }
        res.push_back(to_string(num));
    }
    return res;
}

int solve(const string &num) {
    auto num_digits = num.size();
    auto ans = (num_digits-1)*9;
    auto numbers = get_ordinary(num_digits);
    for (auto c:numbers) {
        if (c <= num) {
            ans++;
        }
        else {
            break;
        }
    }
    return ans;
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
        string num;
        cin >> num;
        auto ans = solve(num);
        cout << ans << endl;
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