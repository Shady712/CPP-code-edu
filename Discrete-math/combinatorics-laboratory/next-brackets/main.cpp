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
string s;
int open, close;
bool add(int i) {
    if (s[i] == ')') {
        close++;
        return false;
    } else {
        open++;
        return close > open;
    }
}
int main() {
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = sz(s) / 2;
    int id = -1;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (add(i)) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        cout << "-";
    } else {
        for (int i = 0; i < 2 * n - (open + close); i++) {
            cout << s[i];
        }
        cout << ")";
        close--;
        for (int i = 0; i < open; i++) {
            cout << "(";
        }
        for (int i = 0; i < close; i++) {
            cout << ")";
        }
    }
}
