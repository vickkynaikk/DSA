#include <stdio.h>
void bubbleSort(int arr[], int n);
int main()
 {
  int n;
  printf("enter the number of elements:   ");
  scanf("%d", &n);

  int arr[n];
  printf("enter the elements:\n"0);
  for (int i=0; i < n; i++)
     {
          scanf("%d ", arr[i]);
     }

bubbleSort(arr, n);
printf("Sorted array: ");
for (int i=0; i < n; i++)
   {
        printf("%d ", arr[i]);
   }
return 0;
}


void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
  {
        for (j = 0; j < n-i-1; j++)
      {
            if (arr[j] > arr[j+1])
           {
                  temp = arr[j];                                                                               // swap arr[j] and arr[j+1]
                  arr[j] = arr[j+1];
                  arr[j+1] = temp;
            }
        }
    }
}


