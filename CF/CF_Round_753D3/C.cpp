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
#define FOR(i, j, k, inc) for (int i = j; i < k; i += inc)
#define REP(i, n) for (int i = 0; i < n; i++)
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

int main()
{
#ifdef TEST
    freopen("/media/nevus/data/CP/CF/CF_Round_753D3/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/CF/CF_Round_753D3/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/CF/CF_Round_753D3/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int n;
        cin >> n;
        vector<ll> num(n);
        REP(i, n)
        {
            ll temp;
            cin >> temp;
            num[i] = temp;
        }
        if (n == 1)
        {
            cout << num[0] << endl;
            continue;
        }
        sort(num.begin(), num.end());
        auto it = num.begin();
        ll correction = 0;
        while ((*it + correction) < 0)
        {
            correction -= (*it + correction);
            it++;
        }

        auto first = it;
        auto second = first + 1;
        while (second != num.end() && (*second + correction) >= (2 * (*first + correction)))
        {
            correction -= (*first + correction);
            first++;
            second++;
        }
        ll ans = (*first) + correction;
        cout << ans << endl;
    }

#ifdef TEST
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}
