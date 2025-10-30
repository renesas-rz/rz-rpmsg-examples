# RZ/G3S Cortex-M33 RPMsg example

This is the Cortex-M33 RPMsg example to work with RZ/G3S Multi-OS Package. This example uses RZ/G FSP for FreeRTOS, portable middleware stacks, best in-case HAL drivers, and OpenAMP framework for Asymmetric Multiprocessing systems. By integrating the Multi-OS Package combined with this example, users can efficiently establish a Multi-OS environment wherein Linux operates on the Cortex®-A55
and FreeRTOS/BareMetal runs on the Cortex-M33, with support for Inter-Processor Communication between these CPU cores.<br>
<img src=./git_images/block-diagram.png width="720">

## Table of Contents
- [RZ/G3S Cortex-M33 RPMsg example](#rzg3s-cortex-m33-rpmsg-example)
 	- [Table of Contents](#table-of-contents)
	- [Getting Started](#getting-started)
    	- [Sample Projects](#sample-projects)
		- [Development Environment](#development-environment)
	- [Demo rzg3s\_cm33\_rpmsg\_linux-rtos\_example](#demo-device_rpmsg_com_type_example)
    	- [Hardware setup](#hardware-setup)
    	- [CM33 sample project setup](#cm33-sample-project-setup)
   		- [CM33 sample program invocation](#cm33-sample-program-invocation)
    		- [CM33 sample program invocation with SEGGER J-Link](#cm33-sample-program-invocation-with-segger-j-link)
    		- [CM33 sample program invocation with u-boot](#cm33-sample-program-invocation-with-u-boot)
    		- [CM33 sample program invocation with remoteproc](#cm33-sample-program-invocation-with-remoteproc)
			- [CM33 sample program invocation with BL2 of Trusted Firmware-A](#cm33-sample-program-invocation-with-bl2-of-trusted-firmware-a)
            - [CM33 sample program invocation with cold boot support](#cm33-sample-program-invocation-with-cold-boot-support)
		- [CA55 sample program invocation](#ca55-sample-program-invocation)
		- [Overview of sample program behavior](#overview-of-sample-program-behavior)

## Getting Started
### Sample Projects
|No.|Program File|Descriptions|
|----|----|----|
|1|rzg3s_cm33_rpmsg_linux-rtos_example|Sample project to check the Inter-Processor Communication in multi-OS environment.
|2|rzg3s_cm33_fpu_rpmsg_linux-rtos_example|Sample project to check the Inter-Processor Communication in multi-OS environment.
|3|rzg3s_cm33_rpmsg_rtos-rtos_example|Sample project to check the Inter-Processor Communication between two RTOS cores in a multi-core RTOS environment.
|4|rzg3s_cm33_fpu_rpmsg_rtos-rtos_example|Sample project to check the Inter-Processor Communication between two RTOS cores in a multi-core RTOS environment.

### Development Environment
|Hardware|Version|
|----|----|
|[RZ/G3S-EVKIT](https://www.renesas.com/en/design-resources/boards-kits/rz-g3s-evkit )|-|
|[Segger J-link](https://www.segger.com/products/debug-probes/j-link/)| J-Link BASE v11.0 (J-Link DLL v7.96j) |


|Software|Version|
|----|----|
|e<sup>2</sup> studio|2025-07 (25.7.0)|
|GNU ARM Embedded 13.3-Rel1|13.3.1.arm-13-24|
|RZ/G FSP|3.1.0|
|Tera Term|-|


For more information to set up your development environment, refer to the following.
- [Getting Started with Flexible Software Package](https://www.renesas.com/en/document/apn/rzg2l-getting-started-with-flexible-software-package)


## Demo **`<device>_rpmsg_<com_type>_example`**
1. `<device>` should be either `rzg3s_cm33` or `rzg3s_cm33_fpu`
2. `<com_type>` should be one of the following:
    - `linux-rtos` (for Linux ↔ RTOS communication)
    - `rtos-rtos` (for RTOS ↔ RTOS communication)

The **`<device>_rpmsg_<com_type>_example`** outputs the message tranfer progress between CPU cores to the console.

### Hardware setup
1. Connect USB Type Micro-AB cable to SER3_UART Connector .
2. Insert micro SD card containing kernel image, device tree, rootfs support for multi-os communication into SDIO connector on the board.
3. Connect Pmod USBUART to the upper side of Pmod 1 of SMARC Carrier Board as shown below for securing the console for the program running on CM33.
4. Connect SEGGER J-Link to RZ/G3S SMARC EVK. For details, please refer to [Getting Started with Flexible Software Package](https://www.renesas.com/en/document/apn/rzg2l-getting-started-with-flexible-software-package)
5. Connect USB-PD Power Charger to USB_C_PWR_IN.<br>
<img src=./git_images/connection-board.png width="720">

### CM33 sample project setup
1. Open e² studio 2025-07 and import the following projects from this repository into your workspace: `<device>_rpmsg_<com_type>_example`
2. (Optional for configuring RPMsg channel) By default, RPMsg channel 0 is configured to be used on CM33. If you would like to use channel 1, please open the property of **MainTask#0** on FSP Smart Configurator, specify 1 for **Thread Context**, and push **General Project Content** button to reflect the change to the source code.

    <img src=./git_images/change_RPMsg_channel.png width="720"><br>
3. (Optional for remoteproc support) Change the value for ENABLE_REMOTEPROC defined in **src/platform_info.h** from 0 to 1 as shown below:
    ```
    #define ENABLE_REMOTEPROC (1U)
    ```

4. (Optional for CM33 cold boot support) Configure Launch Cortex-A55 (core0) as Enabled
5.  Click Generate Project Content to generate the updated source code, then Build the project from Choose Project > Build Project
6. If the build is successfully completed, the following files should be generated in the **Debug** and/or **Release** folder in accordance with the active Build Configuration:
- `<device>_rpmsg_<com_type>_example.elf`
- `<device>_rpmsg_<com_type>_example.srec`

### CM33 sample program invocation
#### CM33 sample program invocation with SEGGER J-Link
1. Start the debug session by selecting one of the following configurations: **`<device>_rpmsg_<com_type>_example Debug_Flat`** or **`<device>_rpmsg_<com_type>_example Release_Flat`**

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
2. Insert the microSD card into SMARC Carrier Board.
3. Turn on SMARC EVK by pressing the Power button for a few seconds.
4. Hit any key to stop autoboot within 3 seconds after the following message is shown in the console connected to SER3_UART of SMARC Carrier Board:
    ```
    U-Boot 2024.07 (Sep 10 2025 - 18:07:39 +0000)

    CPU:   Renesas Electronics CPU rev 16.7
    Model: smarc-rzg3s
    DRAM:  896 MiB
    Core:  31 devices, 15 uclasses, devicetree: separate
    MMC:   sd@11c00000: 0, sd@11c10000: 1, sd@11c20000: 2
    Loading Environment from MMC... Reading from MMC(0)... *** Warning - bad CRC, using default environment

    In:    serial@1004b800
    Out:   serial@1004b800
    Err:   serial@1004b800
    Net:
    Error: ethernet@11c30000 No valid MAC address found.
    No ethernet found.

    Hit any key to stop autoboot:  0
    =>
    ```

5. Load the binary files you copied at step 1 from microSD card to RAM by executing the commands stated below on the console. Here, **N** stands for the partition number in which you stored the binary files.
- For CM33:
    ```
	 => dcache off
	 => mmc dev 1
	 => fatload mmc 1:N 0x00023000 rzg3s_cm33_rpmsg_linux-rtos_example_secure_vector.bin
	 => fatload mmc 1:N 0x00023890 rzg3s_cm33_rpmsg_linux-rtos_example_secure_code.bin
	 => fatload mmc 1:N 0x10023800 rzg3s_cm33_rpmsg_linux-rtos_example_non_secure_vector.bin
	 => fatload mmc 1:N 0x10023840 rzg3s_cm33_rpmsg_linux-rtos_example_non_secure_code.bin
	 => mw.l 0x11020844 0x0001312C
	 => mw.l 0x11020848 0x0001312C
	 => mw.l 0x1102084C 0x00023000
	 => mw.l 0x11020850 0x10023800
	 => mw.l 0x11010504 0x00010001
	 => mw.l 0x11010804 0x00040004
	 => mw.l 0x11010804 0x00070007
	 => dcache on
    ```
- For CM33_FPU:
    ```
	 => dcache off
	 => mmc dev 1
	 => fatload mmc 1:N 0x00060000 rzg3s_cm33_fpu_rpmsg_linux-rtos_example_secure_vector.bin
	 => fatload mmc 1:N 0x00060890 rzg3s_cm33_fpu_rpmsg_linux-rtos_example_secure_code.bin
	 => fatload mmc 1:N 0x10060800 rzg3s_cm33_fpu_rpmsg_linux-rtos_example_non_secure_vector.bin
	 => fatload mmc 1:N 0x10060840 rzg3s_cm33_fpu_rpmsg_linux-rtos_example_non_secure_code.bin
	 => mw.l 0x11020884 0x0001312C
	 => mw.l 0x11020888 0x0001312C
	 => mw.l 0x1102088C 0x00060000
	 => mw.l 0x11020890 0x10060800
	 => mw.l 0x11010504 0x01000100
	 => mw.l 0x11010804 0x04000400
	 => mw.l 0x11010804 0x07000700
	 => dcache on
    ```
6. CM33 sample program is now started.

#### CM33 sample program invocation with remoteproc
1. Booting up Linux by following **5. Booting and Running Linux** of [SMARC EVK of RZ/G3S Linux Startup Guide](https://www.renesas.com/en/document/gde/smarc-evk-rzg3s-linux-start-guide-rev106?queryID=b43f812bac9bf1c0c633e68a3c6ea99e).
3.  Invoke the command below to specify RPMsg sample program to be loaded:
    ```
    root@smarc-rzg3s:~# echo <device>_rpmsg_<com_type>_example.elf > /sys/class/remoteproc/remoteprocX/firmware
    (Note)
    ```
4. Trigger CM33 execution by invoking the command below:
    ```
    root@smarc-rzg3s:~# echo start > /sys/class/remoteproc/remoteprocX/state
    ```
    If CM33 sample program starts to work successfully, the following message should be shown on Linux console:
    ```
    root@smarc-rzg3s:~# echo start > /sys/class/remoteproc/remoteproc0/state
    [ 152.569813] remoteproc remoteproc0: powering up cm33
    [ 152.647167] remoteproc remoteproc0: Booting fw image rzg3s_cm33_rpmsg_linux-rtos_example.elf, size 1068216
    [ 152.657050] remoteproc remoteproc0: unsupported resource 4
    [ 152.669150] remoteproc0#vdev0buffer: assigned reserved memory node vdev0buffer@0x43200000
    [ 152.682507] remoteproc0#vdev0buffer: registered virtio1 (type 7)
    [ 152.692313] remoteproc remoteproc0: remote processor cm33 is now up
    ```
    **Note**: `remoteprocX` can be either `remoteproc0` or `remoteproc1`.
    - When you would like to trigger **CM33** execution, `remoteproc0` should be specified.
    - Also, `remoteproc1` should be specified for triggering **CM33_FPU** execution.

#### CM33 sample program invocation with BL2 of Trusted Firmware-A
1. Re-program the resultant BL2 and FIP binary files using FlashWriter by following **4.3 Download Flash Writer to RAM** of [SMARC EVK of RZ/G3S Linux Startup Guide](https://www.renesas.com/en/document/gde/smarc-evk-rzg3s-linux-start-guide-rev106?queryID=b43f812bac9bf1c0c633e68a3c6ea99e)
2. Program `<device>_rpmsg_<com_type>_example.srec` using FlashWriter with the parameter stated below:
- For Boot Mode 1 (boot image for eMMC mode)
	
	|Partition Area| Start Address in sector |Program Start Address|
	|:------------:|:-----------------------:|:-------------------:|
	|	1 		   |		1000 			 |80200000			   |
	
- For Boot Mode 2 (boot image for xSPI mode)
	
	|Address to load to RAM|Address to save to ROM|
	|:--------------------:|:--------------------:|
	|80200000		  	   |		200000 		  |

#### CM33 sample program invocation with cold boot support
1. Follow **3. Preparing the SD Card**, **4.1 Preparation of Hardware and Software**, **4.2 Startup Procedure**, and **4.3 Download Flash Writer to RAM** of [SMARC EVK of RZ/G3S Linux Start-up Guide](https://www.renesas.com/en/document/gde/smarc-evk-rzg3s-linux-start-guide-rev106?queryID=b43f812bac9bf1c0c633e68a3c6ea99e) to invoke Flash Writer.
2. Change the transfer rate of Flash Writer from the default one `115200bps` to the high speed one `921600bps` as shown below:
	
    ```
	> sup
	Scif speed UP
	Please change to 921.6Kbps baud rate setting of the terminal.
    ```

3. Program `bl2_no_bp_spi-smarc-rzg3s.srec` with Flash Writer as shown below:
	```
	> XLS2
	===== Qspi writing of RZ/G3 Board Command =============
	Load Program to Spiflash
	Writes to any of SPI address.
	Program size & Qspi Save Address
	===== Please Input Program Top Address ============
	Please Input : H'a1e00
	===== Please Input Qspi Save Address ===
	Please Input : H'200000
	Please send ! ('.' & CR stop load)
	```
    Send the data of `bl2_no_bp_spi-smarc-rzg3s.srec` from terminal software after the message `please send !` is shown. After successfully downloading the binary, please enter `y`.

4. Program `fip-smarc-rzg3s.srec` with Flash Writer as shown below:

	```
	> XLS2
	===== Qspi writing of RZ/G3 Board Command =============
	Load Program to Spiflash
	Writes to any of SPI address.
	Program size & Qspi Save Address
	===== Please Input Program Top Address ============
	Please Input : H'0
	===== Please Input Qspi Save Address ===
	Please Input : H'260000
	Please send ! ('.' & CR stop load)
	```
    Send the data of `fip-smarc-rzg3s.srec` from terminal software after the message `please send !` is shown. After successfully downloading the binary, please enter `y`.
5. After writing two loader files normally, change the serial communication protocol speed from `921600` bps to `115200`. Finally, turn off the power of the board.

6. Refer to **4.2 CM33 Sample Program Setup** and follow the procedure including the item **Optional for CM33 cold boot support** of [Quick Start Guide for RZ/G3S Multi-OS Package
](https://www.renesas.com/en/document/qsg/quick-start-guide-rzg3s-multi-os-package?queryID=7ab971994a78b67e7960deb0e56f081b). Do not follow the procedure **Optional for remoteproc support** at this time.

### CA55 sample program invocation
1. Boot up Linux by executing the following command on u-boot:
    ```
    => run bootcmd
    ```
2. Login as root.
    ```
    smarc-rzg3s login: root
    ```
3. Run CA55 sample program by executing the following command:
    ```
    root@smarc-rzg3s:~# rpmsg_sample_client
    ```
4. Then, you can see the following message on the console of Linux side.
	```
	******************************************
	* rpmsg communication sample program *
	******************************************
	1. communicate between CM33 cores 
	2. communicate between CM33 and CA55
	e. exit
	please input
	>
	```
5. Input the number which performs the communication you would like to try on the console. Please note that 1 is allowable ONLY when remoteproc support is enabled. Also, you must NOT invoke the CM33 program in advance. Meanwhile, in case of selecting 1, you need to invoke the CM33 program in advance.

6. In case of typing 1, the communication between CM33 cores should be established and the communication log is repeatedly displayed via the Pmod USBUART. Also, when 2 is typed, you can see the following message on Linux console:
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
    proc_id:1 rsc_id:1 mbx_id:0
    Initialize remoteproc successfully.
    proc_id:0 rsc_id:0 mbx_id:1
    Initialize remoteproc successfully.
    proc_id:1 rsc_id:1 mbx_id:1
    Initialize remoteproc successfully.

    ******************************************
    *   rpmsg communication sample program   *
    ******************************************

    1. communicate with CM33 ch0
    2. communicate with CM33 ch1
    3. communicate with CM33_FPU ch0
    4. communicate with CM33_FPU ch1
    5. communicate with CM33 ch0 and CM33_FPU ch1

    e. exit

    please input
    >
    ```
7. Input the number which performs the communication between CM33 and CA55 you would like to try on the console

### Overview of sample program behavior
1. Wait until a communication channel between CA55 and CM33 is established.
2. Once the communication channel is established, CA55 sample program starts to send the message to CM33 by incrementing its size from the minimum value 17 to the maximum value 488. When sending the message, the following log should be shown on Linux console:
    ```
    Sending payload number 148 of size 165
    ```
3. When CM33 receives the message sent from CA55, the echo reply is sent back to CA55.
4. When CA55 receives the echo reply, the message below should be displayed in the console:
    ```
	received payload number 148 of size 165
    ```
5. After the message which has 488 bytes sized payload is sent from CA55 to CM33 and CM33 sends back the echo reply, the message for terminating the communication channel is sent from CA55 to CM33. Then, CA55 and CM33 sample programs output the following log messages to the corresponding consoles respectively when receiving the termination message.
- On CA55 side:

    ```
	************************************
	Test Results: Error count = 0
	************************************
	Quitting application .. Echo test end
	Stopping application...

	******************************************
	*   rpmsg communication sample program   *
	******************************************

	1. communicate with CM33 ch0
	2. communicate with CM33 ch1
	3. communicate with CM33_FPU ch0
	4. communicate with CM33_FPU ch1
	5. communicate with CM33 ch0 and CM33_FPU ch1

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