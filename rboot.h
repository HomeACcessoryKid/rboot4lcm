/* rboot header overrides

   This "wrapper" header contains default values for building rboot
   on/for esp-open-rtos. It gets included both when building the
   bootloader and when building extras/rboot-ota support. It includes
   the default bootloader/rboot/rboot.h header via the gcc
   include_next mechanism.
*/
#ifndef __RBOOT_H__

// Big flash support is required for esp-open-rtos (we use 8Mbit
// "slots" only.)
#define BOOT_BIG_FLASH

// enable 2 way communication between
// rBoot and the user app via the esp rtc data area
#define BOOT_RTC_ENABLED

// uncomment to add a boot delay, allows you time to connect
// a terminal before rBoot starts to run and output messages
// value is in microseconds
#define BOOT_DELAY_MICROS 50000
#define BOOT_BAUDRATE 115200
//#define BOOT_BAUDRATE 74880

// to define the time within a new powercycle/reboot will be counted
#define BOOT_CYCLE_DELAY_MICROS 1000000 //1 second? NO, actually this is 1.5 seconds but that is OK...
// indicates where the powercycle tracker bits are stored,
// first half for continue-bits, last half for start-bits
// other space between rboot-config and this address can be used for other purposes
#define BOOT_BITS_ADDR 0x1020 // target value 0x1020
// where the LCM ota_main code sits -> becomes rom1
#define OTA_MAIN_SECTOR 0x8d
// we use a default that knows about LifeCycleManager ota_main
#define BOOT_CUSTOM_DEFAULT_CONFIG
#define COUNT4USER 4 //powercycle count that will not yet trigger ota-main
#define VERSION "1.0.1"

// Call 'main' rboot.h to pick up defaults for other parameters
#include_next "rboot.h"

#endif

