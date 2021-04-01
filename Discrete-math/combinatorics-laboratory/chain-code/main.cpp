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
map <vector <bool>, bool> was;
int main() {
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector <bool> beg;
    for (int i = 0; i < n; i++) {
        beg.pb(0);
        cout << 0;
    }
    cout << "\n";
    was[beg] = true;
    vector <bool> v = beg;
    while (true) {
        vector <bool> t;
        for (int i = 1; i < n; i++) {
            t.pb(v[i]);
        }
        t.pb(1);
        if (was[t]) {
            t[n - 1] = 0;
        }
        if (t == beg) {
            break;
        }
        for (bool i : t) {
            cout << i;
        }
        was[t] = true;
        cout << "\n";
        v = t;
    }
}
