---
layout: post
title:  "Shrink VMWare VMDK File"
date:   2023-02-27 10:00:00 +0800
categories: VMware
comments: true
---

# 1. tools and shrinking on guest
* Tools needed on guest
```
$ sudo apt install open-vm-tools
```

* Shrinking vmdk on guest
```
$ vmware-toolbox-cmd disk shrink /
```

# 2. shrinking on host
*Defrag
```
vmware-vdiskmanager.exe -d /path/to/shrink.vmdk
```

* Final Shrink
```
vmware-vdiskmanager.exe -k /path/to/shrink.vmdk
```

# 99. reference link

* 1) [Shrink VMWare VMDK File](https://christitus.com/shrink-vmware-vmdk/)

  
