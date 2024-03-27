#include <stdio.h>
void traverse(int array[], int size);
void updation(int array[]);
void insertion(int array[]);
void deletion(int array[]);

void main()
{
     int first[5]={2,4,6,8,10};
     traverse(first, 5);
     updation(first);
     traverse(first, 5);
     insertion(first);

}

void traverse(int array[], int size)
{
     printf("\nTraverse: ");
     for(int i=0; i<size; i++)
     {
          printf("%d ", array[i]);
     }
}

void updation(int array[])
{
     int idx, data;
     printf("\nIndex to update? ");
     scanf("%d", &idx);
     printf("Updated value? ");
     scanf("%d", &data);
     array[idx]=data;
}

void insertion(int array[])
{
     int idx, data, second[6];
     printf("\nIndex to insert? ");
     scanf("%d", &idx);
     printf("New value? ");
     scanf("%d", &data);

     for(int i=0; i<=idx-1; i++)
     {
          second[i]=array[i];
     }
     second[idx]=data;
     for(int i=idx+1; i<=5; i++)
     {
          second[i]=array[i-1];
     }
     traverse(second, 6);
}

void deletion(int array[]){
     int idx, second[5];
     printf("\nIndex to delete? ");
     scanf("%d", &idx);
     for(int i=0; i<=idx-1; i++)
     {
          second[i]=array[i];
     }
     for(int i=idx+1; i<=5; i++)
     {
          second[i-1]=array[i];
     }
     traverse(second, 5);
}