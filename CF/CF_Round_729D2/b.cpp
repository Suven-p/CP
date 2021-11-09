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

bool solve(int n, const int &a, const int &b)
{
    int maxPow = floor(log2(a) / log2(b));
    int first = pow(a, maxPow);
    if (first == n)
        return true;
    n -= first;
    if (n % b != 0)
        return false;
    n /= b;
    for (int i = maxPow - 1; i <= 0; i--)
    {
        int div = (int)(pow(a, i)) * b;
        if (n % div != 0)
            continue;
        for (int j = 1; j <= n / div; j++)
        {
            auto res = solve(n - (div * j), a, b);
            if (res)
                return true;
        }
    }
    return false;
}

bool solve2(int n, const int &a, const int &b, int startpow)
{
}

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
        int n, a, b;
        cin >> n >> a >> b;
        bool res = solve(n, a, b);
        cout << ((res) ? "Yes\n" : "No\n");
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