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

int n, m, k;
string s[1000];
void radixSort(int id) {
    if (id + 1 == m - k) {
        re;
    }
    vector <string> v[26];
    for (int i = 0; i < n; i++) {
        v[s[i][id] - 'a'].pb(s[i]);
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        for (string j : v[i]) {
            s[cnt++] = j;
        }
    }
    radixSort(id - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    radixSort(m - 1);
    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
}
