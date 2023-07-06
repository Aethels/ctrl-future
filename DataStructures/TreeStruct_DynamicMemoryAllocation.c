#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct for BST
struct tree {
     int key; // the value of the fruit
     int power; // holding strength of the fruit
     int initial_power; // first power of fruit
     struct tree *left; // left subtree
     struct tree *right; // right subtree
};

// structure for bucket
struct bucket {
     struct tree *data; // variable to hold the BST node
     struct bucket *next; // Variable to hold the next stack node
};

// Functions
struct tree *newNode(int key, int power);// Function that creates a new node
struct tree *insert(struct tree *root, int key, int power);// Function that adds a new node to BST
void preorder(struct tree *root);// Function that traverses BST and prints it to the screen
struct tree *shoot(struct tree *root, struct bucket **stack);//BST function that shoots fruit and throws it in bucket
struct tree *delete(struct tree *root, int key);// Function to delete a node from BST
struct tree *minValueNode(struct tree *root);// Function to find the smallest value node of a tree
void push(struct bucket **stack, struct tree *data);// Function that adds a new node to the stack
struct tree *pop(struct bucket **stack);// Function that extracts a node from the stack and returns its data
void printStack(struct bucket **stack);// Function that prints the fruits in the bucket to the screen


int main() {
    
     int N, M; // N: maximum fruit weight, M: number of fruit
     printf("Enter N and M values:\n");
     scanf("%d %d", &N, &M); // Get N and M values from user
    
     srand(time(NULL)); // Set seed to generate random number
    
     struct tree *root = NULL; // define root of BST
    
      for (int i = 0; i < M; i++) {
         // Generate a random number between 1 and N
         int key = rand() %N + 1;
         // Make the holding power of the fruit the same as the value of the fruit
         int power = key;
         // Add a new node to BST
         root = insert(root, key, power);
     }
    
     struct bucket *stack = NULL; // Define bucket as a heap
    
     while (root != NULL) { // As long as the fruit remains on the tree
         printf("Final tree:\n");
         preorder(root); // Print the tree to the screen
         printf("\n");
         root = shoot(root, &stack); // Shoot fruit and throw it into the bucket
     }
    
     printStack(&stack); // Print the fruits in the bucket to the screen
     return 0;
}

// Function that prints the fruits in the bucket
void printStack(struct bucket **stack) {
     printf("Fruits in the bucket(from first to last):\n");
    
     // Find the size of the heap
     int size = 0;
     struct bucket *curr = *stack;
     while (curr != NULL) {
         size++;
         curr = curr->next;
     }
    
     // Do nothing if the stack is empty
     if (size == 0) return;
    
     // Create a non-stack non-empty array
     struct tree *array[size];
    
     // Copy fruits from stack to array
     curr = *stack;
     for (int i = 0; i < size; i++) {
         array[i] = curr->data;
         curr = curr->next;
     }
    
     // Reverse the array
     for (int i = 0; i < size / 2; i++) {
         struct tree *temp = array[i];
         array[i] = array[size - i - 1];
         array[size - i - 1] = temp;
     }
    
     // print the array to the screen
     for (int i = 0; i < size; i++) {
         printf("%d ", array[i]->key);
         free(array[i]); // Delete the array from memory
     }
    
     printf("\n");
}

// Function that extracts a node from the stack and returns its data
struct tree *pop(struct bucket **stack) {
     // Return NULL if stack is empty
     if (*stack == NULL) return NULL;
     // Get the node at the beginning of the stack
     struct bucket *temp = *stack;
     // Update the head of the stack with the next pointer
     *stack = (*stack)->next;
     // Store the data of the received node
     struct tree *data = temp->data;
     // Delete the imported node from memory
     free(temp);
     // Return the stored data
     return data;
}

// Function that adds a new node to the stack
void push(struct bucket **stack, struct tree *data) {
     // Allocate memory for a new stack node
     struct bucket *temp = (struct bucket *)malloc(sizeof(struct bucket));
     // Assign the stack node's data
     temp->data = data;
     // Assign the next pointer of the stack node as the head of the stack
     temp->next = *stack;
     // Assign the head of the stack as a new node
     *stack = temp;
}

