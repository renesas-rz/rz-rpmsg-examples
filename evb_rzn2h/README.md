# RZ/N2H Cortex®-R52 / Cortex®-A55 RPMsg example
This is the Cortex-R52 / Cortex-A55 RPMsg example to work with RZ Multi-OS Package. This example uses RZ FSP for BareMetal / FreeRTOS, portable middleware stacks, best in-case HAL drivers, and OpenAMP framework for Asymmetric Multiprocessing systems. By integrating the Multi-OS Package combined with this example, users can efficiently establish a Multi-OS environment wherein Linux operates on the Cortex®-A55 and BareMetal / FreeRTOS runs on the Cortex®-R52 / Cortex®-A55, with support for Inter-Processor Communication between these CPU cores.<br>

**Multi‑OS Software Architecture with Linux on Cortex®‑A55 and Bare‑metal / FreeRTOS on Cortex®‑R52 and Cortex®‑A55**<br>
<img src=./git_images/block-diagram-linux-fsp.png width="720"><br>

**Multi‑OS Software Architecture with Bare‑metal / FreeRTOS on Cortex®‑R52 and Cortex®‑A55**
<img src=./git_images/block-diagram-fsp-fsp.png width="720">


## Table of Contents
- [RZ/N2H Cortex®-R52 / Cortex®-A55 RPMsg example](#rzn2h-cortex-r52--cortex-a55-rpmsg-example)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
    - [Sample Projects](#sample-projects)
    - [Development Environment](#development-environment)
  - [Example project](#example-project)
    - [Hardware setup](#hardware-setup)
    - [Sample program setup on e2 studio](#sample-program-setup-on-e2-studio)
    - [Sample program setup on EWARM](#sample-program-setup-on-ewarm)
    - [Multi-cores sample program invocation](#multi-cores-sample-program-invocation)
      - [Multi-cores sample program invocation with Segger J-Link/ I-Jet](#multi-cores-sample-program-invocation-with-segger-j-link-i-jet)
      - [Multi-cores sample program invocation with remoteproc](#multi-cores-sample-program-invocation-with-remoteproc)
      - [Multi-cores sample program invocation with u-boot](#multi-cores-sample-program-invocation-with-u-boot)
      - [Multi-cores sample program invocation with BL2 of Trusted Firmware-A](#multi-cores-sample-program-invocation-with-bl2-of-trusted-firmware-a)
    - [Sample application result](#sample-application-result)
    - [Overview of sample program behavior](#overview-of-sample-program-behavior)

## Getting Started
### Sample Projects

|No.|Program File|Descriptions|
|----|----|----|
|1|gcc/iar_rzn2h_ca55_1_rpmsg_linux_baremetal_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|2|gcc/iar_rzn2h_ca55_1_rpmsg_linux_freertos_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|3|gcc/iar_rzn2h_ca55_2_rpmsg_linux_baremetal_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|4|gcc/iar_rzn2h_ca55_2_rpmsg_linux_freertos_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|5|gcc/iar_rzn2h_ca55_3_rpmsg_linux_baremetal_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|6|gcc/iar_rzn2h_ca55_3_rpmsg_linux_freertos_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|7|gcc/iar_rzn2h_cr52_0_rpmsg_linux_baremetal_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|8|gcc/iar_rzn2h_cr52_0_rpmsg_linux_freertos_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|9|gcc/iar_rzn2h_cr52_1_rpmsg_linux_baremetal_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|10|gcc/iar_rzn2h_cr52_1_rpmsg_linux_freertos_demo|Sample project to check the Inter-Processor Communication in multi-OS environment.
|11|rzn2h_ca55_0_baremetal_master_ca55_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|12|rzn2h_ca55_0_baremetal_master_ca55_2_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|13|rzn2h_ca55_0_baremetal_master_ca55_3_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|14|rzn2h_ca55_0_baremetal_master_cr52_0_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|15|rzn2h_ca55_0_baremetal_master_cr52_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|16|rzn2h_ca55_0_freertos_master_ca55_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|17|rzn2h_ca55_0_freertos_master_cr52_0_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|18|rzn2h_ca55_1_baremetal_master_ca55_2_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|19|rzn2h_ca55_1_baremetal_master_cr52_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|20|rzn2h_ca55_1_freertos_master_ca55_2_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|21|rzn2h_ca55_1_freertos_master_cr52_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|22|rzn2h_cr52_0_baremetal_master_ca55_0_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|23|rzn2h_cr52_0_baremetal_master_ca55_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|24|rzn2h_cr52_0_baremetal_master_ca55_2_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|25|rzn2h_cr52_0_baremetal_master_ca55_3_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|26|rzn2h_cr52_0_baremetal_master_cr52_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|27|rzn2h_cr52_0_baremetal_master_cr52_1_freertos_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|28|rzn2h_cr52_0_freertos_master_cr52_1_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|29|rzn2h_cr52_1_baremetal_master_cr52_0_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.
|30|rzn2h_cr52_1_freertos_master_cr52_0_baremetal_slave|Sample project to check the Inter-Processor Communication between two FSP cores in a multi-core FSP environment.

### Development Environment
|Hardware|Version|
|----|----|
|[RZ/N2H-EVKIT](https://www.renesas.com/en/design-resources/boards-kits/rz-n2h-evkit)|-|

|Software|Version|
|----|----|
|e² studio|2025-12|
|[Segger J-link](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack)|8.60|
|Arm GNU Toolchain for Cortex-R|13.3.Rel1|
|Arm GNU Toolchain for Cortex-A|13.2.Rel1|
|IAR Embedded Workbench for Arm|9.60.3|
|RZ Smart Configurator|2025-12|
|RZ FSP|4.0.0|
|Tera Term|-|

For more information to set up your development environment, refer to the following document.
- [Getting Started with Flexible Software Package](https://www.renesas.com/en/document/apn/rzt2-rzn2-getting-started-flexible-software-package)


## Example project
1. `<device>_<platform_type>_<role>_<device>_<platform_type>_<role>` (for FSP ↔ FSP communication)
    - `device`: rzn2h_cr52_0 / rzn2h_cr52_1 / rzn2h_ca55_0 / rzn2h_ca55_1 / rzn2h_ca55_2 / rzn2h_ca55_3
    - `platform_type`: baremetal / freertos
    - `role`: master / slave

2. `gcc/iar_<device>_rpmsg_linux_<platform_type>_demo` (for Linux ↔ FSP communication)
    - `device`: rzn2h_cr52_0 / rzn2h_cr52_1 / rzn2h_ca55_1 / rzn2h_ca55_2 / rzn2h_ca55_3
    - `platform_type`: baremetal / freertos

- Lists the boot methods supported in the Linux - FSP example combination.

|Master|Slave|Debugger|Remoteproc|U-boot|BL2
|----|----|----|----|----|----|
|CA55_0 (Linux)|CA55_1 (Baremetal)|Supported|-|-|Supported
|CA55_0 (Linux)|CA55_1 (FreeRTOS)|Supported|-|-|-
|CA55_0 (Linux)|CA55_2 (Baremetal)|Supported|-|-|Supported
|CA55_0 (Linux)|CA55_2 (FreeRTOS)|Supported|-|-|-
|CA55_0 (Linux)|CA55_3 (Baremetal)|Supported|-|-|Supported
|CA55_0 (Linux)|CA55_3 (FreeRTOS)|Supported|-|-|-
|CA55_0 (Linux)|CR52_0 (Baremetal)|Supported|Supported|Supported|Supported
|CA55_0 (Linux)|CR52_0 (FreeRTOS)|Supported|Supported|-|-
|CA55_0 (Linux)|CR52_1 (Baremetal)|Supported|Supported|Supported|Supported
|CA55_0 (Linux)|CR52_1 (FreeRTOS)|Supported|Supported|-|-

The **`<device>_<platform_type>_<role>_<device>_<platform_type>_<role>`** or **`gcc/iar_<device>_rpmsg_linux_<platform_type>_demo`** outputs the message tranfer progress between CPU cores to the console.

### Hardware setup
1. Connect the J-Link OB or I-Jet debugger and a USB-to-serial cable to the RZ/N2H. For details, please refer to [Getting Started with Flexible Software Package](https://www.renesas.com/en/document/apn/rzt2-rzn2-getting-started-flexible-software-package)

2. Setup operation mode switch setting for RZ/N2H Evaluation Board.
- For FSP - FSP combinations.

|Switch|Setting|Description|
|----|----|----|
|DSW3-1|ON|xSPI1 boot mode (x1 boot serial flash).
|DSW3-2|OFF|xSPI1 boot mode (x1 boot serial flash).
|DSW3-3|ON|xSPI1 boot mode (x1 boot serial flash).
|DSW3-4|OFF|CPU0 ATCM wait cycle = 1 wait cycle.
|DSW3-5|OFF|CPU1 ATCM wait cycle = 1 wait cycle.
|DSW3-6|OFF|Supply voltage of boot peripheral is 3.3 V.
|DSW3-7|ON|JTAG mode = Normal mode.
|DSW15-8|OFF|LED8 (Green).
|DSW15-9|OFF|LED8 (Green).
|DSW15-10|ON|LED8 (Green).
|DSW9-1|ON|Reception of UART data 1 for USB-to-serial conversion and transmission of UART data 1 for USB-to-serial conversion.
|DSW9-2|OFF|Reception of UART data 1 for USB-to-serial conversion and transmission of UART data 1 for USB-to-serial conversion.
|DSW9-3|ON|Reception of UART data 1 for USB-to-serial conversion and transmission of UART data 1 for USB-to-serial conversion.
|DSW9-4|OFF|Reception of UART data 1 for USB-to-serial conversion and transmission of UART data 1 for USB-to-serial conversion.
|DSW5-8|OFF|Reception of UART data 2 for USB-to-serial conversion and transmission of UART data 2 for USB-to-serial conversion.
|DSW9-5|ON|Reception of UART data 2 for USB-to-serial conversion and transmission of UART data 2 for USB-to-serial conversion.
|DSW9-6|OFF|Reception of UART data 2 for USB-to-serial conversion and transmission of UART data 2 for USB-to-serial conversion.
|DSW9-7|ON|Reception of UART data 2 for USB-to-serial conversion and transmission of UART data 2 for USB-to-serial conversion.
|DSW9-8|OFF|Reception of UART data 2 for USB-to-serial conversion and transmission of UART data 2 for USB-to-serial conversion.

- For Linux - FSP combinations.

|Switch|Setting|Description|
|----|----|----|
|DSW3-1|ON|xSPI1 boot mode (x1 boot serial flash).
|DSW3-2|ON|xSPI1 boot mode (x1 boot serial flash).
|DSW3-3|ON|xSPI1 boot mode (x1 boot serial flash).
|DSW3-4|OFF|CPU0 ATCM wait cycle = 1 wait cycle.
|DSW3-5|OFF|CPU1 ATCM wait cycle = 1 wait cycle.
|DSW3-6|OFF|Supply voltage of boot peripheral is 3.3 V.
|DSW3-7|ON|JTAG mode = Normal mode.
|DSW5-3|ON|Signal Connections of MicroSD Card Slot.
|DSW19-1|OFF|Signal Connections of MicroSD Card Slot.
|DSW19-2|ON|Signal Connections of MicroSD Card Slot.
|DSW5-8|OFF|Signal Connections of USB-to-Serial Conversion.

### Sample program setup on e<sup>2</sup> studio
1. Open e² studio and import the following projects from this repository into your workspace:
   - `<device>_<platform_type>_<role>_<device>_<platform_type>_<role>`
   - `gcc_<device>_rpmsg_linux_<platform_type>_demo`

2. (Optional for remoteproc sample) Copy CR52 firmware (`.elf`) from user path in Linux PC to '/lib/firmware'.
   (By default, the firmware for the remoteproc sample is pre-prepared in '/meta-rz-multi-os/recipes-firmware/cr52-firmware/files'. Therefore, rebuilding and reloading the sample is only necessary when modifications are made)

3. (Optional for u-boot sample) In the `Clocks tab` configuration, navigate to `CLMA6 Enable` >> `CLMA6 Alternative CLK` and set it to `PLL` (This configuration is performed on the primary core). Navigate to `Choose Project` >> `Properties` >> `C/C++ Build` >> `Settings` >> `Tool Settings` >> `Cross ARM GNU Create Flash Image` >> `General`, then set `Output file format (-O)` to `Raw binary` and remove `--gap-fill 0xff` from `Other flags`.<br>

    <img src=./git_images/block-diagram-uboot-e2-clock.png width="480"><br>

    <img src=./git_images/block-diagram-uboot-e2-setting.png width="480">

4. (Optional for BL2 of Trusted Firmware-A sample) In the `Clocks tab` configuration, navigate to `CLMA6 Enable` >> `CLMA6 Alternative CLK` and set it to `PLL` (This configuration is performed on the primary core). Modify **FSP_STARTUP_LOCATION** to **0x10080000** in 'script/redefinition_memory_regions_gcc.h'. **Modify ENABLE_BL2** to **1** in '/src/RM_OpenAMP_APP/platform_info.h' (This configuration is performed on the CA55 core).<br>
    
    <img src=./git_images/block-diagram-uboot-e2-clock.png width="480">

### Sample program setup on EWARM
1. Open EWARM and import the following projects from this repository into your workspace:
   - `<device>_<platform_type>_<role>_<device>_<platform_type>_<role>`
   - `iar_<device>_rpmsg_linux_<platform_type>_demo`

2. (Optional for remoteproc sample) Copy CR52 firmware (`.out`) from user path in Linux PC to '/lib/firmware'.
   (By default, the firmware for the remoteproc sample is pre-prepared in '/meta-rz-multi-os/recipes-firmware/cr52-firmware/files'. Therefore, rebuilding and reloading the sample is only necessary when modifications are made)

3. (Optional for u-boot sample) In the `Clocks tab` configuration, navigate to `CLMA6 Enable` >> `CLMA6 Alternative CLK` and set it to `PLL` (This configuration is performed on the primary core). Navigate to `Choose Project` >> `Options` >> `Output Converter` >> `Output`, then set `Output format` to `Raw binary`.<br>
   
    <img src=./git_images/block-diagram-uboot-e2-clock.png width="480"><br>
   
    <img src=./git_images/block-diagram-uboot-ewarm-setting.png width="480">

4. (Optional for BL2 of Trusted Firmware-A sample) In the `Clocks tab` configuration, navigate to `CLMA6 Enable` >> `CLMA6 Alternative CLK` and set it to `PLL` (This configuration is performed on the primary core). Modify **FSP_STARTUP_LOCATION** to **0x10080000** in 'script/redefinition_memory_regions_iar.h'. **Modify ENABLE_BL2** to **1** in '/src/RM_OpenAMP_APP/platform_info.h' (This configuration is performed on the CA55 core). Converting a `.srec` file to the S3 record format can be done using tools such as **objcopy**, **arm-none-eabi-objcopy**, or **aarch64-none-elf-objcopy**, as shown below:
    ```
    objcopy.exe -I srec -O srec --srec-forceS3 input_s1.srec output_s3.srec
    ```
    
    <img src=./git_images/block-diagram-uboot-e2-clock.png width="480"><br>

### Multi-cores sample program invocation
#### Multi-cores sample program invocation with Segger J-Link/ I-Jet
1. Configure the switches according to Section **Hardware setup** to select either the **FSP - FSP** or **Linux - FSP** combination. If the Linux - FSP combination is selected, wait until the Linux boot process is complete and the message shown below appears before proceeding:
    ```
    Poky (Yocto Project Reference Distro) 5.0.11 rzn2h-dev ttySC0
    rzn2h-dev login:
    ```

2. Start the debug session by  click `Debug` button in `Debug Configuration` (on e² studio) or Click the `Download and Debug` button on the toolbar to enter debug mode (on EWARM).
- For FSP - FSP combinations:
    - CR52_0 or CA55_0 must execute before other cores.
    - In the case where CR52_0 or CA55_0 is neither a slave core nor a master core, rzn2h_cr52_0_boot/rzn2h_ca55_0_boot must run before other cores begin execution.
    - In the case of CR52_0 or CA55_0 is master core, it should be setup running as procedure below:
        - Run the master core until it reaches the main function.
        - Running slave core programming.
        - Running master core programming again.
    - Slave must run before running master as OpenAMP procedure.
- For Linux- FSP combinations:
    - For the sample program of the CR52_1/ CA55_1/ CA55_2/ CA55_3 cores, the rzn2h_cr52_0_boot project only needs to complete the project build process and does not need to be downloaded to the board.

3. Now that the sample project has started, the following message is shown on the console:
- FSP – FSP combinations:
    - Console of Slave Core:
    ```
    Successfully open uio device: E0000000.rsctbl.
    Successfully added memory device E0000000.rsctbl.
    Successfully open uio device: E1000000.vring-ctl0.
    Successfully added memory device E1000000.vring-ctl0.
    Successfully open uio device: E1200000.vring-shm0.
    Successfully added memory device E1200000.vring-shm0.
    Initialize remoteproc successfully.
    creating remoteproc virtio
    initializing rpmsg vdev
    Remote proc init.
    RPMSG endpoint has created.
    ```
    - Console of Master Core:
    ```
    Successfully open uio device: E0000000.rsctbl.
    Successfully added memory device E0000000.rsctbl.
    Successfully open uio device: E1000000.vring-ctl0.
    Successfully added memory device E1000000.vring-ctl0.
    Successfully open uio device: E1200000.vring-shm0.
    Successfully added memory device E1200000.vring-shm0.
    Initialize remoteproc successfully.
    creating remoteproc virtio
    initializing rpmsg vdev
    Remote proc init.
    RPMSG endpoint has created.
    ```    
- Linux – FSP combinations:
    - Console of FSP Core
    ```
    *************** CR52_0 BAREMETAL ****************
    *************************************************
    Successfully probed IPI device
    Successfully open uio device: 3e0000000.rsctbl.
    Successfully added memory device 3e0000000.rsctbl.
    Successfully open uio device: 3e1000000.vring-ctl0.
    Successfully added memory device 3e1000000.vring-ctl0.
    Successfully open uio device: 3e1200000.vring-shm0.
    Successfully added memory device 3e1200000.vring-shm0.
    Initialize remoteproc successfully.
    creating remoteproc virtio
    initializing rpmsg vdev
    ```

#### Multi-cores sample program invocation with remoteproc
1. Booting up Linux by following **5. Booting and Running Linux** of [RZ/T2H and RZ/N2H Evaluation Board Linux Startup Guide](https://www.renesas.com/en/software-tool/rz-mpu-verified-linux-package-612-cip).

2. Invoke the command below to specify RPMsg sample program to be loaded:
    ```
    root@rzn2h-dev:~# echo <env>_<device>_rpmsg_linux_<platform_type>_demo.<extension> > /sys/class/remoteproc/<remoteprocX>/firmware
    ```
   - `<env>`: gcc / iar
   - `<device>`: rzn2h_cr52_0 / rzn2h_cr52_1
   - `<platform_type>`: baremetal / freertos
   - `<extension>`: elf (for GCC) / out (for IAR)
   - `<remoteprocX>`: remoteproc0 (for kick CR52_0) / remoteproc1 (for kick CR52_1)

3. Kick CR52 by using the command below:
    ```
    root@rzn2h-dev:~# echo start > /sys/class/remoteproc/remoteprocX/state
    ```
    If CR52 starts to work successfully, the following message should be shown:
    ```
    root@rzn2h-dev:~# echo start > /sys/class/remoteproc/remoteprocX/state
    [44.818601] remoteproc remoteprocX: powering up <core>
    [44.905556] remoteproc remoteprocX: Booting fw image <image>, size <size>
    [44.915926] remoteproc remoteprocX: unsupported resource 4
    [44.947845] remoteprocX#vdev0buffer: assigned reserved memory node vdev0buffer@0x3E1200000
    [44.956469] remoteprocX#vdev0buffer: registered virtio0 (type 7)
    [44.962655] remoteproc remoteprocX: remote processor <core> is now up
    ```
    After kick CR52, RPMsg sample can run by using the command below:
    ```
    root@rzn2h-dev:~# rpmsg_sample_client 0
    ```
4. Stop CR52 by using the command below:
    ```
    root@rzn2h-dev:~# echo stop > /sys/class/remoteproc/remoteprocX/state
    ```
    If CR52 stops to work successfully, the following message should be shown:
    ```
    root@rzn2h-dev:~# echo stop > /sys/class/remoteproc/remoteprocX/state 
    [909.395289] remoteproc remoteprocX: stopped remote processor <core>
    ```
5. After stopping CR52, if you want to restart it, execute the command below:
    ```
    root@rzn2h-dev:~# echo start > /sys/class/remoteproc/remoteprocX/state
    ```
6. Change the firmware and shut down the board. Press the reset button to reboot Linux and repeat steps (1) to (5) if you need to change the firmware. Run the shutdown command on the console as shown below to safely power off the board after the program has finished running. After executing the shutdown command, you will see the "reboot: Power down" message. Then, turn off the POWER_SW:
    ```
    root@rzn2h-dev:~# shutdown -h now
    ```

#### Multi-cores sample program invocation with u-boot
1. Place the binary (`.bin`) file into the first partition of the Micro-SD card.
2. Insert Micro-SD card to RZ/N2H Evaluation Board.
3. Turn on the RZ/N2H Evaluation Board using the POWER_SW. To start invoking the sample from U-Boot, press the Reset button. Then, you should see the following message on the console
    ```
    NOTICE: BL2: v2.7(release):2.7.0/t2h_n2h_1.0.2-dirty
    NOTICE: BL2: Built : 17:00:45, Feb 28 2025
    NOTICE: BL2: Booting BL31
    NOTICE: BL31: v2.7(release):2.7.0/t2h_n2h_1.0.2
    NOTICE: BL31: Built : 17:00:45, Feb 28 2025
    U-Boot 2021.10 (Mar 13 2025 - 09:27:21 +0000)
    CPU: Renesas Electronics RZ/N2H
    Model: Renesas Development EVK based on r9a09g077m44
    DRAM: 7.9 GiB
    MMC: mmc@92080000: 0, mmc@92090000: 1
    Loading Environment from MMC... Card did not respond to voltage select! : -84
    *** Warning - No block device, using default environment
    In: serial@80005000
    Out: serial@80005000
    Err: serial@80005000
    Net:
    Warning: ethernet@92010000 (eth1) using random MAC address - 1a:b6:fa:3f:12:31
    Warning: ethernet@92000000 (eth0) using random MAC address - 56:af:cf:b9:61:24
    eth0: ethernet@92000000, eth1: ethernet@92010000
    Hit any key to stop autoboot: 2
    =>    
    ```
4. Hit any key within 3 sec to stop autoboot.
5. Carry out the following setup on u-boot to kick CR52:
    ```
    fatload mmc 1:1 0xC6001000 <env>_<device>_rpmsg_linux_<platform_type>_demo.bin
    cr52 start_<core> 0x10060000 0x80000
    boot
    ```
    After kick CR52, RPMsg sample can run by using the command below:
    ```
    root@rzn2h-dev:~# rpmsg_sample_client 0
    ```
6. Change the firmware and shut down the board. Press the reset button to reboot Linux and repeat steps (1) to (5) if you need to change the firmware. Run the shutdown command on the console as shown below to safely power off the board after the program has finished running. After executing the shutdown command, you will see the "reboot: Power down" message. Then, turn off the POWER_SW:
    ```
    root@rzn2h-dev:~# shutdown -h now
    ```

#### Multi-cores sample program invocation with BL2 of Trusted Firmware-A
1. Re-program the resultant BL2 and FIP binary files using FlashWriter by following **4.6 Download Flash Programmer to RAM, 4.7 Write the Bootloade** of [RZ/T2H and RZ/N2H Evaluation Board Linux Startup Guide](https://www.renesas.com/en/software-tool/rz-mpu-verified-linux-package-612-cip)
2. After rewriting the bootloader files (bl2_bp_xspi0-rzn2h-dev.srec and fip-rzn2h-dev.srec), proceed to program the FSP image here:
    ```
    XSPIW 0 0x00200000 0x00060000 # input command
    send file
    ```
    Send file > `<env>_<device>_rpmsg_linux_<platform_type>_demo.srec`
    ```
    xSPI Initialize complete
    Erased
    Writen
    ```

### Sample application result
1. FSP – FSP combinations:
- LED ON: Turn on by entering 43210C01 on the Master Core.
    ```
    Successfully open uio device: E0000000.rsctbl.
    Successfully added memory device E0000000.rsctbl.
    Successfully open uio device: E1000000.vring-ctl0.
    Successfully added memory device E1000000.vring-ctl0.
    Successfully open uio device: E1200000.vring-shm0.
    Successfully added memory device E1200000.vring-shm0.
    Initialize remoteproc successfully.
    creating remoteproc virtio
    initializing rpmsg vdev
    Remote proc init.
    RPMSG endpoint has created.
    43210C01
    ```
    
- LED OFF: Turn off by entering 43210C00 on the Master Core.
    ```
    Successfully open uio device: E0000000.rsctbl.
    Successfully added memory device E0000000.rsctbl.
    Successfully open uio device: E1000000.vring-ctl0.
    Successfully added memory device E1000000.vring-ctl0.
    Successfully open uio device: E1200000.vring-shm0.
    Successfully added memory device E1200000.vring-shm0.
    Initialize remoteproc successfully.
    creating remoteproc virtio
    initializing rpmsg vdev
    Remote proc init.
    RPMSG endpoint has created.
    43210C00
    ```    
2. Linux – FSP combinations:
- For the sample program for FSP (CR52) – Linux, execute the command as below:
    ```
    rzn2h-dev login: root
    root@rzn2h-dev:~# rpmsg_sample_client 0
    ```
- For the sample program for FSP (CA55) – Linux, follow the steps below:
    After powering on the board, during the countdown process, press any key to stop:
    ```
    NOTICE: BL2: v2.7(release):2.7.0/t2h_n2h_1.0.2-dirty
    NOTICE: BL2: Built : 17:00:45, Feb 28 2025
    NOTICE: BL2: Booting BL31
    NOTICE: BL31: v2.7(release):2.7.0/t2h_n2h_1.0.2
    NOTICE: BL31: Built : 17:00:45, Feb 28 2025
    U-Boot 2021.10 (Mar 13 2025 - 09:27:21 +0000)
    CPU: Renesas Electronics RZ/N2H
    Model: Renesas Development EVK based on r9a09g077m44
    DRAM: 7.9 GiB
    MMC: mmc@92080000: 0, mmc@92090000: 1
    Loading Environment from MMC... Card did not respond to voltage select! : -84
    *** Warning - No block device, using default environment
    In: serial@80005000
    Out: serial@80005000
    Err: serial@80005000
    Net:
    Warning: ethernet@92010000 (eth1) using random MAC address - 1a:b6:fa:3f:12:31
    Warning: ethernet@92000000 (eth0) using random MAC address - 56:af:cf:b9:61:24
    eth0: ethernet@92000000, eth1: ethernet@92010000
    Hit any key to stop autoboot: 2
    =>  
    ```
    Enter the commands below to support the corresponding CA55 cores:
    ```
    setenv bootargs 'ignore_loglevel console=ttySC0,115200n8 rootwait root=/dev/mmcblk1p2 earlycon'
    setenv bootcmd 'ext4load mmc 1:2 0xC4200000 boot/Image; ext4load mmc 1:2 0xC5F00000 boot/r9a09g077m44-dev-fsp-<a55_core>-support.dtb; booti 0xC4200000 - 0xC5F00000'
    boot
    ```
    - `<a55_core>`: a551 (for CA55_1 core)/ a552 (for CA55_2 core)/ a553 (for CA55_3 core)
    Execute the command below:
    ```
    root@rzn2h-dev:~# rpmsg_sample_client 0
    ```  

- Then, you can see the following message on the console of FSP and Linux:
    ```
    echo test: sent : 484
    received payload number 467 of size 484
    sending payload number 468 of size 485
    echo test: sent : 485
    received payload number 468 of size 485
    sending payload number 469 of size 486
    echo test: sent : 486
    received payload number 469 of size 486
    sending payload number 470 of size 487
    echo test: sent : 487
    received payload number 470 of size 487
    sending payload number 471 of size 488
    echo test: sent : 488
    received payload number 471 of size 488
    ************************************
    Test Results: Error count = 0
    ************************************
    Quitting application .. Echo test end
    Stopping application...
    root@rzn2h-dev:~#
    ``` 

### Overview of sample program behavior
**Overview of application for FSP - FSP**
1. Setting up running for the master core and slave core.

2. UART console of Master core and LED of Slave core can operate to control LED ON and LED OFF.

3. Master core reads data from UART that is to turn off/on for led as data below:

|Data|Action|
|----|----|
|43210C01|Turn on LED.
|43210C00|Turn off LED.
|Anything|Do nothing.

4. After completing receive data, the master core will send states to turn on/off to the slave core.

5. The slave core receives a state of led from the master core through OpenAMP. The slave core executes turn on/ off LED. Then, the slave core sends back to inform slave’s implementation for led to the master core through OpenAMP.

6. The master core receives slave’s implementation for led through OpenAMP and print to console 'Slave turned on LED' or 'Slave turned off LED'.

**Overview of application for Linux - FSP**
1. Wait until a communication channel between FSP and Linux is established.

2. Once the communication channel is established, Linux sample program starts to send the message to FSP while increasing its size from the minimum value 17 to the maximum value 488. At that time, the message like the following should be shown in the console connected to USB to Serial Port of RZ/N2H Evaluation Board.
```
Sending payload number 148 of size 165
```

3. When FSP receives the message sent from Linux, the echo reply is sent back to Linux.

4. When Linux receives the echo reply, the message below should be displayed in the console connected to USB to Serial Port of RZ/N2H Evaluation Board.
```
echo test: sent: 165
received payload number 148 of size 165
```

5. After the message which has 488 bytes sized payload is sent from Linux to FSP and FSP sends back the echo reply, the message for terminating the communication channel is sent from Linux to FSP. Then, Linux and FSP sample programs output the following log messages to the corresponding consoles respectively when receiving the termination message.
Termination message on Linux side:
```
************************************
Test Results: Error count = 0
************************************
Quitting application .. Echo test end
Stopping application...
```
Termination message on FSP side:
```
De-initializating remoteproc
```
Then, FSP side re-waits for the establishment of connection channel. You can see the following log on the console a short time later:
```
creating remoteproc virtio
initializing rpmsg vdev
```
