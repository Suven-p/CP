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
        ll N, C;
        cin >> N >> C;
        multiset<ll> start, exit;
        map<ll, ll> merged;
        for (ll i = 0; i < N; i++)
        {
            ll temp1, temp2;
            cin >> temp1 >> temp2;
            start.insert(temp1);
            exit.insert(temp2);
        }
        auto it1 = (start.begin());
        auto it2 = exit.begin();
        int current_in = 0, current_out = 0;
        while (true)
        {
            if (it1 == start.end() || it2 == exit.end())
                break;
            if (*it1 <= *it2)
            {
                current_in++;
                merged[*it1] = current_in;
                it1++;
            }
            else
            {
                current_in--;
                merged[*it2] = current_in;
                it2++;
            }
        }
        merged[*exit.rbegin()] = 0;
        int prev_num = -1;
        map<ll, ll> cut_value;
        for (auto it = merged.begin();;)
        {
            auto current = *it;
            it++;
            if (it == merged.end())
                break;
            auto next = *it;
            auto number = next.first - current.first - 1;
            if (current.second > start.count(current.first))
            {
                cut_value[current.second - start.count(current.first)]++;
            }
            auto values = current.second;
            if (number)
                cut_value[values] += number;
        }

        vector<ll> cf;
        ll current_cuts = 0, ans = N;
        for (auto it = cut_value.rbegin(); it != cut_value.rend(); it++)
        {
            if (current_cuts + it->second > C)
            {
                ans += C - current_cuts;
                break;
            }
            else
            {
                current_cuts += it->second;
                ans += it->first * it->second;
            }
        }
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