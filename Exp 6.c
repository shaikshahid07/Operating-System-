#include <stdio.h>

int main() {
    int n, bt[10], pr[10], rem[10], wt[10], tat[10], i, t = 0, done = 0, min;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Burst time & Priority of P%d: ", i+1);
        scanf("%d%d", &bt[i], &pr[i]);
        rem[i] = bt[i];
    }

    while(done != n) {
        min = -1;
        for(i = 0; i < n; i++)
            if(rem[i] > 0 && (min == -1 || pr[i] < pr[min])) min = i;

        rem[min]--;
        t++;
        if(rem[min] == 0) {
            done++;
            tat[min] = t;
            wt[min] = tat[min] - bt[min];
        }
    }

    printf("\nP\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);

    return 0;
}
