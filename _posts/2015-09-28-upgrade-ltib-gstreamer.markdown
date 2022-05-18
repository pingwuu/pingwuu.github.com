---
layout: post
title: "upgrade ltib gstreamer"
date: 2015-09-28 15:54:48 +0800
comments: true
categories: ltib gstreamer
---
# 1. Upgrade glib2 to 2.28.8 #

## 1.1 Copy glib2 spec to dist/lfs/5.1/glib2/glib2.spec ##

#for glib2-2.28

	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : A library of functions used by GDK, GTK+, and many applications
	Name            : glib2
	Version         : 2.28.8
	Release         : 1
	License         : LGPL
	Vendor          : Freescale
	Packager        : Stuart Hughes/Kurt Mahan
	Group           : System Environment/Libraries
	Source          : glib-%{version}.tar.bz2
	Patch1          : glib2-2.12.11-relink.patch
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup -n glib-%{version}
	#%patch1 -p1
	
	%Build
	# prevent configure from trying to compile and
	# run test binaries for the target.
	glib_cv_stack_grows=no \
	glib_cv_uscore=no \
	ac_cv_func_posix_getpwuid_r=yes \
	ac_cv_func_posix_getgrgid_r=yes \
	./configure --prefix=%{_prefix} --host=$CFGHOST --build=%{_build}
	make
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*

#for glib2-2.30.2

	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : A library of functions used by GDK, GTK+, and many applications
	Name            : glib2
	Version         : 2.30.2
	Release         : 1
	License         : LGPL
	Vendor          : Freescale
	Packager        : Stuart Hughes/Kurt Mahan
	Group           : System Environment/Libraries
	Source          : glib-%{version}.tar.bz2
	Patch1          : glib2-2.12.11-relink.patch
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup -n glib-%{version}
	#%patch1 -p1
	
	%Build
	# prevent configure from trying to compile and
	# run test binaries for the target.
	glib_cv_stack_grows=no \
	glib_cv_uscore=no \
	glib_cv_have_qsort_r=yes \
	ac_cv_func_posix_getpwuid_r=yes \
	ac_cv_func_posix_getgrgid_r=yes \
	./configure --prefix=%{_prefix} --host=$CFGHOST --build=%{_build}
	make
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*
	
## 1.2 Download glib2-2.28.8.tar.bz2 from the web and copy it to /opt/freescale/pkgs ##
	$ ./ltib -p glib2 -m clean
	$ ./ltib -p glib2 -m prep
	$ ./ltib -p glib2 -m scbuild
	$ ./ltib -p glib2 -m scdeploy

# 2. Upgrade gstreamer-core #

## 2.1 Copy gstreamer-core spec to dist/lfs/5.1/gstreamer-core/gstreamer-core.spec  ##

	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : GStreamer Core
	Name            : gstreamer-core
	Version         : 0.10.35
	Release         : 2
	License         : LGPL
	Vendor          : Freescale Semiconductor
	Packager        : Kurt Mahan, Dexter Ji
	Group           : Applications/System
	Source          : gstreamer-%{version}.tar.gz
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup -n gstreamer-%{version}
	
	%Build
	./configure --prefix=%{_prefix} --host=$CFGHOST --build=%{_build} \
	            --disable-valgrind --without-check NM=nm
	make
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib/ -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*

## 2.2 Download gstreamer-core-0.10.35.tar.gz from the web and copy it to /opt/freescale/pkgs ##

	$ ./ltib -p gstreamer-core -m clean
	$ ./ltib -p gstreamer-core -m prep
	$ ./ltib -p gstreamer-core -m scbuild
	$ ./ltib -p gstreamer-core -m scdeploy

# 3. Upgrade gstreamer-base #

