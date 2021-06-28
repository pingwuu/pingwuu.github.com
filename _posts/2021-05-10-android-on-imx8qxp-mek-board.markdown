---
layout: post
title:  "Android on i.MX8QXP MEK Board"
date:   2021-05-10 13:30:00 +0800
categories: android imx8
comments: true
---

# 1. Demo Images Download & Flash

## 1.1 Demo image download link

```
https://www.nxp.com/webapp/Download?colCode=Q10.0.0_2.6.0_DEMO_8Q&appType=license

https://cache.nxp.com.cn/secured/bsps/android-10.0.0_2.6.0_image_8qmek.tar.gz?__gda__=1620631783_8a6a9b514b438030fa75a2a92db3292b&fileExt=.gz
```

## 1.2 Flash Instruments

Table 12. Options for uuu_imx_android_flash tool

| Option           | Description                                                  |
| ---------------- | ------------------------------------------------------------ |
| -h               | Displays help information of this tool.                      |
| -f soc_name      | Specifes SoC information. For i.MX 8QuadXPlus MEK, it should be "imx8qxp". This option is mandatory. |
| -a               | Only flashes slot a. If this option and "-b" option are not used, slots a and b are both flahsed. |
| -b               | Only flashes slot b. If this option and "-a" option are not used, slots a and b are both flahsed. |
| -c card_size     | Specifies which partition table image file to flash. For i.MX 8QuadXPlus MEK, it can be followed with "28". If this option is not used, default "partition-table.img" is flashed. |
| -u uboot_feature | Flashes U-Boot or SPL&bootloader image with "uboot_feature" in their names. For i.MX 8QuadXPlus MEK, it can be "trusty", "trusty-secure-unlock", "c0", or "trusty-c0". If this option is not used, the default "u-boot-imx8qxp.imx" is flashed. |
| -e               | Erases user data after images are flashed.                   |
| -D directory     | Specifies the directory in which there are the images to be flashed. If this option is not used, images in current working directory will be flashed. |
| -t target_dev    | Specifes the target device. For i.MX 8QuadXPlus MEK, it can be "emmc" and "sd". If this option is not used, images are flashed to eMMC. |
| -daemon          | Runs UUU in daemon mode. This option is used to flash multiple boards of the same type. |
| -i               | If the script is executed with this option, no images are flashed. The script just loads U-Boot to RAM and executes to fastboot mode. This option is used for development. |
| -dryrun          | Only generates a UUU script but not executes UUU with this script. |
| -super           | "super.img" is not generated when flashing images. The one already exists together with other images is used. |

```
> .\uuu_imx_android_flash.bat -f imx8qxp -a -c 7 -u trusty -e -t emmc
```



//for B0 MEK

```
> .\uuu_imx_android_flash.bat -f imx8qxp -a -e -t emmc
```

//for B0 MEK w/o super.img

```
> .\uuu_imx_android_flash.bat -f imx8qxp -a -e -t emmc -super
```





//for cd569

```
> .\uuu_imx_android_flash.bat -f imx8qxp -a -u c0 -e -t emmc
```



# 2. Build android image for imx8qxp mek board

```
1) Get the proprietary tarball from nxp.com and setup build:
imx-android-10.0.0_2.6.0.tar.gz
https://www.nxp.com/webapp/Download?colCode=Q10.0.0_2.6.0_ANDROID_SOURCE&appType=license

2) unzip package
$: tar xvf imx-android-10.0.0_2.6.0.tar.gz

//sync repo
$: source ./imx-android-10.0.0_2.6.0/imx_android_setup.sh


3) download cross compiler for u-boot build
$ wget https://armkeil.blob.core.windows.net/developer/Files/downloads/gnu-a/8.3-2019.03/binrel/gcc-arm-8.3-2019.03-x86_64-aarch64-linux-gnu.tar.xz

export AARCH64_GCC_CROSS_COMPILE=/home/vmuser/projects/android/gcc-arm-8.3-2019.03-x86_64-aarch64-linux-gnu/bin/aarch64-linux-gnu-


$ source build/envsetup.sh
$ lunch mek_8q-userdebug

//build all android image (bootloader, kernel and android images)
$ ./imx-make.sh -j4 2>&1 | tee build-log.txt

//# Build U-Boot/kernel with imx-make.sh first, but not to build Android images.
$ ./imx-make.sh bootloader kernel -j4 2>&1 | tee build-log.txt
# Start the process of build Android images with "make" function.
$ make -j4 2>&1 | tee -a build-log.txt

//build boot image

./imx-make.sh bootimage -j4

or

$ ./imx-make.sh kernel -j4
$ make bootimage -j4


//dtbo image for the i.MX 8QuadMax/8QuadXPlus MEK board
$ ./imx-make.sh dtboimage -j4
```



