#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertNodeAtHead(struct Node* head, int data){
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node)); 
    
    if(newHead == NULL){
        printf("Memory allocation failed");
        return 1;
    }

    newHead->data = data;
    newHead->next = head;

    return newHead;
}

void displayLinkedList(struct Node* head){
    while(head != NULL){
        printf("Value of node is %d\n", head->data);
        head = head->next;
    }

}

int main(){
    int n;
    int newHeadData;

    struct Node* head = NULL;
    // struct Node* temp = NULL;
    struct Node* tail = NULL;

    printf("How many nodes would you like to enter?");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("Memory allocation failed");
            return 1;
        }

        printf("Please enter the value for node number %d: ", i+1);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
            // temp->next = newNode;
        }

        // temp = newNode;

    }

    printf("Enter new node at head: ");
    scanf("%d", &newHeadData);

    head = insertNodeAtHead(head, newHeadData);

    printf("The linked list is as below \n");
    displayLinkedList(head);

    struct Node* temp = head;
    while(temp != NULL){
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}