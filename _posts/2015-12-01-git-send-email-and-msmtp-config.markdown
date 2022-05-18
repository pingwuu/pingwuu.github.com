---
layout: post
title: "git send-email and msmtp config"
date: 2015-12-01 14:40:40 +0800
comments: true
categories: git
---
# 1. msmtp setup and config(using gmail as example) #

	$ apt-get install msmtp
	$ vim ~/.msmtprc
	#########################################################
	account default
	host smtp.gmail.com
	# it seems port 587 not works
	#port 587
	port 25
	from xx.xx@gmail.com
	tls on
	tls_starttls on
	tls_trust_file /home/vmuser/.certs/Equifax_Secure_CA.pem
	# Or use the following for the system certificates, if installed:
	# tls_trust_file /etc/ssl/certs/ca-certificates.crt
	auth on
	user xxx	#<username of gmail>
	logfile ~/.msmtp.log
	###########################################################

# 2. Download the SSL Certificates #

	$ mkdir -pv $HOME/.certs 
	$ cd $HOME/.certs 
	$ touch Equifax_Secure_CA.pem 
	$ wget --no-check-certificate https://github.com/bagder/curl/raw/master/lib/mk-ca-bundle.pl
	$ perl mk-ca-bundle.pl

	# copy extract the "Equifax Secure CA" certificate of ca-bundle.crt to Equifax_Secure_CA.pem
	
	-----BEGIN CERTIFICATE-----
	MIIDIDCCAomgAwIBAgIENd70zzANBgkqhkiG9w0BAQUFADBOMQswCQYDVQQGEwJVUzEQMA4GA1UE
	ChMHRXF1aWZheDEtMCsGA1UECxMkRXF1aWZheCBTZWN1cmUgQ2VydGlmaWNhdGUgQXV0aG9yaXR5
	MB4XDTk4MDgyMjE2NDE1MVoXDTE4MDgyMjE2NDE1MVowTjELMAkGA1UEBhMCVVMxEDAOBgNVBAoT
	B0VxdWlmYXgxLTArBgNVBAsTJEVxdWlmYXggU2VjdXJlIENlcnRpZmljYXRlIEF1dGhvcml0eTCB
	nzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEAwV2xWGcIYu6gmi0fCG2RFGiYCh7+2gRvE4RiIcPR
	fM6fBeC4AfBONOziipUEZKzxa1NfBbPLZ4C/QgKO/t0BCezhABRP/PvwDN1Dulsr4R+AcJkVV5MW
	8Q+XarfCaCMczE1ZMKxRHjuvK9buY0V7xdlfUNLjUA86iOe/FP3gx7kCAwEAAaOCAQkwggEFMHAG
	A1UdHwRpMGcwZaBjoGGkXzBdMQswCQYDVQQGEwJVUzEQMA4GA1UEChMHRXF1aWZheDEtMCsGA1UE
	CxMkRXF1aWZheCBTZWN1cmUgQ2VydGlmaWNhdGUgQXV0aG9yaXR5MQ0wCwYDVQQDEwRDUkwxMBoG
	A1UdEAQTMBGBDzIwMTgwODIyMTY0MTUxWjALBgNVHQ8EBAMCAQYwHwYDVR0jBBgwFoAUSOZo+SvS
	spXXR9gjIBBPM5iQn9QwHQYDVR0OBBYEFEjmaPkr0rKV10fYIyAQTzOYkJ/UMAwGA1UdEwQFMAMB
	Af8wGgYJKoZIhvZ9B0EABA0wCxsFVjMuMGMDAgbAMA0GCSqGSIb3DQEBBQUAA4GBAFjOKer89961
	zgK5F7WF0bnj4JXMJTENAKaSbn+2kmOeUJXRmm/kEd5jhW6Y7qj/WsjTVbJmcVfewCHrPSqnI0kB
	BIZCe/zuf6IWUrVnZ9NA2zsmWLIodz2uFHdh1voqZiegDfqnc1zqcPGUIWVEX/r87yloqaKHee95
	70+sB3c4
	-----END CERTIFICATE-----

	# rehash the certificate so Openssl knows how to find it:
	$ c_rehash $HOME/.certs/

	
	# There remains a final touch, since the username and password are openly in this file you should make the file readable only by the file owner:
	$ chmod 600 ~/.fetchmailrc

# 3. git send-email config #
	
	$ git config --global sendemail.smtpencryption tls
	$ git config --global sendemail.confirm auto
	
	$ cat ~/.gitconfig
	######################################3333
	[user]
        email = xx.xx@gmail.com
        name = Xxx Xx
	[color]
	        ui = auto
	[core]
	        editor = vim
	[sendemail]
	        from = Xxx Xx <xxx.xx@gmail.com>
	        smtpuser =
	        smtpserver = "/usr/bin/msmtp"
	        smtpencryption = tls
	        chainreplyto = false
	        confirm = auto

# 4. Submitting patches #

	$ cd git_repo
	$ git fetch --all --tags
	$ git rebase origin/master	# or other branch
 	
	# To generate it, run:
	$ git format-patch -M -n -s -o outgoing origin/master	
	# This will generate patch files in the outgoing subdirectory, automatically adding the Signed-off-by line.

	# Lastly, send/submit your patch set to the git-repo mailing list:
	$ git send-email --to xxx@xxx.xxx outgoing/*


# 5. Reference link #
	1) https://www.drupal.org/node/831870
	2) http://www.andrews-corner.org/mutt.html
	3) http://blog.csdn.net/orz365/article/details/9236143
