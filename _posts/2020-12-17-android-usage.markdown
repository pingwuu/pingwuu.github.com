---
layout: post
title:  "Android Usage"
date:   2020-12-17 13:30:00 +0800
categories: linux android
comments: true
---

# 1. Android build environment setup



# 2. ADB basic command

## 2.1 The adb devices command

![adb List](/static/img/2020-12-17-android-usage/adb-devices.webp)

The **adb devices** command is the most important one of the bunch, since it's used to make sure your computer and Android device are communicating. That's why we're covering it first.

If you're a pro at the operating system on your computer, you'll want to add the directory with the Android tools to your path. If you're not, no worries. Just start up your terminal or command console and point it where you put the extracted tools you downloaded above.

Once you're sure that you are in the right folder, type *adb devices* at the command prompt. If you get a serial number, you're good to go! If you don't, make sure you're in the right folder and that you have the device driver installed correctly if you're using Windows. And be sure you have USB debugging turned on!

Now that we have everything set up, let's look at a few more commands.

## 2.2 The adb push command

![adb push](/static/img/2020-12-17-android-usage/adb-push.webp)

If you want to move a file onto your Android device programmatically, you want to use the **adb push** command. You'll need to know a few parameters, namely the full path of the file you're pushing, and the full path to where you want to put it. In the picture above I'm pushing a song from my Music folder on my desktop to the music folder on my phone.

