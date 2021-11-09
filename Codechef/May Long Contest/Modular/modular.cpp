#include <bits/stdc++.h>

using namespace std;

// #pragma GCC optimize ("O3")

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

map<pair<ll, ll>, ll> memo;
ll getMod(ll first, ll second)
{
    if (memo.find(mp(first, second)) != memo.end())
    {
        return memo[mp(first, second)];
    }
    else
    {
        ll ans = first % second;
        memo[mp(first, second)] = ans;
        return ans;
    }
}

map<ll, vector<ll>> factorsMemo;
vector<ll> getFactors(ll x) {
    if (factorsMemo.find(x) != factorsMemo.end()) {
        return factorsMemo[x];
    }
    vector<ll> data1, data2;
    for(ll i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            data1.push_back(i);
            data2.push_back(x/i);
        }
    }
    vector<ll> data(data1.begin(), data1.end());
    data.insert(data.end(), data2.rbegin(), data2.rend());
    factorsMemo[x] = data;
    return data;
}

ll solve0(ll M, ll N)
{
    ll count = 0;
    set<pair<ll, ll>> data;
    for (ll i = 1; i < N; i++)
    {
        for (ll j = i + 1; j <= N; j++)
        {
            auto lhs = getMod(M, i);
            // cout << "LHS: " << M << " " << i << ": " << lhs << endl;
            auto rhs = getMod(getMod(M, j), i);
            // cout << "RHS: " << M << " " << j << " " << i << ": " << rhs << endl << endl;
            if (lhs == rhs)
            {
                data.insert({j, i});
                count++;
            }
        }
    }
    for (auto [j, i]: data) {
        cout << "{" << i << ", " << j << "}\n";
    }
    return count;
}

ll solve1(ll M, ll N)
{
    ll count = 0;
    if (N > M + 1)
    {
        // for all a: a >= M+1; (M%a = M)
        auto num_elements = N - M;
        count += (num_elements)*M;
    }

    // Now a, b can be chosed from range [2, M] or [2, N] whichever is lower
    N = min(N, M);

    map<ll, vector<ll>> map_;
    for (ll i = 1; i <= N; i++)
    {
        ll ans = (M % i);
        map_[ans].push_back(i);
    }
    for (auto &elem : map_)
    {
        sort(elem.second.begin(), elem.second.end());
    }
    // Fix 'a'
    bool visited[N + 7];
    memset(visited, 0, sizeof(visited));
    for (ll i = 1; i < N; i++)
    {
        ll lhs = (M % i);
        // to get rhs we can choose (M%b) to be lhs + ka where k=0,1,2,...
        vector<ll> possible;
        ll temp = lhs;
        while (temp <= N)
        {
            possible.push_back(temp);
            temp += i;
        }

        // get possible values of b from (M%b)
        for (auto c : possible)
        {
            // b must be between a and M
            // auto valid_b_start = upper_bound(map_[c].begin(), map_[c].end(), i);
            // auto valid_b_end = map_[c].end();
            // auto num = ((valid_b_end - valid_b_start));
            if (visited[c])
            {
                continue;
            }
            auto num = map_[c].size();
            auto diff = (num * (num - 1)) / 2;
            count += diff;
        }
        visited[lhs] = true;
    }
    return count;
}

ll solve2(ll M, ll N) {
    ll count = 0;
    if (N > M)
    {
        // for all x: x > M+1; (M%x = M)
        auto num_elements = N - M;
        count += ((num_elements)*(M+N-1))/2;
    }

    N = min(N, M);
    set<pair<ll, ll>> data;
    // map<ll, set<ll>> memo;
    // for(ll i = 1; i <= M; i++) {
    //     auto ans = (M % i);
    //     memo[ans].insert(i);
    // }

    // WRONG
    // for(ll a=1; a <= N; a++) {
    //     auto lhs = (M-a);
    //     auto rhs = lhs;
    //     auto start = memo[rhs].upper_bound(lhs);
    //     auto end = memo[rhs].end();
    //     auto diff = std::distance(start, end);
    //     count += diff;
    // }

    for(ll b=2; b <= N; b++) {
        ll t1 = getMod(M, b);
        ll t2 = M - t1;
        auto t3 = getFactors(t2);
        auto t4 = lower_bound(t3.begin(), t3.end(), b);
        for (auto it = t3.begin(); it != t4; it++) {
            data.insert({b, *it});
            count++;
        }
        auto t5 = std::distance(t3.begin(), t4);
        count += t5;
    }

    for (auto [j, i]: data) {
        cout << "{" << i << ", " << j << "}\n";
    }
    return count;
}

int main()
{
#ifdef TEST
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll N, M;
        cin >> N >> M;
        auto count = solve2(M, N);
        cout << count << endl;
        // for (auto c: getFactors(100000)) {
        //     cout << c << " ";
        // }
        // cout << endl;
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