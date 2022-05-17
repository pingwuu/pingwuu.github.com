---
layout: post
title:  "Buildroot on imx8 Dev Board"
date:   2019-12-01 16:55:00 +0800
categories: buildroot imx8 linux u-boot
comments: true
---

**Table of Content**

- [0. Building System OS](#0-building-system-os)
- [1. Update build Environment](#1-update-build-environment)
- [2.  Clone buildroot repo](#2--clone-buildroot-repo)
- [3. Build](#3-build)
- [3.1 Build for i.MX 8QuadXPlus MEK CPU Board](#31-build-for-imx-8quadxplus-mek-cpu-board)
- [4. Custom Build](#4-custom-build)
  * [4.1 Custom kernel](#41-custom-kernel)
- [4. Flash bin](#4-flash-bin)
- [4.1 Flash image to SD card](#41-flash-image-to-sd-card)
- [5. Run examples](#5-run-examples)
  * [5.1 Run Opengl example](#51-run-opengl-example)
  * [5.2 Run Qt example](#52-run-qt-example)
- [6. Build & Run ARM Linux on Qemu](#6-build---run-arm-linux-on-qemu)
  * [6.1 qemu arm versatile](#61-qemu-arm-versatile)
  * [6.2 Qemu arm imx6ul](#62-qemu-arm-imx6ul)
- [99. Reference URL](#99-reference-url)



# 0. Building System OS

```
Ubuntu 18.04.3 LTS
```

# 1. Update build Environment

```
$ sudo apt-get install git build-essential curl chrpath gawk texinfo libncurses5-dev
```

# 2.  Clone buildroot repo

```
$ git clone git://git.buildroot.net/buildroot

or

$ git clone https://git.buildroot.net/buildroot
```

# 3. Build

# 3.1 Build for i.MX 8QuadXPlus MEK CPU Board

```
$ cd buildroot

# Add ccache and download dir to config file 
$ cat configs/freescale_imx8qxpmek_defconfig 
BR2_CCACHE=y
BR2_CCACHE_DIR="/opt/buildroot/ccache"
BR2_DL_DIR="/opt/buildroot/dl"

BR2_aarch64=y
BR2_cortex_a35=y
BR2_ARM_FPU_VFPV3=y
......

$ make freescale_imx8qxpmek_defconfig
$ make

//Rebuild one package - make <package>-dirclean, such as:
$ make qt5base-dirclean
$ make

```

# 4. Custom Build

## 4.1 Custom kernel

```
//configure linux kernel
$ cd buildroot
$ make linux-menuconfig
$ make

```

//todo for imx7 qemu build & run

```
1. CONFIG_IMX_SDMA=y => n
2.
CONFIG_CFG80211=y		n
CONFIG_CFG80211_WEXT=y	n
```

# 4. Flash bin

# 4.1 Flash image to SD card

```
$ dd if=output/images/sdcard.img of=/dev/<your-sd-device>

########################################################
To determine the device associated to the SD card have a look in the
/proc/partitions file:
$ cat /proc/partitions
```

# 5. Run examples

## 5.1 Run Opengl example

//todo

## 5.2 Run Qt example

//todo

# 6. Build & Run ARM Linux on Qemu

## 6.1 qemu arm versatile

```
$ make qemu_arm_versatile_defconfig
$ make menuconfig
//Add OpenSSL libraries by navigating to Target packages -> Networking applications, and select openssh:

$ make 

//run with QEMU with this command line:

$ qemu-system-arm \
  -M versatilepb \
  -kernel output/images/zImage \
  -dtb output/images/versatile-pb.dtb \
  -drive file=output/images/rootfs.ext2,if=scsi,format=raw \
  -append "root=/dev/sda console=ttyAMA0,115200" \
  -serial stdio \
  -net nic,model=rtl8139 -net user \
  -redir tcp:2222::22 \
  -name Versatile_ARM_EXT2
```

## 6.2 Qemu arm imx6ul

```
$ cd buildroot
$ git checkout 2020.02.x
$ make imx6ulevk_defconfig
$ make j8
```

# 99. Reference URL

* [ Buildroot Making Embedded Linux Easy]( https://buildroot.org/ )

* [ https://boundarydevices.com/buildroot-2017-08-imx-platforms/ ]( https://boundarydevices.com/buildroot-2017-08-imx-platforms/ )

* [An ARM Image With Buildroot](https://dzone.com/articles/an-arm-image-with-buildroot)

* [Setup: Linux host, QEMU vm, arm64 kernel](https://github.com/google/syzkaller/blob/master/docs/linux/setup_linux-host_qemu-vm_arm64-kernel.md)

* [Compile Linux kernel 3.2 for ARM and emulate with QEMU](https://balau82.wordpress.com/2012/03/31/compile-linux-kernel-3-2-for-arm-and-emulate-with-qemu/)

* [SEALs - "Simple Embedded Arm Linux system"](https://github.com/kaiwan/seals/wiki/SEALs-HOWTO)

* [Part A. QEMU使用手册](http://wiki.100ask.org/Qemu)

* [buildroot使用介绍](https://www.cnblogs.com/arnoldlu/p/9553995.html)

* [SubjectRe: [PATCH v7 16/25] arm: Add support for generic vDSO (causing crash)](https://lkml.org/lkml/2019/12/4/648)

* [第六期 基于QEMU进行Linux内核模块实验 《虚拟机就是开发板》](https://blog.csdn.net/aggresss/article/details/54956686)

* [Virtual Development Board](https://elinux.org/Virtual_Development_Board)

  

