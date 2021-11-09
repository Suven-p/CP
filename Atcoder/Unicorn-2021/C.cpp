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

int main() {
#ifdef TEST
  freopen("/media/nevus/data/CP/input.in", "r", stdin);
  freopen("/media/nevus/data/CP/output.out", "w", stdout);
  freopen("/media/nevus/data/CP/output.out", "w", stderr);
  auto start = chrono::high_resolution_clock::now();
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool ans = true;
  ll N, M;
  cin >> N >> M;
  ll last_col = 0, last_row = 0, temp = 0;
  REP(i, N) {
    REP(j, M) {
      cin >> temp;
      if (!ans) continue;
      if (temp % 7 == 0 && j != M - 1) {
        ans = false;
        continue;
      }
      if (i == 0 && j == 0) {
        last_row = temp;
        last_col = temp;
        continue;
      }
      if (j == 0) {
        if (temp != last_row + 7) {
          ans = false;
        }
        last_row = temp;
        last_col = temp;
      } else {
        if (temp != last_col + 1) {
          ans = false;
        }
        last_col = temp;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;

#ifdef TEST
  auto end = chrono::high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;
  cout << "Time taken by program is : " << endl
       << fixed << time_taken << setprecision(9) << " seconds" << endl;
#endif
  return 0;
}
