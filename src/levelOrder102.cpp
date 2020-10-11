#include <queue>
#include "solution.h"

using namespace std;

vector<vector<int>> Solution::levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr) {
        return res;
    }

    queue<TreeNode *> treeQ;
    treeQ.push(root);
    while (!treeQ.empty()) {
        int numOfLevel = treeQ.size();
        vector<int> levelNodes;
        while (numOfLevel) {
            numOfLevel--;
            TreeNode *node = treeQ.front();
            treeQ.pop();
            levelNodes.push_back(node->val);
            if (node->left != nullptr) {
                treeQ.push(node->left);
            }
            if (node->right != nullptr) {
                treeQ.push(node->right);
            }
        }
        res.push_back(levelNodes);
        levelNodes.clear();
    }
    return res;
}