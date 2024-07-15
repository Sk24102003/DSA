#include<stdio.h>
#include<stdlib.h>

void maxHeap(int *a, int i, int n)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    int temp;
    if(l<n && *(a+l)>*(a+i))
        largest = l;
    if (r<n && *(a+r)>*(a+largest))
        largest = r;
    if(largest!=i)
    {
        temp = *(a+largest);
        *(a+largest) = *(a+i);
        *(a+i) = temp;
        maxHeap(a, largest, n);
    }
}

void heapify(int *a, int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        maxHeap(a, i, n);
    }
}

void heapSort(int *a, int n)
{
    int i, temp;
    heapify(a, n);
    for(i=n-1;i>=1;i--)
    {
        temp = *(a+i);
        *(a+i) = *(a+0);
        *(a+0) = temp;
        maxHeap(a, 0, i);
    }
}

int main(void)
{
    int n, *a, i;
    printf("Enter the no. of element: ");
    scanf("%d",&n);
    a = (int* )malloc(n*sizeof(int));
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", (a+i));
    }
    printf("Before sorting, the elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", *(a+i));
    }
    heapSort(a, n);
    printf("\nAfter sorting, the elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", *(a+i));
    }
    return 0;
}