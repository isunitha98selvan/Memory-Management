//paging using process table
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Random;
import java.util.Hashtable;

class memory
{
//class to implement the memory. The memory consists of frames of equal sizes.
	public static String a[]=new String[20];
	public static int frames_occupied=0;
	Hashtable<String,Integer> hm= new Hashtable<String,Integer>();
 	//process table
	void assign(LinkedList<String> pages)
	{
		//assign pages to frames in memory.
		int blocks=pages.size();
		int address;
		int flag=0;
		for(int i=0;i<blocks;i++)
		{
			flag=0;
			int k=0;
			do
			{
				//each page is hashed to a frame.
				address=(pages.get(i).hashCode()+k)%20  ;
				k+=1;
				if(frames_occupied==20)
				{
					//there are 20 frames. If no frames are free, display error.
					System.out.println("Not enough frames!");
					break;
				}
				else if(a[address]==null)
				{
				a[address]=pages.get(i);
				hm.put(a[address],address);
				frames_occupied+=1;
				flag=1;
				}
			}
			while(flag==0);
		}
	}
	void mem()
	{
		//loop to print all the frames in memory.
		for(int i=0;i<20;i++)
		{	
			System.out.println(a[i]);
		}
	}
	void access(String page)
	{
			//function to access the frames which store the page.
			int flag=0;
			int k=0;
			do
			{
				int address=(page.hashCode()+k)%20  ;
				k+=1;

				if(a[address-1]!=null)
				{
					System.out.println(hm);
					System.out.println("Accesing memory! Printing value stored in frame");
					System.out.println(a[address-1]);
					flag=1;
				}
			}
			while(flag==0);
		}
}

public class paging
{
	public static void main(String args[])
	{
	//inputs a process and divides it into pages.
	//the pages are stored in a linekd list.
	memory m[]=new memory[10];
	for(int i=0;i<10;i++)
	{
		m[i]=new memory();
	}
	int memory_size=1000; 		
	//memory size is 1000kB
	int size=50;
	int blocks=memory_size/size;
	Scanner input=new Scanner(System.in);
	LinkedList<String> page_no=new LinkedList<String>();
	int n;
	int ch=1;
	int processNum=0;
	//menu to accept process from user and allocate frames using page table.
	do
	{
		if(ch==1)
		{
		System.out.println("Enter a process size: ");
		n=input.nextInt();
		int block_req=(int)Math.ceil(n/size);
		for(int i=1;i<=block_req;i++)
		{
			String result=""+ processNum +i;
			page_no.add(result);
		}
		System.out.println(page_no);
		m[processNum].assign(page_no);
		processNum+=1;
		while(!page_no.isEmpty())
		{
			page_no.remove();
		}
		}
		else if(ch==2)
		{
			System.out.println("Enter process number\n");
			int pNo=input.nextInt();
			System.out.println("Enter page number");
			input.nextLine();
			String page=input.nextLine();
			m[pNo].access(page);

		}
		else if(ch==3)
		{
			m[processNum].mem();
		}
		System.out.println("1)Do you want to enter more processes?");
		System.out.println("2)Do you want to view a process table?");
		System.out.println("3)View memory");
		System.out.println("4)Exit");
		ch=input.nextInt();
	}
	while(ch==1 || ch==2 || ch==3);
	}
}
