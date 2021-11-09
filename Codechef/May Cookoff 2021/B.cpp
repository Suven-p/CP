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

void solve(int data[], int N, int K)
{
    if (N == K)
    {
        cout << 0 << endl;
        return;
    }

    map<int, int> freq[K];
    vi elems[K];
    for (int i = 0; i < N; i++)
    {
        freq[i % K][data[i]]++;
        elems[i % K].push_back(data[i]);
    }
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        auto max_elem = max_element(
            freq[i].begin(),
            freq[i].end(),
            [](auto p1, auto p2)
            { return p1.second < p2.second; });
        ans += elems[i].size() - max_elem->second;
    }
    cout << ans << endl;
    return;
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

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N, K;
        cin >> N >> K;
        int data[N];
        REP(i, N)
        {
            cin >> data[i];
        }
        solve(data, N, K);
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