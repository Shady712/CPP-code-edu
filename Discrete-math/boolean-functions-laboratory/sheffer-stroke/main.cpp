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
string dp[100];
string And(string a, string b) {
    return "((" + a + "|" + b + ")|(" + a + "|" + b + "))";
}
string Or(string a, string b) {
    return "((" + a + "|" + a + ")|(" + b + "|" + b + "))";
}
string get_str(int n) {
    string ans;
    while (n) {
        ans += (n % 10) + 48;
        n /= 10;
    }
    reverse(all(ans));
    return ans;
}
string build(int id) {
    string an, bn;
    string t = get_str(id);
    an = "A" + t;
    bn = "B" + t;
    return "((" + dp[id - 1] + "|" + Or(an, bn) + ")|" + "(" + an + "|" + bn + "))";
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0] = "((A0|B0)|(A0|B0))";
    for (int i = 1; i < n; i++) {
        dp[i] = build(i);
    }
    cout << dp[n - 1];
}
