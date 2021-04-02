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
List* create() {
    char c;
    int x;
    cin >> c >> x;
    re new List(x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    List* t = create();
    List* last = t;
    q--;
    for (int iii = 0; iii < q; iii++) {
        if (t == NULL) {
            last = t = create();
            continue;
        }
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            List* newList = new List(x);
            last -> next = newList;
            last = newList;
        } else {
            cout << t -> value << "\n";
            t = t -> next;
        }
    }
}
