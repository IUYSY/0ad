/* Copyright (C) 2021 Wildfire Games.
 * This file is part of 0 A.D.
 *
 * 0 A.D. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * 0 A.D. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 0 A.D.  If not, see <http://www.gnu.org/licenses/>.
 */

#define MINIMAL_PCH 2
#include "lib/precompiled.h"	// common precompiled header

#if MSC_VERSION
# pragma warning(disable:4250)	// "inherits 'IGUITextOwner::IGUITextOwner::UpdateCachedSize' via dominance"
#endif

#if CONFIG_ENABLE_PCH
#include "gui/CGUI.h"
#include "gui/ObjectBases/IGUIObject.h"
#include "ps/CStr.h"

#endif // CONFIG_ENABLE_PCH
