---
layout: post
title:  "Docker basic Usage"
date:   2019-07-09 16:30:00 +0800
categories: docker linux
comments: true
---

**Table of Content**

- [1. Uninstall old version docker](#1-uninstall-old-version-docker)
- [99. Reference Link](#99-reference-link)



# 1. Uninstall old version docker

```
$ sudo apt-get remove docker docker-engine docker.io containerd runc
```

# 2. docker basic usage

1) list images
```
$ docker images
REPOSITORY            TAG            IMAGE ID       CREATED          SIZE
pingwuu/yocto-build   ubuntu-18.04   02a63fbab8d2   23 minutes ago   2.22GB
hello-world           latest         9c7a54a9a43c   3 months ago     13.3kB
```

2) list container id and image name
```
$ docker ps -a
CONTAINER ID   IMAGE                              COMMAND            CREATED          STATUS                      PORTS     NAMES
bbc84e7c9756   xxx/yocto-build:ubuntu-18.04       "/entrypoint.sh"   22 minutes ago   Up 22 minutes                         yocto-build
386324c34c1b   31de9f781484                       "/entrypoint.sh"   48 minutes ago   Exited (0) 27 minutes ago             practical_feynman
fd6bdf2cb606   31de9f781484                       "/entrypoint.sh"   2 hours ago      Exited (0) 49 minutes ago             beautiful_chatterjee
7e45166d091e   31de9f781484                       "/entrypoint.sh"   2 hours ago      Exited (0) 2 hours ago                sad_banach
7ac972c80cc9   hello-world                        "/hello"           3 hours ago      Exited (0) 3 hours ago                stupefied_easley
43135fdc9f23   hello-world                        "/hello"           3 hours ago      Exited (0) 3 hours ago                dazzling_allen
```

3) docker image push
```
$ docker login
Authenticating with existing credentials...

Login Succeeded
$ docker image push xxx/yocto-build:ubuntu-18.04
```

10) Install package in running docker container
```
* Start your container sudo docker run -it --net=host IMAGE_NAME
* Access your container using bash: sudo docker exec -it CONTAINER_ID bash
* Install whatever you need inside the container
* Exit container's bash
//For example: install liblz4-tool via prox using sock5h
# apt-get -o Acquire::http::proxy="socks5h://127.0.0.1:51837/" install liblz4-tool

* Commit your changes: sudo docker commit -m "commit message" CONTAINER_ID NEW_IMAGE_NAME

```

# 99. Reference Link





