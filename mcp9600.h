#ifndef _MCP9600_H
#define _MCP9600_H

#define MCP9600_REG_HOT_JUNC_TEMP 0x00
#define MCP9600_REG_CFG 0x05

#include "hardware/i2c.h"

#include "register_map.h"

typedef struct mcp9600_inst mcp9600_inst_t;

struct mcp9600_inst {
    register_map_inst_t *register_map;
};

int mcp9600_init(mcp9600_inst_t *, register_map_inst_t *);
int16_t mcp9600_read_blocking(mcp9600_inst_t *mcp9600);

#endif // _MCP9600_H
