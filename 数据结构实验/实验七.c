/*#include <stdio.h>
#include <stdlib.h>

int SeqSearch(int R[],int n,int k)
{
    int i=0;
    while(i<n && R[i]!=k)
    {
        printf("%d ",R[i]);
        i++;
    }
    if(i>=n)
        return -1;
    else
    {
        printf("%d ",R[i]);
        return i;
    }

}

int main() {
  int a[10] = {9,13,15,7,45,32,56,89,60,36};
  int k, loc;
  printf("Please input your number: \n");
  scanf("%d", &k);
  loc=SeqSearch(a, 10, k);
  printf("\n");
  printf("The number's location is %d\n ", loc);
  return 0;
}   */

#include <stdio.h>
#include <stdlib.h>

int BinSearch(int R[], int n, int k)
{
    int low=0,high=n-1,mid,count=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        printf("第%d次查找：在[ %d ,%d]中找到元素R[%d]:%d\n ",++count,low,high,mid,R[mid]);
        if(R[mid]==k)
            return mid;
        if(R[mid]>k)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

int main()
{
    int a[11] = {5, 7, 9, 12, 15, 18, 20, 22, 25, 30,100};
    int k, loc;
    printf("Please input your number: \n");
    scanf("%d", &k);
    loc=BinSearch(a, 11, k);
    if(loc == -1)
        printf("not find!");
    return 0;
}
