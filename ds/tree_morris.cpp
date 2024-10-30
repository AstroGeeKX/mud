#include <iostream>

// 定义二叉树节点结构
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void morrisTraversal(TreeNode *root); // Gemini的Morris遍历函数

// 中序遍历函数 morris
void inorderTraversal(TreeNode *root)
{
  TreeNode *current = root;
  while (current != NULL)
  {
    if (current->left == NULL)
    {
      // 如果左子节点为空，直接访问当前节点并前往右子树
      std::cout << current->val << " ";
      current = current->right;
    }
    else
    {
      // 找到左子树中的最右节点
      TreeNode *predecessor = current->left;
      while (predecessor->right != NULL && predecessor->right != current)
      {
        predecessor = predecessor->right;
      }

      if (predecessor->right == NULL)
      {
        // 如果最右节点的右指针为空，将它指向当前节点，然后继续遍历左子树
        predecessor->right = current;
        current = current->left;
      }
      else
      {
        // 如果最右节点的右指针指向当前节点，说明左子树已被访问过，恢复树的原始结构
        predecessor->right = NULL;
        std::cout << current->val << " "; // 访问当前节点
        current = current->right;         // 访问右子树
      }
    }
  }
}

// 测试代码
int main()
{
  // 构建一棵简单的二叉树
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  // 执行中序遍历
  std::cout << "Inorder Traversal: ";
  inorderTraversal(root);
  std::cout << std::endl;

  // 清理资源
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}

// 二叉树遍历 （天工AI
// 中序遍历 Morris方法 不知道是什么 攒代码

// Gemini的示例代码
void morrisTraversal(TreeNode *root)
{
  TreeNode *current = root;
  while (current != nullptr)
  {
    if (current->left == nullptr)
    {
      // 没有左子树，直接访问当前节点
      std::cout << current->val << " ";
      current = current->right;
    }
    else
    {
      // 有左子树，找到左子树的最右节点
      TreeNode *predecessor = current->left;
      while (predecessor->right != nullptr && predecessor->right != current)
      {
        predecessor = predecessor->right;
      }
      // 如果最右节点的右子树为空，则建立线程连接
      if (predecessor->right == nullptr)
      {
        predecessor->right = current;
        current = current->left;
      }
      else
      {
        // 如果最右节点的右子树不为空，则断开线程连接
        predecessor->right = nullptr;
        std::cout << current->val << " ";
        current = current->right;
      }
    }
  }
}
// 可以看到防御性编程放前面，主要逻辑在else分支