#include <bits/stdc++.h>

using namespace std;

#if defined(LOCALCODE) && !defined(ONLINE_JUDGE)
#pragma GCC optimize "trapv"
#define TEST
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> coord;
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
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
    auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        int N;
        cin >> N;
        set<coord> points;
        set<int> allX, allY;
        coord left = mp(1e9, 0),
              right = (mp(-1e9, 0)),
              top = mp(0, -1e9),
              bottom = mp(0, 1e9);
        REP(i, N)
        {
            int x, y;
            cin >> x >> y;
            coord temp = mp(x, y);
            if (x < left.first)
                left = temp;
            if (x > right.first)
                right = temp;
            if (y < bottom.second)
                bottom = temp;
            if (y > top.second)
                top = temp;
            points.insert(temp);
            allX.insert(x);
            allY.insert(y);
        }
        // For one point solution is trivial
        // This is required because it causes segfault\
        // for single point
        if (N == 1)
        {
            cout << 0 << endl;
            continue;
        }
        ll ans1, ans2;
        // splitting vertically
        coord topLeft = mp(1e9, 0),
              topRight = mp(-1e9, 0),
              bottomLeft = mp(1e9, 0),
              bottomRight = mp(-1e9, 0);
        int midV = (top.second + bottom.second) / 2;
        // splitting horizontally
        coord leftTop = mp(0, -1e9),
              leftBottom = mp(0, 1e9),
              rightTop = mp(0, -1e9),
              rightBottom = mp(0, 1e9);
        int midH = (left.first + right.first) / 2;

        for (auto c : points)
        {
            if (c.first <= midH)
            {
                if (c.second > leftTop.second)
                {
                    leftTop = c;
                }
                if (c.second < leftBottom.second)
                {
                    leftBottom = c;
                }
            }
            else
            {
                if (c.second > rightTop.second)
                {
                    rightTop = c;
                }
                if (c.second < rightBottom.second)
                {
                    rightBottom = c;
                }
            }
            if (c.second <= midV)
            {
                if (c.first < bottomLeft.first)
                {
                    bottomLeft = c;
                }
                if (c.first > bottomRight.first)
                {
                    bottomRight = c;
                }
            }
            else
            {
                if (c.first < topLeft.first)
                {
                    topLeft = c;
                }
                if (c.first > topRight.first)
                {
                    topRight = c;
                }
            }
        }

        auto it1 = allX.upper_bound(midH);
        // Horizontal part 2 x-coord start
        // Part 2 needs to processed first because first part
        // decrements it
        int H2xs = *it1;
        int H2xe = right.first;
        int H2ys = rightBottom.second;
        int H2ye = rightTop.second;

        // Part 2 needs to processed first because first part
        // decrements it
        int H1xs = left.first;
        int H1xe = *(--it1);
        int H1ys = leftBottom.second;
        int H1ye = leftTop.second;

        auto it2 = allY.upper_bound(midV);
        // Part 2 needs to processed first because first part
        // decrements it
        int V2xs = topLeft.first;
        int V2xe = topRight.first;
        int V2ys = *it2;
        int V2ye = top.second;

        // Part 2 needs to processed first because first part
        // decrements it
        int V1xs = bottomLeft.first;
        int V1xe = bottomRight.first;
        int V1ys = bottom.second;
        int V1ye = *(--it2);

        ans1 = ((H1xe - H1xs) * (H1ye - H1ys) + ((H2xe - H2xs) * (H2ye - H2ys)));
        ans2 = ((V1xe - V1xs) * (V1ye - V1ys) + ((V2xe - V2xs) * (V2ye - V2ys)));

        cout << min(ans1, ans2) << endl;
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