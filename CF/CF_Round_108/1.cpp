#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

ll solve(ll r, ll b, ll d) {
    if (b == 0) {
        return 10e12;
    }

    ll minimum_d_required;
    if (r < b) {
        minimum_d_required = ceill(((long double)b)/r) - 1;
    }
    else {
        minimum_d_required = ceill(((long double)r)/b) - 1;
    }

    return minimum_d_required;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        ll r, b, d;
        cin >> r >> b >> d;
        auto minimum_d = solve(r, b, d);
        cout << ((d >= minimum_d)?"YES":"NO") << endl;
    }

    return 0;
}