#include <iostream>
#include <set>
#include <vector>
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
bool a[2000];
struct elem {
    int type;
    int entry1;
    int entry2;
    elem(int x) {
        type = x;
        if (x == 1) {
            entry2 = 0;
        }
    }
};
vector <elem*> ans;
vector <int> con;

void bbuild(int k, int type) {
    if (k == 1) {
        re;
    }
    int Size = sz(ans);
    for (int i = Size - k + 1; i < Size; i += 2) {
        elem* e = new elem(type);
        e -> entry1 = i;
        e -> entry2 = i + 1;
        ans.pb(e);
    }
    bbuild(k / 2, type);
    if (k % 2) {
        elem* e = new elem(type);
        e -> entry1 = Size;
        e -> entry2 = sz(ans);
        ans.pb(e);
    }

}
void build(int x) {
    vector <int> v;
    int t = x;
    while (t) {
        v.pb(t % 2);
        t /= 2;
    }
    while (sz(v) < n) {
        v.pb(0);
    }
    reverse(all(v));
    for (int i = 1; i < n; i += 2) {
        elem* e = new elem(2);
        if (v[i - 1] && v[i]) {
            e -> entry1 = i;
            e -> entry2 = i + 1;
        }
        if (v[i - 1] && !v[i]) {
            e -> entry1 = i;
            e -> entry2 = i + 1 + n;
        }
        if (!v[i - 1] && v[i]) {
            e -> entry1 = i + n;
            e -> entry2 = i + 1;
        }
        if (!v[i - 1] && !v[i]) {
            e -> entry1 = i + n;
            e -> entry2 = i + 1 + n;
        }
        ans.pb(e);
    }
    bbuild(n / 2, 2);
    if (n % 2) {
        elem* e = new elem(2);
        if (v[n - 1]) {
            e -> entry1 = n;
        } else {
            e -> entry1 = 2 * n;
        }
        e -> entry2 = sz(ans);
        ans.pb(e);
    }
    con.pb(sz(ans));
}
void build_con() {
    for (int i = 1; i < sz(con); i += 2) {
        elem* e = new elem(3);
        e -> entry1 = con[i - 1];
        e -> entry2 = con[i];
        ans.pb(e);
    }
    if (sz(con) > 1) {
        bbuild(sz(con) / 2, 3);
        if (sz(con) % 2) {
            elem* e = new elem(3);
            e -> entry1 = con[sz(con) - 1];
            e -> entry2 = sz(ans);
            ans.pb(e);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    bool kek = true;
    for (int i = 0; i < (1 << n); i++) {
        string s;
        cin >> s >> a[i];
        if (a[i]) {
            kek = false;
        }
    }
    if (kek) {
        cout << n + 2 << "\n";
        cout << "1 1\n";
        cout << "2 1 " << n + 1;
        re 0;
    }
    for (int i = 0; i < n; i++) {
        elem* t = new elem(0);
        ans.pb(t);
    }
    for (int i = 0; i < n; i++) {
        elem* t = new elem(1);
        t -> entry1 = i + 1;
        ans.pb(t);
    }
    for (int i = 0; i < (1 << n); i++) {
        if (a[i]){
            build(i);
        }
    }
    build_con();
    cout << sz(ans) << "\n";
    for (int i = n; i < sz(ans); i++) {
        cout << ans[i] -> type << " " << ans[i] -> entry1;
        if (ans[i] -> type != 1) {
            cout << " " << ans[i] -> entry2;
        }
        cout << "\n";
    }
}
