//Question no -1 Akash Katiyar(A26)
#include<stdio.h>

int main()

{
int allocation,cpu,pno[10],completion[10];
int i,j,a,p=0,count,no_of_process,time,remaining,flag=0,time_quantum1=3,time_quantum2=6;

int waiting_time=0,turnaround_time=0,arrival_time[10],burst_time[10],new_burst_time[10],new_burst_time2[10],bt[10],response_time[10];

printf("Enter Total Process:\t ");

scanf("%d",&no_of_process);

remaining=no_of_process;

for(count=0;count<no_of_process;count++)

{

printf("Enter Arrival Time and Burst Time for Process Number %d :",count+1);

scanf("%d",&arrival_time[count]);

scanf("%d",&burst_time[count]);
bt[count]=burst_time[count];

}
	printf("Burst times after first iteration\n");
for(count=0;count<no_of_process;count++)

{
	p=p+1;
	printf("P[%d] - %d\n",p,burst_time[count]-time_quantum1);
	burst_time[count]=burst_time[count]-time_quantum1;
}
    p=0;
	printf("\nBurst times after second iteration\n");
for(count=0;count<no_of_process;count++)

{
	p=p+1;
    printf("P[%d] - %d\n",p,burst_time[count]-time_quantum2);
    new_burst_time[count]=burst_time[count]-time_quantum2;
    new_burst_time2[count]=burst_time[count]-time_quantum2;
}
 for (i = 0; i < no_of_process; ++i) 
        {
            for (j = i + 1; j < no_of_process; ++j)
            {
                if (new_burst_time[i] > new_burst_time[j]) 
                {
                    a =  new_burst_time[i];
                    new_burst_time[i] = new_burst_time[j];
				    new_burst_time[j] = a;
                }
            }
            
        }
        
        
        for (i = 0; i < no_of_process; ++i) 
        {
            for (j = i + 1; j < no_of_process; ++j)
            {
                if (burst_time[i] > burst_time[j]) 
                {
                    a =  burst_time[i];
                    burst_time[i] = burst_time[j];
				    burst_time[j] = a;
                }
            }
        }
        
        
        
        
        for (i = 0; i < no_of_process; ++i) 
        {
            for (j = 0; j < no_of_process+1; ++j)
            {
                if (new_burst_time[i] == new_burst_time2[j]) 
                {
                   allocation=j;
                }
            }
            pno[i]=allocation;
        }
       cpu=(9*no_of_process)+pno[0]+1;
       p=0;
       completion[0]=cpu+new_burst_time[0];
       for(i=0;i<no_of_process;i++)
       {
       	completion[i+1]=completion[i]+new_burst_time[i+1];
	   }
printf("\nThird iteration\n");
printf("\n\nAllocation Sequence|Turnaround Time|Waiting Time\n");
printf("-------------------+---------------+------------\n");
for (i=0;i<no_of_process;i++)
{
printf("P[%d]\t\t   |\t%d\t   |\t%d\n",pno[i]+1,completion[i]-arrival_time[pno[i]],completion[i]-arrival_time[pno[i]]-bt[pno[i]]);
waiting_time+=completion[i]-arrival_time[pno[i]]-bt[pno[i]];
turnaround_time+=completion[i]-arrival_time[pno[i]];
}
printf("\nAverage Waiting Time= %f\n",waiting_time*1.0/no_of_process);

printf("Avg Turnaround Time = %f",turnaround_time*1.0/no_of_process);

return 0;
}
