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

constexpr int mod = (1e9 + 7);
constexpr int maxN = 4e5 + 2;
int N;
vi first(maxN), second(maxN);
vector<pair<int, int>> input(maxN);

long long pow_2(long long b)
{
    long long a = 2;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void flip(int index, vector<bool> &status, int &ans, bool root=true)
{
    if (status[index])
        return;
    auto num1 = first[index];
    auto num2 = second[index];
    status[index] = true;
    if (root) ans++;
    flip(input[num1].second, status, ans, false);
    flip(input[num2].first, status, ans, false);
}

int get_distinct()
{
    vector<bool> status(N, false);
    int ans = 0;
    REP(i, N)
    {
        flip(i, status, ans);
    }
    return ans;
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
        cin >> N;
        REP(i, N)
        {
            cin >> first[i];
            input[first[i]].first = i;
        }
        REP(i, N)
        {
            cin >> second[i];
            input[second[i]].second = i;
        }
        auto i = get_distinct();
        cout << pow_2(i) << endl;
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