---
layout: post 
title:  "FPGA Basic Usage"
date:   2023-12-05 12:00:00 +0800
categories: fpga
comments: true
---

**Table of Content**
- [1. Toolchain setup](#1-toolchain-setup)
  - [1.1 install python](#11-install-python)
  - [1.2 Install apio with the following command:](#12-install-apio-with-the-following-command)
  - [1.3 Install Tool Suite](#13-install-tool-suite)
- [2. Upload examples](#2-upload-examples)
  - [2.1 list available examples](#21-list-available-examples)
  - [2.2 Create the icestick/leds example (copy from examples)](#22-create-the-icestickleds-example-copy-from-examples)
  - [2.3 build and upload to board](#23-build-and-upload-to-board)
- [99. Reference Link](#99-reference-link)

# 1. Toolchain setup
## 1.1 install python
Version : python-3.9.0-amd64.exe

## 1.2 Install apio with the following command:
```
> python -m pip install apio==0.8.1
```

## 1.3 Install Tool Suite
```
> apio install --all --platform windows_amd64

> apio install drivers
```

# 2. Upload examples
## 2.1 list available examples
```
> mkdir d:\apio
> cd apio

 apio > apio examples -l

Alhambra-II\Blinky
-----------------------------------------------------------------------------------------------------------------------------------------------------
 Blinking LED 7

 ......

To get an example, use the command:
   apio examples -d/-f name

Example of use:
   apio examples -f leds
Copy the leds example files to the current directory

```

## 2.2 Create the icestick/leds example (copy from examples)
```
apio > apio examples -d icestick\leds
> cd icestick/leds
> apio verify
> apio sim
```

## 2.3 build and upload to board
```
> cd icestick/leds
> apio build
> apio upload
```

# 99. Reference Link

* [https://github.com/FPGAwars/apio/wiki/Quick-start#apio-installation](https://github.com/FPGAwars/apio/wiki/Quick-start#apio-installation)

* [https://github.com/FPGAwars/apio/issues/305](https://github.com/FPGAwars/apio/issues/305)
