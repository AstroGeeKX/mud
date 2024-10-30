#include <iostream>
#include <stack>

// 二叉树的先序遍历 栈方法
// 利用栈先进后出的特性 右节点先于左节点入栈，出栈就符合左节点到右节点的顺序 根节点根据代码逻辑自己看
void preorderTraversal(TreeNode *root)
{
    // 基础的判空退出
    if (root == NULL)
        return;

    // 这里创建了栈 并且首先把根节点放入栈中，后面开始循环根据逻辑遍历左右子树
    // current只是一个临时变量，大多用于指示作用，真正厉害的在栈里面
    // current为叶子节点（最下层的一个）时，发现子树是空的，应该怎么退回去呢
    // 栈就是一种很好的思路，在刚才遍历的时候入栈的元素，初学者会忘记掉，但是计算机不会忘记
    // 继续出栈，就可以退回到正确的地方，继续往左右子树遍历，整体顺序为左到右，这是二叉树的铁律
    // 局部的子树遍历遵循这个规律，那么整颗树也会遵循这个规则，可以用数学的思想证明
    std::stack<TreeNode *> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty())
    {
        // 这三行是出栈然后输出消息
        TreeNode *current = nodeStack.top();
        nodeStack.pop();
        std::cout << current->val << " ";

        // 右和左子节点入栈一个，逻辑上并列
        // 入栈操作不难理解，难理解的是这样入栈并且每次循环都会出栈打印的做法
        // 为什么能正确地完成先序遍历，脑补栈是一件困难的事
        if (current->right != NULL)
        {
            nodeStack.push(current->right);
        }
        if (current->left != NULL)
        {
            nodeStack.push(current->left);
        }
    }
}

// 只是练习写一遍栈方法实现先序遍历