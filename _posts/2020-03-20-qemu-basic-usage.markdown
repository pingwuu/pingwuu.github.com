---

layout: post
title:  "Qemu Basic Usage"
date:   2020-03-20 23:55:00 +0800
categories: qemu linux u-boot buildroot
comments: true
---

# 1. Buildroot for Qemu Env

For simply, we using buildroot to build u-boot, kernel, rootfs and qemu.

## 1.1 qemu for arm vexpress board

```
//clone buildroot
$ git clone git://git.buildroot.net/buildroot
$ cd buildroot
//make config
$ make qemu_arm_vexpress_defconfig
//build
$ make -jN  //N indicate your pc cores number

or build with enable-sdl
$ time make BR2_JLEVEL="$(nproc)" HOST_QEMU_OPTS='--enable-sdl --enable-sdl-image'

or build with enable-sdl and only for arm target
$ time make BR2_JLEVEL="$(nproc)" HOST_QEMU_OPTS='--target-list="arm-softmmu arm-linux-user" --enable-sdl --enable-kvm --enable-tools --disable-curl'

//run qemu
Run the emulation without graphic:
$ output/host/usr/bin/qemu-system-arm -M vexpress-a9 -smp 1 -m 256 \
  -kernel output/images/zImage \
  -dtb output/images/vexpress-v2p-ca9.dtb \
  -drive file=output/images/rootfs.ext2,if=sd,format=raw \
  -append "console=ttyAMA0,115200 rootwait root=/dev/mmcblk0" \
  -serial stdio -net nic,model=lan9118 -net user

//Run the emulation with SDL Display:
$ output/host/usr/bin/qemu-system-arm -M vexpress-a9 -smp 2 -m 256 \
  -kernel output/images/zImage \
  -dtb output/images/vexpress-v2p-ca9.dtb \
  -drive file=output/images/rootfs.ext2,if=sd,format=raw \
  -append "console=ttyAMA0,115200 rootwait root=/dev/mmcblk0" \
  -display sdl \
  -serial stdio -net nic,model=lan9118 -net user

The login prompt will appear in the terminal that started Qemu. The
graphical window is the framebuffer.

If you want to emulate more cores change "-smp 1" to "-smp 2" for
dual-core or even "smp -4" for a quad-core configuration.
```



## 1.1 qemu for freescale imx6ulevk board

```
$ git clone https://gitee.com/pingwuu/buildroot.git
$ cd buildroot

//make config
$ make qemu_imx6ulevk_defconfig
$ make -j8

//run qemu withou graphic UI
$ output/host/usr/bin/qemu-system-arm \
-M mcimx6ul-evk \
-m 512M \
-dtb output/images/imx6ul-14x14-evk.dtb \
-kernel output/images/zImage \
-drive  file=output/images/rootfs.ext4,format=raw,id=mysdcard -device sd-card,drive=mysdcard \
-append "console=ttymxc0,115200 rootfstype=ext4 root=/dev/mmcblk1 rw rootwait init=/sbin/init  loglevel=8" \
-nographic -serial mon:stdio \
-nic user
```

In order run imx6ul board under qemu, need modify imx6ul-14x14.dts as below

```
// SPDX-License-Identifier: GPL-2.0
//
// Copyright (C) 2015 Freescale Semiconductor, Inc.

/dts-v1/;

#include "imx6ul.dtsi"
#include "imx6ul-14x14-evk.dtsi"

/ {
	model = "Freescale i.MX6 UltraLite 14x14 EVK Board";
	compatible = "fsl,imx6ul-14x14-evk", "fsl,imx6ul";
};

&can1 {
	pinctrl-names = "default";
	pinctrl-0 = <&pinctrl_flexcan1>;
	xceiver-supply = <&reg_can_3v3>;
	status = "disabled";
};

&can2 {
	pinctrl-names = "default";
	pinctrl-0 = <&pinctrl_flexcan2>;
	xceiver-supply = <&reg_can_3v3>;
	status = "disabled";
};

&pwm1 {
	pinctrl-names = "default";
	pinctrl-0 = <&pinctrl_pwm1>;
	status = "disabled";
};

```

