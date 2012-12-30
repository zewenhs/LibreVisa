/* 
 * Copyright (C) 2012 Simon Richter
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "dummy.h"

#include <visa.h>

#include <string.h>

int main()
{
        using_dummy_resource();

        ViSession rmgr;

        if(viOpenDefaultRM(&rmgr) != VI_SUCCESS)
                return 1;

        ViSession vi;

        if(viOpen(rmgr, "DUMMY", VI_NO_LOCK, 0, &vi) != VI_SUCCESS)
                return 1;

        ViByte testdata[] = { 't', 'e', 's', 't' };

        ViUInt32 written;

        if(viWrite(vi, testdata, sizeof testdata, &written) != VI_SUCCESS)
                return 1;

        if(written != sizeof testdata)
                return 1;

        dummy_reader_restart();

        if(dummy_reader_isempty())
                return 1;

        ViUInt32 count;
        ViByte const *data = dummy_reader_read(&count);

        if(count != sizeof testdata)
                return 1;

        if(memcmp(data, testdata, sizeof testdata))
                return 1;

        if(viClose(vi) != VI_SUCCESS)
                return 1;

        if(viClose(rmgr) != VI_SUCCESS)
                return 1;

        return 0;
}
