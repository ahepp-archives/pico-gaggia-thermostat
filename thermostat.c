#include "thermostat.h"

int thermostat_init(
        thermostat_inst_t *thermostat,
        int sp,
        int hy) {
    thermostat->upper_bound = sp + hy;
    thermostat->lower_bound = sp - hy;
    thermostat->is_active = 0;
    return 0;
}

int thermostat_update(thermostat_inst_t *thermostat, int pv) {
    if (thermostat->is_active && (pv > thermostat->upper_bound)) {
        thermostat->is_active = 0;
    }
    else if (!thermostat->is_active && (pv < thermostat->lower_bound)) {
        thermostat->is_active = 1;
    }
    return thermostat->is_active;
}
