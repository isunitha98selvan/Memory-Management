//paging with linked list
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Random;
class memory_block
{
	String p1=null;
	memory_block link;
}
class memory
{
	//class to represent memory. Memory is divided into frames. if a process occupies multiple frames, each frame
	//points to the subsequent frame.
	public static memory_block m[]=new memory_block[20];
	public static int frames_occupied=0;
	memory_block head;

	void mem()
	{
		for(int i=0;i<20;i++)
		{
			System.out.println(m[i].p1);
		}
	}
	void assign(LinkedList<String> page)
	{
		//assigns frames to store the pages.
		int last=0;
		Random rand=new Random();
		int blocks=page.size();
		

		for(int i=0;i<20;i++)
		{
			m[i]=new memory_block();
		}
		for(int i=0;i<blocks;i++)
		{
			int k=0;
			int flag=0;
			do
			{
				//frames are assigned by hashing the pages.
				int address=(page.get(i).hashCode()+k)%20 ;
				System.out.println("Address: "+address);
				k+=1;
				if(m[address].p1==null)
				{
					m[address].p1=page.get(i);
					m[address].link=null;
					if(i!=0)
					{
						m[last].link=m[address];
					}
					if(i==0)
					{
						head=m[address];
					}
					flag=1;
					last=address;
				}
			}

			while(flag!=1);

		}
		memory_block current = head;
		System.out.println("Traversing through memory to view process");

		while (current!=null)
		{
			System.out.println(current.p1);
			current=current.link;
		}
	}
}

public class paging_linked
{
	public static void main(String args[])
	{
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
	do
	{
		//menu to accept process from user and allocate frames using linked list.
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
			m[processNum].mem();
		}
		System.out.println("1)Do you want to enter more processes?");
		System.out.println("2)View memory");
		System.out.println("3)Exit");
		ch=input.nextInt();
	}
	while(ch==1 || ch==2 || ch==3);
	}
}
