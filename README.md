OTA Bootloader (rboot) source module and support files.

rboot is an open source bootloader by Richard Burton:
https://github.com/raburton/rboot

wrapper rboot4lcm to complement homeaccessorykid/life-cycle-manager
-------------------------------------------------------------------
The objective of this repo is to make rboot recognize multiple power reboots
in short time. If detected, the lcm ota-main sector will be launched. Based on 
the amount of reboots, also the sys-param area will be cleared. This provides a
fallback at all times to recover from bad user code or to change the user repository.
Most of the actual functionality will be made in the module rboot


Can be used to build an esp-open-rtos compatible rboot bootloader. Run 'make bootloader' in this directory to compile a new bootloader.

Compiling a new bootloader is optional, there's a prebuilt one in the "firmware_prebuilt" directory that will be used if no new bootloader was compiled.

It is also possible to use rboot from upstream verbatim, but *ensure that the `RBOOT_BIG_FLASH` option is enabled or images in slots other than 0 won't work correctly.

See the contents of the 'rboot' directory for more information on rboot.
