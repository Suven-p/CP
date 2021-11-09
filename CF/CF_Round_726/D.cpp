#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
// #pragma GCC optimize "trapv"
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

constexpr int maxN = 1e9 + 7;
bool prime[maxN];
vi listPrimes;

void SieveOfEratosthenes()
{
    for (int i = 2; i < maxN; i++)
    {
        prime[i] = true;
    }
    prime[1] = false;

    for (int p = 2; p * p < maxN; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * 2; i < maxN; i += p)
                prime[i] = false;
        }
    }

    int j = 0;
    for (int p = 2; p < maxN; p++)
    {
        if (prime[p])
        {
            listPrimes.push_back(p);
        }
    }
}

// Function to count divisors
int countDivisors(int n)
{
    if (n == 1)
        return 0;
    if (prime[n])
        return 0;

    int ans = 1;

    for (int i = 0;; i++)
    {
        if (listPrimes[i] * listPrimes[i] * listPrimes[i] > n)
            break;

        int cnt = 1;
        while (n % listPrimes[i] == 0)
        {
            n = n / listPrimes[i];
            cnt = cnt + 1;
        }
        ans = ans * cnt;
    }
    if (prime[n])
    {
        ans = ans * 2;
    }

    else
    {
        int root = sqrt(n);
        if (prime[root] && (root * root) == n)
        {
            ans *= 3;
        }
        else if (n != 1)
        {
            ans *= 4;
        }
    }
    return max(ans - 2, 0);
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
    SieveOfEratosthenes();
    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int temp;
        cin >> temp;
        auto ans = countDivisors(temp);
        if (ans % 2 == 0)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
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