## 3.1 Copy gstreamer-base spec to dist/lfs/5.1/gst-plugins-base/gst-plugins-base.spec ##

	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : GStreamer Plugins Base
	Name            : gst-plugins-base
	Version         : 0.10.35
	Release         : 1
	License         : LGPL
	Vendor          : Freescale
	Packager        : Kurt Mahan, Dexter Ji
	Group           : Applications/System
	Source          : %{name}-%{version}.tar.gz
	Patch1          : %{name}-0.10.12-relink.patch
	Patch2          : %{name}0.10_%{version}-gstplaybin2_rawvideo_support.patch
	Patch3          : %{name}0.10_%{version}-fix-gstaudiobuild.patch
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup
	%patch1 -p1
	%patch2 -p1
	%patch3 -p1
	
	
	%Build
	export NM=nm
	if [ -z "$PKG_LIBX11" ]
	then
	    XTRA_OPTS="$XTRA_OPTS --without-x"
	fi
	./configure --prefix=%{_prefix} --host=$CFGHOST --build=%{_build} \
		    --disable-vorbis --disable-vorbistest --disable-freetypetest \
		    --disable-theora --disable-ogg --disable-oggtest --disable-pango\
		    --disable-libvisual --disable-cdparanoia --disable-failing-tests --disable-examples $XTRA_OPTS
	make
	
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib/ -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*

## 3.2 Download gst-plugins-base-0.10.35.tar.gz from the web and copy it to /opt/freescale/pkgs ##
	
	./ltib -p gst-plugins-base -m clean
	./ltib -p gst-plugins-base -m prep
	./ltib -p gst-plugins-base -m scbuild
	./ltib -p gst-plugins-base -m scdeploy

# 4. Upgrade gstreamer-bad #
## 4.1 Copy gst-plugins-bad spec to dist/lfs/5.1/gst-plugins-bad/gst-plugins-bad.spec ##

	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : GStreamer Plugins Bad
	Name            : gst-plugins-bad
	Version         : 0.10.22
	Release         : 1
	License         : LGPL
	Vendor          : Freescale
	Packager        : Kurt Mahan
	Group           : Applications/System
	Source          : gst-plugins-bad-%{version}.tar.gz
	Patch1          : gst-plugins-bad-0.10.4-relink.patch
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup
	%patch1 -p1
	
	%Build
	./configure --prefix=%{_prefix} --host=$CFGHOST \
		    --build=%{_build} --disable-valgrind \
		    --disable-x --disable-xvid \
		    --disable-ximagesrc --disable-jack \
		    --disable-sdl --disable-sdltest \
		    --x-includes= --x-libraries= \gst-plugins-bad-0.10.4-relink.patch \
		    --without-check NM=nm
	make
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*

## 4.2 Download gst-plugins-bad-0.10.22.tar.gz  from the web and copy it to /opt/freescale/pkgs ##
	
	./ltib -p gst-plugins-bad -m clean
	./ltib -p gst-plugins-bad -m prep
	./ltib -p gst-plugins-bad -m scbuild
	./ltib -p gst-plugins-bad -m scdeploy

# 4. Upgrade gst-plugins-good #
## 4.1 Copy gst-plugins-good spec to dist/lfs/5.1/gst-plugins-good/gst-plugins-good.spec ##

	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : GStreamer Plugins Good
	Name            : gst-plugins-good
	Version         : 0.10.30
	Release         : 1
	License         : LGPL
	Vendor          : Freescale
	Packager        : Dexter Ji
	Group           : Applications/System
	Source          : %{name}-%{version}.tar.gz
	Patch1          : %{name}-0.10.5-relink.patch
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup
	%patch1 -p1
	
	%Build
	#export CAIRO_CFLAGS="-I${DEV_IMAGE}/usr/include/cairo"
	#export CAIRO_LIBS="-L${DEV_IMAGE}/usr/lib/cairo"
	#export LIBS="-lcairo"
	
	./configure --prefix=%{_prefix} --host=$CFGHOST \
		    --build=%{_build} --without-check \
		    --disable-speex \
		    --disable-shout2test --disable-shout2 \
		    --disable-dv1394 --disable-libpng \
		    --disable-libdv --disable-libcaca \
		    --disable-ladspa --disable-jpeg \
		    --disable-flac \
		    --disable-esd --disable-esdtest \
		    --disable-cairo --disable-aalib \
		    --disable-aalibtest --disable-x \
		    --disable-xvideo --disable-hal NM=nm
	make
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib/ -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*	

## 4.2 Download gst-plugins-good-0.10.30.tar.gz  from the web and copy it to /opt/freescale/pkgs ##
	
	./ltib -p gst-plugins-good -m clean
	./ltib -p gst-plugins-good -m prep
	./ltib -p gst-plugins-good -m scbuild
	./ltib -p gst-plugins-good -m scdeploy

