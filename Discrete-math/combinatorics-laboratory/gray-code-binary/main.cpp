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
vector <bool> code[1000000];
void gen(int x) {
    if (x == n) {
        re;
    }
    int k = (1 << x) - 1;
    for (int i = (1 << x); i < 2 * (1 << x); i++) {
        code[i] = code[k--];
    }
    for (int i = 0; i < (1 << x); i++) {
        code[i].pb(0);
    }
    for (int i = (1 << x); i < 2 * (1 << x); i++) {
        code[i].pb(1);
    }
    gen(x + 1);
}
int main() {
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    code[0].pb(0);
    code[1].pb(1);
    gen(1);
    for (int i = 0; i < (1 << n); i++) {
        reverse(all(code[i]));
        for (bool j : code[i]) {
            cout << j;
        }
        cout << "\n";
    }
}
