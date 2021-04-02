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

string a, b;
string ans;

void input() {
    a = b = "#";
    string s;
    cin >> s;
    a += s;
    cin >> s;
    b += s;
    if (sz(a) < sz(b)) {
        swap(a, b);
    }
}
int begin(int x, int y, bool rev) {
    return rev ? y - 1 : x;
}
bool condition(int i, int x, int y, bool rev) {
    if (rev) {
        return i >= x;
    } else {
        return i < y;
    }
}
int delta(bool rev) {
    return rev ? -1 : 1;
}
vector <int> lcs(int leftA, int rightA, int leftB, int rightB, bool rev) {
    vector <int> lcs[2];
    lcs[0].resize(sz(b) + 2);
    lcs[1].resize(sz(b) + 2);
    for (int i = begin(leftA, rightA, rev);
         condition(i, leftA, rightA, rev);
         i += delta(rev)) {
        for (int j = begin(leftB,  rightB, rev);
             condition(j, leftB, rightB, rev);
             j += delta(rev)) {
            if (a[i] == b[j]) {
                lcs[1][j] = lcs[0][j - delta(rev)] + 1;
            } else {
                lcs[1][j] = max(lcs[0][j], lcs[1][j - delta(rev)]);
            }
        }
        lcs[0] = lcs[1];
    }
    return lcs[1];
}
void hirschberg(int leftA, int rightA, int leftB, int rightB) {
    if (rightA - leftA == 1) {
        bool check = false;
        for (int i = leftB; i < rightB; i++) {
            if (b[i] == a[leftA]) {
                check = true;
                break;
            }
        }
        if (check) {
            ans += a[leftA];
        }
        return;
    }
    int c = (leftA + rightA - 1) / 2;
    vector<int> f = lcs(leftA, c + 1, leftB, rightB, false);
    vector<int> s = lcs(c + 1, rightA, leftB, rightB, true);
    int max = s[leftB], id = leftB;
    for (int j = leftB; j < rightB; j++) {
        int t = f[j];
        if (j + 1 < rightB + 1) {
            t += s[j + 1];
        }
        if (t > max) {
            max = t;
            id = j + 1;
        }
    }
    hirschberg(leftA, c + 1, leftB, id);
    hirschberg(c + 1, rightA, id, rightB);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input();
    hirschberg(1, sz(a), 1, sz(b));
    if (sz(ans) > 1 && ans[0] == '#') {
        ans = ans.substr(1);
    }
    cout << ans;
}
