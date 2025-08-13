#include <stdio.h>
#include <stdint.h>

void priority_scheduling(int n, int *AT, int *BT, int *P) {
    int completed[50] = {0};
    int current_time = 0, completed_count = 0;
    float total_TAT = 0, total_WT = 0;

    while (completed_count < n) {
        int idx = -1, min_P = INT32_MAX;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && AT[i] <= current_time) {
                if (P[i] < min_P) {
                    min_P = P[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            int next_arrival = INT32_MAX;
            for (int i = 0; i < n; i++) {
                if (!completed[i] && AT[i] < next_arrival) {
                    next_arrival = AT[i];
                    idx = i;
                }
            }
            current_time = AT[idx];
        }

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

    printf("\nAverage TAT = %.2f", total_TAT / n);
    printf("\nAverage WT  = %.2f\n", total_WT / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], P[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT and priority of P%d: ", i+1);
        scanf("%d %d %d", &AT[i], &BT[i], &P[i]);
    }

    printf("\nP#\tAT\tBT\tST\tCT\tTAT\tWT\n");
    priority_scheduling(n, AT, BT, P);

    return 0;
}