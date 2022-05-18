---
layout: post
title: "Adding an existing project to Github"
date: 2015-05-26 08:12:55 +0800
comments: true
categories: git github
---

Ref: [https://help.github.com/articles/pushing-to-a-remote/](https://help.github.com/articles/pushing-to-a-remote/)

# 1. Create a new repository on Github #

	Example repo: https://github.com/github-username/test-repo.git

	#To avoid errors, do not initialize the new repository with README, license, or gitignore files. You can add these files after your project has been pushed to GitHub

# 2. Create a local repository on local machine #

	$ mkdir test-repo
	$ cd test-repo
	$ git init
	$ git config --global user.name "Your Name"			# remove --global for current git reop only
	$ git config --global user.email you@example.com	# remove --global for current git reop only
	$ git config --list									# list config
	$ touch test.txt
	$ git add .
	$ git commit -m "First commit"

# 3. Adding a remote repository url to local repository #

	$ git remote -v

	$ git remote add origin https://github.com/github-username/test-repo.git
	or
	$ git remote set-url origin https://github.com/github-username/test-repo.git	# for windows git command

	$ git remote -v
		origin  https://github.com/github-username/test-repo.git (fetch)
		origin  https://github.com/github-username/test-repo.git (push)

# 4. Push the changes in your local repository to Github #

	$ git push origin master

# 5. Renaming branches (remote) #
To rename a branch, you'd use the same git push command, but you would add one more argument: the name of the new branch. For example:

	git push  <REMOTENAME> <LOCALBRANCHNAME>:<REMOTEBRANCHNAME>
 
This pushes the LOCALBRANCHNAME to your REMOTENAME, but it is renamed to REMOTEBRANCHNAME.

# 6. Pushing tags #
By default, and without additional parameters, git push sends all matching branches that have the same names as remote branches.

To push a single tag, you can issue the same command as pushing a branch:

	git push  <REMOTENAME> <TAGNAME>
 
To push all your tags, you can type the command:

	git push  <REMOTENAME> --tags

# 7. Deleting a remote branch or tag #
The syntax to delete a branch is a bit arcane at first glance:

	git push  <REMOTENAME> :<BRANCHNAME> 

Note that there is a space before the colon. The command resembles the same steps you'd take to rename a branch. However, here, you're telling Git to push nothing into BRANCHNAME on REMOTENAME. Because of this, git push deletes the branch on the remote repository.

## 7.1 Deleting your master branch ##

You’ve forked some project on github.

You clone your fork.

Now you’ve got a master branch. It’s the master branch of your fork.

It can be tempting to do work in the master branch and ask for a pull request.

That is best avoided because:

It’s natural to carry on working in your master and that will pollute your pull request with other commits
master is not a descriptive name for a set of changes. It’s easier for the person reviewing your code to have something like fix-for-issue-12.
You may well also have a tracking branch pointing to the main upstream repo. You might call that something like upstream-master. It’s easy to lose concentration and forget you are on upstream-master instead of your master, and nasty errors can result.
To avoid this, I delete the master branch from my forked copy. However, to make that work, you have to tell github not to monitor your master branch.

## 7.2 How to delete master ##

First you delete master in your local clone. To do this we first make a new branch called placeholder or similar, and delete master from there:

	git branch placeholder
	git checkout placeholder
	git branch -D master
All good so far. We next want to delete the branch on github. However, if we do this the naive way:

	git push origin :master

we just get an error like this:

	remote: error: refusing to delete the current branch: refs/heads/master
	To git@github.com:matthew-brett/datarray.git
	! [remote rejected] master (deletion of the current branch prohibited)
	error: failed to push some refs to 'git@github.com:matthew-brett/datarray.git'

That is because github is looking at the master branch to provide the web content when you browse that repository. So we first have to make github look at our placeholder branch instead, then delete master.

First push up the placeholder branch:

	git checkout placeholder # if not on placeholder already
	git push origin placeholder

Then set placeholder to be the github default branch. Go to the main github page for your forked repository, and click on the “Admin” button.

There’s a “Default branch” dropdown list near the top of the screen. From there, select placeholder. On the interface I’m looking at, a green tick appears above the dropdown list. Now you can do (from the command line):

	git push origin :master

and - no master branch...

# 8. Remotes and forks #
You might already know that you can "fork" repositories on GitHub.

When you clone a repository you own, you provide it with a remote URL that tells Git where to fetch and push updates. If you want to collaborate with the original repository, you'd add a new remote URL, typically called upstream, to your local Git clone:

	git remote set-url upstream  <THEIR_REMOTE_URL>
 
Now, you can fetch updates and branches from their fork:

	git fetch upstream branch
	# Grab the upstream remote's branches
	# remote: Counting objects: 75, done.
	# remote: Compressing objects: 100% (53/53), done.
	# remote: Total 62 (delta 27), reused 44 (delta 9)
	# Unpacking objects: 100% (62/62), done.
	# From https://github.com/octocat/repo
	#  * [new branch]      master     -> upstream/master

When you're done making local changes, you can push your local branch to GitHub and initiate a pull request.
