#include<stdio.h>
#include<stdlib.h>
struct block
{
	int size;	//stores size fo memory block
	int isFree;	//stores whether the memory block is free
};
int main()
{
	struct block *memory;
	printf("%s\n","Total memory size:200kB\n ");	
	memory=(struct block*)malloc(200);
	int processSize=0;
	int i=0;
	int spaceAvail=200;
	int occupied=0;
	int count=2;
	//inputs 3 processes from the user and allocates block of memory
	for(i=0;i<3;i++)
	{
		printf("%s\n","Enter process size:" );
		scanf("%d",&processSize);
		occupied+=processSize;
		//if there is not sufficient memory available.
		if(occupied>spaceAvail)
			printf("Not enough memory available!\n");
		else
			(memory+i)->size=processSize;
			(memory+i)->isFree=0;
	}
	printf("List of process:\n");
	for(i=0;i<3;i++)
	{
		printf("%d kB\n",(memory+i)->size);
	}
	int ch;
	int ptr=0;
do
{
	//menu to allocate and free a process.
	ch=0;
	printf("\n\n%s\n","1)Allocate process");
	printf("%s\n","2)Free a process");
	printf("%s\n","Press 0 to exit" );
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("%s\n","Enter process size:" );
		scanf("%d",&processSize);
		int occ=occupied+processSize;
		if(occ>spaceAvail)
		{
			printf("\nNot enough memory available!\n");
			printf("Available space: %d\n",spaceAvail-occupied);
		}
		else
			{
			int flag=0;
			int flag2=0;
			int j;
			occupied+=processSize;
			for(j=0;j<=count;j++)
			{
				//Best fit algorithm
				if((memory+j)->size>processSize )	
				{
					if(flag2==0 ||( memory+j)->size<(memory+ptr)->size)
					{
			
					
					if((memory+j)->isFree==1)
					{		
							ptr=j;
							flag2=1;
					}
					}
				}
			}
						if(flag2==1)
						{
							(memory+ptr)->size=processSize;
							(memory+ptr)->isFree=0;
							flag=1;
						}
				
			if(flag!=1)
			{
				if(j==count && ((memory+j)->isFree=1))
						{
							(memory+j)->size=processSize;
							(memory+j)->isFree=0;
							flag=1;
						}
			}
			if(flag!=1)
			{
				(memory+i)->size=processSize;
				(memory+i)->isFree=0;
				count+=1;
			}

			printf("List of process:\n");
			for(i=0;i<=count;i++)
			{
				printf("%d kB\n",(memory+i)->size);
				printf("Is it free? %d\n",(memory+i)->isFree );
			}
		}
	}
	//if the user wants to free processes.
	if(ch==2)
	{
		printf("%s\n","Enter process to be freed" );
		scanf("%d",&processSize);
		for(i=0;i<=count;i++)
			{
				if((memory+i)->size==processSize)
				{
					(memory+i)->isFree=1;
					occupied-=processSize;
				}
			}
		printf("\nList of process:\n");
		for(i=0;i<=count;i++)
		{
		printf("%d kB ",(memory+i)->size);
		printf("Is it free? %d\n",(memory+i)->isFree );
		}
	}
}
while(ch!=0);
}