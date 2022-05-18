---
layout: post
title: "kindle 3 hack"
date: 2016-01-26 21:23:32 +0800
comments: true
categories: linux kindle e-ink
---
# 1. Prepare #
## 1.1 Open kindle 3 case and solder rs232 as below ##
![Kindle 3 rs232](../images/kindle3-rs232.jpg "Kindle 3 rs232")

## 1.2 User name and password ##
	login user = framework 
	password = mario 

# 2. Bootloader #
## 2.1 Original u-boot info ##
	
	U-Boot 1.3.0-rc3-lab126 (Dec 27 2010 - 17:42:23)
	
	CPU:   Freescale i.MX35 at 532 MHz
	Board: MX35 Luigi [ WDT]
	WDOG_WCR = 0xff31
	WDOG_WMCR = 0x0
	Board Id: SP1B000000000000
	S/N: B008000000000000
	DRAM:  256 MB
	Using default environment
	
	In:    serial
	Out:   serial
	Err:   serial
	No ethernet found.
	i.MX35 CPU board version 2.0
	Net:   No ethernet found.
	Hit any key to stop autoboot:  0 
	uboot> 
	uboot> 
	uboot> printenv
	bootdelay=1
	baudrate=115200
	loadaddr=0x80800000
	uboot_net=tftpboot 0x84000000 u-boot.bin
	uboot_serial=loady 0x84000000
	uboot_ram=go 0x84000000
	bootargs_diag=setenv bootargs tests=all
	diags_net=tftpboot 0x84000000 diagmon.uimage; run bootargs_diag; bootm 0x84000000
	diags_serial=loady 0x84000000; run bootargs_diag; bootm 0x84000000
	bootargs_base=console=ttymxc0,115200 mem=256M panic=10
	bootcmd_root_nfs=setenv bootargs $(bootargs_base) root=/dev/nfs rw nfsroot=$(nfsrootfs),v3,tcp rw ip=$(ipaddr):$(serverip):$(serverip):$(netmask):mario1 rootdelay=3
	bootcmd_root_mmc=setenv bootargs $(bootargs_base) root=/dev/mmcblk1p1 rw ip=none
	bootcmd_root_mvn=setenv bootargs $(bootargs_base) root=/dev/mmcblk0p1 rw ip=none
	bootcmd_kernel_nfs=nfs 0x87f40400 $(nfsrootfs)/uImage; bootm
	bootcmd_kernel_tftp=tftp 0x87f40400 uImage; bootm
	bootcmd_nfs=run bootcmd_root_nfs; run bootcmd_kernel_nfs
	bootcmd_flash=run bootcmd_root_mvn; run bootcmd_kernel_nor
	bootcmd_card=run bootcmd_root_mmc; run bootcmd_kernel_nor
	bootcmd_recovery=run bootcmd_root_recovery; run bootcmd_kernel_nor
	bootcmd_defaultflash=setenv bootargs; run bootcmd_kernel_nor
	bootcmd=bootm 0x87f40400
	testmem=mtest 0x80000000 0x86ffffff
	nfsrootfs=/nfsboot
	ethaddr=00:22:33:44:55:66
	cfgreset=protect off all ; erase (0xA0000000 + (128 * 1024)) +(128 * 1024)
	bootretry=-1
	stdin=serial
	stdout=serial
	stderr=serial
	
	Environment size: 1362/131068 bytes
	uboot> bdinfo
	arch_number = 0x0000066D
	env_t       = 0x00000000
	boot_params = 0x80000100
	DRAM bank   = 0x00000000
	-> start    = 0x80000000
	-> size     = 0x10000000
	ethaddr     = 00:22:33:44:55:66
	ip_addr     = 0.0.0.0
	baudrate    = 115200 bps
	uboot> help
	?       - alias for 'help'
	autoscr - run script from memory
	base    - print or set address offset
	bdinfo  - print Board Info structure
	boot    - boot default, i.e., run 'bootcmd'
	bootd   - boot default, i.e., run 'bootcmd'
	bootm   - boot application image from memory
	bootp   - boot image via network using BootP/TFTP protocol
	cmp     - memory compare
	coninfo - print console devices and information
	cp      - memory copy
	crc32   - checksum calculation
	dhcp    - invoke DHCP client to obtain IP/boot params
	echo    - echo args to console
	go      - start application at address 'addr'
	help    - print online help
	iminfo  - print header information for application image
	itest   - return true/false on integer compare
	loadb   - load binary file over serial line (kermit mode)
	loads   - load S-Record file over serial line
	loady   - load binary file over serial line (ymodem mode)
	loop    - infinite loop on address range
	md      - memory display
	mii     - MII utility commands
	mm      - memory modify (auto-incrementing)
	mtest   - simple RAM test
	mw      - memory write (fill)
	nfs     - boot image via network using NFS protocol
	nm      - memory modify (constant address)
	ping    - send ICMP ECHO_REQUEST to network host
	printenv- print environment variables
	rarpboot- boot image via network using RARP/TFTP protocol
	reset   - Perform RESET of the CPU
	run     - run commands in an environment variable
	setenv  - set environment variables
	sleep   - delay execution for some time
	tftpboot- boot image via network using TFTP protocol
	version - print monitor version
	uboot> version
	
	U-Boot 1.3.0-rc3-lab126 (Dec 27 2010 - 17:42:23)
	uboot> 
