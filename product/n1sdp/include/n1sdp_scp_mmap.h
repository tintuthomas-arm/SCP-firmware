/*
 * Arm SCP/MCP Software
 * Copyright (c) 2018-2022, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef N1SDP_SCP_MMAP_H
#define N1SDP_SCP_MMAP_H

#include <stdint.h>

/*
 * Top-level base addresses
 */
#define SCP_EXPANSION1_BASE          UINT32_C(0x01000000)
#define SCP_EXPANSION2_BASE          UINT32_C(0x21000000)
#define SCP_SCC_BASE                 UINT32_C(0x3FFFF000)
#define SCP_EXPANSION3_BASE          UINT32_C(0x40000000)
#define SCP_PERIPHERAL_BASE          UINT32_C(0x44000000)
#define SCP_MEMORY_CONTROLLER        UINT32_C(0x4E000000)
#define SCP_POWER_PERIPHERAL_BASE    UINT32_C(0x50000000)
#define SCP_NOC_GPV_BASE             UINT32_C(0x51000000)
#define SCP_SYS0_BASE                UINT32_C(0x60000000)
#define SCP_SYS1_BASE                UINT32_C(0xA0000000)
#define SCP_PPB_BASE_INTERNAL        UINT32_C(0xE0000000)
#define SCP_PPB_BASE_EXTERNAL        UINT32_C(0xE0040000)

/*
 * Peripherals - Timer/Counter
 */
#define SCP_REFCLK_CNTCTL_BASE       (SCP_PERIPHERAL_BASE + 0x0000)
#define SCP_REFCLK_CNTBASE0_BASE     (SCP_PERIPHERAL_BASE + 0x1000)
#define SCP_WDOG_BASE                (SCP_PERIPHERAL_BASE + 0x6000)

/*
 * Timer Synchronization Module base
 */
#define SCP_TIMER_SYNC_BASE          UINT32_C(0x47000000)

/*
 * CoreSight control base
 */
#define SCP_CS_CNTCONTROL_BASE       (SCP_PERIPHERAL_BASE + 0xA000)

/*
 * Peripherals - Serial communication
 */
#define SCP_UART_BASE                (SCP_PERIPHERAL_BASE + 0x2000)
#define DIMM_SPD_I2C_BASE            (0xBC040000)
#define SCP_I2C0_BASE                (0x3FFFA000)
#define SCP_I2C1_BASE                (0x3FFFB000)
#define SCP_I2C2_BASE                (0x3FFFC000)

/*
 * Peripherals - Mailbox communication
 */
#define SCP_MHU_AP_BASE              (SCP_PERIPHERAL_BASE + 0x1000000)
#define SCP_MHU_MCP_BASE             (SCP_PERIPHERAL_BASE + 0x1600000)

/*
 * Power control peripherals
 */
#define SCP_PIK_SCP_BASE             (SCP_POWER_PERIPHERAL_BASE + 0x00000)
#define SCP_PIK_DEBUG_BASE           (SCP_POWER_PERIPHERAL_BASE + 0x20000)
#define SCP_SCP_SENSOR_DEBUG_BASE    (SCP_POWER_PERIPHERAL_BASE + 0x30000)
#define SCP_PIK_SYSTEM_BASE          (SCP_POWER_PERIPHERAL_BASE + 0x40000)
#define SCP_SENSOR_SYSTEM_BASE       (SCP_POWER_PERIPHERAL_BASE + 0x50000)
#define SCP_SENSOR_CLUS0_BASE        (SCP_POWER_PERIPHERAL_BASE + 0x60000)
#define SCP_SENSOR_CLUS1_BASE        (SCP_POWER_PERIPHERAL_BASE + 0x80000)
#define SCP_PIK_DEBUG_CHAIN_BASE     (SCP_POWER_PERIPHERAL_BASE + 0x500000)
#define SCP_PIK_CLUSTER_BASE(n)      ((SCP_POWER_PERIPHERAL_BASE + 0x60000) + \
                                      ((n) * 0x20000))

/*
 * PPU base address
 */
