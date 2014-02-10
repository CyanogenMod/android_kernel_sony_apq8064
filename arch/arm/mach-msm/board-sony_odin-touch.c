/* arch/arm/mach-msm/board-sony_odin-touch.c
 *
 * Copyright (C) 2012 Sony Mobile Communications AB.
 *
 * Author: Yusuke Yoshimura <Yusuke.Yoshimura@sonymobile.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2, as
 * published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#include <linux/input.h>
#include <linux/clearpad.h>
#include <linux/input/evgen_helper.h>

struct synaptics_funcarea clearpad_funcarea_array[] = {
	{
		{ 0, 0, 1079, 1919 }, { 0, 0, 1079, 1919 },
		SYN_FUNCAREA_POINTER, NULL
	},
	{ .func = SYN_FUNCAREA_END }
};

struct synaptics_funcarea *clearpad_funcarea_get(u8 module_id, u8 rev)
{
	return clearpad_funcarea_array;
}

int clearpad_flip_config_get(u8 module_id, u8 rev)
{
	return SYN_FLIP_NONE;
}

static struct evgen_record double_tap[] = {
	{
		.type = EVGEN_LOG,
		.data.log.message = "=== DOUBLE TAP ===",
	},
	{
		.type = EVGEN_KEY,
		.data.key.code = KEY_POWER,
		.data.key.down = true,
	},
	{
		.type = EVGEN_KEY,
		.data.key.code = KEY_POWER,
		.data.key.down = false,
	},
	{
		.type = EVGEN_END,
	},
};

static struct evgen_block evgen_blocks[] = {
	{
		.name = "double_tap",
		.records = double_tap,
	},
	{
		.name = NULL,
		.records = NULL,
	}
};


struct evgen_block *clearpad_evgen_block_get(u8 module_id, u8 rev)
{
	return evgen_blocks;
}

struct synaptics_easy_wakeup_config clearpad_easy_wakeup_config = {
	.gesture_enable = false,
	.large_panel = false,
	.timeout_delay = 2000,
};
