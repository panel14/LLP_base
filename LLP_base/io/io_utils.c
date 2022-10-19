#include <stdio.h>

enum close_status {
    CLOSE_OK = 0,
    CLOSE_ERROR
};

enum open_status {
    OPEN_OK = 0,
    OPEN_ERROR
};

enum close_status close_file(FILE* file) {
    if (!fclose(file)) return CLOSE_OK;
    return CLOSE_ERROR;
}

enum open_status open_file(FILE* file) {
    if (!fopen(file)) return OPEN_OK;
    return OPEN_ERROR;
}