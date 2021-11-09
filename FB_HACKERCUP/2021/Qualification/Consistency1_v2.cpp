#include <bits/stdc++.h>
#include <set>

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

int main() {
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

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        string s;
        cin >> s;
        auto firstChar = s[0];
        auto pos = s.find_first_not_of(firstChar);
        int ans = 0;
        if (pos == s.npos) {
            ans = 0;
        } else {
            set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
            int vow = 0, cons = 0;
            int maxVow = 0, maxCons = 0;
            map<char, int> freq;
            for (auto c : s) {
                bool cIsVow = vowels.find(c) != vowels.end();
                freq[c]++;
                if (cIsVow) {
                    vow++;
                    if (freq[c] > maxVow) {
                        maxVow = freq[c];
                    }
                } else {
                    cons++;
                    if (freq[c] > maxCons) {
                        maxCons = freq[c];
                    }
                }
            }
            int toVow = cons + ((vow - maxVow) * 2);
            int toCons = vow + ((cons - maxCons) * 2);
            ans = min(toVow, toCons);
        }
        cout << "Case #" << numTest << ": " << ans << "\n";
    }

    return 0;
}