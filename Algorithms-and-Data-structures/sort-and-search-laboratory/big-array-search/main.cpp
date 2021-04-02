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

ll x, n = 1e18;
int m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> x >> m;
    n -= m;
    cout << "? 1" << endl;
    ll tmp;
    cin >> tmp;
    if (tmp == x) {
        cout << "! 1" << endl;
        re 0;
    }
    ll l, r;
    if (x > tmp) {
        l = 1 + (x - tmp);
        r = l;
        l -= m;
        l = max(2ll, l);
        r = min(n, r);
    } else {
        l = 1 + (x - tmp);
        l = n + l;
        r = l;
        r += m;
        r = min(r, n);
    }
    while (l <= r) {
        ll c = (l + r) / 2;
        cout << "? " << c << endl;
        cin >> tmp;
        if (tmp == x) {
            cout << "! " << c << endl;
            re 0;
        }
        if (tmp < x) {
            l = c + 1;
        } else {
            r = c - 1;
        }
    }
    cout << "! -1" << endl;
}
