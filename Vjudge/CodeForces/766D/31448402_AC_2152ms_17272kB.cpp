#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, M = 750;

int head[N], nxt[N], to[N], wt[N], ne;

void addedge(int u, int v, int c) {
    nxt[ne] = head[u];
    to[ne] = v;
    wt[ne] = c;
    head[u] = ne++;
}

void addbiedge(int u, int v, int c) {
    addedge(u, v, c);
    addedge(v, u, c);
}

int n, m, q;
bool suspend[N];
map<string, int> mp;

int par[N], sz[N];

void init() {
    iota(par, par + n, 0);
    fill(sz, sz + n, 1);
    memset(head, -1, sizeof head);
}

int p(int u) {
    return par[u] == u ? u : par[u] = p(par[u]);
}

bool join(int u, int v) {
    u = p(u);
    v = p(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return 1;
}

bool vis[N], cum[N];

void dfs(int u, bool cur) {
    vis[u] = 1;
    cum[u] = cur;
    for (int e = head[u]; ~e; e = nxt[e]) {
        int v = to[e], c = wt[e];
        if (!vis[v]) {
            dfs(v, cur ^ c);
        }
    }
}

bool ans[N];
int qans[N], ops[N], U[N], V[N];

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        mp[x] = i;
    }

    init();

    for (int i = 0; i < m; ++i) {
        int op;
        string x, y;
        cin >> op >> x >> y;
        int u = mp[x], v = mp[y];
        if (join(u, v)) {
            addbiedge(u, v, op - 1);
            ans[i] = 1;
        } else {
            suspend[i] = 1;
            ops[i] = op;
            U[i] = u;
            V[i] = v;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (p(i) == i) {
            dfs(i, 0);
        }
    }

    for (int i = 0; i < q; ++i) {
        string x, y;
        cin >> x >> y;
        int u = mp[x], v = mp[y];
        if (p(u) != p(v)) {
            qans[i] = 3;
        } else {
            qans[i] = (cum[u] ^ cum[v]) + 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (suspend[i]) {
            int u = U[i], v = V[i];
            if ((cum[u] ^ cum[v]) + 1 == ops[i]) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
        cout << (ans[i] ? "YES\n" : "NO\n");
    }

    for (int i = 0; i < q; ++i)
        cout << qans[i] << endl;

    return 0;
}
