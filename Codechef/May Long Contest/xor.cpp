#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mp make_pair
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)
#define REP(i, n) for(int i=0; i < n; i++)
#ifdef TEST
    #define debug(x...) cerr << #x << x << endl;
#else
    #define debug(x...)
#endif

const unsigned long long mod = 1e9+7;

unsigned long long memo[100009];

void populate() {
    int ans = 1;
    FOR(i, 1, 100001, 1) {
        ans *= 2;
        ans %= mod;
        memo[i] = ans;
    }
}

unsigned long long pow_(long long N) {
    if (memo[N]) return memo[N]%mod;
    long long ans;
    // if (N <= 10) return pow(2, N);
    if (N == 0) return 1;
    long long temp = N;
    long long key = 0;
    // temp = 1;
    ans = 1;
    long long jump = 5;
    while(temp >= jump) {
        ans *= pow(2, jump);
        ans %= mod;
        key += jump;
        memo[key] = ans;
        temp -= jump;
    }
    while(temp) {
        ans *= 2;
        ans %= mod;
        key++;
        memo[key] = ans;
        temp--;
    }
    // while ((temp*2) <= N) {
    //     temp *= 2;
    //     ans = (ans * ans) % mod;
    // }
    // while(temp != N) {
    //     ans *= 2;
    //     ans %= mod;
    //     temp++;
    // }
    return ans;
}

unsigned long long solve(int N) {
    unsigned long long exponent = (N-1);
    return pow_(exponent);
}

int main() {
#ifdef TEST
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    memset(memo, 0, sizeof(memo));
    populate();
    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int N;
        cin >> N;
        auto ans = solve(N);
        cout << ans << endl;
    }

#ifdef TEST
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}