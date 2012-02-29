/****************************************************************************\

	NES Emulator
	Copyright (C) 2012  Ivanov Viktor

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

\****************************************************************************/

#ifndef __CPU_H_
#define __CPU_H_

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "device.h"
#include "clock.h"

namespace vpnes {

/* CPU */
template <class _Bus>
class CCPU: public CClockedDevice<_Bus> {
	using CClockedDevice<_Bus>::Clocks;
	using CDevice<_Bus>::Bus;
public:
	inline explicit CCPU(_Bus *pBus) { Bus = pBus; }
	inline ~CCPU() {}

	/* Выполнить действие */
	inline void Clock(int DoClocks) {
		if ((Clocks -= DoClocks) == 0)
			Clocks = PerformOperation();
	}

	/* Чтение памяти */
	uint8 ReadAddress(uint16 Address) { return 0x00; }
	/* Запись памяти */
	void WriteAddress(uint16 Address, uint8 Src) {}

	/* Отработать команду */
	int PerformOperation();
};

/* Отработать такт */
template <class _Bus>
inline int CCPU<_Bus>::PerformOperation() {
	return 3;
}

}

#endif
