#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

int n,n1,i,j,k=0,tot=0,x,c=0,atat=0,awt=0,minat=0;
int initia(){
	int n;
printf("enter the no. of process for first queue");
scanf("%d",&n);
return n;
}
int initia1(){
	int n;
printf("enter the no. of process for second queue");
scanf("%d",&n);
if(n!=0)
{
return n;
}
else
return 0;
}
		
int sch1(int x,int y)
{
int cal=0;
cal=x-y;
return cal;
	
}
int sch2(int x,int y)
{
int cal=0;
cal=x-y;
return cal;
	
}
int main()
{
n=initia();	
if(n>0)
{
n1=initia1();
int p1[n1];
	int p[n];   
	int bt[n];  int bt1[n1];
	int at[n];  int at1[n1];
	int prior[n]; int prior1[n1];
	int ct[n];
	int tat[n];
	int wt[n];
int waitprocess[n];
int ct1[n1];
	//initialization
	for(i=0;i<n;i++)
	{
		int x=0;
		p[i]=i+1;
		printf(" for process %d enter the arrival time, burst time ,priority",p[i]);
		scanf("%d%d%d",&at[i],&bt[i],&prior[i]);
	
	}
	for(i=0;i<n1;i++)
	{
		int x=0;
		p1[i]=i+1;
		printf(" for process %d enter the arrival time, burst time ,priority",p1[i]);
		scanf("%d%d%d",&at1[i],&bt1[i],&prior1[i]);
	
	}
//printing
	printf(" \n Process\t burst time\t arrival time\t priority\n");
for(i=0;i<n;i++)
	{
		printf(" P%d\t\t %d\t\t %d\t\t %d\t\t\n",p[i],bt[i],at[i],prior[i]);
		printf("\n");
	}
//sorting
int temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
		if(prior[j]>prior[j+1])
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
	//printing
	printf(" \n Process\t burst time\t arrival time\t priority\n");
for(i=0;i<n;i++)
	{
		printf(" P%d\t\t %d\t\t %d\t\t %d\t\t\n",p[i],bt[i],at[i],prior[i]);
		printf("\n");
	}
	
	minat=at[0];
	for(i=0;i<n;i++)
	{
		if(minat>at[i])
		{
			minat=at[i];
		}
	}
	
for(i=0;i<n;i++)
	{
		if(minat==at[i])
		{
			if(bt[i]>at[0])
			{
				x=bt[i]-at[0];
				printf("\n\nP%d,is executed  for %d miliseconds",p[i],at[0]);	      		     
			k=at[0];
			ct[i]=k;
			printf("\n\nP%d,is executed  for %d miliseconds",p[0],bt[0]);
			k=k+bt[0];
			ct[0]=k;
			printf("\n\nP%d is in waiting state  with remaining time of %d milisecond",p[i],x);
		    }
			if(x>0)
			{
				printf("\n\nP%d,is executed for %d miliseconds",p[i],x);	      		     
				k=k+x;
				ct[i]=k;			
			}
			else
			{
					printf("\n\nP%d,is executed for %d miliseconds",p[i],bt[i]);
					k=k+bt[i];
					ct[i]=k;
					x=at[0]-bt[i];
					if(x!=0)
					{
						k=k+x;
					}
					printf("\n\nP%d,is executed  for %d miliseconds",p[0],bt[0]);
					k=k+bt[0];
					ct[0]=k;
			}
    	}
	}
	for(i=2;i<n;i++)
	{
		printf("\n\nP%d,is executed for %d miliseconds",p[i],bt[i]);
		k=k+bt[i];
		ct[i]=k;
		c=i;
	}
		//tat=ct-at;
	//wt=tat-bt
	for(i=0;i<n;i++)
	{
	tat[i]=sch1(ct[i],at[i]);
}
for(i=0;i<n;i++)
{
	wt[i]=sch2(tat[i],bt[i]);
}

printf("\n \nWait time\t TAT\t CT\t Process\t burst time\t arrival time\t priority\n");
for(i=0;i<n;i++)
	{
		printf("%d\t\t %d\t %d\t  P%d\t\t %d\t\t %d\t\t %d\t\t\n",wt[i],tat[i],ct[i],p[i],bt[i],at[i],prior[i]);
		printf("\n");
	awt=awt+wt[i];
	atat=atat+tat[i];
	}
	
	printf("\n average waiting time %d ",(awt/n));
	printf("\n average turn around time %d ",(atat/n));	
	




		
//round robin
if((c+1)==n)
{	
for(i=0;i<n;i++)
	{
	p[i]=0;
}
}
	int y;
	for(i=0;i<n;i++)
	{
	if(p[i]==0)
	y++;
}

	if(y==n)
	{
	printf(" \n Process\t burst time\t arrival time\t priority\n");
for(i=0;i<n1;i++)
	{
		printf(" P%d\t\t %d\t\t %d\t\t %d\t\t\n",p1[i],bt1[i],at1[i],prior1[i]);
		printf("\n");
	}
int tq;
printf("enter time quantum in multiple of 2 \n");
scanf("%d",&tq);
if(tq%2==0)
{

temp=0;
	for(i=0;i<n1-1;i++)
	{
		for(j=0;j<n1-i-1;j++)
		{
		if(at1[j]>at1[j+1])
	{
			temp=at1[j];
			at1[j]=at1[j+1];
			at1[j+1]=temp;
			temp=0;
			
			temp=bt1[j];
			bt1[j]=bt1[j+1];
			bt1[j+1]=temp;
			temp=0;
			
			temp=prior[j];
			prior1[j]=prior1[j+1];
			prior1[j+1]=temp;
			temp=0;
			
			temp=p1[j];
			p1[j]=p1[j+1];
			p1[j+1]=temp;
			temp=0;
}
}
}
	printf(" \n Process\t burst time\t arrival time\t priority\n");
for(i=0;i<n1;i++)
	{
		printf(" P%d\t\t %d\t\t %d\t\t %d\t\t\n",p1[i],bt1[i],at1[i],prior1[i]);
		printf("\n");
	}

for(i=0;i<n1;i++)
{
tot=tot+bt1[i];
}

while(x!=tot)
{
for(i=0;i<n1;i++)
{
if(bt1[i]>tq)
{
x=x+tq;
printf("\n P%d -> %d",p1[i],tq);
bt1[i]=bt1[i]-tq;
}
else if(bt1[i]>0 && bt1[i]<=tq)
{
x=x+bt1[i];
printf("\n P%d -> %d",p1[i],bt1[i]);
bt1[i]=0;
}
}
}
printf("\n Total Estimated Time:%d",x);	
}
else
{
 printf("time quantum not in 2's multiple");
}
}
}
else
{
	printf("n=0 , not acceptable ");
}
}
