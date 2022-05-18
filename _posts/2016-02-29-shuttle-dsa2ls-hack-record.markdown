---
layout: post
title: "Shuttle DSA2LS hack record"
date: 2016-02-29 14:19:11 +0800
comments: true
categories: 
---

# 1. Board introduction #

	http://cn.shuttle.com/products/productsDetail?productId=1807
	https://item.taobao.com/item.htm?spm=a1z02.1.1998049143.d4919530.jI9o9L&scm=1007.10157.22422.100200300000000&id=525584959354&pvid=258f64e4-9420-487b-b2e9-3450cd46b60a

# 2. Original firmware backup info #

## 2.1 u-boot env ##
	U-Boot 2009.08-00737-g770329d ( 7鏈21 2014 - 19:12:29)
	
	CPU: Freescale i.MX6 family TO1.1 at 792 MHz
	Thermal sensor with ratio = 174
	Temperature:   32 C, calibration data 0x5504c169
	mx6q pll1: 792MHz
	mx6q pll2: 528MHz
	mx6q pll3: 480MHz
	mx6q pll8: 50MHz
	ipg clock     : 66000000Hz
	ipg per clock : 66000000Hz
	uart clock    : 80000000Hz
	cspi clock    : 60000000Hz
	ahb clock     : 132000000Hz
	axi clock   : 198000000Hz
	emi_slow clock: 99000000Hz
	ddr clock     : 396000000Hz
	usdhc1 clock  : 198000000Hz
	usdhc2 clock  : 198000000Hz
	usdhc3 clock  : 198000000Hz
	usdhc4 clock  : 198000000Hz
	nfc clock     : 24000000Hz
	Board: i.MX6DL/Solo-SABRESD: unknown-board Board: 0x61011 [POR ]
	Boot Device: MMC
	I2C:   ready
	DRAM:   1 GB
	MMC:   FSL_USDHC: 0,FSL_USDHC: 1,FSL_USDHC: 2,FSL_USDHC: 3
	P0 = 0, P1 = 0, P2 = 0, P3 = 0
	LCD Type = 0, clock = 7425, Div = 20
	In:    serial
	Out:   serial
	Err:   serial
	i2c: I2C4 SDA is low, start i2c recovery...
	I2C4 Recovery failed, I2C1 SDA still low!!!
	i2c: I2C4 SDA is low, start i2c recovery...
	I2C4 Recovery failed, I2C1 SDA still low!!!
	WM8326 PMIC init !
	WM8326 PMIC found ! - 0x4662
	Net:   got MAC address from IIM: 00:00:00:00:00:00
	FEC0 [PRIME]
	Hit any key to stop autoboot:  0
	MX6SDL SABRESD U-Boot > printenv
	bootdelay=3
	baudrate=115200
	ipaddr=192.168.1.103
	serverip=192.168.1.101
	netmask=255.255.255.0
	loadaddr=0x10800000
	rd_loadaddr=0x11000000
	netdev=eth0
	ethprime=FEC0
	splashimage=0x30000000
	splashpos=m,m
	vga_rsl=11
	lvds_num=2
	ethact=FEC0
	mac=80EE739C561C
	stdin=serial
	stdout=serial
	stderr=serial
	fastboot_dev=mmc3
	bootcmd=booti mmc3
	ethaddr=80:EE:73:9C:56:1C
	bootargs=console=ttymxc1,115200 androidboot.console=ttymxc1 androidboot.hardware=freescale init=/init vmalloc=400M video=mxcfb0:dev=hdmi,1920x1080M@60,bpp=32 mac=80:EE:73:9C:56:1C
	
	Environment size: 535/8188 bytes

