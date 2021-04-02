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
    int segment;
};
int n;
snm a[200050];
int find_parent(int x, bool seg) {
    if (seg) {
        if (a[x].parent == x) {
            return x;
        }
        return a[x].parent = find_parent(a[x].parent, seg);
    } else {
        if (a[x].segment == x) {
            return x;
        }
        return a[x].segment = find_parent(a[x].segment, seg);
    }
}
void unite(int x, int y, bool seg) {
    x = find_parent(x, seg);
    y = find_parent(y, seg);
    if (x != y) {
        if (seg) {
            a[min(x, y)].parent = max(x, y);
        } else {
            a[min(x, y)].segment = max(x, y);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int quests;
    cin >> n >> quests;
    for (int i = 1; i <= n; i++) {
        a[i].value = a[i].parent = a[i].segment = i;
    }
    while (quests--) {
        int quest, x, y;
        cin >> quest >> x >> y;
        if (x > y) {
            swap(x, y);
        }

        if (quest == 1) {
            unite(x, y, true);
        }

        if (quest == 2) {
            int id = find_parent(x, false);
            while (id < y) {
                unite(id, id + 1, true);
                unite(id, id + 1, false);
                id = find_parent(++id, false);
            }
        }

        if (quest == 3) {
            cout << ((find_parent(x, true) == find_parent(y, true)) ? "YES" : "NO") << "\n";
        }
    }
}
