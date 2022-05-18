---
layout: post
title: "build linux for imx6"
date: 2015-04-16 19:26:06 +0800
comments: true
categories: linux imx6 ltib yocto qt qml
---

# 	1. 		Install Host OS #

##  1.1		Install VMware ##

    Version: VMware10.03

## 	1.2		Install ubuntu server on VMware ##

	Version: ubuntu-14.04.2-server-amd64

## 	1.3 	Update Sources ##

    $sudo apt-get update

# 	2.		Install Host OS Service #

##  2.1 	Install ssh service ##

    $ sudo apt-get install openssh-client openssh-server

## 	2.2		Install samba service ##

    $ sudo apt-get install samba
	
	$ sudo vim /etc/samba/smb.conf and add below section to the file end

	[home]
	comment = samba share path /home
	browseable = yes
	writeable = yes
	path = /home
	valid users = smb

	$ sudo useradd smb			//add user smb
	
	$ sudo smbpasswd -a smb		//set password for smb user

	$ /etc/init.d/smbd restart	//restart smbd service


# 	3.		Install Host OS build essential #

    $ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \
		build-essential chrpath socat libsdl1.2-dev xterm curl tcl rpm bison m4 \
		zlib1g zlib1g-dev libncurses5-dev liblzo2-dev uuid-dev lzop texi2html texinfo \
		texlive gettext libgtk2.0-dev rpm bison m4 libfreetype6-dev libdbus-glib-1-dev \
		liborbit2-dev intltool ccache libtool uuid-dev liblzo2-dev tcl dpkg asciidoc \
		texlive-latex-base dblatex xutils-dev texlive texinfo lib32z1 lib32ncurses5 \
		lib32bz2-1.0 libc6-dev-i386 u-boot-tools scrollkeeper dos2unix

# 	4.		Build image for imx6 using yocto#

## 	4.1		Install repo ##

    $ curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
 
	$ export PATH=$PATH:/home/vmuser/bin
	
	$ git config --global user.email "user name@email.com"
	
	$ git config --global user.name "User Name"	

##	4.2		Download freescale community bsp source code ##

    $ mkdir fsl-community-bsp
	$ cd fsl-community-bsp
	$ repo init -u https://github.com/Freescale/fsl-community-bsp-platform -b dora
	$ repo sync

## 	4.3 	Change branch and sync ##
	$ cd fsl-community-bsp
	$ repo init -b master	//master or other branch
	$ repo sync
	
## 	4.4		First build ##

### 4.4.1	Sync source code and setup environment ###

    $ cd fsl-community-bsp
	$ repo sync
	$ source setup-environment build
	$ ls
	conf
	
