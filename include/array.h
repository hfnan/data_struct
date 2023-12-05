#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include "type.h"

#define dump(Type, array) do {                            \
    int n = sizeof(array) / sizeof(Type);                 \
    printf("Array: ");                                    \
    for (int i = 0; i < n; i ++) printf("%d ", array[i]); \
    printf("\n");                                         \
} while (0)

#endif