#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalTests = 1;
    cin >> totalTests;

    for (int numTest = 1; numTest <= totalTests; numTest++)
    {
        ll num;
        ll temp;
        cin >> num;
        vector<ll> st_uni(num, 0);      // Student to university mapping
        ll num_uni = 0;
        for (ll i = 0; i < num; i++)
        {
            cin >> temp;
            st_uni[i] = temp - 1;       // Adjust for 0 based index
            num_uni = max(num_uni, temp);
        }
        vector<ll> uni_data[num_uni];     // Each vector contains set of skills
        for (ll i = 0; i < num; i++)
        {
            cin >> temp;
            auto st_university = st_uni[i];
            uni_data[st_university].push_back(temp);
        }

        vector<ll> ss[num_uni];
        for (ll i = 0; i < num_uni; i++) {

        }



        for (ll team_size = 1; team_size <= num; team_size++)
        {
            ll ans = 0;
            for (int i=0; i < num_uni; i++) {
                ll num_st = uni_data[i].size();
                if (num_st == 0) {
                    continue;
                }
                if (num_st < team_size) {
                    continue;
                }
                auto excluded = (num_st % team_size);
                ans += getSum(st[i], num_st, excluded, num_st-1);
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}