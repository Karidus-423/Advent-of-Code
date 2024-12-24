#include <stdio.h>
#include <string.h>

int *QuickSort(int *list) {
  int *sorted_list;

  return sorted_list;
}

int main() {
  int list1[1000], list2[1000];
  char scanned[50];
  char *parse, *rest, *token;

  FILE *fp = fopen("./input.txt", "r");

  for (int i = 0; i < 1000; i++) {
    memset(scanned, 0, sizeof(scanned));
    fscanf(fp, "%d\t%d", &list1[i], &list2[i]);
  }

  fclose(fp);
  return 0;
}
