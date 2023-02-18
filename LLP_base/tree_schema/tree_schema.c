#include "../tree_node/node.c"

struct tree_schema
{
	int raw_tree_size;
	int attributes_count;
	int nodes_count;
	struct node_attribute_info* attr_head;
	struct key_node* root;
};
