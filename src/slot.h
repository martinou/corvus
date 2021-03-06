#ifndef __SLOT_H
#define __SLOT_H

#include <stdint.h>
#include "parser.h"
#include "socket.h"

#define REDIS_CLUSTER_SLOTS 16384

struct context;

enum {
    SLOT_UPDATE_UNKNOWN,
    SLOT_UPDATE_INIT,
    SLOT_UPDATE,
    SLOT_UPDATER_QUIT,
};

struct node_info {
    struct address *nodes;
    size_t index;
    size_t len;
    bool slave_added;
};

uint16_t slot_get(struct pos_array *pos);
void slot_get_addr_list(char *dest);
bool slot_get_node_addr(struct context *ctx, uint16_t slot, struct address *addr,
        struct address *slave);
void slot_create_job(int type);
int slot_start_manager(struct context *ctx);

#endif /* end of include guard: __SLOT_H */
