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

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int size, row, col;
        cin >> size >> row >> col;
        int spacesTop = row - 1;
        int spacesBottom = size - row;
        int spacesLeft = col - 1;
        int spacesRight = size - col;
        int trMoves = min(spacesTop, spacesRight);
        int brMoves = min(spacesBottom, spacesRight);
        int blMoves = min(spacesBottom, spacesLeft);
        int tlMoves = min(spacesTop, spacesLeft);
        int diagonalMoves = trMoves + brMoves + blMoves + tlMoves;
        int verticalMoves = spacesTop + spacesBottom;
        int horizontalMoves = spacesLeft + spacesRight;
        int totalMoves = diagonalMoves + verticalMoves + horizontalMoves;
        cout << totalMoves << endl;
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