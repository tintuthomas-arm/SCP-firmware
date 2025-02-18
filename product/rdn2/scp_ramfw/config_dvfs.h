/*
 * Arm SCP/MCP Software
 * Copyright (c) 2021-2022, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CONFIG_DVFS_H
#define CONFIG_DVFS_H

enum dvfs_element_idx {
    DVFS_ELEMENT_IDX_CPU0,
    DVFS_ELEMENT_IDX_CPU1,
    DVFS_ELEMENT_IDX_CPU2,
    DVFS_ELEMENT_IDX_CPU3,
#if (PLATFORM_VARIANT == 0 || PLATFORM_VARIANT == 1)
    DVFS_ELEMENT_IDX_CPU4,
    DVFS_ELEMENT_IDX_CPU5,
    DVFS_ELEMENT_IDX_CPU6,
    DVFS_ELEMENT_IDX_CPU7,
#endif
#if (PLATFORM_VARIANT == 0)
    DVFS_ELEMENT_IDX_CPU8,
    DVFS_ELEMENT_IDX_CPU9,
    DVFS_ELEMENT_IDX_CPU10,
    DVFS_ELEMENT_IDX_CPU11,
    DVFS_ELEMENT_IDX_CPU12,
    DVFS_ELEMENT_IDX_CPU13,
    DVFS_ELEMENT_IDX_CPU14,
    DVFS_ELEMENT_IDX_CPU15,
#endif
    DVFS_ELEMENT_IDX_COUNT
};

#endif /* CONFIG_DVFS_H */
