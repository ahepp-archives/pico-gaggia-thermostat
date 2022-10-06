#include "mcp9600.h"

int mcp9600_init(mcp9600_inst_t *mcp9600, register_map_inst_t *register_map) {
    mcp9600->register_map = register_map;

    uint8_t cfg = 0x00; // type K no filtering
    register_map_write_blocking(
           mcp9600->register_map,
           MCP9600_REG_CFG,
           &cfg,
           1);

    return 0;
}

int16_t mcp9600_read_blocking(mcp9600_inst_t *mcp9600) {
    uint8_t buf[2];
    register_map_read_blocking(
           mcp9600->register_map,
           MCP9600_REG_HOT_JUNC_TEMP,
           buf,
           2);

    // discards sign and fractional component
    return ((0x7F & buf[0]) << 4) | (buf[1] >> 4);
}
