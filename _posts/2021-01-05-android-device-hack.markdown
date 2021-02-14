---
layout: post
title:  "Android Device Hack"
date:   2021-01-05 14:30:00 +0800
categories: linux android hack pixel3 adb fastboot
comments: true
---

# 1. Basic android tool install and usage

# 1.1 Download and install SDK Platform Tools

https://dl.google.com/android/repository/platform-tools-latest-windows.zip

Ref: https://developer.android.com/studio/releases/platform-tools



# 2. Google Pixel 3 Hack

## 2.1 How to Enable USB Debugging on the Google Pixel 3

Enable developer features on the Google Pixel 3 smartphone by enabling USB Debugging using these steps.

```
1. From the Home screen, swipe up the app list then select “**Settings**“.
2. Scroll to the bottom and tap “**About phone**“.
3. Scroll to the bottom and tap “**Build number**” 7 times.
4. Tap the “**Back**” arrow and you will now see a “**Developer options**” selection. Tap it.
5. Scroll to the “**Debugging**” section and turn “**USB debugging**” to “**On**“.
```

Ref:https://www.technipages.com/google-pixel-usb-debugging

## 2.2 Enable Pixel3 Uart

```
The last step is to reboot the device into the fastboot mode and enable UART (configured as 115200n8 with no hardware flow control):

# adb reboot-bootloader
# fastboot oem uart enable
In order to enable UART, the bootloader obviously needs to be unlocked in the first place.
```

Ref: https://duasynt.com/blog/google-pixel-uart-serial-cable



# 99. Reference URL

* 1) [Google Pixel UART kernel debug cable](https://duasynt.com/blog/google-pixel-uart-serial-cable)
* 2) [android-debug-cable-howto](https://github.com/Peter-Easton/android-debug-cable-howto)
* 3) [PL2303HX模块 USB转串口连接线 TTL电平 接耳机头2.5mm 3.5mm可选](https://item.taobao.com/item.htm?spm=a230r.1.14.23.428f64831Qjo2s&id=40811507033&ns=1&abbucket=10#detail)
* 4) [How to Unlock the Bootloader and Root the Google Pixel 3 with Magisk](https://www.xda-developers.com/google-pixel-3-unlock-bootloader-root-magisk/)
* 5) [Enabling the Serial Port (or Console, UART) on Google Pixel Phones](https://blog.bacon.dev/2020/10/enabling-serial-port-or-console-uart-on.html)
* 6) [USB3.1-CM-CF-V3A, USB 3.1 Type C Male to Female pass through adapter breakout board](https://elabbay.myshopify.com/products/usb3-1-cm-cf-v1a-usb3-1-type-c-male-to-female-pass-through-breakout-board?variant=45423178947)
* 7) [USB 3.1 Type C Female Test Socket Connector PC SMT Experimen](https://item.taobao.com/item.htm?spm=a230r.1.14.230.6f447485d1LOlU&id=635443682877&ns=1&abbucket=10#detail)
* 8) [USB TYPE-C CONN BREAKOUT BOARD](https://detail.tmall.com/item.htm?spm=a230r.1.14.71.918d3519waLs4i&id=629360226887&ns=1&abbucket=10)
* 9) [USB 3.1 Type C Female Test Socket Connector PC SMT Experimen](https://item.taobao.com/item.htm?spm=a230r.1.14.188.6f4474855V6Kls&id=635013437627&ns=1&abbucket=10#detail)
* 10) [USB 3.1 Type-C Connector 24Pin Female Socket PCB Adapter 2x1](https://detail.tmall.com/item.htm?spm=a230r.1.14.126.6f4474855V6Kls&id=633740035622&ns=1&abbucket=10)
* 11) [Adafruit USB Type-C Breakout Board Downstream Connectio](https://item.taobao.com/item.htm?spm=a230r.1.14.36.4b4064ee1iJoxD&id=633762616631&ns=1&abbucket=10#detail)
* 12) [2585〖 USB TYPE-C CONN BREAKOUT BOARD〗](https://detail.tmall.com/item.htm?spm=a230r.1.14.18.9da55feblAXe1s&id=625991863304&ns=1&abbucket=16)
* 12) [TYPE-C公转母测试板USB3.1母座转公头24P转接板PD快充延长数据线](https://item.taobao.com/item.htm?id=610030610901&ali_refid=a3_430582_1006:1242300083:N:kPEiXZhAHVHoMu3qupU0%2BY3seHOR9t8y:1cff6ab3155c5af532d91ad14f94dbf4&ali_trackid=1_1cff6ab3155c5af532d91ad14f94dbf4&spm=a230r.1.14.11#detail)
* 13) [Kirisakura-Kernel for the Pixel 3 and Pixel 3 XL](https://forum.xda-developers.com/t/kernel-05-01-2021-4-9-249-kirisakura_r-3-0-4-for-pixel-3-xl-aka-bluecross.3864563/)
* 14) [Samsung Galaxy A5 2017 (samsung-a5y17lte)](https://wiki.postmarketos.org/wiki/Samsung_Galaxy_A5_2017_(samsung-a5y17lte)#UART_cable)
* 15) [Serial debugging](https://wiki.postmarketos.org/wiki/Serial_debugging#Suzy-Q_debug_cable)
* 16) [Serial debugging:Cable schematics](https://wiki.postmarketos.org/wiki/Serial_debugging:Cable_schematics)
* 17) [3.5mm/2.5立体声插头座 螺丝接线/带端子 音频AUX3/4节免焊接](https://detail.tmall.com/item.htm?spm=a230r.1.14.16.671866aejmteN5&id=537030032133&cm_id=140105335569ed55e27b&abbucket=12&skuId=3205663970834)
* 18) [3.5mm音频线 公头带线 四极 AUX 4节 单头线 4芯 对录输入线 定做](https://item.taobao.com/item.htm?spm=a230r.1.14.83.671866aejmteN5&id=604628628278&ns=1&abbucket=12#detail)
* 19) [AOSP on Pixel3 running Mainline kernel](https://wiki.linaro.org/AOSP/blueline)
* 20) [AOSP on DragonBoard 845c](https://wiki.linaro.org/AOSP/db845c)
* 21) [Dragonboards in AOSP Status](https://docs.google.com/document/d/1df0pDOFCjvmJnylLpnD3GlIBV7BISY68Exc_I_kZMgg/edit#)
* 22) [How to Discover Hidden Fastboot Commands](https://www.xda-developers.com/how-to-discover-hidden-fastboot-commands/)
* 23) [How to enable serial console on Android](http://bootloader.wikidot.com/linux:android:serial)

