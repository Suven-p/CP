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

ll count_sum_lte(ll x, vector<ll> &a, vector<ll> &b)
{
    ll count = 0;
    for (auto &i : a)
    {
        if (i <= x)
        {
            ll required_gt = x - i;
            ll num_elems = std::distance(b.begin(), upper_bound(b.begin(), b.end(), required_gt));
            count += num_elems;
        }
    }
    return count;
}

bool enough(ll mid, ll k, vector<ll> &sum1, vector<ll> &sum2)
{
    ll count = 0;
    for (auto x : sum1)
    {
        if (x == 0)
        {
            count += sum2.size();
            continue;
        }
        ll max_value = mid / x;
        count += std::distance(sum2.begin(), std::upper_bound(sum2.begin(), sum2.end(), max_value));
    }
    return count >= k;
}

ll enough2(ll mid, ll k, vector<ll> &sum1, vector<ll> &C, vll &D)
{
    ll count = 0;
    for (auto x : sum1)
    {
        if (x == 0)
        {
            count += (C.size() + D.size());
            continue;
        }
        ll max_value = (ll)(mid / x);
        count += count_sum_lte(max_value, C, D);
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
        int SA, SB, SC, SD, K;
        cin >> SA >> SB >> SC >> SD >> K;
        vll A(SA), B(SB), C(SC), D(SD);
        REP(i, SA)
        {
            cin >> A[i];
        }
        REP(i, SB)
        {
            cin >> B[i];
        }
        REP(i, SC)
        {
            cin >> C[i];
        }
        REP(i, SD)
        {
            cin >> D[i];
        }
        vll sum1(SA * SB);
        vll sum2(SC * SD);
        REP(i, SA)
        {
            REP(j, SB)
            {
                sum1[i * SB + j] = A[i] + B[j];
            }
        }
        REP(i, SC)
        {
            REP(j, SD)
            {
                sum2[i * SD + j] = C[i] + D[j];
            }
        }
        sort(sum1.begin(), sum1.end());
        sort(sum2.begin(), sum2.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        ll lo = sum1[0] * (C[0] + D[0]), hi = sum1[sum1.size() - 1] * (C[C.size() - 1] + D[D.size() - 1]);
        while (lo < hi)
        {
            auto mid = (lo + hi) >> 1;
            bool isEnough;
            isEnough = enough(mid, K, sum1, sum2);
            if (!isEnough)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        std::cout << lo << endl;
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
