#include<stdio.h>
#include<stdlib.h>
struct block
{
	int size;	//stores size of memory block
	int processSize;	//stores process size.
	int isFree;		//stores whether there is a process allocated to this block or not.
};
//global variables
int processNum=0;
int occupied=0;
int spaceAvail=1000;
struct block *memory;		
//make a linked list of memory nodes
int k=0;
int freed=0;
//fucntion declarations
void allocateP();
void display();
void deleteP();
void compaction();
//displays menu for user.
void menu()
{
	int choice=0;
	do
	{
		printf("%s\n","1)Allocate process");
		printf("%s\n","2)Delete process");
		printf("%s\n","3)Compaction" );
		printf("%s\n","4)Exit");
		scanf("%d",&choice);
		if(choice==1)
			allocateP();
		if(choice==2)
			deleteP();
		if(choice==3)
			compaction();	
	}
	while(choice!=4);
}

void allocateP()
{
			//allocates a process for user using variable sized memory allocation. First fit scheme is used.
			int processSize=0;
			processNum+=1;
			int flag=0;
			printf("%s\n","Enter process size:" );
			scanf("%d",&processSize);
			//if sufficient memory is not available
			if(occupied+processSize>spaceAvail)
				printf("Not enough memory available!\n");
			else
			{
				occupied+=processSize;
				if(freed==1)
				{
					//if the memory block is free
					int j;
					for(j=0;j<processNum;j++)
					{
						if((memory+j)->processSize<(memory+j)->size && (memory+j)->size>processSize)
						{
							(memory+j)->processSize+=processSize;
							(memory+j)->isFree=0;
							flag=1;
							//count+=1;
							break;
						}
					}
				}
				if(flag!=1)
				{
					if((memory+k)->size==0)
					{
						(memory+k)->size=processSize;
						(memory+k)->processSize=processSize;
						(memory+k)->isFree=0;
						k+=1;
					}
				}
				
				display();
			}
}

void display()
{
	//displays all memory blocks and the process allocated to these blocks.
	int i=0;
	printf("\n\n%s\n","Displaying the list of processes: " );
	printf("%s\n\n","Process size(kB)                Size of memory occupied(kB)" );
	for(i=0;i<k;i++)
	{
		printf("%d                                   %d\n",(memory+i)->processSize,(memory+i)->size);
	}
	printf("Total space occupied: %d\n",occupied);
}

void deleteP()
{
	//frees the process from memory block by setting isFree to 1.
	int i,processSize;
	printf("%s\n","Enter process to be freed" );
	scanf("%d",&processSize);
	for(i=0;i<=processNum;i++)
		{
			if((memory+i)->size==processSize)
			{
				(memory+i)->isFree=1;
				(memory+i)->processSize=0;
				occupied-=processSize;
				freed=1;
			}
		}
	display();
}
void compaction()
{
	//function to implement compaction. Swaps all the free blocks to the end of the memory and combines all 
	//free space to one large chunk of memory.
	int flag2=0;
	int i;
	for(i=0;i<processNum;i++)
	{
		if((memory+i)->processSize==0 )
		{
			(memory+i)->processSize=(memory+k-1)->processSize;
			(memory+i)->isFree=(memory+k-1)->isFree;
			(memory+i)->size=(memory+k-1)->size;
			k-=1;
			printf("%d                                   %d\n",(memory+i)->processSize,(memory+i)->size);
			
		}
		//If there is internal fragmentation, swap the fragmented memory to the end and combine with the remaining
		//free space.
		else if((memory+i)->processSize<(memory+i)->size)
		{
			int x=(memory+i)->size-(memory+i)->processSize;
			(memory+i)->size=(memory+i)->processSize;
			k+=2;
			flag2=1;
		}
	}
	display();
	if(flag2==0)
		k+=1;
}
int main()
{
	
	printf("%s\n","Total memory size:200kB\n ");
	//allocate 200kb of memory
	memory=(struct block*)malloc(200);
	menu();
}