# 3. Kernel #

## 3.1 Original kernel info ##
	
	uboot> reset
	            
	
	U-Boot 1.3.0-rc3-lab126 (Dec 27 2010 - 17:42:23)
	
	CPU:   Freescale i.MX35 at 532 MHz
	Board: MX35 Luigi [ WDT]
	WDOG_WCR = 0xff31
	WDOG_WMCR = 0x0
	Board Id: SP1B000000000000
	S/N: B008000000000000
	DRAM:  256 MB
	Using default environment
	
	In:    serial
	Out:   serial
	Err:   serial
	No ethernet found.
	i.MX35 CPU board version 2.0
	Net:   No ethernet found.
	Hit any key to stop autoboot:  0 
	## Booting image at 87f40400 ...
	   Image Name:   Linux-2.6.26-rt-lab126
	   Image Type:   ARM Linux Kernel Image (uncompressed)
	   Data Size:    2166568 Bytes =  2.1 MB
	   Load Address: 80008000
	   Entry Point:  80008000
	   Verifying Checksum ... OK
	   Loading Kernel Image ... OK
	
	Starting kernel ...
	
	Uncompressing Linux.......................................................................................................................... done, booting the kernel.
	boot: C def:bcut:batterycut=1:
	2.6.26-rt-lab126 #5 Sat Feb 5 19:05:05 PST 2011 armv6l
	INFO:Using default keypad setting. (not passing "kb_rev" to module)
	INFO:Loaded module /lib/modules/mxc_keyb.ko  (22508 bytes)
	Press [ENTER] for recovery menu...       0 /INFO:Partition table verified for /dev/mmcblk0
	INFO:Checking for updates... (auto-pilot mode)
	/dev/mmcblk0p4:
	CHS=4/16/100167 size=3282272256 bytes
	flag type      first       last  lba first   lba size
	Partition p1:
	0x00 0x0b         16 <large>            16    6410672
	    CHS: 0/1/1 - <large>
	Partition p2:
	Partition p3:
	Partition p4:
	INFO:Setup loop device /dev/loop0 for /dev/mmcblk0p4 + 8192
	INFO:No update*.bin found; no update needed.
	INFO:no updates found.
	BOOTING DEFAULT.
	  argc == 9
	  argv[0]: "kinit"
	  argv[1]: "console=ttymxc0,115200"
	  argv[2]: "mem=256M"
	  argv[3]: "panic=10"
	  argv[4]: "root=/dev/mmcblk0p1"
	  argv[5]: "ro"
	  argv[6]: "ip=none"
	  argv[7]: "quiet"
	  argv[8]: "lpj=2555904"
	Running ipconfig
	  argc == 4
	  argv[0]: "IP-Config"
	  argv[1]: "-i"
	  argv[2]: "Linux kinit"
	  argv[3]: "ip=none"
	IP-Config: no devices to configure
	kinit: do_mounts
	kinit: name_to_dev_t(/dev/mmcblk0p1) = dev(179,1)
	kinit: root_dev = dev(179,1)
	kinit: /dev/root appears to be a ext3 filesystem
	kinit: trying to mount /dev/root on /root with type ext3
	kinit: Mounted root (ext3 filesystem) readonly.
	Checking for init: /sbin/init
	Checking for init: /bin/init
	Checking for init: /etc/init
	Checking for init: /sbin/init.sysvinit
	INIT: version 2.86 booting
	system: I rcS:def:starting /etc/rcS.d/S02kdb
	system: I S02kdb:def:Setting boot device to mmcblk0
	kdb set: 'system/driver/filesystem/DEV_ROOT'
	system: I rcS:def:starting /etc/rcS.d/S03udev
	system: I S03udev:def:setting up virtual fs for hotplug event handling
	system: I S03udev:def:starting the hotplug events dispatcher
	system: I S03udev:def:synthesizing initial hotplug events
	lipc-send-event[380]: E lipc:con::Connection error(Failed to connect to socket /var/run/dbus/system_bus_socket: No such file or directory)
	lipc-send-event[380]: C def:dbusi::Failed to init dbus
	lipc-send-event[380]: E def:open::Failed to open LIPC
	lipc-send-event[380]: E def:fail:source=com.lab126.hal, event=usbPlugIn:Sending event failed
	lipc-send-event[481]: E lipc:con::Connection error(Failed to connect to socket /var/run/dbus/system_bus_socket: No such file or directory)
	lipc-send-event[481]: C def:dbusi::Failed to init dbus
	lipc-send-event[481]: E def:open::Failed to open LIPC
	lipc-send-event[481]: E def:fail:source=com.lab126.hal, event=audioHS:Sending event failed
	system: I rcS:def:starting /etc/rcS.d/S04rootfsresize
	system: I S04rootfsresize:def:No rootfs on /dev/mmcblk0p1 resizing needed
	system: I rcS:def:starting /etc/rcS.d/S10filesystems
	system: I rcS:def:starting /etc/rcS.d/S10hostname
	system: I rcS:def:starting /etc/rcS.d/S10network
	system: I S10filesystems:def:mounting filesystems
	system: I S10hostname:def:setting device hostname
	system: I S10network:def:initializing network configuration
	system: I S10network:def:Installed Firewall
	system: I rcS:def:starting /etc/rcS.d/S11chpriority
	system: I rcS:def:starting /etc/rcS.d/S11video
	Unknown HZ value! (85) Assume 100.
	system: W S11chpriority:def:Cannot set priority for IRQ-7
	system: I S11video:def:initializing eInk HAL for system use
	system: I S11video:def:eink_debug=0
	system: I S11video:def:Controller set to broads
	system: I rcS:def:starting /etc/rcS.d/S20syslog-ng
	system: I S20syslog-ng:def:starting syslog-ng
	system: I rcS:def:starting /etc/rcS.d/S21init_time
	system: I S21init_time:initboot:time=17100:boot time after init in milliseconds
	system: I rcS:def:starting /etc/rcS.d/S45modules
	system: I S45modules:def:loading module mwan
	system: I S45modules:def:loading module g_file_storage
	system: I S45modules:def:loading module fuse
	system: I S45modules:def:loading module uinput
	system: I S45modules:def:loading module mxc_keyb
	system: I S45modules:def:loading module fiveway
	system: I S45modules:def:loading module volume
	system: I rcS:def:starting /etc/rcS.d/S50system
	mount: mount point /proc/bus/usb does not exist
	Sat Jul 31 00:00:00 UTC 2010
	system: I rcS:def:starting /etc/rcS.d/S55scroll
	system: I S55scroll:def:skipping; no luigi-based work to do here
	system: I rcS:def:starting /etc/rcS.d/S70ethernet
	system: I rcS:def:starting /etc/rcS.d/S70userstore
	system: I S70ethernet:def:not enet
	system: I S70ethernet:def:not usbnet
	system: I S70userstore:def:Found BOOTUP flag file
	dosfsck 2.11-lab126 (1 Jun 2007)
	dosfsck 2.11-lab126, 1 Jun 2007, FAT32, LFN
	Checking we can access the last sector of the filesystem
	Boot sector contents:
	System ID "MSDOS5.0"
	Media byte 0xf8 (hard disk)
	       512 bytes per logical sector
	      8192 bytes per cluster
	      1938 reserved sectors
	First FAT starts at byte 992256 (sector 1938)
	         2 FATs, 32 bit entries
	   1601024 bytes per FAT (= 3127 sectors)
	Root directory start at cluster 2 (arbitrary size)
	Data area starts at byte 4194304 (sector 8192)
	    400155 data clusters (3278069760 bytes)
	63 sectors/track, 255 heads
	        16 hidden sectors
	   6410672 sectors total
	Checking for unused clusters.
	Checking free cluster summary.
	/dev/loop/0: 838 files, 33538/400155 clusters
	system: I rcS:def:starting /etc/rcS.d/S90video
	system: I S90video:def:initializing eInk HAL for rootfs use
	INIT: Entering runlevel: 2
	system: I lifeguard:def:starting eInk HAL lifeguard
	system: I S40diags:def:not starting Diagnostic Services
	system: I S40diags:def:/test/diags/factory does not exist
	system: I S50battcheck:def:running
	Sat Jul 31 08:00:05 2010  INFO:battery voltage: 3708 mV
	Sat Jul 31 08:00:05 2010  INFO:battery charge: 40%
	system: I S50battcheck:def:current voltage = 3703mV
	Sat Jul 31 08:00:05 2010  INFO:battery charge: 40%
	Sat Jul 31 08:00:05 2010  INFO:battery voltage: 3708 mV
	Sat Jul 31 08:00:05 2010  INFO:battery current: -235 mA
	system: I S50battcheck:def:gasgauge capacity=40% volts=3708 mV current=-235 mA
	system: I S50battcheck:def:Waiting for 3460mV or 4%
	system: I S50battcheck:def:battery sufficient, booting to normal runlevel
	INIT: Switching to runlevel: 5
	INIT: Sending processes the TERM signal
	system: I wifi:def:WiFi Device mac = 28:EF:01:4B:F1:55
	Platform set to SHASTA_NATIVEMMC-SDIO
	Platform Setup Script is: /opt/ar6k/host/support/platformscripts/plat_SHASTA_NATIVEMMC-SDIO.sh
	Image path: /sbin
	No debug record limit set
	Load Board Data from /opt/ar6k/target/AR6002/hw2.0/bin/lab126_15dBm_nodiv_WWR_CTL.bin
	Updating MAC address
	BMI Set App Start (address: 0x913950)
	BMI Bit-Wise (OR) modify Register (address: 0x500410, orig:0x8, new: 0x9,  mask:0x1)
	BMI Write compressed Memory (address: 0x502070, filename: /opt/ar6k/target/AR6002/hw2.0/bin/athwlan.bin.z77)
	BMI Write Memory (address: 0x52d6d0, filename: /opt/ar6k/target/AR6002/hw2.0/bin/data.patch.hw2_0.bin)
	BMI Write Memory (address: 0x500418, value: 0x52d6d0)
	BMI Done
	system: I wifi:def:loadAR6000 finished, args=()
	system: I wpa_supplicant:def:wpa supplicant started
	system: I S30network:def:initializing network configuration
	system: I S30network:def:Installed Firewall
	system: I S60dbus:def:starting system message bus
	system: W S64linkjail:def:couldn't run unlinkjail
	Starting Process Monitoring Daemon: Retrieved 127 keys for system/daemon/pmond/
	Starting Power Management Daemon: system: I S70cmd:def:starting CMD daemon
	system: I S70wifid:def:starting wifid
	system: I S75phd:def:Starting Phone-Home Daemon
	system: I S76mcsd:def:starting MCS server
	DK_update starts on Sat Jul 31 08:00:14 AMZ 2010
	clean_repair
	system: I volumd:def:starting Volume daemon
	find DIAGNOSTIC.log
	file 360 KB, limit 5000 KB
	do not compress it
	update_duokan
	custom_debug
	DK_update ends on Sat Jul 31 08:00:14 AMZ 2010
	system: I S80volumd:def:starting Volume daemon
	system: I S82usbnet:def:usbnet is disabled
	system: I S85audio:def:initializing audio driver defaults
	No state is present for card mx35luigi
	system: I S85audio:def:starting audio server
	system: I S87ttsd:def:starting TTS daemon
	Battery Level: 40%
	Sat Jul 31 08:00:17 2010  INFO:battery charge: 40%
	system: I S90cron:def:starting crond
	system: I S90tmd:def:Starting Transfer Manager Daemon
	Starting lipc-daemon: system: I S94browserd:def:Starting Browser Daemon
	Show menu
	system: I S95framework:def:starting booklet framework
	Run Prog
	open successfully:/dev/input/event0
	open successfully:/dev/input/event1
	open successfully:/dev/input/event2
	system: I S95framework:def:logging reset type: hard
	start.sh: starting framework
	
	DuoKan 2012 System
	Run DuoKan program
	KINDLE_VERSION BASE = 300
	stop_tmd_v3v4
	system: I S96boot_finished:def:Boot finished script running
	system: I S96boot_finished:symboot:time=45560:boot time before framework starts, in milliseconds
	system: I browserd:def:Stopping Browser Daemon
	Killed
	system: I updater:def:updater started
	system: W updater:def:Update file not found. Not updating
	system: I phd:def:Stopping Phone-Home Daemon
	system: I ttsd:def:stopping TTS daemon
	com.lab126.powerd failed to set value for property wakeUp (0x8 lipcErrNoSuchProperty)
	get_power: battery_capacity 40% 
	KINDLE_VERSION BASE = 300
	system: I wifid:def:stopping wifid
	stop_framework
	system: I framework:def:stopping booklet framework
	system: I start.sh:stop:signal=15,exitval=143:CVM stopped using SIGTERM
	Unknown HZ value! (85) Assume 100.
	Unknown HZ value! (85) Assume 100.
	[DKLogger] - No LoggerCfg.ini found in working directory!
	07-31 08:00:37:187-<TID: 109667836> DIAGNOSTIC: GetDeviceType(B008)
	07-31 08:00:37:200-<TID: 109667836> DIAGNOSTIC: Diagnostic, kindle version(xKindle_2013-10-25.30919.rtm), device type: (5), kernel version:(2.6.2.30412)
	07-31 08:00:37:209-<TID: 109667836> DIAGNOSTIC: Read string from shell begin: free
	Unknown HZ value! (79) Assume 100.
	07-31 08:00:37:233-<TID: 109667836> DIAGNOSTIC: Read string from shell end: free
	07-31 08:00:37:235-<TID: 109667836> DIAGNOSTIC: free space:
	             total       used       free     shared    buffers     cached
	Mem:        256536      69624     186912          0      12060      37840
	-/+ buffers/cache:      19724     236812
	Swap:            0          0          0
	
	07-31 08:00:37:236-<TID: 109667836> DIAGNOSTIC: Read string from shell begin: top -b -n1
	Unknown HZ value! (79) Assume 100.
	07-31 08:00:37:903-<TID: 109667836> DIAGNOSTIC: Read string from shell end: top -b -n1
	07-31 08:00:37:907-<TID: 109667836> DIAGNOSTIC: 
	top - 08:00:37 up 0 min,  0 users,  load average: 1.85, 0.52, 0.18
	Tasks:  61 total,   1 running,  60 sleeping,   0 stopped,   0 zombie
	Cpu(s): 22.2%us, 43.8%sy,  0.0%ni, 13.5%id, 19.3%wa,  0.7%hi,  0.4%si,  0.0%st
	Mem:    256536k total,    69984k used,   186552k free,    12076k buffers
	Swap:        0k total,        0k used,        0k free,    38052k cached
	
	  PID USER      PR  NI  VIRT  RES  SHR S %CPU %MEM    TIME+  COMMAND            
	 3713 root      20   0  2380 1048  824 R  1.9  0.4   0:00.06 top                
	    1 root      20   0  1484  536  472 S  0.0  0.2   0:01.69 init.sysvinit      
	    2 root      15  -5     0    0    0 S  0.0  0.0   0:00.01 kthreadd           
	    3 root      RT  -5     0    0    0 S  0.0  0.0   0:00.00 posixcputmr/0      
	    4 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-high/0        
	    5 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-timer/0       
	    6 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-net-tx/0      
	    7 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-net-rx/0      
	    8 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-block/0       
	    9 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-tasklet/0     
	   10 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-sched/0       
	   11 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-hrtimer/0     
	   12 root     -51  -5     0    0    0 S  0.0  0.0   0:00.00 sirq-rcu/0         
	   13 root      10 -10     0    0    0 S  0.0  0.0   0:00.07 desched/0          
	   14 root      -2  -5     0    0    0 S  0.0  0.0   0:00.14 events/0           
	   15 root      15  -5     0    0    0 S  0.0  0.0   0:00.03 khelper            
	   67 root      15  -5     0    0    0 S  0.0  0.0   0:00.07 kblockd/0          
	   72 root      15  -5     0    0    0 S  0.0  0.0   0:00.01 mxc_spi.0          
	   75 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 mxc_spi.1          
	   94 root      15  -5     0    0    0 S  0.0  0.0   0:00.32 kmmcd              
	  102 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 pmic_spi/0         
	  174 root      20   0     0    0    0 S  0.0  0.0   0:00.00 pdflush            
	  175 root      20   0     0    0    0 S  0.0  0.0   0:00.00 pdflush            
	  176 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 kswapd0            
	  177 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 aio/0              
	  178 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 nfsiod             
	  214 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 kondemand/0        
	  225 root      15  -5     0    0    0 S  0.0  0.0   0:01.44 mmcqd              
	  256 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 rpciod/0           
	  271 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 kjournald          
	  373 root      16  -4  1520  540  372 S  0.0  0.2   0:00.32 udevd              
	  641 root      15  -5     0    0    0 S  0.0  0.0   0:00.00 kjournald          
	  888 root      15  -5     0    0    0 S  0.0  0.0   0:00.71 eink_fb_bt         
	  890 root      15  -5     0    0    0 S  0.0  0.0   0:00.06 eink_fb_pt         
	  966 root      20   0  1948  660  468 S  0.0  0.3   0:00.21 syslog-ng          
	 1086 root       0 -20     0    0    0 S  0.0  0.0   0:00.00 file-storage-ga    
	 1374 root       0 -20     0    0    0 S  0.0  0.0   0:00.23 loop0              
	 1410 root      20   0 61328 1104  492 S  0.0  0.4   0:00.55 fsp                
	 1489 root      20   0  2656  732  568 S  0.0  0.3   0:00.04 lifeguard          
	 1536 root      20   0  2656  364  200 S  0.0  0.1   0:00.01 lifeguard          
	 1696 root      20   0  2656  752  584 S  0.0  0.3   0:00.11 rc                 
	 1969 root      20   0  1840  824  400 S  0.0  0.3   0:00.15 recEvent           
	 1971 root      15  -5     0    0    0 S  0.0  0.0   0:00.18 AR6K Async         
	 1994 root      -2  -5     0    0    0 S  0.0  0.0   0:00.01 ksdiorqd           
	 2020 root      20   0  3448 1600 1276 S  0.0  0.6   0:00.06 wpa_supplicant     
	 2210 messageb  20   0  2236  812  588 S  0.0  0.3   0:00.21 dbus-daemon        
	 2303 root      20   0 19608 1100  868 S  0.0  0.4   0:00.04 pmond              
	 2353 root      20   0 19680 1420 1212 S  0.0  0.6   0:00.07 powerd             
	 2479 root      20   0 36032 1432 1188 S  0.0  0.6   0:00.08 cmd                
	 2660 root      20   0 35784 1084  916 S  0.0  0.4   0:00.03 mcsd               
	 2723 root      20   0 19600 1288 1100 S  0.0  0.5   0:00.06 volumd             
	 2938 root      20   0 41792 4220 3580 S  0.0  1.6   0:00.31 audioServer        
	 3124 root      20   0  2652  552  464 S  0.0  0.2   0:00.00 crond              
	 3129 root      20   0 38936 2660 2240 S  0.0  1.0   0:00.09 tmd                
	 3130 root      20   0 19324 1028  872 S  0.0  0.4   0:00.01 lipc-daemon        
	 3400 root      20   0  2656  456  288 S  0.0  0.2   0:00.02 rc                 
	 3419 root      20   0  2656  744  596 S  0.0  0.3   0:00.03 sh                 
	 3470 root      20   0  2656  356  188 S  0.0  0.1   0:00.00 S96boot_finishe    
	 3471 root      20   0 19316 1060  920 S  0.0  0.4   0:00.01 lipc-wait-event    
	 3695 root      20   0 29340  12m 8096 S  0.0  4.9   0:00.61 KindleApp          
	 3712 root      20   0  2652  548  472 S  0.0  0.2   0:00.01 sh                 
	
	
	
	killall: mplayer: no process killed
	07-31 08:00:38:318-<TID: 109667836> DIAGNOSTIC: Begin execute command: sysctl vm.overcommit_memory=1
	Unknown HZ value! (79) Assume 100.
	vm.overcommit_memory = 1
	07-31 08:00:38:342-<TID: 109667836> DIAGNOSTIC: End execute command: sysctl vm.overcommit_memory=1
	07-31 08:00:38:389-<TID: 109667836> DIAGNOSTIC: m_testLowAlarm : 0
	07-31 08:00:38:391-<TID: 109667836> DIAGNOSTIC: DKPowerManagerImpl::UpdatePowerLevel init power=40, voltage=3713, mAH=643
	07-31 08:00:38:393-<TID: 109667836> DIAGNOSTIC: DKPowerManagerImpl::StartPowerdMonitor()
	07-31 08:00:38:398-<TID: 109667836> DIAGNOSTIC: DKPowerManagerImpl::StartWaitEvent()
	07-31 08:00:38:400-<TID: 109671336> DIAGNOSTIC: Read string from shell begin: lipc-wait-event  -s 60 com.lab126.powerd outOfScreenSaver,goingToScreenSaver,userShutdown,outOfShutdown,charging,notCharging,battLevelChanged 2>>/mnt/us/DK_System/xKindle/powerError.log
	07-31 08:00:38:438-<TID: 111349057> DIAGNOSTIC: sigwaitinfo() begin wait sig
	07-31 08:00:38:448-<TID: 109667836> DIAGNOSTIC: Initialize BookStore Managers
	07-31 08:00:38:848-<TID: 111495694> DIAGNOSTIC: CStartProgress::ProgressThread (0, 80)
	07-31 08:00:38:867-<TID: 109667836> DIAGNOSTIC: DKPowerManagerImpl::AccquireLock, lock(0),src=9,m_lockNum=0
	07-31 08:00:38:869-<TID: 109667836> DIAGNOSTIC: DKPowerManagerImpl::AccquireLock:preventScreenSaver 1
	07-31 08:00:38:938-<TID: 113173416> DIAGNOSTIC: DKPowerManagerImpl::ReleaseLock, lock(0),src=9,m_lockNum=1
	07-31 08:00:38:939-<TID: 113173416> DIAGNOSTIC: DKPowerManagerImpl::ReleaseLock, preventScreenSaver 0
	07-31 08:00:38:993-<TID: 109667836> DIAGNOSTIC: Begin Init Keyboard
	
	
	07-31 08:00:47:843-<TID: 109667836> DIAGNOSTIC: SetScreenSaverStatus:0
	07-31 08:00:47:854-<TID: 109667836> DIAGNOSTIC: Begin Create FileManager
	07-31 08:00:47:856-<TID: 109667836> DIAGNOSTIC: Begin LoadFileToFileManger
	07-31 08:00:48:224-<TID: 109667836> DIAGNOSTIC: Main cost 1 seconds to scan all 25 files
	07-31 08:00:48:225-<TID: 109667836> DIAGNOSTIC: Read string from shell begin: free
	Unknown HZ value! (80) Assume 100.
	07-31 08:00:48:253-<TID: 109667836> DIAGNOSTIC: Read string from shell end: free
	07-31 08:00:48:255-<TID: 109667836> DIAGNOSTIC: free space:
	             total       used       free     shared    buffers     cached
	Mem:        256536     135400     121136          0      24824      72604
	-/+ buffers/cache:      37972     218564
	Swap:            0          0          0
	
	07-31 08:00:48:302-<TID: 115133352> DIAGNOSTIC: DKPowerManagerImpl::AccquireLock, lock(0),src=2,m_lockNum=0
	07-31 08:00:48:303-<TID: 115133352> DIAGNOSTIC: DKPowerManagerImpl::AccquireLock:preventScreenSaver 1
	07-31 08:00:48:364-<TID: 111495694> DIAGNOSTIC: CStartProgress::ProgressThread over!
	07-31 08:00:48:382-<TID: 115133352> DIAGNOSTIC: DKPowerManagerImpl::ReleaseLock, lock(0),src=2,m_lockNum=1
	07-31 08:00:48:385-<TID: 115133352> DIAGNOSTIC: DKPowerManagerImpl::ReleaseLock, preventScreenSaver 0
	07-31 08:00:49:513-<TID: 109667836> DIAGNOSTIC: m_testLowAlarm : 0
	07-31 08:00:49:515-<TID: 109667836> DIAGNOSTIC: Read string from file begin: /sys/devices/platform/fsl-usb2-udc/charging
	07-31 08:00:49:517-<TID: 109667836> DIAGNOSTIC: Read string from file end: /sys/devices/platform/fsl-usb2-udc/charging
	07-31 08:00:50:798-<TID: 109667836> DIAGNOSTIC: Begin Create main thread
	07-31 08:00:50:817-<TID: 109667836> DIAGNOSTIC: Start wait usb
	07-31 08:00:50:969-<TID: 109667836> DIAGNOSTIC: Back to home
	07-31 08:00:50:978-<TID: 109667836> DIAGNOSTIC: Read string from shell begin: free
	Unknown HZ value! (80) Assume 100.
	07-31 08:00:51:069-<TID: 109667836> DIAGNOSTIC: Read string from shell end: free
	07-31 08:00:51:071-<TID: 109667836> DIAGNOSTIC: free space:
	             total       used       free     shared    buffers     cached
	Mem:        256536     143480     113056          0      24940      73720
	-/+ buffers/cache:      44820     211716
	Swap:            0          0          0
	
	
	
	ls
	pwd


# 4. Rootfs #

# 5. GUI #

