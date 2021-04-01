#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cstring>
#include <ctime>
#include <cassert>

#define pb emplace_back
#define pf emplace_front
#define re return
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_cxx;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <long long> vll;
typedef long double LD;

const ll MOD = 1e9 + 7;
const double pi = 3.14159265359;


int n;
void subset(vector <int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << "\n";
    if (v[sz(v) - 1] == n) {
        return;
    }
    for (int next = v[sz(v) - 1] + 1; next <= n; next++) {
        v.pb(next);
        subset(v);
        v.pop_back();
    }
}
int main() {
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        vector <int> v = {i};
        subset(v);
    }
}
