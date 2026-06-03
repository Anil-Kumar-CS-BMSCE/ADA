#include <stdio.h>
struct Item
{
    int weight;
    int profit;
    float ratio;
};
void sort(struct Item arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j].ratio < arr[j + 1].ratio)
            {
                struct Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    printf("Enter profit and weight of each item:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].profit, &arr[i].weight);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    sort(arr, n);
    float totalProfit = 0.0;
    for(int i = 0; i < n; i++)
    {
        if(capacity >= arr[i].weight)
        {
            capacity -= arr[i].weight;
            totalProfit += arr[i].profit;
        }
        else
        {
            totalProfit += arr[i].ratio * capacity;
            break;
        }
    }
    printf("Maximum Profit = %.2f\n", totalProfit);
    return 0;
}