// Function to find the smallest value node of a tree
struct tree *minValueNode(struct tree *root) {
     struct tree *curr = root; // Initialize current node as root
     // Go to the end of the left subtree
     while (curr->left != NULL)
         curr = curr->left;
     // Return the leftmost node
     return curr;
}

// Function that deletes a node from BST
struct tree *delete(struct tree *root, int key) {
     // Return NULL if tree is empty
     if (root == NULL) return NULL;
     // If the key to be deleted is less than the root key, search in the left subtree
     if (key < root->key)
         root->left = delete(root->left, key);
     // If the key to be deleted is greater than the root's key, search in the right subtree
     else if (key > root->key)
         root->right = delete(root->right, key);
     // If the key to be deleted is equal to the root's key, perform the delete
     else {
         // If root has no left subtree, return its right subtree
         if (root->left == NULL) {
             struct tree *temp = root->right;
             free(root); // Delete root from memory
             return temp;
         }
        
         // If root has no right subtree, return left subtree
         else if (root->right == NULL) {
             struct tree *temp = root->left;
             free(root); // Delete root from memory
             return temp;
         }
        
         // Find the smallest node of the right subtree if the root has both left and right subtrees
         struct tree *temp = minValueNode(root->right);
        
         // Replace the key and power of root with the key and power of the smallest node
         root->key = temp->key;
         root->power = temp->power;
        
         // Keep the BST property by deleting the smallest node from the right subtree
         root->right = delete(root->right, temp->key);
     }
    
     return root; // Return the tree
}

// Function in BST that hits fruit and throws it into the bucket
struct tree *shoot(struct tree *root, struct bucket **stack) {

     int k, p; // k: value of the fruit, p: power of the shot
     printf("Enter the value and shooting power of the fruit you want to hit:\n");
     scanf("%d %d", &k, &p); // Get k and p values from user
    
     struct tree *curr = root; // Initialize current node as root
    
     struct tree *parent = NULL; // Variable to hold current node's parent
    
     int dir = 0; // Variable to hold the direction of the current node relative to its parent (0: left, 1: right)
    
     // Find the node with k value by searching BST
     while (curr != NULL && curr->key != k) {
         parent = curr; // Update parent
         if (k < curr->key) { // Go to left subtree if key k is less than current node's key
             curr = curr->left;
             dir = 0;
         }
         else { // Go to right subtree if key k is greater than key of current node
             curr = curr->right;
             dir = 1;
         }
     }
     // If node with k value is not found give error message
     if (curr == NULL) {
         printf("There is no fruit on the tree with the value %d!\n", k);
         return root; // Return the tree as it is
     }
    
     // If node with k value is found, reduce the holding power
     curr->power -= p;
    
     // If the grip strength is 0 or less, wipe the fruit from the tree and throw it into the bucket
     if (curr->power <= 0) {
         printf("The fruit with the value %d fell from the tree!\n", k);
         curr->power = curr->initial_power; // Initialize the power of the fruit
         push(stack, curr); // Add fruit to bucket
         root = delete(root, k); // Delete fruit from tree
     }
    
     return root; // Return the tree
}

// Function that traverses and prints the BST preorder
void preorder(struct tree *root) {
     // If the tree is not empty
     if (root != NULL) {
         // Write root's key and power to the screen
         printf("%d (%d) ", root->key, root->power);
// Cycle left subtree
         preorder(root->left);
         // Cycle right subtree
         preorder(root->right);
     }
}

// Function that adds a new node to the BST
struct tree *insert(struct tree *root, int key, int power) {
     // If tree is empty create a new node and return it as root
     if (root == NULL) return newNode(key, power);
     // If the tree is not empty, add to the appropriate place
     if (key < root->key) // Add to left subtree if key is less than root's key
         root->left = insert(root->left, key, power);
     else if (key > root->key) // Add to right subtree if key is greater than root's key
         root->right = insert(root->right, key, power);
            
     // return root
     return root;
}

// Function that creates a new node
struct tree *newNode(int key, int power) {
     // Allocate memory for a new node
     struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
     // Assign the key and power of the node
     temp->key = key;
     temp->power = power;
     // Make the initial strength of the node the same as its strength
     temp->initial_power = power;
     // Assign the left and right subtrees of the node to NULL
     temp->left = NULL;
     temp->right = NULL;
     // Rotate the node
     return temp;
}



