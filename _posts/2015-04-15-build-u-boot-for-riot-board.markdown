---
layout: post
title: "build u-boot for riot board"
date: 2015-04-15 14:52:23 +0800
comments: true
categories: u-boot imx6 RIoT
---

## 1. Get u-boot source ##

    git clone https://github.com/Freescale/u-boot-fslc.git

## 2. make & build ##
	$cd u-boot-fslc
	$export ARCH=arm 
	$export CROSS_COMPILE=arm-linux-gnueabihf-
	$make riotboard_defconfig 
	$make
	$ls ls -l u-boot.*
	    -rw-rw-r-- 1 jordon jordon 331492 Dec  7 05:44 u-boot.bin
    	-rw-rw-r-- 1 jordon jordon 334848 Dec  7 05:44 u-boot.imx
    	-rw-rw-r-- 1 jordon jordon   1286 Dec  7 05:44 u-boot.lds
    	-rw-rw-r-- 1 jordon jordon 317244 Dec  7 05:44 u-boot.map
    	-rw-rw-r-- 1 jordon jordon 994618 Dec  7 05:44 u-boot.srec
