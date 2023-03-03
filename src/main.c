#include "StorageFilePublicAPI/storageFilePublic.h"
#include "UserAPI/InteractiveMode/interactiveMode.h"
#include "Utils/parser.h"

int main(int argc, char** argv) {
	printf("Launch program\n");
	char* filename;
	char* v;

	FILE* fp;
	FILE* parsed;

	char flag;

	if (argc < 3 || argc > 4) {
		printf("Wrong number of aguments: %d", argc);
		return 1;
	}
	else if (argc == 4) {
		v = argv[3];
	}
	filename = argv[2];
	flag = argv[1][1];

	switch (flag)
	{
	case 'o':
		storageOpenOrCreateFile(filename, "r+b", &fp);
		break;

	case 'n':
		storageOpenOrCreateFile(filename, "w", &fp);
		storageCloseFile(fp);
		storageOpenOrCreateFile(filename, "r+b", &fp);
		initFile(fp);
		break;

	case 'p':
		storageOpenOrCreateFile(v, "r", &parsed);

		storageOpenOrCreateFile(filename, "w", &fp);
		storageCloseFile(fp);
		storageOpenOrCreateFile(filename, "r+b", &fp);

		initFile(fp);
		parseFile(fp, parsed);
		break;

	default:
		printf("unknown");
		break;
	}
	start(fp);

	return 0;
}