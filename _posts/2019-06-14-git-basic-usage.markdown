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

# 1.3 Git Proxy

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



# 1.3 git-lfs install

```
$ curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
$ sudo apt-get install git-lfs
$ git lfs install
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



# 90 FAQ

## 90.1 How to fix “Filename too long error” during git clone

```
$ git config --system core.longpaths true

or

$ git clone -c core.longpaths=true <repo-url>
```



# 99. Reference URL

* 1) [Git mirror available in Beijing](http://cdn.kernel.org/beijing-git-mirror.html)
* 

