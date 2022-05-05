---
layout: post
title:  "Git Basic Usage"
date:   2019-06-14 16:00:00 +0800
categories: git repo
comments: true
---

# 1. git  basic command

## 1.1 Git Config for Global repo

```  script
git config --global user.name "username"
git config --global user.email "email"
```

## 1.2 Git Config for Local repo

```
git config user.name "username"
git config user.email "email"
```

## 1.3 Git Proxy

```
# 以下使用http代理
git config --global http.proxy http://127.0.0.1:1080
git config --global https.proxy https://127.0.0.1:1080

# 以下使用socks5代理
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'

# proxy for one site
$ git config --global http.https://android.googlesource.com/.proxy 'socks5://127.0.0.1:1080'
$ git config --global https.https://android.googlesource.com/.proxy 'socks5://127.0.0.1:1080'

# 取消代理
git config --global --unset http.proxy
git config --global --unset https.proxy
git config --global --unset http.https://android.googlesource.com/.proxy
git config --global --unset https.https://android.googlesource.com/.proxy

//Handle subsequent SSL protocol errors
git -c http.sslVerify=false clone https://domain.com/path/to/git
git config http.sslVerify false
git config --global http.https://domain.com.sslVerify false


//Unset SSL verification
git config --global --unset http.sslVerify
git config --global --unset http.https://domain.com.sslVerify
```

## 1.4 git-lfs install

```
$ curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
$ sudo apt-get install git-lfs
$ git lfs install
```

## 1.5 http(s) proxy setting

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

## 1.6 apt proxy via socks5

```
sudo apt-get -o Acquire::http::proxy="socks5h://127.0.0.1:1080/" update
```



## 1.7 git log options

* How to git log in reverse order?

```
$ git log --reverse
```

* Git log before some commit date

```
$ git log --before="2011-12-01" --pretty=format:"%cd"
```



# 2. SSH key for git

## 2.1 Generate a new SSH key

```
$ ssh-keygen -t rsa -C "your_email@example.com"
```

## 2.2 Add public key to your bitbucket, github or gitee account

--- Please refer [https://confluence.atlassian.com/bitbucketserver/ssh-user-keys-for-personal-use-776639793.html](https://confluence.atlassian.com/bitbucketserver/ssh-user-keys-for-personal-use-776639793.html)

```
1) Check ssh key for github
> ssh -T git@github.com
Hi username! You've successfully authenticated, but GitHub does not
# provide shell access.
```

```
2) Check ssh key for bitbucket
> $ ssh -T git@bitbucket.org
```

```
3)Check ssh key for Gitee
$ ssh -T git@gitee.com
```

```
4) Check ssh key for gitlab
$ ssh -T git@gitlab.com

If the welcome message doesn’t appear, you can troubleshoot the problem by running ssh in verbose mode with the following command:
$ ssh -Tvvv git@gitlab.com
```

## 2.3 Manage multiple usernames for git/ssh config

```
1) > touch ~/.ssh/config & add below content
# github
Host github.com
    HostName github.com
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/id_rsa_github
    User user_github

# bitbucket
Host bitbucket.org
    HostName bitbucket.org
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/id_rsa_bitbucket
    User user_bitbucket

# gitlab
Host gitlab.com
  Preferredauthentications publickey
  IdentityFile ~/.ssh/id_rsa_gitlab
  user user_gitlab
  ProxyCommand nc -x localhost:1080 %h %p  # using proxy localhost:1080 for git command
```

Ref URL: [Use Proxy for Git/GitHub](https://gist.github.com/coin8086/7228b177221f6db913933021ac33bb92)

## 2.4 Git SSH Proxy setup

Create or edit ~/.ssh/config file

```
## ssh access bitbucket.or via HTTP proxy
Host bitbucket.org
    ProxyCommand connect -H 127.0.0.1:1081 %h %p

## other sites, do NOT use proxy
Host *
    ProxyCommand connect %h %p

```

# 3. How to clone all branches and tags between remote git repositories

## 3.1 Branches

* 1) See local branches

```
$ git branch 
* master
```

* 2) See remote branches

```
$ git branch -r
  origin-gitlab/master
  origin/HEAD -> origin/master
  origin/master
```

* 3) See all local and remote branches

```
$ git branch -a
* master
  remotes/origin-gitlab/master
  remotes/origin/HEAD -> origin/master
  remotes/origin/master
```

* 4) Track remote all branch

```
//Track remote origin all branches
$ remote=origin ; for brname in `git branch -r | grep $remote | grep -v master | grep -v HEAD | awk '{gsub(/^[^\/]+\//,"",$1); print $1}'`; do git branch --track $brname $remote/$brname || true; done 2>/dev/null
```

