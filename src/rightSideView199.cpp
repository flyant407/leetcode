// #include "solution.h"

// using namespace std;


// TreeNode* dfs(TreeNode* node, int& depth)
// {
//     if (node->right != nullptr) {
//         depth++;
//         return node->right;
//     } else if (node->left != nullptr) {
//         depth++;
//         return node->left;
//     } else {
//         return nullptr;
//     }
// }

// vector<int> Solution::rightSideView(TreeNode* root)
// {
//     int depth = 0;
//     vector<int> res;
//     if (root == nullptr) {
//         return res;
//     }
//     depth++;
//     res.push_back(root->val);
//     TreeNode* currentNode = root
//     TreeNode* nextNode;
//     TreeNode* preNode;

//     nextNode = dfs(currentNode, depth);
//     if (nextNode != nullptr) {
//         if (depth > res.size()) {
//             res.push_back(nextNode->val);
//         }
//         preNode = currentNode;
//         currentNode = nextNode;
//         nextNode = dfs(currentNode, depth);
//     } else {
//         currentNode = preNode;
//         depth--;
//         next
//     }


// }