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

string t = "", last;
map <int, string> voc;
int code = 26, n, a[1000];
void fillVoc() {
    string word = "a";
    for (int i = 0; i < 26; i++) {
        voc[i] = word;
        word[0]++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fillVoc();
    last = voc[a[0]];
    cout << last;
    for (int i = 1; i < n; i++) {
        if (voc[a[i]] == "") {
            last += last[0];
            voc[a[i]] = last;
            code = max(code, a[i] + 1);
            cout << last;
        } else {
            string t = voc[a[i]];
            voc[code++] = last + t[0];
            last = t;
            cout << t;
        }
    }
}
