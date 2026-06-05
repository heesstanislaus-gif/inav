/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdbool.h>
#include <platform.h>

#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

timerHardware_t timerHardware[] = {
    // Logical S1 = Motor 1
    // Physical M1 pad = PA8 / TIM1_CH1
    DEF_TIM(TIM1, CH1, PA8,  TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR, 0, 1),

    // Logical S2 = Motor 2
    // Physical M3 pad = PA10 / TIM1_CH3
    // Your second motor is soldered to physical M3.
    DEF_TIM(TIM1, CH3, PA10, TIM_USE_MC_MOTOR | TIM_USE_FW_MOTOR, 0, 6),

    // Logical S3 = Servo 1
    // Physical LED pad = PA15 / TIM2_CH1
    // Use this for the aileron servo if it is soldered to LED.
    DEF_TIM(TIM2, CH1, PA15, TIM_USE_MC_SERVO | TIM_USE_FW_SERVO, 0, 5),

    // Logical S4 = Servo 2
    // Physical RSSI pad = PB1 / TIM3_CH4
    // Use this for the elevator servo after moving it from SDA to RSSI.
    DEF_TIM(TIM3, CH4, PB1,  TIM_USE_MC_SERVO | TIM_USE_FW_SERVO, 0, 2),
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
