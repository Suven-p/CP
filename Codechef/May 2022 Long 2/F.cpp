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

constexpr long long M = (long long)1e9 + 1;

long long solve(vector<int> &nums)
{
    vector<int> prevRow(7, 0);
    prevRow[0] = 1;
    vector<int> currRow = prevRow;
    for (size_t currentIndex = 0; currentIndex < nums.size(); currentIndex++)
    {
        currRow = vector<int>(7, 0);
        ll current = nums[currentIndex];
        int length = log10(current) + 1;
        REP(i, 7)
        {
            int remainderAfterAdding = ((ll)(pow(10, length) * i) + current) % 7;
            currRow[i] = (currRow[i] + prevRow[i]) % M;
            currRow[remainderAfterAdding] = (currRow[remainderAfterAdding] + prevRow[i]) % M;
        }
        prevRow = currRow;
    }
    return (currRow[0] - 1 + M) % M;
}

ll bruteForce(vector<int> &nums)
{
    ll count = 0;
    for (int i = 1; i < (1 << nums.size()); i++)
    {
        ll num = 0;
        REP(j, (1 << nums.size()))
        {
            if (i & (1 << j))
            {
                int length = log10(nums[j]) + 1;
                if (length != 1 && length != 2)
                    num *= (ll)pow(10, length);
                num += nums[j];
            }
        }
        if (num != 0 && num % 7 == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
#ifdef TEST
    freopen("/media/lubuntu_nevus/Home_image/CP/input.in", "r", stdin);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stdout);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    // cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        // int N;
        // cin >> N;
        // vi nums(N);
        // REP(i, N)
        // {
        //     cin >> nums[i];
        // }
        vi nums(10, 0);
        for (int numIteration = 0; numIteration < 100; numIteration++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = rand() % 100;
                if (nums[i] == 0)
                {
                    i--;
                }
            }
            if (solve(nums) != bruteForce(nums))
            {
                cout << "Invalid for ";
                for (auto &num : nums)
                {
                    cout << num << " ";
                }
                cout << endl;
            }
        }
        // cout << solve(nums) << endl;
        // cout << bruteForce(nums) << endl
        //      << endl;
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
