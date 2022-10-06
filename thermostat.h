#ifndef _THERMOSTAT_H
#define _THERMOSTAT_H

typedef struct thermostat_inst thermostat_inst_t;
struct thermostat_inst {
    int upper_bound;
    int lower_bound;
    int is_active;
};

/*
 * Initialize a thermostat controller
 * @param thermostat  The thermostat controller to initialize
 * @param sp  The setpoint of the thermostat
 * @param hy  The hysteresis of the thermostat
 * @return 0 if no error
 */
int thermostat_init(
        thermostat_inst_t *thermostat,
        int sp,
        int hy);

/*
 * Update a thermostat controller
 * @param thermostat  The thermostat controller to update
 * @param pv  The process variable (temperature)
 * @return 0 if no error
 */
int thermostat_update(thermostat_inst_t *thermostat, int pv);

#endif // _THERMOSTAT_H
