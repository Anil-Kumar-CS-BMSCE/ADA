#include <stdio.h>
#define LEFT -1
#define RIGHT 1
int getMobile(int a[], int dir[], int n)
{
    int mobile = 0, mobilePos = -1;
    for(int i = 0; i < n; i++)
    {
        if(dir[i] == LEFT && i != 0 && a[i] > a[i - 1])
        {
            if(a[i] > mobile)
            {
                mobile = a[i];
                mobilePos = i;
            }
        }
        if(dir[i] == RIGHT && i != n - 1 && a[i] > a[i + 1])
        {
            if(a[i] > mobile)
            {
                mobile = a[i];
                mobilePos = i;
            }
        }
    }
    return mobilePos;
}
void printPermutation(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n], dir[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }
    printPermutation(a, n);
    while(1)
    {
        int mobilePos = getMobile(a, dir, n);
        if(mobilePos == -1)
            break;
        int swapPos;
        if(dir[mobilePos] == LEFT)
            swapPos = mobilePos - 1;
        else
            swapPos = mobilePos + 1;
        int temp = a[mobilePos];
        a[mobilePos] = a[swapPos];
        a[swapPos] = temp;
        temp = dir[mobilePos];
        dir[mobilePos] = dir[swapPos];
        dir[swapPos] = temp;
        mobilePos = swapPos;
        int mobile = a[mobilePos];
        for(int i = 0; i < n; i++)
        {
            if(a[i] > mobile)
                dir[i] = -dir[i];
        }
        printPermutation(a, n);
    }
    return 0;
}
