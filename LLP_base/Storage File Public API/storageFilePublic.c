#include <stdio.h>
#include "../query API/query.c"
#include "../tree_node/node.c"

FILE* storageOpenOrCreate(char * filename) {
	return 0;
}

int storageRetrive(char * filename) {
	return 0;
}

int storageInsert(FILE* sd, struct key_node node) {
	return 0;
}

int storageUpdate(FILE* sd, struct condition cond, struct key_node node) {
	return 0;
}

int storageDelete(FILE* sd, struct condition cond) {
	return 0;
}

int storageClose(FILE* sd) {
	return 0;
}

struct resultSet storageSelect(FILE* sd, struct query query) {

}

struct key_node getCurrentItem(struct resultSet iter) {

}

bool tryNextItem(struct resultSet iter) {
	return false;
}

