#include <iostream>
#include <queue>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// AI生成的层序遍历，分别处理了每一层的内容，归总到一共二维数组里
std::vector<std::vector<int>> levelOrderTraversal(TreeNode* root) {
    std::vector<std::vector<int>> result; // To store the level order traversal result
    if (!root) return result; // Return empty vector if the tree is empty

    std::queue<TreeNode*> nodeQueue; // Queue for level order traversal
    nodeQueue.push(root); // Push the root node into the queue

    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size(); // Number of nodes at the current level
        std::vector<int> currentLevel; // To store the values of nodes at the current level

        for (int i = 0; i < levelSize; i++) {
            TreeNode* currentNode = nodeQueue.front(); // Get the front node from the queue
            nodeQueue.pop(); // Pop the front node from the queue

            currentLevel.push_back(currentNode->val); // Add the value of the node to the current level vector

            if (currentNode->left) nodeQueue.push(currentNode->left); // Add left child to the queue if it exists
            if (currentNode->right) nodeQueue.push(currentNode->right); // Add right child to the queue if it exists
        }

        result.push_back(currentLevel); // Add the current level vector to the result vector
    }

    return result;
}

// this is remake, more easy, only printf
// 这里是重写，遍历直接打印输出，更简单
// 层序遍历很简单，用的是队列不是栈，不要和前序遍历等混淆
void MyLevelOrderTraversal(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> nodeQueue; // 队列用于存储遍历到的节点
    nodeQueue.push(root); // 首先放入一个根节点
    
    while (!nodeQueue.empty()) {
        TreeNode* currentNode = nodeQueue.front(); // 获取队列首个元素
        nodeQueue.pop(); // 上面获取了，这里就可以删掉了
        std::cout << currentNode->val << " "; // 虽然队列删掉了，但是临时变量刚刚获取了地址
        
        if (currentNode->left) nodeQueue.push(currentNode->left); // 探左子树
        if (currentNode->right) nodeQueue.push(currentNode->right); // 探右子树
    }

}
// 原理很简单，从根节点开始，弹出根节点的同时打印出来，并且存储左右子树节点
// 因为是队列，所以顺着刚刚存入的左右子树节点依次打印，各自打印之后，顺便存入左右子节点
// 只需要2-3层树就可以模拟这个过程，十分轻松


// Function to print the level order traversal result
void printOnLevel(const std::vector<std::vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Main function to demonstrate the usage of levelOrderTraversal function
int main() {
    // Construct a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Perform level order traversal and print the result
    // std::vector<std::vector<int>> result = levelOrderTraversal(root);
    // printLevelOrder(result);
    MyLevelOrderTraversal(root);

    // Clean up the allocated memory for the tree nodes
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}