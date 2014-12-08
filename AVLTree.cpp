#include "AVLTree.h"

AVLTree::AVLTree()
{
root = nullptr;
}

void AVLTree::insert(Node* data)
{
    if(root == nullptr)
    {
      root = new AVLNode(data);
    }
    else
    {
        if (data->getWord() > root->data->getWord())
        {
            _insert(root->right, data);
            if (height(root->right) - height(root->left) == 2)
            {
                if (data->getWord() > root->right->data->getWord())
                {
                   rotateWithRightChild(root);
                }
                else
                {
                    doubleWithRightChild(root);
                }
            }
        }
        else
        {
            _insert(root->left, data);
            if (height(root->left) - height(root->right) == 2)
            {
                if (data->getWord() < root->left->data->getWord())
                {
                    rotateWithLeftChild(root);
                }
                else
                {
                    doubleWithLeftChild(root);
                }
                }
        }
    }
    root->height = max(height(root->left), height(root->right)) + 1;
}

bool AVLTree::contains(string& data)
{
    if (root == nullptr) return false;
    else if (root->data->getWord() == data) return true;
    else
    {
        if (data > root->data->getWord())
        {
            return _contains(data, root->right);
        }
        else
        {
            return _contains(data, root->left);
        }
    }
}


Node* AVLTree::search(string& data)
{
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->data->getWord() == data) return root->data;
    else
    {
        if (data > root->data->getWord())
        {
            return _search(data, root->right);
        }
        else
        {
            return _search(data, root->left);
        }
    }
}
AVLTree::~AVLTree()
{
    root->~AVLNode();
    root = nullptr;
}


void AVLTree::_insert(AVLNode*& node, Node*& data)
{
    if (node == nullptr)
    {
        node = new AVLNode(data);
    }
    else
    {
        if (data->getWord() > node->data->getWord())
        {
            _insert(node->right, data);
            if (height(node->right) - height(node->left) == 2)
            {
                if (data->getWord() > node->right->data->getWord())
                {
                    rotateWithRightChild(node);
                }
                else
                {
                    doubleWithRightChild(node);
                }
            }
        }
        else
        {
            _insert(node->left, data);
            if (height(node->left) - height(node->right) == 2)
            {
                if (data->getWord() < node->left->data->getWord())
                {
                    rotateWithLeftChild(node);
                }
                else
                {
                    doubleWithLeftChild(node);
                }
            }
        }

    }
    node->height = (max(height(node->left), height(node->right)) + 1);
}

int AVLTree::height(AVLNode *t)
{
    return(t == nullptr ? -1 : t->height);
}

void AVLTree::rotateWithLeftChild(AVLNode*& k1)
{
    AVLNode *k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1->height = max(height(k1->left), height(k1->right) + 1);
    k2->height = max(height(k2->left), height(k2->right) + 1);
    k1 = k2;
}

void AVLTree::rotateWithRightChild(AVLNode*& k1)
{
    AVLNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->right), height(k1->left) + 1);
    k2->height = max(height(k2->right), height(k2->left) + 1);
    k1 = k2;
}

void AVLTree::doubleWithLeftChild(AVLNode*& k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void AVLTree::doubleWithRightChild(AVLNode*& k3)
{
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

int AVLTree::max(int left, int right)
{
    if (left > right) return left;
    else return right;
}

bool AVLTree::_contains(string& data, AVLNode*& node)
{
    if (node == nullptr) return false;
    else if (node->data->getWord() == data) return true;
    else
    {
        if (data > node->data->getWord())
            return _contains(data, node->right);
        else
            return _contains(data, node->left);
    }
}

Node* AVLTree::_search(string& data, AVLNode*& node)
{
    if (node == nullptr) return nullptr;
    else if (node->data->getWord() == data) {
        return node->data;
    }
    else
    {
        if (data > node->data->getWord())
            return _search(data, node->right);
        else
            return _search(data, node->left);
    }
}

