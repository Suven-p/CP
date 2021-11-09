#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")

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

#define MAXN   500009
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

map<int, vector<int>> factorsMemo;
vector<int> getFactors(int n) {
    if (factorsMemo.find(n) != factorsMemo.end()) {
        return factorsMemo[n];
    }
    auto ret = getFactorization(n);
    set<int> ans = {1};
    for (auto prime: ret) {
        set<int> newElements;
        for(auto a: ans) {
            newElements.insert(a * prime);
        }
        ans.insert(newElements.begin(), newElements.end());
    }
    vector<int> vec(ans.begin(), ans.end());
    factorsMemo[n] = vec;
    return factorsMemo[n];
}

inline bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    else return spf[n] == n;
}

size_t countFactors(int n) {
    if (factorsMemo.find(n) != factorsMemo.end()) {
        return factorsMemo[n].size();
    }
    if (n == 1) return 1;
    if (isPrime(n)) return 2;
    size_t ans = 1;
    while(true) {
        auto prime = spf[n];
        if (prime * prime * prime > n || n == 1) {
            break;
        }
        int count = 1;
        while (n % prime == 0) {
            n /= prime;
            count++;
        }
        ans *= count;
    }
    if (isPrime(n)) {
        ans *= 2;
    }
    else {
        int root = sqrt(n);
        if (root * root == n && isPrime(root)) {
            ans *= 3;
        }
        else if (n != 1)
            ans *= 4;
    }
    return ans;
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

    set<int> processed;
    for(int b=2; b <= N; b++) {
        int t1 = (M % b);
        ll t2 = M - t1;
        if (processed.find(t2) != processed.end()) {
            continue;
        }
        processed.insert(t2);
        if (b >= (M+2)/2) {
            assert(b==t2);
            count += countFactors(t2) - 1;
        }
        else {
            auto t3 = getFactors(t2);
            auto last = upper_bound(t3.begin(), t3.end(), N);
            if (last != t3.end()) {
                size_t dist = last - t3.begin();
                t3.resize(dist);
            }
            auto t4 = lower_bound(t3.begin(), t3.end(), b);
            ll excluded = (t4 - t3.begin());
            ll included = t3.size() - excluded;
            auto t5 = (excluded + t3.size() - 1) * (included) / 2;
            count += t5;
        }
    }

    // for (auto [j, i]: data) {
    //     cout << "{" << i << ", " << j << "}\n";
    // }
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    // primes.clear();
    // generatePrimes(numPrimes);

    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll N, M;
        cin >> N >> M;
        auto count = solve2(M, N);
        cout << count << endl;
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