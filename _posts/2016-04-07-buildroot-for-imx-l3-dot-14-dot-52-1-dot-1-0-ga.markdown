---
layout: post
title: "Buildroot for imx L3.14.52_1.1.0_ga"
date: 2016-04-07 13:04:45 +0800
comments: true
categories: imx6 buildroot u-boot linux
---
# 1. Get Buildroot #

	$ git clone git://git.buildroot.net/buildroot.git buildroot (commit id: 986fa441e49cc180f77704699a6d2bb3627bf86a)
	
# 2. Edit config file for imx6qsabresd board #

	$ vim configs/freescale_imx6qsabresd_defconfig as below
	################################################################################################################
	# architecture
	BR2_arm=y
	BR2_BINFMT_ELF=y
	BR2_cortex_a9=y
	BR2_ARM_ENABLE_NEON=y
	BR2_ARM_ENABLE_VFP=y
	BR2_ARM_EABIHF=y
	BR2_ARM_FPU_VFPV3D16=y
	BR2_ARM_INSTRUCTIONS_ARM=y
	
	#toolchain
	BR2_TOOLCHAIN_EXTERNAL=y
	BR2_TOOLCHAIN_EXTERNAL_LINARO_ARM=y
	BR2_TOOLCHAIN_EXTERNAL_DOWNLOAD=y
	
	#Build Options
	BR2_DL_DIR="/opt/buildroot/dl"
	
	# patches
	BR2_GLOBAL_PATCH_DIR="board/freescale/imx6sabre/patches"
	
	# Linux headers same as kernel, a 3.14 series
	BR2_PACKAGE_HOST_LINUX_HEADERS_CUSTOM_3_14=y
	
	# system
	BR2_TARGET_GENERIC_GETTY_PORT="ttymxc0"
	
	# kernel
	BR2_LINUX_KERNEL=y
	BR2_LINUX_KERNEL_CUSTOM_GIT=y
	BR2_LINUX_KERNEL_CUSTOM_REPO_URL="git://git.freescale.com/imx/linux-2.6-imx.git"
	BR2_LINUX_KERNEL_CUSTOM_REPO_VERSION="rel_imx_3.14.52_1.1.0_ga"
	BR2_LINUX_KERNEL_DEFCONFIG="imx_v7"
	#BR2_LINUX_KERNEL_UIMAGE=y
	BR2_LINUX_KERNEL_ZIMAGE=y
	BR2_LINUX_KERNEL_UIMAGE_LOADADDR="0x10008000"
	BR2_LINUX_KERNEL_DTS_SUPPORT=y
	BR2_LINUX_KERNEL_INTREE_DTS_NAME="imx6q-sabresd"
	
	# filesystem
	#BR2_TARGET_ROOTFS_EXT2=y
	BR2_TARGET_ROOTFS_TAR=y
	BR2_TARGET_ROOTFS_TAR_BZIP2=y
	
	# bootloader
	BR2_TARGET_UBOOT=y
	BR2_TARGET_UBOOT_BOARDNAME="mx6qsabresd"
	BR2_TARGET_UBOOT_FORMAT_IMX=y
	BR2_TARGET_UBOOT_CUSTOM_GIT=y
	BR2_TARGET_UBOOT_CUSTOM_REPO_URL="git://git.freescale.com/imx/uboot-imx.git"
	BR2_TARGET_UBOOT_CUSTOM_REPO_VERSION="rel_imx_3.14.52_1.1.0_ga"
	################################################################################################################

# 3. Build image #
	$ make freescale_imx6qsabresd_defconfig
	$ make -j 8
	$ ls output/images/* -alh
	-rw-r--r-- 1 vmuser vmuser  42K Apr  7 13:46 output/images/imx6q-sabresd.dtb
	-rw-r--r-- 1 vmuser vmuser 8.3M Apr  7 13:46 output/images/rootfs.ext2
	-rw-r--r-- 1 vmuser vmuser 6.7M Apr  7 13:48 output/images/rootfs.tar
	-rw-r--r-- 1 vmuser vmuser 2.7M Apr  7 13:48 output/images/rootfs.tar.bz2
	-rw-r--r-- 1 vmuser vmuser 403K Apr  7 13:34 output/images/u-boot.imx
	-rw-r--r-- 1 vmuser vmuser 5.3M Apr  7 13:46 output/images/zImage
	
# 4. Config display as HMDI #
	1) Enter u-boot console
	2) 
	=> setenv mmcargs 'setenv bootargs console=${console},${baudrate} ${smp} root=${mmcroot} rootwait rw video=mxcfb0:dev=hdmi,1920x1080M@60,if=RGB24'
	=> saveenv

# 5. Config display as single LVDS #

# 6. Config display as dual LVDS #

