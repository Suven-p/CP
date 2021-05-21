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

pair<vi, vi> partition(vi data, ll to_get)
{
}

pair<bool, pair<vi, vi>> solve(ll N)
{
    ll sum = (N * (N + 1)) / 2;
    ll to_get = sum / 2;
    if (sum % 2 == 1)
    {
        return {false, {{}, {}}};
    }
    else
    {
        vi first, second;
        while (N)
        {
            if (to_get >= N)
            {
                first.push_back(N);
                to_get -= N;
            }
            else
            {
                second.push_back(N);
            }
            N--;
        }
        return {to_get == 0, {first, second}};
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

    int N;
    cin >> N;
    auto ans = solve(N);
    if (ans.first)
    {
        cout << "YES\n";

        cout << ans.second.first.size() << "\n";
        for (auto c : ans.second.first)
        {
            cout << c << ' ';
        }
        cout << "\n";

        cout << ans.second.second.size() << "\n";
        for (auto c : ans.second.second)
        {
            cout << c << ' ';
        }
        cout << "\n";
    }
    else
    {
        cout << "NO" << endl;
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