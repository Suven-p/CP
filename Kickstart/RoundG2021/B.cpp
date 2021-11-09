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
#define FOR(i, j, k, inc) for (int i=j ; i<k ; i+=inc)
#define REP(i, n) for(int i=0; i < n; i++)
#ifdef TEST
    #define debug(x...) cerr << #x << x << endl;
#else
    #define debug(x...)
#endif

struct coord {
    ll x, y;
};

int main() {
#ifdef TEST
    freopen("/media/nevus/data/CP/input.in", "r", stdin);
    freopen("/media/nevus/data/CP/output.out", "w", stdout);
    freopen("/media/nevus/data/CP/output.out", "w", stderr);
        auto start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests=1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++) {
        int numObjects;
        cin >> numObjects;
        vector<pair<coord, coord>> objects;
        multimap<ll, char> xs, ys;
        vector<ll> start_x, start_y;
        REP(i, numObjects) {
            coord a, b;
            cin >> a.x >> a.y >> b.x >> b.y;
            objects.push_back({a, b});
            xs.insert({a.x, 's'});
            xs.insert({b.x, 'f'});
            ys.insert({a.y, 's'});
            ys.insert({b.y, 'f'});
            start_x.push_back(a.x);
            start_y.push_back(a.y);
        }

        auto last_x = xs.begin()->first;
        ll temp_x = 0;
        ll up = 0, down = numObjects;
        for (const auto& x: start_x) {
            temp_x += abs(x - last_x);
        }
        ll min_x = temp_x;
        ll x_val = last_x;
        for (const auto& x: xs) {
            auto diff = x.first - last_x;
            temp_x = temp_x - (diff * (down - up));
            if (temp_x < min_x) {
                min_x = temp_x;
                x_val = x.first;
            }
            last_x = x.first;
            if (x.second == 's') {
                down--;
            }
            else if (x.second == 'f') {
                up++;
            }
        }

        auto last_y = ys.begin()->first;
        ll temp_y = 0;
        up = numObjects, down = 0;
        for (const auto& y: start_y) {
            temp_y += abs(y - last_y);
        }
        ll min_y = temp_y;
        ll y_val = last_y;
        for (const auto& y: ys) {
            auto diff = y.first - last_y;
            temp_y = temp_y - (diff * (up - down));
            if (temp_y < min_y) {
                min_y = temp_y;
                y_val = y.first;
            }
            last_y = y.first;
            if (y.second == 's') {
                up--;
            }
            else if (y.second == 'f') {
                down++;
            }
        }

        cout << "Case #" << numTest << ": " << x_val << " " << y_val << endl;
    }

#ifdef TEST
        auto end = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;
        cout << "Time taken by program is : " << endl << fixed
             << time_taken << setprecision(9) << " seconds" << endl;
#endif
    return 0;
}
