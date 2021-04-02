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
    int parent;
    int val;
    int sz;
};
snm a[300050];
int n;

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
        a[y].parent = x;
        a[x].sz += a[y].sz;
    }
}
void ini(int x) {
    a[x].parent = a[x].val = x;
    a[x].sz = 1;
}
void get(int x) {
    x = find_parent(x);
    cout << x << "\n";
    int y = x + 1;
    if (y > n) {
        y = 1;
    }
    unite(y, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ini(i);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        get(x);
    }
}
