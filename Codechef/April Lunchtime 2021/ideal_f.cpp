#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+45;

int n,k,a;
int is_special[N];
vector <int> g[N];
int has_special[N];
int depth[N],closest[N],spnode[N];

void prep(int x,int par){
    has_special[x] |= is_special[x];

    int spn = 0;
    for(auto f : g[x]){
        if(f == par) continue;
        depth[f] = depth[x]+1;
        prep(f,x);
        has_special[x] |= has_special[f];
        if(has_special[f]) spn = spnode[f];
    }

    if(is_special[x]) spnode[x] = x;
    else spnode[x] = spn;
}

void dfs(int x,int par){
    if(has_special[x]) closest[x] = x;
    else closest[x] = closest[par];
    for(auto f : g[x]){
        if(f == par) continue;
        dfs(f,x);
    }
}

void solve(){
    cin >> n >> k >> a;
    for(int i = 1; i <= n; i++){
        g[i].clear();
        is_special[i] = depth[i] = closest[i] = has_special[i] = spnode[i] = 0;
    }

    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        is_special[x] = 1;
    }

    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth[a] = 0;
    prep(a,0);
    dfs(a,0);

    for(int i = 1; i <= n; i++){
        int maxval = 2*depth[closest[i]]-depth[i];
        cout << maxval;
        if(i < n) cout << " ";
        else cout << endl;
    }

    for(int i = 1; i <= n; i++){
        cout << spnode[closest[i]];
        if(i < n) cout << " ";
        else cout << endl;
    }
}

int main(){
    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("/media/psuv/Data/CP/input.in", "r", stdin);
    freopen("/media/psuv/Data/CP/output.out", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << endl
         << fixed
         << time_taken << setprecision(9) << " seconds" << endl;
}