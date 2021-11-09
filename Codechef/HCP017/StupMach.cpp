#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll N;
        cin >> N;
        vector<ll> data(N, 0);
        ll ans = 0;
        for (ll i=0; i < N; i++) {
            cin >> data[i];
        }
        auto start = data.begin(), end = data.end();
        ll decrement = 0;
        while(start != end) {
            auto min = min_element(start, end);
            ll num_elements = end - start;
            *min -= decrement;
            ans += (*min) * num_elements;
            decrement += (*min);
            end = min;
        }

        cout << ans << endl;
    }

    return 0;
}