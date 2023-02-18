#include "../headers/osFile.h"

const int PAGE_SIZE = 4096;

struct page {
	unsigned char * pageData;
};

//pageNum + 1, т.к. 0-ая страница служебная
static long getPageOffset(int pageNum) {
	return PAGE_SIZE * (pageNum + 1);
}

int allocPage() {

}

int freePage(int pageNum) {

}

int readPage(FILE* file, int pageNum, unsigned char* buffer) {
	//Нужна проверка на существование страницы с данным номером
	long pageOffset = getPageOffset(pageNum);
	return readFile(file, buffer, pageOffset, PAGE_SIZE);
}

int writePage(FILE* file, int pageNum, unsigned char* buffer) {
	//Нужна проверка на существование страницы с данным номером
	long pageOffset = getPageOffset(pageNum);
	return writeFile(file, buffer, pageOffset, PAGE_SIZE);
}