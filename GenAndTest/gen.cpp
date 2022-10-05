#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    int n = 1e3;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), default_random_engine(seed));
    cout << n << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;

    return 0;
}
