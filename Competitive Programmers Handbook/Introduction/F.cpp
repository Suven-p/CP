#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
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
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll row, col;
        cin >> row >> col;
        ll cycle = max(row, col);
        ll ans = 0;
        ll cyc_st = 1 + ((cycle - 1) * (cycle - 1));
        ll cyc_end = (cycle * cycle);
        if (col == cycle)
        {
            if (cycle % 2 == 0)
            {
                ans = cyc_st + (row - 1);
            }
            else
            {
                ans = cyc_end - (row - 1);
            }
        }
        else if (row == cycle)
        {
            if (cycle % 2 == 0)
            {
                ans = cyc_end - (col - 1);
            }
            else
            {
                ans = cyc_st + (col - 1);
            }
        }
        cout << ans << "\n";
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