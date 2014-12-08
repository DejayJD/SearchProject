#include "avlnode.h"

AVLNode::AVLNode()
{
    left = nullptr;
    right = nullptr;
    height = 0;
}

AVLNode::AVLNode(Node* data) : left(nullptr), right(nullptr), data(data), height(0)
{

}

AVLNode::~AVLNode()
{
    if(left != nullptr) {
        left->~AVLNode();
    }
    if(right != nullptr) {
        right->~AVLNode();
    }
    delete left;
    delete right;
}
