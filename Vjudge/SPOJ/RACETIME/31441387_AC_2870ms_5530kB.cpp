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
            int bucket = pos / sq;
            etkhan2t[bucket].clear();
            for (int j = bucket * sq; j < n && j < (bucket + 1) * sq; ++j)
                etkhan2t[bucket].push_back(arr[j]);
            sort(etkhan2t[bucket].begin(), etkhan2t[bucket].end());
        } else {
            int st, en, x;
            scanf("%d%d%d", &st, &en, &x);
            --st, --en;
            int ans = 0;
            for (int j = st; j <= en; ++j) {
                if (j % sq == 0 && j + sq - 1 <= en) {
                    ans += upper_bound(etkhan2t[j / sq].begin(), etkhan2t[j / sq].end(), x) - etkhan2t[j / sq].begin();
                    j += sq - 1;
                } else if (arr[j] <= x) {
                    ++ans;
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
