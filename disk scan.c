#include<stdio.h>
#include<stdlib.h>
void direc(int l,int index, int a[],int size,int n)
{
	int i,seek=0;
	if(l==1)
	{	
		printf("You have chosen right direction:\n");
		seek+=abs((size)-a[index]);
		for(i=index;i!=(n+1);i++)
		{
			printf("%d->",a[i]);
		}

		printf("%d->",(size));
		seek+=abs((size)-a[0]);
		for(i=index-1;i!=0;i--)
		{
			printf("%d->",a[i]);
		}
		printf("%d",a[i]);			
	}
	else if(l==0)
	{
		printf("You have chosen left direction:\n");
		i=index;
		seek+=abs(a[i]-0);
		for(i=index;i!=0;i--)
		{
			printf("%d->",a[i]);
		}	
		printf("%d->0->",a[0]);
		seek+=abs((a[n])-0);
		for(i=index+1;i!=n;i++)
		{
			printf("%d->",a[i]);
			
			a[i]=0;
		}
		printf("%d\n",a[i]);		
	}
	printf("Total seek time: %d\n",seek);
	float avg_seek=(float)seek/(n+1);
	printf("Average seek time: %.2f\n",avg_seek);	
}
void main()
{
	int n,i,size,l,head,index,p,c,temp=0,dir;
	int a[100],b[100];
	printf("Enter the number of requests: ");
	scanf("%d",&n);
	int diff[n];
	printf("Enter the initial head position: ");
	scanf("%d",&a[0]);
	printf("Enter the requests: ");
	for(i=1;i<=n;i++)
	{
	scanf("%d",&a[i]);
	b[i]=a[i];
	}	
	head=a[0];
	printf("Enter size of disk: ");
	scanf("%d",&size);
	printf("Enter the direction of movement:\n 1 for right\n0 for left:\n");
	scanf("%d",&dir);
	for(p=1;p<n+1;p++)
	{
	for(c=0;c<n-p+1;c++)
	 {
		if(a[c]>a[c+1])
		{
			temp=a[c];
			a[c]=a[c+1];
			a[c+1]=temp;
		}
	 }
	}
	for(i=0;i<=n;i++)
	{
		if(head==a[i])
		{
			index=i;

			break;
		}
	}
	direc(dir,index,a,(size-1),n);
}
