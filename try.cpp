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

class Solution
{
public:
    long long countGlobal(vector<int> &nums, size_t start, size_t end)
    {
        long long ans = 0;
        if (start >= end)
        {
            return 0;
        }
        auto mid = (start + end) / 2;
        ans += countGlobal(nums, start, mid);
        ans += countGlobal(nums, mid + 1, end);
        size_t i = start, j = mid + 1, k = 0, p = mid + 1;
        vector<int> temp(end - start + 1);
        while (i <= mid)
        {
            while (p <= end && nums[i] > 2ll * nums[p])
            {
                p++;
            }
            ans += p - (mid + 1);
            while (j <= end && nums[i] >= nums[j])
            {
                temp[k] = nums[j];
                j++;
                k++;
            }
            temp[k] = nums[i];
            i++;
            k++;
        }
        while (j <= end)
        {
            temp[k] = nums[j];
            j++;
            k++;
        }
        std::copy(temp.begin(), temp.end(), nums.begin() + start);
        return ans;
    }

    int reversePairs(vector<int> &nums)
    {
        return countGlobal(nums, 0, nums.size() - 1);
    }
};

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

    long long N;
    cin >> N;
    vector<int> nums(N);
    REP(i, N)
    {
        cin >> nums[i];
    }
    Solution s;
    cout << s.reversePairs(nums) << endl;

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
