---
layout: post
title:  "Yocto on Google Coral Dev Board"
date:   2019-06-04 16:55:00 +0800
categories: yocto coral tpu edge linux u-boot
comments: true
---

# 1. Update build Environment

```
$ sudo apt-get install git-core build-essential curl chrpath gawk texinfo

```

# 2. Install repo

```
$ mkdir ~/bin
$ curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo

// Please using tsinghua as mirror if you can not access googleapis and add REPO_URL to you .bashrc file
$ curl https://mirrors.tuna.tsinghua.edu.cn/git/git-repo  > ~/bin/repo

$ export REPO_URL='https://mirrors.tuna.tsinghua.edu.cn/git/git-repo/'

$ chmod a+x ~/bin/repo
```

# 3. Configure git

```
$ git config --global user.name "Your Name"
$ git config --global user.email you@example.com
```

# 4. Init repo manifest & build

```
$ mkdir coral && cd coral

// Initialize repo manifest
$ repo init -u https://github.com/Freescale/fsl-community-bsp-platform -b thud

// Fetch layers in manifest
$ repo sync -j4

// Clone meta-coral
$ git clone https://github.com/mirzak/meta-coral.git sources/meta-coral

//Setup the environment
$ MACHINE=coral-dev DISTRO=fslc-wayland source ./setup-environment build

// Add the meta-coral layer to bblayers.conf:
$ echo 'BBLAYERS += "${BSPDIR}/sources/meta-coral"' >> conf/bblayers.conf

// Start bitbaking:
$ bitbake core-image-baseit

//list core-image-base all task 
$ bitbake -c listtasks core-image-base

// download all source only 
$ bitbake -c fetchall core-image-base

```

Note:

```
If you encounter any certification trouble after having run repo init,
"
fatal: Cannot get https://gerrit.googlesource.com/git-repo/clone.bundle
fatal: error [SSL: CERTIFICATE_VERIFY_FAILED] certificate verify failed (_ssl.c:590)
"
disable python certification check: "export PYTHONHTTPSVERIFY=0"
```

```
If you meet below error:
| cp: cannot stat ‘/home/vmuser/projects/coral/build/tmp/deploy/images/coral-dev/imx-boot-tools/u-boot-nodtb.bin’: No such file or directory
| WARNING: exit code 1 from a shell command.
| ERROR: Function failed: do_compile (log file is located at 

 The quick workaround is just to run:
$ bitbake -c cleansstate u-boot
$ bitbake -c cleansstate imx-boot
$ bitbake u-boot
$ bitbake imx-boot
```



# 5. For zeus branch

Ref URL:https://hub.mender.io/t/google-coral-dev-board/1711/12

```
$ mkdir mender-coral && cd mender-coral

$ repo init -u https://github.com/mendersoftware/meta-mender-community \
           -m meta-mender-coral/scripts/manifest-coral.xml \
           -b zeus
$ repo sync

$ repo sync

$ . setup-environment coral

$ bitbake core-image-minimal
```





# x. Get and Build the ARM Trusted firmware

```
Get ATF from: https://source.codeaurora.org/external/imx/imx-atf
branch: imx_4.19.35_1.0.0
$ source /opt/fsl-imx-wayland/5.4-zeus/environment-setup-aarch64-poky-linux
$ $ LDFLAGS="" CC="$CC" make PLAT=imx8mq bl31
$ cp build/imx8mq/release/bl31.bin u-boot/$(builddir)
```



# x. Get the ddr and hdmi firmware

```
$ wget https://www.nxp.com/lgfiles/NMG/MAD/YOCTO/firmware-imx-7.9.bin
$ chmod +x firmware-imx-7.9.bin
$ ./firmware-imx-7.9.bin
$ cp firmware-imx-7.9/firmware/hdmi/cadence/signed_hdmi_imx8m.bin $(builddir)
$ cp firmware-imx-7.9/firmware/ddr/synopsys/lpddr4*.bin $(builddir)
```





Boot Mode

```
Switch1 	Switch2 	Switch3 	Switch4
Off			On			Don't Care	Don't Care	---> Serial Download
On			Off			Off			Off			---> eMMC
On			Off			On			On			---> SD Card
```





boot from u-boot console

printenv