* 5) Push all branches to remote

```
$ git push -u --all origin
```

## 3.2 Tags

* 1) List Local Git Tags

```
$ git tag

v1.0
v2.0
```

* 2) List Remote Git Tags

```
$ git ls-remote --tags origin

53a7dcf1ca57e05d456321b406730b39dc8ed75e        refs/tags/v1.0
7a9ad7fd794bf52a11de43aacc6010978e6100d3        refs/tags/v2.0
```

* 3) Fetching Remote Tags Easily

```
$ git fetch --all --tags

Fetching origin
From git-repository
   53a7dc..7a9ad7    master     -> origin/master
 * [new tag]         v1.0       -> v1.0
 * [new tag]         v1.0       -> v2.0
```

* 4) Push tags to a remote Repo:

 In order to push them to a remote repo, you have a few options: 

```
$ git push <repo-name> <tag-name>
```

This command will push a single tag to the remote repo, and it is commonly the preferred method 

 The other way would be to push *all* of the tags to the remote repo: 

```
$ git push --tags <repo-name>
```

# 4. Breakpoint Resume

由于`git clone`不支持断点续传，所以可以使用支持断点续传的`git fetch`。一个简单的步骤如下所示，请按自己的需求酌情更改：

```
mkdir linux && cd linux
git init
git fetch git://mirrors.ustc.edu.cn/linux.git
git checkout FETCH_HEAD
```

# 5. Linux Kernel Git Stable

如需克隆 linux 代码，使用

```
git clone https://mirrors.tuna.tsinghua.edu.cn/git/linux-stable.git
```

若要将 tuna mirror 加入已有代码库，可在已有仓库中运行

```
git remote add tuna https://mirrors.tuna.tsinghua.edu.cn/git/linux-stable.git
```

或运行

```
git remote set-url origin https://mirrors.tuna.tsinghua.edu.cn/git/linux-stable.git
```

将默认上游设置为 TUNA 镜像

# 6. Configuring a remote for a fork

1. Open Git Bash.

2. List the current configured remote repository for your fork.

   ```shell
   $ git remote -v
   > origin  https://github.com/YOUR_USERNAME/YOUR_FORK.git (fetch)
   > origin  https://github.com/YOUR_USERNAME/YOUR_FORK.git (push)
   ```

3. Specify a new remote *upstream* repository that will be synced with the fork.

   ```shell
   $ git remote add upstream https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git
   ```

4. Verify the new upstream repository you've specified for your fork.

   ```shell
   $ git remote -v
   > origin    https://github.com/YOUR_USERNAME/YOUR_FORK.git (fetch)
   > origin    https://github.com/YOUR_USERNAME/YOUR_FORK.git (push)
   > upstream  https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git (fetch)
   > upstream  https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git (push)
   ```

# 7. Syncing a fork

Sync a fork of a repository to keep it up-to-date with the upstream repository.

