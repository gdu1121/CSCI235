#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val; // This will represent the value of the node
    TreeNode* left; // This will represent the left subtree
    TreeNode* right; // This will represent the right subtree
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Create a function that will traverse the BST in-order
void inOrderTraversal(TreeNode* root, std::vector<int>& result){
    // We use recursion to traverse the BST in-order.
    // The Base Case of the recursion will be when the root is nullptr.
    if(root == nullptr) return;

    // Traverse the left subtree first.
    inOrderTraversal(root->left, result);
    // Push the current node's value to the result vector.
    result.push_back(root->val);
    // Traverse the right subtree.
    inOrderTraversal(root->right, result);
}

// Create a function that will determine if a tree is a valid BST using the in-order traversal.
bool isValidBST(TreeNode* root){
    std::vector<int> result; // Create an empty vector to store the in-order traversal of the tree.
    // Call the inOrderTraversal function to get the inorder traversal of the tree and store it in the result vector.
    // This is because a BST is a tree where the left node is always less than the right node
    // and the in-order traversal of a BST is always sorted in ascending order.
    inOrderTraversal(root, result);
    // After traversing the tree in-order, we will check if the result vector is sorted in ascending order.
    // If the result vectore is sorted in ascending order, return true, otherwise return false.
    for(int i = 0; i < result.size() - 1; i++){ // Result.size() - 1 because we do not need to compare the last element with the next element.
        // If the current element is greater than or equal to the next element, return false.
        if(result[i] >= result[i+1]){   
            return false;
        } 
    }
    // If the result vector is sorted in ascending order, return true.
    return true;
}

// Create a function that will perform a pre-order traversal of the BST.
// A pre-order travesral of a BST traverses the root node first, then the left subtree, and then the right subtree.
void preOrderTraversal(TreeNode* root, std::vector<int>& result){
    // We use recursion to traverse the BST
    // Base case for the recursion is when the root is nullptr.
    if(root == nullptr) return;
    // We first push the root node's value into the result vector.
    result.push_back(root->val);
    // Now we will traverse the left subtree.
    preOrderTraversal(root->left, result);
    // Finally, we will traverse the right subtree.
    preOrderTraversal(root->right, result);
}

// Create a function that will perform a post-order traversal of the BST.
// A post-order traversal involves traversing the left subtree, then the right subtree, and finally the root node.
void postOrderTraversal(TreeNode* root, std::vector<int>& result){
    // We use recursion to traverse the BST.
    // The base case for the recursion is when the root is nullptr.
    if(root == nullptr) return;
    // First, we will traverse the left subtree.
    postOrderTraversal(root->left, result);
    // Then, we will traverse the right subtree.
    postOrderTraversal(root->right, result);
    // Finally, we will push the root node's value into the result vector.
    result.push_back(root->val);
}

// Create a function to perform a level-order traversal of the BST.
// Level-order traversal visits nodes level by level from left to right.
// Because level-order follows a FIFO order, we will use a queue to implement this traversal.
void levelOrderTraversal(TreeNode* root, std::vector<int>& result){
    // If the tree is empty, we simply return.
    if(root == nullptr) return;
    // We create a queue to store the pointer of each visited node.
    std::queue<TreeNode*> q;
    // With level-order we start at the root node, therefore we push the root node into the queue first.
    q.push(root);
    // We will continue traversing the tree until the queue is empty.
    while(!q.empty()){
        // We will get the front node of the queue.
        TreeNode* current = q.front();
        // We will pop the front node from the queue.
        q.pop();
        // We will push the value of the current node into the result vector.
        result.push_back(current->val);
        // If the current node has a left child, we will push it into the queue.
        if(current->left != nullptr){
            q.push(current->left);
        }
        // We will do the same for the right child.
        if(current->right != nullptr){
            q.push(current->right);
        }
    }
}

// Create a function that will determine whether a binary tree is full.
// By definition of full, each node must either have 0 or 2 children.
bool isFull(TreeNode* root){
    // To begin, we will check if the tree is empty.
    if(root == nullptr) return true; // An empty tree is considered full.
    // Now we check if the current node has any children.
    if (root->left == nullptr && root->right == nullptr){
        return true; // Both left and right children are null, therefore it is a leaf node.
    }
    // We now recursively check if both the left and right subtrees are full.
    if(root->left != nullptr && root->right != nullptr){
        return isFull(root->left) && isFull(root->right);
    }
    // If the current node has only one child, the tree is not full.
    return false;
}

