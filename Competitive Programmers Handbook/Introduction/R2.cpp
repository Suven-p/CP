#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#define TEST
#endif
typedef long long ll;
typedef unsigned long long ull;
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

ull pos_memo[19];
void pre()
{
    ull ans = 0;
    for (ull i = 0; i < 19; i++)
    {
        ans += 9ULL * (ull)pow(10ULL, i - 1) * i;
        pos_memo[i] = ans;
    }
}

int extractNumber(ull num, ull index)
{
    num /= (ull)pow(10, index);
    return num % 10ULL;
}

auto solve(ull pos)
{
    ull numDigits;
    REP(i, 19)
    {
        if (pos_memo[i] >= pos)
        {
            numDigits = i;
            break;
        }
    }

    ull rangeStart = pow(10ULL, numDigits - 1);
    // casting to ull is required for pow or subtraction is not
    // performed for large numbers probably due to rounding off
    ull rangeEnd = (ull)pow(10ULL, numDigits) - 1;

    ull numStart = 0, numEnd = rangeEnd - rangeStart + 1, numMid = 0;
    ull digitsStart = 1, digitsEnd = pos_memo[numDigits] - pos_memo[numDigits - 1], digitsMid = 0;
    pos -= pos_memo[numDigits - 1];
    assert(digitsStart <= pos && digitsEnd >= pos);
    while (true)
    {
        numMid = (numStart + numEnd + 1) / 2;
        digitsMid = digitsStart + (numMid - numStart) * numDigits;
        if (digitsMid <= pos)
        {
            numStart = numMid;
            digitsStart = digitsMid;
        }
        else
        {
            numEnd = numMid;
        }
        if ((max(digitsMid, pos) - min(digitsMid, pos)) <= 2 * numDigits)
        {
            break;
        }
    }
    ull posDiff = pos - digitsStart;
    if (posDiff == 0)
    {
        return extractNumber(numStart + rangeStart, numDigits - 1);
    }
    ull numDiff = posDiff / numDigits;
    ull num = rangeStart + numStart + numDiff;
    ull index = posDiff % numDigits;
    if (index == 0)
    {
        index = numDigits;
    }
    index--;
    return extractNumber(num, index);
}

int main()
{
#ifdef TEST
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ull pos;
        cin >> pos;
        auto ans = solve(pos);
        cout << ans << endl;
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