#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 2e6 + 10;

struct ADJ {
    int head[N], nxt[2 * N], to[2 * N], ne;

    void init() {
        memset(head, -1, sizeof head);
        ne = 0;
    }

    void addedge(int u, int v) {
        nxt[ne] = head[u];
        to[ne] = v;
        head[u] = ne++;
    }

    void addbiedge(int u, int v) {
        addedge(u, v);
        addedge(v, u);
    }
} adj;

int n, m, color[N], qs[N], qe[N], qk[N], qi[N], qAns[N], freq[N], tree[N], col[N], sq, s, e;
int st[N], en[N], dfstime;

void dfs(int u, int par) {
    col[st[u] = dfstime++] = color[u];
    for (int e = adj.head[u]; ~e; e = adj.nxt[e]) {
        int v = adj.to[e];
        if (v == par) continue;
        dfs(v, u);
    }
    en[u] = dfstime - 1;
}


void update(int i, int v) {
    for (; i < N; i += i & -i)
        tree[i] += v;
}

int get(int i) {
    int ret = 0;
    for (; i; i -= i & -i)
        ret += tree[i];
    return ret;
}

void add(int val) {
    ++freq[val];
    update(freq[val], 1);
    update(freq[val] + 1, -1);
}

void del(int val) {
    update(freq[val], -1);
    update(freq[val] + 1, 1);
    --freq[val];
}

void updateSE(int idx) {
    while (e < qe[idx] + 1) add(col[e++]);
    while (e > qe[idx] + 1) del(col[--e]);
    while (s < qs[idx]) del(col[s++]);
    while (s > qs[idx]) add(col[--s]);
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", color + i);

    adj.init();
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        adj.addbiedge(u, v);
    }

    dfs(0, -1);

    for (int i = 0; i < m; ++i) {
        int v, k;
        scanf("%d%d", &v, &k);
        --v;
        qs[i] = st[v], qe[i] = en[v], qk[i] = k;
        qi[i] = i;
    }

    sq = sqrtl((n * 1ll * n) / m) + 10;
    sort(qi, qi + m, [](int i, int j) {
        return make_pair(qs[i] / sq, qe[i]) < make_pair(qs[j] / sq, qe[j]);
    });

    for (int i = 0; i < m; ++i) {
        updateSE(qi[i]);
        qAns[qi[i]] = get(qk[qi[i]]);
    }

    for (int i = 0; i < m; ++i)
        printf("%d\n", qAns[i]);

    return 0;
}