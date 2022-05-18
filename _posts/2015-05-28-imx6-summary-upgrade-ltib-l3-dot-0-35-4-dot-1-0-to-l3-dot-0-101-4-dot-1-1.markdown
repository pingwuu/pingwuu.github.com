---
layout: post
title: "imx6 summary upgrade ltib L3.0.35_4.1.0 to L3.0.101_4.1.1"
date: 2015-05-28 10:50:25 +0800
comments: true
categories: imx6 ltib
---
# 1. Setup and build ltib using bsp L3.0.35_4.1.0_130816 #

# 2. Download L3.0.101_4.1.1 package #
	Version: 
		L3.0.101_4.1.1_141016_source.gz
		IMX_MMCODEC_3.0.101_4.1.1_Bundle.gz
# 3. Upgrade to L3.0.101_4.1.1 #

## 3.1 Copy the following packages to host /opt/freescale/pkgs ##
	firmware-imx-3.0.101-4.1.1.tar.gz
	imx-vpu-lib-3.0.101-4.1.1.tar.gz
	libfslcodec-3.0.11.tar.gz
	libfslparser-3.0.11.tar.gz
	libfslvpuwrap-1.0.46.tar.gz
	gst-fsl-plugins-3.0.11.tar.gz
	gst-fsl-plugins-3.0.11-configure.patch
	glib2-2.12.1-atomic.patch
	gpu-viv-bin-mx6q-3.0.101-4.1.1.tar.gz
	gpu-viv-bin-mx6s-3.0.101-4.1.1.tar.gz
	gpu-viv-wl-bin-mx6q-3.0.101-4.1.1.tar.gz
	gpu-viv-wl-bin-mx6s-3.0.101-4.1.1.tar.gz
	linux-3.0.101.tar.bz2 
	linux-3.0.101-imx_4.1.1.bz2
	u-boot-v2009.08-imx_3.0.101_4.1.1.tar.bz2

## 3.2 Patch ltib_config_platform_imx.patch ##
	$ cp ltib_config_platform_imx.patch Ltib_installed/config/platform/imx
	$ cd Ltib_installed/config/platform/imx
	$ patch -p1 –i ltib_config_platform_imx.patch

## 3.3 Patch ltib_dist_lfs-5.1.patch ##
	$ cp ltib_dist_lfs-5.1.patch Ltib_installed/dist
	$ cd Ltib_installed/dist
	$ patch -p1 –i ltib_dist_lfs-5.1.patch

# 4. Config and build ltib #
	$ cd Ltib_installed/
	$ ./ltib –config
	$ ./ltib

	$ ./ltib -m prep -p u-boot 	# fetch u-boot sourc code
	$ ./ltib -m prep -p kernel 	# fetch kernel souce code
 

Done!