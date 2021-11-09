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
        int N;
        cin >> N;
        set<int> input;
        bool has_negative = false;
        int minDiff = 1e9 + 7;
        REP(i, N)
        {
            int temp;
            cin >> temp;
            auto res = input.insert(temp);
            if (temp < 0)
            {
                has_negative = true;
            }
        }
        if (has_negative)
        {
            cout << "NO" << endl;
        }
        else
        {
            minDiff = *input.begin();
            for (auto it = input.begin(); it != (input.end()); it++)
            {
                int val = *it;
                if (minDiff == 0)
                    minDiff = val;
                if (val == 0)
                {
                    minDiff = 0;
                    continue;
                }
                minDiff = __gcd(minDiff, val);
            }
            for (int i = minDiff; i < *input.rbegin(); i += minDiff)
            {
                input.insert(i);
            }
            cout << "YES\n" << input.size() << "\n";
            for (auto c: input) {
                cout << c << " ";
            }
            cout << endl;
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