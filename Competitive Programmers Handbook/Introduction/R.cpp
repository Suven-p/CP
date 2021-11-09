#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
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

ll pos_memo[18] = {0};
ll max_position(ll num_digits)
{
    ll ans = (num_digits * pow(10, num_digits)) - (pow(10, num_digits) - 10) / 9 - 1;
    return ans;
}

void pre()
{
    FOR(i, 1, 18, 1)
    {
        pos_memo[i] = max_position(i);
    }
}

int num(ll req_pos, ll numDigits)
{
    if (!(req_pos <= pos_memo[numDigits] && req_pos >= pos_memo[numDigits - 1]))
    {
        throw "Baka move somewhere";
    }
    ll range_start = pow(10, numDigits - 1);
    // Round off error on bigger numbers when using pow(10, numDigits) -1
    ll range_end = ((ll)pow(10, numDigits)) - 1;

    ll digitsuptolast = pos_memo[numDigits - 1];
    ll pos_diff = req_pos - digitsuptolast;
    ll num_diff = pos_diff / numDigits;

    // When pos_diff > 1e17 num_diff is wrong
    // if (pos_diff < 1e17)
    // {
    //     if (pos_diff % numDigits == 0)
    //     {
    //         ll num = range_start + num_diff - 1;
    //         return num;
    //     }
    //     else
    //     {
    //         ll num = range_start + num_diff;
    //         return num;
    //     }
    // }

    ll num_start = 0,
       num_end = 9 * (ll)pow(10, numDigits - 1),
       num_mid = (num_start + num_end + 1) / 2;

    ll digits_start = 0,
       digits_end = num_end * numDigits,
       digits_mid = 0;
    req_pos -= digitsuptolast;
    while (true)
    {
        if (num_end - num_start + 1 < 100)
        {
            break;
        }
        num_mid = (num_start + num_end + 1) / 2;
        digits_mid = digits_start + (num_mid - num_start) * numDigits;
        if (digits_mid <= req_pos)
        {
            num_start = num_mid;
            digits_start = digits_mid;
        }
        else
        {
            num_end = num_mid;
            digits_end = digits_mid;
        }
    }
    // digits_start -= numDigits;
    pos_diff = req_pos - digits_start;
    num_diff = (pos_diff / numDigits);
    ll num = range_start + num_start + num_diff;
    stringstream ss;
    ss << num;
    string num_s;
    ss >> num_s;
    int index = (pos_diff % numDigits);
    int ans = (num_s[index] - '0');
    return index;
}

int solve(ll pos)
{
    ll num_digits = 0;
    FOR(i, 1, 18, 1)
    {
        if (pos_memo[i] >= pos)
        {
            num_digits = i;
            break;
        }
    }

    int number = num(pos, num_digits);
    return number;
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

    int q;
    cin >> q;
    REP(i, q)
    {
        ll pos;
        cin >> pos;
        auto ans = solve(pos);
        cout << ans << "\n";
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