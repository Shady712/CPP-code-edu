#include <iostream>
#include <vector>

using namespace std;

const int N = 1e7 + 7;

vector <int> hashSet[N];

int hashFunction(int x) {
    return abs(x + 17) % N;
}

int indexOf(int x, int id) {
    for (int i = 0; i < (int) hashSet[id].size(); i++) {
        if (hashSet[id][i] == x) {
            return i;
        }
    }
    return -1;
}

bool exists(int x) {
    return indexOf(x, hashFunction(x)) != -1;
}

void insert(int x) {
    if (exists(x)) {
        return;
    }
    hashSet[hashFunction(x)].emplace_back(x);
}

void del(int x) {
    int hf = hashFunction(x);
    int id = indexOf(x, hf);
    if (id != -1) {
        swap(hashSet[hf][id], hashSet[hf][(int)hashSet[hf].size() - 1]);
        hashSet[hf].pop_back();
    }
}


string quest;
void solve() {
    int x;
    cin >> x;
    if (quest == "insert") {
        insert(x);
    } else if (quest == "exists") {
        string ans = (exists(x) ? "true" : "false");
        cout << ans << "\n";
    } else if (quest == "delete") {
        del(x);
    } else {
        throw invalid_argument("Unsupported operation");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> quest) {
        solve();
    }
}
