#include "../tree_node/node.c"

struct tree_schema
{
	int tree_size;
	int nodes_count;

	struct key_node* root;
};
