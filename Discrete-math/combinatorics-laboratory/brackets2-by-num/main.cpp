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
void solve() {
    ll bal = 0, t = 0;
    string ans, opened;
    for (int i = 2 * n - 1; i >= 0; i--) {
        bool undone = true;
        updateT(i, t, bal);
        if (t > k) {
            open(ans, opened, '(', bal);
            undone = false;
        }
        if (undone) {
            k -= t;
            if (bal && sz(opened) && opened[sz(opened) - 1] == '(') {
                t = ((cnt[i][bal - 1]) << ((i - bal + 1) / 2));
            } else {
                t = 0;
            }
            if (t > k) {
                close(ans, opened, ')', bal);
                undone = false;
            }
            if (undone) {
                k -= t;
                updateT(i, t, bal);
                if (t > k) {
                    open(ans, opened, '[', bal);
                    undone = false;
                }
                if (undone) {
                    k -= t;
                    close(ans, opened, ']', bal);
                }
            }
        }
    }
    cout << ans;
}
int main() {
    freopen("num2brackets2.in", "r", stdin);
    freopen("num2brackets2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
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
