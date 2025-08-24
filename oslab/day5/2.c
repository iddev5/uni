#include <stdio.h>
#include <stdint.h>

void sort(int n, int *idx, int *AT, int *BT) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (AT[j] > AT[j+1]) {
                int temp = AT[j];
                AT[j] = AT[j+1];
                AT[j + 1] = temp;

                temp = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp;

                temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = idx[j];
            }
}

void round_robin(int n, int *AT, int *BT, int TQ) {
    int completed_count = 0, current_time = 0, gc = 0;
    int RT[n], ST[n], idx[n], completed[n], GC[50], GC_time[50];
    float total_TAT = 0, total_WT = 0;

    for (int i = 0; i < n; i++) {
        idx[i] = i+1;
        RT[i] = BT[i];
        ST[i] = -1;
        completed[i] = 0;
    }

    sort(n, idx, AT, BT);
    while (completed_count < n) {
        for (int i = 0; i < n; i++) {
            if (!completed[i]) {
                int amt = RT[i] > TQ ? TQ : RT[i];
                RT[i] -= amt;
                ST[i] = ST[i] == -1 ? current_time : ST[i];
                current_time += amt;

                GC[gc] = idx[i];
                GC_time[gc++] = current_time;

                if (RT[i] == 0) {
                    int TAT = current_time - AT[i], WT = TAT - BT[i];

                    total_TAT += TAT;
                    total_WT += WT;

                    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", idx[i], AT[i], BT[i], ST[i], current_time, TAT, WT);

                    completed[i] = 1;
                    completed_count++;
                }
            }
        }
    }

    printf("\nAverage TAT = %.2f\n", total_TAT / n);
    printf("Average WT = %.2f\n", total_WT / n);

    printf("\nGantt Chart\nP#\tTime\n");
    for (int i = 0; i < gc; i++)
        printf("P%d\t%d\n", GC[i], GC_time[i]);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int TQ;
    printf("Enter time quantum (TQ): ");
    scanf("%d", &TQ);

    int AT[n], BT[n];
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    printf("\nP#\tAT\tBT\tST\tCT\tTAT\tWT\n");
    round_robin(n, AT, BT, TQ);
    return 0;
}