#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Node {
    int data;
    struct Node* nextAddress;
};

struct Node* createLinkedList() {
    struct Node* head = NULL;

    return head;
}

struct Node* insertAtBeginning(struct Node* head, int x) {
    struct Node* newNodeAdrress = (struct Node*)malloc(sizeof(struct Node));
    (*newNodeAdrress).data = x;
    
    if (head == NULL) {
        head = newNodeAdrress;
        newNodeAdrress->nextAddress = NULL;
        return head;

    }

    (*newNodeAdrress).nextAddress = head;
    head = newNodeAdrress;

    return head;

};

void insertAtIndex(struct Node* head, int x, int i) {
    struct Node* newNodeAdrress = (struct Node*)malloc(sizeof(struct Node));
    (*newNodeAdrress).data = x;

    int index = 0;
    int stopAt = i;
    struct Node* traveser = head;
    struct Node* prevAddress;

    while(traveser != NULL || stopAt != index) {
        prevAddress = traveser;
        traveser = traveser->nextAddress;
        index++;

    }

    prevAddress->nextAddress = newNodeAdrress;

    if(stopAt > index) {
        printf("Error: index out of bounds, elemeted inserted at the end of the list on index %d\n\n", index);
        return;
    }

    return;

}

void insertAtEnd(struct Node* head, int x) {
    struct Node* newNodeAdrress = (struct Node*)malloc(sizeof(struct Node));
    (*newNodeAdrress).data = x;

    struct Node* traveser = head;
    struct Node* prevAddress;

    if(head = NULL) {
        printf("linkedList is NULL, please use insertAtBeginning\n\n");
        return;
    }

    while(traveser != NULL) {
        prevAddress = traveser;
        traveser = traveser->nextAddress;

    }

    prevAddress->nextAddress = newNodeAdrress;

    return;
}

void printList(struct Node* head) {
    struct Node* traveser = head;

    if(head == NULL) {
        printf("Error: list is NULL");
        return;
    }

    printf("[ ");
    while(traveser != NULL) {
        if(traveser->nextAddress == NULL) {
            printf("%d", traveser->data);
            break;
        }

        printf("%d, ", traveser->data);
        traveser = traveser->nextAddress;
    }

    printf(" ]\n");

    return;
}


int main() {

    int size;
    int x; //data to insert


    printf("How many digits do you want to store?\n");
    scanf("%d", &size);

    struct Node* head = NULL;

    int i;

    for( i = 0; i < size; i++) {
        printf("Enter a number: ");
        scanf("%d", &x);

        if(i == 0) {
           head = insertAtBeginning(head, x);

        } else {
            insertAtEnd(head, x);
        }
    }

    printList(head);

    char y[5];

    printf("\nWant to make a change? Y/N? ");
    scanf("%s", y);

    if (strcmp("y", y) == 0 || strcmp("Y", y) == 0 || strcmp("yes", y) == 0 || strcmp("YES", y) == 0 ) {
        int j;
        printf("\nWhich position do you want to insert a number? ");
        scanf("%d", &j);

        printf("\nEnter number to insert: ");
        scanf("%d", &x);

        insertAtIndex(head, x, j);
        printList(head);
        printf("\nThat's the last of it. Have a good day.");
    } else if (strcmp("N", y) == 0 || strcmp("NO", y) == 0 || strcmp("no", y) == 0 || strcmp("n", y) == 0) {
        printf("\nAcknowledged! Have a good day.\n");

    } else {
        printf("\nInvalid selection. Please enter valid input! Y/N, yes/no or y/n.\n");
    }
    

    return 0;
};