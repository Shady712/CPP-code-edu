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

int n, k = 0;
pair <int, int> a[70000];
int ans[70000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i] = {0, i};
    }
    int r = n - 1;
    while (r >= 0) {
        k++;
        int c = r / 2;
        a[c].fi = n - k + 1;
        swap(a[c], a[r]);
        r--;
    }
    for (int i = 0; i < n; i++) {
        ans[a[i].se] = a[i].fi;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
