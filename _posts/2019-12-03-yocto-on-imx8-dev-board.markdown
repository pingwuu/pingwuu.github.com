---

layout: post
title:  "Yocto on i.MX8 Dev Board"
date:   2019-12-03 10:45:00 +0800
categories: yocto imx8 linux u-boot
comments: true
---

# 0. Building System OS

```
Ubuntu 16.04.6 LTS
```

# 1. Update build Environment

```
$ sudo apt-get install gawk wget git diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev libncurses5-dev

//Essentials: Packages needed to build an image on a headless system:
$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint3 xterm

//Documentation: Packages needed if you are going to build out the Yocto Project documentation manuals:
$ sudo apt-get install make xsltproc docbook-utils fop dblatex xmlto

$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev
$ sudo apt-get install libsdl1.2-dev xterm sed cvs subversion coreutils texi2html python-pysqlite2 help2man make gcc g++ desktop-file-utils libgl1-mesa-dev libglu1-mesa-dev mercurial autoconf automake groff curl lzop asciidoc u-boot-tools
```

# 2. Install repo

```
$ mkdir ~/bin
$ curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo

// Please using tsinghua as mirror if you can not access googleapis and add REPO_URL to you .bashrc file
$ curl https://mirrors.tuna.tsinghua.edu.cn/git/git-repo  > ~/bin/repo

$ export REPO_URL='https://mirrors.tuna.tsinghua.edu.cn/git/git-repo/'

$ chmod a+x ~/bin/repo

## Add the following line to the .bashrc file to ensure that the ~/bin folder is in your PATH variable
export PATH=~/bin:$PATH
```

# 3. Configure git

```
$ git config --global user.name "Your Name"
$ git config --global user.email you@example.com
```

# 4. Init repo manifest & build

## 4.1 Init & Build

Here using branch: imx-linux-sumo and manifext: imx-4.14.78-1.0.0_ga.xml as example

```
$ mkdir imx-yocto-bsp
$ cd imx-yocto-bsp

//Initialize repo manifest
$ repo init -u https://source.codeaurora.org/external/imx/imx-manifest -b imx-linux-sumo -m imx-4.14.78-1.0.0_ga.xml
$ repo sync -j4

//change branch & manifest
$ repo init -u https://source.codeaurora.org/external/imx/imx-manifest -b imx-linux-sumo -m imx-4.14.98-2.0.0_ga.xml

//change branch & manifest
$ repo init -u https://source.codeaurora.org/external/imx/imx-manifest -b imx-linux-sumo -m imx-4.14.98-2.3.1.xml

//Build configurations
$ DISTRO=fsl-imx-wayland MACHINE=imx8qxpmek source fsl-setup-release.sh -b build-wayland

//Enter build dir with env after firt congifurations
$ source setup-environment build-wayland/

//Local configuration tuning
A Yocto Project build can take considerable build resources both in time and disk usage, especially when building in multiple build directories. There are methods to optimize this, for example, use a shared sstate cache (caches the state of the build) and downloads directory (holds the downloaded packages). These can be set to be at any location in the local.conf file by adding statements such as these:

DL_DIR="/opt/yocto/downloads"
SSTATE_DIR="/opt/yocto/sstate-cache"

BB_NUMBER_THREADS = "8"
PARALLEL_MAKE = "-j 8"

INHERIT += "rm_work"

// Building an imange
# A small image that only allows a device to boot
$ bitbake core-image-minimal

//Builds an i.MX image with a GUI without any Qt content
$ bitbake fsl-image-validation-imx

//Build SDK
$ bitbake fsl-image-validation-imx -c populate_sdk

# Build open source Qt5 image
$ bitbake fsl-image-qt5-validation-imx

//build SDK
$ bitbake fsl-image-qt5-validation-imx -c populate_sdk

//list core-image-base all task 
$ bitbake -c listtasks core-image-base

// download all source only 
$ bitbake -c fetchall core-image-base

//Install SDK
build-wayland/tmp/deploy/sdk$ ./fsl-imx-wayland-glibc-x86_64-fsl-image-qt5-validation-imx-aarch64-toolchain-4.14-sumo.sh

//Using sdk
$ source /opt/fsl-imx-wayland/4.14-sumo/environment-setup-aarch64-poky-linux
```

