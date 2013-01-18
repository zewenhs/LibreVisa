/* 
 * Copyright (C) 2013 Simon Richter
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

#include "findlist.h"

namespace librevisa {

ViStatus findlist::Close()
{
        return VI_SUCCESS;
}

ViStatus findlist::FindNext(ViRsrc rsrc)
{
        if(resources.empty())
                return VI_ERROR_RSRC_NFOUND;

        resources.front().copy(rsrc, 256);
        resources.pop_front();
        return VI_SUCCESS;
}

}