```
//buildroot qemu + nxp imx6ul kernel + 100askrootfs ok
output/host/usr/bin/qemu-system-arm \
 -M mcimx6ul-evk \
 -m 512M \
-kernel output/images/zImage \
-dtb output/images/imx6ul-14x14-evk.dtb \
 -nographic -serial mon:stdio \
 -drive  file=output/images/rootfs.img,format=raw,id=mysdcard -device sd-card,drive=mysdcard \
 -append "console=ttymxc0,115200 rootfstype=ext4 root=/dev/mmcblk1  rw rootwait init=/sbin/init  loglevel=8" \
 -nic user
```

```
//initram fs
$ output/host/usr/bin/qemu-system-arm \
-M mcimx6ul-evk \
-kernel output/images/zImage \
-no-reboot -initrd output/images/rootfs.ext4 \
-m 256 -display none -serial null \
--append 'rdinit=/sbin/init earlycon=ec_imx6q,mmio,0x21e8000,115200n8 console=ttymxc0,115200' \
-dtb output/images/imx6ul-14x14-evk.dtb \
-nographic -monitor null -serial stdio
```





# 2. Buildroot useful command

1)  Rebuild specify package

```
//config linux kernel
$ make linux-menuconfig

//rebuild linux kernel
$ make linux-rebuild
```





# 3. QEMU Build option

1) Qemu --help

```

```

2) Disable binfmt_misc

```
echo 0 > /proc/sys/fs/binfmt_misc/qemu-arm
```



1) Qemu configure option

