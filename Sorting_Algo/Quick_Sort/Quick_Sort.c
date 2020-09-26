#include<stdio.h>
#define max 6
int a[max];
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int low, int high){
	int i=low-1;
	int pv = a[high];
	for(int j=low;j<=high-1;j++){
		if(a[j]<pv){
			i++;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[high],&a[i+1]);

	return (i+1);
}

void quicksort(int low,int high)
{
	printf("\n");


	if(low<high)
  {

		int p = partition(low,high);

		quicksort(low,p-1);
		quicksort(p+1,high);

	}
}

void printArray(){
	printf("\n");
	printf("Array After Sorting is:");
	for(int i=0;i<max;i++){
		printf("%d ",a[i]);
	}
}

int main()
{   

		for(int p=0;p<max;p++)
    {
			int num;
			printf("Enter number to insert in array:\n");
			scanf("%d",&num);
			a[p]=num;
    }

		quicksort(0,max-1);
		printArray();
return 0;
}