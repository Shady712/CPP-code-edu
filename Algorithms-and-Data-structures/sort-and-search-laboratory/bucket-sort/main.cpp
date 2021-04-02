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

int n, A, B, k;
pair <int, vector <unsigned int> > buck[1000];
unsigned int* a;

unsigned int cur = 0;
unsigned int nextRand24() {
    cur = cur * A + B;
    re(cur >> 8);
}
unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    re(a << 8) ^ b;
}

int part(int id, int l, int r) {
    unsigned int x = buck[id].se[(l + r) / 2];
    swap(buck[id].se[(l + r) / 2], buck[id].se[r]);
    int i = l;
    for (int j = l; j <= r; j++) {
        if (buck[id].se[j] < x) {
            swap(buck[id].se[j], buck[id].se[i++]);
        }
    }
    swap(buck[id].se[i], buck[id].se[r]);
    re i;
}
void quicksort(int id, int l, int r) {
    if (l >= r) {
        re;
    }
    int c = part(id, l, r);
    quicksort(id, l, c - 1);
    quicksort(id, c + 1, r);
}
void bucketsort(int mn, unsigned int mx) {
    /*for (int i = 0; i < k; i++) {
        buck[i].clear();
    }*/
    unsigned int range = mx - mn;
    for (int i = 0; i < n; i++) {
        int id = (int)((ull)((ull)a[i] * (ull)k) / (ull)range);
        if (id >= k) {
            id = k - 1;
        }
        if (sz(buck[id].se) > buck[id].fi) {
            buck[id].se[buck[id].fi++] = a[i];
        } else {
            buck[id].fi++;
            buck[id].se.pb(a[i]);
        }
    }
    for (int i = 0; i < k; i++) {
        quicksort(i, 0, buck[i].fi - 1);
    }
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < buck[i].fi; j++) {
            a[cnt++] = buck[i].se[j];
        }
        buck[i].fi = 0;
    }
}

void solve() {
    unsigned int mn = 4294967295, mx = 0;
    for (int i = 0; i < n; i++) {
        a[i] = nextRand32();
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    bucketsort(mn, mx);
    ll ans = 0;
    for (ull i = 0; i < (ull)n; i++) {
        ans += (ull)a[i] * (ull)(i + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int quests;
    cin >> quests >> n >> A >> B;
    if (n == 1) {
        for (int i = 0; i < quests; i++) {
            unsigned int x = nextRand32();
            cout << x << "\n";
        }
        re 0;
    }
    a = new unsigned int[n];
    k = (int)sqrt(n);
    if (k * k != n) {
        k++;
    }
    while (quests--) {
        solve();
    }
}
