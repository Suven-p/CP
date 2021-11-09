#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define pb push_back
#define FOR(i, j, k) for (ll i = (j); i < ((ll)k); i++)
#define FORR(i, j, k) for (ll i = (j); i > ((ll)k); i--)
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
#ifdef TEST
#define debug(x...) cerr << #x << x << endl;
#else
#define debug(x...)
#endif

    int
    solve(string str)
{
    vi sheeps;
    REP(i, str.size())
    {
        if (str[i] == '*')
        {
            sheeps.pb(i);
        }
    }
    if (sheeps.size() == 0 || sheeps.size() == str.size() || sheeps.size() == 1)
    {
        return 0;
    }
    int mid_in = sheeps.size() / 2;
    auto mid_pos = sheeps[mid_in];
    int ans = 0;
    int destination = mid_pos - 1;
    FORR(i, mid_in - 1, -1)
    {
        auto in = sheeps[i];
        ans += (destination - in);
        destination--;
    }
    destination = mid_pos + 1;
    FOR(i, mid_in + 1, sheeps.size())
    {
        auto in = sheeps[i];
        ans += (in - destination);
        destination++;
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
        int n;
        cin >> n;
        string str;
        cin >> str;
        auto ans = solve(str);
        cout << ans << endl;
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