# 5. Upgrade gst-plugins-ugly #
## 5.1 Copy gst-plugins-ugly spec to dist/lfs/5.1/gst-plugins-ugly/gst-plugins-ugly.spec ##
	
	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : GStreamer Plugins Ugly
	Name            : gst-plugins-ugly
	Version         : 0.10.18
	Release         : 1
	License         : LGPL
	Vendor          : Freescale
	Packager        : Kurt Mahan
	Group           : Applications/System
	Source          : gst-plugins-ugly-%{version}.tar.gz
	Patch1          : gst-plugins-ugly-0.10.5-relink.patch
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup
	%patch1 -p1
	
	%Build
	./configure --prefix=%{_prefix} --host=$CFGHOST --build=%{_build} NM=nm
	make
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib/ -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*	

## 5.2 Download gst-plugins-ugly-0.10.18.tar.gz  from the web and copy it to /opt/freescale/pkgs ##
	
	./ltib -p gst-plugins-ugly -m clean
	./ltib -p gst-plugins-ugly -m prep
	./ltib -p gst-plugins-ugly -m scbuild
	./ltib -p gst-plugins-ugly -m scdeploy

# 6. Upgrade gst-ffmpeg #
## 6.1 Copy gst-ffmpeg spec to dist/lfs/5.1/gst-ffmpge/gst-ffmpeg.spec ##
		
	%define pfx /opt/freescale/rootfs/%{_target_cpu}
	
	Summary         : GStreamer plugin for FFmpeg codecs
	Name            : gst-ffmpeg
	Version         : 0.10.12
	Release         : 1
	License         : LGPL
	Vendor          : Freescale
	Packager        : John Faith
	Group           : Applications/System
	Source          : %{name}-%{version}.tar.gz
	Patch1          : gst-ffmpeg-0.10.3-relink.patch
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	URL             : http://gstreamer.freedesktop.org/src/gst-ffmpeg
	
	%Description
	%{summary}
	
	%Prep
	%setup
	%patch1 -p1
	
	%Build
	ac_cv_func_register_printf_function=no \
	./configure --prefix=%{_prefix} --host=$CFGHOST --build=%{_build} --without-check --disable-altivec
	DEBUG_CFLAGS="-g" make
	#make
	
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib/ -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*


## 6.2 Download gst-ffmpeg-0.10.12.tar.gz  from the web and copy it to /opt/freescale/pkgs ##
	
	./ltib -p gst-ffmpeg -m clean
	./ltib -p gst-ffmpeg -m prep
	./ltib -p gst-ffmpeg -m scbuild
	./ltib -p gst-ffmpeg -m scdeploy

# 7. Upgrade gst-plugins-farsight #
## 7.1 Copy gst-plugins-farsight spec to dist/lfs/5.1/gst-plugins-farsight/gst-plugins-farsight.spec ##

	%define pfx /opt/freescale/rootfs/%{_target_cpu}

	Summary         : Set of plugins for Gstreamer used Audio/Video conferencing
	Name            : gst-plugins-farsight
	Version         : 0.12.11
	Release         : 1
	License         : LGPL
	Packager        : Fadi Souilem/Stuart Hughes
	Group           : Applications/System
	Source          : %{name}-%{version}.tar.gz
	BuildRoot       : %{_tmppath}/%{name}
	Prefix          : %{pfx}
	
	%Description
	%{summary}
	
	%Prep
	%setup
	
	%Build
	./configure --prefix=%{_prefix} --host=$CFGHOST \
	        --disable-jingle-p2p \
	        --with-plugins=rtpmux,rtpdemux,rtpssrcdemux,rtppayloads
	
	make
	
	%Install
	rm -rf $RPM_BUILD_ROOT
	make install DESTDIR=$RPM_BUILD_ROOT/%{pfx}
	find $RPM_BUILD_ROOT/%{pfx}/%{_prefix}/lib -name "*.la" | xargs rm -f
	
	%Clean
	rm -rf $RPM_BUILD_ROOT
	
	%Files
	%defattr(-,root,root)
	%{pfx}/*


## 7.2 Download gst-plugins-farsight-0.12.11.tar.gz  from the web and copy it to /opt/freescale/pkgs ##
	
	./ltib -p gst-plugins-farsight -m clean
	./ltib -p gst-plugins-farsight -m prep
	./ltib -p gst-plugins-farsight -m scbuild
	./ltib -p gst-plugins-farsight -m scdeploy
