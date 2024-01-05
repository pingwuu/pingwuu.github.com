---
layout: post
title:  "Allwinner Chip Usage"
date:   2020-12-11 09:30:00 +0800
categories: allwinner linux driver
comments: true
---
**Table of Contents**
- [1. F1C100s - LicheePI Nano](#1-f1c100s---licheepi-nano)
- [2. F1C200S - MangoPi-R3](#2-f1c200s---mangopi-r3)
- [90 FAQ](#90-faq)
- [99. Reference URL](#99-reference-url)

# 1. F1C100s - LicheePI Nano



# 2. F1C200S - MangoPi-R3

# 3. walnutpi

## 3.1 build image

update host package
```
$ sudo apt-get install swig

$ sudo apt update
$ sudo apt install software-properties-common
$ sudo add-apt-repository ppa:deadsnakes/ppa
$ sudo apt install python3.8
$ sudo apt-get install python3.8-dev python3-setuptools
```

switch python3 to python3.8
```
$ sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.6 36
$ sudo update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.8 38
$ sudo update-alternatives --config python3
```

### 3.1.1 build uboot
```
$ git clone https://github.com/ARM-software/arm-trusted-firmware.git
$ git clone https://github.com/walnutpi/uboot.git
$ export PATH=/usr/local/linaro-aarch64-2020.09-gcc10.2-linux5.4/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
$ export CROSS_COMPILE=aarch64-linux-gnu-

$ cd arm-trusted-firmware
$ make PLAT=sun50i_h616  DEBUG=1 bl31

$ cd ../uboot/

$ make walnutpi_1b_defconfig

$ make orangepi_zero2_defconfig
$ make orangepi_zero3_defconfig

$ make BL31=../arm-trusted-firmware/build/sun50i_h616/debug/bl31.bin
```

### 3.1.2 flash u-boot-sunxi-with-spl.bin to sdcard offset 8K position
```
$ sudo dd if=u-boot-sunxi-with-spl.bin of=/dev/sdX bs=1k seek=8
```

# 90. FAQ



# 99. Reference URL

* 1) [FEL](https://linux-sunxi.org/FEL)
* 2) [licheepi zero BSP 内核(linux3.4) 编译教程](https://whycan.com/t_682.html)
* 3) [连续多个晚上熬夜，终于搞定F1C100S裸奔（从SPI Flash启动）](https://whycan.com/t_1393.html)
* 4) [F1C100S裸奔framebuffer+PWM+GPIO驱动](https://whycan.com/t_1457.html)
* 5) [Nano 一键烧录及脚本使用说明](http://nano.lichee.pro/build_sys/onekey.html)
* 6) [MangoPi-R3](https://wiki.dfrobot.com.cn/_SKU_DFR0780_MangoPi-R3)
* 7) [最新版本：R3c](https://mangopi.org.cn/mangopi_r)
* 8) [buildroot-tiny200 (F1C100/200s) 开发包近期更新内容 * 已支持DVP摄像头 *](https://whycan.com/t_5221.html/t_5221.html)
* 9) [荔枝派Nano 全流程指南](http://nano.lichee.pro/)
* 10) https://github.com/thirtythreeforty/businesscard-linux/issues/11
* 11) [uboot 增加不同型号的 nor-flash 调试笔记](https://blog.csdn.net/u010632165/article/details/117752714)
* 12) [【linux项目】lichee nano linux烧写](https://www.cnblogs.com/lizhuming/p/15487208.html)
* 13) [尝试从零构建F1C100s开发环境](https://whycan.com/t_3138.html)
* 13) [分享一份自己的F1c100s的Buildroot编译配置](https://whycan.com/t_4214.html)
* 14) [jim-kirisame](https://github.com/jim-kirisame)/**[buildroot_configs](https://github.com/jim-kirisame/buildroot_configs)**
