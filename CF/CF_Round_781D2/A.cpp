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
        ll N;
        cin >> N;
        if (N == 4)
        {
            cout << "1 1 1 1" << endl;
            continue;
        }
        if (N == 6)
        {
            cout << "1 3 1 1" << endl;
            continue;
        }
        ll a, b, c, d;
        if (N % 2 == 1)
        {
            // gcd(a, b) = gcd(a, a + 1) = 1
            // lcm(1, 1) = 1 and solve for a
            a = (N - 3) / 2;
            b = a + 1;
            c = 1;
            d = 1;
        }
        else
        {
            a = N - 3;
            b = 1;
            c = 1;
            d = 1;
        }
        cout << a << " " << b << " " << c << " " << d << endl;
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
