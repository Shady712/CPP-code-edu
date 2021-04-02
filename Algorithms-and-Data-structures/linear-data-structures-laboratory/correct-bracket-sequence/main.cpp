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
    char value;
    List* next = NULL;
    List(char x) {
        value = x;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    while (cin >> s) {
        if (s[0] != '(' && s[0] != '[') {
            cout << "NO\n";
            continue;
        }
        bool ans = true;
        List* t = new List(s[0]);
        for (int i = 1; i < sz(s); i++) {
            if (s[i] == '(' || s[i] == '[') {
                List* New = new List(s[i]);
                New -> next = t;
                t = New;
            } else {
                if (t == NULL) {
                    ans = false;
                    break;
                }
                if ((t -> value == '(' && s[i] != ')') || (t -> value == '[' && s[i] != ']')) {
                    ans = false;
                    break;
                } else {
                    t = t -> next;
                }
            }
        }
        if (t != NULL) {
            ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
