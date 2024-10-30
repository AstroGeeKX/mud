#include <iostream>
#include <stack>

// 定义二叉树节点结构
struct TreeNode {
    int val; // 树节点存的值
    TreeNode *left; // 左节点
    TreeNode *right; // 右节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    // 结构体构造函数 对成员进行一系列初始化
};

// 先序遍历函数
void preorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;  // 根节点为空，直接返回

    std::stack<TreeNode*> nodeStack;  // 创建一个栈来保存节点  比如使用链表 尾插和尾删 类似栈的操作
    nodeStack.push(root);  // 首先将根节点入栈 循环开始的情况
    TreeNode* c; // c stand for current

    //// 节点栈不空就保持循环 ////
    while (!nodeStack.empty()) {
        c = nodeStack.top();  // 获取栈顶节点 c是临时变量
        nodeStack.pop();  // 弹出栈顶节点  临时值c已经完成拷贝 把栈里的弹出

        std::cout << c->val << " ";  // 访问当前节点，并打印

        // 注意：先右后左，因为栈是后进先出的  这跟栈的特性有关，与二叉树无关
        if (c->right) 
            nodeStack.push(c->right); // 右节点不为空 入栈
        if (c->left)
            nodeStack.push(c->left); // 左节点不为空 入栈
    }
}

// 测试代码
int main() {
    // 构建一棵简单的二叉树 (已经手动配平)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);

    /*平衡树的第二种方式
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    */

    // 执行先序遍历
    std::cout << "先序遍历（Preorder Traversal）: ";
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

// 栈的使用并不是唯一选择 只是充当存储临时变量的工具
// 搞清原理，灵活变通 可以用list和vector来代替
// 其实不完全是这样，stack的选择不是唯一，但数据处理的形式要有栈的特性，即FILO
// 因为二叉树遍历总是从左到右，靠上左树先访问->靠下左树后访问->靠下右树先访问->靠上右树后访问
// 全部节点都能遍历到并且只访问一次，这样就能保证遍历结果是符合先序遍历的
// 9月4日补充


// 为什么用指针 指针和变量在编码上本质都是标识符

/*计算机里面有两个变化 一个是数值 二个是地址
单纯的数值变化可以做到简单的算术逻辑运算
但要进行复杂的 内存单元结构发生调度变化就需要指针

变量可以改变 “数值”
指针可以改变 “数值” 和 “另一个地址的数值” 和 “特殊读写权限”
*/

/*泛型是泛化类型 指针是泛化地址
防止十个变量十个名的情况
十个变量用一个名就可以了，通过第一个变量名加上地址偏移量来表示后面任意的变量*/