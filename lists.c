#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        fprintf(stderr, "Can not allocate node!");
        exit(1);
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    }
    else {
        Node* curr = *head;
        while(curr -> next != NULL) {
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
}

void deallocateList(Node** head) {
    Node* curr = *head;
    while(curr != NULL) {
        Node* temp = curr;
        curr = curr -> next;
        free(temp);
    }
}

void removeNegativeNodes(Node** head) {
    if(*head == NULL) return;
    Node* curr = *head;
    Node* prev = NULL;
    while(curr != NULL) {
        if(curr -> data < 0) {
            Node* temp = curr;

            if(curr == *head) {
                *head = curr -> next;
            }
            else {
                prev -> next = curr -> next;
            }
            curr = temp -> next;
            free(temp);
        }
        else {
            prev = curr;
            curr = curr -> next;
        }
    }
}

void removeFromInterval(Node** head, int minValue, int maxValue) {
    if (*head == NULL) {
        // Handle case where head or *head is NULL
        return;
    }

    Node* curr = *head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->data >= minValue && curr->data <= maxValue) {
            Node* temp = curr;

            if (curr == *head) {
                // If curr is the head node
                *head = curr->next;
                curr = *head; // Move curr to the new head
            } else {
                // If curr is not the head node
                prev->next = curr->next;
                curr = prev->next; // Move curr to the next node after deletion
            }

            free(temp); // Free the memory for the deleted node
        } else {
            // If curr is not within the interval, move prev and curr forward
            prev = curr;
            curr = curr->next;
        }
    }
}


void removeNegAndNonPosAfter(Node** head) {
    // -1 -2 3

    if(*head == NULL) return;
    if((*head) -> data < 0 && (*head) -> next == NULL) {
        free(*head);
        return;
    }

    Node* curr = *head;
    Node* prev = NULL;
    while(curr != NULL && curr -> next != NULL) {
        /*
        -1 -2 3
        curr = -1 prev = NULL
        temp = -1 head = -2
        curr = -2 free(-1)
        prev = -2 curr = 3
        */

        if(curr -> data < 0 && curr -> next -> data <= 0) {
            Node* temp = curr;
            if(curr == *head) {
                *head = temp -> next;
            }
            else {
                prev -> next = curr -> next;
            }
            curr = curr -> next;
            free(temp);
        }
        else {
            prev = curr;
            curr = curr -> next;
        }
    }
}

void displayList(Node* head) {
    while(head) {
        printf("[%i] -> %d\n", head, head -> data);
        head = head -> next;
    }
}