Notice the slashes in the file path and the quotes around the path on my computer in the command. **Windows uses \ as a directory switch in a file path and Unix uses /**. Because the file name has spaces and special characters (I renamed it this way on purpose!) you need to encase the path in quotes.

## 2.3 The adb pull command

![adb pull](/static/img/2020-12-17-android-usage/adb-pull.webp)

If adb push sends files to your Android device, it stands to reason the **adb pull** command would pull them out.

That's exactly what it does, and it works the same way as the adb push command did. You need to know both the path of the file you want to pull off, as well as the path you want it placed into. You can leave the destination path blank and it will drop the file into your tools folder to make things easy.

In this example, I did it the hard way and entered the full path(s) so you can see what it looks like. Remember your forward slash versus backward slash rules here and you'll have no problems.

## 2.4 The adb reboot command

![adb pull](/static/img/2020-12-17-android-usage/adb-reboot.webp)

This is exactly what you think it is — a way to reboot your device from the command line. Running it is simple: just type *adb reboot* and enter.

Before you say "I can just push the button!" you have to understand that these commands can be scripted, and your device can reboot in the middle of a script if you need it to. And that's a good segue to number five.

## 2.5 The adb reboot-bootloader and adb reboot recovery commands

![adb pull](/static/img/2020-12-17-android-usage/android-bootloader.webp)

Not only can you reboot your device, but you can also specify that it reboots to the bootloader. This is awfully handy, as sometimes those button combos are touchy, and if you have a lot of devices it's tough to remember them all. Some devices don't even have a way to boot to the bootloader without this command. And once again, being able to use this command in a script is priceless.

Doing it is easy, just type *adb reboot-bootloader* and hit the enter key.

Most devices can also boot into the recovery directly with the *adb reboot recovery* (note there is no hyphen in this one) and some can't. It won't hurt anything to try.

## 2.6 The fastboot devices command

![adb pull](/static/img/2020-12-17-android-usage/adb-fastboot.webp)

When you're working inside the bootloader, adb no longer works. You're not yet booted into Android, and the debugging tools aren't active to communicate with. You'll need to use the **fastboot** command in its place.

Fastboot is probably the most powerful Android debug tool available, and many devices don't have it enabled. If yours does, you need to be sure things are communicating. That's where the fastboot devices command comes into play. At the prompt, just type in *fastboot devices* and you should see a serial number, just like the adb devices command we looked at earlier.

If things aren't working and you're using Windows, you likely have a driver issue and you'll need to source it from the manufacturer.

## 2.7 The fastboot unlock command

![adb pull](/static/img/2020-12-17-android-usage/fastboot-oem-unlock-warning.webp)

**The fastboot unlock process will erase \*everything\* on your phone and reset it.**

The holy grail of Android commands, **fastboot flashing unlock** does one thing, and one thing only -- unlocks your bootloader. It's not enabled on every phone, even phones that support fastboot, but we're including it because even if you don't need it, it's an important part of Android's openness. Google doesn't care what we do with phones as long as it doesn't go against rules for Google Play access, and that includes this easy way to crack them open, even if the company who made your phone doesn't support it.

Using it is easy enough. Once you've used fastboot devices to make sure everything is communicating, just type *fastboot flashing unlock* at the prompt and hit enter. Look at your device, read carefully, and choose wisely.

## 2.8 The adb install command

![adb pull](/static/img/2020-12-17-android-usage/adb-install.png)

While adb push can copy files to our Android devices, **adb install** can actually install apps. You'll need to supply the path where you have the .apk file saved, then run it like this: *adb install TheAppName.apk*.

If you're updating an app, you use the -r switch: *adb install -r TheAppName.apk*. There is also a **-s** switch which tries to install on the SD card as well as other commands you probably won't ever need.

And finally, you can uninstall apps by their package name with *adb uninstall package-name-here*. Uninstall has a switch, too. The -k switch will uninstall the app but leave all the app data and cache in place.

## 2.9 The adb sideload command

![adb pull](/static/img/2020-12-17-android-usage/adb-sideload.png)

An OTA (over-the-air) update is downloaded by your phone as a .zip file. You can also download that zip file manually and install it without having to wait for your phone to have the update pushed to it. The end result is the same as if you had waited, but we hate waiting.

All you have to do is download the update to your computer. Plug your phone into the computer. Then, reboot into recovery on your phone and using the up and down volume buttons choose *Apply update from ADB*. Then hop into your favorite terminal/command line and type *adb sideload Full-Path-to-the-file.zip* and hit enter. Let things run their course, and you're golden.

## 2.10 The adb shell command

![adb shell](/static/img/2020-12-17-android-usage/adb-shell.png)

The **adb shell** command confuses a lot of folks. There are two ways to use it, one where you send a command to the device to run in its own command-line shell, and one where you actually enter the device's command shell from your terminal.

In the image above, I'm inside the device shell. Getting there is easy enough, just type *adb shell* and enter. Once inside, you can interact with the actual running operating system on your phone. I'll warn you that unless you're familiar with an ash or bash shell, you need to be careful here because things can turn south quickly if you're not. Ash and bash are command shells. They allow you to interact with your phone through typed commands and a lot of folks use one or both on their Linux or Mac computers even if they didn't know it. **It is not DOS so don't try any DOS commands.**

The other method of using the adb shell command is using it to tell your phone to run a shell command without going into the shell. Using it is easy; type *adb shell* An example would be changing permissions on a file like so: *adb shell chmod666 /sdcard/somefile*.

Be very careful running direct commands using these methods.

-----------------------------------------------------------------------------------------------------------------------------------------------------------

Ref:https://www.androidcentral.com/10-basic-terminal-commands-you-should-know



# 2. Dragonboard 410c board

## 2.1 DragonBoard 410c Board Recovery

Reference URL: 

https://www.96boards.org/documentation/consumer/dragonboard/dragonboard410c/installation/board-recovery.md.html#sd-card-recovery-image

https://www.96boards.org/documentation/consumer/guides/qdl.md.html

1) Fastboot on Linux Host

Ref url: https://www.96boards.org/documentation/consumer/dragonboard/dragonboard410c/installation/linux-fastboot.md.html



## 2.1 Flash SD Image

Reference URL: https://blog.csdn.net/cuichuankai/article/details/49761755



1) Download SD Image for Android

https://releases.linaro.org/96boards/dragonboard410c/qualcomm/android/16.06/dragonboard410c_sdcard_install_android-118.zip

2) Flash image to SD card

```
//check sd card device on host pc
$ cat /proc/partitions 
major minor  #blocks  name

   7        0       2220 loop0
   7        1      66324 loop1
   7        2       2496 loop2
   7        3     165288 loop3
   7        4      56692 loop4
   7        5        276 loop5
   7        6       3736 loop6
   7        7     261700 loop7
  11        0    1048575 sr0
   8        0  367001600 sda
   8        1  366999552 sda1
   7        8     166776 loop8
   7        9     100208 loop9
   7       10       2540 loop10
   7       11        956 loop11
   7       12      65896 loop12
   7       13     223124 loop13
   7       14      56712 loop14
   7       15     100208 loop15
   7       16        276 loop16
   7       17        956 loop17
   8       16   15558144 sdb    	<------ Maybe this is you sd card  

//unzip downloaded image
$ unzip dragonboard410c_sdcard_install_android-118.zip

//using dd write image to sd card
$ sudo dd if=db410c_sd_install_android.img of=/dev/sdb bs=4M
$ sync

```







## 2.2 Build Android for db410c

```
$ repo init -u https://android.googlesource.com/platform/manifest -b master
$ repo sync -j$(nproc) -c

$ rm -r device/linaro/dragonboard
$git clone -b db410c https://android-git.linaro.org/device/linaro/dragonboard410c.git device/linaro/dragonboard

$ source build/envsetup.sh

$ lunch db410c32_only-userdebug

or

$ lunch db410c

$ make -j8
```



```
$ repo init -u git://codeaurora.org/platform/manifest.git -b release -m LA.BR.1.2.9.c25-04000-8x16.0.xml –repo-url=git://codeaurora.org/tools/repo.git

$ 

```





## 2.99. FAQ

* 1) checkvintf E 11-19 21:57:18 294853 294853 VintfObject.cpp:68] getDeviceHalManifest: -2147483648 VINTF parse error: Cannot add manifest fragment /vendor/etc/vintf/manifest/manifest.xml: HAL "android.hardware.wifi.supplicant" has a conflict: Conflicting major version: 1.2 (from /vendor/etc/vintf/manifest.xml) vs. 1.3 (from /vendor/etc/vintf/manifest/manifest.xml). Check whether or not multiple modules providing the same HAL are installed.

In my case (android 10 and 11) it was:
out/target/product/db410c32_only/vendor/etc/vintf/manifest.xml

I commented out the whole 2 sections starting at:

```
<!--
<hal format="hidl" >
 <name>android.hardware.wifi.hostapd</name>
 ...
</hal>

and  
<hal format="hidl" >
 <name>android.hardware.wifi.supplicant</name>
 ...
</hal>

-->
```

* 2) [Android not showing up after flashing](https://discuss.96boards.org/t/android-not-showing-up-after-flashing/1506)

  Solution: 

  Hi geko,

  I have encountered the same situation, and I found if I erase all partitions then it works!

  ```
  sudo fastboot erase DDR
  sudo fastboot erase aboot
  sudo fastboot erase abootbak
  sudo fastboot erase boot
  sudo fastboot erase cache
  sudo fastboot erase config
  sudo fastboot erase devinfo
  sudo fastboot erase fsc
  sudo fastboot erase fsg
  sudo fastboot erase hyp
  sudo fastboot erase hypbak
  sudo fastboot erase keystore
  sudo fastboot erase misc
  sudo fastboot erase modem
  sudo fastboot erase modemst1
  sudo fastboot erase modemst2
  sudo fastboot erase oem
  sudo fastboot erase persist
  sudo fastboot erase recovery
  sudo fastboot erase rpm
  sudo fastboot erase rpmbak
  sudo fastboot erase sbl1
  sudo fastboot erase sbl1bak
  sudo fastboot erase sec
  sudo fastboot erase ssd
  sudo fastboot erase system
  sudo fastboot erase tz
  sudo fastboot erase tzbak
  sudo fastboot erase userdata
  ```

  



# 99. Reference URL

* 1) [Building Android Open Source Project (AOSP) for Dragonboard 410c and 820c Family](https://www.96boards.org/documentation/consumer/dragonboard/guides/aosp/)
* 2) [Is the AOSP master supported for Dragonboard 410c?](https://discuss.96boards.org/t/is-the-aosp-master-supported/9017)
* 3) [Android AOSP 7.1 build for DragonBoard 410c - Successful build but failed to boot](https://discuss.96boards.org/t/android-aosp-7-1-build-for-dragonboard-410c-successful-build-but-failed-to-boot/10716)
* 4) [VAR-SOM-MX8 - Android Pie P9.0.0_r30 Developer Guide](https://variwiki.com/index.php?title=Android_NXP_Guide&release=RELEASE_P9.0.0_2.0.0_GA_VAR-SOM-MX8)
* 5) [Download Qualcomm HS-USB QDLoader 9008 Drivers & How to Install](https://www.thecustomdroid.com/qualcomm-hs-usb-qdloader-9008-drivers/)
* 6) [Download and Install Qualcomm QDL Driver [QDLoader HS-USB]](https://www.getdroidtips.com/download-qualcomm-qdl-driver-qdloader/)
* 7) [Noob's guide to building AOSP from scratch.](https://forum.xda-developers.com/t/noobs-guide-to-building-aosp-from-scratch.4012293/)
* 8) [Snapdragon Development Platforms](https://wiki.codeaurora.org/xwiki/bin/Snapdragon+Developer+Platforms/)
* 9) [https://www.codeaurora.org/project-category/active-projects](https://www.codeaurora.org/project-category/active-projects)
* 10) [db820c|db410c: Update prebuilt qcomlt-4.14 kernel](https://android-review.linaro.org/c/device/linaro/dragonboard410c-kernel/+/18461/1)
* 
