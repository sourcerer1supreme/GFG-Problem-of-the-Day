#include<iostream>
#include<stdlib.h>
using namespace std;

void merge(int a[],int low, int mid, int high);
void merge_sort(int a[], int low, int high);

void display(int a[], int n);

int main()
{
    int n,i;
    cout<<"Enter n: ";
    scanf("%d",&n);

    int *a = (int*)malloc(n*sizeof(int));

    printf("Enter the numbers: \n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    printf("\nUnsorted array is: \n");
    display(a,n);

    merge_sort(a,0,n-1);

    printf("\nSorted array is: \n");
    display(a,n);

    return 0;
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
       cout<<a[i]<<" ";
}

void merge_sort(int a[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low, int mid, int high)
{
    int temp[50];
    int i = low, k = low, j = mid+1;
    while (i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while(i<=mid)
        temp[k++] = a[i++];

    while(j<=high)
        temp[k++] = a[j++];

    for(i=low;i<=high;i++)
        a[i] = temp[i];
}
