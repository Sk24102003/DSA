#include<stdio.h>
#include<stdlib.h>
void merge(int *a, int low, int mid, int high)
{
    int k; int* b;
    int h = low;
    int j = mid+1;
    int i = low;
    b = (int *)malloc((high+1)*sizeof(int));
    if(b==NULL)
    {
        printf("Insufficient Memory!!\n");
        exit(0);
    }
    while((h<=mid)&&(j<=high))
    {
        if(*(a+h)<=*(a+j))
        {
            *(b+i) = *(a+h);
            h++;
        }
        else
        {
            *(b+i) = *(a+j);
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            *(b+i) = *(a+k);
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            *(b+i) = *(a+k);
            i++;
        }
    }
    for(k=low;k<=high;k++)
    {
        *(a+k) = *(b+k);
    }
}
void mergeSort(int *a, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
int main(void)
{
    int *a, n, i;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        printf("Insufficient Memory!!\n");
        exit(0);
    }

    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d", (a+i));
    }

    printf("\nBefore sorting the elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t", *(a+i));
    }
    
    mergeSort(a, 0, n-1);
    printf("\nAfter sorting the elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t", *(a+i));
    }
    return 0;
}