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
};
struct req {
    int left;
    int right;
    int value;
};

int n, m;
snm a[300050];

int find_parent(int x) {
    if (a[x].parent == x) {
        return x;
    }
    return a[x].parent = find_parent(a[x].parent);
}
void unite(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x < y) {
        swap(x, y);
    }
    if (x != y) {
        a[y].parent = x;
    }
}
bool comp(req x, req y) {
    if (x.value == y.value) {
        if (x.left == y.left) {
            return x.right > y.right;
        }
        return x.left > y.left;
    }
    return x.value > y.value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n + 5; i++) {
        a[i].value = a[i].parent = i;
    }
    vector <req> reqs(m);
    for (int i = 0; i < m; i++) {
        cin >> reqs[i].left >> reqs[i].right >> reqs[i].value;
        reqs[i].left--;
        reqs[i].right--;
        reqs[i].value;
    }
    sort(all(reqs), comp);
    vector <int> ans(n);
    for (int &i : ans) {
        i = ((1 << 30) - 1) * 2 + 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = find_parent(reqs[i].left); j <= reqs[i].right; j = find_parent(j + 1)) {
            ans[j] = reqs[i].value;
            unite(j, j + 1);
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
}