## 4.2 Change branch & manifest

```
//change branch & manifest
$ repo init -u https://source.codeaurora.org/external/imx/imx-manifest -b imx-linux-sumo -m imx-4.14.98-2.0.0_ga.xml

$ repo init -u https://source.codeaurora.org/external/imx/imx-manifest -b imx-linux-sumo -m imx-4.14.98-2.2.0.xml

$ repo init -u https://source.codeaurora.org/external/imx/imx-manifest
-b imx-linux-warrior -m imx-4.19.35-1.1.0.xml

//Sync repo
$ repo sync -j4

//Configure & Build same as 4.1
......
```

# 5. Rebuild one package

If one package build failed, you can clean and then rebuild it as below instruction:

* Remove temp:

  ```
  $ bitbake -c clean gstreamer
  ```

* To remove temp and sstate cache

  ```
  $ bitbake -c cleansstate gstreamer
  ```

* To remove download as well, and lets begin build starting from do_fetch and all

  ```
  $ bitbake -c cleanall gstreamer
  ```

* Once you are done with either of these clean, which ever suits you, you can simple give build command for the specified: 

  ```
  $ bitbake gstreamer
  ```

  

# 6. Flashing an SD card image

```
$ bunzip2 -dk -f <image_name>.sdcard.bz2 
$ sudo dd if=<image name>.sdcard of=/dev/sdx bs=1M conv=fsync
$ sudo dd if=./fsl-image-qt5-validation-imx-imx8qxpmek.sdcard of=/dev/sdx bs=1M conv=fsync
$ sudo dd if=./imx-image-full-imx8qxpmek.sdcard of=/dev/sdx bs=1M conv=fsync

#######
To identify the device node assigned to the SD/MMC card, carry out the following command on host:

$ cat /proc/partitions 
major minor  #blocks  name
   8     0   78125000 sda
   8     1   75095811 sda1
   8     2          1 sda2
   8     5    3028221 sda5
   8    32  488386584 sdc
   8    33  488386552 sdc1
   8    16    3921920 sdb
   8    18    3905535 sdb1
In this example, the device node assigned is /dev/sdb (a block is 1024 Bytes). 

```

# 10.  FAQ

* Error: Could not find vk_validation_error_messages.h 

  Reference [ https://community.nxp.com/thread/496054 ]( https://community.nxp.com/thread/496054 )

  It seems ubuntu18.04 has this issue, now we switch to ubuntu16.04.6 version.

*  Meson version is 0.44.1 but project requires >=0.45

   Modify tmp/work/aarch64-poky-linux/vkmark/1.0-r0/git/meson.build as below:

   ```
   --- a/meson.build
   +++ b/meson.build
   @@ -3,7 +3,7 @@ project(
        'cpp',
        default_options : ['cpp_std=c++14'],
        version : '2017.08',
   -    meson_version: '>=0.45'
   +    meson_version: '>=0.41'
        )
   ```

# 99. Reference URL

* [Yocto Project Reference Manual](https://community.nxp.com/external-link.jspa?url=https%3A%2F%2Fwww.yoctoproject.org%2Fdocs%2Fcurrent%2Fref-manual%2Fref-manual.html%23detailed-supported-distros) 

* [Create an Ubuntu VM environment to build Yocto BSP](https://community.nxp.com/docs/DOC-343758)  

* [https://www.codetd.com/article/7909182](https://www.codetd.com/article/7909182)

* [Multilib enablement iMX8 yocto](https://community.nxp.com/thread/505289)

* [meta-seco-bsp-release-imx8-ga-rel](https://git.seco.com/arm/nxp/imx8/release/bsp1/meta-seco-bsp-release-imx8-ga-rel)

* [Building CL-SOM-iMX8 Yocto Linux images](https://mediawiki.compulab.com/w/index.php?title=Building_CL-SOM-iMX8_Yocto_Linux_images)

* [Building Qt5 using yocto on Wandboard](http://wiki.wandboard.org/Building_Qt5_using_yocto_on_Wandboard)

* [Building Wandboard Systems with Yocto](https://jumpnowtek.com/wandboard/Wandboard-Systems-with-Yocto.html)

* [https://github.com/compulab-yokneam/meta-bsp-imx8mm](https://github.com/compulab-yokneam/meta-bsp-imx8mm)

  
