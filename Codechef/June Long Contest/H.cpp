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

int log_2(unsigned long long x)
{
    return ((unsigned)(8 * sizeof(unsigned long long) - __builtin_clzll((x)) - 1));
}

vector<unsigned int> solve(unsigned int N, unsigned int K)
{
    unsigned int num_bits = log_2(N);
    if (N != (1 << num_bits))
        num_bits++;
    unsigned int req_ans = (1 << (num_bits)) - 1;
    vector<unsigned int> temp;
    if (K == 1)
    {
        return {N};
    }
    if (K <= num_bits)
    {
        for (unsigned int i = 0; i < K - 1; i++)
        {
            temp.push_back(1 << (num_bits - i - 1));
        }
        auto bits_to_set = (num_bits - K + 1);
        auto ans = (1 << (bits_to_set + 1)) - 1;
        temp.push_back(ans);
        return temp;
    }
    if (K == N)
    {
        for (unsigned int i = 1; i <= N; i++)
        {
            temp.push_back(i);
        }
        return temp;
    }

    return {req_ans};
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
        int N, K;
        cin >> N >> K;
        auto ans = solve(N, K);
        for (auto c : ans)
        {
            cout << c << " ";
        }
        cout << "\n";
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