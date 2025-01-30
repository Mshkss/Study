#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

//возврат высоты узла
int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

//возврат баланса узла (разница высоты левого и правого поддерева)
int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return y;
}

Node* insert(Node* node, int key) { //вставка узла


    if (node == nullptr) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
//префиксный обход
void preOrder(Node* root) {
    if (root != nullptr) {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void mergeTrees(Node** result, Node* tree1, Node* tree2, Node* tree3, Node* tree4) {
    *result = insert(*result, tree1->key);
    *result = insert(*result, tree2->key);
    *result = insert(*result, tree3->key);
    *result = insert(*result, tree4->key);
}

int main() {
    setlocale(0, "");
    Node* root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 5);
    root1 = insert(root1, 15);

    Node* root2 = nullptr;
    root2 = insert(root2, 20);
    root2 = insert(root2, 25);
    root2 = insert(root2, 55);

    Node* root3 = nullptr;
    root3 = insert(root3, 30);
    root3 = insert(root3, 35);
    root3 = insert(root3, 40);

    Node* root4 = nullptr;
    root4 = insert(root4, 45);
    root4 = insert(root4, 50);

    Node* resultTree = nullptr;
    mergeTrees(&resultTree, root1, root2, root3, root4);

    std::cout << "Итоговое дерево: ";
    preOrder(resultTree);

    return 0;
}