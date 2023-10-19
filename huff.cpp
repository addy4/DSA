#include </Users/PremBhatia1/stdc.h>

using namespace std;

class Node
{
public:
    int frequency;
    string ch;
    string code;
    Node *left;
    Node *right;

    // timer
    static int timer;

    // time
    int time;

    Node(int v)
    {
        this->frequency = v;
        this->ch = "";
        this->code = "";
        this->time = this->timer++;
        this->left = NULL;
        this->right = NULL;
    }

    Node(int v, string c)
    {
        this->frequency = v;
        this->ch = c;
        this->code = "";
        this->time = this->timer++;
        this->left = NULL;
        this->right = NULL;
    }

    void append_bits(string bit)
    {
        this->code = this->code + bit;
    }
};

int Node::timer = 0;

// Custom comparator function
struct CustomComparator
{
    bool operator()(const Node *a, const Node *b) const
    {
        if (a->frequency < b->frequency)
        {
            return true;
        }
        else if (a->frequency == b->frequency)
        {
            if (a->time > b->time)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};

class Huffman
{
public:
    // HUFFTREE
    multiset<Node *, CustomComparator> hufftree;

    // METHODS
    void createHufftree(map<string, int> chars);
    void solve(map<string, int> chars, map<string, string> &solution);
    void traverseAssignBits(Node *root, string code, map<string, string> &solution);
    Node *merge(Node *lnode, Node *rnode);
};

void Huffman::createHufftree(map<string, int> chars)
{
    for (auto i : chars)
    {
        Node *node = new Node(i.second, i.first);
        //hufftree.insert({node->frequency, node});
        hufftree.insert(node);
    }

    for (auto i : hufftree)
    {
        //cout << i.first << ", " << i.second->ch << " - " << i.second->frequency << endl;
        cout << i->ch << ", " << i->frequency << ", " << i->time << endl;
    }

    return;
}

Node *Huffman::merge(Node *lnode, Node *rnode)
{
    Node *root = new Node(lnode->frequency + rnode->frequency);
    root->left = lnode;
    root->right = rnode;
    return root;
}

void Huffman::traverseAssignBits(Node *root, string str, map<string, string> &solution)
{
    if (root == NULL)
    {
        return;
    }
    root->code = str;
    if (root->left == NULL && root->right == NULL)
    {
        solution[root->ch] = root->code;
        cout << "leaf at: " << root->ch << ", " << root->frequency << endl;
    }
    cout << "at " << root->ch << " with " << root->frequency << " time: " << root->time << endl;
    traverseAssignBits(root->left, str + "0", solution);
    traverseAssignBits(root->right, str + "1", solution);
}

void Huffman::solve(map<string, int> chars, map<string, string> &solution)
{
    this->createHufftree(chars);

    while (hufftree.size() > 1)
    {
        Node *lnode = *(hufftree.begin());
        hufftree.erase(hufftree.begin());
        Node *rnode = *(hufftree.begin());
        hufftree.erase(hufftree.begin());

        Node *root = merge(lnode, rnode);
        cout << root->left->ch << ", " << root->right->ch << endl;

        //hufftree.insert({root->frequency, root});
        hufftree.insert(root);

        cout << lnode->frequency << " and " << rnode->frequency << endl;
    }

    Node *root = *(hufftree.begin());
    traverseAssignBits(root, "", solution);

    return;
}

int main(int argc, char const *argv[])
{
    /* CHAR MAP */
    map<string, int> chars;
    chars["a"] = 10;
    chars["b"] = 15;
    chars["i"] = 12;
    chars["o"] = 3;
    chars["u"] = 4;
    chars["s"] = 13;
    chars["t"] = 1;
    /* CHAR MAP */

    /* SOLUTION */
    map<string, string> solution;
    /* SOLUTION */

    /* SOLVE */
    Huffman *soln = new Huffman();
    soln->solve(chars, solution);

    for (auto iter : solution)
    {
        cout << "CHAR: " << iter.first << ", BITS: " << iter.second << endl;
    }

    return 0;
}
