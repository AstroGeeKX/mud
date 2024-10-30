#include <iostream>
#include <stack>
#include <vector>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 后序遍历函数
std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (root == NULL) return result;

    std::stack<TreeNode*> stk;
    TreeNode* curr = root;
    TreeNode* lastVisited = NULL;

    while (curr != NULL || !stk.empty()) {
        while (curr != NULL) {
            stk.push(curr);
            curr = curr->left;
        }
        
        TreeNode* topNode = stk.top();
        if (topNode->right == NULL || topNode->right == lastVisited) {
            result.push_back(topNode->val);
            lastVisited = topNode;
            stk.pop();
        } else {
            curr = topNode->right;
        }
    }

    return result;
}

// 示例用法
int main() {
    // 构建下面这样的二叉树
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> postorder = postorderTraversal(root);
    for (int val : postorder) {
        std::cout << val << " ";
    }
    // 输出: 4 5 2 3 1

    // 注意：这里没有释放树节点内存，在实际应用中，应该释放掉不再使用的节点以避免内存泄漏。
    return 0;
}

// 二叉树后序遍历栈方法 （天工AI