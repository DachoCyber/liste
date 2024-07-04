#ifndef _LISTS_H_
#define _LISTS_H_

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void appendNode(Node** head, int data);
Node* createNode(int data);
void displayList(Node* head);
void deallocateList(Node** head);
void removeNegativeNodes(Node** head);
void removeFromInterval(Node** head, int minValue, int maxValue);

#endif // _LISTS_H_
