#include<stdio.h>
#include<conio.h>
int a[10],c[10],i,j,k,n,beg,end;
void mergesort(int[],int ,int);
void merging(int[],int,int,int,int);
int main()
{
    printf("\n enter the number of array elements");
    scanf("%d",&n);
    printf("\n enter array elements");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n enter ered array elements are");
    for(i=1;i<=n;i++)
    {
        printf("\n%d",a[i]);
    }
    mergesort(a,1,n);
    printf("\n the sorted array");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
void mergesort(int a[],int beg,int end)
{
    int mid;
    if(beg<end)
    {
        mid=(beg+end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merging(a,beg,mid,mid+1,end);
    }
}

void  merging(int a[],int lb,int m,int m1,int ub)
{
    i=lb;
    k=lb;
    j=m1;
    while(i<=m&&j<=ub)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i++;
        }
        else
        {
            c[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>m)
    {
        while(j<=ub)
        {
            c[k]=a[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<=m)
        {
            c[k]=a[i];
            k++;
            i++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        a[k]=c[k];
    }
}
