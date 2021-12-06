---
layout: post
title:  "Android Device Hack"
date:   2021-01-05 14:30:00 +0800
categories: linux android hack pixel3 adb fastboot
comments: true
---

[TOC]

# 1. Android tool install and usage

## 1.1 Download and install SDK Platform Tools

https://dl.google.com/android/repository/platform-tools-latest-windows.zip

Ref: https://developer.android.com/studio/releases/platform-tools



# 2. Flash and Build Android for Pixel 3

## 2.1 Flash Factory Image

1) Download factory image for pixel 3 of android 11

https://dl.google.com/dl/android/aosp/blueline-rq1a.210205.004-factory-3ab98ba8.zip

2) Flash all image

```
unzip blueline-rq1a.210205.004-factory-3ab98ba8.zip

C:\Android\pixel3\blueline-rq1a.210205.004>flash-all.bat
Sending 'bootloader' (8517 KB)                     OKAY [  0.219s]
Writing 'bootloader'                               FAILED (remote: 'No such file or directory')
fastboot: error: Command failed
Rebooting into bootloader                          OKAY [  0.007s]
Finished. Total time: 0.010s
< waiting for any device >
Sending 'radio_a' (71452 KB)                       OKAY [  2.148s]
Writing 'radio_a'                                  (bootloader) Flashing Pack version SSD:g845-00146-201008-B-6891496
(bootloader) Flashing partition modem_a
OKAY [  0.418s]
Finished. Total time: 3.196s
Rebooting into bootloader                          OKAY [  0.048s]
Finished. Total time: 0.051s
< waiting for any device >
--------------------------------------------
Bootloader Version...: b1c1-0.3-6863019
Baseband Version.....: g845-00146-201008-B-6891496
Serial Number........: 8ABX0Q0Q4
--------------------------------------------
extracting android-info.txt (0 MB) to RAM...
Checking 'product'                                 OKAY [  0.164s]
Checking 'version-bootloader'                      OKAY [  0.168s]
Checking 'version-baseband'                        OKAY [  0.168s]
Setting current slot to 'a'                        OKAY [  0.186s]
extracting boot.img (64 MB) to disk... took 0.232s
archive does not contain 'boot.sig'
Sending 'boot_a' (65536 KB)                        OKAY [  1.612s]
Writing 'boot_a'                                   OKAY [  0.315s]
extracting dtbo.img (8 MB) to disk... took 0.029s
archive does not contain 'dtbo.sig'
Sending 'dtbo_a' (8192 KB)                         OKAY [  0.285s]
Writing 'dtbo_a'                                   OKAY [  0.089s]
archive does not contain 'dt.img'
archive does not contain 'recovery.img'
extracting vbmeta.img (0 MB) to disk... took 0.001s
archive does not contain 'vbmeta.sig'
Sending 'vbmeta_a' (8 KB)                          OKAY [  0.118s]
Writing 'vbmeta_a'                                 OKAY [  0.064s]
archive does not contain 'vbmeta_system.img'
archive does not contain 'vendor_boot.img'
extracting super_empty.img (0 MB) to disk... took 0.002s
Rebooting into fastboot                            OKAY [  0.052s]
< waiting for any device >
Sending 'system_a' (4 KB)                          OKAY [  0.007s]
Updating super partition                           OKAY [  0.043s]
Resizing 'product_a'                               OKAY [  0.036s]
Resizing 'system_a'                                OKAY [  0.035s]
Resizing 'system_ext_a'                            OKAY [  0.035s]
Resizing 'vendor_a'                                OKAY [  0.035s]
archive does not contain 'boot_other.img'
archive does not contain 'odm.img'
archive does not contain 'odm_dlkm.img'
extracting product.img (1883 MB) to disk... took 8.325s
archive does not contain 'product.sig'
Resizing 'product_a'                               OKAY [  0.046s]
Sending sparse 'product_a' 1/8 (262140 KB)         OKAY [  6.384s]
Writing 'product_a'                                OKAY [  2.467s]
Sending sparse 'product_a' 2/8 (262140 KB)         OKAY [  6.330s]
Writing 'product_a'                                OKAY [  1.422s]
Sending sparse 'product_a' 3/8 (262140 KB)         OKAY [  6.280s]
Writing 'product_a'                                OKAY [  1.326s]
Sending sparse 'product_a' 4/8 (262140 KB)         OKAY [  6.363s]
Writing 'product_a'                                OKAY [  1.379s]
Sending sparse 'product_a' 5/8 (262140 KB)         OKAY [  6.296s]
Writing 'product_a'                                OKAY [  1.372s]
Sending sparse 'product_a' 6/8 (262140 KB)         OKAY [  6.295s]
Writing 'product_a'                                OKAY [  1.354s]
Sending sparse 'product_a' 7/8 (262140 KB)         OKAY [  6.280s]
Writing 'product_a'                                OKAY [  1.359s]
Sending sparse 'product_a' 8/8 (94004 KB)          OKAY [  2.280s]
Writing 'product_a'                                OKAY [  0.578s]
extracting system.img (786 MB) to disk... took 3.763s
archive does not contain 'system.sig'
Resizing 'system_a'                                OKAY [  0.046s]
Sending sparse 'system_a' 1/4 (262140 KB)          OKAY [  6.272s]
Writing 'system_a'                                 OKAY [  2.504s]
Sending sparse 'system_a' 2/4 (262140 KB)          OKAY [  6.354s]
Writing 'system_a'                                 OKAY [  1.352s]
Sending sparse 'system_a' 3/4 (262140 KB)          OKAY [  6.327s]
Writing 'system_a'                                 OKAY [  1.349s]
Sending sparse 'system_a' 4/4 (18540 KB)           OKAY [  0.451s]
Writing 'system_a'                                 OKAY [  0.219s]
extracting system_ext.img (182 MB) to disk... took 0.740s
archive does not contain 'system_ext.sig'
Resizing 'system_ext_a'                            OKAY [  0.047s]
Sending 'system_ext_a' (187292 KB)                 OKAY [  4.504s]
Writing 'system_ext_a'                             OKAY [  2.117s]
extracting system_other.img (68 MB) to disk... took 0.302s
archive does not contain 'system.sig'
Sending 'system_b' (69888 KB)                      OKAY [  1.677s]
Writing 'system_b'                                 OKAY [  0.401s]
extracting vendor.img (408 MB) to disk... took 2.252s
archive does not contain 'vendor.sig'
Resizing 'vendor_a'                                OKAY [  0.048s]
Sending sparse 'vendor_a' 1/2 (262140 KB)          OKAY [  6.378s]
Writing 'vendor_a'                                 OKAY [  2.476s]
Sending sparse 'vendor_a' 2/2 (156520 KB)          OKAY [  3.809s]
Writing 'vendor_a'                                 OKAY [  0.873s]
archive does not contain 'vendor_dlkm.img'
archive does not contain 'vendor_other.img'
Erasing 'userdata'                                 OKAY [  8.207s]
Erase successful, but not automatically formatting.
File system type raw not supported.
Erasing 'metadata'                                 OKAY [  0.014s]
Erase successful, but not automatically formatting.
File system type raw not supported.
Rebooting                                          OKAY [  0.007s]
Finished. Total time: 159.558s
Press any key to exit...
```



