#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, SQ = 320;

int arr[N], n, q;

vector<int> etkhan2t[SQ];

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    int sq = sqrt(n);

    for (int i = 0; i < n; ++i)
        etkhan2t[i / sq].push_back(arr[i]);

    for (int i = 0; i <= sq; ++i)
        sort(etkhan2t[i].begin(), etkhan2t[i].end());

    for (int i = 0; i < q; ++i) {
        char op;
        scanf(" %c", &op);
        if (op == 'M') {
            int pos, x;
            scanf("%d%d", &pos, &x);
            --pos;
            arr[pos] = x;
            etkhan2t[pos / sq].clear();
            for (int j = (pos / sq) * sq; j < n && j < (pos / sq + 1) * sq; ++j)
                etkhan2t[pos / sq].push_back(arr[j]);
            sort(etkhan2t[pos / sq].begin(), etkhan2t[pos / sq].end());
        } else {
            int st, en, x;
            scanf("%d%d%d", &st, &en, &x);
            --st, --en;
            int ans = 0, stq = st / sq, enq = en / sq;
            for (int j = stq + 1; j < enq; ++j) {
                ans += upper_bound(etkhan2t[j].begin(), etkhan2t[j].end(), x) - etkhan2t[j].begin();
            }
            if (stq == enq) {
                for (int j = st; j <= en; ++j) {
                    if (arr[j] <= x) {
                        ++ans;
                    }
                }
            } else {
                for (int j = st; j < (stq + 1) * sq; ++j) {
                    if (arr[j] <= x) {
                        ++ans;
                    }
                }
                for (int j = en; j >= enq * sq; --j) {
                    if (arr[j] <= x) {
                        ++ans;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
