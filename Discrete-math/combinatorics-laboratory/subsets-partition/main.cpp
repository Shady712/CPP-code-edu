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
int cur[15];
void part(int t, int cnt) {
    if (t == n) {
        if (cnt == k) {
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    if (cur[j] == i) {
                        cout << j + 1 << " ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < cnt; i++) {
        cur[t] = i;
        part(t + 1, cnt);
    }
    cur[t] = cnt;
    part(t + 1, cnt + 1);

}
int main() {
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    part(0, 0);
}
