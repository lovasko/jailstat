#include <sys/types.h>

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <inttypes.h>
#include <stdio.h>
#include <tak.h>

#include "types.h"

int
main(void)
{
	struct tak t_conn;
	int retval;
	struct js_prison_list* prison_list;
	struct js_prison* prison;

	retval = tak_open(&t_conn, TAK_TYPE_INFO_CTF, TAK_DATA_SOURCE_KVM);
	if (retval != TAK_OK) {
		fprintf(stderr, "ERROR: %s\n", tak_error_string(retval));
		return EXIT_FAILURE;
	}

	prison_list = malloc(sizeof(struct js_prison_list));
	retval = tak_map_sym(&t_conn,
	                     "struct js_prison_list",
	                     "allprison",
	                     (void**)&prison_list);
	if (retval != TAK_OK) {
		fprintf(stderr, "ERROR: %s\n", tak_error_string(retval));
		return EXIT_FAILURE;
	}

	for (prison = prison_list->tqh_first;
	     prison != NULL;
	     prison = prison->p_list.tqe_next)
	{
		printf("ID: %lld\n", prison->pr_id);
	}

	return EXIT_SUCCESS;
}

