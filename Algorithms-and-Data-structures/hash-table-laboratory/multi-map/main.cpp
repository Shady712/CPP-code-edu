#include <iostream>
#include <vector>

using namespace std;

const int N = 1e7 + 7;
const int n = 239;


struct val {
    string value;
    val* previous;
    val* next;
};

struct element {
    int count;
    string key;
    vector <val*> hashSet[n];
    val* last;

    int hashFunction(string value) {
        int id = 0;
        for (char i : value) {
            id = id * 239 + (int) i;
        }
        return abs(id + 17) % n;
    }

    int indexOf(string value, int id) {
        for (int i = 0; i < (int) hashSet[id].size(); i++) {
            if (hashSet[id][i] -> value == value) {
                return i;
            }
        }
        return -1;
    }

    void insert(string value) {
        int hf = hashFunction(value);
        int id = indexOf(value, hf);
        if (id == -1) {
            auto v = new val();
            v -> value = value;
            v -> previous = last;
            v -> next = nullptr;
            if (last != nullptr) {
                last -> next = v;
            }
            last = v;
            hashSet[hf].emplace_back(v);
            count++;
        }
    }

    void del(string value) {
        int hf = hashFunction(value);
        int id = indexOf(value, hf);
        if (id != -1) {
            auto previous = hashSet[hf][id] -> previous;
            auto next = hashSet[hf][id] -> next;
            if (previous != nullptr) {
                previous -> next = next;
            }
            if (next != nullptr) {
                next -> previous = previous;
            } else {
                last = previous;
            }
            swap(hashSet[hf][id], hashSet[hf][(int) hashSet[hf].size() - 1]);
            hashSet[hf].pop_back();
            count--;
        }
    }
};

vector <element*> hashSet[N];
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
        if (hashSet[id][i] -> key == key) {
            return i;
        }
    }
    return -1;
}

void get() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id == -1) {
        cout << "0\n";
    } else {
        cout << hashSet[hf][id] -> count << " ";
        val* cur = hashSet[hf][id] -> last;
        while (cur != nullptr) {
            cout << cur -> value << " ";
            cur = cur -> previous;
        }
        cout << "\n";
    }
}

void insert() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id == -1) {
        auto e = new element();
        e -> count = 0;
        e -> key = key;
        e -> last = nullptr;
        e -> insert(value);
        hashSet[hf].emplace_back(e);
    } else {
        hashSet[hf][id] -> insert(value);
    }
}

void del() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id != -1) {
        hashSet[hf][id] -> del(value);
    }
}

void deleteAll() {
    int hf = hashFunction();
    int id = indexOf(hf);
    if (id != -1) {
        for (int i = 0; i < n; i++) {
            hashSet[hf][id] -> hashSet -> clear();
        }
        hashSet[hf][id] -> last = nullptr;
        hashSet[hf][id] -> count = 0;
    }
}

string quest;
void solve() {
    cin >> key;
    if (quest == "put") {
        cin >> value;
        insert();
    } else if (quest == "delete") {
        cin >> value;
        del();
    } else if (quest == "deleteall") {
        deleteAll();
    } else if (quest == "get") {
        get();
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