Before you can sync your fork with an upstream repository, you must [configure a remote that points to the upstream repository](https://help.github.com/en/articles/configuring-a-remote-for-a-fork) in Git.

1. Open Git Bash.

2. Change the current working directory to your local project.

3. Fetch the branches and their respective commits from the upstream repository. Commits to `master` will be stored in a local branch, `upstream/master`.

   ```shell
   $ git fetch upstream
   > remote: Counting objects: 75, done.
   > remote: Compressing objects: 100% (53/53), done.
   > remote: Total 62 (delta 27), reused 44 (delta 9)
   > Unpacking objects: 100% (62/62), done.
   > From https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY
   >  * [new branch]      master     -> upstream/master
   ```

4. Check out your fork's local `master` branch.

   ```shell
   $ git checkout master
   > Switched to branch 'master'
   ```

5. Merge the changes from `upstream/master` into your local `master` branch. This brings your fork's `master` branch into sync with the upstream repository, without losing your local changes.

   ```shell
   $ git merge upstream/master
   > Updating a422352..5fdff0f
   > Fast-forward
   >  README                    |    9 -------
   >  README.md                 |    7 ++++++
   >  2 files changed, 7 insertions(+), 9 deletions(-)
   >  delete mode 100644 README
   >  create mode 100644 README.md
   ```

   If your local branch didn't have any unique commits, Git will instead perform a "fast-forward":

   ```shell
   $ git merge upstream/master
   > Updating 34e91da..16c56ad
   > Fast-forward
   >  README.md                 |    5 +++--
   >  1 file changed, 3 insertions(+), 2 deletions(-)
   ```

# 8. Syncing a Fork of a GitHub Repository with Upstream

Ref URL:  https://ardalis.com/syncing-a-fork-of-a-github-repository-with-upstream

For this example I’m going to use the [Microsoft .NET Docs GitHub repo](https://github.com/dotnet/docs) as the upstream repo and [my own fork of the docs repo](https://github.com/ardalis/docs-1) as the fork I’m trying to sync.

The first thing you need to do is make sure you have a git remote configured for the upstream (original, source) repository. You can view your current remotes with this command:

```
$ git remote
origin
```

To add the repository from which you forked and name it upstream, you would use the `git remote add` command like so:

```
$ git remote add upstream https://github.com/dotnet/docs.git
```

You can confirm it worked by running `git remote` again:

```
$ git remote
origin
upstream
```

Now you need to sync your local git repo with the upstream version. There are 3 git repositories involved here: upstream, origin, local. You’re going to apply changes from upstream to local first, and then push them to origin after that’s done. To get the changes from the upstream repo, you need to *fetch* them (and specify the remote).

```
$ git fetch upstream
```

Now check out your master branch and merge the upstream master into it:

```
$ git checkout master
Switched to branch 'master'
 
$ git merge upstream/master
Updating  <code>a422352..5fdff0f
...
```

At this point your local repo is up to date with the upstream repo. The last step is to push your changes up to your fork on GitHub.

```
$ git push
```

And you’re done! Now you’re all set to work on your 2nd (or Nth) pull request for the upstream repository using the same fork you created some time ago.

## Reset to Upstream

What if things are out of whack and you just want to reset your branch to the upstream version, losing anything that may be committed to your fork that you don’t intend to pull request upstream? Follow these steps, [originally described here](https://stackoverflow.com/a/42332860/13729):

```
# ensures current branch is master
git checkout master
 
# pulls all new commits made to upstream/master
git pull upstream master
 r
# this will delete all your local changes to master
git reset --hard upstream/master
 
# take care, this will delete all your changes on your forked master
git push origin master --force
```

# 9. Submodule

## 9.1 add submodule

```
$ git submodule add <url> <path>	//add submodule
$ git diff --cached 				//check added submodule info
$ git commit ...					//commit
$ git push ...						//push to repo
```

# 10. Export and Import Patches with git

REF: https://davidwalsh.name/git-export-patch

## 10.1 Exporting a Patch

Let's say you've created a feature branch for your impending changeset, made changes, and committed those changes.  Now it's time to export your commits to a patch file -- you would execute the following:

```shell
git format-patch master --stdout > my-patch-file.patch
```

The command above outputs your commits to a `.patch` file.  This patch file can be imported into other repositories for testing, application, etc.  Some repositories require the most detailed patch output.  You can provide that with:

```shell
git format-patch master --full-index --stdout > my-patch-file.patch
```

From the git documentation, `--full-index` signifies: *Instead of the first handful of characters, show the full pre- and post-image blob object names on the "index" line when generating patch format output.*

## 10.2 Importing a Patch

If you receive a patch file, you'll want to do a few checks before trying to merge it!

### Ensure Patch Relevance

You can ensure the patch applies to the current set of work:

```shell
# See if patch is applicable
git apply --check my-patch-file.patch

# Ensure patch applies to current index
git apply --index my-patch-file.patch
```

### View Patch Diff Information

If you want to know which files have been changed, added, or removed, you can use the following command:

```shell
# See which files have been changed
git apply --stat my-patch-file.patch
```

### Merge the Code

Once you're satisfied with the patch code and want to merge and test (testing should be done on a feature branch), you can execute:

```shell
# Signs the patch by merger for history
git am --signoff my-patch-file.patch
```

Welcome to some of the operations that GitHub (and likewise services) do for us in the background.  I love doing stuff from [command line](https://davidwalsh.name/tutorials/shell) but I'd much rather use  an elegant front-end for this type of stuff.  In the case you're stuck without a UI, however, keep these commands handy!



## 10.3 How to using git to generate and apply patch

使用方法（直接给一些examples）：

**git format-patch**

```
$ git format-patch HEAD^ 　　　　　　　　　　　　　  #生成最近的1次commit的patch

$ git format-patch HEAD^^　　　　　　　　　　　　　 #生成最近的2次commit的patch

$ git format-patch HEAD^^^ 　　　　　　　　　　　　　#生成最近的3次commit的patch

$ git format-patch HEAD^^^^ 　　　　　　　　　　　   #生成最近的4次commit的patch

$ git format-patch <r1>..<r2>                       #生成两个commit间的修改的patch（包含两个commit. <r1>和<r2>都是具体的commit号)

$ git format-patch -1 <r1>                          #生成单个commit的patch

$ git format-patch <r1>                            #生成某commit以来的修改patch（不包含该commit）

$ git format-patch --root <r1>　　　　　　　　　　　　  #生成从根到r1提交的所有patch
```

 

**git am**

```
$ git apply --stat 0001-limit-log-function.patch  　　　 # 查看patch的情况

$ git apply --check 0001-limit-log-function.patch  　　 # 检查patch是否能够打上，如果没有任何输出，则说明无冲突，可以打上

(注：git apply是另外一种打patch的命令，其与git am的区别是，git apply并不会将commit message等打上去，打完patch后需要重新git add和git commit，而git am会直接将patch的所有信息打上去，而且不用重新git add和git commit,author也是patch的author而不是打patch的人)

$ git am 0001-limit-log-function.patch                # 将名字为0001-limit-log-function.patch的patch打上

$ git am --signoff 0001-limit-log-function.patch         # 添加-s或者--signoff，还可以把自己的名字添加为signed off by信息，作用是注明打patch的人是谁，因为有时打patch的人并不是patch的作者

$ git am ~/patch-set/*.patch　　　　　　　　　　　　　# 将路径~/patch-set/*.patch 按照先后顺序打上

$ git am --abort                                  # 当git am失败时，用以将已经在am过程中打上的patch废弃掉(比如有三个patch，打到第三个patch时有冲突，那么这条命令会把打上的前两个patch丢弃掉，返回没有打patch的状态)

$ git am --resolved                               #当git am失败，解决完冲突后，这条命令会接着打patch
```



**如果打Patch的过程中发生了冲突（conflicts），怎么办？**

解决patch冲突的过程是：

**如果不想打这一系列patch了，直接：git am --abort。**

如果还想打, 有两种解决方案：

**方案一（个人推荐）：**

(1) 根据git am失败的信息，找到发生冲突的具体patch文件，然后用命令git apply --reject <patch_name>，强行打这个patch，发生冲突的部分会保存为.rej文件（例如发生冲突的文件是a.txt，那么运行完这个命令后，发生conflict的部分会保存为a.txt.rej），未发生冲突的部分会成功打上patch

(2) 根据.rej文件，通过编辑该patch文件的方式解决冲突。

(3) 废弃上一条am命令已经打了的patch：git am --abort

(4) 重新打patch：git am ~/patch-set/*.patchpatch

**方案二：**

(1) 根据git am失败的信息，找到发生冲突的具体patch文件，然后用命令git apply --reject <patch_name>，强行打这个patch，发生冲突的部分会保存为.rej文件（例如发生冲突的文件是a.txt，那么运行完这个命令后，发生conflict的部分会保存为a.txt.rej），未发生冲突的部分会成功打上patch

(2) 根据.rej文件，通过编辑发生冲突的code文件的方式解决冲突。

(3) 将该patch涉及到的所有文件（不仅仅是发生冲突的文件）通过命令git add <file_name>添加到工作区中

(4) 告诉git冲突已经解决，继续打patch: git am --resolved (git am --resolved 和 git am --continue是一样的)

 

**分析**：方案一和方案二主要区别是解决冲突的方法不一样。方案一是通过编辑patch文件的方式解决冲突，方案二十通过编辑冲突code文件的方式解决冲突。这两种方案区别比较大：经过实验，核心区别在于，方案二无法验证冲突有没有切实的解决。即使你在方案二的第二步乱改一通，也能“打完”发生冲突的patch（并没有检测修改后的code文件跟patch期望的是否相同）。因此，如果采用方案二，那么再解决code文件冲突后，需要人工去确认修改的正确性。

# 11 repo Usage

## 11.1 repo basic cmd

```
//list branch
$ repo branches
```

## 11.2 Use repo on Windows to download android source

[https://lynxbee.com/use-repo-on-windows-to-download-android-source/#.YnM-LOjP1PZ](https://lynxbee.com/use-repo-on-windows-to-download-android-source/#.YnM-LOjP1PZ)

**Start git-bash with “Right Click” and “Run as administrator”**

As mentioned in the beginning, Windows doesn’t support hyperlink creation for non-admin users hence if you dont have admin permissions to start git bash, there are options as mentioned in https://github.com/git-for-windows/git/wiki/Symbolic-Links using which you can still be able to enable hyperlink creation with git-bash for non-admin user, but this also will need atleast once help from someone who has admin permissions to enable developer mode or other options as mentioned in link.

**On the started terminal, create a directory and type below commands,**

```
$ export MSYS="winsymlinks:nativestrict"
$ curl https://storage.googleapis.com/git-repo-downloads/repo > ~/repo
$ chmod 777 ~/repo
```

In this example, we will demo how you can download Android opensource code aosp, with branch “android-8.1.0_r7” , you can change it to your server url and branch as necessary.

```
$ mkdir aosp_src
$ cd aosp_src
$ ~/repo init -u https://android.googlesource.com/platform/manifest -b android-8.1.0_r75
$ repo sync
```



# 90 FAQ

## 90.1 How to fix “Filename too long error” during git clone

```
$ git config --system core.longpaths true

or

$ git clone -c core.longpaths=true <repo-url>
```

## 90.2 git : How to remove a big file wrongly committed

I added a large file to a git repository (102Mb), commited and push and got an error due to size limit limitations on github

```
remote: error: GH001: Large files detected. You may want to try Git Large File Storage - https://git-lfs.github.com. remote: error: Trace: 7d51855d4f834a90c5a5a526e93d2668 remote: error: See http://git.io/iEPt8g for more information. remote: error: File coverage/sensitivity/simulated.bed is 102.00 MB; this exceeds GitHub's file size limit of 100.00 MB
```

Here, you see the path of the file (coverage/sensitivity/simualted.bed).

So, the solution is actually quite simple (when you know it): you can use the filter-branch command as follows:

```
git filter-branch --tree-filter 'rm -rf path/to/your/file' HEAD git push
```

Ref:https://thomas-cokelaer.info/blog/2018/02/git-how-to-remove-a-big-file-wrongly-committed/

## 9.3 Ubuntu18.04：gnutls_handshake() failed: Error in the pull function.

Ubuntu18.04：gnutls_handshake() failed: Error in the pull function.
克隆GitHub仓库

git clone https://github.com/trekhleb/javascript-algorithms.git --depth=1
出现错误

fatal: unable to access 'https://github.com/trekhleb/javascript-algorithms.git/': gnutls_handshake() failed: Error in the pull function.
错误原因分析：

git使用了libcurl4-gnutls-dev，而在ubuntu18中该库作出了修改，导致git无法使用SSL进行连接。


解决方案1：安装依赖包

sudo apt-get -y install build-essential nghttp2 libnghttp2-dev libssl-dev
使用此方法暂时解决了问题，但不知道什么原因，重新与服务器建立连接后，又抛出了上面的错误。


解决方案2：重新编译并安装使用libcurl4–openssl–dev的git。

具体的脚本：

#安装需要的工具包
sudo apt-get update
sudo apt-get install build-essential fakeroot dpkg-dev
sudo apt-get build-dep git
sudo apt-get install libcurl4-openssl-dev    #应当在安装git构建依赖之后否则会报错无法查找到libcurl4-openssl-dev

mkdir ~/git-openssl
cd ~/git-openssl
apt-get source git    #git源码

cd git-2.17.1/    #根据你的git源码版本切换
sed -i 's/libcurl4-gnutls-dev/libcurl4-openssl-dev/g' debian/control    #将debian/control文件中libcurl4-gnutls-dev全部替换为libcurl4-openssl-dev
sed -i 's/TEST =test//g' debian/rules    #删除debian/rules文件中TEST =test

sudo dpkg-buildpackage -rfakeroot -b    #生成安装包
cd ..
sudo dpkg -i git_2.17.1-1ubuntu0.3_amd64.deb     #安装对应版本的git
注：Git的版本按照情况自行变更。

可能遇到的问题：
构建安装包失败。

原因：sed -i 's/libcurl4-gnutls-dev/libcurl4-openssl-dev/g' debian/control语句执行失效

解决方案：手动进行修改。编辑debian/control 文件并全部替换 libcurl4-gnutls-dev 为 libcurl4-openssl-dev 删除debian/rules文件中的TEST=test 重新编译并安装。

然而，本人在执行sudo dpkg-buildpackage -rfakeroot -b时抛出了错误，由于是新服务器，可能缺少部分依赖，所以果断选择了第三种解决方案。


解决方案3：执行使用编译好的安装包安装。

安装包下载：git_openssl_2.17.1

执行安装：

sudo dpkg -i git_2.17.1-1ubuntu0.3_amd64.deb 
成功！！！
————————————————
版权声明：本文为CSDN博主「南极浮冰」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_39132520/article/details/114924970

# 99. Reference URL

* 1) [Git mirror available in Beijing](http://cdn.kernel.org/beijing-git-mirror.html)
