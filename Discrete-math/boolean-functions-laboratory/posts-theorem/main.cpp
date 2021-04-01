#include <iostream>
#include <set>
#include <vector>
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
pair <int, string> a[1000];
bool zero = true;
bool one = true;
bool self = true;
bool mono = true;
bool linear = true;
bool dominate(int x, int y) {
    while (x || y) {
        if (x % 2 < y % 2) {
            re false;
        }
        x /= 2;
        y /= 2;
    }
    re true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < n; i++) {
        if (a[i].se[0] == '1') {
            zero = false;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i].se[(1 << a[i].fi) - 1] == '0') {
            one = false;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << a[i].fi); j++) {
            if (a[i].se[j] == a[i].se[(1 << a[i].fi) - 1 - j]) {
                self = false;
                break;
            }
        }
        if (!self) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << a[i].fi); j++) {
            for (int k = j + 1; k < (1 << a[i].fi); k++) {
                if (dominate(k, j) && a[i].se[k] < a[i].se[j]) {
                    mono = false;
                    break;
                }
            }
            if (!mono) {
                break;
            }
        }
        if (!mono) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << a[i].fi); j++) {
            bool t = false;
            for (int k = 0; k < (1 << a[i].fi); k++) {
                if (dominate(j, k)) {
                    if (a[i].se[k] == '1')
                        t ^= 1;
                }
            }
            if (t && __builtin_popcount(j) > 1) {
                linear = false;
                break;
            }
        }
        if (!linear) {
            break;
        }
    }
    cout << (zero || one || self || mono || linear ? "NO" : "YES");
}
