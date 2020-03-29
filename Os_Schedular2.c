//Question no -1 Akash Katiyar(A26)
#include<stdio.h>

int main()

{

int p=0,count,no_of_process,time,remaining,flag=0,time_quantum1=3,time_quantum2=6;

int waiting_time=0,turnaround_time=0,arrival_time[6],burst_time[6],response_time[6];

printf("Enter Total Process:\t ");

scanf("%d",&no_of_process);

remaining=no_of_process;

for(count=0;count<no_of_process;count++)

{

printf("Enter Arrival Time and Burst Time for Process Number %d :",count+1);

scanf("%d",&arrival_time[count]);

scanf("%d",&burst_time[count]);

}
	printf("Burst times after first iteration\n");
for(count=0;count<no_of_process;count++)

{
	p=p+1;
	printf("P[%d] - %d\n",p,burst_time[count]-time_quantum1);
	burst_time[count]=burst_time[count]-time_quantum1;
	response_time[count]=burst_time[count];
	
}
    p=0;
	printf("\nBurst times after second iteration\n");
for(count=0;count<no_of_process;count++)

{
	p=p+1;
    printf("P[%d] - %d\n",p,burst_time[count]-time_quantum2);
    burst_time[count]=burst_time[count]-time_quantum2;
	response_time[count]=burst_time[count];
}

printf("\n\nAllocation Sequence|Turnaround Time|Waiting Time\n");
printf("-------------------+---------------+------------\n");
p=0;
for(time=0,count=0;remaining!=0;)


{

if(response_time[count]<=36 && response_time[count]>0)

{

time+=response_time[count];

response_time[count]=0;

flag=1;

}

else if(response_time[count]>0)

{

response_time[count]-=36;

time+=36;

}

if(response_time[count]==0 && flag==1)

{
p=p+1;
remaining--;
printf("P[%d]\t\t   |\t%d\t   |\t%d\n",p,time-arrival_time[count],time-arrival_time[count]-burst_time[count]);
waiting_time+=time-arrival_time[count]-burst_time[count];

turnaround_time+=time-arrival_time[count];

flag=0;

}

if(count==no_of_process-1)

count=0;

else if(arrival_time[count+1]<=time)

count++;

else

count=0;

}

printf("\nAverage Waiting Time= %f\n",waiting_time*1.0/no_of_process);

printf("Avg Turnaround Time = %f",turnaround_time*1.0/no_of_process);

return 0;

}
