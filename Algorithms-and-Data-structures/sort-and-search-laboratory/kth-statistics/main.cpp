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

int n, k, A, B, C;
int a[30000000];

pair <int, int> part(int l, int r) {
    int x = a[(l + r) / 2];
    swap(a[(l +r) / 2], a[r]);
    int i = l;
    for (int j = l; j <= r; j++) {
        if (a[j] < x) {
            swap(a[j], a[i++]);
        }
    }
    swap(a[i], a[r]);
    pair <int, int> ans;
    ans.fi = i;
    while (i <= r && a[i] == x) {
        i++;
    }
    ans.se = i - 1;
    re ans;
}

void quicksort(int l, int r) {
    if (l >= r) {
        re;
    }
    pair <int, int> c = part(l, r);
    if (c.fi <= k && k <= c.se) {
        re;
    }
    if (k < c.fi) {
        quicksort(l, c.fi - 1);
    } else {
        quicksort(c.se + 1, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> A >> B >> C >> a[0] >> a[1];
    k--;
    for (int i = 2; i < n; i++) {
        a[i] = A * a[i - 2] + B * a[i - 1] + C;
    }
    quicksort(0, n - 1);
    cout << a[k];
}
