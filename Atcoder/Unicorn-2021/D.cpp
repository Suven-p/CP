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

  ll N, Q;
  cin >> N >> Q;
  ll back[N + 1];
  ll front[N + 1];
  memset(back, 0, (N + 1) * sizeof(back[0]));
  memset(front, 0, (N + 1) * sizeof(back[0]));
  REP(i, Q) {
    ll q, x, y;
    cin >> q >> x;
    switch (q) {
      case 1: {
        cin >> y;
        back[x] = y;
        front[y] = x;
        break;
      }
      case 2: {
        cin >> y;
        back[x] = 0;
        front[y] = 0;
        break;
      }
      case 3: {
        ll temp = x;
        vector<ll> ans;
        while (front[temp] != 0) {
          temp = front[temp];
        }
        while (temp != 0) {
          ans.push_back(temp);
          temp = back[temp];
        }
        cout << ans.size() << " ";
        for (auto car : ans) {
          cout << car << " ";
        }
        cout << endl;
        break;
      }
    }
  }

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
