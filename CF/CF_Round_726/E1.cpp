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
    // cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int i = 0;
        int sz;
        string sub;
        while (true)
        {
            sz = 1 << i;
            if (sz > n || sz > (k / 2))
            {
                break;
            }
            string s1 = s.substr(0, sz);
            string s2 = s.substr(sz, sz);
            if (s1 > s2)
            {
                sub = s1 + s2;
            }
            else
            {
                sub = s1;
                break;
            }
            i++;
        }
        while (sub.size() < k)
        {
            sub += sub;
        }
        sub.resize(k);
        cout << sub << endl;
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