#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int indexNode = 2;

typedef struct node {
    int data;
    short int height;
    int balance;
    int leftIndex;
    int rightIndex;
    struct node* left;
    struct node* right;
    node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
        balance = 0;
        leftIndex = rightIndex = 0;
    }
}binTree;

binTree* fillTree(int mas[][3], binTree** tree, int i) {
    binTree* root = new node(mas[i][0]);
    if (mas[i][1] != 0) {
        root->left = fillTree(mas, tree, mas[i][1]);
    }
    if (mas[i][2] != 0) root->right = fillTree(mas, tree, mas[i][2]);
    tree[i] = root;
    return root;
}

int Height(binTree* root) {
    int leftHeigh = 0, rightHeight = 0;
    if (root->left) leftHeigh = Height(root->left);
    if (root->right) rightHeight = Height(root->right);
    int height = ((leftHeigh > rightHeight) ? leftHeigh : rightHeight) + 1;
    root->height = height;
    root->balance = rightHeight - leftHeigh;
    return height;
}

binTree* rotateLeft(binTree* root) {
    binTree* node = root->right;
    root->right = node->left;
    node->left = root;
    return node;
}

binTree* rotateRight(binTree* root) {
    binTree* node = root->left;
    root->left = node->right;
    node->right = root;
    return node;
}

binTree* balance(binTree* root, binTree** tree) {
    ;
    if (root->balance == 2) {
        if (root->right->balance < 0) {
            root->right = rotateRight(root->right);
        }
        return rotateLeft(root);
    }
    return root;
}

void print(binTree* root, int level) {
    int left = 0, right = 0;
    if (root == nullptr)return;
    else {

        print(root->left, level - 1);
        if (level == 0) {
            if (root->left) left = indexNode++;
            if (root->right) right = indexNode++;
            cout << root->data << " " << left << " " << right << "\n";
        }
    }
    print(root->right, level - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int mas[n + 1][3];
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &mas[i][0], &mas[i][1], &mas[i][2]);
    }
    binTree* tree[n + 1];
    binTree* root = fillTree(mas, tree, 1);
    Height(root);
    root = balance(root, tree);
    int height = Height(root);
    cout << n << "\n";
    for (int i = 0; i < height; ++i) {
        print(root, i);
    }
    return 0;
}