#include <bits/stdc++.h>
using namespace std;
//int n,k;
vector<int> get(int n, int k, int req, int power, int curxor)
{

    vector<int> v(n + 1);
    if (k == 0)
        return v;
    if (k == 1)
    {
        v[req] = 1;
        return v;
    }
    if (k == 2)
    {
        //cout<<req<<' '<<k<<' '<<n<<'\n';
        if ((req % 4 == 1 || req % 4 == 3) && req - 1 <= n)
        {
            v[req - 1] = 1;
            v[1] = 1;
            return v;
        }
        else if ((req % 4 == 0 || req % 4 == 2) && req + 1 <= n)
        {
            v[req + 1] = 1;
            v[1] = 1;
            return v;
        }
    }
    int needxor = req;
    if (k > n / 2)
    {
        needxor = req ^ curxor;
        k = n - k;
        //cout<<n<<' '<<k<<' '<<needxor<<'\n';
        vector<int> last = get(n, k, needxor, power, curxor);
        for (int i = 0; i < last.size(); ++i)
            if (last[i] == 1)
                v[i] = 1;
        for (int i = 1; i <= n; ++i)
            v[i] = 1 - v[i];
    }
    else
    {

        int cur = (1 << power) - 1;
        if (needxor & (1 << power))
        {
            v[1 << power] = 1;
            needxor ^= (1 << power);
            --k;
            ++cur;
        }

        int cxor = 0, cnt = 0;
        vector<int> last = get((1 << power) - 1, k, needxor, power - 1, 0);
        for (int i = 1; i < last.size(); ++i)
        {
            if (last[i])
            {
                cxor ^= i;
                ++cnt;
            }
        }
        //cout<<n<<' '<<k<<' '<<req<<' '<<cxor<<' '<<cnt<<'\n';
        if (cxor != needxor || cnt != k)
        {
            v[cur + 1] = 1;
            v[cur + 2] = 1;
            k -= 2;
            needxor ^= (cur + 1);
            needxor ^= (cur + 2);
            last = get((1 << power) - 1, k, needxor, power - 1, 0);
            cxor = 0;
            cnt = 0;
            for (int i = 1; i < last.size(); ++i)
            {
                if (last[i])
                {
                    cxor ^= i;
                    ++cnt;
                }
            }
            if (cxor != needxor || cnt != k)
            {
                v[cur + 2] = 0;
                v[cur + 3] = 1;
                needxor ^= (cur + 2);
                needxor ^= (cur + 3);
                last = get((1 << power) - 1, k, needxor, power - 1, 0);
            }
        }
        for (int i = 0; i < last.size(); ++i)
            if (last[i] == 1)
                v[i] = 1;
    }
    return v;
}
int solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n << '\n';
        return n;
    }
    int tot = 0;
    for (int i = 1; i <= n; ++i)
        tot ^= i;
    if (n == k)
    {
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return tot;
    }
    if (k == n - 1)
    {
        int mx = -1, cur = -1;
        for (int i = 1; i <= n; ++i)
        {
            if ((tot ^ i) > mx)
            {
                mx = (tot ^ i);
                cur = i;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == cur)
                continue;
            cout << i << ' ';
        }
        cout << '\n';
        return mx;
    }
    int p = 1, cnt = 0;
    while (p <= n)
    {
        p *= 2;
        ++cnt;
    }
    --p;
    --cnt;
    if (tot == p && k == n - 2)
    {
        cout << 1 << ' ';
        for (int i = 4; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return tot - 1;
    }
    int x = 0;
    vector<int> ans = get(n, k, p, cnt, tot);
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i])
        {
            cout << i << ' ';
            x ^= i;
            ++cnt;
        }
    }
    cout << '\n';
    if (x != p || cnt != k)
    {
        cout << n << ' ' << k << '\n';
        exit(0);
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;
//int n,k;
vector<int> get(int n, int k, int req, int power, int curxor)
{

    vector<int> v(n + 1);
    if (k == 0)
        return v;
    if (k == 1)
    {
        v[req] = 1;
        return v;
    }
    if (k == 2)
    {
        //cout<<req<<' '<<k<<' '<<n<<'\n';
        if ((req % 4 == 1 || req % 4 == 3) && req - 1 <= n)
        {
            v[req - 1] = 1;
            v[1] = 1;
            return v;
        }
        else if ((req % 4 == 0 || req % 4 == 2) && req + 1 <= n)
        {
            v[req + 1] = 1;
            v[1] = 1;
            return v;
        }
    }
    int needxor = req;
    if (k > n / 2)
    {
        needxor = req ^ curxor;
        k = n - k;
        //cout<<n<<' '<<k<<' '<<needxor<<'\n';
        vector<int> last = get(n, k, needxor, power, curxor);
        for (int i = 0; i < last.size(); ++i)
            if (last[i] == 1)
                v[i] = 1;
        for (int i = 1; i <= n; ++i)
            v[i] = 1 - v[i];
    }
    else
    {

        int cur = (1 << power) - 1;
        if (needxor & (1 << power))
        {
            v[1 << power] = 1;
            needxor ^= (1 << power);
            --k;
            ++cur;
        }

        int cxor = 0, cnt = 0;
        vector<int> last = get((1 << power) - 1, k, needxor, power - 1, 0);
        for (int i = 1; i < last.size(); ++i)
        {
            if (last[i])
            {
                cxor ^= i;
                ++cnt;
            }
        }
        //cout<<n<<' '<<k<<' '<<req<<' '<<cxor<<' '<<cnt<<'\n';
        if (cxor != needxor || cnt != k)
        {
            v[cur + 1] = 1;
            v[cur + 2] = 1;
            k -= 2;
            needxor ^= (cur + 1);
            needxor ^= (cur + 2);
            last = get((1 << power) - 1, k, needxor, power - 1, 0);
            cxor = 0;
            cnt = 0;
            for (int i = 1; i < last.size(); ++i)
            {
                if (last[i])
                {
                    cxor ^= i;
                    ++cnt;
                }
            }
            if (cxor != needxor || cnt != k)
            {
                v[cur + 2] = 0;
                v[cur + 3] = 1;
                needxor ^= (cur + 2);
                needxor ^= (cur + 3);
                last = get((1 << power) - 1, k, needxor, power - 1, 0);
            }
        }
        for (int i = 0; i < last.size(); ++i)
            if (last[i] == 1)
                v[i] = 1;
    }
    return v;
}
int solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n << '\n';
        return n;
    }
    int tot = 0;
    for (int i = 1; i <= n; ++i)
        tot ^= i;
    // No elements can be excluded
    if (n == k)
    {
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return tot;
    }
    // Only one element can be excluded
    if (k == n - 1)
    {
        int mx = -1, cur = -1;
        for (int i = 1; i <= n; ++i)
        {
            if ((tot ^ i) > mx)
            {
                mx = (tot ^ i);
                cur = i;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i == cur)
                continue;
            cout << i << ' ';
        }
        cout << '\n';
        return mx;
    }
    int p = 1, numBits = 0;
    while (p <= n)
    {
        p *= 2;
        ++numBits;
    }
    --p;
    --numBits;
    if (tot == p && k == n - 2)
    {
        cout << 1 << ' ';
        for (int i = 4; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return tot - 1;
    }
    int x = 0;
    vector<int> ans = get(n, k, p, numBits, tot);
    numBits = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i])
        {
            cout << i << ' ';
            x ^= i;
            ++numBits;
        }
    }
    cout << '\n';
    if (x != p || numBits != k)
    {
        cout << n << ' ' << k << '\n';
        exit(0);
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}