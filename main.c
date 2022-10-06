#include <stdio.h>

#include "hardware/i2c.h"
#include "pico/stdlib.h"

#include "mcp9600.h"
#include "register_map.h"
#include "thermostat.h"

#define DELAY_MS 1000

int main() {
    const uint SSR_PIN = 0;
    const uint SDA_PIN = 16;
    const uint SCL_PIN = 17;

    const uint8_t THERMO_I2C_ADDR = 0x60;

    stdio_init_all();

    // Initialize i2c bus
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    // Construct thermocouple amplifier
    register_map_inst_t thermo_reg_inst;
    register_map_init(&thermo_reg_inst, i2c_default, THERMO_I2C_ADDR);
    mcp9600_inst_t thermo_inst;
    mcp9600_inst_t *thermo = &thermo_inst;
    mcp9600_init(thermo, &thermo_reg_inst);

    // Replace the default Gaggia L107-8C with a software thermostat
    // controlling power to the boiler with a solid state relay
    gpio_init(SSR_PIN);
    gpio_set_dir(SSR_PIN, GPIO_OUT);
    gpio_put(SSR_PIN, 0);
    thermostat_inst_t boiler_thermostat_inst;
    thermostat_inst_t *boiler = &boiler_thermostat_inst;
    thermostat_init(boiler, 107, 8);

    while (true) {
        int16_t temp = mcp9600_read_blocking(thermo);
        gpio_put(SSR_PIN, thermostat_update(boiler, temp));
        printf("%dc\n", temp);

        sleep_ms(DELAY_MS);
    }
}
