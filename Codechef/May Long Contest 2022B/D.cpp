// Tracing out pattern in paper and excluding 0's you get Pascal's triangle; Use combination
// property of generating Pascal's triangle: nCr = (nCr-1 * (n - r + 1))/r
// Adjust for some special indices

#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif
typedef long long ll;
typedef unsigned long long ull;
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

constexpr ull MOD = 1e9 + 7;
auto mod(ull a)
{
    return a % MOD;
}

auto pow_mod(ull x, ull n, ull m = MOD)
{
    ull y = 1;
    while (n > 0)
    {
        if (n & 1)
            y = mod(y * x);
        x = mod(x * x);
        n >>= 1;
    }
    return y;
}

auto modular_inverse(ull a, ull m = MOD)
{
    return pow_mod(a, m - 2, m);
}

void printPascalsTriangle(ll N, ll L, ll R)
{
    unsigned long long prev = 1;
    if (L == 0)
    {
        cout << 1 << " ";
        if (R == 0)
        {
            return;
        }
        cout << "0 ";
    }
    // nCr = (nCr-1 * (n - r + 1))/r
    for (ll r = 1; r <= N; r++)
    {
        if (r > R)
        {
            break;
        }
        // auto mult = double(N - r + 1) / r;
        auto curr = mod(mod(prev * (N - r + 1)) * modular_inverse(r));
        if (r >= L)
        {
            cout << curr << " ";
            if (r != R)
            {
                cout << "0 ";
            }
        }
        prev = curr;
    }
}

bool is_odd(ll N)
{
    return N & 1;
}

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
        ll N, L, R;
        cin >> N >> L >> R;
        L += N;
        R += N;
        // Shifting by N puts values in even indices; 0,2,4...
        // and zeroes in odd indices; 1,3,5...
        // Answer is given by C(N,r) for L/2 <= r <= R/2
        bool add_final_zero = false;
        if (is_odd(R))
        {
            if (L != R)
            {
                add_final_zero = true;
            }
            R--;
        }
        if (is_odd(L))
        {
            cout << "0 ";
            L++;
        }
        L /= 2ll;
        R /= 2ll;
        // Print pascals triangle in range [L, R]
        printPascalsTriangle(N, L, R);
        if (add_final_zero)
        {
            cout << "0";
        }
        cout << endl;
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
