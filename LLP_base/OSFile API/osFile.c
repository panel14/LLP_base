#include "osFile.h"

enum openStatus openOrCreateFile(char* filename, FILE** fp) {
	*fp = fopen(filename, "a+");
	return (NULL == fp) ? OPEN_FAIL : OPEN_SUCCESS;
}

enum closeStatus closeFile(FILE *fp) {
	return (fclose(fp) == 0) ? CLOSE_SUCCESS : CLOSE_FAIL  
}
//need in size_t offset and size_t return
enum readStatus readFile(FILE* fp, void* buffer, size_t size) {
	size_t len = fread(buffer, size, 1, fp);

	if (len != 1) return READ_LEN_ERROR;
	if (feof(fp)) return READ_UNEXPECTED_EOF;

	return READ_OK;
}
//need in size_t offset and size_t return
enum writeStatus writeFile(FILE* fp, void* buffer, size_t size) {
	size_t len = fwrite(buffer, size, 1, fp);

	if (len != 1) return WRITE_LEN_ERROR;
	if (feof(fp)) return WRITE_UNEXPECTED_EOF;

	return WRITE_OK;
}

int deleteFile(char* filename) {
	return remove(filename);
}