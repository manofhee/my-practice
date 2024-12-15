#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void reverseList(struct Node** headRef) {
    struct Node* prev = NULL;
    struct Node* curr = *headRef;
    struct Node* next = NULL;
    
    while (curr != NULL) {
        // store the next code
        next = curr->next;

        // reverse curr node
        curr->next = prev;

        // move pointer ahead by one
        prev = curr;
        curr = next;
    }

    // update the head pointer
    *headRef = prev;
}
