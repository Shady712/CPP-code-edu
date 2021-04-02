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

struct List {
    int value;
    List* next = NULL;
    List(int x) {
        value = x;
    }
};
bool isNumber(char x) {
    int ans = x - '0';
    if (ans >= 0 && ans <= 9) {
        re true;
    } else {
        re false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    getline(cin, s);
    List* t = new List(s[0] - '0');
    for (int i = 2; i < sz(s); i += 2) {
        if (isNumber(s[i])) {
            List* New = new List(s[i] - '0');
            New -> next = t;
            t = New;
        } else {
            if (s[i] == '+') {
                int ans = t -> value;
                t = t -> next;
                ans += t -> value;
                t = t -> next;
                List* New = new List(ans);
                New -> next = t;
                t = New;
            }
            if (s[i] == '-') {
                int ans = t -> value;
                t = t -> next;
                ans = t -> value - ans;
                t = t -> next;
                List* New = new List(ans);
                New -> next = t;
                t = New;
            }
            if (s[i] == '*') {
                int ans = t -> value;
                t = t -> next;
                ans *= t -> value;
                t = t -> next;
                List* New = new List(ans);
                New -> next = t;
                t = New;
            }
        }
    }
    cout << t -> value;
}