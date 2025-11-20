#include<stdio.h>
int arr[10];
int display()
{
	printf("enter the elements of the array :\n");
	for(int i =0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("the elements of the array are :-- \n");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}



int max()
{
	int max=arr[0];
	for(int i=0;i<10;i++)
	{
		if(arr[i]>max)
		max=arr[i];
		
	}
	printf("largest element of the array is  %d",max);
	printf("\n\n");
}

int min()
{
	int min=arr[0];
	for(int i=0;i<10;i++)
	{
		if(arr[i]<min)
		{
			min=arr[i];
		}
		
	}
		printf("smallest element of the array is : %d ",min);
		printf("\n\n");
}


int LS()
{

int a;
	printf("enter the element you want to search for :-- \n");
	scanf("%d",&a);
	for(int i=0;i<10;i++)
	{
		if(arr[i]==a)
		{
			printf("element found");
		}
		else if(arr[i]!=a)
		{	
		printf("element not found");
		
		break;
		}
	}
	
}




int main()
{
	display();
	max();
	min();
	LS();
}