```
$ ./configure  --help

Usage: configure [options]
Options: [defaults in brackets after descriptions]

Standard options:
  --help                   print this message
  --prefix=PREFIX          install in PREFIX [/usr/local]
  --interp-prefix=PREFIX   where to find shared libraries, etc.
                           use %M for cpu name [/usr/gnemul/qemu-%M]
  --target-list=LIST       set target list (default: build everything)
                           Available targets: aarch64-softmmu alpha-softmmu 
                           arm-softmmu cris-softmmu hppa-softmmu i386-softmmu 
                           lm32-softmmu m68k-softmmu microblaze-softmmu 
                           microblazeel-softmmu mips-softmmu mips64-softmmu 
                           mips64el-softmmu mipsel-softmmu moxie-softmmu 
                           nios2-softmmu or1k-softmmu ppc-softmmu ppc64-softmmu 
                           riscv32-softmmu riscv64-softmmu s390x-softmmu 
                           sh4-softmmu sh4eb-softmmu sparc-softmmu 
                           sparc64-softmmu tricore-softmmu unicore32-softmmu 
                           x86_64-softmmu xtensa-softmmu xtensaeb-softmmu 
                           aarch64-linux-user aarch64_be-linux-user 
                           alpha-linux-user arm-linux-user armeb-linux-user 
                           cris-linux-user hppa-linux-user i386-linux-user 
                           m68k-linux-user microblaze-linux-user 
                           microblazeel-linux-user mips-linux-user 
                           mips64-linux-user mips64el-linux-user 
                           mipsel-linux-user mipsn32-linux-user 
                           mipsn32el-linux-user nios2-linux-user 
                           or1k-linux-user ppc-linux-user ppc64-linux-user 
                           ppc64abi32-linux-user ppc64le-linux-user 
                           riscv32-linux-user riscv64-linux-user 
                           s390x-linux-user sh4-linux-user sh4eb-linux-user 
                           sparc-linux-user sparc32plus-linux-user 
                           sparc64-linux-user tilegx-linux-user 
                           x86_64-linux-user xtensa-linux-user 
                           xtensaeb-linux-user
  --target-list-exclude=LIST exclude a set of targets from the default target-list

Advanced options (experts only):
  --cross-prefix=PREFIX    use PREFIX for compile tools []
  --cc=CC                  use C compiler CC [cc]
  --iasl=IASL              use ACPI compiler IASL [iasl]
  --host-cc=CC             use C compiler CC [cc] for code run at
                           build time
  --cxx=CXX                use C++ compiler CXX [c++]
  --objcc=OBJCC            use Objective-C compiler OBJCC [cc]
  --extra-cflags=CFLAGS    append extra C compiler flags QEMU_CFLAGS
  --extra-cxxflags=CXXFLAGS append extra C++ compiler flags QEMU_CXXFLAGS
  --extra-ldflags=LDFLAGS  append extra linker flags LDFLAGS
  --cross-cc-ARCH=CC       use compiler when building ARCH guest test cases
  --cross-cc-flags-ARCH=   use compiler flags when building ARCH guest tests
  --make=MAKE              use specified make [make]
  --install=INSTALL        use specified install [install]
  --python=PYTHON          use specified python [python3]
  --smbd=SMBD              use specified smbd [/usr/sbin/smbd]
  --with-git=GIT           use specified git [git]
  --static                 enable static build [no]
  --mandir=PATH            install man pages in PATH
  --datadir=PATH           install firmware in PATH/qemu
  --docdir=PATH            install documentation in PATH/qemu
  --bindir=PATH            install binaries in PATH
  --libdir=PATH            install libraries in PATH
  --libexecdir=PATH        install helper binaries in PATH
  --sysconfdir=PATH        install config in PATH/qemu
  --localstatedir=PATH     install local state in PATH (set at runtime on win32)
  --firmwarepath=PATH      search PATH for firmware files
  --with-confsuffix=SUFFIX suffix for QEMU data inside datadir/libdir/sysconfdir [/qemu]
  --with-pkgversion=VERS   use specified string as sub-version of the package
  --enable-debug           enable common debug build options
  --enable-sanitizers      enable default sanitizers
  --disable-strip          disable stripping binaries
  --disable-werror         disable compilation abort on warning
  --disable-stack-protector disable compiler-provided stack protection
  --audio-drv-list=LIST    set audio drivers list:
                           Available drivers: oss alsa sdl pa
  --block-drv-whitelist=L  Same as --block-drv-rw-whitelist=L
  --block-drv-rw-whitelist=L
                           set block driver read-write whitelist
                           (affects only QEMU, not qemu-img)
  --block-drv-ro-whitelist=L
                           set block driver read-only whitelist
                           (affects only QEMU, not qemu-img)
  --enable-trace-backends=B Set trace backend
                           Available backends: dtrace ftrace log simple syslog ust
  --with-trace-file=NAME   Full PATH,NAME of file to store traces
                           Default:trace-<pid>
  --disable-slirp          disable SLIRP userspace network connectivity
  --enable-tcg-interpreter enable TCG with bytecode interpreter (TCI)
  --enable-malloc-trim     enable libc malloc_trim() for memory optimization
  --oss-lib                path to OSS library
  --cpu=CPU                Build for host CPU [x86_64]
  --with-coroutine=BACKEND coroutine backend. Supported options:
                           ucontext, sigaltstack, windows
  --enable-gcov            enable test coverage analysis with gcov
  --gcov=GCOV              use specified gcov [gcov]
  --disable-blobs          disable installing provided firmware blobs
  --with-vss-sdk=SDK-path  enable Windows VSS support in QEMU Guest Agent
  --with-win-sdk=SDK-path  path to Windows Platform SDK (to build VSS .tlb)
  --tls-priority           default TLS protocol/cipher priority string
  --enable-gprof           QEMU profiling with gprof
  --enable-profiler        profiler support
  --enable-debug-stack-usage
                           track the maximum stack usage of stacks created by qemu_alloc_stack
  --enable-plugins
                           enable plugins via shared library loading

Optional features, enabled with --enable-FEATURE and
disabled with --disable-FEATURE, default is enabled if available:

  system          all system emulation targets
  user            supported user emulation targets
  linux-user      all linux usermode emulation targets
  bsd-user        all BSD usermode emulation targets
  docs            build documentation
  guest-agent     build the QEMU Guest Agent
  guest-agent-msi build guest agent Windows MSI installation package
  pie             Position Independent Executables
  modules         modules support (non-Windows)
  debug-tcg       TCG debugging (default is disabled)
  debug-info      debugging information
  sparse          sparse checker

  gnutls          GNUTLS cryptography support
  nettle          nettle cryptography support
  gcrypt          libgcrypt cryptography support
  auth-pam        PAM access control
  sdl             SDL UI
  sdl-image       SDL Image support for icons
  gtk             gtk UI
  vte             vte support for the gtk UI
  curses          curses UI
  iconv           font glyph conversion support
  vnc             VNC UI support
  vnc-sasl        SASL encryption for VNC server
  vnc-jpeg        JPEG lossy compression for VNC server
  vnc-png         PNG compression for VNC server
  cocoa           Cocoa UI (Mac OS X only)
  virtfs          VirtFS
  mpath           Multipath persistent reservation passthrough
  xen             xen backend driver support
  xen-pci-passthrough    PCI passthrough support for Xen
  brlapi          BrlAPI (Braile)
  curl            curl connectivity
  membarrier      membarrier system call (for Linux 4.14+ or Windows)
  fdt             fdt device tree
  bluez           bluez stack connectivity
  kvm             KVM acceleration support
  hax             HAX acceleration support
  hvf             Hypervisor.framework acceleration support
  whpx            Windows Hypervisor Platform acceleration support
  rdma            Enable RDMA-based migration
  pvrdma          Enable PVRDMA support
  vde             support for vde network
  netmap          support for netmap network
  linux-aio       Linux AIO support
  cap-ng          libcap-ng support
  attr            attr and xattr support
  vhost-net       vhost-net kernel acceleration support
  vhost-vsock     virtio sockets device support
  vhost-scsi      vhost-scsi kernel target support
  vhost-crypto    vhost-user-crypto backend support
  vhost-kernel    vhost kernel backend support
  vhost-user      vhost-user backend support
  spice           spice
  rbd             rados block device (rbd)
  libiscsi        iscsi support
  libnfs          nfs support
  smartcard       smartcard support (libcacard)
  libusb          libusb (for usb passthrough)
  live-block-migration   Block migration in the main migration stream
  usb-redir       usb network redirection support
  lzo             support of lzo compression library
  snappy          support of snappy compression library
  bzip2           support of bzip2 compression library
                  (for reading bzip2-compressed dmg images)
  lzfse           support of lzfse compression library
                  (for reading lzfse-compressed dmg images)
  seccomp         seccomp support
  coroutine-pool  coroutine freelist (better performance)
  glusterfs       GlusterFS backend
  tpm             TPM support
  libssh          ssh block device support
  numa            libnuma support
  libxml2         for Parallels image format
  tcmalloc        tcmalloc support
  jemalloc        jemalloc support
  avx2            AVX2 optimization support
  replication     replication support
  opengl          opengl support
  virglrenderer   virgl rendering support
  xfsctl          xfsctl support
  qom-cast-debug  cast debugging support
  tools           build qemu-io, qemu-nbd and qemu-img tools
  vxhs            Veritas HyperScale vDisk backend support
  bochs           bochs image format support
  cloop           cloop image format support
  dmg             dmg image format support
  qcow1           qcow v1 image format support
  vdi             vdi image format support
  vvfat           vvfat image format support
  qed             qed image format support
  parallels       parallels image format support
  sheepdog        sheepdog block driver support
  crypto-afalg    Linux AF_ALG crypto backend driver
  capstone        capstone disassembler support
  debug-mutex     mutex debugging support
  libpmem         libpmem support
  xkbcommon       xkbcommon support

NOTE: The object files are built at the place where configure is launched

```

