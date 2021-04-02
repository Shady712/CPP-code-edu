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
double A;
double get_ans(double x) {
    double pr = A, ans = x;
    for (int i = 2; i < n; i++) {
        double tmp = ans;
        ans = 2.0 * ans - pr + 2.0;
        pr = tmp;
        if (ans <= 0.0) {
            re ans;
        }
    }
    re ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> A;
    double l = 0.01, r = 1e12, ans = 1e18;
    while (r - l >= 0.0000001) {
        double c = (l + r) / 2.0;
        double t = get_ans(c);
        if (t > 0) {
            ans = t;
            r = c;
        } else {
            l = c;
        }
    }
    printf("%.2f", ans);
}
