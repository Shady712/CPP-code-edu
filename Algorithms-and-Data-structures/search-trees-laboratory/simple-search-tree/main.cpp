#include <iostream>

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
    node(int x) {
        key = x;
        left = right = nullptr;
    }
};

node* root = nullptr;

int minimum(node* t) {
    return t -> left == nullptr ? t -> key : minimum(t -> left);
}
int maximum(node* t) {
    return t -> right == nullptr ? t -> key : maximum(t -> right);
}

node* next(int x) {
    node* cur = root;
    node* ans = nullptr;
    while (cur != nullptr) {
        if (cur -> key <= x) {
            cur = cur -> right;
        } else {
            ans = cur;
            cur = cur -> left;
        }
    }
    return ans;
}
node* prev(int x) {
    node* cur = root;
    node* ans = nullptr;
    while (cur != nullptr) {
        if (cur -> key < x) {
            ans = cur;
            cur = cur -> right;
        } else {
            cur = cur -> left;
        }
    }
    return ans;
}

node* insert(node* cur, int x) {
    if (cur == nullptr) {
        return new node(x);
    }

    if (cur -> key < x) {
        cur -> right = insert(cur -> right, x);
    }
    if (cur -> key > x) {
        cur -> left = insert(cur -> left, x);
    }

    return cur;
}
void insert(int x) {
    node* ans = insert(root, x);
    root = ans;
}

node* del(node* cur, int x) {
    if (cur == nullptr) {
        return nullptr;
    }

    if (cur -> key == x) {
        if (cur -> left == nullptr && cur -> right == nullptr) {
            return nullptr;
        }
        if (cur -> left == nullptr || cur -> right == nullptr) {
            if (cur -> left == nullptr) {
                return cur -> right;
            } else {
                return cur -> left;
            }
        }
        cur -> key = minimum(cur -> right);
        cur -> right = del(cur -> right, cur -> key);
        return cur;
    }

    if (cur -> key < x) {
        cur -> right = del(cur -> right, x);
        return cur;
    } else {
        cur -> left = del(cur -> left, x);
        return cur;
    }
}
void del(int x) {
    node* ans = del(root, x);
    root = ans;
}

bool exists(node* cur, int x) {
    if (cur == nullptr) {
        return false;
    }

    if (cur -> key == x) {
        return true;
    }

    if (cur -> key < x) {
        return exists(cur -> right, x);
    } else {
        return exists(cur -> left, x);
    }
}

int main() {
    string quest;
    while (cin >> quest) {
        int x;
        cin >> x;
        if (quest == "insert") {
            insert(x);
        } else if (quest == "delete") {
            del(x);
        } else if (quest == "exists") {
            cout << ((exists(root, x)) ? "true" : "false") << "\n";
        } else if (quest == "next") {
            node* ans = next(x);
            if (ans == nullptr) {
                cout << "none";
            } else {
                cout << ans -> key;
            }
            cout << "\n";
        } else if (quest == "prev") {
            node* ans = prev(x);
            if (ans == nullptr) {
                cout << "none";
            } else {
                cout << ans -> key;
            }
            cout << "\n";
        }
    }
}
