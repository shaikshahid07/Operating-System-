#include <stdio.h>

int main() {
    int n, bt[10], pr[10], rt[10], done=0, t=0, i, min;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("BT & Priority of P%d: ",i+1);
        scanf("%d%d",&bt[i],&pr[i]);
        rt[i]=bt[i];
    }
    while(done<n){
        min=-1;
        for(i=0;i<n;i++)
            if(rt[i]>0 && (min==-1||pr[i]<pr[min])) min=i;
        rt[min]--; t++;
        if(rt[min]==0){
            done++;
            printf("P%d finished at time %d\n",min+1,t);
        }
    }
    return 0;
}
