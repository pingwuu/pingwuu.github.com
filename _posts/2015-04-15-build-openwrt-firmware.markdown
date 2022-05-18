---
layout: post
title: "build openwrt firmware"
date: 2015-04-15 14:51:54 +0800
comments: true
categories: openwrt wrtnode u-boot linux
---

# 1. Hardware #

wrtnode board [http://cn.wrtnode.com/](http://cn.wrtnode.com/)

# 2. Backup firmware #
## 1) ssh to wrtnode board ##

    root@OpenWrt:/tmp# cat /proc/mtd
	dev:    size   erasesize  name
	mtd0: 00030000 00010000 "u-boot"
	mtd1: 00010000 00010000 "u-boot-env"
	mtd2: 00010000 00010000 "factory"
	mtd3: 00fb0000 00010000 "firmware"
	mtd4: 00e96447 00010000 "rootfs"
	mtd5: 00780000 00010000 "rootfs_data"

## 2) back up u-boot and factory partition to /tmp ##
	root@OpenWrt:/tmp# dd if=/dev/mtd0 of=/tmp/wrtnode_u-boot.backup
	root@OpenWrt:/tmp# dd if=/dev/mtd1 of=/tmp/wrtnode_u-boot-env.backup
	root@OpenWrt:/tmp# dd if=/dev/mtd2 of=/tmp/wrtnode_factory.backup
	root@OpenWrt:/tmp# cat /proc/mtd > wrtnode_mtd_info.txt

## 3) scp backup firmware to local pc ##
    $ scp root@192.168.8.1:/tmp/wrtnode_u-boot.backup .
	$ scp root@192.168.8.1:/tmp/wrtnode_u-boot-env.backup .
	$ scp root@192.168.8.1:/tmp/wrtnode_factory.backup .
	$ scp root@192.168.8.1:/tmp/wrtnode_mtd_info.txt .

# 3. Build u-boot #

# 4. Build kernel #

# 5. Build openwrt image #
