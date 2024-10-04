#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node* insert(struct Node *head, int data, int p)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(p==0)
    {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    for (int i = 0; i<p-1 && current!=NULL; i++)
        current = current->next;
    if(current == NULL)
    {
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}
void printList(struct Node* head) 
{
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main()
{
    int n,data,p;
    struct Node *head = NULL;
    struct Node* tail = NULL;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&data);
        struct Node* newNode = createNode(data);
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &data);
    scanf("%d", &p);
    head = insert(head, data, p);
    printList(head);
    return 0;
}