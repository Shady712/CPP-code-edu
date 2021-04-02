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

struct snm {
    int value;
    int parent;
    int sz;
};
struct quest {
    string type;
    int v;
    int u;
};

int n, m, k;
snm a[50050];

int find_parent(int x) {
    if (a[x].parent == x) {
        return x;
    }
    return a[x].parent = find_parent(a[x].parent);
}
void unite(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x != y) {
        if (a[x].sz < a[y].sz) {
            swap(x, y);
        }
        a[y].parent = x;
        a[x].sz += a[y].sz;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        a[i].value = a[i].parent = i;
        a[i].sz = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
    }
    vector <quest> quests;
    for (int iii = 0; iii < k; iii++) {
        string q;
        int x, y;
        cin >> q >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        quest t;
        t.type = q;
        t.v = x;
        t.u = y;
        quests.pb(t);
    }
    vector <bool> ans;
    for (int i = k - 1; i >= 0; i--) {
        if (quests[i].type == "cut") {
            unite(quests[i].v, quests[i].u);
        } else {
            ans.pb(((find_parent(quests[i].v) == find_parent(quests[i].u)) ? true : false));
        }
    }
    reverse(all(ans));
    for (bool i : ans) {
        cout << (i ? "YES" : "NO") << "\n";
    }
}