### 4.4.2	Choose your board ###

    $ cd fsl-community-bsp

	$ cd build

	$ vim conf/local.conf #you can change MACHINE

	MACHINE ??= 'imx6qsabresd'
	DISTRO ?= 'poky'
	PACKAGE_CLASSES ?= "package_rpm"
	EXTRA_IMAGE_FEATURES = "debug-tweaks"
	USER_CLASSES ?= "buildstats image-mklibs image-prelink"
	PATCHRESOLVE = "noop"
	BB_DISKMON_DIRS = "\
	    STOPTASKS,${TMPDIR},1G,100K \
	    STOPTASKS,${DL_DIR},1G,100K \
	    STOPTASKS,${SSTATE_DIR},1G,100K \
	    ABORT,${TMPDIR},100M,1K \
	    ABORT,${DL_DIR},100M,1K \
	    ABORT,${SSTATE_DIR},100M,1K"
	CONF_VERSION = "1"
	
	BB_NUMBER_THREADS = '1'
	PARALLEL_MAKE = '-j 1'
	
	DL_DIR ?= "${BSPDIR}/downloads/"
	ACCEPT_FSL_EULA = "1"


	//list all freescale boards conf
	$ ls ../sources/meta-fsl-arm/conf/machine/*.conf -l
		-rw-rw-r-- 1 vmuser vmuser  539 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx23evk.conf
		-rw-rw-r-- 1 vmuser vmuser 2440 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx28evk.conf
		-rw-rw-r-- 1 vmuser vmuser  667 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx31pdk.conf
		-rw-rw-r-- 1 vmuser vmuser  603 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx35pdk.conf
		-rw-rw-r-- 1 vmuser vmuser  333 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx51evk.conf
		-rw-rw-r-- 1 vmuser vmuser  469 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx53ard.conf
		-rw-rw-r-- 1 vmuser vmuser  460 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx53qsb.conf
		-rw-rw-r-- 1 vmuser vmuser  638 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx6dlsabreauto.conf
		-rw-rw-r-- 1 vmuser vmuser  393 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx6dlsabresd.conf
		-rw-rw-r-- 1 vmuser vmuser  533 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx6qsabreauto.conf
		-rw-rw-r-- 1 vmuser vmuser  432 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx6qsabresd.conf
		-rw-rw-r-- 1 vmuser vmuser  432 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx6slevk.conf
		-rw-rw-r-- 1 vmuser vmuser  615 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx6solosabreauto.conf
		-rw-rw-r-- 1 vmuser vmuser  468 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/imx6solosabresd.conf
		-rw-rw-r-- 1 vmuser vmuser  542 Apr 16 23:58 ../sources/meta-fsl-arm/conf/machine/twr-vf65gs10.conf
	
	//list all non-freescale boards conf
	$ ls ../sources/meta-fsl-arm-extra/conf/machine/*.conf -l
		-rw-rw-r-- 1 vmuser vmuser  155 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cfa10036.conf
		-rw-rw-r-- 1 vmuser vmuser  199 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cfa10037.conf
		-rw-rw-r-- 1 vmuser vmuser  234 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cfa10049.conf
		-rw-rw-r-- 1 vmuser vmuser  234 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cfa10055.conf
		-rw-rw-r-- 1 vmuser vmuser  229 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cfa10056.conf
		-rw-rw-r-- 1 vmuser vmuser  255 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cfa10057.conf
		-rw-rw-r-- 1 vmuser vmuser  255 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cfa10058.conf
		-rw-rw-r-- 1 vmuser vmuser  466 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/cgtqmx6.conf
		-rw-rw-r-- 1 vmuser vmuser  246 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/imx233-olinuxino-maxi.conf
		-rw-rw-r-- 1 vmuser vmuser  190 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/imx233-olinuxino-micro.conf
		-rw-rw-r-- 1 vmuser vmuser  188 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/imx233-olinuxino-mini.conf
		-rw-rw-r-- 1 vmuser vmuser  508 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/imx6qsabrelite.conf
		-rw-rw-r-- 1 vmuser vmuser  726 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/m28evk.conf
		-rw-rw-r-- 1 vmuser vmuser  767 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/m53evk.conf
		-rw-rw-r-- 1 vmuser vmuser 1641 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/nitrogen6x.conf
		-rw-rw-r-- 1 vmuser vmuser  786 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/nitrogen6x-lite.conf
		-rw-rw-r-- 1 vmuser vmuser  538 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/wandboard-dual.conf
		-rw-rw-r-- 1 vmuser vmuser  529 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/wandboard-quad.conf
		-rw-rw-r-- 1 vmuser vmuser  465 Apr 16 23:58 ../sources/meta-fsl-arm-extra/conf/machine/wandboard-solo.conf

	//list available images
	$ find ../sources -name *image*
		../sources/meta-fsl-arm/scripts/lib/image
		../sources/meta-fsl-arm/classes/mfgtool-initramfs-image.bbclass
		../sources/meta-fsl-arm/classes/image_types_fsl.bbclass
		../sources/meta-fsl-arm/recipes-fsl/images
		../sources/meta-fsl-arm/recipes-fsl/images/fsl-image-mfgtool-initramfs.bb
		../sources/poky/scripts/lib/image
		../sources/poky/scripts/lib/image/canned-wks/sdimage-bootpart.wks
		../sources/poky/scripts/lib/wic/plugins/imager
		../sources/poky/scripts/lib/wic/plugins/source/fsimage.py
		../sources/poky/scripts/lib/wic/imager
		../sources/poky/scripts/lib/wic/imager/baseimager.py
		../sources/poky/scripts/test-remote-image
		../sources/poky/scripts/contrib/ddimage
		../sources/poky/scripts/runqemu-addptable2image
		../sources/poky/documentation/ref-manual/ref-images.xml
		../sources/poky/documentation/ref-manual/figures/image-generation.png
		../sources/poky/documentation/ref-manual/figures/images.png
		../sources/poky/documentation/mega-manual/figures/image-generation.png
		../sources/poky/documentation/mega-manual/figures/images.png
		../sources/poky/documentation/mega-manual/figures/using-a-pre-built-image.png
		../sources/poky/documentation/mega-manual/figures/building-an-image.png
		../sources/poky/documentation/yocto-project-qs/figures/using-a-pre-built-image.png
		../sources/poky/documentation/yocto-project-qs/figures/building-an-image.png
		../sources/poky/bitbake/bin/image-writer
		../sources/poky/bitbake/lib/toaster/orm/migrations/0005_auto__add_target_image_file__add_target_file__add_field_variablehistor.py
		../sources/poky/bitbake/lib/toaster/orm/migrations/0006_auto__add_field_target_image_size__add_field_target_license_manifest_p.py
		../sources/poky/bitbake/lib/toaster/toastergui/static/css/images
		../sources/poky/bitbake/lib/bb/ui/icons/images
		../sources/poky/bitbake/lib/bb/ui/icons/images/images_hover.png
		../sources/poky/bitbake/lib/bb/ui/icons/images/images_display.png
		../sources/poky/bitbake/lib/bb/ui/crumbs/imagedetailspage.py
		../sources/poky/bitbake/lib/bb/ui/crumbs/imageconfigurationpage.py
		../sources/poky/bitbake/lib/bb/ui/crumbs/hig/saveimagedialog.py
		../sources/poky/bitbake/lib/bb/ui/crumbs/hig/retrieveimagedialog.py
		../sources/poky/bitbake/lib/bb/ui/crumbs/hig/imageselectiondialog.py
		../sources/poky/bitbake/lib/bb/ui/crumbs/hig/deployimagedialog.py
		../sources/poky/meta-selftest/recipes-test/images
		../sources/poky/meta-selftest/recipes-test/images/oe-selftest-image.bb
		../sources/poky/meta/recipes-extended/images
		../sources/poky/meta/recipes-extended/images/core-image-lsb-sdk.bb
		../sources/poky/meta/recipes-extended/images/core-image-full-cmdline.bb
		../sources/poky/meta/recipes-extended/images/core-image-kernel-dev.bb
		../sources/poky/meta/recipes-extended/images/core-image-lsb.bb
		../sources/poky/meta/recipes-extended/images/core-image-testmaster.bb
		../sources/poky/meta/recipes-extended/images/core-image-lsb-dev.bb
		../sources/poky/meta/recipes-extended/images/core-image-testmaster-initramfs.bb
		../sources/poky/meta/recipes-multimedia/gstreamer/gst-ffmpeg-0.10.13/0001-avcodec-msrle-use-av_image_get_linesize-to-calculate.patch
		../sources/poky/meta/recipes-qt/images
		../sources/poky/meta/recipes-qt/images/qt4e-demo-image.bb
		../sources/poky/meta/recipes-qt/qt4/qt4-4.8.6/0028-Don-t-crash-on-broken-GIF-images.patch
		../sources/poky/meta/recipes-graphics/xorg-lib/xcb-util-image_0.4.0.bb
		../sources/poky/meta/recipes-graphics/images
		../sources/poky/meta/recipes-graphics/images/core-image-x11.bb
		../sources/poky/meta/recipes-graphics/images/core-image-directfb.bb
		../sources/poky/meta/recipes-graphics/images/core-image-weston.bb
		../sources/poky/meta/recipes-graphics/images/core-image-clutter.bb
		../sources/poky/meta/recipes-devtools/mkelfimage
		../sources/poky/meta/recipes-devtools/mkelfimage/mkelfimage
		../sources/poky/meta/recipes-devtools/mkelfimage/mkelfimage_git.bb
		../sources/poky/meta/recipes-core/images
		../sources/poky/meta/recipes-core/images/core-image-minimal.bb
		../sources/poky/meta/recipes-core/images/core-image-base.bb
		../sources/poky/meta/recipes-core/images/build-appliance-image_12.0.1.bb
		../sources/poky/meta/recipes-core/images/build-appliance-image
		../sources/poky/meta/recipes-core/images/core-image-minimal-mtdutils.bb
		../sources/poky/meta/recipes-core/images/core-image-minimal-dev.bb
		../sources/poky/meta/recipes-core/images/core-image-minimal-initramfs.bb
		../sources/poky/meta/classes/image-buildinfo.bbclass
		../sources/poky/meta/classes/testimage-auto.bbclass
		../sources/poky/meta/classes/testimage.bbclass
		../sources/poky/meta/classes/image_types_uboot.bbclass
		../sources/poky/meta/classes/image-vmdk.bbclass
		../sources/poky/meta/classes/core-image.bbclass
		../sources/poky/meta/classes/image.bbclass
		../sources/poky/meta/classes/image_types.bbclass
		../sources/poky/meta/classes/image-prelink.bbclass
		../sources/poky/meta/classes/image-swab.bbclass
		../sources/poky/meta/classes/image-live.bbclass
		../sources/poky/meta/classes/image-mklibs.bbclass
		../sources/poky/meta/lib/oe/image.py
		../sources/poky/meta/lib/oeqa/controllers/masterimage.py
		../sources/poky/meta/recipes-bsp/u-boot/u-boot-mkimage_2015.01.bb
		../sources/poky/meta/recipes-rt/images
		../sources/poky/meta/recipes-rt/images/core-image-rt.bb
		../sources/poky/meta/recipes-rt/images/core-image-rt-sdk.bb
		../sources/poky/meta/recipes-connectivity/connman/connman-gnome/images
		../sources/poky/meta/recipes-sato/images
		../sources/poky/meta/recipes-sato/images/core-image-sato.bb
		../sources/poky/meta/recipes-sato/images/core-image-sato-dev.bb
		../sources/poky/meta/recipes-sato/images/core-image-sato-sdk.bb
		../sources/poky/meta-skeleton/recipes-multilib/images
		../sources/poky/meta-skeleton/recipes-multilib/images/core-image-multilib-example.bb
		../sources/meta-openembedded/meta-oe/recipes-multimedia/libsdl-image
		../sources/meta-openembedded/meta-oe/recipes-multimedia/libsdl-image/libsdl-image
		../sources/meta-openembedded/meta-oe/recipes-multimedia/libsdl-image/libsdl-image_1.2.12.bb
		../sources/meta-openembedded/meta-oe/recipes-graphics/lxdm/lxdm/0001-lxdm.conf.in-blacklist-root-for-release-images.patch
		../sources/meta-openembedded/meta-oe/recipes-graphics/nonworking/slim/slim/0002-Fix-image-handling-integer-overflows.patch
		../sources/meta-openembedded/meta-oe/recipes-support/imagemagick
		../sources/meta-openembedded/meta-oe/recipes-support/imagemagick/imagemagick_6.8.9.bb
		../sources/meta-openembedded/meta-initramfs/recipes-bsp/images
		../sources/meta-openembedded/meta-initramfs/recipes-bsp/images/initramfs-kexecboot-klibc-image.bb
		../sources/meta-openembedded/meta-initramfs/recipes-bsp/images/initramfs-debug-image.bb
		../sources/meta-openembedded/meta-initramfs/recipes-bsp/images/initramfs-kexecboot-image.bb
		../sources/Documentation/release-notes/source/images.inc
		../sources/Documentation/user-guide/source/images.rst
		../sources/Documentation/user-guide/source/image-list.inc
		../sources/meta-fsl-demos/recipes-qt/images
		../sources/meta-fsl-demos/recipes-qt/images/qt-in-use-image.bb
		../sources/meta-fsl-demos/recipes-qt/images/qte-in-use-image.bb
		../sources/meta-fsl-demos/recipes-fsl/images
		../sources/meta-fsl-demos/recipes-fsl/images/fsl-image-machine-test.bb
		../sources/meta-fsl-demos/recipes-fsl/images/fsl-image-multimedia-full.bb
		../sources/meta-fsl-demos/recipes-fsl/images/fsl-image-multimedia.bb

### 4.4.3	Start to build ###
	//list core-image-base all task	
	$ bitbake -c listtasks core-image-base

	// download all source only	
	$ bitbake -c fetchall core-image-base
	
	//build
	$ bitbake core-image-base




# 	5.		Build image for imx6 using ltib #

## 	5.1 	Get imx6 bsp source from fresscale sit ##

    Version: L3.0.35_4.1.0_130816_source.gz
	$ cd ~/ltib_src
	$ tar xvf L3.0.35_4.1.0_130816_source.gz

## 	5.2 	Add user super privilege to visudo ##
	
    $sudo /usr/sbin/visudo

	#add below line for vmuser account super privilege
	vmuser ALL = NOPASSWD: /usr/bin/rpm, /opt/freescale/ltib/usr/bin/rpm

## 	5.3 	Install LTIB ##
    $ cd ~/ltib_src
	$ ./L3.0.35_4.1.0_130816_source/install

	......
	Installation complete, your ltib installation has been placed in 
	/home/vmuser/ltib_src/ltib, to complete the installation:
	
	cd /home/vmuser/ltib_src/ltib
	./ltib

## 	5.4		Apply ltib ubuntu patch ##

### 5.4.1	Add librt.so link ###
    $ sudo ln -s /usr/lib/x86_64-linux-gnu/librt.so   /usr/lib/librt.so


### 5.4.2	Apply 0001_make_L3.0.35_4.1.0_compile_on_Ubuntu_14.04_64bit_OS.patch ###

    $ cd /home/vmuser/ltib_src/ltib
	$ wget https://community.freescale.com/servlet/JiveServlet/download/100725-3-274381/0001_make_L3.0.35_4.1.0_compile_on_Ubuntu_14.04_64bit_OS.patch.zip
	$ unzip 0001_make_L3.0.35_4.1.0_compile_on_Ubuntu_14.04_64bit_OS.patch.zip
	$ git apply 0001_make_L3.0.35_4.1.0_compile_on_Ubuntu_14.04_64bit_OS.patch

	

## 	5.5		Fist build LTIB for imx6q-sdb ##
	
	$ cd /home/vmuser/ltib_src/ltib

	$ ./ltib -m config

	Platform choice (Freescale iMX reference boards)  --->


	Choose the platform type
	Selection (imx6q)  --->


	Choose the packages profile
	Selection (use packages in preconfig (Min profile))  --->


	(imx6q) Platform
	--- LTIB settings
		 System features  --->
	--- Choose the target C library type
		Target C library type (glibc)  --->
		C library package (from toolchain only)  --->
		Toolchain component options  --->
	--- Toolchain selection.
		Toolchain (ARM, gcc-4.6.2, multilib, neon optimized, gnueabi/eglibc2.13)  --->
	(-O2 -march=armv7-a -mfpu=vfpv3 -mfloat-abi=softfp) Enter any CFLAGS for gcc/g++ (NEW)
	--- Choose your bootloader for U-Boot
		bootloader (u-boot)  --->
		u-boot version (u-boot v2009.08)  --->
	--- Choose your board for u-boot
		board (mx6q_sabresd)  --->
	--- Choose your Kernel
		kernel (Linux 3.0.35-imx)  --->
	[ ] Always rebuild the kernel
	[ ] Produce cscope index
	--- Include kernel headers
	[*] Configure the kernel

	...
	
	--- Package selection 
		Package list  --->
	--- Target System Configuration
		Options  --->
	--- Target Image Generation
		Options  --->
	---
	Load an Alternate Configuration File
	Save Configuration to an Alternate File

	
	--- Platform specific package selection
	
	[*] gpu-viv-bin-mx6q

	[*] dbus

	[*] expat

	[*] libjpeg

	[*] libpng

	
	$ ./ltib

	$ config kernel 

	Device Driver --->
	MXC support drivers --->
	        MXC Vivante GPU Support --->
		<*> MXC vivante GPU support

	
## 	5.6		Build IMX6 GPU SDK ##

    $ tar -xzvf gpu_sdk_v1.00.tar.gz -C ./gpu_sdk_v1.00
	$ cd gpu_sdk_v1.00

### 5.6.1	Build DevIL lib ###
	
	$ cd gpu_sdk_v1.00
	$ cp Demos/MultiAPI/GIFT/resources/required_libs/DevIL/DevIL-1.7.8.tar.gz  /opt/freescale/pkgs/
	$ cp Demos/MultiAPI/GIFT/resources/required_libs/DevIL/DevIL-1.7.8.tar.gz.md5  /opt/freescale/pkgs/
	$ mkdir /home/vmuser/ltib_src/ltib/dist/lfs-5.1/devil
	$ cp Demos/MultiAPI/GIFT/resources/required_libs/DevIL/DevIL-1.7.8.spec /home/vmuser/ltib_src/ltib/dist/lfs-5.1/devil/
	$ 
	$ cd /home/vmuser/ltib_src/ltib/
	$ dos2unix dist/lfs-5.1/devil/DevIL-1.7.8.spec
	$ ./ltib -m prep -p DevIL-1.7.8.spec
    $ ./ltib -m scbuild -p DevIL-1.7.8.spec
    $ ./ltib -m scdeploy -p DevIL-1.7.8.spec

###	5.6.2	Build assimp-2.0.863-sdk ###

	$ cd /home/vmuser/project/gpu_sdk/gpu_sdk_v1.00/Demos/MultiAPI/GIFT/resources/required_libs/assimp-2.0.863
	$ tar -xzvf assimp-2.0.863-sdk.tar.gz -C ./assimp-2.0.863-sdk
	$ cd assimp-2.0.863-sdk
	$ cd imx6
	$ edit imx6_toolchain as below
	
	# this one is important
	SET(CMAKE_SYSTEM_NAME Linux)
	#this one not so much
	SET(CMAKE_SYSTEM_VERSION 1)
	
	# specify the cross compiler
	SET(CMAKE_C_COMPILER   /opt/freescale/usr/local/gcc-4.6.2-glibc-2.13-linaro-multilib-2011.12/fsl-linaro-toolchain/bin/arm-fsl-linux-gnueabi-gcc)
	SET(CMAKE_CXX_COMPILER /opt/freescale/usr/local/gcc-4.6.2-glibc-2.13-linaro-multilib-2011.12/fsl-linaro-toolchain/bin/arm-fsl-linux-gnueabi-g++)
	
	# where is the target environment 
	SET(CMAKE_FIND_ROOT_PATH  /home/vmuser/ltib_src/ltib/rootfs)
	
	# search for programs in the build host directories
	SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	# for libraries and headers in the target directories
	SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

	$ cmake -DCMAKE_TOOLCHAIN_FILE=./imx6_toolchain -DENABLE_BOOST_WORKAROUND=ON ..
	$ make


	$ ls code/ -alh
	total 9.9M
	drwxrwxr-x 3 vmuser vmuser 4.0K Apr 20 19:24 .
	drwxr-xr-x 5 vmuser vmuser 4.0K Apr 20 18:50 ..
	drwxrwxr-x 3 vmuser vmuser 4.0K Apr 20 18:50 CMakeFiles
	-rw-rw-r-- 1 vmuser vmuser  12K Apr 20 18:50 cmake_install.cmake
	lrwxrwxrwx 1 vmuser vmuser   14 Apr 20 19:24 libassimp.so -> libassimp.so.2
	lrwxrwxrwx 1 vmuser vmuser   18 Apr 20 19:24 libassimp.so.2 -> libassimp.so.2.0.0
	-rwxrwxr-x 1 vmuser vmuser 9.7M Apr 20 19:24 libassimp.so.2.0.0
	-rw-rw-r-- 1 vmuser vmuser 143K Apr 20 18:50 Makefile

	$ ls ../include/ -alh
	total 440K
	drwxr-xr-x  3 vmuser vmuser 4.0K Apr 20 18:34 .
	drwxrwxr-x 13 vmuser vmuser 4.0K Apr 20 18:34 ..
	-rw-r--r--  1 vmuser vmuser  15K Nov 22  2010 aiAnim.h
	-rw-r--r--  1 vmuser vmuser  701 Nov 22  2010 aiAssert.h
	-rw-r--r--  1 vmuser vmuser 7.3K Nov 22  2010 aiCamera.h
	-rw-r--r--  1 vmuser vmuser 3.5K Nov 22  2010 aiColor4D.h
	-rw-r--r--  1 vmuser vmuser 6.9K Nov 22  2010 aiColor4D.inl
	-rw-r--r--  1 vmuser vmuser  27K Nov 22  2010 aiConfig.h
	-rw-r--r--  1 vmuser vmuser 9.8K Nov  2  2011 aiDefines.h
	-rw-r--r--  1 vmuser vmuser 4.5K Nov 22  2010 aiFileIO.h
	-rw-r--r--  1 vmuser vmuser 7.8K Nov 22  2010 aiLight.h
	-rw-r--r--  1 vmuser vmuser  48K Nov 22  2010 aiMaterial.h
	-rw-r--r--  1 vmuser vmuser 6.1K Nov 22  2010 aiMaterial.inl
	-rw-r--r--  1 vmuser vmuser 5.7K Nov 22  2010 aiMatrix3x3.h
	-rw-r--r--  1 vmuser vmuser 7.7K Nov 22  2010 aiMatrix3x3.inl
	-rw-r--r--  1 vmuser vmuser 8.7K Nov 22  2010 aiMatrix4x4.h
	-rw-r--r--  1 vmuser vmuser  15K Nov 22  2010 aiMatrix4x4.inl
	-rw-r--r--  1 vmuser vmuser  24K Nov 22  2010 aiMesh.h
	-rw-r--r--  1 vmuser vmuser  28K Nov 22  2010 aiPostProcess.h
	-rw-r--r--  1 vmuser vmuser  11K Nov 22  2010 aiQuaternion.h
	-rw-r--r--  1 vmuser vmuser  14K Nov 22  2010 aiScene.h
	-rw-r--r--  1 vmuser vmuser 6.4K Nov 22  2010 aiTexture.h
	-rw-r--r--  1 vmuser vmuser  15K Nov 22  2010 aiTypes.h
	-rw-r--r--  1 vmuser vmuser 5.5K Nov 22  2010 aiVector2D.h
	-rw-r--r--  1 vmuser vmuser 4.0K Nov 22  2010 aiVector3D.h
	-rw-r--r--  1 vmuser vmuser 8.6K Nov 22  2010 aiVector3D.inl
	-rw-r--r--  1 vmuser vmuser 4.1K Nov 22  2010 aiVersion.h
	-rw-r--r--  1 vmuser vmuser  19K Nov 22  2010 assimp.h
	-rw-r--r--  1 vmuser vmuser  27K Nov 22  2010 assimp.hpp
	drwxr-xr-x  2 vmuser vmuser 4.0K Apr 20 18:34 Compiler
	-rw-r--r--  1 vmuser vmuser 7.5K Nov 22  2010 DefaultLogger.h
	-rw-r--r--  1 vmuser vmuser 4.8K Nov 22  2010 IOStream.h
	-rw-r--r--  1 vmuser vmuser 8.0K Nov 22  2010 IOSystem.h
	-rw-r--r--  1 vmuser vmuser 8.9K Nov 22  2010 Logger.h
	-rw-r--r--  1 vmuser vmuser 3.8K Nov 22  2010 LogStream.h
	-rw-r--r--  1 vmuser vmuser 3.3K Nov 22  2010 NullLogger.h
	-rw-r--r--  1 vmuser vmuser 3.7K Nov 22  2010 ProgressHandler.h

	$ copy *.so to  /home/vmuser/ltib_src/ltib/usr/lib

	$ copy *.h to   /home/vmuser/ltib_src/ltib/usr/include/ASSIMP
	
	$ ced /home/vmuser/ltib_src/ltib/usr/lib
	$ sudo ln -s libassimp.so.2.0.0 libassimp.so.2
	$ sudo ln -s libassimp.so.2 libassimp.so
	$ ls libassimp.so* -alh
	lrwxrwxrwx 1 root root   14 Apr 20 19:51 libassimp.so -> libassimp.so.2
	lrwxrwxrwx 1 root root   18 Apr 20 19:51 libassimp.so.2 -> libassimp.so.2.0.0
	-rwxr-xr-x 1 root root 9.7M Apr 20 19:49 libassimp.so.2.0.0

### 5.6.3	Build GIFT ###
    $ tar -xzvf GIFT_v4.tar.gz -C ./GIFT_v4
	$ cd GIFT_v4

	$ edit Makefile as below
	
	#----------------- development environment here
	#important so we know where the libraries are
	LTIB_ROOTFS=/home/vmuser/ltib_src/ltib/rootfs
	LTIB_SRC=/home/vmuser/ltib_src/ltib/rpm/BUILD/linux
	
	#set CROSS_COMPILE as below
	CROSS_COMPILE = /opt/freescale/usr/local/gcc-4.6.2-glibc-2.13-linaro-multilib-2011.12/fsl-linaro-toolchain/bin/arm-fsl-linux-gnueabi-
	
	#extra headers
	EXTRA_INC =  $(LTIB_SRC)/include
	
	#system headers
	FSL_PLATFORM_INC = $(LTIB_ROOTFS)/usr/include
	
	#extra libraries
	EXTRA_LIB = 
	
	#system libraries
	FSL_PLATFORM_LIB = $(LTIB_ROOTFS)/usr/lib
	
	#random needed vars
	ARCH = arm
	CD = cd
	DEL_FILE = rm -f
	MKDIR = mkdir -p
	RMDIR = rmdir
	CC = $(CROSS_COMPILE)g++
	AR = $(CROSS_COMPILE)ar
	LD = $(CROSS_COMPILE)g++
	CP = cp
	MAKE = make
	
	#CFLAGS = -DDEBUG -D_DEBUG -D_GNU_SOURCE -mfloat-abi=softfp -mfpu=neon -fPIC -O3 -fno-strict-aliasing -fno-optimize-sibling-calls -Wall -g
	
	CFLAGS = -DLINUX -DEGL_API_FB -mfloat-abi=softfp -mfpu=vfpv3 -fPIC -fno-strict-aliasing -fno-optimize-sibling-calls -O2 -march=armv7-a -mapcs-frame -fPIC -Wall -W -Wno-unused-parameter
	
	CFLAGS += -I$(FSL_PLATFORM_INC) -I$(EXTRA_INC)
	
	LFLAGS = -Wl,--library-path=$(FSL_PLATFORM_LIB),-rpath-link=$(FSL_PLATFORM_LIB) -ldl
	
	EGL_FLAGS = -lEGL
	
	ES11_FLAGS = -lGLESv1_CM
	
	ES20_FLAGS = -lGLESv2 
	
	VG11_FLAGS = -lOpenVG
	
	ASSIMP_FLAGS = -lassimp
	
	DEVIL_FLAGS = -lIL
	
	#-----------------for each app here
	
	APPNAME			= gift
	DESTDIR			= ./bin
	SRCDIR			= .
	
	#LFLAGS                  += $(EGL_FLAGS) $(ES20_FLAGS) -lm
	LFLAGS			+= $(EGL_FLAGS) $(ES20_FLAGS) $(ASSIMP_FLAGS) $(DEVIL_FLAGS) -lm
	
	OBJECTS			= GIFT.o obj3d.o TouchScreen.o SceneManager.o fslutil.o
	
	first: all
	
	all: $(APPNAME)
	
	.PHONY: all
	
	$(APPNAME): $(OBJECTS) 
		-@$(MKDIR) $(DESTDIR)
		$(LD) $(LFLAGS) -o $(DESTDIR)/$(APPNAME) $(OBJECTS)
	
	%.o : %.cpp
		$(CC) $(CFLAGS) -c $< -o $@
	
	clean:
		$(DEL_FILE) $(OBJECTS) $(UTILOBJS)
		$(DEL_FILE) *~ core *.core
	
	distclean: clean
		$(DEL_FILE) $(DESTDIR)/$(APPNAME)
		-@$(RMDIR) $(DESTDIR)
	

	$ edit fslutil.c as below
	
	...
	#include <EGL/egl.h>
	#include "fslutil.h" //#include <fslutil.h>
	#include <IL/il.h>
	...

	$ make clean
	$ make
	$ ls bin/ -alh
	total 60K
	drwxrwxr-x 2 vmuser vmuser 4.0K Apr 20 20:16 .
	drwxrwxr-x 4 vmuser vmuser 4.0K Apr 20 20:16 ..
	-rwxrwxr-x 1 vmuser vmuser  52K Apr 20 20:16 gift
	


# 	6	Build image for imx6 using buildroot #

## 	6.1	Get buildroot source code ##
    
	$ git clone http://git.buildroot.net/git/buildroot.git buildroot.git
	$ cd buildroot.git

## 	6.2	Build using freescale_imx6qsabresd_defconfig default config ##

	$ cd buildroot.git
	$ make freescale_imx6qsabresd_defconfig
	$ make

## 	6.3	Using eglibc ##

	$ make menuconfig

		Toolchain type (Buildroot toolchain)  --->
		(buildroot) custom toolchain vendor name

		*** Kernel Header Options ***
		Kernel Headers (Manually specified Linux version)  --->
		(3.10.17) linux version
		Custom kernel headers series (3.10.x)  --->

		C library (eglibc)  --->
		eglibc version (2.18-svnr23787)  ---> 
		
		......

	$ make

##	6.4	Change device node management to static ##
	
	$ cd buildroot.git
	$ add system/device_table_imx6.txt as below
		# See package/makedevs/README for details
		#
		# This device table is used to assign proper ownership and permissions
		# on various files. It doesn't create any device file, as it is used
		# in both static device configurations (where /dev/ is static) and in
		# dynamic configurations (where devtmpfs, mdev or udev are used).
		#
		# <name>				        <type>	<mode>	<uid>	<gid>	<major>	<minor>	<start>	<inc>	<count>
		/dev					        d	    755	    0	    0	    -	    -	    -	    -	    -
		/tmp					        d	    1777	0	    0	    -	    -	    -	    -	    -
		/etc					        d	    755	    0	    0	    -	    -	    -	    -	    -
		/root					        d	    700	    0	    0	    -	    -	    -	    -	    -
		#/var/www				        d	    755	    33	    33	    -	    -	    -	    -	    -
		/etc/random-seed		        f	    600	    0	    0	    -	    -	    -	    -	    -
		/etc/shadow				        f	    600	    0	    0	    -	    -	    -	    -	    -
		/etc/passwd				        f	    644	    0	    0	    -	    -	    -	    -	    -
		#/etc/network/if-up.d			d	    755	    0	    0	    -	    -	    -	    -	    -
		#/etc/network/if-pre-up.d		d	    755	    0	    0	    -	    -	    -	    -	    -
		#/etc/network/if-post-up.d		d	    755	    0	    0	    -	    -	    -	    -	    -
		#/etc/network/if-down.d			d	    755	    0	    0	    -	    -	    -	    -	    -
		#/etc/network/if-pre-down.d		d	    755	    0	    0	    -	    -	    -	    -	    -
		#/etc/network/if-post-down.d	    d	    755	    0	    0	    -	    -	    -	    -	    -
		
		# uncomment this to allow starting x as non-root
		#/usr/X11R6/bin/Xfbdev		    f	    4755	0	    0	    -	    -	    -	    -	    -

	$ add system/device_table_dev_imx6.txt as below
		# See package/makedevs/README for details
		#
		# This device table is used only to create device files when a static
		# device configuration is used (entries in /dev are static).
		#
		# <name>	        <type>	<mode>	<uid>	<gid>	<major>	<minor>	<start>	<inc>	<count>
		
		# Normal system devices
		/dev/null	        c	    666	    0	    0	    1	    3	    0	    0	    -
		/dev/console	    c	    666	    0	    0	    5	    1	    -	    -	    -
		/dev/ttymxc	        c	    666	    0	    0	    207	    16	    0	    1	    4

	$ make menuconfig

	 	(buildroot) System hostname
		(Welcome to Buildroot) System banner
			Passwords encoding (md5)  --->
			Init system (BusyBox)  --->
			/dev management (Static using device table)  --->
		(system/device_table_imx6.txt) Path to the permission tables
		(system/device_table_dev_imx6.txt) Path to the device tables
			Root FS skeleton (default target skeleton)  --->
		
		......
	
	$ make  

## 	6.5	Remove login prompt ##

	//todo it seems not work correctly
	$ cd buildroot.git
	$ make menuconfig
	
		......
	
		[ ] Run a getty (login prompt) after boot
	
		......
	
	$ make

	//try this method
	$ cd buildroot.git
	$ make busybox-menuconfig
		
		......
		
		[*] getty
		[ ] login                                                                                                                      
	 	[ ] Run logged in session in a child process

		......
		
	$ make

## 	6.6	Add gpu driver ##

	$ cd buildroot.git
	$ make menuconfig
	
		Target packages  --->
		
			Hardware handling  --->

				[*] Freescale i.MX libraries  --->

		--- Freescale i.MX libraries                                                                                          	
		i.MX platform (imx6q)  --->                                                                                     
		*** imx-lib needs an imx-specific Linux kernel to be built ***                                                  	
		*** imx-vpu needs an imx-specific Linux kernel to be built ***
		[ ]   firmware-imx (NEW)
		[*]   gpu-viv-bin-mx6q                                                                                                
		[*]     install examples 