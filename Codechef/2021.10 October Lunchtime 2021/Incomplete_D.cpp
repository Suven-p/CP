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

int N, Q;
constexpr int maxN = 1e5 + 10;
vector<int> tree[maxN];

void reset() {
  N = 0;
  Q = 0;
  REP(i, maxN) { tree[i].clear(); }
}

void maximize_value(int current, int parent, ll& value, bool is_odd) {
  if (is_odd) {
    ll num_children =
        (current == 1) ? tree[current].size() : tree[current].size() - 1;
    value += abs(int(num_children - 1));
  }
  for (auto node : tree[current]) {
    if (node != parent) {
      maximize_value(node, current, value, !is_odd);
    }
  }
}

auto minimize_value() { return 0; }

auto solve() {
  assert(Q == 1 || Q == 2);
  switch (Q) {
    case 1: {
      ll value = 0;
      maximize_value(1, 0, value, true);
      cout << value << endl;
      break;
    }
    case 2: {
      break;
    }
    default:
      throw "Invalid value for Q!";
  }
}

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
    reset();
    cin >> N >> Q;
    REP(i, N - 1) {
      int u, v;
      cin >> u >> v;
      tree[u].push_back(v);
      tree[v].push_back(u);
    }
    solve();
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
