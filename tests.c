#include <stdio.h>
#include "lists.h"


int test1() {
    Node* head1 = NULL;
    removeFromInterval(&head1, -1000, 1000);
    if(head1 != NULL) {
        printf("Function 'removeFromInterval' does not work!");
        return 0;
    }

    Node* head2 = NULL;
    removeNegAndNonPosAfter(&head2);
    if(head2 != NULL) {
        printf("Function 'removeNegAndNonPosAfter' does not work!");
        return 0;
    }
    Node* head3 = NULL;
    removeNegativeNodes(&head3);
    if(head3 != NULL) {
        printf("Function 'removeNegativeNodes' does not work!");
        return 0;
    }
    return 1;
}

int test2() {
    Node* head1 = NULL;
    appendNode(&head1, 1);
    appendNode(&head1, 2);
    removeFromInterval(&head1, 1, 3);
    if(head1 != NULL) {
        printf("Function 'removeFromInterval' does not work!");
        return 0;
    }


    Node* head2 = NULL;
    appendNode(&head2, -1);
    appendNode(&head2, -2);
    removeNegAndNonPosAfter(&head2);
    if(head2 -> data != -2 || head2 -> next != NULL) {
        printf("Function 'removeNegAndNonPosAfter' does not work!");
        return 0;
    }
    Node* head3 = NULL;
    appendNode(&head3, -1);
    removeNegativeNodes(&head3);
    if(head3 != NULL) {
        printf("Function 'removeNegativeNodes' does not work!");
        return 0;
    }
    return 1;
}


int test3() {
    Node* head1 = NULL;
    appendNode(&head1, 3);
    appendNode(&head1, 4);
    appendNode(&head1, 1);
    appendNode(&head1, 2);
    removeFromInterval(&head1, 1, 2);
    if(head1 -> data != 3 || head1 -> next -> data != 4 || head1 -> next -> next != NULL) {
        printf("Function 'removeFromInterval' does not work!");
        return 0;
    }


    Node* head2 = NULL;
    appendNode(&head2, -1);
    appendNode(&head2, 0);
    appendNode(&head2, -2);
    removeNegAndNonPosAfter(&head2);
    if(head2 -> data != 0 || head2 -> next -> data != -2 || head2 -> next -> next != NULL) {
        printf("Function 'removeNegAndNonPosAfter' does not work!");
        return 0;
    }
    Node* head3 = NULL;
    appendNode(&head3, -1);
    removeNegativeNodes(&head3);
    if(head3 != NULL) {
        printf("Function 'removeNegativeNodes' does not work!");
        return 0;
    }
    return 1;
}
