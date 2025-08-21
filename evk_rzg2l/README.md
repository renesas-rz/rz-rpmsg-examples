# RZ/G2L Cortex-M33 RPMsg example

This is the Cortex-M33 RPMsg example to work with RZ/G2L Multi-OS Package. This example uses RZ/G FSP for FreeRTOS, portable middleware stacks, best in-case HAL drivers, and OpenAMP framework for Asymmetric Multiprocessing systems. By integrating the Multi-OS Package combined with this example, users can efficiently establish a Multi-OS environment wherein Linux operates on the Cortex®-A55
and FreeRTOS/BareMetal runs on the Cortex-M33, with support for Inter-Processor Communication between these CPU cores.<br>
<img src=./git_images/block-diagram.png width="720">

## Table of Contents
- [RZ/G2L Cortex-M33 RPMsg example](#rzg2l-cortex-m33-rpmsg-example)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
    - [Sample Projects](#sample-projects)
    - [Development Environment](#development-environment)
  - [Demo rzg2l\_cm33\_rpmsg\_linux-rtos\_example](#demo-rzg2l_cm33_rpmsg_linux-rtos_example)
    - [Hardware setup](#hardware-setup)
    - [CM33 sample project setup](#cm33-sample-project-setup)
    - [CM33 sample program invocation](#cm33-sample-program-invocation)
      - [CM33 sample program invocation with SEGGER J-Link](#cm33-sample-program-invocation-with-segger-j-link)
      - [CM33 sample program invocation with u-boot](#cm33-sample-program-invocation-with-u-boot)
      - [CM33 sample program invocation with remoteproc](#cm33-sample-program-invocation-with-remoteproc)
    - [CA55 sample program invocation](#ca55-sample-program-invocation)
    - [Overview of sample program behavior](#overview-of-sample-program-behavior)

## Getting Started
### Sample Projects
|No.|Program File|Descriptions|
|----|----|----|
|1|rzg2l_cm33_rpmsg_linux-rtos_example|Sample project to check the Inter-Processor Communication in multi-OS environment.


### Development Environment
|Hardware|Version|
|----|----|
|[RZ/G2L-EVKIT](https://www.renesas.com/en/design-resources/boards-kits/rz-g2l-evkit)|-|
|[Segger J-link](https://www.segger.com/products/debug-probes/j-link/)| J-Link BASE v11.0 (J-Link DLL v7.96j) |


|Software|Version|
|----|----|
|e<sup>2</sup> studio|2025-07 (25.7.0)|
|GNU ARM Embedded 13.3-Rel1|13.3.1.arm-13-24|
|RZ/G FSP|3.1.0|
|Tera Term|-|


For more information to set up your development environment, refer to the following document.
- ["Getting Started with Flexible Software Package"](https://www.renesas.com/en/document/apn/rzg2l-getting-started-with-flexible-software-package)


## Demo rzg2l_cm33_rpmsg_linux-rtos_example

The **rzg2l_cm33_rpmsg_linux-rtos_example** outputs the message tranfer progress between CPU cores to the console.

### Hardware setup
1. Connect SEGGER J-Link to RZ/G2L SMARC EVK. For details, please refer to [Getting Started with Flexible Software Package](https://www.renesas.com/en/document/apn/rzg2l-getting-started-with-flexible-software-package)
2. Connect Pmod USBUART to the upper side of Pmod 1 of SMARC Carrier Board as shown below for securing the console for the program running on CM33.
3. Insert micro SD card containing kernel image, device tree, rootfs support for multi-os communication into CN10 connector on the board.<br>
<img src=./git_images/connection-board.png width="720">

### CM33 sample project setup
1. Open e2 studio 2025-07, import **rzg2l_cm33_rpmsg_linux-rtos_example** from this repo to your workspace.
2. (Optional for configuring RPMsg channel)
By default, RPMsg channel 0 is configured to be used on CM33. If you would like to use channel 1, please open the property of **MainTask#0** on FSP Smart Configurator, specify 1 for **Thread Context**, and push **General Project Content** button to reflect the change to the source code.
<img src=./git_images/change_RPMsg_channel.png width="720"><br>
3. (Optional for remoteproc support)
Change the value for ENABLE_REMOTEPROC defined in **src/platform_info.h** from 0 to 1 as shown below:
    ```
    #define ENABLE_REMOTEPROC (1U)
    ```
4. Build the project. The following files should be generated in Debug and/or Release directory in accordance with the active Build Configuration if there is no build failures.
- rzg2l_cm33_rpmsg_linux-rtos_example.elf
- rzg2l_cm33_rpmsg_linux-rtos_example_non_secure_code.bin
- rzg2l_cm33_rpmsg_linux-rtos_example_non_secure_vector.bin
- rzg2l_cm33_rpmsg_linux-rtos_example_secure_code.bin
- rzg2l_cm33_rpmsg_linux-rtos_example_secure_vector.bin

### CM33 sample program invocation
#### CM33 sample program invocation with SEGGER J-Link
1. Start debug project by choosing **rzg2l_cm33_rpmsg_linux-rtos_example Debug_Flat** or **rzg2l_cm33_rpmsg_linux-rtos_example Release_Flat**
2. When Debug Perspective is opened, Program Counter (PC) should be located at the top of Warm_Reset_S function. Then, you need to press **Resume** button.
3. Program stops at the top of main function. So, please click the same button as the previous step to start example.
4. Now that CM33 sample project has started, the following message is shown on the console associated with Pmod USBUART:
    ```
    Successfully probed IPI device
    Successfully open uio device: 42F00000.rsctbl.
    Successfully added memory device 42F00000.rsctbl.
    Successfully open uio device: 43000000.vring-ctl0.
    Successfully added memory device 43000000.vring-ctl0.
    Successfully open uio device: 43200000.vring-shm0.
    Successfully added memory device 43200000.vring-shm0.
    Initialize remoteproc successfully.
    creating remoteproc virtio
    initializing rpmsg vdev
    Waiting for events...
    ```
    Please note that CM33 sample program is waiting for the establishment of RPMsg channel between CM33 and CA55

#### CM33 sample program invocation with u-boot
1. Copy the binary files generated at step 4 of [CM33 sample project Setup](#cm33-sample-project-setup) section to microSD card.
2. Insert the microSD card into CN10 of SMARC Carrier Board.
3. Turn on SMARC EVK by pressing the Power button for a few seconds.
4. Hit any key to stop autoboot within 3 seconds after the following message is shown in the console connected to CN14 of SMRAC Carrier Board:
    ```
    U-Boot 2021.10 (May 16 2025 - 07:01:33 +0000)

    CPU:   Renesas Electronics CPU rev 1.0
    Model: smarc-rzg2l
    DRAM:  1.9 GiB
    SF: Detected mt25qu512a with page size 256 Bytes, erase size 64 KiB, total 64 MiB
    WDT:   watchdog@0000000012800800
    WDT:   Started with servicing (60s timeout)
    MMC:   sd@11c00000: 0, sd@11c10000: 1
    Loading Environment from MMC... OK
    In:    serial@1004b800
    Out:   serial@1004b800
    Err:   serial@1004b800
    U-boot WDT started!
    Net:
    Error: ethernet@11c20000 address not set.

    Error: ethernet@11c30000 address not set.
    No ethernet found.

    Hit any key to stop autoboot:  0
    =>
    ```
5. Load the binary files you copied at step 1 from microSD card to RAM by executing the commands stated below on the console. Here, **N** stands for the partition number in which you stored the binary files.
    ```
    dcache off
    mmc dev 1
    fatload mmc 1:N 0x0001FF80 rzg2l_cm33_rpmsg_linux-rtos_example_secure_vector.bin
    fatload mmc 1:N 0x42EFF440 rzg2l_cm33_rpmsg_linux-rtos_example_secure_code.bin
    fatload mmc 1:N 0x00010000 rzg2l_cm33_rpmsg_linux-rtos_example_non_secure_vector.bin
    fatload mmc 1:N 0x40010000 rzg2l_cm33_rpmsg_linux-rtos_example_non_secure_code.bin
    cm33 start_debug 0x1001FF80 0x00010000
    dcache on
    ```
6. CM33 sample program is now started.

#### CM33 sample program invocation with remoteproc
1. Booting up Linux by following **5. Booting and Running Linux** of [SMARC EVK of RZ/G2L Linux Startup Guide](https://www.renesas.com/en/document/gde/smarc-evk-rzg2l-rzg2lc-rzg2ul-linux-start-guide-rev107).
2. Invoke the command stated below to specify the sample program to be loaded:
    ```
    root@smarc-rzg2l:~# echo rzg2l_cm33_rpmsg_linux-rtos_example.elf > /sys/class/remoteproc/remoteproc0/firmware
    ```
3. Kick CM33 by invoking the command below:
    ```
    root@smarc-rzg2l:~# echo start > /sys/class/remoteproc/remoteproc0/state
    ```
    If CM33 sample program starts to work successfully, the following message should be shown on Linux console:
    ```
    root@smarc-rzg2l:~# echo start > /sys/class/remoteproc/remoteproc0/state
    [   93.703255] remoteproc remoteproc0: powering up cm33
    [   93.796548] remoteproc remoteproc0: Booting fw image rzg2l_cm33_rpmsg_linux-rtos_example.elf, size 1032012
    [   93.806451] remoteproc remoteproc0: unsupported resource 4
    [   93.816511] rproc-virtio rproc-virtio.1.auto: assigned reserved memory node vdev0buffer@43200000
    [   93.825650] rproc-virtio rproc-virtio.1.auto: registered virtio0 (type 7)
    [   93.832603] remoteproc remoteproc0: remote processor cm33 is now up
    ```

### CA55 sample program invocation
1. Boot up Linux by executing the following command on u-boot:
    ```
    => run bootcmd
    ```
2. Login as root.
    ```
    smarc-rzg2l login: root
    ```
3. Run CA55 sample program by executing the following command:
    ```
    root@smarc-rzg2l:~# rpmsg_sample_client
    ```
4. Then, you can see the following message on the console relative to CN14 of SMARC carrier board. Be sure that you invoke CM33 sample program in advance
    ```
    Successfully probed IPI device
    metal: info:      metal_uio_dev_open: No IRQ for device 42f00000.rsctbl.
    Successfully open uio device: 42f00000.rsctbl.
    Successfully added memory device 42f00000.rsctbl.
    metal: info:      metal_uio_dev_open: No IRQ for device 43000000.vring-ctl0.
    Successfully open uio device: 43000000.vring-ctl0.
    Successfully added memory device 43000000.vring-ctl0.
    metal: info:      metal_uio_dev_open: No IRQ for device 43200000.vring-shm0.
    Successfully open uio device: 43200000.vring-shm0.
    Successfully added memory device 43200000.vring-shm0.
    metal: info:      metal_uio_dev_open: No IRQ for device 43100000.vring-ctl1.
    Successfully open uio device: 43100000.vring-ctl1.
    Successfully added memory device 43100000.vring-ctl1.
    metal: info:      metal_uio_dev_open: No IRQ for device 43500000.vring-shm1.
    Successfully open uio device: 43500000.vring-shm1.
    Successfully added memory device 43500000.vring-shm1.
    metal: info:      metal_uio_dev_open: No IRQ for device 42f01000.mhu-shm.
    Successfully open uio device: 42f01000.mhu-shm.
    Successfully added memory device 42f01000.mhu-shm.
    Initialize remoteproc successfully.
    Initialize remoteproc successfully.

    ******************************************
    *   rpmsg communication sample program   *
    ******************************************

    1. communicate with RZ/G2 CM33 ch0
    2. communicate with RZ/G2 CM33 ch1

    e. exit

    please input
    >
    ```
5. Type 1 if RPMsg channel 0 is used on CM33 RPMsg sample program. Also, type 2 if RPMsg channel 1 is used on the sample program.

### Overview of sample program behavior
1. Wait until a communication channel between CA55 and CM33 is established.
2. Once the communication channel is established, CA55 sample program starts to send the message to CM33 by incrementing its size from the minimum value 17 to the maximum value 488. When sending the message, the following log should be shown on Linux console:
    ```
    Sending payload number 148 of size 165
    ```
3. When CM33 receives the message sent from CA55, the echo reply is sent back to CA55.
4. When CA55 receives the echo reply, the message below should be displayed in the console:
    ```
    echo test: sent : 165
    received payload number 148 of size 165
    ```
5. After the message which has 488 bytes sized payload is sent from CA55 to CM33 and CM33 sends back the echo reply, the message for terminating the communication channel is sent from CA55 to CM33. Then, CA55 and CM33 sample programs output the following log messages to the corresponding consoles respectively when receiving the termination message.
  - On CA55 side:
    ```
    ******************************************
    * rpmsg communication sample program *
    ******************************************
    1. communicate with RZ/G2L CM33 ch0
    2. communicate with RZ/G2L CM33 ch1
    e. exit
    please input
    >
    ```
    If you would like to quit the application, please type e.
  - On CM33 side:
    ```
    De-initializating remoteproc
    ```
6. Finally, CM33 sample program re-waits for the establishment of connection channel. You can see the following log on the console a short time later:
    ```
    creating remoteproc virtio
    initializing rpmsg vdev
    ```
