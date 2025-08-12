#include <stdio.h>
#include <stdint.h>

void sjf(int n, int *AT, int *BT) {
    int completed[50] = {0};
    int current_time = 0;
    int completed_count = 0;
    float total_WT = 0, total_TAT = 0;

    while (completed_count < n) {
        int idx = -1;
        int min_BT = INT32_MAX;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && AT[i] <= current_time) {
                if (BT[i] < min_BT) {
                    min_BT = BT[i];
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
        completed[idx] = 1;
        completed_count++;
    }

    printf("\nAverage TAT = %.2f", total_TAT / n);
    printf("\nAverage WT  = %.2f\n", total_WT / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "P#", "AT", "BT", "ST", "CT", "TAT", "WT");
    sjf(n, AT, BT);

    return 0;
}
