// BST class - Binary Search Tree that satisfies the AVL property
//  This class is an extension of the BST class and adds the AVL property for extra credits
// You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Jason Gray
// Compiler:  g++
// File type: headher file BST.h
// @brief This class defines a BST search tree
//=======================================================

#ifndef ASSIGN_5E_BST_H
#define ASSIGN_5E_BST_H

// T: element data type
// int for node element typ now, but can be changed to any data type.
typedef int T;

/**
 * Class to implement a Binary Search Tree (BST)
 */
class BST
{
public:
    /**
     * Nested helper Node class
     */
    class Node
    {
    public:
        /**
         * The data stored within a node
         */
        T data;

        /**
         * Pointer to the node's left child
         */
        Node *leftChild;

        /**
         * Pointer to the node's right child
         */
        Node *rightChild;

        /**
         * Pointer to the node's parent
         */
        Node *parent;

        /**
         * The height of the node
         */
        int height;

        /**
         * Node constructor, which initializes everything
         */
        Node(T d) : data(d), leftChild(nullptr), rightChild(nullptr), parent(nullptr)
        {
            height = 0;
        }
    };

    /**
     * BST Constructor, which should initialize an empty BST
     */
    BST();

    /**
     * BST Destructor, which should deallocate anything dynamic
     */
    ~BST();

    /**
     * Find a query element in this BST
     *
     * @param query The query element to find
     * @return true if query exists in this BST, otherwise false
     */
    bool find(const T &query) const;

    /**
     * Return pointer to the left-most node in this BST
     *
     * @return The left-most node in this BST
     */
    Node *getLeftMostNode();

    /**
     * Remove all elements from the BST and deallocate all nodes
     */
    void clear();

    /**
     * Return the number of elements in the BST
     * @return The number of elements in the BST
     */
    unsigned int size() const;

    /**
     * @brief Return the maximum height of the BST. Root is at height 0
     * @return The height of the BST
     */
    int height() const;

    /**
     * @brief Return pointer to the root node of the BST
     * @return The root node of the BST. nullptr if the BST is empty
     */
    Node *getRoot();

    /**
     * @brief Print the subtree at the given node using inorder traversal
     * @param node a pointer to node in BST
     */
    void printInorder(Node *node);

    /**
     * @brief Print the subtree at node using preorder traversal
     * @param node a pointer to node in BST
     */
    void printPreorder(Node *node);

    /**
     * @brief Print the subtree at node using postorder traversal
     * @param node a pointer to node in BST
     */
    void printPostorder(Node *node);

    /**
     * Find the successor of this Node in the BST
     * @param node The node to find the successor of
     * @return Node* Pointer to the successor of this Node, or nullptr if none exists
     */
    Node *successor(Node *node);

    /**
     * Insert a new element to this BST. It should maintain the AVL property.
     * @param element The new element to insert
     * @return true if the insertion was successful, otherwise false (e.g. duplicate)
     */
    bool insert(T element);

    /**
     * Remove an element from this BST. It should maintain the AVL property.
     * @param element The element to remove
     * @return true if the removal was successful, otherwise false (e.g. not found)
     */
    bool remove(T element);
    
    /**
     * @brief Print the balance factor of each node in the BST in-order
     * @param node the starting node at the root of the subtree
     */
    void printBalanceFactors(Node *);

    /**
     * @brief compute the balance factor of a node
     * @return the balance factor for the input node
    */
    int balanceFactor(Node *node);
private:
    /**
     * Pointer to the root node of this BST
     */
    Node *root;

    /**
     * Total number of elements currently in the BST
     */
    unsigned int numElements;

    /**
     * @brief Rotate the subtree rooted at node to the left
     * @param node The root of the subtree to rotate
     */
    void rotateLeft(Node *node);

    /**
     * @brief Rotate the subtree rooted at node to the right
     * @param node The root of the subtree to rotate
     */
    void rotateRight(Node *node);

    /**
     * @brief Rebalance the subtree rooted at node
     * @param node The root of the subtree to rebalance
     */
    void rebalance(Node *node);

    /**
     * @brief Delete all nodes starting at the node called in the argument
     * @param node a pointer to a node in the BST
     */
    void clear(Node* node);

    /**
     * @brief recursive helper function to get height of the BST
     * @param node the node to start recursive function
     * @return height of subtree starting at node
     */
    int height(Node *node) const;

    /**
     * Return the left-most node of a subtree rooted at the node
     * @param node the node to start recursive function
     * @return pointer to the leftmost node in a subtree
     */
    Node *getLeftMostNode(Node *node);

    /**
     * @brief helper function for removing a node
     * @param node the node to be removed, obtained from remove()
     * @return true if node is removed
    */
    bool removeNode(Node *node);

    /**
     * @brief update the height of the input node
     * @param node the node of which height is updated
    */
    void updateHeight(Node* node);

    /**
     * @brief function to set left or right child of input node
     * @param left true if assigning leftChild, false if assigning rightChild
     * @param child pointer to the child to be assigned to node
     * @param node pointer to node of which child needs reassigning
     * @return true if child is reassigned
    */
    bool setChild(bool left, Node *child, Node *node);

    /**
     * @brief replaces currentChild with newChild for node
     * @param currentChild pointer to the currentChild which needs replacement
     * @param newChild pointer to newChild to replace
     * @param node pointer to node that needs child replaced
     * @return true if child is replaced
    */
    bool replaceChild(Node *currentChild, Node *newChild, Node *node);
};

#endif // ASSIGN_5_BST_H
