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

constexpr int maxN = 1e5 + 6;
int data_[maxN], N, min_elem = 1e8, min_ind = -1;
// vi primes[maxN];
// bool isPrime[maxN];

// void pre()
// {
//     memset(isPrime, true, sizeof(isPrime));

//     for (int p = 2; p * p <= maxN; p++)
//     {
//         if (isPrime[p] == true)
//         {
//             for (int i = p * p; i < maxN; i += p)
//                 isPrime[i] = false;
//         }
//     }
//     for (int p = 2; p <= maxN; p++)
//     {
//         if (isPrime[p])
//         {
//             primes->push_back(p);
//         }
//     }
// }

vector<vi> solve()
{
    vector<vi> ans;
    int count = 1;
    for (int i = min_ind - 1; i >= 0; i--)
    {
        ans.push_back(vi({i + 1, min_ind + 1, min_elem, min_elem + count}));
        count++;
    }
    count = 1;
    for (int i = min_ind + 1; i < N; i++)
    {
        ans.push_back(vi({i + 1, min_ind + 1, min_elem, min_elem + count}));
        count++;
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
    // pre();
    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        min_elem = 1e8;
        min_ind = -1;
        cin >> N;
        REP(i, N)
        {
            cin >> data_[i];
            if (data_[i] < min_elem)
            {
                min_elem = data_[i];
                min_ind = i;
            }
        }
        auto ans = solve();
        cout << ans.size() << "\n";
        for (auto c : ans)
        {
            for (auto j : c)
            {
                cout << j << " ";
            }
            cout << "\n";
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