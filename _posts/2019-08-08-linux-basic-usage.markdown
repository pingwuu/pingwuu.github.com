---
layout: post
title:  "Linux Basic Usage"
date:   2019-08-08 11:30:00 +0800
categories: linux
comments: true
---

# 1. Purpose

This blog will write linux basic usage

# 2. Basic Installation

## 2.1 Guest OS Version

```
ubuntu-18.04.3-desktop-amd64.iso
```

## 2.2 VirtualBox version

```
Oracle VirtualBox 6.0
```

## 2.3 Install basic linux  system

## 2.4 Guest OS configure

* Install openssh-server & openssh-client

```
$ sudo apt-get install openssh-server openssh-client
```

* Install samba

```
1) Install samba
$ sudo apt-get install samba samba-common

2) Add samba user/pwd
vmuser@vmuser:~$ sudo groupadd smb -g 6000
vmuser@vmuser:~$ sudo useradd smb -u 6000 -g 6000 -s /sbin/nologin -d /dev/null
vmuser@vmuser:~$ sudo smbpasswd -a smb
New SMB password:
Retype new SMB password:
Added user smb.

3) Edit smb.conf
$ sudo vim /etc/samba/smb.conf
### add below config ###
# share dir
[projects_16]
    comment = share projects folder
    path = /home/vmuser/projects
    browseable = yes
    read only = no
    guest ok = no
    create mask = 0777
    directory mask = 0777
    valid users = smb
    force user = nobody
    force group = nogroup
    public = yes
    available = yes
    writeable = yes
    
4) Restart samba service
$ sudo service smbd restart

//Access on Windows OS with samba user created
\\192.168.56.101\share
```



# 3. Proxy setting

## 3.1 apt proxy via socks5

```
sudo apt-get -o Acquire::http::proxy="socks5h://127.0.0.1:1080/" update
```

## 3.2 http(s) proxy setting

```
# 设置http代理
export http_proxy=

# 设置https代理
export HTTPS_PROXY=

# 设置ftp代理
export FTP_PROXY=

# 同时设置http、https以及ftp代理
export ALL_PROXY=

=================================================================================
Proxy setting on terminal
# 设置代理，只在当前终端有效
$ export http_proxy=http://<IP>:<PORT>
或是
$ export http_proxy=socks5://127.0.0.1:1080
$ export HTTPS_PROXY=socks5://127.0.0.1:1080

# 取消代理
$ unset http_proxy
$ unset https_proxy

```

Reference URL: https://www.cnblogs.com/hupeng1234/p/9783336.html



## 3.3 Git Proxy

```
# 以下使用http代理
git config --global http.proxy http://127.0.0.1:1080
git config --global https.proxy https://127.0.0.1:1080

# 以下使用socks5代理
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'

# 取消代理
git config --global --unset http.proxy
git config --global --unset https.proxy

//Handle subsequent SSL protocol errors
git -c http.sslVerify=false clone https://domain.com/path/to/git
git config http.sslVerify false
git config --global http.https://domain.com.sslVerify false


//Unset SSL verification
git config --global --unset http.sslVerify
git config --global --unset http.https://domain.com.sslVerify
```



## 3.3 Yocto Proxy Setting

Ref: https://www.wangzhi.vip/?p=186

```
设置主要参考以下官网Wiki的指南：
https://wiki.yoctoproject.org/wiki/Working_Behind_a_Network_Proxy

wget http://git.yoctoproject.org/cgit/cgit.cgi/poky/plain/scripts/oe-git-proxy
mkdir ~/bin
cp oe-git-proxy ~/bin
chmod +x ~/bin/oe-git-proxy

vim ~/.bashrc
-------------------------------------------------------------------------------
export http_proxy='http://192.168.2.9:8118/'
export https_proxy='https://192.168.2.9:8118/'
export ALL_PROXY='socks5://192.168.2.9:1080/'
export all_proxy='socks5://192.168.2.9:1080/'
export no_proxy='192.168.1.7'
export GIT_PROXY_COMMAND="oe-git-proxy"
export NO_PROXY=$no_proxy
-------------------------------------------------------------------------------

vim ~/.wgetrc
-------------------------------------------------------------------------------
http_proxy=http://192.168.2.9:8118
https_proxy=https://192.168.2.9:8118
no_proxy=192.168.1.7
use_proxy=on
-------------------------------------------------------------------------------
```



