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

int numOperations(string a, string b) {
  if (a == b)
    return 0;
  int numOp = 0;
  // last found character
  int index1 = -1;
  // character to process
  int index2 = 0;
  for (auto c : b) {
    auto pos = a.find_first_of(c, index1 + 1);
    if (pos == std::string::npos) {
      numOp +=
          a.size() - ((index1 != -1) ? index1 : 0) - ((index1 != -1) ? 1 : 0);
      numOp += b.size() - index2;
      index1 = a.size() - 1;
      break;
    }
    numOp += pos - ((index1 != -1) ? index1 : 0) - ((index1 != -1) ? 1 : 0);
    index1 = pos;
    index2++;
  }
  numOp += a.size() - index1 - 1;
  return numOp;
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

  vector<string> powers;
  for (unsigned long long i = 0; i <= 62; i++) {
    powers.push_back(to_string(1ull << i));
  }
  numOperations("6656", "65536");
  for (int numTest = 1; numTest <= totalTests; numTest++) {
    string k;
    cin >> k;
    int minOp = k.length() + 1;
    for (auto num : powers) {
      int operations = numOperations(k, num);
      if (operations < minOp) {
        minOp = operations;
      }
    }
    cout << minOp << endl;
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