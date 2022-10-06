#ifndef _REGISTER_MAP_H
#define _REGISTER_MAP_H

#include "hardware/i2c.h"

typedef struct register_map_inst register_map_inst_t;

struct register_map_inst {
    uint8_t i2c_addr;
    i2c_inst_t *i2c_bus;
};

int register_map_init(register_map_inst_t *register_map, i2c_inst_t *i2c_bus, uint8_t i2c_addr);
int register_map_read_blocking(register_map_inst_t *register_map, uint8_t addr, uint8_t *bytes, uint8_t len);
int register_map_write_blocking(register_map_inst_t *register_map, uint8_t addr, uint8_t *bytes, uint8_t len);

#endif // _REGISTER_MAP_H
