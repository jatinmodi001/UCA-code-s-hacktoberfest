#include<stdio.h>
#include<stdlib.h>

struct dates
{
	int arrival;
	int departure;
};
int comp(const void *a,const void *b)
{
	int l = ((struct dates *)a)->arrival;
	int m = ((struct dates *)b)->arrival;
	return l-m;
}
int main()
{
	int rooms;
	printf("Enter the number of rooms : ");
	scanf("%d",&rooms);
	if(rooms == 0)
	{
		printf("Not Possible");
		return 0;
	}
	printf("Enter number of persons : ");
	int size;
	scanf("%d",&size);
	struct dates arr[size];
	printf("Enter arrival dates and departure\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i].arrival);
		scanf("%d",&arr[i].departure);
		if(arr[i].arrival > arr[i].departure)
		{
			printf("Not Possible");
			exit(0);
		}
	}
	int flag = 1;
	qsort(arr,size,sizeof(arr[0]),comp);
	rooms--;
	for(int i=1;i<size;i++)
	{
		
		if((arr[i].arrival <= arr[i-1].departure))
		{
			rooms--;		
		}
		for(int j=i;j>0;j--)
		{
			if(arr[i].arrival > arr[j-1].departure)
				rooms++;
		}
		if(rooms == 0)
		{
			flag = 0;
			break;
		}
	}
	if(flag)	
		printf("Possible\n");
	else
		printf("Not possible\n");
	return 0;
}
