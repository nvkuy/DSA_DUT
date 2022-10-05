#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 0, cur = 0;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    sort(b.begin(), b.end());
    while (true) {
        bool ic = false;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i]) ic = true;
        if (!ic)
            break;
        for (int i = cur; i + 1 < n; i += 2)
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        ans++, cur = 1 - cur;
    }
    cout << ans << endl;

    return 0;
}
