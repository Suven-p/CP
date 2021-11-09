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

    ll N;
    cin >> N;
    ll data[N], sum = 0;
    for (ll i=0; i < N; i++) {
        cin >> data[i];
        sum += data[i];
    }

    ll totalQueries=1;
    cin >> totalQueries;
    ll ans = sum;

    ll c = pow(10ll, 9ll) + 7;
    for (ll numQueries = 0; numQueries < totalQueries; numQueries++) {
        ll temp;
        cin >> temp;
        ans = ((ans%c) * (2%c));
        cout << ans%c << endl;
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