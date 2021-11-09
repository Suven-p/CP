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
    int K;
    cin >> K;
    set<char> from[26], to[26];
    REP(i, K) {
      char temp1, temp2;
      cin >> temp1 >> temp2;
      int i1 = int(temp1) - int('A');
      int i2 = int(temp2) - int('A');
      to[i1].insert(temp2);
      for (auto c : to[i2]) {
        to[i1].insert(c);
        from[c - 'A'].insert(temp1);
      }
      from[i2].insert(temp1);
      for (auto c : from[i1]) {
        from[i2].insert(c);
        to[c - 'A'].insert(temp2);
      }
    }
    set<char> toCheck(s.begin(), s.end());
    set<char> possibleCandidate;
    REP(i, 26) {
      bool invalid = false;
      for (auto c : toCheck) {
        if (int(c - 'A') == i)
          continue;
        if (from[i].find(c) == from[i].end()) {
          invalid = true;
          break;
        }
      }
      if (!invalid) {
        possibleCandidate.insert(i + 'A');
      }
    }
  } // end of numtest
  return 0;
}