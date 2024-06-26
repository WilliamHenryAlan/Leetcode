/*
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例 1:

输入: [1,2,3,null,5,null,4]
输出: [1,3,4]

示例 2:

输入: [1,null,3]
输出: [1,3]

示例 3:

输入: []
输出: []
*/

#include<iostream>
#include <vector>
#include <queue>
using namespace std;
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
    std::vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size) {
                TreeNode* temp = q.front(); 
                if (size == 1) {        //只有是最右侧的节点 才push 因此 要先push left child 再是 right child
                    ret.push_back(temp->val);  
                }
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                q.pop();
                size--;
            }
        }
        return ret;
    }
};
/*
review 2024.2.14
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> q;
        if (!root) return {};
        q.push(root);
        std::vector<int> ans;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                if (size == 0) ans.push_back(temp->val);
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
        }
        return ans;
    }
};
/*
review 2024.6.24
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode* temp = q.front();
                if (n == 0) {
                    ans.push_back(temp->val);
                }
                if (temp) {
                    if (temp->left) {
                        q.push(temp->left);
                    }
                    if (temp->right) {
                        q.push(temp->right);
                    }
                }
                q.pop();
            }
        }
        return ans;
    }
};