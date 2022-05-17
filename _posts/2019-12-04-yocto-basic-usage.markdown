---
layout: post
title:  "Yocto Basic Usage"
date:   2019-12-04 11:30:00 +0800
categories: yocto
comments: true
---

**Table of Content**

- [1. Yocto usage](#1-yocto-usage)
  * [1.1 Rebuild package](#11-rebuild-package)
  * [1.2 Custom Yocto](#12-custom-yocto)
    + [1.2.1 Add custom layer](#121-add-custom-layer)
- [2. UUU usage](#2-uuu-usage)
- [99. Reference URL](#99-reference-url)



# 1. Yocto usage

## 1.1 Rebuild package

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




## 1.2 Custom Yocto

### 1.2.1 Add custom layer

* Prerequisites

  Compile a reference image for the Yocto Project

```
# cd <BSP_DIR>/sources  
# bitbake-layer create <NEW_LAYER_NAME> 
```



# 2. UUU usage



# 99. Reference URL

* [Using “uuu” to flash eMMC]( https://www.technexion.com/support/knowledgebase/using-uuu-to-flash-emmc/ )
* [How to use UUU to flash the iMX boards]( https://imxdev.gitlab.io/tutorial/How_to_use_UUU_to_flash_the_iMX_boards/ )
* [How to using local repo instead of remote on yocto project]( https://blog.csdn.net/sy373466062/article/details/50363537 )
* [Including Custom Executables and Libraries in Your Embedded Linux Image with Yocto](https://dornerworks.com/blog/including-custom-executables-and-libraries-in-your-linux-image-with-yocto)

