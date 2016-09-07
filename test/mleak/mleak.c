#include <assert.h>
#include <stdio.h>
#include <yajl/yajl_tree.h>
#include <yajl/mhook.h>

int main()
{
	const char teststr[] = "{\"name\" : \"John\"}";
	char errstr[1024] = {0};
	yajl_val tr;

	tr = yajl_tree_parse(teststr, errstr, sizeof(errstr));

	assert(tr != NULL);
	yajl_tree_free(tr);

	mhook_print_unfree();
	return 0;
}
