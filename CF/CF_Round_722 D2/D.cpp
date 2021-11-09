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

const int MAXN = 1e6 + 7;
bool isPrime[MAXN + 1];
vi listPrimes;
ll dp[MAXN];
const ll mod = 998244353;
void sieve()
{
    for (int i = 2; i <= MAXN; i++)
    {
        isPrime[i] = true;
    }
    isPrime[1] = false;
    for (int i = 2; (i * i) <= MAXN; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * 2; j <= MAXN; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= MAXN; i++)
    {
        if (isPrime[i])
        {
            listPrimes.push_back(i);
        }
    }
}

int countDivisors(int num)
{
    if (num == 1)
        return 1;
    int ans = 1;
    for (ull i = 0; i < listPrimes.size(); i++)
    {
        int prime = listPrimes[i];
        if ((prime * prime * prime) > num)
            break;
        int count = 1;
        while (num % prime == 0)
        {
            num /= prime;
            count++;
        }
        ans *= count;
    }
    if (isPrime[num])
        ans *= 2;
    else
    {
        ll root = sqrt(num);
        if (root * root == num && isPrime[root])
        {
            ans *= 3;
        }
        else if (num != 1)
        {
            ans *= 4;
        }
    }
    return ans;
}

void pre()
{
    sieve();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < MAXN; i++)
    {
        dp[i] = (countDivisors(i)) % mod;
    }
    ll current = 1;
    for (int i = 2; i < MAXN; i++)
    {
        dp[i] = ((dp[i]) % mod + (current % mod)) % mod;
        current += dp[i];
    }
}

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
    pre();

    int totalTests = 1;
    // cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {

        int N;
        cin >> N;
        cout << dp[N] << endl;
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