#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <node.h>

using namespace std;

template <class T> class AVLTree
{
private:
    class AVLNode
    {
    public: // Member Variables
        AVLNode *left, *right;
        T data;
        int height;

    public: // Constructor || Destructor
        AVLNode()
        {
            left = nullptr;
            right = nullptr;
            height = 0;
        }

        AVLNode(T& data) : left(nullptr), right(nullptr), data(data), height(0)
        {

        }

        ~AVLNode()
        {

        }
    public: // Member Functions

    };

private: // Member Variables
    AVLNode *root;
public : // Constructor || Destructor
    AVLTree()
    {
        root = nullptr;
    }
public : // Member Functions
    void insert(T data)
    {
        if(root == nullptr)
        {
            root = new AVLNode(data);
            //cout << "Created root with data : " << data << endl;
        }
        else
        {
            if (data->getWord() > root->data->getWord())
            {
                //cout << data <<" is going right of " << root->data << endl;
                _insert(root->right, data);
                if (height(root->right) - height(root->left) == 2)
                {
                    if (data->getWord() > root->right->data->getWord())
                    {
                        rotateWithRightChild(root);
                        //cout << "rotating with right child" << endl;
                    }
                    else
                    {
                        doubleWithRightChild(root);
                        //cout << "double rotating with right child" << endl;
                    }
                }
            }
            else
            {
                //cout << data <<" is going left of " << root->data << endl;
                _insert(root->left, data);
                if (height(root->left) - height(root->right) == 2)
                {
                    if (data->getWord() < root->left->data->getWord())
                    {
                        rotateWithLeftChild(root);
                        //cout << "rotating with left child" << endl;
                    }
                    else
                    {
                        doubleWithLeftChild(root);
                        //cout << "double rotating with left child" << endl;
                    }
                }
            }
        }
        root->height = max(height(root->left), height(root->right)) + 1;

    }

//    bool contains(T data)
//    {
//        if (root == nullptr) return false;
//        else if (root->data == data) return true;
//        else
//        {
//            if (data > root->data)
//            {
//                return _contains(data, root->right);
//            }
//            else
//            {
//                return _contains(data, root->left);
//            }
//        }
//    }

    bool contains(string& data)
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

    T& search(T data)
    {
        if (root == nullptr) cerr << "no data" << endl;
        else if (root->data->getWord() == data->getWord()) return root->data;
        else
        {
            if (data->getWord() > root->data->getWord())
            {
                return _search(data, root->right);
            }
            else
            {
                return _search(data, root->left);
            }
        }
    }

    Node*& search(string& data)
    {
        if (root == nullptr) cerr << "no data" << endl;
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
private: // Member Functions
     void _insert(AVLNode*& node, T& data)
     {
         if (node == nullptr)
         {
             node = new AVLNode(data);
             //cout << "Created AVLNode with data : " << data << endl;
         }
         else
         {
             if (data->getWord() > node->data->getWord())
             {
                 //cout << data << " is going right of " << node->data << endl;
                 _insert(node->right, data);
                 if (height(node->right) - height(node->left) == 2)
                 {
                     if (data->getWord() > node->right->data->getWord())
                     {
                         rotateWithRightChild(node);
                         //cout << "rotating with right child" << endl;
                     }
                     else
                     {
                         doubleWithRightChild(node);
                         //cout << "double rotating with right child" << endl;
                     }
                 }
             }
             else
             {
                 //cout << data << " is going left of " << node->data << endl;
                 _insert(node->left, data);
                 if (height(node->left) - height(node->right) == 2)
                 {
                     if (data->getWord() < node->left->data->getWord())
                     {
                         rotateWithLeftChild(node);
                         //cout << "rotating with left child" << endl;
                     }
                     else
                     {
                         doubleWithLeftChild(node);
                         //cout << "double rotating with left child" << endl;
                     }
                 }
             }

         }
         node->height = (max(height(node->left), height(node->right)) + 1);
     }
     int height(AVLNode *t)
     {
         return(t == nullptr ? -1 : t->height);
     }

     void rotateWithLeftChild(AVLNode*& k1)
     {
         AVLNode *k2 = k1->left;
         k1->left = k2->right;
         k2->right = k1;
         k1->height = max(height(k1->left), height(k1->right) + 1);
         k2->height = max(height(k2->left), height(k2->right) + 1);
         k1 = k2;
     }

     void rotateWithRightChild(AVLNode*& k1)
     {
         AVLNode *k2 = k1->right;
         k1->right = k2->left;
         k2->left = k1;
         k1->height = max(height(k1->right), height(k1->left) + 1);
         k2->height = max(height(k2->right), height(k2->left) + 1);
         k1 = k2;
     }

     void doubleWithLeftChild(AVLNode*& k3)
     {
         rotateWithRightChild(k3->left);
         rotateWithLeftChild(k3);
     }

     void doubleWithRightChild(AVLNode*& k3)
     {
         rotateWithLeftChild(k3->right);
         rotateWithRightChild(k3);
     }

     int max(int left, int right)
     {
         if (left > right) return left;
         else return right;
     }

//     bool _contains(T& data, AVLNode*& node)
//     {
//         if (node == nullptr) return false;
//         else if (node->data == data) return true;
//         else
//         {
//             if (data > node->data)
//                 return _contains(data, node->right);
//             else
//                 return _contains(data, node->left);
//         }
//     }

     bool _contains(string& data, AVLNode*& node)
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

//     T& _search(T& data, AVLNode*& node)
//     {
//         if (node == nullptr) cerr << "no data" << endl;
//         else if (node->data == data) return node->data;
//         else
//         {
//             if (data > node->data)
//                 return _search(data, node->right);
//             else
//                 return _search(data, node->left);
//         }
//     }
     Node*& _search(string& data, AVLNode*& node)
     {
         if (node == nullptr) cerr << "no data" << endl;
         else if (node->data->getWord() == data) return node->data;
         else
         {
             if (data > node->data->getWord())
                 return _search(data, node->right);
             else
                 return _search(data, node->left);
         }
     }


};

#endif // AVLTREE_H
