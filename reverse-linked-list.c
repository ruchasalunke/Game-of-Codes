#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};
struct Node* reverseList(struct Node* head)
{
    struct Node *curr = head, *prev = NULL, *next;
    while (curr != NULL) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void printList(struct Node* node)
{
    while (node != NULL) 
    {
        if (node->next != NULL)
            printf("%d -> ", node->data);
        else
            printf("%d", node->data);
        node = node->next;
    }
}
struct Node* createNode(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
int main()
{
    int n;
    scanf("%d",&n);
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i=0; i<n; i++) 
    {
        int data;
        scanf("%d", &data);
        struct Node* new_node = createNode(data);
        if (head == NULL) 
        {
            head = new_node;
            tail = new_node;
        }
        else 
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    head = reverseList(head);
    printList(head);
    printf("\n");
    return 0;
}
