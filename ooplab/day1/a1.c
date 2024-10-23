#include <stdio.h>

int main() {
  int n, i;
  printf("Enter no. of students: ");
  scanf("%d", &n);

  struct Student {
    unsigned long roll_no;
    char name[32];
    int year;
  } students[n];

  for (i = 0; i < n; i++) {
    printf("Enter roll no of student %d: ", i);
    scanf("%lu", &students[i].roll_no);

    printf("Enter name of student %d: ", i);
    scanf("%s", students[i].name);

    printf("Enter year of student %d: ", i);
    scanf("%d", &students[i].year);
  }

  printf("Details of all students\n");

  for (i = 0; i < n; i++) {
    printf("Student %d:\n", i);
    printf("Roll No: %lu\n", students[i].roll_no);
    printf("Name: %s\n", students[i].name);
    printf("Year: %d\n\n", students[i].year);
  }

  return 0;
}
