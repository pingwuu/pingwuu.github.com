---
layout: post
title:  "Linux Command Basic Usage"
date:   2019-11-28 22:10:00 +0800
categories: linux command
comments: true
---

# 1. Purpose

This blog will introduce linux command basic usage



# 2. Basic Command

## 2.1 zip command

```
$ zip --help                                                                                           ✔  476  06:10:14 
Copyright (c) 1990-2008 Info-ZIP - Type 'zip "-L"' for software license.
Zip 3.0 (July 5th 2008). Usage:
zip [-options] [-b path] [-t mmddyyyy] [-n suffixes] [zipfile list] [-xi list]
  The default action is to add or replace zipfile entries from list, which
  can include the special name - to compress standard input.
  If zipfile and list are omitted, zip compresses stdin to stdout.
  -f   freshen: only changed files  -u   update: only changed or new files
  -d   delete entries in zipfile    -m   move into zipfile (delete OS files)
  -r   recurse into directories     -j   junk (don't record) directory names
  -0   store only                   -l   convert LF to CR LF (-ll CR LF to LF)
  -1   compress faster              -9   compress better
  -q   quiet operation              -v   verbose operation/print version info
  -c   add one-line comments        -z   add zipfile comment
  -@   read names from stdin        -o   make zipfile as old as latest entry
  -x   exclude the following names  -i   include only the following names
  -F   fix zipfile (-FF try harder) -D   do not add directory entries
  -A   adjust self-extracting exe   -J   junk zipfile prefix (unzipsfx)
  -T   test zipfile integrity       -X   eXclude eXtra file attributes
  -y   store symbolic links as the link instead of the referenced file
  -e   encrypt                      -n   don't compress these suffixes
  -h2  show more help
```

```
Example:
zip -r yasuo.zip abc.txt dir1 #Add file abx.txt and folder dir1 to zip file yasuo.zip
```

## 2.2 unzip command

```
$ unzip --help                                                                                         ✔  477  06:10:19 
UnZip 6.00 of 20 April 2009, by Debian. Original by Info-ZIP.

Usage: unzip [-Z] [-opts[modifiers]] file[.zip] [list] [-x xlist] [-d exdir]
  Default action is to extract files in list, except those in xlist, to exdir;
  file[.zip] may be a wildcard.  -Z => ZipInfo mode ("unzip -Z" for usage).

  -p  extract files to pipe, no messages     -l  list files (short format)
  -f  freshen existing files, create none    -t  test compressed archive data
  -u  update files, create if necessary      -z  display archive comment only
  -v  list verbosely/show version info       -T  timestamp archive to latest
  -x  exclude files that follow (in xlist)   -d  extract files into exdir
modifiers:
  -n  never overwrite existing files         -q  quiet mode (-qq => quieter)
  -o  overwrite files WITHOUT prompting      -a  auto-convert any text files
  -j  junk paths (do not make directories)   -aa treat ALL files as text
  -U  use escapes for all non-ASCII Unicode  -UU ignore any Unicode fields
  -C  match filenames case-insensitively     -L  make (some) names lowercase
  -X  restore UID/GID info                   -V  retain VMS version numbers
  -K  keep setuid/setgid/tacky permissions   -M  pipe through "more" pager
  -O CHARSET  specify a character encoding for DOS, Windows and OS/2 archives
  -I CHARSET  specify a character encoding for UNIX and other archives

See "unzip -hh" or unzip.txt for more help.  Examples:
  unzip data1 -x joe   => extract all files except joe from zipfile data1.zip
  unzip -p foo | more  => send contents of foo.zip via pipe into program more
  unzip -fo foo ReadMe => quietly replace existing ReadMe if archive file newer

```

# 2.3 tar command

1) Create tar Archive File

```
# tar -cvf tecmint-14-09-12.tar /home/tecmint/

/home/tecmint/
/home/tecmint/cleanfiles.sh
/home/tecmint/openvpn-2.1.4.tar.gz
/home/tecmint/tecmint-14-09-12.tar
/home/tecmint/phpmyadmin-2.11.11.3-1.el5.rf.noarch.rpm
/home/tecmint/rpmforge-release-0.5.2-2.el5.rf.i386.rpm
```

* **c** – Creates a new .tar archive file.

* **v** – Verbosely show the .tar file progress.

* **f** – File name type of the archive file.

2) Create tar.gz Archive File

```
# tar cvzf MyImages-14-09-12.tar.gz /home/MyImages
OR
# tar cvzf MyImages-14-09-12.tgz /home/MyImages

/home/MyImages/
/home/MyImages/Sara-Khan-and-model-Priyanka-Shah.jpg
/home/MyImages/RobertKristenviolent101201.jpg
/home/MyImages/Justintimerlake101125.jpg
/home/MyImages/Mileyphoto101203.jpg
/home/MyImages/JenniferRobert101130.jpg
/home/MyImages/katrinabarbiedoll231110.jpg
/home/MyImages/the-japanese-wife-press-conference.jpg
/home/MyImages/ReesewitherspoonCIA101202.jpg
/home/MyImages/yanaguptabaresf231110.jpg
```

3) Create tar.bz2 Archive File

```
# tar cvfj Phpfiles-org.tar.tb2 /home/php

/home/php/
/home/php/iframe_ew.php
/home/php/videos_all.php
/home/php/rss.php
/home/php/index.php
/home/php/vendor.php
/home/php/video_title.php
/home/php/report.php
/home/php/object.html
/home/php/video.php
```

### Reference Article

[ 18 Tar Command Examples in Linux ]( https://www.tecmint.com/18-tar-command-examples-in-linux/ )



## 2.4 Create a 1GB.bin random content file:

```
 dd if=/dev/urandom of=1GB.bin bs=64M count=16 iflag=fullblock
```

# 3.  update-alternatives 

 The following will set your `/usr/bin/python` to default to 2.7 but have 3.6 available when you want: 

```
sudo update-alternatives --install /usr/bin/python python /usr/bin/python2.7 20
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.6 10
```

 The highest priority here is used as the "automatic" choice for `/usr/bin/python` but you can easily switch by running

```
sudo update-alternatives --config python
```



# 4. Find Command

1) find "main(" string in *.c file of current path 

```
$ find . -name "*.c" -print | xargs grep "main("
```



# 5. Regular Expressions

Ref URL: https://linuxize.com/post/regular-expressions-in-grep/

## 5.1 Literal Matches

The most basic usage of the `grep` command is to search for a literal character or series of characters in a file. For example, to display all the lines containing the string “bash” in the [`/etc/passwd`](https://linuxize.com/post/etc-passwd-file/) file, you would run the following command:

```
grep bash /etc/passwdCopy
```

The output should look something like this:

```output
root:x:0:0:root:/root:/bin/bash
linuxize:x:1000:1000:linuxize:/home/linuxize:/bin/bash
```

In this example, the string “bash” is a basic regular expression that consists of a four literal characters. This tells `grep` to search for a string that has a “b” immediately followed by “a”, “s”, and “h”.

By default, the `grep` command is case sensitive. This means that the uppercase and lowercase characters are treated as distinct.

To ignore case when searching, use the `-i` option (or `--ignore-case`).

It is important to note that `grep` looks for the search pattern as a string, not a word. So if you were searching for “gnu”, `grep` will also print the lines where “gnu” is embedded in larger words, such as “cygnus” or “magnum”.

If the search string includes spaces, you need to enclose it in single or double quotation marks:

```
grep "Gnome Display Manager" /etc/passwdCopy
```





//todo

```
find | grep car | xargs rm -f
```



# 99. Reference URL



