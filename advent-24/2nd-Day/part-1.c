#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAFE 0

int GetLevels(char *report, int *nums) {
  char *report_cpy = strdup(report);
  char *save_ptr, *token;

  token = strtok_r(report_cpy, "\x20", &save_ptr);
  int i = 0;
  while (token != NULL) {
    // printf("TOKEN: %s\n", token);
    nums[i] = atoi(token);
    i++;
    token = strtok_r(NULL, "\x20", &save_ptr);
  }

  for (int j = 0; j < i; j++) {
    printf("Array[%d]: %d\n", j, nums[j]);
  }

  free(report_cpy);
  return i;
}

int CheckSteps(int *nums, int mode, int size) {
  for (int i = 0; i < size - 1; i++) {
    int diff = nums[i + 1] - nums[i];

    if (mode == 0) {
      if (diff < 1 || diff > 3) {
        return 1;
      }
    } else if (mode == 1) {
      // Check for decreasing
      if (diff > -1 || diff < -3) {
        return 1;
      }
    }
  }
  return 0;
}

int MakeReport(int *nums, int size) {
  if (nums[0] < nums[1]) {
    // All must increase
    return CheckSteps(nums, 0, size);
  } else if (nums[0] > nums[1]) {
    // All must decrease
    return CheckSteps(nums, 1, size);
  } else {
    // Invalid: equal values or mixed pattern
    return 1;
  }
}

int main() {
  FILE *fp = fopen("./input.txt", "r");
  char str_bfr[256];
  int numbers[10];
  char *track_ptr = str_bfr;
  int safe_reports = 0;

  int n = 0;
  while (fgets(str_bfr, 60, fp) != NULL) {
    printf("-%d---------\nString: %s\n", n, str_bfr);
    n++;

    int report_size = GetLevels(str_bfr, numbers);

    if (MakeReport(numbers, report_size) == SAFE) {
      safe_reports++;
    }

    memset(str_bfr, '\0', sizeof(char));
  }

  printf("Safe Reports %d\n", safe_reports);

  fclose(fp);
}
