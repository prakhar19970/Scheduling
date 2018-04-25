#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
void fun1(int t0 ,int t1,int t2,int t3);
void sch1();
void disp();
int n,i,j,k=0;

int main()
{
	printf("enter the no. of process");
scanf("%d",&n);
	int p[n];
	int bt[n];
	int at[n];
	int prior[n];
int waitprocess[n];	
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf(" for process %d enter the arrival time, burst time ,priority",(i+1));
		scanf("%d%d%d",&at[i],&bt[i],&prior[i]);
	}
	printf(" \n Process\t burst time\t arrival time\t priority\n");
for(i=0;i<n;i++)
	{
		printf(" P%d\t\t %d\t\t %d\t\t %d\t\t\n",(i+1),bt[i],at[i],prior[i]);
		printf("\n");
	}
int temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
		if(at[j]>at[j+1])
		{
			temp=at[j];
			at[j]=at[j+1];
			at[j+1]=temp;
			temp=0;
			
			temp=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=temp;
			temp=0;
			
			temp=prior[j];
			prior[j]=prior[j+1];
			prior[j+1]=temp;
			temp=0;
			
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
			temp=0;
}
	}
	
	}
		printf(" \n Process\t burst time\t arrival time\t priority\n");
		for(i=0;i<n;i++)
	{
		printf(" P%d\t\t %d\t\t %d\t\t %d\t\t\n",p[i],bt[i],at[i],prior[i]);
		printf("\n");
	}
	
	printf("P%d,will be executed first because arrival time %d\n",p[0],at[0]);
	
	for(i=0;i<n;i++)
	{
		int x=0;

		if(bt[i]>at[i+1])
			{
				if(prior[i]<prior[i+1])
			{
				printf("P%d,is executed\n",p[i]);
			p[i]=0;
			}
			
			   else 
			{
				x=bt[i]-at[i+1];
				if(x>0)
				{
	printf("P%d,is executed for %d miliseconds,\nP%dgoes in waiting state \nwith remaining time of %d milisecond\n",p[i+1],bt[i+1],p[i],x);
				waitprocess[k]=p[i];
				p[i+1]=0;
				k++;
			}
				}		
				}
		
		}
	
		
	for(i=0;i<n;i++)
	{
		if(waitprocess[i]!=0)
				printf("P%d,is executed\n",waitprocess[i]);
				p[i]=0;
	}
	
	int y;
	for(i=0;i<n;i++)
	{
	if(p[i]==0)
	y++;
}
	if(y==n)
	{
	printf("enter the no. of process");
scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf(" for process %d enter the arrival time, burst time ,priority",(i+1));
		scanf("%d%d%d",&at[i],&bt[i],&prior[i]);
	}
	printf(" \n Process\t burst time\t arrival time\t priority\n");
for(i=0;i<n;i++)
	{
		printf(" P%d\t\t %d\t\t %d\t\t %d\t\t\n",(i+1),bt[i],at[i],prior[i]);
		printf("\n");
	}
pritntf("here time quantum is taken as 2");
temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
		if(at[j]>at[j+1])
	{
			temp=at[j];
			at[j]=at[j+1];
			at[j+1]=temp;
			temp=0;
			
			temp=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=temp;
			temp=0;
			
			temp=prior[j];
			prior[j]=prior[j+1];
			prior[j+1]=temp;
			temp=0;
			
			temp=p[j];
			p[j]=p[j+1];
			p[j+1]=temp;
			temp=0;
}
}
}
int tq=2;
	printf("P%d,will be executed first because arrival time %d\n",p[0],at[0]);
for(i=0;i<n;i++)
{
	if(bt[i]>=tq)
	{
		x=bt[i]-tq;
	if(x>0)
	{
		waitprocess[i]=p[i];
		rem[i]=x;
	}
	else
	printf("P%d,is executed",p[i]);
	}
		
	}
	for(i=0;i<n;i++)
	{
		if(rem[i]>tq)
		{
			x=rem[i]-tq;
	if(x>0)
	{
		waitprocess[i]=p[i];
		rem[i]=x;
	}
			
		}
		}	
	
}
	void disp()
	{
			printf("value of n %d",n);
		printf(" \n Process\t burst time\t arrival time\t priority\n");
		for(i=0;i<n;i++)
	{
		printf(" P%d\t\t\t %d\t\t\t %d\t\t\t %d\t\t\t\n");
		printf("\n");
	}
		
	}
	
