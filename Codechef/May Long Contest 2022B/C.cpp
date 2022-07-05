// A xor B > A & B if number of bits is different
// if number of bits of A is greater than that of B; first digit of A xor B is 1 but A and B is 0
//     1xxx        1xxx
// xor 01xx        01xx
//     1xxx        0xxx
// Total possible numbers = (R - L + 1)
// exclude elements whose number of bits is same as X
// Numbers of exclude = count(A[I]); L <= I <= R where number of bits of A[I] = number of bits of X
// Ans = Total possible numbers - Exclude

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

map<ll, unsigned long long> memoize;
unsigned long long count_bits(ll n)
{
    if (n == 0)
        return 0;
    if (memoize.count(n))
    {
        return memoize[n];
    }
    memoize[n] = (unsigned long long)(log2(n) + 1);
    return memoize[n];
}

// Find number of position in positions in range [L, R]
ll find_num(vector<size_t> &positions, ll L, ll R)
{
    auto itStart = lower_bound(positions.begin(), positions.end(), L);
    auto itEnd = upper_bound(positions.begin(), positions.end(), R);
    // If all elements are smaller than L, return 0
    if (itStart == positions.end())
    {
        return 0;
    }
    // If all elements are greater than R, first element greater than L
    // is also greater than R, return 0
    if (*itStart > R)
    {
        return 0;
    }
    // else *itStart >= L and itEnd > R
    ll distance = std::distance(itStart, itEnd);
    return distance;
}

int main()
{
#ifdef TEST
    freopen("/media/lubuntu_nevus/Home_image/CP/input.in", "r", stdin);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stdout);
    freopen("/media/lubuntu_nevus/Home_image/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;
    // To find given answer count number of elements in the array
    // such that len(X) != len(A[i]) for i in [L, R]
    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N;
        cin >> N;
        vll A(N);
        map<unsigned long long, vector<size_t>> num_bits_to_array_position;
        REP(i, N)
        {
            ll temp;
            cin >> temp;
            A[i] = count_bits(temp);
            num_bits_to_array_position[A[i]].push_back(i);
        }
        for (auto it = num_bits_to_array_position.begin(); it != num_bits_to_array_position.end(); it++)
        {
            sort(it->second.begin(), it->second.end());
        }
        int Q;
        cin >> Q;
        REP(i, Q)
        {
            ll L, R, X;
            cin >> L >> R >> X;
            L--;
            R--;
            ll ans = R - L + 1;
            auto length_X = count_bits(X);
            auto &positions = num_bits_to_array_position[length_X];
            auto distance = find_num(positions, L, R);
            ans -= distance;
            cout << ans << endl;
        }
    }

#ifdef TEST
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}
