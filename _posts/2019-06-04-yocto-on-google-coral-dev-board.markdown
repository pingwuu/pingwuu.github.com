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



# 99. Reference URL

* [https://mkrak.org/2019/05/23/running-a-yocto-generated-distribution-on-google-coral-dev-board/](https://mkrak.org/2019/05/23/running-a-yocto-generated-distribution-on-google-coral-dev-board/)
* [https://antmicro.com/blog/2019/04/google-coral/](https://antmicro.com/blog/2019/04/google-coral/)
* [imx-manifest Readme](https://source.codeaurora.org/external/imx/imx-manifest/tree/README?h=imx-linux-rocko)
* [Linux L4.9.88_2.0.0 Rocko, i.MX7ULP1 Linux/SDK2.4 RFP(GA) Release Announcement](https://community.nxp.com/docs/DOC-340805)
* [i.MX_Yocto_Project_User's_Guide](/static/files/imx-yocto-L4.14.98_2.0.0_ga/i.MX_Yocto_Project_User's_Guide.pdf)
