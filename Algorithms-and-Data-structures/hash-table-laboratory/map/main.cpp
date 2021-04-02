#include <iostream>
#include <vector>

using namespace std;

const int N = 1e7 + 7;

vector < pair <string, string> > hashSet[N];
string key, value;
int hashFunction() {
    int id = 0;
    for (char i : key) {
        id = id * 239 + (int) i;
    }
    return abs(id + 17) % N;
}

int indexOf(int id) {
    for (int i = 0; i < (int) hashSet[id].size(); i++) {
        if (hashSet[id][i].first == key) {
            return i;
        }
    }
    return -1;
}

string get() {
    int hf = hashFunction();
    int id = indexOf(hf);
    return id == -1 ? "none" : hashSet[hf][id].second;
}

void insert() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id == -1) {
        hashSet[hf].emplace_back(key, value);
    } else {
        hashSet[hf][id].second = value;
    }
}

void del() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id != -1) {
        swap(hashSet[hf][id], hashSet[hf][(int) hashSet[hf].size() - 1]);
        hashSet[hf].pop_back();
    }
}


string quest;
void solve() {
    cin >> key;
    if (quest == "put") {
        cin >> value;
        insert();
    } else if (quest == "delete") {
        del();
    } else if (quest == "get") {
        cout << get() << "\n";
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
