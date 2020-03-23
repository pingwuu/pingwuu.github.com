---
layout: post
title:  "Yocto Basic Usage"
date:   2019-12-04 11:30:00 +0800
categories: yocto
comments: true
---

# 1. Yocto usage



## x.x Rebuild package

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

*  Once you are done with either of these clean, which ever suits you, you can simple give build command for the specified: 

  ```
  $ bitbake gstreamer
  ```

  

# 2. UUU usage



# 99. Reference URL

* [Using “uuu” to flash eMMC]( https://www.technexion.com/support/knowledgebase/using-uuu-to-flash-emmc/ )
* [How to use UUU to flash the iMX boards]( https://imxdev.gitlab.io/tutorial/How_to_use_UUU_to_flash_the_iMX_boards/ )
* [How to using local repo instead of remote on yocto project]( https://blog.csdn.net/sy373466062/article/details/50363537 )
* [Including Custom Executables and Libraries in Your Embedded Linux Image with Yocto](https://dornerworks.com/blog/including-custom-executables-and-libraries-in-your-linux-image-with-yocto)