## 2.2 Build from AOSP source for Android 11 of Pixel 3

Version Info:

Factory image version: 11.0.0 (RQ1A.210205.004, Feb 2021) (Ref: https://developers.google.com/android/images)

Build number: RQ1A.210205.004	android-11.0.0_r29	Android11	Pixel 3, Pixel 3a, Pixel 3a XL, Pixel 3 XL, Pixel 4, Pixel 4a, Pixel 4a (5G), Pixel 4 XL, Pixel 5	2021-02-05 (Ref: https://source.android.com/setup/start/build-numbers)

Driver Binaries:
Pixel 3 binaries for Android 11.0.0 (RQ1A.210205.004)(https://developers.google.com/android/drivers)

| Hardware Component                                          | Company  | Download                                                     | SHA-256 Checksum                                             |
| :---------------------------------------------------------- | :------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| Vendor image                                                | Google   | [Link](https://dl.google.com/dl/android/aosp/google_devices-blueline-rq1a.210205.004-bdf0db36.tgz) | 63060335ea10a8cf3c8d558e6614ac29cacf57dcb7bfa691cd833331922a1146 |
| GPS, Audio, Camera, Gestures, Graphics, DRM, Video, Sensors | Qualcomm | [Link](https://dl.google.com/dl/android/aosp/qcom-blueline-rq1a.210205.004-9842d5ac.tgz) |                                                              |

```
$ mkdir android
$ cd android
$ repo init -u https://android.googlesource.com/platform/manifest -b android-11.0.0_r29
$ repo sync -j16
$ axel http://dl.google.com/dl/android/aosp/google_devices-blueline-rq1a.210205.004-bdf0db36.tgz
$ tar -zxvf google_devices-blueline-rq1a.210205.004-bdf0db36.tgz
$ ./extract-google_devices-blueline.sh
...
Files extracted successfully.


$ axel http://dl.google.com/dl/android/aosp/qcom-blueline-rq1d.210105.003-9fa2b19d.tgz
$ tar -zxvf qcom-blueline-rq1d.210105.003-9fa2b19d.tgz
$ ./extract-qcom-blueline.sh
...
Files extracted successfully.


$ source build/envsetup.sh
$ lunch

You're building on Linux

Lunch menu... pick a combo:
     1. aosp_arm-eng
     2. aosp_arm64-eng
     3. aosp_blueline-userdebug
     4. aosp_blueline_car-userdebug
     5. aosp_bonito-userdebug
     6. aosp_bonito_car-userdebug
     7. aosp_bramble-userdebug
     8. aosp_car_arm-userdebug
     9. aosp_car_arm64-userdebug
     10. aosp_car_x86-userdebug
     11. aosp_car_x86_64-userdebug
     12. aosp_car_x86_64_app-userdebug
     13. aosp_cf_arm64_auto-userdebug
     14. aosp_cf_arm64_phone-userdebug
     15. aosp_cf_x86_64_phone-userdebug
     16. aosp_cf_x86_auto-userdebug
     17. aosp_cf_x86_phone-userdebug
     18. aosp_cf_x86_tv-userdebug
     19. aosp_coral-userdebug
     20. aosp_coral_car-userdebug
     21. aosp_crosshatch-userdebug
     22. aosp_crosshatch_car-userdebug
     23. aosp_flame-userdebug
     24. aosp_flame_car-userdebug
     25. aosp_redfin-userdebug
     26. aosp_sargo-userdebug
     27. aosp_sunfish-userdebug
     28. aosp_trout_arm64-userdebug
     29. aosp_trout_x86-userdebug
     30. aosp_x86-eng
     31. aosp_x86_64-eng
     32. arm_krait-eng
     33. arm_v7_v8-eng
     34. armv8-eng
     35. armv8_kryo385-eng
     36. beagle_x15-userdebug
     37. beagle_x15_auto-userdebug
     38. car_x86_64-userdebug
     39. db845c-userdebug
     40. fuchsia_arm64-eng
     41. fuchsia_x86_64-eng
     42. hikey-userdebug
     43. hikey64_only-userdebug
     44. hikey960-userdebug
     45. hikey960_tv-userdebug
     46. hikey_tv-userdebug
     47. pixel3_mainline-userdebug
     48. poplar-eng
     49. poplar-user
     50. poplar-userdebug
     51. qemu_trusty_arm64-userdebug
     52. silvermont-eng
     53. uml-userdebug
     54. yukawa-userdebug
     55. yukawa_sei510-userdebug

$ lunch aosp_blueline-userdebug	//blueline for Google Pixel 3 device

$ make -j24


//Flash all -- Not booted
$ export ANDROID_PRODUCT_OUT=./out/target/product/blueline

$ fastboot flashall -w
--------------------------------------------
Bootloader Version...: b1c1-0.3-6863019
Baseband Version.....: g845-00146-201008-B-6891496
Serial Number........: 8ABX0Q0Q4
--------------------------------------------
Checking 'product'                                 OKAY [  0.060s]
Setting current slot to 'a'                        OKAY [  0.146s]
Sending 'boot_a' (65536 KB)                        OKAY [  2.470s]
Writing 'boot_a'                                   OKAY [  0.389s]
Sending 'dtbo_a' (8192 KB)                         OKAY [  0.390s]
Writing 'dtbo_a'                                   OKAY [  0.100s]
Sending 'vbmeta_a' (8 KB)                          OKAY [  0.120s]
Writing 'vbmeta_a'                                 OKAY [  0.067s]
Rebooting into fastboot                            OKAY [  0.060s]
< waiting for any device >
Sending 'system_a' (4 KB)                          OKAY [  0.008s]
Updating super partition                           OKAY [  0.052s]
Resizing 'product_a'                               OKAY [  0.035s]
Resizing 'system_a'                                OKAY [  0.035s]
Resizing 'system_ext_a'                            OKAY [  0.035s]
Resizing 'product_a'                               OKAY [  0.046s]
Sending 'product_a' (234160 KB)                    OKAY [  9.172s]
Writing 'product_a'                                OKAY [  1.546s]
Resizing 'system_a'                                OKAY [  0.046s]
Sending sparse 'system_a' 1/4 (262140 KB)          OKAY [ 10.892s]
Writing 'system_a'                                 OKAY [  1.657s]
Sending sparse 'system_a' 2/4 (262140 KB)          OKAY [ 10.558s]
Writing 'system_a'                                 OKAY [  1.382s]
Sending sparse 'system_a' 3/4 (262140 KB)          OKAY [ 10.632s]
Writing 'system_a'                                 OKAY [  1.348s]
Sending sparse 'system_a' 4/4 (17604 KB)           OKAY [  0.858s]
Writing 'system_a'                                 OKAY [  0.199s]
Resizing 'system_ext_a'                            OKAY [  0.047s]
Sending 'system_ext_a' (105516 KB)                 OKAY [  4.076s]
Writing 'system_ext_a'                             OKAY [  0.932s]
Sending 'system_b' (68476 KB)                      OKAY [  2.781s]
Writing 'system_b'                                 OKAY [  0.421s]
Erasing 'userdata'                                 OKAY [  8.400s]
Erase successful, but not automatically formatting.
File system type raw not supported.
Erasing 'metadata'                                 OKAY [  0.016s]
Erase successful, but not automatically formatting.
File system type raw not supported.
Rebooting                                          OKAY [  0.006s]
Finished. Total time: 109.975s


//Flash all - boot well
$ fastboot flashall -w
--------------------------------------------
Bootloader Version...: b1c1-0.3-6863019
Baseband Version.....: g845-00146-201008-B-6891496
Serial Number........: 8ABX0Q0Q4
--------------------------------------------
Checking 'product'                                 OKAY [  0.060s]
Setting current slot to 'a'                        OKAY [  0.077s]
Sending 'boot_a' (65536 KB)                        OKAY [  2.680s]
Writing 'boot_a'                                   OKAY [  0.322s]
Sending 'dtbo_a' (8192 KB)                         OKAY [  0.610s]
Writing 'dtbo_a'                                   OKAY [  0.098s]
Sending 'vbmeta_a' (8 KB)                          OKAY [  0.120s]
Writing 'vbmeta_a'                                 OKAY [  0.067s]
Rebooting into fastboot                            OKAY [  0.060s]
< waiting for any device >
Sending 'system_a' (4 KB)                          OKAY [  0.008s]
Updating super partition                           OKAY [  0.051s]
Resizing 'product_a'                               OKAY [  0.035s]
Resizing 'system_a'                                OKAY [  0.035s]
Resizing 'system_ext_a'                            OKAY [  0.036s]
Resizing 'vendor_a'                                OKAY [  0.034s]
Resizing 'product_a'                               OKAY [  0.045s]
Sending 'product_a' (234160 KB)                    OKAY [  9.188s]
Writing 'product_a'                                OKAY [  1.512s]
Resizing 'system_a'                                OKAY [  0.046s]
Sending sparse 'system_a' 1/4 (262140 KB)          OKAY [ 10.359s]
Writing 'system_a'                                 OKAY [  1.657s]
Sending sparse 'system_a' 2/4 (262140 KB)          OKAY [ 10.710s]
Writing 'system_a'                                 OKAY [  1.390s]
Sending sparse 'system_a' 3/4 (262140 KB)          OKAY [ 10.614s]
Writing 'system_a'                                 OKAY [  1.352s]
Sending sparse 'system_a' 4/4 (19856 KB)           OKAY [  0.911s]
Writing 'system_a'                                 OKAY [  0.209s]
Resizing 'system_ext_a'                            OKAY [  0.047s]
Sending 'system_ext_a' (105516 KB)                 OKAY [  4.112s]
Writing 'system_ext_a'                             OKAY [  0.971s]
Sending 'system_b' (69468 KB)                      OKAY [  2.795s]
Writing 'system_b'                                 OKAY [  0.413s]
Resizing 'vendor_a'                                OKAY [  0.046s]
Sending sparse 'vendor_a' 1/3 (262140 KB)          OKAY [ 10.491s]
Writing 'vendor_a'                                 OKAY [  1.684s]
Sending sparse 'vendor_a' 2/3 (262140 KB)          OKAY [ 10.856s]
Writing 'vendor_a'                                 OKAY [  1.347s]
Sending sparse 'vendor_a' 3/3 (35976 KB)           OKAY [  1.572s]
Writing 'vendor_a'                                 OKAY [  0.288s]
Erasing 'userdata'                                 OKAY [  8.419s]
Erase successful, but not automatically formatting.
File system type raw not supported.
Erasing 'metadata'                                 OKAY [  0.040s]
Erase successful, but not automatically formatting.
File system type raw not supported.
Rebooting                                          OKAY [  0.006s]
Finished. Total time: 126.742s

```

# 3. Google Pixel 3 Hack

## 3.1 How to Enable USB Debugging on the Google Pixel 3

Enable developer features on the Google Pixel 3 smartphone by enabling USB Debugging using these steps.

```
1. From the Home screen, swipe up the app list then select “**Settings**“.
2. Scroll to the bottom and tap “**About phone**“.
3. Scroll to the bottom and tap “**Build number**” 7 times.
4. Tap the “**Back**” arrow and you will now see a “**Developer options**” selection. Tap it.
5. Scroll to the “**Debugging**” section and turn “**USB debugging**” to “**On**“.
```

Ref:https://www.technipages.com/google-pixel-usb-debugging



## 3.2 unlock/re-lock bootloader

### Unlocking the bootloader

You can flash a custom system only if the bootloader allows it, and the bootloader is locked by default. You can unlock the bootloader, but doing so deletes user data for privacy reasons. After unlocking, *all* data on the device is erased, that is, both private app data and shared data accessible over USB (including photos and movies). Before attempting to unlock the bootloader, back up any important files on the device.

You need to unlock the bootloader only once, and you can re-lock it if necessary.

### Unlocking recent devices

All Nexus and Pixel devices released since 2014 (starting with Nexus 6 and Nexus 9) have factory-reset protection and require a multistep process to unlock the bootloader.

1. To enable OEM unlocking on the device:

   1. In Settings, tap **About phone**, then tap **Build number** seven times.
   2. When you see the message *You are a developer*, tap the **back** button.
   3. Tap **Developer options** and enable **OEM unlocking** and **USB debugging**. (If **OEM unlocking** is disabled, connect to the internet so the device can check in at least once. If it remains disabled, your device might be SIM locked by your carrier and the bootloader can't be unlocked.)

2. Reboot into the bootloader and use

    

   ```
   fastboot
   ```

    

   to unlock it.

   - For newer devices (2015 and higher):

     ```
     fastboot flashing unlock
     ```

   - For older devices (2014 and lower):

     ```
     fastboot oem unlock
     ```

3. Confirm the unlock onscreen.

**Note:** On Nexus 10, after unlocking the bootloader, the internal storage remains unformatted. You can format the device using `fastboot format cache` followed by `fastboot format userdata`.

### Re-locking the bootloader

To re-lock the bootloader:

- For newer devices (2015 and higher):

  ```
  fastboot flashing lock
  ```

- For older devices (2014 and lower):

  ```
  fastboot oem lock
  ```

**Note:** Re-locking the bootloading on a Motorola Xoom erases all user data (including the shared USB data).

Ref: [unlocking-the-bootloader](https://source.android.com/setup/build/running#unlocking-the-bootloader)



## 3.3 Enable Pixel 3 Uart

```
The last step is to reboot the device into the fastboot mode and enable UART (configured as 115200n8 with no hardware flow control):

# adb reboot-bootloader
//enable uart console
# fastboot oem uart enable
In order to enable UART, the bootloader obviously needs to be unlocked in the first place.

//disable uart console
# fastboot oem uart disable
```

Ref: https://duasynt.com/blog/google-pixel-uart-serial-cable



# 4. Always-Updated List of Google Pixel Codenames

In a tradition dating back to the [Nexus](https://nexus5.gadgethacks.com/) days, Google has always used fish-themed codenames when communicating internally about their phones. Their laptops and tablets are usually named after video game characters. These names often give us the first evidence of an upcoming device when they're used in software commits in [Android's open source code](https://android-review.googlesource.com/).

- **Jump to a model year: [2013](https://android.gadgethacks.com/how-to/list-googles-internal-code-names-for-every-pixel-device-ever-0345367/#jump-2013devices) | [2015](https://android.gadgethacks.com/how-to/list-googles-internal-code-names-for-every-pixel-device-ever-0345367/#jump-2015devices) | [2016](https://android.gadgethacks.com/how-to/list-googles-internal-code-names-for-every-pixel-device-ever-0345367/#jump-2016devices) | [2017](https://android.gadgethacks.com/how-to/list-googles-internal-code-names-for-every-pixel-device-ever-0345367/#jump-2017devices) | [2018](https://android.gadgethacks.com/how-to/list-googles-internal-code-names-for-every-pixel-device-ever-0345367/#jump-2018devices) | [2019](https://android.gadgethacks.com/how-to/list-googles-internal-code-names-for-every-pixel-device-ever-0345367/#jump-2019devices) | [2020](https://android.gadgethacks.com/how-to/list-googles-internal-code-names-for-every-pixel-device-ever-0345367/#jump-2020devices)**

Codenames become very important when you're dealing with [custom ROMs](https://android.gadgethacks.com/how-to/twrp-101-install-custom-rom-0167655/) and root mods. The numerals in friendly names like "Pixel 2" could cause problems if they were used in software code or file names. Something simple with no spaces, no numbers, and no special characters works best, so that's the name you'll need to know in order to download the right files for your device.

You could even cite a trickle-down effect here, as the codenames used in the modding community for a device typically get adopted by frequenters of the gadget's various forums, such as XDA, Reddit, and Google Groups. So knowing your Pixel's code name is effectively a gateway to better support.

### 2013 Devices

- **Chromebook Pixel:** [Link](https://www.chromium.org/chromium-os/developer-information-for-chrome-os-devices)

### 2015 Devices

- **Chromebook Pixel:** [Samus](https://www.chromium.org/chromium-os/developer-information-for-chrome-os-devices)
- **Pixel C:** [Ryu](https://developers.google.com/android/images#ryu)

### 2016 Devices

- **Pixel:** [Sailfish](https://source.android.com/setup/build/running#booting-into-fastboot-mode)
- **Pixel XL:** [Marlin](https://android.googlesource.com/device/google/marlin/)

### 2017 Devices

- **Pixel 2:** [Walleye](https://source.android.com/setup/build/running#booting-into-fastboot-mode)
- **Pixel 2 XL:** [Taimen](https://android.googlesource.com/device/google/taimen/)
- **Pixelbook:** [Eve](https://www.chromium.org/chromium-os/developer-information-for-chrome-os-devices)

### 2018 Devices

- **Pixel 3:** [Blueline](https://source.android.com/setup/build/running#booting-into-fastboot-mode)
- **Pixel 3 XL:** [Crosshatch](https://android.googlesource.com/device/google/crosshatch/)
- **Pixel Slate:** [Nocturne](https://www.chromium.org/chromium-os/developer-information-for-chrome-os-devices)

### 2019 Devices

- **Pixel 3a:** [Sargo](https://source.android.com/setup/build/running#booting-into-fastboot-mode)
- **Pixel 3a XL:** [Bonito](https://android.googlesource.com/device/google/bonito/)
- **Pixel 4:** [Flame](https://developers.google.com/android/images#flame)
- **Pixel 4 XL:** [Coral](https://android.googlesource.com/device/google/coral/)
- **Pixelbook Go:** [Atlas](https://www.chromium.org/chromium-os/developer-information-for-chrome-os-devices)

### 2020 Devices

- **Pixel 4a:** [Sunfish](https://android.googlesource.com/device/google/sunfish/)
- **Pixel 4a 5G:** [Bramble](https://android.googlesource.com/device/google/bramble/)
- **Pixel 5:** [Redfin](https://android.googlesource.com/device/google/redfin/)



# 10. Flash and Build Android for Pixel 4XL

## 10.1 Flash Factory Image

### Download factory image for pixel 4XL of android 11

Go to page https://developers.google.com/android/images and select RQ3A.211001.001 to download

| 11.0.0 (RQ3A.211001.001, Oct 2021) | [Flash](https://flash.android.com/build/7641976?target=coral-user&signed) | [Link](https://dl.google.com/dl/android/aosp/coral-rq3a.211001.001-factory-c086a4c3.zip) |
| ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |

Search Build Tag -> android-11.0.0_r46

https://source.android.google.cn/setup/start/build-numbers

| RQ3A.211001.001 | android-11.0.0_r46 | Android11 | Pixel 3, Pixel 3 XL, Pixel 3a, Pixel 3a XL, Pixel 4, Pixel 4 XL, Pixel 4a, Pixel 4a (5G), Pixel 5 | 2021-10-01 |
| --------------- | ------------------ | --------- | ------------------------------------------------------------ | ---------- |

Driver Binaries:

### Pixel 4 XL binaries for Android 11.0.0 (RQ3A.211001.001)

| Hardware Component                                          | Company  | Download                                                     | SHA-256 Checksum                                             |
| :---------------------------------------------------------- | :------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| Vendor image                                                | Google   | [Link](https://dl.google.com/dl/android/aosp/google_devices-coral-rq3a.211001.001-a802c980.tgz) | 12c7396bdd4b3e3af839d6f18de1e835613956983a6d39fcca939c63aa5c4264 |
| GPS, Audio, Camera, Gestures, Graphics, DRM, Video, Sensors | Qualcomm | [Link](https://dl.google.com/dl/android/aosp/qcom-coral-rq3a.211001.001-2955f6f2.tgz) | b684d04899ad654c4bd64932fb5db10f8442337088b5e2c20af7f7eb5dc87818 |



### Flash all image

To flash a system image:

1) Download the appropriate system image for your device below, then unzip it to a safe directory.

2) Connect your device to your computer over USB.

3) Start the device in fastboot mode with one of the following methods:

   * Using the [adb tool](http://developer.android.com/tools/help/adb.html): With the device powered on, execute:

   ```
   adb reboot bootloader
   ```

   - Using a key combo: Turn the device off, then turn it on and immediately hold down the relevant [key combination](https://source.android.com/source/running#booting-into-fastboot-mode) for your device.

4) If necessary, unlock the device's bootloader using one of the following methods:

   - If you are updating a Nexus or Pixel device that is manufactured in 2015 or later (for example, a Nexus 5X, Nexus 6P, Pixel, Pixel XL, Pixel 2 or Pixel 2 XL device), run this command:

     ```
     fastboot flashing unlock
     ```

   **Note:** the 'flashing unlock' command is only available with fastboot version 23.0.1 or later. The latest available version of fastboot can be downloaded from [SDK Platform Tools](https://developer.android.com/studio/releases/platform-tools.html).

   - For Pixel 2: To flash the bootloader, Pixel 2's boot loader must be updated to at least Oreo MR1's version first. This may be done by applying an over-the-air (OTA) update, or sideloading a [full OTA](https://developers.google.com/android/ota) with the instructions on that page.

   - For Pixel 2 **XL only** with loader version prior to TMZ20a: the critical partitions may also need to be unlocked before flashing. The unlock can be performed with this command, and should NOT be done on other devices:

     ```
     fastboot flashing unlock_critical
     ```

   - If you are updating an older device, run this command:

     ```
     fastboot oem unlock
     ```

   The target device will show you a confirmation screen. (This erases all data on the target device.)

   See [Unlocking the bootloader](https://source.android.com/source/running#unlocking-the-bootloader) for more detailed instructions.

5) Open a terminal and navigate to the unzipped system image directory.

6) Execute the `flash-all` script. This script installs the necessary bootloader, baseband firmware(s), and operating system.



## 10.2 Flash OTA



## 10.3 Build AOSP 11 for PIXEL 4XL

### 10.3.1 Source Code Download

1)  Create work folder

   ```
   $ mkdir android
   $ cd android
   ```

2) Init repo and sync

   ```
   //download from google site
   $ repo init -u https://android.googlesource.com/platform/manifest
   $ repo sync -j4
   
   //download from ustc mirror if you can't access google repos
   $ export REPO_URL = 'https://gerrit-googlesource.proxy.ustclug.org/git-repo'
   $ repo init -u git://mirrors.ustc.edu.cn/aosp/platform/manifest -b android-11.0.0_r46
   $ repo sync -j4
   
   or using a shell to loop sync - repo.sh as below:
   #####
   #!/bin/bash
   repo sync -j4
   while [ $? -ne 0 ]
   do
   echo "======sync failed ,re-sync again======"
   sleep 3
   repo sync -j4
   done
   
   ```

3) Device and vendor code download

   https://developers.google.com/android/drivers

   Device driver:

   https://dl.google.com/dl/android/aosp/google_devices-coral-rq3a.211001.001-a802c980.tgz

   Vendor driver:

   https://dl.google.com/dl/android/aosp/qcom-coral-rq3a.211001.001-2955f6f2.tgz

   ```
   $ cd android
   $ wget https://dl.google.com/dl/android/aosp/qcom-coral-rq3a.211001.001-2955f6f2.tgz
   $ zxvf qcom-coral-rq3a.211001.001-2955f6f2.tgz
   $ extract-qcom-coral.sh
   vendor/
   vendor/qcom/
   vendor/qcom/coral/
   vendor/qcom/coral/LICENSE
   vendor/qcom/coral/BoardConfigPartial.mk
   vendor/qcom/coral/proprietary/
   vendor/qcom/coral/proprietary/libimsmedia_jni.so
   vendor/qcom/coral/proprietary/ims.apk
   vendor/qcom/coral/proprietary/lib64/
   vendor/qcom/coral/proprietary/lib64/libimsmedia_jni.so
   vendor/qcom/coral/proprietary/lib64/libmmosal.so
   vendor/qcom/coral/proprietary/lib64/libmdsprpc_system.so
   vendor/qcom/coral/proprietary/lib64/libsdsprpc_system.so
   vendor/qcom/coral/proprietary/lib64/libadsprpc_system.so
   vendor/qcom/coral/proprietary/lib64/libdiag_system.so
   vendor/qcom/coral/proprietary/lib64/libcdsprpc_system.so
   vendor/qcom/coral/proprietary/Android.bp
   vendor/qcom/coral/proprietary/com.qualcomm.qti.uceservice-V2.0-java.jar
   vendor/qcom/coral/proprietary/vendor.qti.hardware.alarm-V1.0-java.jar
   vendor/qcom/coral/proprietary/libmmosal.so
   vendor/qcom/coral/proprietary/qti-telephony-hidl-wrapper.jar
   vendor/qcom/coral/proprietary/libmdsprpc_system.so
   vendor/qcom/coral/proprietary/libsdsprpc_system.so
   vendor/qcom/coral/proprietary/QtiTelephonyService.apk
   vendor/qcom/coral/proprietary/com.qualcomm.qcrilmsgtunnel.xml
   vendor/qcom/coral/proprietary/vendor.qti.ims.callinfo-V1.0-java.jar
   vendor/qcom/coral/proprietary/qti_telephony_utils.xml
   vendor/qcom/coral/proprietary/qti-telephony-utils.jar
   vendor/qcom/coral/proprietary/qti_telephony_hidl_wrapper.xml
   vendor/qcom/coral/proprietary/libadsprpc_system.so
   vendor/qcom/coral/proprietary/vendor.qti.hardware.data.latency-V1.0-java.jar
   vendor/qcom/coral/proprietary/libdiag_system.so
   vendor/qcom/coral/proprietary/qcrilhook.xml
   vendor/qcom/coral/proprietary/qcrilhook.jar
   vendor/qcom/coral/proprietary/org_codeaurora_ims.xml
   vendor/qcom/coral/proprietary/libcdsprpc_system.so
   vendor/qcom/coral/proprietary/vendor.qti.voiceprint-V1.0-java.jar
   vendor/qcom/coral/proprietary/qcrilmsgtunnel.apk
   vendor/qcom/coral/proprietary/Android.mk
   vendor/qcom/coral/device-partial.mk
   vendor/google_devices/
   vendor/google_devices/coral/
   vendor/google_devices/coral/android-info.txt
   vendor/google_devices/coral/proprietary/
   vendor/google_devices/coral/proprietary/BoardConfigVendor.mk
   vendor/google_devices/coral/proprietary/device-vendor.mk
   
   Files extracted successfully.
   
   $ wget https://dl.google.com/dl/android/aosp/google_devices-coral-rq3a.211001.001-a802c980.tgz
   $ zxvf google_devices-coral-rq3a.211001.001-a802c980.tgz
   $ extract-google_devices-coral.sh
   vendor/
   vendor/google_devices/
   vendor/google_devices/coral/
   vendor/google_devices/coral/android-info.txt
   vendor/google_devices/coral/LICENSE
   vendor/google_devices/coral/BoardConfigPartial.mk
   vendor/google_devices/coral/proprietary/
   vendor/google_devices/coral/proprietary/bootloader.img
   vendor/google_devices/coral/proprietary/BoardConfigVendor.mk
   vendor/google_devices/coral/proprietary/radio.img
   vendor/google_devices/coral/proprietary/vendor.img
   vendor/google_devices/coral/proprietary/device-vendor.mk
   vendor/google_devices/coral/proprietary/Android.mk
   vendor/google_devices/coral/device-partial.mk
   
   Files extracted successfully.
   ```

4) a

### 10.3.2 Build

```
$ source build/envsetup.sh
$ lunch aosp_coral-userdebug
$ make -j32
```

### 10.3.3 Flash image

Flash on Windows

```
> adb reboot bootloader
> cd C:\Android\pixel4xl\out\target\product\coral
> set ANDROID_PRODUCT_OUT=.\
> fastboot flashall -w
```



## 10.4 Build Kernel



# 90. FAQ

## 90.1 Android ADB devices unauthorized

**Question:**

```
>adb devices
* daemon not running; starting now at tcp:5037
* daemon started successfully
List of devices attached
8ABX0Q0Q4       unauthorized
```

***Answer:***

Thankgod xda developers exist : http://forum.xda-developers.com/verizon-lg-g3/help/unable-to-access-adb-t2830087

Just had to delete adbkey file in C:Users/$Name/.android adbkey.pub was missing.

Restart after this and both files are there.

If this does not work : - Try Revoke USB DEBUGGING Authorization. - Enable USB debugging again.

Ref: [Android ADB devices unauthorized](https://stackoverflow.com/questions/31638582/android-adb-devices-unauthorized)



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
* 24) [Pixel 3上Android 11源码下载，编译与烧录](https://hqw700.github.io/2021/01/01/aosp-build/)
* 25) [Soong Build System](https://source.android.com/setup/build)
* 26) [Driver Binaries for Nexus and Pixel Devices](https://developers.google.com/android/drivers)
* 27) [macos pixel3的aosp下载、编译及刷机](https://www.jianshu.com/p/0505194069c6)
* 28) [AOSP on Pixel3 running Mainline kernel](https://wiki.linaro.org/AOSP/blueline)

