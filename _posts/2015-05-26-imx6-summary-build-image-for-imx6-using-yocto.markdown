---
layout: post
title: "Imx6 Summary Build Image for Imx6 Using Yocto"
date: 2015-05-26 17:07:56 +0800
comments: true
categories: imx6 yocto repo
---

# 1. Install repo #

    $ curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo

	or

	$ install a local repo (repo-local)
 
	$ export PATH=$PATH:/home/vmuser/bin
	
	$ git config --global user.email "user name@email.com"
	
	$ git config --global user.name "User Name"	

# 2. Download freescale community bsp source code #

    $ mkdir fsl-community-bsp
	$ cd fsl-community-bsp
	$ repo init -u https://github.com/Freescale/fsl-community-bsp-platform -b fido
	$ repo sync

# 3. Change branch and sync ##
	$ cd fsl-community-bsp
	$ repo init -b master	//master or other branch
	$ repo sync
	
# 4. First build #

## 4.1 Sync source code and setup environment ##

    $ cd fsl-community-bsp
	$ repo sync
	$ source setup-environment build
	$ ls
	conf
	
## 4.2 Choose your board ##

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

## 4.3 Start to build ##
	//list core-image-base all task	
	$ bitbake -c listtasks core-image-base

	// download all source only	
	$ bitbake -c fetchall core-image-base
	
	//build
	$ bitbake core-image-base