## 3.4 [How to use pip with socks proxy?](https://stackoverflow.com/questions/22915705/how-to-use-pip-with-socks-proxy)

```
$ pip install pysocks
$ pip install <yourpacakge> --proxy socks5:127.0.0.1:8123
```



## 3.5 Docker Proxy

```
$ cat /etc/systemd/system/docker.service.d/proxy.conf 
[Service]
Environment="HTTP_PROXY=socks5://127.0.0.1:1080"
Environment="HTTPS_PROXY=socks5://127.0.0.1:1080"
Environment="NO_PROXY="localhost,127.0.0.1,::1"
```





# 4. DTC

# 4.1 Decompile dtb to dts

```
[kris@:~/kernel_imx/scripts/dtc]$

./dtc -I dtb -O dts ../../arch/arm/boot/dts/imx6q-sabresd-ldo.dtb  > ~/f.dts
```



# 5. commands

## 5.1 Kernel version
```

```



# 6. Install package

## 6.1 Install Mono on Ubuntu

Ref: https://gist.github.com/carolynvs/4520736f6017ca252a44

```
wget http://download.mono-project.com/repo/xamarin.gpg
sudo apt-key add xamarin.gpg
echo "deb http://download.mono-project.com/repo/debian wheezy main" | sudo tee --append /etc/apt/sources.list.d/mono-xamarin.list
sudo apt-get update
sudo apt-get install mono-complete

sudo certmgr -ssl -m https://go.microsoft.com
sudo certmgr -ssl -m https://nugetgallery.blob.core.windows.net
sudo certmgr -ssl -m https://nuget.org
mozroots --import --sync
```



# 7. Shrink virtual disk (VDI) of a VirtualBox VM (Linux)

Ref URL: https://askubuntu.com/questions/1092812/zerofree-on-ubuntu-18-04

```
Here's how I did it on Ubuntu 18.04 Server guest

Put Ubuntu 18.04 Desktop Live CD in VM's optical drive (make sure boot sequence loads this first)
Boot VM, when CD asks: click Try Ubuntu
Once GUI is up, run terminal
sudo apt install zerofree and let it install
sudo fdisk -l and note system HD e.g. /dev/sda2
sudo zerofree -v /dev/sda2 and let it finish
halt
ACPI shutdown VM
Remove Ubuntu 18.04 Desktop Live CD from VM's optical drive before restarting

or download zerofree_1.0.4-1_amd64.deb to install

$ wget http://archive.ubuntu.com/ubuntu/pool/main/z/zerofree/zerofree_1.0.4-1_amd64.deb
$ sudo dpkg -i zerofree_1.0.4-1_amd64.deb
```

Then on windows

```
> >D:\ProgramFiles\Oracle\VirtualBox\VBoxManage  modifymedium disk  C:\_00_VM\ubuntu_18_04_4\ubuntu_18_04_4.vdi  -compact
```



# 8. Ubuntu Source Backup

## 8.1 Ubuntu 16 sources

//tsinghua for ubuntu 16

```
# deb cdrom:[Ubuntu 16.04 LTS _Xenial Xerus_ - Release amd64 (20160420.1)]/ xenial main restricted
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial universe
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates universe
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security universe
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security multiverse

```



# 90. FAQ

## 90.1 The following packages have unmet dependencies:
Q:

