#include "sstring.h"

size_t split(char* str, const char chr, char*** arr) {
	int count = 1;
	int i = 0;
	char* ptr;

	ptr = str;

	while (*ptr != '\n' && *ptr != '\0') {
		if (*ptr == chr) count++;
		ptr++;
	}

	*arr = (char**)malloc(sizeof(char*) * count);
	if (*arr == NULL) exit(1);

	for (char* pch = strtok(str, &chr); pch != NULL; pch = strtok(NULL, &chr)) {
		if (i == count - 1 && pch[strlen(pch) - 1] == '\n')
			pch[strlen(pch) - 1] = '\0';
		(*arr)[i++] = pch;
	}

	return count;
}

int isNumeric(const char* str) {
	while (*str != '\0' && *str != 13) {
		if (*str < '0' || *str > '9') 
			return 1;
		str++;
	}
	return 0;
}

char* concat(const char* str1, const char* str2) {
	char* res = malloc(strlen(str1) + strlen(str2) + 1);
	strcpy(res, str1);
	strcpy(res, str2);
	return res;
}