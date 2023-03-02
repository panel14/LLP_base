#pragma once
#include <inttypes.h>

#define META_SIZE sizeof(struct treeMeta)
#define ATTR_HEAD_SIZE sizeof(struct attributeHeader)
#define ATTR_INFO_SIZE sizeof(struct nodeAttributeInfo)
#define SCHEMA_SIZE sizeof(struct treeSchema)

enum dataType {

	INT = 0,
	FLOAT,
	STRING,
	BOOL
};

struct treeMeta {
	uint64_t curId;
	uint64_t templateSize;
};

#pragma pack(push, 4)
struct attributeHeader {
	uint32_t size;
	enum dataType type;
};
struct nodeAttributeInfo {
	struct attributeHeader* header;
	char* attributeName;
};
#pragma pack(pop)

struct treeSchema
{
	struct nodeAttributeInfo** nodesTemplate;
	struct treeMeta* meta;
	uint64_t* root;
};
