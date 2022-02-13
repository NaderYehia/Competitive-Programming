#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, SQ = 320;

int arr[N], n, q;
int sparse[30][N], lg[N];

void buildSparse() {
    lg[0] = -1;
    for (int i = 0; i < n; ++i) {
        sparse[0][i] = arr[i];
        lg[i + 1] = lg[i] + !((i + 1) & i);
    }
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j <= n - (1 << i); ++j) {
            int a = sparse[i - 1][j];
            int b = sparse[i - 1][j + (1 << (i - 1))];
            sparse[i][j] = __gcd(a, b);
        }
    }
}

int query(int qs, int qe) {
    int sz = qe - qs + 1;
    int l = lg[sz];
    int a = sparse[l][qs];
    int b = sparse[l][qe - (1 << l) + 1];
    return __gcd(a, b);
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    buildSparse();

    map<int, long long> mp;
    for (int i = 0; i < n; ++i) {
        int cur = arr[i], id = i;
        while (id < n) {
            int lo = id, hi = n - 1, md;
            while (lo < hi) {
                md = lo + (hi - lo + 1) / 2;
                if (query(i, md) < cur) hi = md - 1;
                else lo = md;
            }
            mp[cur] += lo - id + 1;
            cur = query(i, lo + 1);
            id = lo + 1;
        }
    }

    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", mp[x]);
    }

    return 0;
}
