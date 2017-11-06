#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#include "SysTickScheduler.h"
#include "arm_cortex_m_multitasking.h"
#include "arm_cortex_m_wrapper.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE ARM Cortex-M3 (QEMU)
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS 127.0.0.1
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_EXTMODE_CONFIGURATION TCP/IP
#define MW_RTOS Baremetal
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_CLOCKING_CPUCLOCKRATEMHZ 100
#define MW_DATAVERSION 2016.02
#define MW_MULTI_TASKING_MODE 1

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