//for cd569

```
$ export AARCH64_GCC_CROSS_COMPILE=/home/vmuser/projects/android/gcc-arm-8.3-2019.03-x86_64-aarch64-linux-gnu/bin/aarch64-linux-gnu-
$ source build/envsetup.sh
$ lunch cd569_8q-userdebug
//build all android image (bootloader, kernel and android images)
$ ./imx-make.sh -j4 2>&1 | tee build-log.txt

//build bootloader and kernel only
$ ./imx-make.sh bootloader kernel -j4

//build boot image
./imx-make.sh bootimage -j4

or

$ ./imx-make.sh kernel -j4
$ make bootimage -j4

//dtboimage
$ ./imx-make.sh dtboimage -j32 2>&1 | tee build-dtboimage-log-mek.txt
```





//kernel build error

```
TARGET_KERNEL_DEFCONFIG := imx_v8_defconfig
```

build log

```

Merging KERNEL config
rm -f /home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_OBJ/.config
device/fsl/common/tools/mergeconfig.sh vendor/nxp-opensource/kernel_imx /home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_bu                       ild/out/target/product/cd569_8q/obj/KERNEL_OBJ \
arm64 vendor/nxp-opensource/kernel_imx/arch/arm64/configs/imx_v8_defconfig
Using /home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/arch/arm64/configs/imx_v8_def                       config as base
make[1]: Entering directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx'
make[2]: Entering directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_                       OBJ'
  GEN     Makefile
scripts/kconfig/conf  --alldefconfig Kconfig
./.tmp.config.2beRvi0ghF:469:warning: symbol value 'm' invalid for RC_CORE
#
# configuration written to .config
#
make[2]: Leaving directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_O                       BJ'
make[1]: Leaving directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx'
Value requested for CONFIG_RC_CORE not in final .config
Requested value:  CONFIG_RC_CORE=m
Actual value:     # CONFIG_RC_CORE is not set

Value requested for CONFIG_RC_DECODERS not in final .config
Requested value:  CONFIG_RC_DECODERS=y
Actual value:

Value requested for CONFIG_IR_NEC_DECODER not in final .config
Requested value:  CONFIG_IR_NEC_DECODER=m
Actual value:

Value requested for CONFIG_IR_RC5_DECODER not in final .config
Requested value:  CONFIG_IR_RC5_DECODER=m
Actual value:

Value requested for CONFIG_IR_RC6_DECODER not in final .config
Requested value:  CONFIG_IR_RC6_DECODER=m
Actual value:

Value requested for CONFIG_IR_JVC_DECODER not in final .config
Requested value:  CONFIG_IR_JVC_DECODER=m
Actual value:

Value requested for CONFIG_IR_SONY_DECODER not in final .config
Requested value:  CONFIG_IR_SONY_DECODER=m
Actual value:

Value requested for CONFIG_IR_SANYO_DECODER not in final .config
Requested value:  CONFIG_IR_SANYO_DECODER=m
Actual value:

Value requested for CONFIG_IR_SHARP_DECODER not in final .config
Requested value:  CONFIG_IR_SHARP_DECODER=m
Actual value:

Value requested for CONFIG_IR_MCE_KBD_DECODER not in final .config
Requested value:  CONFIG_IR_MCE_KBD_DECODER=m
Actual value:

Value requested for CONFIG_IR_XMP_DECODER not in final .config
Requested value:  CONFIG_IR_XMP_DECODER=m
Actual value:

Value requested for CONFIG_IR_IMON_DECODER not in final .config
Requested value:  CONFIG_IR_IMON_DECODER=m
Actual value:

Value requested for CONFIG_IR_RCMM_DECODER not in final .config
Requested value:  CONFIG_IR_RCMM_DECODER=m
Actual value:

Value requested for CONFIG_RC_DEVICES not in final .config
Requested value:  CONFIG_RC_DEVICES=y
Actual value:

Value requested for CONFIG_IR_GPIO_CIR not in final .config
Requested value:  CONFIG_IR_GPIO_CIR=m
Actual value:

Building arm64 5.4 kernel ...
make[1]: Entering directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx'
make[2]: Entering directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_                       OBJ'
  GEN     Makefile
scripts/kconfig/conf  --syncconfig Kconfig
*
* Restart config...
*
*
* General architecture-dependent options
*
Kprobes (KPROBES) [N/y/?] n
Stack Protector buffer overflow detection (STACKPROTECTOR) [Y/n/?] y
  Strong Stack Protector (STACKPROTECTOR_STRONG) [Y/n/?] y
Clang Shadow Call Stack (SHADOW_CALL_STACK) [N/y/?] (NEW)
Error in reading or end of file.

Link-Time Optimization (LTO) (EXPERIMENTAL)
> 1. None (LTO_NONE)
choice[1]: 1
Use a virtually-mapped stack (VMAP_STACK) [Y/n/?] y
Perform full reference count validation at the expense of speed (REFCOUNT_FULL) [Y/?] y
Locking event counts collection (LOCK_EVENT_COUNTS) [N/y/?] n
*
* Memory initialization
*
Initialize kernel stack variables at function entry
> 1. no automatic initialization (weakest) (INIT_STACK_NONE)
  2. 0xAA-init everything on the stack (strongest) (INIT_STACK_ALL_PATTERN) (NEW)
  3. zero-init everything on the stack (strongest and safest) (INIT_STACK_ALL_ZERO) (NEW)
choice[1-3?]:
Error in reading or end of file.
Enable heap memory zeroing on allocation by default (INIT_ON_ALLOC_DEFAULT_ON) [N/y/?] n
Enable heap memory zeroing on free by default (INIT_ON_FREE_DEFAULT_ON) [N/y/?] n
make[2]: Leaving directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_O                       BJ'
make[1]: Leaving directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx'
make[1]: Entering directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx'
make[2]: Entering directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_                       OBJ'
  GEN     Makefile
  CALL    /home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/scripts/checksyscalls.sh
  CALL    /home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/scripts/atomic/check-atom                       ics.sh
  CHK     include/generated/compile.h
  GZIP    kernel/config_data.gz
  CC      kernel/configs.o
  AR      kernel/built-in.a
  CC      drivers/staging/fsl_qbman/qman_high.o
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/drivers/staging/fsl_qbman/qman_high                       .c:1159:26: error:
      value size does not match register size specified by the constraint and modifier [-Werror,-Wasm-operand-widths]
                             : [result] "=r" (res)
                                              ^
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/drivers/staging/fsl_qbman/qman_high                       .c:1158:21: note:
      use constraint modifier "w"
                asm volatile("and %[result], %[in1], %[in2]"
                                  ^~~~~~~~~
                                  %w[result]
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/drivers/staging/fsl_qbman/qman_high                       .c:1160:22: error:
      value size does not match register size specified by the constraint and modifier [-Werror,-Wasm-operand-widths]
                             : [in1] "r" (zero), [in2] "r" (*s64)
                                          ^
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/drivers/staging/fsl_qbman/qman_high                       .c:1158:32: note:
      use constraint modifier "w"
                asm volatile("and %[result], %[in1], %[in2]"
                                             ^~~~~~
                                             %w[in1]
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/drivers/staging/fsl_qbman/qman_high                       .c:1169:22: error:
      value size does not match register size specified by the constraint and modifier [-Werror,-Wasm-operand-widths]
                             : [in1] "r" (res), [in2] "r" (s64)
                                          ^
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/drivers/staging/fsl_qbman/qman_high                       .c:1167:32: note:
      use constraint modifier "w"
                asm volatile("add %[result], %[in1], %[in2]"
                                             ^~~~~~
                                             %w[in1]
3 errors generated.
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/scripts/Makefile.build:286: recipe                        for target 'drivers/staging/fsl_qbman/qman_high.o' failed
make[5]: *** [drivers/staging/fsl_qbman/qman_high.o] Error 1
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/scripts/Makefile.build:556: recipe                        for target 'drivers/staging/fsl_qbman' failed
make[4]: *** [drivers/staging/fsl_qbman] Error 2
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/scripts/Makefile.build:556: recipe                        for target 'drivers/staging' failed
make[3]: *** [drivers/staging] Error 2
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx/Makefile:1811: recipe for target 'd                       rivers' failed
make[2]: *** [drivers] Error 2
make[2]: Leaving directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_O                       BJ'
Makefile:179: recipe for target 'sub-make' failed
make[1]: *** [sub-make] Error 2
make[1]: Leaving directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/vendor/nxp-opensource/kernel_imx'
/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/device/fsl/common/build/kernel.mk:159: recipe for target '/home/vmus                       er/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_OBJ/arch/arm64/boot/Image' failed
make: *** [/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build/out/target/product/cd569_8q/obj/KERNEL_OBJ/arch/arm64/boo                       t/Image] Error 2
make: Leaving directory '/home/vmuser/projects/android/nxp-imx-android-10.0.0_2.6.0/android_build'

```





# 99. Reference URL

* 1) a
* 

