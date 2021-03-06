/*
  Copyright (c) 2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdint.h>
#include "platform.h"
#include "watchdog.h"
extern "C" {
#include <core/dev/watchdog.h>
}

void watchdogEnable (uint32_t timeout)
{
	(void)timeout;
	watchdog_start();
}

void watchdogDisable(void)
{
	watchdog_stop();
}

void watchdogReset(void)
{
	watchdog_periodic();
}


extern "C"
void _watchdogDefaultSetup (void)
{
	watchdog_stop();
}
void watchdogSetup (void) __attribute__ ((weak, alias("_watchdogDefaultSetup")));


