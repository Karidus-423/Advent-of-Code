#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAFE 0

typedef struct Report {
  int inc;
  int dec;
  int errs;
} Report;

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

  free(report_cpy);
  return i;
}

void CheckReport(Report *report, int *diffs, int size) {
  printf("Inc: %d|", report->inc);
  printf("Dec: %d|\n", report->dec);

  if (report->inc > report->dec) {
    // Check for increasing
    report->errs += report->dec;
  } else {
    // Check for decreasing
    report->errs += report->inc;
  }

  printf("Diffs: \n");
  for (int i = 0; i < size; i++) {
    if (diffs[i] < 1 || 3 < diffs[i]) {
      report->errs += 1;
    }
    printf("%d ", diffs[i]);
  }
}

int MakeReport(int *nums, int size) {
  Report report = {0, 0, 0};
  int *diffs;
  int dec, inc;
  int errs = 0;

  diffs = malloc(sizeof(int) * (size - 1));
  if (diffs == NULL) {
    perror("Error Allocating Memory");
    exit(0);
  }
  memset(diffs, 0, sizeof(int) * (size - 1));

  for (int i = 0; i < size - 1; i++) {
    int next = nums[i + 1];
    int curr = nums[i];

    diffs[i] = abs(curr - next);
    if (curr > next) {
      report.dec++;
    } else if (curr < next) {
      report.inc++;
    }
  }

  CheckReport(&report, diffs, size - 1);
  errs = report.errs;

  printf("\nErrors: %d\n", errs);

  free(diffs);

  if (errs == 0 || errs == 1) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  FILE *fp = fopen("./input.txt", "r");
  char str_bfr[256];
  int numbers[15];
  char *track_ptr = str_bfr;
  int safe_reports = 0;

  int n = 0;
  while (fgets(str_bfr, 60, fp) != NULL) {
    n++;

    int report_size = GetLevels(str_bfr, numbers);

    if (MakeReport(numbers, report_size) == SAFE) {
      safe_reports++;
    }

    memset(str_bfr, '\0', sizeof(str_bfr));
  }

  printf("\n~~~~~~~~~~~~~Safe Reports %d~~~~~~~~~~~~~~~\n", safe_reports);

  fclose(fp);
}
