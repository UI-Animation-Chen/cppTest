namespace czf{

class TreeNode {
public:
    TreeNode(int data, TreeNode *firstChild, TreeNode *nextSibling) {
        this->data = data;
        this->firstChild = firstChild;
        this->nextSibling = nextSibling;
    }
    // default assign operator and assign constructor is appropriate.
private:
    int data;
    TreeNode *firstChild;
    TreeNode *nextSibling;
};

} //namespace czf
