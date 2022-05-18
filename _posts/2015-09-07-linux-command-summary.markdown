---
layout: post
title: "linux command summary"
date: 2015-09-07 09:18:08 +0800
comments: true
categories: 
---

# 1. How to find files by content #
	$ find "main(" string in *.c file of current path
	$ find . -name "*.c" -print | xargs grep "main("

# 2. Check process memory status #
	$ top 					#using top to get process id
	$ cat /proc/70/status	#70 is the process id
	$ watch -n 10 cat /proc/70/status #check process memory status per 10s

# 3. Iterate all PID #
	$ for pid in `ps -ef | grep your_search_term | awk '{print $2}'` ; do kill $pid ; done

	Refer : http://stackoverflow.com/questions/21470362/find-the-pids-of-running-processes-and-store-as-an-array

	Just replace your_search_term with the process name you want to kill.

	You could also make it into a script and swap your_search_term for $1

	EDIT: I suppose I should explain how this works.

	The back ticks `` collects the output from the expression inside it. In this case it will return a list of pids for a process name.

	Using a for loop we can iterate through each pid and kill the process.

	EDIT2: replaced kill -9 with kill