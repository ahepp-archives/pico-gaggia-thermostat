#include "register_map.h"


int register_map_init(
        register_map_inst_t *register_map,
        i2c_inst_t *i2c_bus,
        uint8_t i2c_addr) {
    register_map->i2c_addr = i2c_addr;
    register_map->i2c_bus = i2c_bus;
    return 0;
}
int register_map_read_blocking(
        register_map_inst_t *register_map,
        uint8_t addr,
        uint8_t *bytes,
        uint8_t len) {
    i2c_write_blocking(register_map->i2c_bus,
            register_map->i2c_addr,
            &addr,
            1,
            true);
    i2c_read_blocking(register_map->i2c_bus,
            register_map->i2c_addr,
            bytes,
            len,
            false);
    return 0;
}

int register_map_write_blocking(
        register_map_inst_t *register_map,
        uint8_t addr,
        uint8_t *bytes,
        uint8_t len) {
    i2c_write_blocking(register_map->i2c_bus,
            register_map->i2c_addr,
            &addr,
            1,
            true);
    i2c_write_blocking(register_map->i2c_bus,
            register_map->i2c_addr,
            bytes,
            len,
            false);
    return 0;
}