// Create a function that will determine the height of a binary tree.
// Height should start at 1 for an empty tree. (As per textbook definition)
int height(TreeNode* root){
    // If the tree is empty, we return 0.
    if(root == nullptr) return 0;
    // We will recursively determine the maximum height between the left and right subtrees.
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    // The height of the tree is the maximum height of the left and right subtrees plus 1 for the current node.
    return std::max(leftHeight, rightHeight) + 1; // This will determine the longest path from the root to a leaf node and add 1 for the root node.
}

// Create a function that will find a node with a specific value in the BST.
TreeNode* findNode(TreeNode* root, int value){
    // We first check to see if the tree is empty.
    if(root == nullptr) return nullptr;
    // If the current node's value matches the value we are looking for, we return the current node.
    if(root->val == value) return root;
    // If the current node's value is less than the value we are looking for, we move to the right subtree.
    if(root->val < value){
        return findNode(root->right, value);
    }
    // If the current node's value is greater than the value we are looking for, we move to the left subtree.
    if(root->val > value){
        return findNode(root->left, value);
    }
    // If the value is not found in the tree, we return nullptr.
    return nullptr;
}

// Create a function that will find the minimum value in the BST.
TreeNode* findMin(TreeNode* root){
    // If the tree is empty, we return nullptr.
    if(root == nullptr) return;
    // We will traverse the left subtree until we reach the leftmost node.
    TreeNode* current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    // The leftmost node is the minimum value in the BST.
    return current;
}

// Create a function that will find the maximum value in the BST.
TreeNode* findMax(TreeNode* root){
    // If the tree is empty, we return nullptr.
    if(root == nullptr) return;
    // We will traverse the right subtree until we reach the rightmost node.
    TreeNode* current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    // The rightmost node is the maximum value in the BST.
    return current;
}

//Create a function that will insert a new value into the BST.
TreeNode* insertNode(TreeNode* root, int value){
    // If the tree is empty, we create a new node with the desired value and return it as the new root.
    if(root == nullptr){
        return new TreeNode(value);
    }
    // If the value to be inserted is less than the current nodee's value, we move to the left subtree.
    if(value < root->val){
        root->left = insertNode(root->left, value);
    }
    // If the value to be inserted is greater than the current node's value, we move to the right subtree.
    else if(value > root->val){
        root->right = insertNode(root->right, value);
    }
    // If the value is already present in the tree, we do not insert it again.
    return root; // Return the unchanged root pointer.
}

// Create a function that will delete a node with a specfic value from the BST.
TreeNode* deleteNode(TreeNode* root, int value){
    // If the tree is empty, we simply return nullptr.
    if(root == nullptr) return nullptr;
    // We first need to find the node to be deleted.
    if(value < root->val){
        root->left = deleteNode(root->left, value);
    } else if(value > root->val){
        root->right = deleteNode(root->right, value);
    }
    // If the value is found, we delete the node.
    else {
        // Case 1: Node is a leaf node (no children).
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        //Case 2: Node has only one child. We check if the child is on the left or the right.
        if(root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            return temp; 
        } else if(root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has two children. We use findMin on the right subtree to find the inorder successor.
        TreeNode* temp = findMin(root->right);
        // We copy the inorder successor's value to the current node.
        root->val = temp->val;
        // We then delete the inorder successor from the right subtree.
        root->right = deleteNode(root->right, temp->val);
    }
}

// Create a main function to test the above implementations.
int main(){
    // Create a simple BST for testing.
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    // Test in-order traversal
    std::vector<int> inOrderResult;
    inOrderTraversal(root, inOrderResult);
    std::cout << "In-order Traversal: ";
    for(int val : inOrderResult){
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Test if the tree is a valid BST
    std::cout << "Is Valid BST: " << (isValidBST(root) ? "Yes" : "No") << std::endl;
    // Test pre-order traversal
    std::vector<int> preOrderResult;
    preOrderTraversal(root, preOrderResult);
    std::cout << "Pre-order Traversal: ";
    for(int val : preOrderResult){
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Test post-order traversal
    std::vector<int> postOrderResult;
    postOrderTraversal(root, postOrderResult);
    std::cout << "Post-order Traversal: ";
    for(int val : postOrderResult){
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Test level-order traversal
    std::vector<int> levelOrderResult;
    levelOrderTraversal(root, levelOrderResult);
    std::cout << "Level-order Traversal: ";
    for(int val : levelOrderResult){
        std::cout << val << " ";
    }
    std::cout << std::endl;
    // Test if the tree is full
    std::cout << "Is Full Tree: " << (isFull(root) ? "Yes" : "No") << std::endl;
    // Test height of the tree
    std::cout << "Height of Tree: " << height(root) << std::endl;
    // Clean up memory (delete the tree)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}