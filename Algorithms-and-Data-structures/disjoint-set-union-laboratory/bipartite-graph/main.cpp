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
    bool color;
};

int n;
snm a[200050];

int find_parent(int x, bool& col) {
    col ^= !a[x].color;
    if (a[x].parent == x) {
        return x;
    }
    col = !col;
    return find_parent(a[x].parent, col);
}
void unite(int x, int y) {
    bool colx, coly;
    colx = coly = false;
    x = find_parent(x, colx);
    y = find_parent(y, coly);
    if (x != y) {
        if (a[x].sz < a[y].sz) {
            swap(x, y);
        }
        a[y].parent = x;
        a[x].sz += a[y].sz;
        if (colx == coly) {
            a[y].color = !a[y].color;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].value = a[i].parent = i;
        a[i].sz = 1;
        a[i].color = false;
    }
    int quests;
    cin >> quests;
    int shift = 0;
    while (quests--) {
        int q, x, y;
        cin >> q >> x >> y;
        x += shift;
        y += shift;
        x %= n;
        y %= n;
        if (!q) {
            unite(x, y);
        } else {
            bool colx, coly;
            colx = coly = false;
            x = find_parent(x, colx);
            y = find_parent(y, coly);
            if (x == y) {
                if (colx == coly) {
                    shift++;
                    shift %= n;
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "YES\n";
            }
        }
    }
}
