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

int n;
int a[100000];
void merge_arr(int* a, int l, int r) {
    int* b = new int[r - l];
    int c = (l + r) / 2;
    int i = l, j = c, k = 0;
    while (i < c && j < r) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i < c) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int i = l; i < r; i++) {
        a[i] = b[i - l];
    }
}
void merge_sort(int* a, int l, int r) {
    if (r - l > 1) {
        int c = (l + r) / 2;
        merge_sort(a, l, c);
        merge_sort(a, c, r);
        merge_arr(a, l, r);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    for (int iii = 0; iii < q; iii++) {
        int x;
        cin >> x;
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int c = (l + r) / 2;
            if (a[c] >= x) {
                ans = c;
                r = c - 1;
            } else {
                l = c + 1;
            }
        }
        if (ans == -1 || a[ans] != x) {
            cout << "-1 -1\n";
            continue;
        }
        cout << ans + 1 << " ";
        l = 0;
        r = n - 1;
        ans = -1;
        while (l <= r) {
            int c = (l + r) / 2;
            if (a[c] <= x) {
                ans = c;
                l = c + 1;
            } else {
                r = c - 1;
            }
        }
        cout << ans + 1 << "\n";
    }
}
