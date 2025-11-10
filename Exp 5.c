#include <stdio.h>

int main() {
    int n, i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int bt[n], pr[n], wt[n], tat[n], p[n];
    printf("Enter burst times: ");
    for(i=0;i<n;i++) scanf("%d",&bt[i]);
    printf("Enter priorities (lower = higher priority): ");
    for(i=0;i<n;i++){ scanf("%d",&pr[i]); p[i]=i+1; }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(pr[i]>pr[j]){
                temp=pr[i]; pr[i]=pr[j]; pr[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=p[i]; p[i]=p[j]; p[j]=temp;
            }
    wt[0]=0;
    for(i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];
    for(i=0;i<n;i++) tat[i]=wt[i]+bt[i];
    printf("\nPID\tPR\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++) printf("%d\t%d\t%d\t%d\t%d\n",p[i],pr[i],bt[i],wt[i],tat[i]);
    return 0;
}