#define SCP_PPU_SCP_BASE             (SCP_PIK_SCP_BASE + 0x1000)
#define SCP_PPU_SYS0_BASE            (SCP_PIK_SYSTEM_BASE + 0x1000)
#define SCP_PPU_SYS1_BASE            (SCP_PIK_SYSTEM_BASE + 0x5000)
#define SCP_PPU_DEBUG_BASE           (SCP_PIK_DEBUG_BASE + 0x1000)
#define SCP_PPU_CLUSTER_BASE(n)      (SCP_PIK_CLUSTER_BASE((n)) + 0x1000)
#define SCP_PPU_CORE_BASE(n, m)      (SCP_PPU_CLUSTER_BASE((n)) + \
                                      ((m) + 1) * 0x1000)

/*
 * PCIe & CCIX Peripherals
 *
 * SCP memory for PCIe and CCIX APB and AXI Access
 * (0x6000_0000 - 0x9FFF_FFFF) maps AP memory address
 * space (0x4000_0000 - 0x7FFF_FFFF)
 */

/*
 * APB Registers
 */
#define PCIE_RC_CFG_REG_SCP_BASE     UINT32_C(0x80000000)
#define PCIE_IP_CFG_REG_SCP_BASE     UINT32_C(0x80800000)
#define PCIE_MSG_CFG_REG_SCP_BASE    UINT32_C(0x80850000)

#define CCIX_RC_CFG_REG_SCP_BASE     UINT32_C(0x82000000)
#define CCIX_IP_CFG_REG_SCP_BASE     UINT32_C(0x82800000)
#define CCIX_MSG_CFG_REG_SCP_BASE    UINT32_C(0x82850000)

/*
 * PCIe and CCIX Subordinate AXI space visible to SCP
 */
#define PCIE_AXI_SUBORDINATE_SCP_BASE UINT32_C(0x90000000)
#define CCIX_AXI_SUBORDINATE_SCP_BASE UINT32_C(0x88000000)

/*
 * PCIe and CCIX Subordinate AXI in 64-bit space visible to AP
 */
#define PCIE_AXI64_SUBORDINATE_AP_BASE UINT64_C(0x900000000)
#define CCIX_AXI64_SUBORDINATE_AP_BASE UINT64_C(0x2900000000)

/*
 * 1MB window into AP memory space
 * This region enables SCP to access AP's memory region
 * in terms of 1MB windows.
 */
#define SCP_AP_1MB_WINDOW_OFFSET     0x2B000000
#define SCP_AP_1MB_WINDOW_BASE       (SCP_SYS1_BASE + SCP_AP_1MB_WINDOW_OFFSET)
#define SCP_AP_1MB_WINDOW_SIZE       0x100000
#define SCP_AP_1MB_WINDOW_ADDR_MASK  0xFFFFF
#define SCP_AP_1MB_WINDOW_SHIFT      20

/*
 * GIC600 Registers
 */
#define GIC600_GICC_BASE          (SCP_SYS1_BASE + 0x2C000000)
#define GIC600_GICH_BASE          (SCP_SYS1_BASE + 0x2C010000)
#define GIC600_GICV_BASE          (SCP_SYS1_BASE + 0x2C020000)

#define GIC600_GICD_BASE          (SCP_SYS1_BASE + 0x30000000)
#define GIC600_GICA_BASE          (SCP_SYS1_BASE + 0x30010000)
#define GIC600_GICP_BASE          (SCP_SYS1_BASE + 0x30030000)
#define GIC600_GITS_BASE          (SCP_SYS1_BASE + 0x30040000)

/*
 * System access port 0
 */
#define SCP_CMN600_BASE           (SCP_SYS0_BASE + 0x10000000)
#define CMN600_ROOT_NODE_OFFSET   0xD00000
#define CMN600_ROOTNODE_BASE      (SCP_CMN600_BASE + CMN600_ROOT_NODE_OFFSET)