```
u-boot=> printenv
baudrate=115200
board_name=Google i.MX8MQ Phanbell
board_rev=iMX8MQ
boot_fdt=try
bootcmd=mmc dev ${mmcdev}; if mmc rescan; then if run loadbootscript; then run bootscript; else if run loadimage; then run mmcboot; else run netboot; fi; fi; else booti ${loadaddr} - ${fdt_addr}; fi
bootcmd_mfg=run mfgtool_args;if iminfo ${initrd_addr}; then if test ${tee} = yes; then bootm ${tee_addr} ${initrd_addr} ${fdt_addr}; else booti ${loadaddr} ${initrd_addr} ${fdt_addr}; fi; else echo "Run fastboot ..."; fastboot 0; fi;
bootdelay=2
bootscript=echo Running bootscript from mmc ...; source
console=ttymxc0,115200
emmc_dev=0
ethprime=FEC
fastboot_dev=mmc0
fdt_addr=0x43000000
fdt_file=imx8mq-evk.dtb
fdt_high=0xffffffffffffffff
fdtcontroladdr=7f11c428
image=Image
initrd_addr=0x43800000
initrd_high=0xffffffffffffffff
jh_clk=
jh_mmcboot=setenv fdt_file imx8mq-evk-root.dtb; setenv jh_clk clk_ignore_unused; if run loadimage; then run mmcboot; else run jh_netboot; fi;
jh_netboot=setenv fdt_file imx8mq-evk-root.dtb; setenv jh_clk clk_ignore_unused; run netboot;
kboot=booti
loadaddr=0x40480000
loadbootscript=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};
loadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}
loadimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${image}
mfgtool_args=setenv bootargs console=${console},${baudrate} rdinit=/linuxrc clk_ignore_unused
mmcargs=setenv bootargs ${jh_clk} console=${console} root=${mmcroot}
mmcautodetect=yes
mmcboot=echo Booting from mmc ...; run mmcargs; if test ${boot_fdt} = yes || test ${boot_fdt} = try; then if run loadfdt; then booti ${loadaddr} - ${fdt_addr}; else echo WARN: Cannot load the DT; fi; else echo wait for boot; fi;
mmcdev=0
mmcpart=1
mmcroot=/dev/mmcblk0p2 rootwait rw
nandfit_part=yes
netargs=setenv bootargs ${jh_clk} console=${console} root=/dev/nfs ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp
netboot=echo Booting from net ...; run netargs;  if test ${ip_dyn} = yes; then setenv get_cmd dhcp; else setenv get_cmd tftp; fi; ${get_cmd} ${loadaddr} ${image}; if test ${boot_fdt} = yes || test ${boot_fdt} = try; then if ${get_cmd} ${fdt_addr} ${fdt_file}; then booti ${loadaddr} - ${fdt_addr}; else echo WARN: Cannot load the DT; fi; else booti; fi;
script=boot.scr
sd_dev=1
serial#=0a1181d6f32ef62a
soc_type=imx8mq
splashimage=0x50000000

Environment size: 2328/4092 bytes

```



```
u-boot=> run loadimage
28013056 bytes read in 188 ms (142.1 MiB/s)
u-boot=> run loadfdt
45463 bytes read in 12 ms (3.6 MiB/s)
u-boot=> booti ${loadaddr} - ${fdt_addr}
## Flattened Device Tree blob at 43000000
   Booting using the fdt blob at 0x43000000
   Using Device Tree in place at 0000000043000000, end 000000004300e196

Starting kernel ...

```



```
u-boot=> run mmcargs
u-boot=> test ${boot_fdt}
u-boot=>
u-boot=> test ${boot_fdt}
u-boot=> echo ${boot_fdt}
try
u-boot=> run loadfdt
45463 bytes read in 12 ms (3.6 MiB/s)
u-boot=> booti  ${loadaddr} - ${fdt_addr}
Bad Linux ARM64 Image magic!
u-boot=> run loadimage
28013056 bytes read in 188 ms (142.1 MiB/s)
u-boot=> booti  ${loadaddr} - ${fdt_addr}

```



//emmc boot ok using below command:

```
run mmcargs

or
========
setenv bootargs ${jh_clk} console=${console} root=${mmcroot}
setenv bootargs console=${console} root=${mmcroot}
setenv bootargs console=${console}	//VFS: Cannot open root device "(null)" or unknown-block(0,0): error -6

run loadimage
run loadfdt
booti  ${loadaddr} - ${fdt_addr}
```





```
$ DISTRO=fsl-imx-wayland MACHINE=imx8mqea-com source ea-setup-release.sh -b build

$ bitbake core-image-minimal

```







# 99. Reference URL

* [https://mkrak.org/2019/05/23/running-a-yocto-generated-distribution-on-google-coral-dev-board/](https://mkrak.org/2019/05/23/running-a-yocto-generated-distribution-on-google-coral-dev-board/)
* [https://antmicro.com/blog/2019/04/google-coral/](https://antmicro.com/blog/2019/04/google-coral/)
* [imx-manifest Readme](https://source.codeaurora.org/external/imx/imx-manifest/tree/README?h=imx-linux-rocko)
* [Linux L4.9.88_2.0.0 Rocko, i.MX7ULP1 Linux/SDK2.4 RFP(GA) Release Announcement](https://community.nxp.com/docs/DOC-340805)
* [i.MX_Yocto_Project_User's_Guide](/static/files/imx-yocto-L4.14.98_2.0.0_ga/i.MX_Yocto_Project_User's_Guide.pdf)
* [Update or flash the Dev Board](https://coral.ai/docs/dev-board/reflash/#update-your-board-with-apt-get)
* [Getting Started with Mendel Linux](https://coral.googlesource.com/docs/+/refs/heads/master/GettingStarted.md)
* 
