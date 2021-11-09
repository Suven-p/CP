#include <bits/stdc++.h>

using namespace std;

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

#define MAXN 2000009
int spf[MAXN];
void sieve()
{
    memset(spf, 0, sizeof(spf));
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

map<int, vector<int>> factorsMemo;
vector<int> getFactors(int n)
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
    vector<int> vec(ans.begin(), ans.end());
    factorsMemo[n] = vec;
    return factorsMemo[n];
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
    // cin >> totalTests;
    sieve();
    auto a = getFactors(315);
    for (auto c : a)
        cout << c << endl;

        // for (int numTest = 1; numTest <= totalTests; numTest++)
        // {
        //     int k = 20;
        //     int lim = 2 * k;
        //     ll terms[lim + 1];
        //     ll answer = 0;
        //     for (int i = 1; i <= lim; i++)
        //     {
        //         ll term = k + (i * i);
        //         terms[i] = term;
        //         cout << setw(5) << i << "\t";
        //         cout << setw(5) << term << "\t"
        //              << setw(5) << terms[i - 1] << "\t"
        //              << setw(5) << term - terms[i - 1] << "\t";
        //         if (i > 1)
        //         {
        //             int ans = gcd(terms[i], terms[i - 1]);
        //             cout << setw(5) << ans << "\t";
        //             answer += ans;
        //         }

        //         cout << endl;
        //     }
        //     cout << "Answer:" << answer << endl;
        // }

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