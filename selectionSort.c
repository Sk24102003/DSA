#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *a, int n)
{
    int i, j, smallest;
    for(i=0;i<=n-2;i++)
    {
        smallest = i;
        for(j=i+1;j<=n-1;j++)
        {
            if(*(a+j) < *(a+smallest))
                smallest = j;
        }
        if(smallest != i)
        {
            *(a+smallest) = *(a+smallest) + *(a+i);
            *(a+i) = *(a+smallest) - *(a+i);
            *(a+smallest) = *(a+smallest) - *(a+i);
        }
    }
}

int main(void)
{
    int n, *a, i;
    printf("\nEnter the no. of elements: ");
    scanf("%d",&n);
    a = (int* )malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("Insufficient Memory!!");
        exit(0);
    }
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",(a+i));
    printf("\nBefore sorting the elements are: ");
    for(i=0;i<n;i++)
        printf("%d  ",*(a+i));
    selectionSort(a,n);
    printf("\nAfter sorting the elements are: ");
    for(i=0;i<n;i++)
        printf("%d  ",*(a+i));
    return 0;
}