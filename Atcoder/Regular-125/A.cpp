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

  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int numOperations = M;
  bool firstSwitch = false;
  FOR(i, 0, M, 1) {
    int temp2;
    cin >> temp2;
    if (temp2 != a[0]) {
      if (firstSwitch) {
        numOperations++;
      } else {
        int nextPos = 1;
        int nextChar = temp2;
        int diff1 = -1, diff2 = -1;
        while (nextPos < N && a[nextPos] != nextChar) {
          nextPos++;
        }
        if (nextPos < N) {
          diff1 = nextPos;
        }
        nextPos = N - 1;
        while (nextPos >= 0 && a[nextPos] != nextChar) {
          nextPos--;
        }
        if (nextPos >= 0) {
          diff2 = N - nextPos;
        }
        if (diff1 == -1 && diff2 == -1) {
          cout << -1 << endl;
          return 0;
        } else {
          diff1 = (diff1 == -1) ? 1e9 : diff1;
          diff2 = (diff2 == -1) ? 1e9 : diff2;
          numOperations += min(diff1, diff2);
          firstSwitch = true;
        }
      }
      a[0] = temp2;
    }
  }
  cout << numOperations << endl;

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