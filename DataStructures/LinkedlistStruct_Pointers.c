#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
struct node {
    char name[20]; // Name data
    struct node *next; // Pointer to the next node
};

// Function to create a new node with a given name and return its pointer
struct node *create_node(char *name) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    strcpy(new_node->name, name); // Copy the name to the node data
    new_node->next = NULL; // Set the next pointer to NULL
    return new_node; // Return the pointer to the new node
}

// Function to insert a node at the end of a linked list and return its pointer
struct node *insert_node(struct node *head, struct node *node) {
    if (head == NULL) { // If the list is empty, make the node the head
        head = node;
    } else { // Otherwise, find the last node and link it to the new node
        struct node *current = head; // Start from the head
        while (current->next != NULL) { // Loop until the last node is found
            current = current->next; // Move to the next node
        }
        current->next = node; // Link the last node to the new node
    }
    return head; // Return the pointer to the head of the list
}

// Function to swap the data of two nodes
void swap_nodes(struct node *a, struct node *b) {
    char temp[20]; // Temporary variable to store a name
    strcpy(temp, a->name); // Copy a's name to temp
    strcpy(a->name, b->name); // Copy b's name to a's name
    strcpy(b->name, temp); // Copy temp's name to b's name
}

// Function to sort a linked list of names in alphabetical order using bubble sort algorithm
void sort_list(struct node *head) {
    int swapped; // Flag to indicate if any swap occurred in a pass
    struct node *current; // Pointer to the current node in a pass
    struct node *last = NULL; // Pointer to the last unsorted node in a pass

    if (head == NULL) { // If the list is empty, do nothing
        return;
    }

    do {
        swapped = 0; // Initialize swapped to 0 at the beginning of each pass
        current = head; // Initialize current to the head at the beginning of each pass

        while (current->next != last) { // Loop until the last unsorted node is reached
            if (strcmp(current->name, current->next->name) > 0) { // If the current name is greater than the next name in lexicographical order, swap them
                swap_nodes(current, current->next); // Swap the data of current and next nodes
                swapped = 1; // Set swapped to 1 to indicate that a swap occurred
            }
            current = current->next; // Move to the next node
        }
        last = current; // Set last to the current node, which is now sorted

    } while (swapped); // Repeat until no swap occurs in a pass, which means the list is sorted
}

// Function to print a linked list of names
void print_list(struct node *head) {
    struct node *current = head; // Start from the head
    while (current != NULL) { // Loop until the end of the list is reached
        printf("%s\n", current->name); // Print the name of the current node
        current = current->next; // Move to the next node
    }
}

// Main function to test the code
int main() {
    struct node *head = NULL; // Initialize an empty list

    // Create some nodes with names and insert them into the list
    head = insert_node(head, create_node("Zeynep"));
    head = insert_node(head, create_node("Emre"));
    head = insert_node(head, create_node("Ayse"));
    head = insert_node(head, create_node("Musa"));
    head = insert_node(head, create_node("Remzi"));

    printf("The original list is:\n");
    print_list(head); // Print the original list

    sort_list(head); // Sort the list

    printf("The sorted list is:\n");
    print_list(head); // Print the sorted list

    return 0;
}

