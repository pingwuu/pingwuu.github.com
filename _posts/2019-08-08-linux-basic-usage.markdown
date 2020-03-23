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



# 99. Reference URL

1) [https://wiki.apertis.org/Main_Page](https://wiki.apertis.org/Main_Page)

2) [QNX Doc](http://www.qnx.com/developers/docs/)



