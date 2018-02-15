//A memory management system
#include<stdio.h>
#include<stdlib.h>

void BestFit(int blockSize[],int m,int processSize[],int n)
{
	//allocates smallest block that is larger than the process.
	int memory[m];
	int BestFit=0;
	int i;
	int j;
	int k;
	for(i=0;i<m;i++)
	{
		memory[m]=0;	//all memory blocks are free
	}

	for(i=0;i<n;i++)		
	{
		BestFit=0;
		for(j=0;j<m;j++)			//find a suitable block for each process
		{	
			if(processSize[i]<=blockSize[j])
			{
				if(blockSize[BestFit]>=blockSize[j] || blockSize[BestFit]<processSize[i])
				{
						BestFit=j;	
				}
			}
		
		}

		if(blockSize[BestFit]-processSize[i]<0)			//check if there is sufficent memory
		{
			printf("Process size: %d\n", processSize[i]);
			printf("%s\n","Not enough memory!" );
		}
		else
		{
			//Displays the process and block allocated.
			memory[i]=blockSize[BestFit];				
			printf("Process of size %d :",processSize[i]);
			printf("Allocated to block of size: %d\n",blockSize[BestFit]);
			blockSize[BestFit]-=processSize[i];
			printf("Space left in block: %d\n", blockSize[BestFit]);
		}
	}
}	
void Firstfit(int blockSize[],int m, int processSize[],int n)
{
	//allocates the first free block that is larger than the process
	int i=0;
	int j=0;
	int memory[n];
	for(i=0;i<n;i++)
	{
		int flag=0;
		for(j=0;j<m;j++)
		{
			if(processSize[i]<=blockSize[j])		//finds first block larger than process
			{
				memory[i]=blockSize[j];
				printf("Process of size %d :",processSize[i]);
				printf("Allocated to block of size: %d\n",blockSize[j]);
				blockSize[j]-=processSize[i];
				printf("Space left in block: %d\n", blockSize[j]);
				flag=1;
				break;
			}

		}
		if(flag!=1)		//if no block is found display error
		{
			printf("Process size: %d\n", processSize[i]);
			printf("%s\n","Not enough memory!" );
		}

			

	}

}

void WorstFit(int blockSize[],int m, int processSize[],int n)
{
	//find the largest block that is larger than the process
	int i,j;
	int memory[n];
	for(i=0;i<n;i++)
	{
		int WorstFit=0;
		for(j=0;j<m;j++)
		{
			if(processSize[i]<=blockSize[j])
			{
				if(blockSize[WorstFit]<=blockSize[j] || blockSize[WorstFit]<processSize[i])
				{
						WorstFit=j;	
				}
			}

		}
		if(blockSize[WorstFit]-processSize[i]<0)		//if there is not sufficient memory
		{
			printf("Process size: %d\n", processSize[i]);
			printf("%s\n","Not enough memory!" );
		}
		else
		{
			memory[i]=blockSize[WorstFit];
			printf("Process of size %d :",processSize[i]);
			printf("Allocated to block of size: %d\n",blockSize[WorstFit]);
			blockSize[WorstFit]-=processSize[i];
			printf("Space left in block: %d\n", blockSize[WorstFit]);
		}
	}
}

int main()
{
	int blockSize[]={100,500,200,300,600};		//predefined block sizes
	int processSize[]={212,417,112,426};		//process sizes
	int m=sizeof(blockSize)/sizeof(blockSize[0]);
	int n=sizeof(processSize)/sizeof(processSize[0]);

	//allocate memory for the above processes using best fit, firstfit and worstfit
	printf("%s\n","BestFit memory allocation: " );	
	BestFit(blockSize,m,processSize,n);

	int blockSize1[]={100,500,200,300,600};
	int processSize1[]={212,417,112,426};
	printf("\n\n%s\n","Firstfit memory allocation: ");
	m=sizeof(blockSize1)/sizeof(blockSize1[0]);
	n=sizeof(processSize1)/sizeof(processSize1[0]);
	Firstfit(blockSize1,m,processSize1,n);

	int blockSize2[]={100,500,200,300,600};
	int processSize2[]={212,417,112,426};
	printf("%s\n","WorstFit allocation: " );
	m=sizeof(blockSize2)/sizeof(blockSize2[0]);
	n=sizeof(processSize2)/sizeof(processSize2[0]);
	WorstFit(blockSize2,m,processSize2,n);

}