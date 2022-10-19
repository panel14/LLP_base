
struct cell_header {

	int size;
};

struct key_node {

	struct cell_header header;
	char* node_name;
	int parrent_offset;
	int subkeys_offset;
	int key_values_offset;
};

enum data_type {
	INT,
	DOUBLE,
	STRING,
	BOOL
};

struct key_value {

	struct cell_header header;
	char* value_name;
	int data_size;
	enum data_type type;
	double data_offset;
};