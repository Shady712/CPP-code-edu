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

int n, k;
int st = 1;
vector <int> code[200000];
void gen(int x) {
    if (x == n) {
        re;
    }
    int tmp = st;
    for (int i = 0; i < k; i++) {
        int id = st - 1;
        for (int j = 0; j < tmp; j++) {
            code[st + j] = code[id--];
        }
        st += tmp;
    }
    st -= tmp;
    int id = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < tmp; j++) {
            code[id++].pb(i);
        }
    }
    gen(x + 1);
}
int main() {
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        code[i].pb(i);
    }
    st = k;
    gen(1);
    for (int i = 0; i < st; i++) {
        for (int j : code[i]) {
            cout << j;
        }
        cout << "\n";
    }
}
