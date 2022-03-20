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
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)
#define REP(i, n) for(int i=0; i < n; i++)
#ifdef TEST
    #define debug(x...) cerr << #x << x << endl;
#else
    #define debug(x...)
#endif

char winner(char first, char second) {
    if (first == second) return first;
    if (first == 'R') {
        if (second == 'S') return 'R';
        else return 'P';
    }
    else if (first == 'P') {
        if (second == 'R') return 'P';
        else return 'S';
    }
    if (first == 'S') {
        if (second == 'P') return 'S';
        else return 'R';
    }
}

using MemoKey = pair<int, char>;
map<MemoKey, char> memo;

char solve(const string& str, int start, char prev_result) {
    auto key = mp(start, prev_result);
    if (memo.find(key) != memo.end()) return memo[key];
    if (start == str.size()) {
        memo[key] = prev_result;
        return prev_result;
    }
    auto ans = solve(str, start + 1, winner(prev_result, str[start]));
    memo[key] = ans;
    return memo[key];
}

int main() {
#ifdef TEST
    freopen("/media/nevus/Data/CP/input.in", "r", stdin);
    freopen("/media/nevus/Data/CP/output.out", "w", stdout);
    freopen("/media/nevus/Data/CP/output.out", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        memo.clear();
        int N;
        cin >> N;
        string S, ans;
        cin >> S;
        char prev = 0;
        REP(i, N) {
            ans += solve(S, i + 1, S[i]);
        }
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
