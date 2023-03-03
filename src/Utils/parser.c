#include "parser.h"

void parseFile(FILE* to, FILE* from) {
	char line[INPUT_SIZE];
	char** args = NULL;
	size_t templateSize;

	struct treeSchema* schema = malloc(SCHEMA_SIZE);
	readTreeSchema(schema, to);

	templateSize = schema->meta->templateSize;
	enum dataType* types = malloc(sizeof(enum dataType) * templateSize);
	char** attrNames = malloc(sizeof(char *) * templateSize);

	for (int i = 0; i < templateSize; i++) {
		types[i] = schema->nodesTemplate[i]->header->type;
		attrNames[i] = schema->nodesTemplate[i]->attributeName;
	}

	fgets(line, INPUT_SIZE, from);

	while (!feof(from)) {
		if (strlen(line) == 0) break;
		line[strlen(line) - 1] = '\0';
		char* prefix = concat("add ", line);
		split(prefix, ' ', &args);

		size_t code = storageInsertNode(to, args, templateSize, types, attrNames);

		if (code != 0) {
			printf("Error code %zu\nIn line: %s\n", code, line);
		}
		free(prefix);
		free(args);
		fgets(line, INPUT_SIZE, from);
	}

	freeTreeSchema(schema);
	fclose(from);
	fflush(to);
	free(types);
	free(attrNames);
}