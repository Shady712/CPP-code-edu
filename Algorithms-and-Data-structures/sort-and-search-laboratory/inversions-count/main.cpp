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

int n, m, A, B;
int a[1000000];
ll ans = 0;

unsigned int cur = 0;
unsigned int nextRand24() {
    cur = A * cur + B;
    re(cur >> 8);
}

void mergeArr(int l, int r) {
    int* b = new int[r - l];
    int c = (l + r) / 2;
    int i = l, j = c, ij = 0;
    while (i < c && j < r) {
        if (a[i] <= a[j]) {
            b[ij++] = a[i++];
        } else {
            ans += c - i;
            b[ij++] = a[j++];
        }
    }
    while (i < c) {
        b[ij++] = a[i++];
    }
    while (j < r) {
        b[ij++] = a[j++];
    }
    for (int i = l; i < r; i++) {
        a[i] = b[i - l];
    }
    delete b;
}
void mergesort(int l, int r) {
    if (l + 1 >= r) {
        re;
    }
    int c = (l + r) / 2;
    mergesort(l, c);
    mergesort(c, r);
    mergeArr(l, r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> A >> B;
    for (int i = 0; i < n; i++) {
        a[i] = (int)nextRand24() % m;
    }
    mergesort(0, n);
    cout << ans;
}
