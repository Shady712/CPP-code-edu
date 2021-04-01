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


int main() {
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s;
    t = s;
    int id = sz(s) - 1;
    while (id >= 0 && s[id] == '0') {
        id--;
    }
    if (id < 0) {
        cout << "-\n";
    } else {
        s[id] = '0';
        for (int i = id + 1; i < sz(s); i++) {
            s[i] = '1';
        }
        cout << s << "\n";
    }
    id = sz(t) - 1;
    while (id >= 0 && t[id] == '1') {
        id--;
    }
    if (id < 0) {
        cout << "-";
    } else {
        t[id] = '1';
        for (int i = id + 1; i < sz(t); i++) {
            t[i] = '0';
        }
        cout << t;
    }
}
