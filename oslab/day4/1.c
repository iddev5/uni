#include <stdio.h>
#include <stdint.h>

void srtf(int n, int *AT, int *BT, int TQ) {
    int completed[50] = {0};
    int current_time = 0, completed_count = 0;
    float total_TAT = 0, total_WT = 0;

    int RT[n], GC[50], gc = 0;
    for (int i = 0; i < n; i++)
        RT[i] = BT[i];

    while (completed_count < n) {
        int idx = -1, min_RT = INT32_MAX;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && AT[i] <= current_time) {
                if (RT[i] < min_RT) {
                    min_RT = RT[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            int min_AT = INT32_MAX;
            for (int i = 0; i < n; i++) {
                if (!completed && AT[i] < min_AT) {
                    min_AT = AT[i];
                    idx = i;
                }
            }
        }

        RT[idx] -= RT[idx] < TQ ? RT[idx] : TQ;
        GC[gc++] = idx;

        if (RT[idx] == 0) {
            int ST = (current_time > AT[idx]) ? current_time : AT[idx];
            int CT = ST + BT[idx];
            int TAT = CT - AT[idx];
            int WT = TAT - BT[idx];

            total_WT += WT;
            total_TAT += TAT;

            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", idx + 1, AT[idx], BT[idx], ST, CT, TAT, WT);
            current_time = CT;
            completed_count++;
            completed[idx] = 1;
        }

        current_time += TQ;
    }

    printf("\nGC: ");
    for (int i = 0; i < gc; i++) {
        printf("P%d", GC[i] + 1);
        if (i != gc - 1) printf(" -> ");
    }

    printf("\n\nAverage TAT = %.2f", total_TAT / n);
    printf("\nAverage WT  = %.2f\n", total_WT / n);
}

int main() {
    int n, TQ;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter TQ: ");
    scanf("%d", &TQ);

    int AT[n], BT[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT of P%d: ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    printf("\nP#\tAT\tBT\tST\tCT\tTAT\tWT\n");
    srtf(n, AT, BT, TQ);

    return 0;
}