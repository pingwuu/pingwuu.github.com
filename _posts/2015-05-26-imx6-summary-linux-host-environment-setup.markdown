---
layout: post
title: "imx6 summary linux host environment setup"
date: 2015-05-26 08:52:12 +0800
comments: true
categories: imx6 linux
---
# 	1.	Install Host OS #

##  1.1	Install VMware ##

    Version: VMware10.03

## 	1.2	Install ubuntu server on VMware ##

	Version: ubuntu-14.04.2-server-amd64

## 	1.3 Update Sources ##

    $sudo apt-get update

# 	2.	Install Host OS Service #

##  2.1 Install ssh service ##

    $ sudo apt-get install openssh-client openssh-server

## 	2.2	Install samba service ##

    $ sudo apt-get install samba
	
	$ sudo vim /etc/samba/smb.conf and add below section to the file end

	[home]
	comment = samba share path /home
	browseable = yes
	writeable = yes
	path = /home
	valid users = smb

	$ sudo useradd smb			//add user smb
	
	$ sudo smbpasswd -a smb		//set password for smb user

	$ /etc/init.d/smbd restart	//restart smbd service


# 	3.	Install Host OS build essential #

    $ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib \
		build-essential chrpath socat libsdl1.2-dev xterm curl tcl rpm bison m4 \
		zlib1g zlib1g-dev libncurses5-dev liblzo2-dev uuid-dev lzop texi2html texinfo \
		texlive gettext libgtk2.0-dev rpm bison m4 libfreetype6-dev libdbus-glib-1-dev \
		liborbit2-dev intltool ccache libtool uuid-dev liblzo2-dev tcl dpkg asciidoc \
		texlive-latex-base dblatex xutils-dev texlive texinfo lib32z1 lib32ncurses5 \
		lib32bz2-1.0 libc6-dev-i386 u-boot-tools scrollkeeper dos2unix
