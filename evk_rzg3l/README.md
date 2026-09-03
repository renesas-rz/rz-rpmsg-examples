# RZ/G3L, RZ/G3SE Cortex-M33 RPMsg example

This is the Cortex-M33 RPMsg example to work with RZ Multi-OS Package. This example uses RZ FSP for FreeRTOS, portable middleware stacks, best in-case HAL drivers, and OpenAMP framework for Asymmetric Multiprocessing systems. By integrating the Multi-OS Package combined with this example, users can efficiently establish a Multi-OS environment wherein Linux operates on the Cortex®-A55
and FreeRTOS/BareMetal runs on the Cortex-M33, with support for Inter-Processor Communication between these CPU cores.<br>
<img src=./git_images/block-diagram.png width="720">

## Table of Contents
- [RZ/G3L, RZ/G3SE Cortex-M33 RPMsg example](#rzg3l-rzg3se-cortex-m33-rpmsg-example)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
    - [Sample Projects](#sample-projects)
    - [Development Environment](#development-environment)
  - [Demo rzg3l\_cm33\_rpmsg\_linux\_rtos\_example](#demo-rzg3l_cm33_rpmsg_linux_rtos_example)
    - [Hardware setup](#hardware-setup)
    - [CM33 sample project setup](#cm33-sample-project-setup)
    - [CM33 sample program invocation](#cm33-sample-program-invocation)
      - [CM33 sample program invocation with SEGGER J-Link](#cm33-sample-program-invocation-with-segger-j-link)
      - [CM33 sample program invocation with u-boot](#cm33-sample-program-invocation-with-u-boot)
      - [CM33 sample program invocation with remoteproc](#cm33-sample-program-invocation-with-remoteproc)
      - [CM33 sample program invocation in BL2 of Trusted Firmware-A](#cm33-sample-program-invocation-in-bl2-of-trusted-firmware-a)
      - [CM33 sample program with CM33 cold boot](#cm33-sample-program-with-cm33-cold-boot)
    - [CA55 sample program invocation](#ca55-sample-program-invocation)
    - [Overview of sample program behavior](#overview-of-sample-program-behavior)
  - [Creating a Custom Project for RZ/G3SE](#creating-a-custom-project-for-rzg3se)
    - [Create a New Project](#create-a-new-project)
    - [Configure and Build the application](#configure-and-build-the-application)

## Getting Started
### Sample Projects
|No.|Program File|Descriptions|
|----|----|----|
|1|rzg3l_cm33_rpmsg_linux_rtos_example|Sample project to check the Inter-Processor Communication in multi-OS environment.


### Development Environment
|Hardware|Version|
|----|----|
|[RZ/G3L-EVKIT](https://www.renesas.com/en/design-resources/boards-kits/rz-g3l-evkit)|-|
|[Segger J-link](https://www.segger.com/products/debug-probes/j-link/)| J-Link BASE v11.0 (J-Link DLL v9.44) |


|Software|Version|
|----|----|
|e<sup>2</sup> studio|2026-07 (26.07.0)|
|GNU ARM Embedded 13.3-Rel1|13.3.1.arm-13-24|
|RZ FSP|4.2.0|
|Tera Term|-|


For more information to set up your development environment, refer to the following document.
- [Getting Started with Flexible Software Package](https://www.renesas.com/en/document/apn/rzg2l-getting-started-with-flexible-software-package)


## Demo rzg3l_cm33_rpmsg_linux_rtos_example

The **rzg3l_cm33_rpmsg_linux_rtos_example** outputs the message tranfer progress between CPU cores to the console.

### Hardware setup
1. Connect USB Type Micro-AB cable to SER3_UART Connector.
2. Insert micro SD card containing kernel image, device tree, rootfs support for multi-os communication into SD**n** slot of SMARC board.
3. Connect SEGGER J-Link to RZ/G3L SMARC EVK. For details, please refer to [Getting Started with Flexible Software Package](https://www.renesas.com/en/document/apn/rzg2l-getting-started-with-flexible-software-package)
4. Connect USB-PD Power Charger to USB Type-C Connector (USB-C_PWR_IN).<br>
<img src=./git_images/connection-board.png width="720">

### CM33 sample project setup
1. Open e2 studio 2026-07, import **rzg3l_cm33_rpmsg_linux-rtos_example** from this repo to your workspace.
2. (Optional for configuring RPMsg channel)
By default, RPMsg channel 0 is configured to be used on CM33. If you would like to use channel 1, please open the property of **Main Task** on FSP Smart Configurator, specify 1 for **Thread Context**, and push **General Project Content** button to reflect the change to the source code.
<img src=./git_images/change_RPMsg_channel.png width="720"><br>
3. (Optional for remoteproc support)
    Change the value for ENABLE_REMOTEPROC defined in **src/platform_info.h** from 0 to 1 as shown below:
    ```
    #define ENABLE_REMOTEPROC (1U)
    ```
4. Build the project. The following files should be generated in Debug and/or Release directory in accordance with the active Build Configuration if there is no build failures.
- rzg3l_cm33_rpmsg_linux_rtos_example.elf
- rzg3l_cm33_rpmsg_linux_rtos_example_non_secure_code.bin
- rzg3l_cm33_rpmsg_linux_rtos_example_non_secure_vector.bin
- rzg3l_cm33_rpmsg_linux_rtos_example_secure_code.bin
- rzg3l_cm33_rpmsg_linux_rtos_example_secure_vector.bin

### CM33 sample program invocation
#### CM33 sample program invocation with SEGGER J-Link
1. Start debug project by choosing **rzg3l_cm33_rpmsg_linux-rtos_example Debug_Flat** or **rzg3l_cm33_rpmsg_linux-rtos_example Release_Flat**
2. When Debug Perspective is opened, Program Counter (PC) should be located at the top of Warm_Reset_S function. Then, you need to press **Resume** button.
3. Program stops at the top of main function. So, please click the same button as the previous step to start example.
4. Now that CM33 sample project has started.
    Please note that CM33 sample program is waiting for the establishment of RPMsg channel between CM33 and CA55

#### CM33 sample program invocation with u-boot
1. Copy the binary files generated at step 4 of [CM33 sample project Setup](#cm33-sample-project-setup) section to microSD card.
2. Insert the microSD card into SD**n** slot of SMARC Carrier Board.
3. Turn on SMARC EVK by pressing the Power button for a few seconds.
4. Hit any key to stop autoboot within 3 seconds after the following message is shown in the console connected to SER3_UART of SMARC Carrier Board:
    ```
    U-Boot 2024.07 (Sep 15 2025 - 02:44:29 +0000)

    CPU:   Renesas Electronics CPU rev 12.0
    Model: smarc-rzg3l
    DRAM:  1.9 GiB
    Core:  30 devices, 15 uclasses, devicetree: separat
    MMC:   sd@11c00000: 0, sd@11c10000: 1, sd@11c20000: 2
    WDT:   Started with servicing (60s timeout)
    MMC:   sd@11c00000: 0, sd@11c10000: 1
    Loading Environment from MMC... Reading from MMC(0)... OK
    In:    serial@100ac000
    Out:   serial@100ac000
    Err:   serial@100ac000
    Net:
    Error: ethernet@11c40000 No valid MAC address found.
    Error: ethernet@11c30000 No valid MAC address found.
    Error: ethernet@11c30000 No valid MAC address found.
    Error: ethernet@11c40000 No valid MAC address found.
    No ethernet found.

    Hit any key to stop autoboot:  0
    =>
    ```

5. Set up U-boot environmental variables.
    ```
    => env default -a
    => setenv bootargs 'console=ttySC3,115200 rw rootwait earlycon root=/dev/mmcblknp2'
    => setenv bootcmd 'mmc dev n;ext4load mmc n:2 0x48080000 /boot/Image;ext4load mmc n:2 0x48000000 /boot/r9a08g046l48-smarc.dtb;booti 0x48080000 - 0x48000000'
    => saveenv
    ```
    Note: **n** stand for partition number of SD slot on RZ/G3L SMARC board.

6. Load the binary files you copied at step 1 from microSD card to RAM by executing the commands stated below on the console. Here, **n** stands for the partition number in which you stored the binary files.
    ```
    => setenv cm33start 'dcache off\
    mmc dev n\
    ext4load mmc n:2 0x00023000 rzg3l_cm33_rpmsg_linux_rtos_example_secure_vector.bin\
    ext4load mmc n:2 0x00023890 rzg3l_cm33_rpmsg_linux_rtos_example_secure_code.bin\
    ext4load mmc n:2 0x10023800 rzg3l_cm33_rpmsg_linux_rtos_example_non_secure_vector.bin\
    ext4load mmc n:2 0x10023840 rzg3l_cm33_rpmsg_linux_rtos_example_non_secure_code.bin\
    mw.l 0x11020864 0x0001312C\
    mw.l 0x11020868 0x0001312C\
    mw.l 0x1102086C 0x00023000\
    mw.l 0x11020870 0x10023800\
    mw.l 0x11010504 0x00010001\
    mw.l 0x11010804 0x00040004\
    mw.l 0x11010804 0x00070007\
    dcache on'
    => run cm33 start
    ```
6. CM33 sample program is now started.

#### CM33 sample program invocation with remoteproc
1. Booting up Linux by following RZ/G3L Linux Startup Guide.
2. Invoke the command stated below to specify the sample program to be loaded:
    ```
    root@smarc-rzg3l:~# echo rzg3l_cm33_rpmsg_linux_rtos_example.elf > /sys/class/remoteproc/remoteproc0/firmware
    ```
3. Kick CM33 by invoking the command below:
    ```
    root@smarc-rzg3l:~# echo start > /sys/class/remoteproc/remoteproc0/state
    ```
    If CM33 sample program starts to work successfully, the following message should be shown on Linux console:
    ```
    root@smarc-rzg3l:~# echo start > /sys/class/remoteproc/remoteproc0/state
    [   93.703255] remoteproc remoteproc0: powering up cm33
    [   93.796548] remoteproc remoteproc0: Booting fw image rzg3l_cm33_rpmsg_linux_rtos_example.elf, size 1014548
    [   93.806451] remoteproc remoteproc0: unsupported resource 4
    [   93.816511] rproc-virtio rproc-virtio.2.auto: assigned reserved memory node vdev0buffer@43200000
    [   93.825650] rproc-virtio rproc-virtio.2.auto: registered virtio0 (type 7)
    [   93.832603] remoteproc remoteproc0: remote processor cm33 is now up
    ```

#### CM33 sample program invocation in BL2 of Trusted Firmware-A
##### Deployment of Build Artifacts for CA55 cold boot

1. Connect SER3_UART of RZG3L SMARC EVK with Host PC and established serial port connection.
2. Configure DIPSW of RZ/G3L SMARC EVK as follows, to specify CA55 cold boot and SCIF download mode.

###### SW_OPT_MUX

| Switch  | 1   | 2   | 3   | 4  |
|---------|-----|-----|-----|----|
| Setting | OFF | OFF | OFF | ON |

###### SW_MODE

| Switch  | 1   | 2      | 3   | 4  |
|---------|-----|--------|-----|----|
| Setting | OFF | **ON** | OFF | ON |

###### When using SD1 slot

###### BOOT

| Switch  | 1  | 2   | 3   | 4   | 5   | 6   |
|---------|----|-----|-----|-----|-----|-----|
| Setting | ON | OFF | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4   | 5   | 6   |
|---------|-----|-----|----|-----|-----|-----|
| Setting | OFF | OFF | ON | OFF | OFF | OFF |

###### When using JTAG & SD2 slot

###### BOOT

| Switch  | 1       | 2   | 3   | 4   | 5   | 6   |
|---------|---------|-----|-----|-----|-----|-----|
| Setting | **OFF** | OFF | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4      | 5   | 6   |
|---------|-----|-----|----|--------|-----|-----|
| Setting | OFF | OFF | ON | **ON** | OFF | OFF |

##### CM33 sample project setup for CA55 cold boot
1. Open e2 studio 2026-07, create a new CM33 project by selecting the board "RZ/G3L Evaluation Board Kit (SMARC) - Booting from TF-A on Cortex-A55 cold boot".
2. Build the project. Upon a successful build, the generated `.srec` file can be found in the Debug and/or Release directory in accordance with the active Build Configuration.
3. Deploy the generated `.srec` file using Flash Writer via QSPI as follow:

    Program the `.srec` file as shown:
    ```
    > xls2
    ===== Qspi writing of RZ/G Board Command =============
    Load Program to Spiflash
    ===== Please Input Program Top Address ============
    Please Input : H'00000
    ===== Please Input Qspi Save Address ===
    Please Input : H'270000
    please send ! ('.' & CR stop load)
    ```

    After the transfer finishes, you should see messages confirming SPI erase and write completion.

    Return the board to normal boot mode and continue setup per the Linux Start-up Guide.

##### Set up the board for CA55 cold boot and xSPI boot mode
After all build artifacts have been deployed, change the board's DIP switch settings as shown below,
and then power-cycle the board.

###### SW_OPT_MUX

| Switch  | 1   | 2   | 3   | 4  |
|---------|-----|-----|-----|----|
| Setting | OFF | OFF | OFF | ON |

###### SW_MODE

| Switch  | 1   | 2       | 3   | 4  |
|---------|-----|---------|-----|----|
| Setting | OFF | **OFF** | OFF | ON |

###### When using SD1 slot

###### BOOT

| Switch  | 1  | 2   | 3   | 4   | 5   | 6   |
|---------|----|-----|-----|-----|-----|-----|
| Setting | ON | OFF | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4   | 5   | 6   |
|---------|-----|-----|----|-----|-----|-----|
| Setting | OFF | OFF | ON | OFF | OFF | OFF |

###### When using JTAG & SD2 slot

###### BOOT

| Switch  | 1       | 2   | 3   | 4   | 5   | 6   |
|---------|---------|-----|-----|-----|-----|-----|
| Setting | **OFF** | OFF | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4      | 5   | 6   |
|---------|-----|-----|----|--------|-----|-----|
| Setting | OFF | OFF | ON | **ON** | OFF | OFF |

#### CM33 sample program with CM33 cold boot
##### Deployment of Build Artifacts for CM33 cold boot

1. Connect SER3_UART of RZG3L SMARC EVK with Host PC and established serial port connection.
2. Configure DIPSW of RZ/G3L SMARC EVK as follows, to specify CA55 cold boot and SCIF download mode.

###### SW_OPT_MUX

| Switch  | 1   | 2   | 3   | 4  |
|---------|-----|-----|-----|----|
| Setting | OFF | OFF | OFF | ON |

###### SW_MODE

| Switch  | 1   | 2      | 3   | 4  |
|---------|-----|--------|-----|----|
| Setting | OFF | **ON** | OFF | ON |

###### When using SD1 slot

###### BOOT

| Switch  | 1  | 2   | 3   | 4   | 5   | 6   |
|---------|----|-----|-----|-----|-----|-----|
| Setting | ON | OFF | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4   | 5   | 6   |
|---------|-----|-----|----|-----|-----|-----|
| Setting | OFF | OFF | ON | OFF | OFF | OFF |

###### When using JTAG & SD2 slot

###### BOOT

| Switch  | 1       | 2   | 3   | 4   | 5   | 6   |
|---------|---------|-----|-----|-----|-----|-----|
| Setting | **OFF** | OFF | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4      | 5   | 6   |
|---------|-----|-----|----|--------|-----|-----|
| Setting | OFF | OFF | ON | **ON** | OFF | OFF |

##### CM33 sample project setup for CM33 cold boot
1. Open e2 studio 2026-07, create a new CM33 project by selecting the board "RZ/G3L Evaluation Board Kit (SMARC) - Cortex-M33 cold boot".
2. Build the project. Upon a successful build, the generated `.srec` file can be found in the Debug and/or Release directory in accordance with the active Build Configuration.
3. Deploy the generated `.srec` file using Flash Writer via QSPI as follow:

    Program the `.srec` file as shown:
    ```
    > xls2
    ===== Qspi writing of RZ/G2 Board Command =============
    Load Program to Spiflash
    ===== Please Input Program Top Address ============
    Please Input : H'21E00
    ===== Please Input Qspi Save Address ===
    Please Input : H'00000
    please send ! ('.' & CR stop load)
    ```
    After the transfer finishes, you should see messages confirming SPI erase and write completion.

    In addition, when using the CM33 cold boot environment,
    replace the programming address of bl2_bp_spi-smarc-rzg3l.srec in the Linux Start Up Guide with the address below before proceeding.

    ```
    > xls2
    ===== Qspi writing of RZ/G2 Board Command =============
    Load Program to Spiflash
    ===== Please Input Program Top Address ============
    Please Input : H'00000
    ===== Please Input Qspi Save Address ===
    Please Input : H'270000
    please send ! ('.' & CR stop load)
    ```

    Return the board to normal boot mode and continue setup per the Linux Start-up Guide.

##### Set up the board for CM33 cold boot and xSPI boot mode

After all build artifacts have been deployed, change the board's DIP switch settings as shown below,
and then power-cycle the board.

###### SW_OPT_MUX

| Switch  | 1   | 2   | 3   | 4  |
|---------|-----|-----|-----|----|
| Setting | OFF | OFF | OFF | ON |

###### SW_MODE

| Switch  | 1   | 2       | 3   | 4  |
|---------|-----|---------|-----|----|
| Setting | OFF | **OFF** | OFF | ON |

###### When using SD1 slot

###### BOOT

| Switch  | 1  | 2      | 3   | 4   | 5   | 6   |
|---------|----|--------|-----|-----|-----|-----|
| Setting | ON | **ON** | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4   | 5   | 6   |
|---------|-----|-----|----|-----|-----|-----|
| Setting | OFF | OFF | ON | OFF | OFF | OFF |

###### When using JTAG & SD2 slot

###### BOOT

| Switch  | 1       | 2      | 3   | 4   | 5   | 6   |
|---------|---------|--------|-----|-----|-----|-----|
| Setting | **OFF** | **ON** | OFF | OFF | OFF | OFF |

###### SYS

| Switch  | 1   | 2   | 3  | 4      | 5   | 6   |
|---------|-----|-----|----|--------|-----|-----|
| Setting | OFF | OFF | ON | **ON** | OFF | OFF |

### CA55 sample program invocation
1. Boot up Linux by executing the following command on u-boot:
    ```
    => run bootcmd
    ```
2. Login as root.
    ```
    smarc-rzg3l login: root
    ```
3. Run CA55 sample program by executing the following command:
    ```
    root@smarc-rzg3l:~# rpmsg_sample_client
    ```
4. Then, you can see the following message on the console relative to SER3_UART of SMARC carrier board. Be sure that you invoke CM33 sample program in advance
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

    1. communicate with RZ/G3L CM33 ch0
    2. communicate with RZ/G3L CM33 ch1

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
    1. communicate with RZ/G3L CM33 ch0
    2. communicate with RZ/G3L CM33 ch1
    e. exit
    please input
    >
    ```
    If you would like to quit the application, please type e.
6. Finally, CM33 sample program re-waits for the establishment of connection channel.


## Creating a Custom Project for RZ/G3SE
### Create a New Project
1. Launch e² studio. 
2. Select **File > New > Renesas C/C++ Project** 
3. Enter a project name. 
4. Select the project template “**RZ/G3L, RZ/G3SE Custom User Board**”.
<img src=./git_images/select-project-template-for-rzg3se.png width="720"><br>
5. Select the device that matches the target hardware.<br>
<img src=./git_images/select-target-device-for-rzg3se.png width="720"><br>
6. Click **Next** to proceed through the remaining configuration pages using, unless customization is required.
7. Click **Finish** to create the project.

### Configure and Build the application
1. Open **configuration.xml** in the project.
2. In the **Stacks Configuration** tab, add and configure the required software components.
3. Configure the peripheral settings and middleware parameters as required by the application.
4. Click **Generate Project Content**.
5. Confirm that the generated source files are created successfully.
6. Add user application source files to the project.
7. Build the project.
