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
        int n;
        cin >> n;
        int maxIndex = 0, minIndex = 0, min = 1e9, max = 0;
        int left = 0, right = 0;
        bool eq = false;
        REP(i, n)
        {
            int temp;
            cin >> temp;
            if (temp > max)
            {
                max = temp;
                maxIndex = i;
            }
            if (temp < min)
            {
                min = temp;
                minIndex = i;
            }
        }
        // from left
        if (maxIndex < n - maxIndex)
        {
            left = maxIndex + 1;
        }
        else if (maxIndex > n - maxIndex)
        {
            right = (n - maxIndex);
        }
        else
        {
            eq = true;
            if (minIndex < n - minIndex)
            {
                left = std::max(maxIndex + 1, minIndex + 1);
            }
            else if (minIndex < n - minIndex)
            {
                right = std::max(n - maxIndex, n - minIndex);
            }
        }

        if (!eq)
        {
            if (minIndex < n - minIndex)
            {
                left = std::max(left, minIndex + 1);
            }
            else if (minIndex < n - minIndex)
            {
                right = std::max(right, n - minIndex);
            }
            else
            {
            }
        }
        cout << left + right << endl;
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