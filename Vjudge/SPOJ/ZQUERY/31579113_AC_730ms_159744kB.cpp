#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, SQ = 225, offset = 50000;

int n, m, arr[N], prv[N], ans[SQ][N], last[SQ][N], mp[N];

void precompute() {
    memset(mp, -1, sizeof mp);
    for (int i = 0; i <= n; ++i) {
        prv[i] = mp[arr[i]];
        mp[arr[i]] = i;
    }

    memset(last, -1, sizeof last);
    for (int i = 0; i <= n; i += SQ) {
        for (int j = 0; j < i + SQ; ++j) {
            last[i / SQ][arr[j]] = j;
        }
    }

    for (int i = 0; i <= n; i += SQ) {
        int best = 0;
        memset(mp, -1, sizeof mp);
        for (int j = i; j <= n; ++j) {
            if (~mp[arr[j]]) {
                best = max(best, j - mp[arr[j]]);
            } else {
                mp[arr[j]] = j;
            }
            ans[i / SQ][j] = best;
        }
    }
}

int main() {

    //freopen("meciul.in", "r", stdin);
    //freopen("meciul.out", "w", stdout);

    scanf("%d%d", &n, &m);
    arr[0] = offset;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
        arr[i] += arr[i - 1];
    }

    precompute();

    for (int i = 0; i < m; ++i) {
        int st, en;
        scanf("%d%d", &st, &en);
        --st;
        int stBlock = st / SQ;
        int enBlock = en / SQ;
        if (stBlock == enBlock) {
            int best = 0;
            for (int j = st; j <= en; ++j) {
                if (prv[j] >= st) continue;
                int cur = last[enBlock][arr[j]];
                while (cur > en) {
                    cur = prv[cur];
                }
                best = max(best, cur - j);
            }
            printf("%d\n", best);
            continue;
        }
        ++stBlock;
        int answer = ans[stBlock][en];
        for (int j = st; j < stBlock * SQ; ++j) {
            if (prv[j] >= st) continue;
            int cur = last[enBlock][arr[j]];
            while (cur > en) {
                cur = prv[cur];
            }
            answer = max(answer, cur - j);
        }
        printf("%d\n", answer);
    }

    return 0;
}
