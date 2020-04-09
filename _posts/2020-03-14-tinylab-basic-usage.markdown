---
layout: post
title:  "Tinylab Basic Usage"
date:   2019-12-04 11:30:00 +0800
categories: tinylab qemu linux u-boot
comments: true
---

# 1. Ubuntu Install

* Ubuntu Version:  Ubuntu 18.04.04 Desktop
* Install Type: Minimal Install

# 2. Docker Install

1) Update the apt package index

```
$ sudo apt-get update
```

2)  Install packages to allow apt to use a repository over HTTPS

```
$ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common
```

3) Add Docker’s official GPG key

```
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
```



Aliyun Mirrors Setting if your network speed is slow to access https://download.docker.com/ site:

```
# step 1: 安装必要的一些系统工具
sudo apt-get update
sudo apt-get -y install apt-transport-https ca-certificates curl software-properties-common
# step 2: 安装GPG证书
curl -fsSL http://mirrors.aliyun.com/docker-ce/linux/ubuntu/gpg | sudo apt-key add -

# step 2.2: check key
sudo apt-key fingerprint 0EBFCD88

# Step 3: 写入软件源信息
sudo add-apt-repository "deb [arch=amd64] http://mirrors.aliyun.com/docker-ce/linux/ubuntu $(lsb_release -cs) stable"
# Step 4: 更新并安装 Docker-CE
sudo apt-get -y update
sudo apt-get -y install docker-ce docker-ce-cli containerd.io

注意：其他注意事项在下面的注释中
# 安装指定版本的Docker-CE:
# Step 1: 查找Docker-CE的版本:
# apt-cache madison docker-ce
#   docker-ce | 17.03.1~ce-0~ubuntu-xenial | http://mirrors.aliyun.com/docker-ce/linux/ubuntu xenial/stable amd64 Packages
#   docker-ce | 17.03.0~ce-0~ubuntu-xenial | http://mirrors.aliyun.com/docker-ce/linux/ubuntu xenial/stable amd64 Packages
# Step 2: 安装指定版本的Docker-CE: (VERSION 例如上面的 17.03.1~ce-0~ubuntu-xenial)
# sudo apt-get -y install docker-ce=[VERSION]

//****** This version is ok for ubuntu18.04.3 ******
# sudo apt-get -y install docker-ce=5:19.03.7~3-0~ubuntu-bionic docker-ce-cli=5:19.03.7~3-0~ubuntu-bionic containerd.io

# 通过经典网络、VPC网络内网安装时，用以下命令替换Step 2、Step 3中的命令
# 经典网络：
# curl -fsSL http://mirrors.aliyuncs.com/docker-ce/linux/ubuntu/gpg | sudo apt-key add -
# sudo add-apt-repository "deb [arch=amd64] http://mirrors.aliyuncs.com/docker-ce/linux/ubuntu $(lsb_release -cs) stable"
# VPC网络：
# curl -fsSL http://mirrors.cloud.aliyuncs.com/docker-ce/linux/ubuntu/gpg | sudo apt-key add -
# sudo add-apt-repository "deb [arch=amd64] http://mirrors.cloud.aliyuncs.com/docker-ce/linux/ubuntu $(lsb_release -cs) stable"
```



Verify that you now have the key with the fingerprint `9DC8 5822 9FC7 DD38 854A E2D8 8D81 803C 0EBF CD88`, by searching for the last 8 characters of the fingerprint

```
$ sudo apt-key fingerprint 0EBFCD88
    
pub   rsa4096 2017-02-22 [SCEA]
      9DC8 5822 9FC7 DD38 854A  E2D8 8D81 803C 0EBF CD88
uid           [ unknown] Docker Release (CE deb) <docker@docker.com>
sub   rsa4096 2017-02-22 [S]
```

4) Use the following command to set up the **stable** repository. To add the **nightly** or **test** repository, add the word `nightly` or `test` (or both) after the word `stable` in the commands below. [Learn about **nightly** and **test** channels](https://docs.docker.com/install/)

```
$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
```



#### INSTALL DOCKER ENGINE - COMMUNITY

1) Update the `apt` package index

```
$ sudo apt-get update
```

2) Install the *latest version* of Docker Engine - Community and containerd, or go to the next step to install a specific version

```
$ sudo apt-get install docker-ce docker-ce-cli containerd.io
```

3) [Option] To install a *specific version* of Docker Engine - Community, list the available versions in the repo, then select and install

a. List the versions available in your repo

```
$ apt-cache madison docker-ce

  docker-ce | 5:18.09.1~3-0~ubuntu-xenial | https://download.docker.com/linux/ubuntu  xenial/stable amd64 Packages
  docker-ce | 5:18.09.0~3-0~ubuntu-xenial | https://download.docker.com/linux/ubuntu  xenial/stable amd64 Packages
  docker-ce | 18.06.1~ce~3-0~ubuntu       | https://download.docker.com/linux/ubuntu  xenial/stable amd64 Packages
  docker-ce | 18.06.0~ce~3-0~ubuntu       | https://download.docker.com/linux/ubuntu  xenial/stable amd64 Packages
  ...
```

b. Install a specific version using the version string from the second column, for example, `5:18.09.1~3-0~ubuntu-xenial`

```
$ sudo apt-get install docker-ce=<VERSION_STRING> docker-ce-cli=<VERSION_STRING> containerd.io
```

4) Docker Mirror Setting

a. Aliyun Docker Mirror

[Aliyun Docker Mirror Documentation](https://help.aliyun.com/document_detail/60750.html)

您可以通过修改daemon配置文件/etc/docker/daemon.json来使用加速器

```
sudo mkdir -p /etc/docker
sudo tee /etc/docker/daemon.json <<-'EOF'
{
  "registry-mirrors": ["https://<your accelerate address>.mirror.aliyuncs.com"]
}
EOF
sudo systemctl daemon-reload
sudo systemctl restart docker
```

b. USTC Docker Mirror

```

```

5) Verify that Docker Engine - Community is installed correctly by running the `hello-world` image

```
$ sudo docker run hello-world
```



6) Add current user to docker user group to avoid sudo

```
$ sudo usermod -aG docker $USER
```

# 3. Tinylab setup & run

```
$ git clone https://gitee.com/tinylab/cloud-lab.git
$ cd cloud-lab && tools/docker/choose linux-lab

$ tools/docker/pull   # Pull from docker hub
$ tools/docker/run
$ tools/docker/vnc
```



# 4. Add a new board to linux-lab

Using arm/mcimx6ul-evk as example to describle.

1) Add a repo for bsp





Misc

====================================================

Build qemu4.2.0 under tinyclub issue:

ubuntu@linux-lab:/labs/linux-lab$ make qemu-defconfig

[ internal gcc-4.7 ]:

Remote.:
Local..: /usr/bin/
Tool...: arm-linux-gnueabi-gcc
Version: arm-linux-gnueabi-gcc (Ubuntu/Linaro 4.7.3-12ubuntu1) 4.7.3
More...: /usr/bin/arm-linux-gnueabi-gcc-4.3 /usr/bin/arm-linux-gnueabi-gcc-4.7


ERROR: glib-2.48 gthread-2.0 is required to compile QEMU

make: *** [/labs/linux-lab/output/arm/qemu-v4.2.0-mcimx6ul-evk/.stamp_qemu-defconfig] Error 1



# 99. Reference URL

* 1) [Docker CE 镜像源站](https://yq.aliyun.com/articles/110806?spm=5176.8351553.0.0.5b2f1991iQZMic)
* 2) [Docker 教程](https://www.runoob.com/docker/docker-tutorial.html)
* 

