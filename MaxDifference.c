#include<stdio.h>
#include<stdlib.h>
struct element
{
	int value;
	int index;
};
int comp(void *a,void *b)
{
	int l = ((struct element *)a)->value; 
	int r = ((struct element *)b)->value;  
	return l - r;
}
int main()
{
	int n;
	printf("Enter size of array\n");
	scanf("%d",&n);
	struct element arr[n];
	printf("Enter elements\n");
	//scan element
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i].value);
		arr[i].index = i;
	}
	qsort(arr,n,sizeof(arr[0]),comp);
	int max=0;
	int min=arr[0].value;
	for(int i=1;i<n;i++)
	{
		if((arr[i].value-min)>max)
       		{
           		max=arr[i].value-min;
       		}
       		if(arr[i].value<min)
       		{
           		min=arr[i].value;
        	}
   	}    
   	printf("%d\n",max);
    	return 0;

}
