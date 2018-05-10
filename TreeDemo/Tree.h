#include "TreeNode.h"

namespace czf{

class Tree {
public:
    Tree();
    void add(TreeNode);
    void remove(TreeNode);
    void print();
private:
    TreeNode root;
};

} // namecpace czf
