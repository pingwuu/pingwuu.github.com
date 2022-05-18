---
layout: post
title: "using ltib's u-boot kernel and rootfs to boot board step by step"
date: 2015-05-14 14:47:48 +0800
comments: true
categories: ltib imx6
---

# 1. Config and build ltib for sabre sdb imx6q #

# 2. Get source code #
    $ cd path/ltib

    $ ./ltib -m prep -p u-boot
    
    $ cd path/ltib

    $ ./ltib -m prep -p kernel
    
    
# 3. Modify and build u-boot #

    $ cd path/ltib/rpm/BUILD/u-boot-2009.08
    
    $ modify inlcude/configs/mx6q_sabresd.h as below
    
    ////////////////////////////////////////////////////////////////////
    
	#if 0	//boot from nfs
	#define	CONFIG_EXTRA_ENV_SETTINGS					\
			"netdev=eth0\0"						\
			"ethprime=FEC0\0"					\
			"uboot=u-boot.bin\0"			\
			"kernel=uImage\0"				\
			"nfsroot=/opt/eldk/arm\0"				\
			"bootargs_base=setenv bootargs console=ttymxc0,115200\0"\
			"bootargs_nfs=setenv bootargs ${bootargs} root=/dev/nfs "\
				"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0"\
			"bootcmd_net=run bootargs_base bootargs_nfs; "		\
				"tftpboot ${loadaddr} ${kernel}; bootm\0"	\
			"bootargs_mmc=setenv bootargs ${bootargs} ip=dhcp "     \
				"root=/dev/mmcblk0p1 rootwait\0"                \
			"bootcmd_mmc=run bootargs_base bootargs_mmc; "   \
			"mmc dev 3; "	\
			"mmc read ${loadaddr} 0x800 0x2000; bootm\0"	\
			"bootcmd=run bootcmd_net\0"
	#endif
	
	#if 1	//boot from mmc and display on lvds1 to LDB-CLAA(1280x420)
	#define	CONFIG_EXTRA_ENV_SETTINGS					\
			"netdev=eth0\0"						\
			"ethprime=FEC0\0"					\
			"uboot=u-boot.bin\0"					\
			"kernel=uImage\0"					\
			"nfsroot=/opt/eldk/arm\0"				\
			"bootargs_base=setenv bootargs console=ttymxc0,115200 \0"\
			"bootargs_nfs=setenv bootargs ${bootargs} root=/dev/nfs "\
				"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0"\
			"bootcmd_net=run bootargs_base bootargs_nfs; "		\
				"tftpboot ${loadaddr} ${kernel}; bootm\0"	\
			"bootargs_mmc=setenv bootargs ${bootargs} "     \
				"root=/dev/mmcblk0p1 rootfstype=ext4 rootwait rw lpj=7905280 printk.time=1 verify=no" \
				" ldb=sin1 video=mxcfb0:dev=ldb,LDB-CLAA,if=RGB666,bpp=32 video=mxcfb1:off consoleblank=0 \0"\
			"bootcmd_mmc=run bootargs_base bootargs_mmc; "	\
			"mmc dev 3; "					\
			"mmc read ${loadaddr} 0x800 0x2000; bootm\0"	\
			"bootcmd=run bootcmd_mmc\0"
	#endif
	
	#if 0	//boot from mmc and display on twice lvds to LDB-1080P60(1920x720)
	#define	CONFIG_EXTRA_ENV_SETTINGS					\
			"netdev=eth0\0"						\
			"ethprime=FEC0\0"					\
			"uboot=u-boot.bin\0"			\
			"kernel=uImage\0"				\
			"nfsroot=/opt/eldk/arm\0"				\
			"bootargs_base=setenv bootargs console=ttymxc0,115200 \0"\
			"bootargs_nfs=setenv bootargs ${bootargs} root=/dev/nfs "\
				"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0"\
			"bootcmd_net=run bootargs_base bootargs_nfs; "		\
				"tftpboot ${loadaddr} ${kernel}; bootm\0"	\
			"bootargs_mmc=setenv bootargs ${bootargs} "     \
				"root=/dev/mmcblk0p1 rootfstype=ext4 rootwait rw lpj=7905280 printk.time=1 verify=no" \
				" ldb=spl0 video=mxcfb0:dev=ldb,LDB-1080P60,if=RGB24,bpp=32 video=mxcfb1:off consoleblank=0 \0"                \
			"bootcmd_mmc=run bootargs_base bootargs_mmc; "   \
			"mmc dev 3; "	\
			"mmc read ${loadaddr} 0x800 0x2000; bootm\0"	\
			"bootcmd=run bootcmd_mmc\0"
	#endif

    #if 0 //ltib default nfs boot
    #define	CONFIG_EXTRA_ENV_SETTINGS \
    		"netdev=eth0\0" \
    		"ethprime=FEC0\0" \
    		"uboot=u-boot.bin\0" \
    		"kernel=uImage\0" \
    		"nfsroot=/opt/eldk/arm\0" \
    		"bootargs_base=setenv bootargs console=ttymxc0,115200\0" \
    		"bootargs_nfs=setenv bootargs ${bootargs} root=/dev/nfs " \
    			"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0" \
    		"bootcmd_net=run bootargs_base bootargs_nfs; " \
    			"tftpboot ${loadaddr} ${kernel}; bootm\0" \
    		"bootargs_mmc=setenv bootargs ${bootargs} ip=dhcp " \
    			"root=/dev/mmcblk0p1 rootwait\0" \
    		"bootcmd_mmc=run bootargs_base bootargs_mmc; " \
    		"mmc dev 3; " \
    		"mmc read ${loadaddr} 0x800 0x2000; bootm\0"	\
    		"bootcmd=run bootcmd_net\0"                             \
    
    #else // for mmc boot

	#define	CONFIG_EXTRA_ENV_SETTINGS \
		"netdev=eth0\0" \
		"ethprime=FEC0\0" \
		"uboot=u-boot.bin\0" \
		"kernel=uImage\0" \
		"nfsroot=/opt/eldk/arm\0" \
		"bootargs_base=setenv bootargs console=ttymxc0,115200 \0" \
		"bootargs_nfs=setenv bootargs ${bootargs} root=/dev/nfs " \
			"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0" \
		"bootcmd_net=run bootargs_base bootargs_nfs; " \
			"tftpboot ${loadaddr} ${kernel}; bootm\0" \
		"bootargs_mmc=setenv bootargs ${bootargs} " \
			"root=/dev/mmcblk0p1 rootfstype=ext4 rootwait rw lpj=7905280 printk.time=1 verify=no" \
			" ldb=spl0 video=mxcfb0:dev=ldb,LDB-1080P60,if=RGB24,bpp=32 video=mxcfb1:off consoleblank=0 \0" \
		"bootcmd_mmc=run bootargs_base bootargs_mmc; " \
		"mmc dev 3; " \
		"mmc read ${loadaddr} 0x800 0x2000; bootm\0" \
		"bootcmd=run bootcmd_mmc\0" \
    
    #endif

    /////////////////////////////////////////////////////////////////////////
    
    $ export ARCH=arm
    $ export CROSS_COMPILE=/opt/gcc-linaro-arm-linux-gnueabi-2012.04-20120426_linux/bin/arm-linux-gnueabi-
    
    $ make mx6q_sabresd_config
    
    $ make
    
	////////////////////////////Note/////////////////////////////////
	
	uboot mmc read/write命令用法

	mmc read用来读取mmc内容到内存，
	
	mmc write用来写入内存内容到mmc中
	
	具体用法,
	
	mmc read <device num> addr blk# cnt [partition]
	
	mmc write <device num> addr blk# cnt [partition]
	
	mmc list
	
	device num是mmc的设备号，可以通过mmc list查询
	
	addr是内存地址
	
	blk# 是mmc内的块号
	
	cnt 块数目 ( 块大小为512Byte )
	
	使用范例：
	
	mmc write 2 0x90000000 0x600 0x10
	
	把内存0x90000000开始，长度为16x512大小的数据，写入到第2个mmc设备块偏移位置为0x600处
	
	mmc read 2 0x90000000 0x600 0x10

	把第二个mmc设备块偏移为0x600处开始，长度为16x512大小的数据，读出到内存0x90000000处
	///////////////////////////////////////////////
    
