---
layout: post
title: "MFGTool Emmc mksdcard.sh"
date: 2015-05-14 19:07:18 +0800
comments: true
categories: imx6 freescale shell 
---

# MFGTool Emmc mksdcard.sh comment #

## 1.烧写脚本： ##

	<CMD state="Updater" type="push" body="send" file="mksdcard.sh.tar">Sending partition shell</CMD> 

	<CMD state="Updater" type="push" body="$ tar xf $FILE "> Partitioning...</CMD>
	
	<CMD state="Updater" type="push" body="$ sh mksdcard.sh /dev/mmcblk0"> Partitioning...</CMD> 

## 2 其中 ：$ sh mksdcard.sh /dev/mmcblk0 ##
	mksdcard.sh文件内容为：

	#######################################################################
	#!/bin/sh
	
	# partition size in MB
	BOOT_ROM_SIZE=10
	BOOT_SYSTEM_SIZE=100
	
	
	# call sfdisk to create partition table
	# destroy the partition table
	node=$1
	dd if=/dev/zero of=${node} bs=1024 count=1
	
	sfdisk --force -uM ${node} << EOF
	${BOOT_ROM_SIZE},${BOOT_SYSTEM_SIZE},83
	,,83
	EOF
	######################################################################

	#!/bin/sh
	#partition size in MB

	BOOT_ROM_SIZE=10       						#这里定义的是启动ROM 10MB
	ROOT_SYSTEM_SIZE=1024 						#这里定义的是系统大小 1024mb

	#call sfdisk to create partition table
	#destroy the partition table

	node=$1										#$1为命令行第一个传递的参数 在此为 /dev/mmcblk0
	dd if=/dev/zero of=${node} bs=1024 count=1	#将前导一个1024字节(1KB)大小的分区零0

	sfdisk--force -uM ${node} << EOF      		#SmartFdisk –uM表示以MB为单位生成报告  即： sfdisk --force -um  /dev/mmcblk0 <<EOF
	${BOOT_ROM_SIZE},${ROOT_SYSTEM_SIZE},0c 
	,,83
	EOF

	#(,,83) 将其他所有空间再分成一个区,，此处应该就是mmcblk0p2 其中 83是Linux分区标识 Uboot和kernel是直接使用dd写入mmcblk0中的，而分区则是使用sfdisk进行的，空出了uboot和kernel的位置，从起始地址10MB开始的

## 3. linux  sfdisk命令说明 ##
	sfdisk reads lines of the form

             <start> <size> <id>< bootable> <c,h,s> <c,h,s>

      where each line fills one partition descriptor.

