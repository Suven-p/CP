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
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int max1 = a;
        int max2 = 0;
        if (b > max1)
        {
            max2 = max1;
            max1 = b;
        }
        else if (b > max2)
        {
            max2 = b;
        }
        if (c > max1)
        {
            max2 = max1;
            max1 = c;
        }
        else if (c > max2)
        {
            max2 = c;
        }
        if (d > max1)
        {
            max2 = max1;
            max1 = d;
        }
        else if (d > max2)
        {
            max2 = d;
        }
        if ((max1 == a && max2 == b) || (max1 == b && max2 == a))
        {
            cout << "NO\n";
        }
        else if ((max1 == c && max2 == d) || (max1 == d && max2 == c))
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
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