# 4. Modify and build kernel #
    
    $ cd path/ltib/rpm/BUILD/linux-3.0.35
    
    $ export ARCH=arm
    
    $ export CROSS_COMPILE=/opt/gcc-linaro-arm-linux-gnueabi-2012.04-20120426_linux/bin/arm-linux-gnueabi-
    
    $ make imx6_defconfig
    
    $ make uImage
    
# 5. Reduce rootfs #
    
    $ cd path/ltib/rootfs
    
    $ add post_build.sh
    ##########################################
    #!/bin/sh
    cd dev
    sudo mknod null c 1 3
    sudo chmod 666 null
    
    sudo mknod console c 5 1
    sudo chmod 777 console
    
    for i in 0 1 2 3 4 5 6 7 8 9 10 11 12; do sudo mknod fb$i c 29 $i; done
    
    sudo mknod mxc_ipu c 253 0
    sudo mknod mxc_vpu c 252 0
    sudo mknod ttymxc0 c 207 16
    sudo mknod video0 c 81 0
    sudo mknod galcore c 199 0
    
    cd ..
    sudo rm -rf unit_tests
    sudo rm -rf boot
    sudo rm -rf opt/fsl_samples
    sudo rm -rf opt/viv_samples
    sudo rm -rf share
    
    sudo rm -rf usr/include
    sudo rm -rf usr/info
    sudo rm -rf usr/man
    sudo rm -rf usr/src
    sudo rm -rf usr/share
    
    sudo rm -rf var/spool
    sudo rm -rf var/ftp
    sudo rm -rf var/log
    sudo rm -rf var/run
    sudo rm -rf var/mail
    sudo rm -rf var/lock
    sudo rm -rf var/lib
    sudo rm -rf var/www
    ###############################################
    
    $ ./post_build.sh
    
    $ sudo tar -cjvf ../rootfs.tar.bz2 ./*
    
# 6. Flash u-boot.bin, uImage and rootfs.tar.bz2 to board mmc #

# 7. Reset board. Done! #