#define SCP_AP_SHARED_SECURE_RAM     (SCP_SYS0_BASE + 0x05400000)
#define SCP_AP_SHARED_NONSECURE_RAM  (SCP_SYS0_BASE + 0x05200000)
#define SCP_MCP_SHARED_SECURE_RAM    (SCP_PERIPHERAL_BASE + 0x01620000)
#define SCP_MCP_SHARED_NONSECURE_RAM (SCP_PERIPHERAL_BASE + 0x01610000)

/*
 * System access port 1
 */
#define SCP_TRUSTED_RAM_BASE          (SCP_SYS1_BASE + 0x04000000)
#define SCP_NONTRUSTED_RAM_BASE       (SCP_SYS1_BASE + 0x06000000)
#define SCP_SSC_BASE                  (SCP_SYS1_BASE + 0x2A420000)
#define SCP_REFCLK_CNTCONTROL_BASE    (SCP_SYS1_BASE + 0x2A430000)

/*
 * Base addresses of MHU devices
 */
#define MHU_SCP_TO_AP_NS(cluster) ((SCP_MHU_AP_BASE + \
                                   (0x00010000 * cluster) + 0x00000020))
#define MHU_AP_TO_SCP_NS(cluster) ((SCP_MHU_AP_BASE + \
                                   (0x00010000 * cluster) + 0x00000120))
#define MHU_SCP_TO_AP_S(cluster)  ((SCP_MHU_AP_BASE + \
                                   (0x00010000 * cluster) + 0x00000200))
#define MHU_AP_TO_SCP_S(cluster)  ((SCP_MHU_AP_BASE + \
                                   (0x00010000 * cluster) + 0x00000300))

#define MHU_SCP_TO_MCP_NS         (SCP_MHU_MCP_BASE + 0x00000020)
#define MHU_MCP_TO_SCP_NS         (SCP_MHU_MCP_BASE + 0x00000120)
#define MHU_SCP_TO_MCP_S          (SCP_MHU_MCP_BASE + 0x00000200)
#define MHU_MCP_TO_SCP_S          (SCP_MHU_MCP_BASE + 0x00000300)

/*
 * N1SDP PLL address space
 */
#define SCP_PLL_CPU0_CTRL            (SCP_SCC_BASE + 0x00000100)
#define SCP_PLL_CPU0_STAT            (SCP_SCC_BASE + 0x00000104)
#define SCP_PLL_CPU1_CTRL            (SCP_SCC_BASE + 0x00000108)
#define SCP_PLL_CPU1_STAT            (SCP_SCC_BASE + 0x0000010C)
#define SCP_PLL_CLUS_CTRL            (SCP_SCC_BASE + 0x00000110)
#define SCP_PLL_CLUS_STAT            (SCP_SCC_BASE + 0x00000114)
#define SCP_PLL_SYSPLL_CTRL          (SCP_SCC_BASE + 0x00000118)
#define SCP_PLL_SYSPLL_STAT          (SCP_SCC_BASE + 0x0000011C)
#define SCP_PLL_DMC_CTRL             (SCP_SCC_BASE + 0x00000120)
#define SCP_PLL_DMC_STAT             (SCP_SCC_BASE + 0x00000124)
#define SCP_PLL_INTERCONNECT_CTRL    (SCP_SCC_BASE + 0x00000128)
#define SCP_PLL_INTERCONNECT_STAT    (SCP_SCC_BASE + 0x0000012C)

/*
 * DDR PHY base address
 */
#define SCP_DDR_PHY0                 (0x50604000)
#define SCP_DDR_PHY1                 (0x50614000)

/*
 * DMC-620 controller base address
 */
#define SCP_DMC0                     (SCP_MEMORY_CONTROLLER + 0x00000000)
#define SCP_DMC1                     (SCP_MEMORY_CONTROLLER + 0x00100000)

/*
 * SoC temperature register address
 */
#define SCP_PLAT_BASE                (SCP_SYS0_BASE + 0x3FFE0000)
#define SCP_SENSOR_SOC_TEMP          (SCP_PLAT_BASE + 0x00000080)

#endif /* N1SDP_SCP_MMAP_H */
