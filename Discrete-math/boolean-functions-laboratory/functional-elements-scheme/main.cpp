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

struct func {
    int m;
    vector <int> entry;
    vector <int> value;
    func(int x) {
        m = x;
    }
};
int n;
int out;
vector <int> v[30];
vector <int> var;
vector <func*> fs(30);
int depth;
int d[30];
vector <bool> ans;
int was[30];
vector <bool> tmp(30);
void dfs(int x) {
    assert(clock() < 1500);
    for (int y : v[x]) {
        if (d[y] == -1) {
            d[y] = d[x] + 1;
            dfs(y);
        } else {
            if (d[x] + 1 > d[y]) {
                d[y] = d[x] + 1;
                dfs(y);
            }
        }
    }
}
int bfs(int apex) {
    memset(d, -1, sizeof(d));
    d[apex] = 0;
    dfs(apex);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, d[i]);
    re ans;
}
bool get_ans(int apex) {
    if (fs[apex] == NULL) {
        re tmp[apex];
    }
    if (was[apex] != -1) {
        re was[apex];
    }
    vector <bool> cur;
    for (int i : fs[apex] -> entry) {
        cur.pb(get_ans(i));
    }
    int t = 0;
    for (bool i : cur) {
        t = t * 2 + i;
    }
    re was[apex] = (fs[apex] -> value[t]);
}
bool solve() {
    memset(was, -1, sizeof(was));
    re get_ans(out);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (!m) {
            var.pb(i);
            fs[i] = NULL;
        } else {
            func* f = new func(m);
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                x--;
                f -> entry.pb(x);
                v[x].pb(i);
            }
            for (int j = 0; j < (1 << m); j++) {
                int x;
                cin >> x;
                f -> value.pb(x);
            }
            fs[i] = f;
        }
    }
    for (int i = 0; i < sz(var); i++) {
        depth = max(depth, bfs(var[i]));
    }
    cout << depth << "\n";
    out = n - 1;
    for (int i = 0; i < (1 << sz(var)); i++) {
        vector <bool> x(sz(var));
        int k = i, id = 0;
        while (k) {
            x[id++] = k % 2;
            k /= 2;
        }
        reverse(all(x));
        for (int i = 0; i < sz(var); i++)
            tmp[var[i]] = x[i];
        ans.pb(solve());
    }
    for (bool i : ans)
        cout << i;
}
