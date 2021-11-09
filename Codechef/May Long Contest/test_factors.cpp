#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool hash_[200005];
int divCount(int n)
{
    int total = 1;
    for (int p = 2; p <= n; p++) {
        if (hash_[p]) {
            int count = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n = n / p;
                    count++;
                }
                total = total * (count + 1);
            }
        }
    }
    return total;
}

map<ll, vector<ll>> factorsMemo;
vector<long long> getFactors(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(hash_, true, sizeof(hash_));
    for (int p = 2; p * p < 200005; p++)
        if (hash_[p] == true)
            for (int i = p * 2; i < 200005; i += p)
                hash_[i] = false;


    cout << divCount(100000);
    // for (auto c: getFactors(100000)) {
    //     cout << c << " ";
    // }
    cout << endl;

}