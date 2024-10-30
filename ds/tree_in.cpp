#include <iostream>
#include <stack>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历函数
void inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current != NULL || !stk.empty()) {
        // 遍历左子树，并将所有节点压入栈中
        while (current != NULL) {
            stk.push(current);
            current = current->left;
        }

        // 访问栈顶节点，即左子树的最右节点
        current = stk.top();
        stk.pop();
        std::cout << current->val << " ";

        // 转向右子树
            current = current->right;
    }
}

// 测试代码
int main() {
    // 构建一棵简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);

    // 执行中序遍历
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}

// 二叉树中序遍历 （天工AI
// 还是利用栈方法 先来后到 后发优势
// 代码不复杂，但逻辑看不懂，多攒几篇