---
layout: post
title: "sync a fork of a repository to keep it up-to-date with the upstream repository"
date: 2015-06-10 15:05:40 +0800
comments: true
categories: git github
---
# 1. Configuring a remote for a fork #

To sync changes you make in a fork with the original repository, you must configure a remote that points to the upstream repository in Git.

## 1.1 Open Terminal (for Mac users) or the command prompt (for Windows and Linux users) ##

## 1.2 List the current configured remote repository for your fork ##
	$ git remote -v
	  origin  https://github.com/YOUR_USERNAME/YOUR_FORK.git (fetch)
	  origin  https://github.com/YOUR_USERNAME/YOUR_FORK.git (push)

## 1.3 Specify a new remote upstream repository that will be synced with the fork ##
	$ git remote add upstream https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git

## 1.4 Verify the new upstream repository you've specified for your fork ##
	$ git remote -v
	  origin    https://github.com/YOUR_USERNAME/YOUR_FORK.git (fetch)
	  origin    https://github.com/YOUR_USERNAME/YOUR_FORK.git (push)
	  upstream  https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git (fetch)
	  upstream  https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY.git (push)

# 2. Syncing a fork #

Sync a fork of a repository to keep it up-to-date with the upstream repository

2.1 Change the current working directory to your local project

2.2 Fetch the branches and their respective commits from the upstream repository. Commits to master will be stored in a local branch, upstream/master.

	$ git fetch upstream
	  remote: Counting objects: 75, done.
	  remote: Compressing objects: 100% (53/53), done.
	  remote: Total 62 (delta 27), reused 44 (delta 9)
	  Unpacking objects: 100% (62/62), done.
	  From https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY
	   * [new branch]      master     -> upstream/master

2.3 Check out your fork's local master branch

	$ git checkout master
	  Switched to branch 'master'

2.4 Merge the changes from upstream/master into your local master branch. This brings your fork's master branch into sync with the upstream repository, without losing your local changes.

	$ git merge upstream/master
	  Updating a422352..5fdff0f
	  Fast-forward
	  README                    |    9 -------
	  README.md                 |    7 ++++++
	  2 files changed, 7 insertions(+), 9 deletions(-)
	  delete mode 100644 README
	  create mode 100644 README.md

2.5 If your local branch didn't have any unique commits, Git will instead perform a "fast-forward":

	$ git merge upstream/master
	  Updating 34e91da..16c56ad
	  Fast-forward
	  README.md                 |    5 +++--
	  1 file changed, 3 insertions(+), 2 deletions(-)

# 3. Pushing to a remote #

	$ git push  <REMOTENAME> <BRANCHNAME>   