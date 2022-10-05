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

const double er = 1e-6;

bool cmpgrea(double a, double b) {
    return a - b > er;
}

bool cmpequa(double a, double b) {
    return abs(a - b) < er;
}

double dist(pair<long long, long long> p1, pair<long long, long long> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

vector<double> getEdges(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    vector<double> rs;
    rs.push_back(dist(p1, p2));
    rs.push_back(dist(p1, p3));
    rs.push_back(dist(p2, p3));
    return rs;
}

bool isTri(vector<double> &edges) {
    sort(edges.begin(), edges.end());
    return cmpgrea(edges[0] + edges[1], edges[2]);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, ans = 0;
    cin >> n;
    vector<pair<long long, long long>> cors(n);
    for (int i = 0; i < n; i++)
        cin >> cors[i].first >> cors[i].second;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                vector<double> tmp = getEdges(cors[i], cors[j], cors[k]);
                if (!isTri(tmp))
                    continue;
                if (cmpequa(tmp[0], tmp[1]) | cmpequa(tmp[1], tmp[2]))
                    ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
