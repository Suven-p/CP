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

vector<int> getBits(int num, int nBits)
{
    int temp = num;
    vector<int> ans(nBits, 0);
    REP(i, nBits)
    {
        if (num & 1 << i)
        {
            ans[i] = 1;
        }
    }
    return ans;
}

string gray(int i, int N)
{
    auto bits = getBits(i, N);
    string ans(N, '0');
    for (int i = 0; i < N - 1; i++)
    {
        ans[N - 1 - i] = (bits[i] ^ (bits[i + 1])) ? '1' : '0';
    }
    ans[0] = (bits[N - 1]) ? '1' : '0';
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

    int N;
    cin >> N;
    for (ll i = 0; i < (ll)pow(2, N); i++)
    {
        cout << gray(i, N) << "\n";
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