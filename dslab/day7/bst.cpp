#include <iostream>
using namespace std;

class Tree {
    int val;
    Tree *left;
    Tree *right;
public:
    Tree(int v1, Tree *l, Tree *r) {
        val = v1;
        left = l;
        right = r;
    }

    void insert(int v) {
        Tree *t = new Tree(v, NULL, NULL);
        Tree *curr = this;
        while (curr) {
            if (curr->val > v) {
                if (curr->left)
                    curr = curr->left;
                else {
                    curr->left = t;
                    break;
                }
            } else {
                if (curr->right)
                    curr = curr->right;
                else {
                    curr->right = t;
                    break;
                }
            }
        }
    }

    Tree *getNodeAndParent(int v, Tree **parent) {
        Tree *node = this;
        while (node) {
            Tree *past = node;
            if (node->val > v)
                node = node->left;
            else if (node->val < v)
                node = node->right;
            else return node;
            *parent = past;
        }
        return NULL;
    }

    void deleteNode(int v) {
        Tree *parent;
        Tree *node = getNodeAndParent(v, &parent);

        if (!node) {
            cout << "Node with value " << v << " not found" << endl;
            return;
        }

        if (!node->left && !node->right) {
            if (parent->left == node) parent->left = NULL;
            else parent->right = NULL;
            delete node;
        } else if (!node->left) {
            if (parent->left == node) parent->left = node->right;
            else parent->right = node->right;
            delete node;
        } else if (!node->right) {
            if (parent->left == node) parent->left = node->left;
            else parent->right = node->left;
            delete node;
        } else {
            Tree *temp = node;
            while (temp->left)
                temp = temp->left;
            int temp_val = temp->val;
            deleteNode(temp->val);
            node->val = temp_val;
        }
    }

    void findNode(int v) {
        Tree *parent;
        Tree *node = getNodeAndParent(v, &parent);

        if (node) {
            cout << "True" << endl;
            if (parent) cout << "Parent node: " << parent->val << endl;
            if (node->left || node->right) {
                cout << "Child nodes: ";
                if (node->left) cout << "Left: " << node->left->val << " ";
                if (node->right) cout << "Right: " << node->right->val;
                cout << endl; 
            } else cout << "There are no child nodes" << endl;
            return;
        }
        cout << "False" << endl;

    }

    void display_preorder(Tree *r) {
        if (!r) return;
        cout << r->val << " ";
        display_preorder(r->left);
        display_preorder(r->right);
    }

    void display_inorder(Tree *r) {
        if (!r) return;
        display_inorder(r->left);
        cout << r->val << " ";
        display_inorder(r->right);
    }

    void display_postorder(Tree *r) {
        if (!r) return;
        display_postorder(r->left);
        display_postorder(r->right);
        cout << r->val << " ";
    }

    void traverse() {
        cout << "Pre-order: ";
        display_preorder(this);
        cout << "\nIn-order: ";
        display_inorder(this);
        cout << "\nPost-order: ";
        display_postorder(this);
        cout << endl;
    }
};

int main() {
    Tree *root = NULL;
    int ch, data;
    cout << "BST Program:" << endl;
    while (true) {
        
        cout << "1. Insert\n2. Delete\n3. Find\n4. Traverse\n5. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;

                if (!root) root = new Tree(data, NULL, NULL);
                else root->insert(data); 
                break;
            case 2:
                cout << "Enter data to remove: ";
                cin >> data;

                root->deleteNode(data);
                break;
            case 3:
                cout << "Enter data to find: ";
                cin >> data;

                root->findNode(data);
                break;
            case 4:
                cout << "Traversing the tree:" << endl;
                root->traverse();
                break;
            case 5:
                cout << "Exiting program" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again" << endl;
                break;
        }

        for (int i = 0; i < 15; i++) cout << "-";
        cout << endl;
    }
}