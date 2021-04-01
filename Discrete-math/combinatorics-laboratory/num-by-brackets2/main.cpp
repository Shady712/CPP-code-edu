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


ll n, k;
ll cnt[100][100];
string s;
map <char, char> op;
void updateT(int i, ll& t, ll bal) {
    if (bal < n) {
        t = ((cnt[i][bal + 1]) << ((i - bal - 1) / 2));
    } else {
        t = 0;
    }
}
void open(string& ans, string& opened, char c, ll& bal) {
    opened += c;
    ans += c;
    bal++;
}
void close(string& ans, string& opened, char c, ll& bal) {
    assert(opened[sz(opened) - 1] == op[c]);
    opened.erase(sz(opened) - 1, 1);
    ans += c;
    bal--;
}
/// tired of making nice code
void solve() {
    ll bal = 0, t = 0, ans = 0;
    string opened;
    for (int i = 0; i < 2 * n; i++) {
        bool undone = true;
        if (s[i] == '(') {
            bal++;
            opened += s[i];
            undone = false;
        }
        if (undone) {
            if (bal < n) {
                t = bal + 1;
                ans += ((cnt[2 * n - i - 1][t]) << ((2 * n - i - 1 - t) / 2));
            }
            if (s[i] == ')') {
                assert(opened[sz(opened) - 1] == '(');
                opened.erase(sz(opened) - 1, 1);
                bal--;
                undone = false;
            }
            if (undone) {
                if (bal && sz(opened) && opened[sz(opened) - 1] == '(') {
                    t = bal - 1;
                    ans += ((cnt[2 * n - i - 1][t]) << ((2 * n - i - 1 - t) / 2));
                }
                if (s[i] == '[') {
                    bal++;
                    opened += s[i];
                    undone = false;
                }
                if (undone) {
                    if (bal < n) {
                        ans += ((cnt[2 * n - i - 1][t]) << ((2 * n - i - 1 - t) / 2));
                    }
                    if (s[i] == ']') {
                        assert(opened[sz(opened) - 1] == '[');
                        opened.erase(sz(opened) - 1, 1);
                        bal--;
                        undone = false;
                    }
                }
            }
        }
    }
    cout << ans;
}
int main() {
    freopen("brackets2num2.in", "r", stdin);
    freopen("brackets2num2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = sz(s) / 2;
    op[')'] = '(';
    op[']'] = '[';
    cnt[0][0] = 1;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            cnt[i + 1][j] += cnt[i][j + 1];
            if (j < n) {
                cnt[i + 1][j + 1] += cnt[i][j];
            }
        }
    }
    solve();
}
