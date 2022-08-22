#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    /* data */
    int value;
    struct Node *next;
} Node;

void middle()
{
}
void quickSort()
{
}
void insertNode(Node **head, int value)
{
    struct Node *new_node = malloc(sizeof(new_node));
    new_node->value = value;
    new_node->next = NULL;
    struct Node *last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void iterateList(Node *node)
{
    while (node != NULL)
    {
        /* code */
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    /* code */
    int num = atoi(argv[1]);
    if (argc <= 1)
    {
        printf("Error Input\n");
        exit(1);
    }

    struct Node *head = malloc(sizeof(head));
    head->value = atoi(argv[1]);
    head->next = NULL;
    num = argc;
    for (int i = 2; i < num; ++i)
    {
        int v = atoi(argv[i]);
        insertNode(&head, v);
    }
    iterateList(head);
    printf("%d", head->value);
    return 0;
}
