/**
 * @author - Heera Singh
 * @date - 07-04-2024
 * @desc -
 * */

#ifndef DEVIKAOS_SYSTEM_H
#define DEVIKAOS_SYSTEM_H

#include "types.h"

uint8 inportb (uint16 _port);
void outportb (uint16 _port, uint8 _data);

#endif //DEVIKAOS_SYSTEM_H
