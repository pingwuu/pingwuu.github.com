---
layout: post
title: "v4l and gstreamer"
date: 2015-09-29 11:05:58 +0800
comments: true
categories: v4l gstreamer ipu csi camera
---

# 1. V4L Test commmand #

## 1.1 Overlay ##
	root@freescale ~$ cd /unit_tests/
	root@freescale /unit_tests$ /unit_tests/mxc_v4l2_overlay.out -iw 720 -ih 480 -it 0 -il 0 -ow 720 -oh 480 -ot 50 -ol 200

## 1.2 TVIN ##
	root@freescale ~$ cd /unit_tests/
	
	root@freescale /unit_tests$ /unit_tests/mxc_v4l2_tvin.out -ow 720 -oh 480 -ot 20 -ol 20 -c 10 -m 0 -tb -f YUYV
	root@freescale /unit_tests$ /unit_tests/mxc_v4l2_tvin.out -ow 720 -oh 480 -ot 20 -ol 20 -c 10 -m 0 -tb -f UYVY
	
	root@freescale /unit_tests$ /unit_tests/mxc_v4l2_tvin.out -ow 720 -oh 480 -ot 20 -ol 20 -c 10 -m 0 -tb -f NV12

	root@freescale /unit_tests$ /unit_tests/mxc_v4l2_tvin.out -ow 720 -oh 480 -ot 20 -ol 20 -c 10 -m 0 -tb -f NV12


# 2. GStreamer Test Command #

# 1. Display videotest pattern #

	$ gst-launch -v videotestsrc ! mfw_v4lsink


# 2. Video loopback #

## 2.1 Single Camera ##

	$ gst-launch -v mfw_v4lsrc ! mfw_v4lsink

	$ gst-launch -v mfw_v4lsrc device=/dev/video0 ! mfw_v4lsink disp-width=720 disp-height=480

	$ gst-launch -v mfw_v4lsrc device=/dev/video0 ! video-sink="mfw_isink axis-top=0 axis-left=0 disp-width=720 disp-height=420"

	$ gst-launch -v mfw_v4lsrc device=/dev/video0 ! mfw_isink disp-width=720 disp-height=480

## 2.1 Single TV Decoder ##

	$ gst-launch -v tvsrc ! mfw_v4lsink

	$ gst-launch -v tvsrc ! mfw_isink

	$ gst-launch -v tvsrc ! mfw_v4lsink axis-top=50 axis-left=100  disp-width=720 disp-height=480

	$ gst-launch -v tvsrc device=/dev/video0 ! mfw_v4lsink axis-top=50 axis-left=100  disp-width=720 disp-height=480
