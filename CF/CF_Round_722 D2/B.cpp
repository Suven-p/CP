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

int N;
vi input;

int solve()
{
    int ans = 0;
    bool is_repeat = false;
    int min_diff = 10e8;
    sort(input.begin(), input.end());
    REP(i, N)
    {
        auto c = input[i];
        if (c <= 0)
        {
            ans++;
            if (i > 0)
            {
                min_diff = min((abs(c - input[i - 1])), min_diff);
                if (c == input[i - 1])
                    is_repeat = true;
            }
        }
        else
        {
            if ((not is_repeat) and c <= min_diff)
            {
                ans++;
            }
            break;
        }
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

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        input.clear();
        cin >> N;
        REP(i, N)
        {
            int temp;
            cin >> temp;
            input.push_back(temp);
        }
        auto ans = solve();
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