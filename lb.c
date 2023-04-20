#include<stdio.h>
void main()
{
	int in,out,bsize,n,b=0;
	printf("Enter the bucket size : ");
	scanf("%d",&bsize);
	printf("Enter the no. of inputs : ");
	scanf("%d",&n);
	printf("Enter the packet outgoing rate : ");
	scanf("%d",&out);
	while(n!=0)
	{
		printf("\nEnter the incoming packet size : ");
		scanf("%d",&in);
		printf("Incoming packet size is : %d\n",in);
		if (in<=(bsize-b))
		{
			b+=in;
			printf("Bucket status : %d out of %d\n",b,bsize);
		}
		else
		{
			printf("Dropped packets : %d\n",in-(bsize-b));
			printf("Bucket Status : %d out of %d\n",b,bsize);
			b=bsize;
		}
		b=b-out;
		printf("After outgoing,bucket status : %d out of %d\n",b,bsize);
		n--;
	}
}
