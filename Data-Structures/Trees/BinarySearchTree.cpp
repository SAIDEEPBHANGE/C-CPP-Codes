#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }
    // Insertion in BST
    void insert(int val) {
        root = insertRec(root, val);
    }
    Node* insertRec(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insertRec(root->left, val);
        } else if (val > root->data) {
            root->right = insertRec(root->right, val);
        }
        return root;
    }
    // Searching in BST
    bool search(int val) {
        return searchRec(root, val);
    }
    bool searchRec(Node* root, int val) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == val) {
            return true;
        }
        if (val < root->data) {
            return searchRec(root->left, val);
        } else {
            return searchRec(root->right, val);
        }
    }
    // Deletion in BST
    void deleteNode(int val) {
        root = deleteRec(root, val);
    }
    Node* deleteRec(Node* root, int val) {
        if (root == nullptr) {
            return root;
        }
        if (val < root->data) {
            root->left = deleteRec(root->left, val);
        } else if (val > root->data) {
            root->right = deleteRec(root->right, val);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }
    // Minimum in BST
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    // Maximum in BST
    Node* maxValueNode(Node* node) {
        Node* current = node;
        while (current && current->right != nullptr) {
            current = current->right;
        }
        return current;
    }
    // Floor in BST
    int floor(int val) {
        Node* node = floorRec(root, val);
        return node ? node->data : -1;
    }
    Node* floorRec(Node* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->data == val) {
            return root;
        }
        if (root->data > val) {
            return floorRec(root->left, val);
        }
        Node* temp = floorRec(root->right, val);
        return temp ? temp : root;
    }
    // Ceil in BST
    int ceil(int val) {
        Node* node = ceilRec(root, val);
        return node ? node->data : -1;
    }
    Node* ceilRec(Node* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->data == val) {
            return root;
        }
        if (root->data < val) {
            return ceilRec(root->right, val);
        }
        Node* temp = ceilRec(root->left, val);
        return temp ? temp : root;
    }
    // Inorder Successor in BST
    Node* inorderSuccessor(Node* root, int val) {
        Node* target = searchNode(root, val);
        if (!target) {
            return nullptr;
        }
        if (target->right) {
            return minValueNode(target->right);
        }
        Node* succ = nullptr;
        while (root) {
            if (val < root->data) {
                succ = root;
                root = root->left;
            } else if (val > root->data) {
                root = root->right;
            } else {
                break;
            }
        }
        return succ;
    }
    Node* searchNode(Node* root, int val) {
        if (root == nullptr || root->data == val) {
            return root;
        }
        if (val < root->data) {
            return searchNode(root->left, val);
        } else {
            return searchNode(root->right, val);
        }
    }
    // Inorder Predecessor in BST
    Node* inorderPredecessor(Node* root, int val) {
        Node* target = searchNode(root, val);
        if (!target) {
            return nullptr;
        }
        if (target->left) {
            return maxValueNode(target->left);
        }
        Node* pred = nullptr;
        while (root) {
            if (val < root->data) {
                root = root->right;
            } else if (val > root->data) {
                pred = root;
                root = root->left;
            } else {
                break;
            }
        }
        return pred;
    }
    // BST Traversals
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    void inorderRec(Node* root) {
        if (root) {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }
    void preorder() {
        preorderRec(root);
        cout << endl;
    }
    void preorderRec(Node* root) {
        if (root) {
            cout << root->data << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }
    void postorder() {
        postorderRec(root);
        cout << endl;
    }
    void postorderRec(Node* root) {
        if (root) {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->data << " ";
        }
    }
};
int main() {
    BST tree;
    // Insertion
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    // Traversals
    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << "Postorder Traversal: ";
    tree.postorder();
    // Search
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    // Delete Node
    tree.deleteNode(20);
    cout << "Inorder after deletion of 20: ";
    tree.inorder();
    // Minimum and Maximum
    cout << "Minimum: " << tree.minValueNode(tree.root)->data << endl;
    cout << "Maximum: " << tree.maxValueNode(tree.root)->data << endl;
    // Floor and Ceil
    cout << "Floor of 65: " << tree.floor(65) << endl;
    cout << "Ceil of 65: " << tree.ceil(65) << endl;
    // Inorder Successor and Predecessor
    Node* successor = tree.inorderSuccessor(tree.root, 60);
    cout << "Inorder Successor of 60: " << (successor ? to_string(successor->data) : "Not Found") << endl;
    Node* predecessor = tree.inorderPredecessor(tree.root, 60);
    cout << "Inorder Predecessor of 60: " << (predecessor ? to_string(predecessor->data) : "Not Found") << endl;
    return 0;
}