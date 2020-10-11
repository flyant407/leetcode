#include <algorithm>
#include <stack>
#include "solution.h"

using namespace std;

// void dfs(TreeNode* node, int depth, int& maxDep)
// {
//     if (node == nullptr) {
//         maxDep = max(depth, maxDep);
//         return;
//     }
//     depth++;
//     dfs(node->left, depth, maxDep);
//     dfs(node->right, depth, maxDep);
// }

// int Solution::maxDepth(TreeNode* root)
// {
//     int depth = 0;
//     int maxDep = 0;
//     dfs(root, depth, maxDep);
//     return maxDep;
// }
/****************以下是使用stack代替尾递归****************************/
// int Solution::maxDepth(TreeNode* root)
// {
//     int depth = 0;
//     int maxDep = 0;
//     stack<pair<TreeNode*,int>> s;
//     if (s == nullptr) {
//         return 0;
//     }
//     pair<TreeNode*,int> rNode = make_pair(root,0);
//     s.push(rNode);
//     while (!s.empty()) {
//         TreeNode* node = s.top().first;
//         depth = s.top().second;
//         maxDep = max(depth,maxDep);
//         s.pop();
//         pair<TreeNode*,int> pNode;
//         if (node->right) {
//             pNode = make_pair(node->right,depth + 1);
//             s.push(pNode);
//         }
//         if (node->left) {
//             pNode = make_pair(node->left,depth + 1);
//             s.push(pNode);
//         }
//     }
//     return maxDep;
// }

/****************以下是使用stack做较通用的算法****************************/
void visitAlongleftBranch(pair<TreeNode*,int> node, stack<pair<TreeNode*,int>>& s)
{
    while (node.first) {
        int depth = node.second + 1;
        pair<TreeNode*,int> rNode = make_pair(node.first->right, depth);
        s.push(rNode);
        node = make_pair(node.first->left, depth);
    }
    
}

int Solution::maxDepth(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    int depth = 0;
    int maxDep = 0;
    stack<pair<TreeNode*,int>> s;
    pair<TreeNode*,int> node = make_pair(root,0);
    while (true) {
        visitAlongleftBranch(node,s);
        if (s.empty()) {
            break;
        }
        node = s.top();
        s.pop();
    }

    return maxDep;
}