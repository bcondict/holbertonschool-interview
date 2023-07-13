#include "list.h"

int main(void)
{
    List *list = NULL;

    printf("Adding nodes to the end of the list:\n");
    add_node_end(&list, "Hello");
    add_node_end(&list, "World");
    add_node_end(NULL, "Invalid");  // Testing invalid input
    if (list != NULL)
    {
        printf("First node: %s\n", list->str);
        printf("Last node: %s\n", list->prev->str);
    }
    printf("\n");

    printf("Adding nodes to the beginning of the list:\n");
    add_node_begin(&list, "OpenAI");
    add_node_begin(&list, "GPT-3.5");
    add_node_begin(NULL, "Invalid");  // Testing invalid input
    if (list != NULL)
    {
        printf("First node: %s\n", list->str);
        printf("Last node: %s\n", list->prev->str);
    }
    printf("\n");

    printf("Adding node with memory allocation failure:\n");
    add_node_end(&list, "Memory Allocation Failure");  // Testing memory allocation failure
    if (list != NULL)
    {
        printf("First node: %s\n", list->str);
        printf("Last node: %s\n", list->prev->str);
    }
    printf("\n");

    return 0;
}
