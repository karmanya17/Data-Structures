#include<stdio.h>
int main()
{
	int a[100],position,c,n;
	printf("enter the no of elements in the array \n");
	scanf("%d",&n);
	printf("the elements of the array are \n");
	for(c=0;c<n;c++)
	{
		scanf("%d",&a[c]);
	}

	printf("enter the position from where the element is to be deleted\n");
	scanf("%d",&position);
	if(position>=n+1)
	printf("the deletion of element is not possible\n");
	else
	{
		for(c=position-1;c<n;c++)
		{
			a[c]=a[c+1];
			
		}
		printf("the resultant array is \n");
		for(c=0;c<n-1;c++)
		{
			printf("\n %d",a[c]);
		}
	}
	return 0;
}

