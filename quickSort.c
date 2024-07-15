#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    *b = (*a + *b) - (*a = *b);
}
int partition(int *arr, int low, int high)
{
    int i, j, pivot;
    pivot = *(arr+low);
    j = low;
    for(i=low+1;i<=high;i++)
    {
        if(*(arr+i)<pivot)
        {
            j++;
            swap((arr+i), (arr+j));
        }
    }
    swap((arr+low), (arr+j));
    return j;
}
void quickSort(int *arr, int low, int high)
{
    int j;
    if(high>low)
    {
        j = partition(arr, low, high);
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}
int main(void)
{
    int *arr, n, i;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    arr=(int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Insufficient Memory!!\n");
        exit(0);
    }

    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", (arr+i));
    }

    printf("\nBefore sorting the elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t", *(arr+i));
    }
    
    quickSort(arr, 0, n-1);
    printf("\nAfter sorting the elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t", *(arr+i));
    }
    return 0;
}