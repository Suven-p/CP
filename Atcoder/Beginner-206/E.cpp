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

constexpr int maxN = 1e6;
vector<int> phi(maxN + 1);
vector<int> div_(maxN + 1, 0);
int L, R;
void findDivisors()
{
    for (int i = max(L, 2); i <= R; i++)
    {
        for (int j = 1; j * i <= R; j++)
            div_[i * j]++;
    }
}

void phi_1_to_n()
{
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= maxN; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= maxN; i++)
        for (int j = 2 * i; j <= maxN; j += i)
            phi[j] -= phi[i];
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

    phi_1_to_n();
    cin >>
        L >> R;
    if (L > R)
    {
        swap(L, R);
    }
    int ans = 0;
    for (int i = L; i <= R; i++)
    {
        cout << phi[i] << endl;
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