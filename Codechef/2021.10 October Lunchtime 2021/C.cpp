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
        ll N, K;
        cin >> N >> K;
        ll matrix[N*N];
        for(ll i=0; i<N; i++) {
            for(ll j=0; j<N; j++) {
                ll temp;
                cin >> temp;
                matrix[i*N+j] = temp;
            }
        }
        sort(matrix, matrix + (N*N));
        ll mid_row = ceil((N + 1) / 2.0F);
        ll num_rows_before = mid_row - 1;
        assert(num_rows_before == int(N/2));
        ll num_rows_to_remove = N - mid_row;
        assert((num_rows_before +num_rows_to_remove + 1) == N);
        ll num_elements_to_remove = num_rows_to_remove * N;
        ll new_size = (N * N) - num_elements_to_remove;

        ll min_cost = 0;
        for(ll i = mid_row - 1; i < new_size; i += mid_row) {
            min_cost += matrix[i];
        }
        if (min_cost > K) {
            cout << -1 << endl;
            continue;
        }
        else if (min_cost == K) {
            cout << matrix[mid_row - 1] << endl;
            continue;
        }
        // cout << min_cost << std::endl;

        auto compute_cost = [&](ll min_chosen) {
            ll L = 0;
            ll cost = 0;
            ll num_chosen = 0;
            for(ll i = 0; i < new_size; i++) {
                auto num = matrix[i];
                if (L >= num_rows_before && num >= min_chosen) {
                    cost += num;
                    L -= num_rows_before;
                    num_chosen++;
                }
                else {
                    L++;
                }
                if (num_chosen == N) {
                    break;
                }
            }
            return cost;
        };
        auto comparator = [&](ll value, ll element) {
            return value < compute_cost(element);
        };
        auto first_greater = upper_bound(
            matrix,
            matrix + new_size,
            K,
            comparator
        );
        if (first_greater == matrix + new_size) {
            auto required = matrix[new_size - N];
            cout << required << endl;
        }
        else {
            auto required = --first_greater;
            cout << *required << endl;
        }
        // auto first = matrix.begin();
        // auto last = matrix.end();
        // auto count = distance(first, last);
        // while (count > 0) {
        //     auto it = first;
        //     auto step = count / 2;
        //     it += step;
        // }




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
