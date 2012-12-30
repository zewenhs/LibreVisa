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

#ifndef freevisa_resource_h_
#define freevisa_resource_h_ 1

#include "object.h"

namespace freevisa {

class session;

class resource :
        public object
{
public:
        resource();

public:
        unsigned int add_ref() { return ++refcount; }
        unsigned int release() { return --refcount; }

        virtual ViStatus GetAttribute(ViAttr, void *);

        virtual ViStatus Open(ViRsrc, ViAccessMode, ViUInt32, ViSession *)
        {
                return VI_ERROR_NSUP_OPER;
        }

        virtual ViStatus FindRsrc(ViString, ViFindList *, ViUInt32 *, ViRsrc)
        {
                return VI_ERROR_NSUP_OPER;
        }

        virtual ViStatus Read(ViBuf, ViUInt32, ViUInt32 *)
        {
                return VI_ERROR_NSUP_OPER;
        }

        virtual ViStatus Write(ViBuf, ViUInt32, ViUInt32 *)
        {
                return VI_ERROR_NSUP_OPER;
        }

        virtual ViStatus ReadSTB(ViUInt16 *)
        {
                return VI_ERROR_NSUP_OPER;
        }

        virtual ViStatus ParseRsrc(
                ViRsrc,
                ViUInt16 *,
                ViUInt16 *,
                ViString * = 0,
                ViString * = 0,
                ViString * = 0)
        {
                return VI_ERROR_NSUP_OPER;
        }

        bool lock_exclusive(session const *);
        void unlock_exclusive();

private:
        unsigned int refcount;
        session const *exclusive_lock_holder;
};

}

#endif
