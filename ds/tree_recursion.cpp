#include <iostream>

// 二叉树结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int o) : val(o), left(nullptr), right(nullptr){};
};

void preOrderTraversal(TreeNode* t){
    if (t == nullptr)
        return;
    std::cout << t->val << " ";
    preOrderTraversal(t->left);
    preOrderTraversal(t->right);
}

void inOrderTraversal(TreeNode* t){
    if (t == nullptr)
        return;
    inOrderTraversal(t->left);
    std::cout << t->val << " ";
    inOrderTraversal(t->right);
}

void postOrderTraversal(TreeNode* t){
    if (t == nullptr)
        return;
    postOrderTraversal(t->left);
    postOrderTraversal(t->right);
    std::cout << t->val << " ";
}

int main(){

    // 构建一棵简单的二叉树 (已经手动配平)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);

    std::cout << "前序遍历" << std::endl;
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "中序遍历" << std::endl;
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "后序遍历" << std::endl;
    postOrderTraversal(root);
    std::cout << std::endl;
    return 0;
}

// 二叉树前中后序遍历 递归实现 （浙大数据结构课