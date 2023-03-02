#pragma once

#include <stdlib.h>
#include "../DataFileAPI/dataFile.h"

void createEmptyTreeSchema(char** template, enum dataType* types, size_t templateSize, size_t* attrSizes, struct treeSchema* schema);