# 4. Qemu build

## 4.1 Build for arm

```
$ sudo apt-get install pkg-config libglib2.0-dev autoconf libtool libpixman-1-dev

$ git clone git://git.qemu.org/qemu.git
$ cd qmeum
$ ./configure --prefix=$PWD/ --target-list="arm-softmmu arm-linux-user" --enable-debug --enable-sdl --enable-kvm --enable-tools --disable-curl	//enable sdl

$ ./configure --prefix=$PWD/ --target-list="arm-softmmu arm-linux-user" --enable-debug --enable-kvm --enable-tools --disable-curl	//without sdl

$ make

```



# 90. FAQ

1) How to quit the QEMU monitor when not using a GUI?

```
For -nographic just enter:

Ctrl-A X
which means

first press Ctrl + A (A is just key a, not the alt key),
then release the keys,
afterwards type X
```



# 99. Reference URL

* 1) [Speed up your kernel development cycle with QEMU](https://kernel-recipes.org/en/2015/talks/speed-up-your-kernel-development-cycle-with-qemu/)
* 2) [What is Kernel Recipes](https://kernel-recipes.org/)
* 3) [Step-by-step Using qemu to Boot an Emulated Odroid](http://odroid.us/mediawiki/index.php?title=Step-by-step_Using_qemu_to_Boot_an_Emulated_Odroid)
* 4) [Part A. QEMU使用手册](http://wiki.100ask.org/Qemu)
* 5) [Qemu搭建ARM vexpress开发环境(一)](https://www.cnblogs.com/microxiami/p/9746979.html)
* 6) [Linux下如何指定某一类型程序用特定程序打开（通过binfmt_misc）](https://blog.csdn.net/roland_sun/article/details/50062295)
* 

