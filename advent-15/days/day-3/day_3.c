#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Santa;

typedef enum {
    LEFT,
    UP,
    DOWN,
    RIGHT,
} Direction;

int Travel(int maze[1000][1000], Direction *list, int list_size) {
    Santa real_santa = {500, 500};
    Santa robo_santa = {500, 500};
    Santa santas[2] = {real_santa, robo_santa};
    Santa *santa;

    int newly_visited = 0;

    for (int n = 0; n < list_size; n++) {
        if ((n % 2) == 0) {
            santa = &santas[0];
        } else {
            santa = &santas[1];
        }

        if (maze[santa->y][santa->x] == 0) {
            newly_visited++;
            maze[santa->y][santa->x] += 1;
        }

        switch (list[n]) {
        case LEFT:
            santa->x -= 1;
            break;
        case UP:
            santa->y += 1;
            break;
        case DOWN:
            santa->y -= 1;
            break;
        case RIGHT:
            santa->x += 1;
            break;
        }
    }

    return newly_visited;
};

// Read from input.txt and return an array of directions.
Direction *GetDirections(FILE *stream, int size) {

    Direction *list = malloc(size * sizeof(Direction));

    char ch;

    int i = 0;
    while ((ch = fgetc(stream)) != EOF) {
        switch (ch) {
        case '>':
            list[i] = RIGHT;
            break;
        case '^':
            list[i] = UP;
            break;
        case '<':
            list[i] = LEFT;
            break;
        case 'v':
            list[i] = DOWN;
            break;
        }
        i++;
    }

    return list;
}

int main() {
    FILE *stream = fopen("./input.txt", "r");
    if (stream == NULL) {
        printf("Unable to find file.");
    }
    fseek(stream, 0, SEEK_END);
    int size = ftell(stream);
    rewind(stream);

    Direction *directions = GetDirections(stream, size);

    fclose(stream);

    int maze[1000][1000] = {0};

    int total = Travel(maze, directions, size);

    free(directions);
    printf("Total Houses:%d\n", total);
}
