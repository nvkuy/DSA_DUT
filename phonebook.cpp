#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<string> arr(n);
    set<string> ss;
    bool iok = true;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (ss.find(arr[i]) != ss.end())
            iok = false;
        ss.insert(arr[i]);
    }
    for (int len = 1; len <= 10; len++) {
        ss.clear();
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (arr[i].size() == len)
                tmp.push_back(i);
            if (arr[i].size() > len)
                ss.insert(arr[i].substr(0, len));
        }
        for (int p : tmp)
            if (ss.find(arr[p]) != ss.end())
                iok = false;
    }
    cout << iok << endl;

    return 0;
}
