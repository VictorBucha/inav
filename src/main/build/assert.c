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

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "platform.h"

#if defined(USE_ASSERT)
const char * assertFailureFile = NULL;
int assertFailureLine = 0;

void assertFailed2(const char * file, int line)
{
    if (!assertFailureLine) {
        assertFailureFile = file;
        assertFailureLine = line;
    }
#if defined(USE_ASSERT_STOP)
    while(1) {
        __asm("BKPT #0\n") ; // Break into the debugger
    }
#endif
}
#endif
