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
vector <bool> a[10];
vector <bool> s;
string ans;
string solve(int id) {
    string t;
    vector <bool> v;
    for (int i = 0; i < 2 * n; i++) {
        if (a[i][id]) {
            if (sz(t)) {
                t += "&";
            } else {
                v = a[i];
            }
            if (i >= n) {
                t += "~";
            }
            int num = i % n;
            num++;
            t += num + '0';
            for (int j = 0; j < 33; j++) {
                v[j] = (v[j] & a[i][j]);
            }
        }
    }
    if (!sz(v)) {
        re "-1";
    }
    for (int i = 0; i < 33; i++) {
        if (v[i] && !s[i]) {
            re "-1";
        }
    }
    re t;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        ll x;
        cin >> x;
        if (i < n) {
            while (x) {
                a[i].pb(x % 2);
                x /= 2;
            }
            while (sz(a[i]) < 33) {
                a[i].pb(0);
            }
        } else {
            if (!x) {
                cout << "(1&~1)";
                re 0;
            }
            if (x < 0) {
                cout << "Impossible";
                re 0;
            }
            while (x) {
                s.pb(x % 2);
                x /= 2;
            }
            while (sz(s) < 33) {
                s.pb(0);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 33; j++) {
            a[i + n].pb(!a[i][j]);
        }
    }
    for (int i = 0; i < 33; i++) {
        if (s[i]) {
            string t = solve(i);
            if (t == "-1") {
                cout << "Impossible";
                re 0;
            }
            ans += "(" + t + ")";
        }
    }
    cout << ans[0];
    for (int i = 1; i < sz(ans); i++) {
        if (ans[i] == '(' && ans[i - 1] == ')') {
            cout << "|";
        }
        cout << ans[i];
    }
}
