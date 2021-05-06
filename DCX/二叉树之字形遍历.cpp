#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

//二叉树Z字形遍历
//层次遍历是用队列来存每一个节点，因为访问子节点的顺序与父亲节点相同
//而Z字形遍历访问子节点的顺序与父亲节点相反，因此可以考虑用栈来存
class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> cur;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* temp;
        s1.push(root);
        int flag = 0;
        while (!s1.empty() || !s2.empty())
        {
            int n = max(s1.size(), s2.size());
            if(flag == 0)
                for (int i = 0; i < n; i++)
                {
                    temp = s1.top();
                    s1.pop();
                    cur.push_back(temp->val);
                    if (temp->left)s2.push(temp->left);
                    if (temp->right)s2.push(temp->right);
                }
            else 
                for (int i = 0; i < n; i++)
                {
                    temp = s2.top();
                    s2.pop();
                    cur.push_back(temp->val);
                    if (temp->left)s1.push(temp->right);
                    if (temp->right)s1.push(temp->left);
                }
            ans.push_back(cur);
            cur.clear();
            flag ^= 1;
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> a;
    TreeNode* root = new TreeNode;
    root->val = 3;
    root->left = new TreeNode;
    root->left->val = 9;
    root->right = new TreeNode;
    root->right->val = 20;
    root->right->left = root->right->right = nullptr;
    root->left->left = new TreeNode;
    root->left->right = new TreeNode;
    root->left->left->val = 15;
    root->left->right->val = 7;
    root->left->left->left = root->left->left->right = nullptr;
    root->left->right->left = root->left->right->right = nullptr;
    Solution s;
    a = s.zigzagLevelOrder(root);
    for (int i = 0; i < a.size(); i++)
    {
        for (auto aa : a[i])
            cout << " " << aa;
        cout << endl;
    }
    return 0;
}