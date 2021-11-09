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
        ll ans = 0, max_ = 0;
        ll input[3][3];
        cin >> input[0][0] >> input[0][1] >> input[0][2];
        cin >> input[1][0] >> input[1][2];
        cin >> input[2][0] >> input[2][1] >> input[2][2];
        if (input[0][1] - input[0][0] == input[0][2] - input[0][1])
        {
            ans++;
        }
        if (input[2][1] - input[2][0] == input[2][2] - input[2][1])
        {
            ans++;
        }
        if (input[1][0] - input[0][0] == input[2][0] - input[1][0])
        {
            ans++;
        }
        if (input[1][2] - input[0][2] == input[2][2] - input[1][2])
        {
            ans++;
        }

        // row
        if ((input[1][0] % 2) == (input[1][2] % 2))
        {
            ll temp = 0;
            input[1][1] = (input[1][0] + input[1][2]) / 2;
            temp++;
            if (input[1][1] - input[0][1] == input[2][1] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[0][0] == input[2][2] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[2][0] == input[0][2] - input[1][1])
            {
                temp++;
            }
            max_ = std::max(max_, temp);
        }

        // column
        if ((input[0][1] % 2) == (input[2][1] % 2))
        {
            ll temp = 0;
            input[1][1] = (input[0][1] + input[2][1]) / 2;
            temp++;
            if (input[1][1] - input[1][0] == input[1][2] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[0][0] == input[2][2] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[2][0] == input[0][2] - input[1][1])
            {
                temp++;
            }
            max_ = std::max(max_, temp);
        }

        // diagonal
        if ((input[0][0] % 2) == (input[2][2] % 2))
        {
            ll temp = 0;
            input[1][1] = (input[0][0] + input[2][2]) / 2;
            temp++;
            if (input[1][1] - input[1][0] == input[1][2] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[0][1] == input[2][1] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[2][0] == input[0][2] - input[1][1])
            {
                temp++;
            }
            max_ = std::max(max_, temp);
        }
        if ((input[0][2] % 2) == (input[2][0] % 2))
        {
            ll temp = 0;
            input[1][1] = (input[0][2] + input[2][0]) / 2;
            temp++;
            if (input[1][1] - input[1][0] == input[1][2] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[0][1] == input[2][1] - input[1][1])
            {
                temp++;
            }
            if (input[1][1] - input[0][0] == input[2][2] - input[1][1])
            {
                temp++;
            }
            max_ = std::max(max_, temp);
        }

        ans += max_;
        cout << "Case #" << numTest << ": " << ans << endl;
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