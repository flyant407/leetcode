#include "solution.h"

using namespace std;

vector<int> Solution::postorderTraversal(TreeNode *root)
{
    if (root == nullptr) {
        return postorderTraversalRes;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    postorderTraversalRes.push_back(root->val);
    return postorderTraversalRes;
}