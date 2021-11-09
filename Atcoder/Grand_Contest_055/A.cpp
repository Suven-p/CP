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

  int N;
  cin >> N;
  string S;
  cin >> S;
  string ans = S;
  int DIGIT = 1;
  // positions of A, B, and, C
  vector<int> positions[3];
  while (true) {
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] != 'A' && ans[i] != 'B' && ans[i] != 'C') continue;
      positions[ans[i] - 'A'].push_back(i);
    }
    sort(positions[0].begin(), positions[0].begin());
    sort(positions[1].begin(), positions[1].begin());
    sort(positions[2].begin(), positions[2].begin());
    size_t first_pos = ans.find_first_of("ABC");
    if (first_pos == string::npos) {
      break;
    }
    char first = ans[first_pos];
    ll num_current = 0;
    vector<char> others({'A', 'B', 'C'});
    others.erase(others.begin() + (first - 'A'));
    ll first_positions[3];
    first_positions[0] = -1;
    first_positions[1] = -1;
    first_positions[2] = -1;
    first_positions[first - 'A'] = first_pos;
    for (size_t i = 0; i < positions[first - 'A'].size(); i++) {
      auto pos = positions[first - 'A'][i];
      bool can_add = true;
      decltype(positions[0].end()) next_pos;
      for (auto other : others) {
        auto other_positions = positions[other - 'A'];
        next_pos =
            upper_bound(other_positions.begin(), other_positions.end(), pos);
        if (next_pos == other_positions.end()) {
          can_add = false;
          break;
        }
        ll remaining = std::distance(next_pos, other_positions.end());
        if (remaining < (num_current + 1)) {
          can_add = false;
          break;
        }
        pos = *(next_pos + num_current);
        first_positions[other - 'A'] = *next_pos;
      }
      if (can_add) {
        num_current++;
      } else {
        break;
      }
    }
    for (int i = 0; i < 3; i++) {
      auto cur_pos = first_positions[i];
      int count = 0;
      while (count != num_current) {
        auto index = ans.find_first_of('A' + i, cur_pos);
        cur_pos = index;
        ans[index] = DIGIT + '0';
        count++;
      }
    }
    DIGIT++;
  }

  for (auto c : ans) {
    cout << c;
  }
  cout << endl;

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
