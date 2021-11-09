#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (ll i = j; i < k; i += inc)
#define REP(i, n) for (ll i = 0; i < n; i++)
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

vector<int> primes;

constexpr ll MAX = 100000;
// utility function for sieve of sieve of Eratosthenes
void sieve()
{
    bool isComposite[MAX + 1] = {false};
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isComposite[i] == false)
            for (int j = 2; j * i <= MAX; j++)
                isComposite[i * j] = true;
    }

    // Store all prime numbers in vector primes[]
    for (int i = 2; i <= MAX; i++)
        if (isComposite[i] == false)
            primes.push_back(i);
}

// Function to find LCM of first n Natural Numbers
long long LCM(long long n)
{
    long long lcm = 1;
    for (ll i = 0;
         i < primes.size() && primes[i] <= n;
         i++)
    {
        // Find the highest power of prime, primes[i]
        // that is less than or equal to n
        ll pp = primes[i];
        while (pp * primes[i] <= n)
            pp = pp * primes[i];

        // multiply lcm with highest power of prime[i]
        lcm *= pp;
        lcm %= 1000000007;
    }
    return lcm;
}

constexpr ll MOD = 1e9 + 7;
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
    ll totalTests = 1;
    cin >> totalTests;

    sieve();
    cout << LCM(90000) << endl;
    return 0;

    for (ll numTest = 1; numTest <= totalTests; numTest++)
    {
        ll n;
        cin >> n;
        long long ans = 0;
        ans += (n % MOD) * 2;
        ll number = 1;
        for (ll i = 2;;)
        {
            number = (number * i) / (int)__gcd(number, i);
            ll numDiv;
            numDiv = (n / number) % MOD;
            // numDiv = modDivide(n * __gcd(number, i), number * i, MOD);
            // try
            // {
            //     numDiv = modDivide(n * __gcd(number, i), number * i, MOD);
            // }
            // catch (...)
            // {
            //     cout << "Error for i= " << i << endl;
            // }
            if (numDiv == 0)
                break;
            ans += numDiv;
            i++;
        }
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