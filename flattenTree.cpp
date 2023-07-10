#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        root = flat(root);
    }
    TreeNode *flat(TreeNode *root)
    {
        TreeNode *headptr = root;
        //while (headptr)
        //{
        //    cout << headptr->val << endl;
        //    headptr = headptr->right;
        //}
        //cout << endl;
        //cout << endl;
        if (root == nullptr)
        {
            return root;
        }
        TreeNode *prev = flat(root->left);
        TreeNode *next = flat(root->right);
        if (prev)
        {
            TreeNode *iter = prev;
            while (iter->right)
            {
                iter = iter->right;
            }
            iter->right = root->right;
            iter->left = nullptr;
            root->right = prev;
            root->left = nullptr;
        }
        return root;
    }
};

int main()
{
    Solution sln;

    //create tree
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(21);
    head->left->left = new TreeNode(32);
    head->left->left->left = new TreeNode(45);
    head->right = new TreeNode(61);
    head->right->right = new TreeNode(72);
    head->right->right->right = new TreeNode(83);
    head->right->right->right->right = new TreeNode(94);

    //head->left = new TreeNode(2);
    //head->left->left = new TreeNode(3);
    //head->left->right = new TreeNode(4);
    //head->right = new TreeNode(5);
    //head->right->right = new TreeNode(6);
    //head->right->left = new TreeNode(7);

    //solve tree
    sln.flatten(head);
    while (head)
    {
        cout << head->val << endl;
        head = head->right;
    }
}
