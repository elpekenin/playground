// Copyright 2023 Pablo Martinez (@elpekenin) <elpekenin@elpekenin.dev>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef  STM32_SERIAL_USE_USART2
#define STM32_SERIAL_USE_USART2 TRUE
