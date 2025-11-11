#include <stdio.h>

int main() {
    int n, bt[10], rem[10], wt[10]={0}, tat[10], tq, i, t=0, done;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;
                if(rem[i] > tq) {
                    t += tq;
                    rem[i] -= tq;
                } else {
                    t += rem[i];
                    wt[i] = t - bt[i];
                    rem[i] = 0;
                }
            }
        }
    } while(!done);

    for(i = 0; i < n; i++) tat[i] = bt[i] + wt[i];

    printf("\nP\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);

    return 0;
}
