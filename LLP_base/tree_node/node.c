enum data_type {

	INT,
	DOUBLE,
	STRING,
	BOOL
};

struct key_node {

	char* node_name;
	struct key_node* parrent_node;
	struct key_node* subkey_nodes;
	struct node_attribute_info* attributes;
};

struct node_attribute_info {

	int index;
	int raw_size;
	int raw_offset;
	char* name;
	enum data_type type;
	struct attribute_data* data;
	struct node_attribute* next;
};

struct attribute_data {

	int size;
	unsigned char * data;
};