-Last Class Summary
- Appointment Shceduler Problem
- Binary Search Tree

Even in the midterm, and in the review I talked about the coding problems

- BST: Possible Case
1 2 3 4 5 6 7 8 9 ...
Height of the tree: n Complexity: O(n)

Regular BST
- h = height of Tree
- Complexity
  - Searching is O(h)
  - Deleting is O(h)


Example of Best Case
-Somewhat balanced
- Other Somewhat balanced Trees
- AVL Tree, O(n)
- AVL Tree - For any node, the height difference between left and right-subtrees is at most 1
- it can be 0, in that case it would be somewhat balanced
- the balance factor of a node in an AVL tree is defined as:
Balanced Factor = Height of Leftsubtree - Height of Right subtree
- For an AVL ree, this balance factor must always be -1, 0 or 1

- Balancing (aka Rotation)
- Rotations are the baseic tree-restructuring operation for almost all balanced search trees
- wont violate the binary search tree poperty
- whenever the balanced factor is 2 or -2, then we need to do rotations to balance the tree

**** - Insertion in AVL Tree - ****
-Perform the normal BST insertion
- Starting from the new node, travel up and find the first unbalanced node
- Perform appropriate rotations

-We start at the root, and compare it to the value we are looking for, is the value bigger or smaller than the first parent
node that will tell us where it goes, to the left or right

- if it was 2, the balance rotation, we would do a right roation
- if it was -2, for some node, then we would do a left rotation

****- Deletion in AVL Tree - ****
-Perform the normal BST deletion on the node
- starting from that node, travel up and find the first unbalanced node
-Perform appropriate rotation(s) 

**** - Type of Rotations - ***
-LL
-RR
-RL
-LR

struct Node {
  int key;
Node *left;
Node *right;
int height;


}

/***** CODE FOR LEFT ROTATE *****/
Node *leftRotate(Node *x) {
    Node *y = x->right;  // Set y as the right child of x
    Node *T2 = y->left;  // Store the left subtree of y (to be reassigned)

    // Perform Rotation
    y->left = x;  // Make x the left child of y
    x->right = T2;  // Move T2 to the right child of x

    // Update heights of the rotated nodes
    x->height = 1 + max(height(x->left), height(x->right));  
    y->height = 1 + max(height(y->left), height(y->right));  

    // Return the new root (y)
    return y;
}

/***** CODE FOR RIGHT ROTATE *****/
Node *rightRotate(Node *y) {
    Node *x = y->left;  // Set x as the left child of y
    Node *T2 = x->right;  // Store the right subtree of x (to be reassigned)

    // Perform Rotation
    x->right = y;  // Make y the right child of x
    y->left = T2;  // Move T2 to the left child of y

    // Update heights of the rotated nodes
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    // Return the new root (x)
    return x;
}