## 2.2 Full boot log ##
	U-Boot 2009.08-00737-g770329d ( 7鏈21 2014 - 19:12:29)
	
	CPU: Freescale i.MX6 family TO1.1 at 792 MHz
	Thermal sensor with ratio = 174
	Temperature:   34 C, calibration data 0x5504c169
	mx6q pll1: 792MHz
	mx6q pll2: 528MHz
	mx6q pll3: 480MHz
	mx6q pll8: 50MHz
	ipg clock     : 66000000Hz
	ipg per clock : 66000000Hz
	uart clock    : 80000000Hz
	cspi clock    : 60000000Hz
	ahb clock     : 132000000Hz
	axi clock   : 198000000Hz
	emi_slow clock: 99000000Hz
	ddr clock     : 396000000Hz
	usdhc1 clock  : 198000000Hz
	usdhc2 clock  : 198000000Hz
	usdhc3 clock  : 198000000Hz
	usdhc4 clock  : 198000000Hz
	nfc clock     : 24000000Hz
	Board: i.MX6DL/Solo-SABRESD: unknown-board Board: 0x61011 [WDOG ]
	Boot Device: MMC
	I2C:   ready
	DRAM:   1 GB
	MMC:   FSL_USDHC: 0,FSL_USDHC: 1,FSL_USDHC: 2,FSL_USDHC: 3
	P0 = 0, P1 = 0, P2 = 0, P3 = 0
	LCD Type = 0, clock = 7425, Div = 20
	In:    serial
	Out:   serial
	Err:   serial
	i2c: I2C4 SDA is low, start i2c recovery...
	I2C4 Recovery failed, I2C1 SDA still low!!!
	i2c: I2C4 SDA is low, start i2c recovery...
	I2C4 Recovery failed, I2C1 SDA still low!!!
	WM8326 PMIC init !
	WM8326 PMIC found ! - 0x4662
	Net:   got MAC address from IIM: 00:00:00:00:00:00
	FEC0 [PRIME]
	Hit any key to stop autoboot:  0 
	kernel   @ 10808000 (4702408)
	ramdisk  @ 11800000 (187117)
	kernel cmdline: 
	        use uboot command line:
	        console=ttymxc1,115200 androidboot.console=ttymxc1 androidboot.hardware=freescale init=/init vmalloc=400M video=mxcfb0:dev=hdmi,1920x1080M@60,bpp=32 mac=80:EE:73:9C:56:1C 
	
	Starting kernel ...
	
	Initializing cgroup subsys cpu
	Linux version 3.0.35-06233-g7856f09-dirty (Shuttle@dc2-server) (gcc version 4.6.x-google 20120106 (prerelease) (GCC) ) #4 SMP PREEMPT Mon Jul 28 17:10:33 CST 2014
	CPU: ARMv7 Processor [412fc09a] revision 10 (ARMv7), cr=10c53c7d
	CPU: VIPT nonaliasing data cache, VIPT aliasing instruction cache
	Machine: Freescale i.MX 6Quad/DualLite/Solo Sabre-SD Board
	Ignoring unrecognised tag 0x54410008
	Memory policy: ECC disabled, Data cache writealloc
	CPU identified as i.MX6DL/SOLO, silicon rev 1.1
	PERCPU: Embedded 7 pages/cpu @c12eb000 s6592 r8192 d13888 u32768
	Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 210688
	Kernel command line: console=ttymxc1,115200 androidboot.console=ttymxc1 androidboot.hardware=freescale init=/init vmalloc=400M video=mxcfb0:dev=hdmi,1920x1080M@60,bpp=32 mac=80:EE:73:9C:56:1C
	PID hash table entries: 2048 (order: 1, 8192 bytes)
	Dentry cache hash table entries: 65536 (order: 6, 262144 bytes)
	Inode-cache hash table entries: 32768 (order: 5, 131072 bytes)
	Memory: 767MB 64MB = 831MB total
	Memory: 830928k/830928k available, 217648k reserved, 441344K highmem
	Virtual kernel memory layout:
	    vector  : 0xffff0000 - 0xffff1000   (   4 kB)
	    fixmap  : 0xfff00000 - 0xfffe0000   ( 896 kB)
	    DMA     : 0xfbe00000 - 0xffe00000   (  64 MB)
	    vmalloc : 0xd9800000 - 0xf2000000   ( 392 MB)
	    lowmem  : 0xc0000000 - 0xd9000000   ( 400 MB)
	    pkmap   : 0xbfe00000 - 0xc0000000   (   2 MB)
	    modules : 0xbf000000 - 0xbfe00000   (  14 MB)
	      .init : 0xc0008000 - 0xc0042000   ( 232 kB)
	      .text : 0xc0042000 - 0xc08c297c   (8707 kB)
	      .data : 0xc08c4000 - 0xc095a310   ( 601 kB)
	       .bss : 0xc095a334 - 0xc0ae1d88   (1567 kB)
	Preemptible hierarchical RCU implementation.
	NR_IRQS:624
	MXC GPIO hardware
	sched_clock: 32 bits at 3000kHz, resolution 333ns, wraps every 1431655ms
	Set periph_clk's parent to pll2_pfd_400M!
	arm_max_freq=1GHz
	MXC_Early serial console at MMIO 0x21e8000 (options '115200')
	bootconsole [ttymxc1] enabled
	Calibrating delay loop... 1581.05 BogoMIPS (lpj=7905280)
	pid_max: default: 32768 minimum: 301
	Mount-cache hash table entries: 512
	Initializing cgroup subsys debug
	Initializing cgroup subsys cpuacct
	Initializing cgroup subsys freezer
	CPU: Testing write buffer coherency: ok
	hw perfevents: enabled with ARMv7 Cortex-A9 PMU driver, 7 counters available
	CPU1: Booted secondary processor
	Brought up 2 CPUs
	SMP: Total of 2 processors activated (3162.11 BogoMIPS).
	print_constraints: dummy: 
	NET: Registered protocol family 16
	print_constraints: vddpu: 725 <--> 1300 mV at 700 mV fast normal 
	print_constraints: vddcore: 725 <--> 1300 mV at 1150 mV fast normal 
	print_constraints: vddsoc: 725 <--> 1300 mV at 1200 mV fast normal 
	print_constraints: vdd2p5: 2000 <--> 2775 mV at 2400 mV fast normal 
	print_constraints: vdd1p1: 800 <--> 1400 mV at 1100 mV fast normal 
	print_constraints: vdd3p0: 2625 <--> 3400 mV at 3000 mV fast normal 
	----------> lvds_mode_select=0
	ram_console: got buffer at 3ff00000, size 100000
	ram_console: uncorrectable error in header
	ram_console: no valid data in buffer (sig = 0x01450204)
	console [ram-1] enabled
	hw-breakpoint: found 6 breakpoint and 1 watchpoint registers.
	hw-breakpoint: 1 breakpoint(s) reserved for watchpoint single-step.
	hw-breakpoint: maximum watchpoint size is 4 bytes.
	L310 cache controller enabled
	l2x0: 16 ways, CACHE_ID 0x410000c8, AUX_CTRL 0x02050000, Cache size: 524288 B
	bio: create slab <bio-0> at 0
	mxs-dma mxs-dma-apbh: initialized
	print_constraints: SPKVDD: 4200 mV 
	print_constraints: vmmc: 3300 mV 
	vgaarb: loaded
	SCSI subsystem initialized
	spi_imx imx6q-ecspi.0: probed
	usbcore: registered new interface driver usbfs
	usbcore: registered new interface driver hub
	usbcore: registered new device driver usb
	Freescale USB OTG Driver loaded, $Revision: 1.55 $
	wm831x 2-0034: WM8326 revision C
	set IRQ459(port=7, GPIO=11) to be a wakeup source......
	add wake up source irq 110
	print_constraints: vdd_arm: 600 <--> 1500 mV at 1350 mV at 0 mA 
	print_constraints: vdd_soc: 600 <--> 1500 mV at 1350 mV at 0 mA 
	print_constraints: vdd_1v8_ldo1: 1700 <--> 1800 mV at 1350 mV 
	print_constraints: vdd_2v5_ldo7: 2400 <--> 2500 mV at 1350 mV 
	imx-ipuv3 imx-ipuv3.0: IPU DMFC NORMAL mode: 1(0~1), 5B(4,5), 5F(6,7)
	MIPI CSI2 driver module loaded
	Advanced Linux Sound Architecture Driver Version 1.0.24.
	Bluetooth: Core ver 2.16
	NET: Registered protocol family 31
	Bluetooth: HCI device and connection manager initialized
	Bluetooth: HCI socket layer initialized
	Bluetooth: L2CAP socket layer initialized
	Bluetooth: SCO socket layer initialized
	Switching to clocksource mxc_timer1
	NET: Registered protocol family 2
	IP route cache hash table entries: 16384 (order: 4, 65536 bytes)
	TCP established hash table entries: 65536 (order: 7, 524288 bytes)
	TCP bind hash table entries: 65536 (order: 7, 786432 bytes)
	TCP: Hash tables configured (established 65536 bind 65536)
	TCP reno registered
	UDP hash table entries: 256 (order: 1, 8192 bytes)
	UDP-Lite hash table entries: 256 (order: 1, 8192 bytes)
	NET: Registered protocol family 1
	RPC: Registered named UNIX socket transport module.
	RPC: Registered udp transport module.
	RPC: Registered tcp transport module.
	RPC: Registered tcp NFSv4.1 backchannel transport module.
	PCI: CLS 0 bytes, default 32
	Unpacking initramfs...
	Freeing initrd memory: 180K
	PMU: registered new PMU device of type 0
	Static Power Management for Freescale i.MX6
	wait mode is enabled for i.MX6
	cpaddr = d9820000 suspend_iram_base=d98b8000
	PM driver module loaded
	IMX usb wakeup probe
	the wakeup pdata is 0xd6439420
	add wake up source irq 75
	IMX usb wakeup probe
	the wakeup pdata is 0xd64391e0
	cpu regulator mode:ldo_enable
	i.MXC CPU frequency driver
	highmem bounce pool size: 64 pages
	ashmem: initialized
	NTFS driver 2.1.30 [Flags: R/O].
	JFFS2 version 2.2. (NAND) 漏 2001-2006 Red Hat, Inc.
	fuse init (API version 7.16)
	msgmni has been set to 761
	NET: Registered protocol family 38
	cryptodev: driver loaded.
	io scheduler noop registered
	io scheduler deadline registered
	io scheduler cfq registered (default)
	mxc_sdc_fb mxc_sdc_fb.0: register mxc display driver hdmi
	mxc_hdmi mxc_hdmi: Detected HDMI controller 0x13:0x1a:0xa0:0xc1
	fbcvt: 1920x1080@60: CVT Name - 2.073M9
	imx-ipuv3 imx-ipuv3.0: IPU DMFC DP HIGH RESOLUTION: 1(0,1), 5B(2~5), 5F(6,7)
	mxc_sdc_fb mxc_sdc_fb.1: register mxc display driver hdmi
	mxc_hdmi mxc_hdmi: Error only one HDMI output support now!
	mxc_sdc_fb mxc_sdc_fb.1: NO mxc display driver found!
	imx-sdma imx-sdma: loaded firmware 1.1
	imx-sdma imx-sdma: initialized
	Serial: IMX driver
	imx-uart.1: ttymxc1 at MMIO 0x21e8000 (irq = 59) is a IMX
	console [ttymxc1] enabled, bootconsole disabled
	console [ttymxc1] enabled, bootconsole disabled
	imx-uart.0: ttymxc0 at MMIO 0x2020000 (irq = 58) is a IMX
	loop: module loaded
	m25p80 spi0.0: found m25p05-nonjedec, expected sst25vf016b
	m25p80 spi0.0: m25p05-nonjedec (64 Kbytes)
	Creating 2 MTD partitions on "m25p80":
	0x000000000000-0x000000100000 : "bootloader"
	mtd: partition "bootloader" extends beyond the end of device "m25p80" -- size truncated to 0x10000
	0x000000010000-0x000000010000 : "kernel"
	mtd: partition "kernel" is out of reach -- disabled
	GPMI NAND driver registered. (IMX)
	vcan: Virtual CAN interface driver
	CAN device driver interface
	flexcan netdevice driver
	FEC Ethernet Driver
	fec_enet_mii_bus: probed
	PPP generic driver version 2.4.2
	PPP Deflate Compression module registered
	PPP BSD Compression module registered
	PPP MPPE Compression module registered
	NET: Registered protocol family 24
	PPTP driver version 0.8.5
	tun: Universal TUN/TAP device driver, 1.6
	tun: (C) 1999-2004 Max Krasnyansky <maxk@qualcomm.com>
	ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
	fsl-ehci fsl-ehci.0: Freescale On-Chip EHCI Host Controller
	fsl-ehci fsl-ehci.0: new USB bus registered, assigned bus number 1
	fsl-ehci fsl-ehci.0: irq 75, io base 0x02184000
	fsl-ehci fsl-ehci.0: USB 2.0 started, EHCI 1.00
	hub 1-0:1.0: USB hub found
	hub 1-0:1.0: 1 port detected
	add wake up source irq 72
	fsl-ehci fsl-ehci.1: Freescale On-Chip EHCI Host Controller
	fsl-ehci fsl-ehci.1: new USB bus registered, assigned bus number 2
	fsl-ehci fsl-ehci.1: irq 72, io base 0x02184200
	fsl-ehci fsl-ehci.1: USB 2.0 started, EHCI 1.00
	hub 2-0:1.0: USB hub found
	hub 2-0:1.0: 1 port detected
	usbcore: registered new interface driver cdc_acm
	cdc_acm: USB Abstract Control Model driver for USB modems and ISDN adapters
	Initializing USB Mass Storage driver...
	usbcore: registered new interface driver usb-storage
	USB Mass Storage support registered.
	usbcore: registered new interface driver usbserial
	usbserial: USB Serial Driver core
	USB Serial support registered for GSM modem (1-port)
	usbcore: registered new interface driver option
	option: v0.7.2:USB Driver for GSM modems
	USB Serial support registered for Qualcomm USB modem
	usbcore: registered new interface driver qcserial
	ARC USBOTG Device Controller driver (1 August 2005)
	android_usb gadget: Mass Storage Function, version: 2009/09/11
	android_usb gadget: Number of LUNs=1
	 lun0: LUN: removable file: (no medium)
	Gadget Android: controller 'fsl-usb2-udc' not recognized
	android_usb gadget: android_usb ready
	Suspend udc for OTG auto detect
	USB Host suspend begins
	will suspend roothub and its children
	ehci_fsl_bus_suspend begins, DR
	ehci_fsl_bus_suspend ends, DR
	host suspend ends
	USB Gadget resume begins
	fsl_udc_resume, Wait for wakeup thread finishes
	dr_controller_run: udc out low power mode
	USB Gadget resume ends
	fsl-usb2-udc: bind to driver android_usb 
	mousedev: PS/2 mouse device common for all mice
	input: gpio-keys as /devices/platform/gpio-keys/input/input0
	i2c-core: driver [isl29023] using legacy suspend method
	i2c-core: driver [isl29023] using legacy resume method
	using rtc device, wm831x, for alarms
	wm831x-rtc wm831x-rtc: rtc core: registered wm831x as rtc0
	i2c /dev entries driver
	lirc_dev: IR Remote Control driver registered, major 251 
	IR NEC protocol handler initialized
	IR RC5(x) protocol handler initialized
	IR RC6 protocol handler initialized
	IR JVC protocol handler initialized
	IR Sony protocol handler initialized
	IR RC5 (streamzap) protocol handler initialized
	IR LIRC bridge handler initialized
	usbcore: registered new interface driver mceusb
	Linux video capture interface: v2.00
	mxc_v4l2_output mxc_v4l2_output.0: V4L2 device registered as video16
	mxc_v4l2_output mxc_v4l2_output.0: V4L2 device registered as video17
	usbcore: registered new interface driver uvcvideo
	USB Video Class driver (v1.1.0)
	sabresd_battery: max8903_probe is called......
	sabresd_battery: register max8903-ac......
	sabresd_battery: register max8903-charger......
	imx2-wdt imx2-wdt.0: IMX2+ Watchdog Timer enabled. timeout=60s (nowayout=1)
	device-mapper: uevent: version 1.0.3
	device-mapper: ioctl: 4.20.0-ioctl (2011-02-02) initialised: dm-devel@redhat.com
	Bluetooth: Virtual HCI driver ver 1.3
	Bluetooth: HCI UART driver ver 2.2
	Bluetooth: HCIATH3K protocol initialized
	Bluetooth: Generic Bluetooth USB driver ver 0.6
	usbcore: registered new interface driver btusb
	sdhci: Secure Digital Host Controller Interface driver
	sdhci: Copyright(c) Pierre Ossman
	mmc0: SDHCI controller on platform [sdhci-esdhc-imx.3] using ADMA
	mmc1: SDHCI controller on platform [sdhci-esdhc-imx.1] using ADMA
	mxc_vdoa mxc_vdoa: i.MX Video Data Order Adapter(VDOA) driver probed
	VPU initialized
	mxc_asrc registered
	Galcore version 4.6.9.6622
	usb 2-1: new high speed USB device number 2 using fsl-ehci
	revserved_memory_account:viv_gpu registerd
	Thermal calibration data is 0x5504c169
	Thermal sensor with ratio = 174
	Anatop Thermal registered as thermal_zone0
	anatop_thermal_probe: default cooling device is cpufreq!
	Registered led device: red_led
	Registered led device: blue_led
	usbcore: registered new interface driver usbhid
	usbhid: USB HID core driver
	logger: created 256K log 'log_main'
	logger: created 256K log 'log_events'
	logger: created 256K log 'log_radio'
	logger: created 256K log 'log_system'
	usbcore: registered new interface driver snd-usb-audio
	mxc_hdmi_soc mxc_hdmi_soc.0: MXC HDMI Audio
	mxc_spdif mxc_spdif.0: MXC SPDIF Audio
	mmc0: new high speed DDR MMC card at address 0001
	mmcblk0: mmc0:0001 SEM04G 3.68 GiB 
	hub 2-1:1.0: USB hub found
	mmcblk0boot0: mmc0:0001 SEM04G partition 1 2.00 MiB
	hub 2-1:1.0: 4 ports detected
	mmcblk0boot1: mmc0:0001 SEM04G partition 2 2.00 MiB
	 mmcblk0: p1 p2 p3 < p5 p6 p7 p8 > p4
	mmcblk0: p4 size 5554176 extends beyond EOD, truncated
	 mmcblk0boot1: unknown partition table
	 mmcblk0boot0: unknown partition table
	wm8962 0-001a: customer id 0 revision D
	input: WM8962 Beep Generator as /devices/platform/imx-i2c.0/i2c-0/0-001a/input/input1
	asoc: wm8962 <-> imx-ssi.1 mapping ok
	input: wm8962-audio Headphone Jack as /devices/platform/soc-audio.5/sound/card0/input2
	asoc: mxc-spdif <-> imx-spdif-dai.0 mapping ok
	asoc: mxc-hdmi-soc <-> imx-hdmi-soc-dai.0 mapping ok
	ALSA device list:
	  #0: wm8962-audio
	  #1: imx-spdif
	  #2: imx-hdmi-soc
	oprofile: using arm/armv7-ca9
	GACT probability NOT on
	Mirror/redirect action on
	u32 classifier
	    Actions configured
	Netfilter messages via NETLINK v0.30.
	nf_conntrack version 0.5.0 (12986 buckets, 51944 max)
	ctnetlink v0.93: registering with nfnetlink.
	NF_TPROXY: Transparent proxy support initialized, version 4.1.0
	NF_TPROXY: Copyright (c) 2006-2007 BalaBit IT Ltd.
	xt_time: kernel timezone is -0000
	IPv4 over IPv4 tunneling driver
	GRE over IPv4 demultiplexor driver
	ip_tables: (C) 2000-2006 Netfilter Core Team
	arp_tables: (C) 2002 David S. Miller
	TCP cubic registered
	NET: Registered protocol family 10
	Mobile IPv6
	ip6_tables: (C) 2000-2006 Netfilter Core Team
	IPv6 over IPv4 tunneling driver
	NET: Registered protocol family 17
	NET: Registered protocol family 15
	can: controller area network core (rev 20090105 abi 8)
	NET: Registered protocol family 29
	can: raw protocol (rev 20090105)
	can: broadcast manager protocol (rev 20090105 t)
	Bluetooth: RFCOMM TTY layer initialized
	Bluetooth: RFCOMM socket layer initialized
	Bluetooth: RFCOMM ver 1.11
	Bluetooth: BNEP (Ethernet Emulation) ver 1.3
	Bluetooth: BNEP filters: protocol multicast
	Bluetooth: HIDP (Human Interface Emulation) ver 1.2
	L2TP core driver, V2.0
	PPPoL2TP kernel driver, V2.0
	L2TP IP encapsulation support (L2TPv3)
	L2TP netlink interface
	L2TP ethernet pseudowire support (L2TPv3)
	lib80211: common routines for IEEE802.11 drivers
	lib80211_crypt: registered algorithm 'NULL'
	lib80211_crypt: registered algorithm 'WEP'
	usb 2-1.2: new high speed USB device number 3 using fsl-ehci
	lib80211_crypt: registered algorithm 'CCMP'
	lib80211_crypt: registered algorithm 'TKIP'
	USB Gadget resume begins
	fsl_udc_resume, Wait for wakeup thread finishes
	VFP support v0.3: implementor 41 architecture 3 part 30 variant 9 rev 4
	Bus freq driver module loaded
	Bus freq driver Enabled
	mxc_dvfs_core_probe
	DVFS driver module loaded
	regulator_init_complete: SPKVDD: incomplete constraints, leaving on
	wm831x-rtc wm831x-rtc: setting system clock to 2014-01-01 00:34:54 UTC (1388536494)
	Freeing init memory: 232K
	init: cannot find '/system/etc/install-recovery.sh', disabling 'flash_recovery'
	init: cannot find '/system/bin/ingsvcd', disabling 'ing'
	android_usb: already disabled
	android_usb: already disabled
	mtp_bind_config
	adb_bind_config
	root@android:/ # adb_open
	eth0: Freescale FEC PHY driver [Generic PHY] (mii_bus:phy_addr=1:01, irq=-1)
	ADDRCONF(NETDEV_UP): eth0: link is not ready
	ERROR: HDMI is not ready!
	asoc: can't open platform imx-hdmi-soc-audio.0
	warning: `zygote' uses 32-bit capabilities (legacy support in use)
	request_suspend_state: wakeup (3->0) at 9798080003 (2014-01-01 00:35:02.050842335 UTC)
	eth0: Freescale FEC PHY driver [Generic PHY] (mii_bus:phy_addr=1:01, irq=-1)
	ADDRCONF(NETDEV_UP): eth0: link is not ready
	acc_open
	acc_release
	ehci_fsl_bus_resume begins, DR
	[sdhci_pre_dma_transfer] invalid cookie: data->host_cookie 1685 host->next_data.cookie 1686
	[sdhci_pre_dma_transfer] invalid cookie: data->host_cookie 1689 host->next_data.cookie 1690
	init: sys_prop: permission denied uid:1003  name:service.bootanim.exit
	
	root@android:/ # 

