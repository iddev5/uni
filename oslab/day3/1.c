#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

struct process {
  int idx, AT, BT;
};

// void print_processes(int n, struct process *processes) {
//   for (int i = 0; i < n; i++) 
//     printf("P%d (%d, %d), ", processes[i].idx, processes[i].AT, processes[i].BT);
//   printf("\n");
// }

int get_next_process(int n, struct process *processes, int time) {
  int min_p = -1, min_p_value = INT32_MAX;
  for (int i = 0; i < n; i++) {
    if (time >= processes[i].AT && processes[i].AT < min_p_value) {
      min_p = i;
      min_p_value = processes[i].AT;
    }
  }
  return min_p;
}

void remove_process(int n, int idx, struct process *processes) {
  for (int i = idx; i < n; i++) {
    processes[i].idx = processes[i+1].idx;
    processes[i].AT = processes[i+1].AT;
    processes[i].BT = processes[i+1].BT;
  }
  processes[n-1].idx = -1;
  processes[n-1].AT = -1;
  processes[n-1].BT = -1;
}

void schedule_fcfs(int n, struct process *processes) {
  int time = 0;
  float sum_WT = 0.0, sum_TAT = 0.0;

  for (int i = 0; i <= 5; i++) {
    int proc_idx = get_next_process(n, processes, time);
    // printf("proc got: %d -> %d\n", proc_idx, processes[proc_idx].idx);
    if (proc_idx == -1) {
      time++;
      continue;
    }
    struct process proc = processes[proc_idx];

    if (time < proc.AT)
      time = proc.AT;

    sum_WT += (time - proc.AT);
    sum_TAT += (time + proc.BT);

    printf("P%d\t%d\t%d\t%d\n", proc.idx, time, time - proc.AT, time + proc.BT);
    time += proc.BT;

    remove_process(n, proc_idx, processes);
    // print_processes(n, processes);
    n--;
  }

  printf("\nAvg. waiting time: %.2f\n", sum_WT / 5);
  printf("Avg. total time: %.2f\n", sum_TAT / 5);
}

int main() {
  // int AT[] = {1, 4, 2, 1, 4};
  // int BT[] = {4, 3, 1, 2, 5};

  struct process processes[] = {
    { 1, 1, 4 },
    { 2, 4, 3 },
    { 3, 2, 1 },
    { 4, 1, 2 },
    { 5, 4, 5 },
  };

  printf("P#\tST\tWT\tTAT\n");
  for (int i = 0; i < 32; i++)
    putchar('-');
  putchar('\n');
  schedule_fcfs(5, processes);

  return 0;
}
