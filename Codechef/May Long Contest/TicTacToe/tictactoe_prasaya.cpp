#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for (i = 0; i < n; i++)
#define deb(x) cout << #x << " = " << x << endl
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
typedef vector<int> vi;
typedef vector<ll> vl;

void solve()
{
    int i = 0, j = 0;
    vector<string> t(3);
    vector<char> v;
    bool present = false;
    for (int i = 0; i < 3; i++)
    {
        cin >> t[i];
    }
    int num_x = 0;
    int num_o = 0;
    int co = 0;
    int t_size = 9;
    for (int i = 0; i < 3; i++)
    {
        v.push_back(t[i][0]);
        v.push_back(t[i][1]);
        v.push_back(t[i][2]);
        // if( (t[i][0] == '_') || (t[i][1] == '_') || (t[i][2] == '_') ){
        //     present = true;
        // }
    }

    for (int i = 0; i < 9; ++i)
    {
        if (v[i] == *"X")
            num_x++;
        if (v[i] == *"O")
            num_o++;
        if (v[i] == *"_")
        {
            co++;
            t_size--;
            present = true;
        }
    }

    if ((num_x > 5) || (num_o > 4))
    {
        cout << 3 << endl;
        return;
    }

    if (num_x < num_o)
    {
        cout << 3 << endl;
        return;
    }
    if ((num_x - num_o) > 1)
    {
        cout << 3 << endl;
        return;
    }

    vi vw(8, 0);
    int win = 0;
    int wind = 0, winr = 0, winc = 0;
    int wino = 0, winx = 0;

    // if row is complete
    if ((v[0] == v[1]) && (v[1] == v[2]) && (v[0] != *"_"))
    {
        win++;
        winr++;
        vw[0]++;
        if (v[0] == *"X")
            winx++;
        else
            wino++;
    }
    // if row 2 is complete
    if ((v[3] == v[4]) && (v[4] == v[5]) && (v[3] != *"_"))
    {
        win++;
        winr++;
        vw[1]++;
        if (v[3] == *"X")
            winx++;
        else
            wino++;
    }
    // if row 3 is complete
    if ((v[6] == v[7]) && (v[7] == v[8]) && (v[6] != *"_"))
    {
        win++;
        winr++;
        vw[2]++;
        if (v[6] == *"X")
            winx++;
        else
            wino++;
    }

    // if d1 is complete
    if ((v[0] == v[4]) && (v[4] == v[8]) && (v[0] != *"_"))
    {
        win++;
        wind++;
        vw[3]++;
        if (v[0] == *"X")
            winx++;
        else
            wino++;
    }
    // if d2 is complete
    if ((v[2] == v[4]) && (v[4] == v[6]) && (v[2] != *"_"))
    {
        win++;
        wind++;
        vw[4]++;
        if (v[2] == *"X")
            winx++;
        else
            wino++;
    }
    // if c1 is complete
    if ((v[0] == v[3]) && (v[3] == v[6]) && (v[0] != *"_"))
    {
        win++;
        winc++;
        vw[5]++;
        if (v[0] == *"X")
            winx++;
        else
            wino++;
    }
    // if c2 is complete
    if ((v[1] == v[4]) && (v[4] == v[7]) && (v[1] != *"_"))
    {
        win++;
        winc++;
        vw[6]++;
        if (v[1] == *"X")
            winx++;
        else
            wino++;
    }
    // if c3 is complete
    if ((v[2] == v[5]) && (v[5] == v[8]) && (v[2] != *"_"))
    {
        win++;
        winc++;
        vw[7]++;
        if (v[2] == *"X")
            winx++;
        else
            wino++;
    }

    //  deb(winx);
    //  deb(wino);
    if (wino > 1)
    {
        cout << 3 << endl;
        return;
    }

    if (winx > 0 && num_x == num_o)
    {
        cout << 3 << endl;
        return;
    }

    if (winx > 0 && wino > 0)
    {
        cout << 3 << endl;
        return;
    }

    if (win > 2)
    {
        cout << 3 << endl;
        return;
    }

    if ((win == 1) && (wino == 1))
    {
        if (num_x > num_o)
        {
            cout << 3 << endl;
            return;
        }
    }

    if ((win == 2) && (winc == 1) && (winr == 1))
    {
        cout << 1 << endl;
        return;
    }
    if ((win == 2) && (winc == 1) && (wind == 1))
    {
        cout << 1 << endl;
        return;
    }
    if ((win == 2) && (winr == 1) && (wind == 1))
    {
        cout << 1 << endl;
        return;
    }
    if ((win == 2) && (wind == 1) && (wind == 1))
    {
        cout << 1 << endl;
        return;
    }

    // if ( (win == 1) && (wino == 1)){
    //     if(ca > cb){
    //         cout <<  3 << endl;
    //         return;
    //     }
    // }
    if (win == 1)
    {
        cout << 1 << endl;
        return;
    }
    // if((present == false) && (ca + cb == 9) ){
    //     cout << 1 << endl;
    //     return;
    // }
    if (num_x + num_o == 9)
    {
        cout << 1 << endl;
        return;
    }

    if ((win == 2) && (winc == 1) && (winc == 1))
    {
        cout << 3 << endl;
        return;
    }
    if ((win == 2) && (winr == 1) && (winr == 1))
    {
        cout << 3 << endl;
        return;
    }

    cout << 2 << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output2.out", "w", stdout);
    freopen("/media/psuv/Data/CP/output2.out", "w", stderr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}