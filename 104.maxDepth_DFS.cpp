/*
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
*/

/*
solution:
高度和深度的概念
1.题目要求求最大深度 转化为求根节点高度 这样可以用后序遍历回溯 从而求解
2.确定了用后序遍历 写出递归三部曲

*/
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {  //参数和返回值
        if (root == nullptr) {      //循环终止条件
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);  //分别求出左右子树的高度
        return std::max(left,right)+1;
        //return left >= right ? left+1:right+1;  //对比左右子树高度 返回根节点高度
    }
};