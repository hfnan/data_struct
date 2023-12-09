#ifndef DS_TYPE_H
#define DS_TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int ElemType;

#define new(Type) (Type*)malloc(sizeof(Type))
#define newarray(n) (ElemType*)malloc(n * sizeof(ElemType))
#endif