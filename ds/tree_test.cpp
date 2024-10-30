#include <iostream>

// 树的结构体定义 // 树的结构体定义 // 树的结构体定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 树的结构体定义 // 树的结构体定义 // 树的结构体定义

// 递归方法查找左子树的最右节点
TreeNode* findRightMostNode(TreeNode* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    TreeNode* rhs = findRightMostNode(root->left);
    return rhs;
}

// 栈方法
TreeNode* findRightMostNodeIterative(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    TreeNode* node = root;
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


int main() {
    // 构建一棵简单的二叉树 （完全二叉树 平衡的
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);

    // 找到左子树的最右节点
    TreeNode* rightMostNode = findRightMostNodeIterative(root);
    if (rightMostNode) {
        std::cout << "Left subtree's rightmost node value: " << rightMostNode->val << std::endl;
    } else {
        std::cout << "Tree does not have a left subtree" << std::endl;
    }

    // 删除了delete语句，没必要手动清除内存
    return 0;
}

// 二叉树测试函数用例