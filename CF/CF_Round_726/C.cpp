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
        vector<int> heights;
        vi ordered(N, 0);
        REP(i, N)
        {
            int temp;
            cin >> temp;
            heights.push_back(temp);
        }
        sort(heights.begin(), heights.end());
        if (N == 2)
        {
            for (auto c : heights)
            {
                cout << c << " ";
            }
            cout << endl;
            continue;
        }
        int minDiff = 1e9, minIndex = -1;
        for (int i = 1; i < N; i++)
        {
            auto diff = abs(heights[i] - heights[i - 1]);
            if (diff < minDiff)
            {
                minDiff = diff;
                minIndex = i;
            }
        }
        for (int i = minIndex; i < N; i++)
        {
            cout << heights[i] << " ";
        }
        for (int i = 0; i < minIndex; i++)
        {
            cout << heights[i] << " ";
        }
        cout << endl;
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