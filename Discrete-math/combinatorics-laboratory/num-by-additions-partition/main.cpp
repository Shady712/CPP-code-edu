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

string s;
ll n, k;
ll cnt[200][200];
vector <int> input;

int parse(int& i) {
    int ans = 0;
    while (i < sz(s) && '0' <= s[i] && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0');
        i++;
    }
    return ans;
}
void parse() {
    for (int i = 0; i < sz(s); i++) {
        input.pb(parse(i));
    }
    n = accumulate(all(input), 0ll);
    k = sz(input);
}

void additive(vector <int> v, int sum, int last) {
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = last; j < input[i]; j++) {
            ans += cnt[n][j];
        }
        last = max(last, input[i]);
        n -= last;
    }
    cout << ans;
}
int main() {
    freopen("part2num.in", "r", stdin);
    freopen("part2num.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    parse();
    for (int i = 1; i <= n; i++) {
        cnt[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                for (int k = j; k <= i; k++) {
                    cnt[i][j] += cnt[i - j][k];
                }
            }
        }
    }
    vector <int> v;
    additive(v, n, 1);
}
