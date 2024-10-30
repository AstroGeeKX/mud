#include <iostream>
#include <stack>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 先序遍历函数
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;  // 根节点为空，直接返回

    std::stack<TreeNode*> nodeStack;  // 创建一个栈来保存节点
    nodeStack.push(root);  // 将根节点入栈

    while (!nodeStack.empty()) {
        TreeNode* current = nodeStack.top();  // 获取栈顶节点
        nodeStack.pop();  // 弹出栈顶节点

        std::cout << current->val << " ";  // 访问当前节点

        // 注意：先右后左，因为栈是后进先出的
        if (current->right != NULL) {
            nodeStack.push(current->right);  // 如果右子节点不为空，则入栈
        }
        if (current->left != NULL) {
            nodeStack.push(current->left);  // 如果左子节点不为空，则入栈
        }
    }
}

// 测试代码
int main() {
    // 构建一棵简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 执行先序遍历
    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    // 清理资源
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// 二叉树的先序遍历 （天工AI
// 降本增效树