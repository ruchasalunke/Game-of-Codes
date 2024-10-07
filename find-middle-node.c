#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int findMiddle(struct Node* head) 
{
    struct Node *s = head, *f = head;
    while (f != NULL && f->next != NULL) 
    {
        s = s->next;
        f = f->next->next;
    }
    return s->data;
}
int main() 
{
    int n;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        int data;
        scanf("%d",&data);
        struct Node* newNode = createNode(data);
        if(head == NULL)
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
    printf("%d\n",findMiddle(head));
    struct Node* current = head;
    while (current) 
    {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    return 0;
}
