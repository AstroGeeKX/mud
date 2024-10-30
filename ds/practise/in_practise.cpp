#include <iostream>
#include <stack>

// 定义二叉树节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode *root)
{
    std::stack<TreeNode *> stk;
    TreeNode *current = root;

    while (current != NULL || !stk.empty())
    {
        while (current != NULL)
        {
            stk.push(current);
            current = current->left;
            // 二叉树从左往右的遍历特性
            // 左子树一直入栈
        }

        // stack容器的特性，这三行代码只是出栈
        current = stk.top();
        stk.pop();
        std::cout << current->val << " ";
        // 上面左子树入栈到底，所以往右子树看
        current = current->right;
    }
}

int main()
{

    return 0;
}