// Any tree of height 1 is minimum diameter tree.
// Special cases when one color is zero but other is 1 and >1.
// If both >= 2, select any one as root and append all other directly to root

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
    freopen("/media/lubuntu_nevus/Home_image/CP/input.in", "r", stdin);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stdout);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int B, W;
        cin >> B >> W;
        // If a single node of any color exists, then it is minimum diameter tree.
        // If there are 2 or more of same color nodes, then it is impossible to have alternating colors.
        if ((B == 0 && W > 1) || (W == 0 && B > 1))
        {
            cout << -1 << endl;
            continue;
        }
        // Handling for case when either color if 1 and other is > 1.
        if (B > W)
        {
            REP(i, W)
            {
                cout << "W";
            }
            REP(i, B)
            {
                cout << "B";
            }
        }
        else
        {
            REP(i, B)
            {
                cout << 'B';
            }
            REP(i, W)
            {
                cout << 'W';
            }
        }
        cout << "\n";
        for (int i = B + W; i > 1; i--)
        {
            cout << "1 " << i << "\n";
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
