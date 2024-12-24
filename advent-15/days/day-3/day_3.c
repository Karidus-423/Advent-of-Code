#include <stdio.h>
#include <stdlib.h>
void _checkCardinal(char dir, int *n, int *s, int *w, int *e) {

    switch (dir) {
    case '^':
        *n += 1;
        break;
    case 'v':
        *s += 1;
        break;
    case '<':
        *w += 1;
        break;
    case '>':
        *e += 1;
        break;
    }
}

int main() {
    FILE *file_ptr = fopen("./input.txt", "r");
    if (file_ptr == NULL) {
        printf("Unable to find file.");
        exit(0);
    }
    char c;
    int north = 0, south = 0, east = 0, west = 0;
    int house_once = 1;
    int house_many = 1;

    while ((c = fgetc(file_ptr)) != EOF) {
        _checkCardinal(c, &north, &south, &east, &west);
    }

    printf("Went North: %d, South: %d, East: %d, West: %d\n", north, south,
           east, west);

    fclose(file_ptr);
}