```
sudo apt-get install openssh-server 
Reading package lists... Done
Building dependency tree       
Reading state information... Done
Some packages could not be installed. This may mean that you have
requested an impossible situation or if you are using the unstable
distribution that some required packages have not yet been created
or been moved out of Incoming.
The following information may help to resolve the situation:


The following packages have unmet dependencies:
 openssh-server : Depends: openssh-client (= 1:7.6p1-4)
                  Depends: openssh-sftp-server but it is not going to be installed
                  Recommends: ssh-import-id but it is not going to be installed
E: Unable to correct problems, you have held broken packages.
```

A: update /etc/apt/source.list as below
```
# deb cdrom:[Lubuntu 18.04 LTS _Bionic Beaver_ - Release amd64 (20180426)]/ bionic main multiverse restricted universe

# See http://help.ubuntu.com/community/UpgradeNotes for how to upgrade to
# newer versions of the distribution.
deb http://us.archive.ubuntu.com/ubuntu/ bionic main restricted
# deb-src http://us.archive.ubuntu.com/ubuntu/ bionic main restricted


## Major bug fix updates produced after the final release of the
## distribution.
deb http://us.archive.ubuntu.com/ubuntu/ bionic-updates main restricted
# deb-src http://us.archive.ubuntu.com/ubuntu/ bionic-updates main restricted


## N.B. software from this repository is ENTIRELY UNSUPPORTED by the Ubuntu
## team. Also, please note that software in universe WILL NOT receive any
## review or updates from the Ubuntu security team.
# deb-src http://us.archive.ubuntu.com/ubuntu/ bionic universe
# deb-src http://us.archive.ubuntu.com/ubuntu/ bionic-updates universe


## N.B. software from this repository is ENTIRELY UNSUPPORTED by the Ubuntu 
## team, and may not be under a free licence. Please satisfy yourself as to 
## your rights to use the software. Also, please note that software in 
## multiverse WILL NOT receive any review or updates from the Ubuntu
## security team.
deb http://us.archive.ubuntu.com/ubuntu/ bionic multiverse
# deb-src http://us.archive.ubuntu.com/ubuntu/ bionic multiverse
deb http://us.archive.ubuntu.com/ubuntu/ bionic-updates multiverse
# deb-src http://us.archive.ubuntu.com/ubuntu/ bionic-updates multiverse


## N.B. software from this repository may not have been tested as
## extensively as that contained in the main release, although it includes
## newer versions of some applications which may provide useful features.
## Also, please note that software in backports WILL NOT receive any review
## or updates from the Ubuntu security team.
# deb http://us.archive.ubuntu.com/ubuntu/ bionic-backports main restricted universe multiverse
# deb-src http://us.archive.ubuntu.com/ubuntu/ bionic-backports main restricted universe multiverse

## Uncomment the following two lines to add software from Canonical's
## 'partner' repository.
## This software is not part of Ubuntu, but is offered by Canonical and the
## respective vendors as a service to Ubuntu users.
deb http://archive.canonical.com/ubuntu bionic partner
# deb-src http://archive.canonical.com/ubuntu bionic partner


deb http://security.ubuntu.com/ubuntu bionic-security main restricted
# deb-src http://security.ubuntu.com/ubuntu bionic-security main restricted
# deb-src http://security.ubuntu.com/ubuntu bionic-security universe
deb http://security.ubuntu.com/ubuntu bionic-security multiverse
# deb-src http://security.ubuntu.com/ubuntu bionic-security multiverse
```

# 99. Reference URL

1) [https://wiki.apertis.org/Main_Page](https://wiki.apertis.org/Main_Page)

2) [QNX Doc](http://www.qnx.com/developers/docs/)

3) [How To Easily Upgrade Linux Kernel In Ubuntu And Linux Mint -ukuu](https://itsfoss.com/upgrade-linux-kernel-ubuntu/)

4) [http://mirrors.aliyun.com/ubuntu-releases/](http://mirrors.aliyun.com/ubuntu-releases/)






