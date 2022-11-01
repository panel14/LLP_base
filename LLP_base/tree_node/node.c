
enum data_type {

	INT,
	DOUBLE,
	STRING,
	BOOL
};

struct key_node {

	char* node_name;
	key_node* parrent_node;
	key_node* subkey_nodes;
	node_attribute_info* attributes;
};

struct node_attribute_info {

	int index;
	int raw_size;
	int raw_offset;
	char* name;
	data_type type;
	struct attribute_data* data;
	struct node_attribute* next;
};

struct attribute_data {

	int size;
	byte* data;
};