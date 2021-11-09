#include <bits/stdc++.h>

using namespace std;

// #pragma OPTIMIZE("O3")

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

map<pair<ll, ll>, ll> memo;
#define MAXN 2000009
int spf[MAXN];
void sieve()
{
    for (int i = 1; i < MAXN; i++)
        spf[i] = 2 * i + 1;
    for (ll i = 3; i * i < 2 * MAXN; i += 2)
    {
        auto index = (i - 1) / 2;
        if (spf[index] == i)
        {
            for (int j = i * i; j < 2 * MAXN; j += i)
            {
                if (j % 2 == 0)
                    continue;
                auto i2 = (j - 1) / 2;
                if (spf[i2] == j)
                {
                    spf[i2] = i;
                }
            }
        }
    }
}

int get_spf(int i)
{
    auto index = (i - 1) / 2;
    return spf[index];
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        auto a = get_spf(x);
        ret.push_back(a);
        x = x / a;
    }
    return ret;
}

map<int, set<int>> factorsMemo;
set<int> getFactors(int n)
{
    if (factorsMemo.find(n) != factorsMemo.end())
    {
        return factorsMemo[n];
    }
    auto ret = getFactorization(n);
    set<int> ans = {1};
    for (auto prime : ret)
    {
        set<int> newElements;
        for (auto a : ans)
        {
            newElements.insert(a * prime);
        }
        ans.insert(newElements.begin(), newElements.end());
    }
    factorsMemo[n] = ans;
    return factorsMemo[n];
}

int getHcf(int a, int b)
{
    auto f2 = getFactors(b);
    for (auto it = f2.rbegin(); it != f2.rend(); it++)
    {
        if (a % (*it) == 0)
        {
            return (*it);
        }
    }
    return 1;
}

auto solve0(ll N)
{
    ll ans = 0;
    for (ll i = 1; i <= 2 * N; i++)
    {
        ans += std::gcd(N + (i * i), ((2 * i) + 1));
    }
    return ans;
}

auto solve1(ll N)
{
    ll ans = 0;
    for (ll i = 1; i <= 2 * N; i++)
    {
        auto n1 = (N + (i * i));
        auto n2 = (2 * i) + 1;
        ans += getHcf(n1, n2);
    }
    return ans;
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
    int totalTests = 1;
    cin >> totalTests;

    sieve();

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll N;
        cin >> N;
        auto ans = solve1(N);
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