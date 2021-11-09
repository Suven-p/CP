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
  int totalTests = 1;

  int N;
  cin >> N;
  set<int> tree[N];
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    tree[a - 1].insert(b - 1);
    tree[b - 1].insert(a - 1);
  }
  bool ans = false;
  REP(i, N) {
    if (tree[i].size() == N - 1) {
      ans = true;
      break;
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
