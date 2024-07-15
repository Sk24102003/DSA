#include <stdio.h>
#include <stdlib.h>

void insert(int *ptr, int n, int item, int pos)
{
    int i;
    ptr = realloc(ptr, (n + 1) * sizeof(int));
    if (ptr == NULL)
    {
        printf("Insufficient Memory!!!\n");
        exit(0);
    }

    for (i = n; i >= pos; i--)
    {
        *(ptr + i) = *(ptr + i - 1);
    }
    *(ptr + (pos - 1)) = item;
    n++;

    printf("After inserting the element the array will be :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    free(ptr);
    ptr = NULL;
}
int main(void)
{
    int n, *ptr, i, item, pos;
    printf("Enter size :\n");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Insufficient Memory!!!\n");
        exit(0);
    }

    printf("Enter the elements of the array :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }

    printf("Enter the element to insert :\n");
    scanf("%d", &item);

    printf("Enter the position where the item to be inserted :\n");
    scanf("%d", &pos);

    insert(ptr, n, item, pos);

    free(ptr);
    ptr = NULL;
    return 0;
}
