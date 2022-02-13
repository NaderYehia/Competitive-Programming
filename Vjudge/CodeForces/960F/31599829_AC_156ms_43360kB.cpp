#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct node {
    int best;
    node *left, *right;

    node(int best = 0) {
        this->best = best;
        left = right = NULL;
    }
} *tree[4 * N];

int query(int qs, int qe, node *&cur, int ss = 0, int se = N) {
    if (ss > qe || se < qs || cur == NULL) return 0;
    if (ss >= qs && se <= qe) return cur->best;
    int md = ss + (se - ss) / 2;
    return max(query(qs, qe, cur->left, ss, md), query(qs, qe, cur->right, md + 1, se));
}

void update(int qi, int qv, node *&cur, int ss = 0, int se = N) {
    if (ss > qi || se < qi) return;
    if (cur == NULL) cur = new node(qv);
    cur->best = max(cur->best, qv);
    if (ss == se) return;
    int md = ss + (se - ss) / 2;
    update(qi, qv, cur->left, ss, md);
    update(qi, qv, cur->right, md + 1, se);
}


int n, m;

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d", &n, &m);
    int best = 1;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        int cur = query(0, c - 1, tree[u]) + 1;
        best = max(best, cur);
        update(c, cur, tree[v]);
    }
    printf("%d\n", best);

    return 0;
}