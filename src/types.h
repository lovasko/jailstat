#include <stdint.h>

struct js_prison;

struct js_prison_entry {
	struct js_prison* tqe_next;
};

struct js_prison {
	intmax_t pr_id;
	struct js_prison_entry p_list;
};

struct js_prison_list {
	struct js_prison* tqh_first;
};

