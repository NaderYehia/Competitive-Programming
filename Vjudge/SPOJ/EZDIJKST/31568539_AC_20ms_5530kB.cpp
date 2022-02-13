#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10, M = 1e5 + 10, inf = 0x3f3f3f3f, offset = 50000;

int head[N], nxt[N], to[N], cost[N], ne;

void addedge(int u, int v, int c) {
    nxt[ne] = head[u];
    to[ne] = v;
    cost[ne] = c;
    head[u] = ne++;
}

int dis[N];

int dijkstra(int src, int dest) {
    memset(dis, '?', sizeof dis);
    priority_queue<pair<int, int> > pq;
    dis[src] = 0;
    pq.push({0, src});
    while (pq.size()) {
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dis[u] != d) continue;
        for (int e = head[u]; ~e; e = nxt[e]) {
            int v = to[e], c = cost[e];
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                pq.push({-(d + c), v});
            }
        }
    }
    return dis[dest];
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        memset(head, -1, sizeof head);
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            addedge(u, v, c);
        }
        int src, dest;
        scanf("%d%d", &src, &dest);
        int ans = dijkstra(src, dest);
        if (ans == 0x3f3f3f3f) puts("NO");
        else printf("%d\n", ans);
    }

    return 0;
}