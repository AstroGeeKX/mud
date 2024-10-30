#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void postorderTraversal(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        // Traverse left subtree
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Check if there's a right child
        if (current == nullptr && !s.empty() && s.top()->right != nullptr) {
            current = s.top()->right;
        } else {
            // Pop top element from stack and print its data
            current = s.top();
            cout << current->data << " ";
            s.pop();

            // If the popped element has a right child and the right child is not processed,
            // then make right child as current so that it will be processed in future
            if (!s.empty() && s.top() == current->right) {
                current = s.top();
                s.pop();
                s.push(current);
                current = current->left;
            } else {
                current = nullptr;
            }
        }
    }
}

int main() {
    // Create a binary tree
    Node* root = new Node{1, new Node{2, new Node{4, nullptr, nullptr}, new Node{5, nullptr, nullptr}}, new Node{3, nullptr, nullptr}};

    // Perform postorder traversal
    postorderTraversal(root);

    return 0;
}

// 二叉树后序遍历栈方法 （Gemini