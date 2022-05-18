---
layout: post
title: Octopress Install and Usage on Windows 7
date: 2015-04-14 09:15:12 +0800
categories: octopress github blog
---

## 1. 	Install git ##
 	
    	Version : Git-1.9.2-preview20140411.exe
    
## 2. 	Install RubyInstaller ##
 
    	Version: rubyinstaller-2.1.5-x64
    
## 3. 	Add Ruby install path(Example: D:\Ruby\Ruby21-x64\bin) to user's PATH Environment Variable ##
    
## 4. 	Install RubyInstaller DevKit ##
    
    	Version: DevKit-mingw64-64-4.7.2-20130224-1432-sfx.exe
    
## 5. 	RubyInstaller DevKit configure ##

### 5.1	change to DevKit install dir ###
    
        D:\> cd d:\Ruby\DevKit
    
### 5.2	ruby dk.rb init ###
    
        d:\Ruby\DevKit> ruby dk.rb init

        Initialization complete! Please review and modify the auto-generated
        'config.yml' file to ensure it contains the root directories to all
        of the installed Rubies you want enhanced by the DevKit.
        
        Add Ruby install path to config.yml as below
        
        #####################################################################
        #
        # Example:
        #
        # ---
        # - C:/ruby19trunk
        # - C:/ruby192dev
        #
        
        - D:\Ruby\Ruby21-x64        
        
        ######################################################################
    
        
### 5.3	ruby dk.rb install ###
    
        d:\Ruby\DevKit> ruby dk.rb install
    

## 6. 	Change ruby sources to http://ruby.taobao.org/ ##
    
        D:\> cd d:\Ruby\DevKit
        
        d:\Ruby\DevKit> gem sources --remove http://rubygems.org/
        
        d:\Ruby\DevKit> gem sources --remove https://rubygems.org/
        
        d:\Ruby\DevKit> gem sources -a http://ruby.taobao.org/
         
        d:\Ruby\DevKit> gem sources -l
        
        *** CURRENT SOURCES ***
    
        http://ruby.taobao.org/
    

## 7. 	Install rdoc and bundler ##

     
        D:\> cd d:\Ruby\DevKit
        
        d:\Ruby\DevKit>gem install rdoc bundler
            
        Depending on your version of ruby, you may need to install ruby rdoc/ri data:
        
        <= 1.8.6 : unsupported
         = 1.8.7 : gem install rdoc-data; rdoc-data --install
         = 1.9.1 : gem install rdoc-data; rdoc-data --install
        >= 1.9.2 : nothing to do! Yay!
        Successfully installed rdoc-4.2.0
        Parsing documentation for rdoc-4.2.0
        Done installing documentation for rdoc after 5 seconds
        Successfully installed bundler-1.9.3
        Parsing documentation for bundler-1.9.3
        Done installing documentation for bundler after 2 seconds
        2 gems installed
    
    
## 8	Install Octopress blog if you first using it on github ##

### 8.1	Create repo on your github ###

        Create a repo named username.github.com.git on your github

### 8.2 Clone octopress.git ###
        
        $ git clone git://github.com/imathis/octopress.git username.github.com
        
### 8.3 Modify octopress GEM Source ###

        $cd username.github.com
        
        $edit Gemfile  and change source "http://rubygems.org/"  to source "http://ruby.taobao.org/" 
        
        source "http://ruby.taobao.org/"
        
### 8.4	Install GEM component ###

        $ bundle install
        
        DL is deprecated, please use Fiddle
        Fetching source index from http://ruby.taobao.org/
        Resolving dependencies...............
        Installing rake 10.4.2
        Using RedCloth 4.2.9
        Installing blankslate 2.1.2.4
        Installing hitimes 1.2.2
        Installing timers 4.0.1
        Installing celluloid 0.16.0
        Using chunky_png 1.3.4
        Using fast-stemmer 1.0.2
        Installing classifier-reborn 2.0.3
        Installing coffee-script-source 1.9.1.1
        Installing execjs 2.5.2
        Installing coffee-script 2.4.1
        Installing colorator 0.1
        Installing multi_json 1.11.0
        Installing sass 3.4.13
        Installing compass-core 1.0.3
        Installing compass-import-once 1.0.5
        Using rb-fsevent 0.9.4
        Installing ffi 1.9.8
        Installing rb-inotify 0.9.5
        Installing compass 1.0.3
        Using tilt 2.0.1
        Installing haml 4.0.6
        Installing jekyll-coffeescript 1.0.1
        Installing jekyll-gist 1.2.1
        Installing jekyll-paginate 1.1.0
        Installing jekyll-sass-converter 1.3.0
        Installing listen 2.10.0
        Installing jekyll-watch 1.2.1
        Installing kramdown 1.6.0
        Installing liquid 2.6.2
        Installing mercenary 0.3.5
        Using posix-spawn 0.3.11
        Installing yajl-ruby 1.2.1
        Installing pygments.rb 0.6.3
        Installing redcarpet 3.2.3
        Installing safe_yaml 1.0.4
        Installing parslet 1.5.0
        Installing toml 0.1.2
        Installing jekyll 2.5.3
        Installing jekyll-sitemap 0.8.1
        Installing octopress-hooks 2.6.0
        Installing octopress-date-format 2.0.2
        Using rack 1.6.0
        Using rack-protection 1.5.3
        Installing rdiscount 2.1.8
        Using rubypants 0.2.0
        Using sass-globbing 1.0.0
        Using sinatra 1.4.6
        Using stringex 1.4.0
        Using bundler 1.9.3
        Bundle complete! 14 Gemfile dependencies, 51 gems now installed.
        Use `bundle show [gemname]` to see where a bundled gem is installed.
        Post-install message from compass:
            Compass is charityware. If you love it, please donate on our behalf at http://umdf.org/compass Thanks!
        Post-install message from haml:
        
        HEADS UP! Haml 4.0 has many improvements, but also has changes that may break
        your application:
        
        * Support for Ruby 1.8.6 dropped
        * Support for Rails 2 dropped
        * Sass filter now always outputs <style> tags
        * Data attributes are now hyphenated, not underscored
        * html2haml utility moved to the html2haml gem
        * Textile and Maruku filters moved to the haml-contrib gem
        
        For more info see:
        
        http://rubydoc.info/github/haml/haml/file/CHANGELOG.md
        
        
### 8.5	Install Octopress template file ###

        $ rake install
        
        rake aborted!
        You have already activated rake 10.1.0, but your Gemfile requires rake 0.9.6. Prepending `bundle exec` to your command may solve this.
        e:/study/username.github.com/Rakefile:2:in `<top (required)>'
        (See full trace by running task with --trace)
        
        
        #add "aliasalias rake='bundle exec rake'" to git bash bash_profile if display error as above
        
        $ echo "alias rake='bundle exec rake'" >> ~/.bash_profile
        
        $ . ~/.bash_profile
        $ aliasalias rake='bundle exec rake'
        $ rake install

### 8.6	setup octopress and github ##

        $ cd username.github.com.git
        $ rake setup_github_pages       #you need input username and password of you github account and blog url(https://github.com/username/username.github.com.git)

## 9 	Clone your Octopress if you had used it on github ##
    
### 9.1	Clone your Octopress repo ###
    
        $ git clone -b source https://github.com/username/username.github.com.git username.github.com.git   # replace username using yours
        
        Cloning into 'username.github.com'...
        remote: Counting objects: 5279, done.
        remote: Total 5279 (delta 0), reused 0 (delta 0), pack-reused 5279R
        Receiving objects: 100% (5279/5279), 1.37 MiB | 129.00 KiB/s, done.
        Resolving deltas: 100% (2537/2537), done.
        Checking connectivity... done.
		
		$ git clone -b master https://github.com/username/username.github.com.git _deploy  # replace username using yours

### 9.2	Install Octopress GEM component ###
        
        $ cd username.github.com.git
        
        $ bundle install
        
        DL is deprecated, please use Fiddle
        Fetching source index from http://ruby.taobao.org/
        Resolving dependencies...
        Installing rake 0.9.2.2
        Installing RedCloth 4.2.9
        Installing chunky_png 1.2.5
        Installing fast-stemmer 1.0.1
        Installing classifier 1.3.3
        Installing fssm 0.2.9
        Installing sass 3.2.9
        Installing compass 0.12.2
        Installing directory_watcher 1.4.1
        Installing haml 3.1.7
        Installing kramdown 0.13.8
        Installing liquid 2.3.0
        Installing syntax 1.0.0
        Installing maruku 0.6.1
        Installing posix-spawn 0.3.6
        Installing yajl-ruby 1.1.0
        Installing pygments.rb 0.3.4
        Installing jekyll 0.12.0
        Installing rack 1.5.2
        Installing rack-protection 1.5.0
        Installing rb-fsevent 0.9.1
        Installing rdiscount 2.0.7.3
        Installing rubypants 0.2.0
        Installing sass-globbing 1.0.0
        Installing tilt 1.3.7
        Installing sinatra 1.4.2
        Installing stringex 1.4.0
        Using bundler 1.9.3
        Bundle complete! 15 Gemfile dependencies, 28 gems now installed.
        Use `bundle show [gemname]` to see where a bundled gem is installed.
    
## 10	Add a remote name(default is origin) for the repository git@github.com:username/username.github.com.git ##
    
        $ cd username.github.com.git
        $ git remote
        
        origin
        
        $ git remote add origin git@github.com:username/username.github.com.git #default name is origin, you can change it       
        
## 11.	Management blog ##

        $ cd username.github.com.git
    
### 11.1 Add blog ###

        $ rake new_post["blog_name"]
    
### 11.2 Generate static file ###

        $ rake generate
    
### 11.3 Preview blog ###

        $ rake preview
    
        #now you can preview blog using local address on any browser: http://localhost:4000
    
### 11.4 Deploy blog to github ###

        $rake deploy
        
        #now you can access you blog using github address on any browser: http://username.github.com
                
## 	12. Management blog source code	 ##
        
###	12.1 Add file to local repo ###
        
        $ git add .
        
### 12.2 Commit file to repo ###

        $ git commit -m "commit file comment"
        
### 12.3 Push local repo file to remote ###

        $ git push origin source #origin is local repo name, source is branch name
        
### 12.4 Pull last remote repo file to local ###
	
        $ git pull orign source

### 12.5 Add a image to your blog ###

		1) add image file to source/images folder
		2) add below code to you blog
	
		![a brick](../images/a_brick.png "A brick")

### 12.6 Add attach file to your blog ###

    	1) add attach file to source/images folder
    	2) add a hyperlink and link address point to your file(such as ../images/test.txt)

=[Attached file here(test.txt)][1]


## 	13	Enable comment ##

### 13.1 Register an account on www.disqus.com ###

### 13.2 Register "unique Disqus URL" for github blog ###

### 13.3 Edit _config.yml as below###
	
	# Disqus Comments
	disqus_short_name: site_short_name_register_on_disqus
	disqus_show_comment_count: true
              
### 13.4 Enable comment on your blog as below ###
	
	---
	layout: post
	title: "title name"
	date: 2015-04-15 14:51:54 +0800
	comments: true
	categories: category1, category2 
	---
		

  [1]: ../images/test.txt


## 	14 	Pushing changes from two different machines ##
If you want to blog from more than one computer, you need to make sure that you push everything before switching computers. From the first machine do the following whenever you’ve made changes:

	$ rake generate
	$ git add .
	$ git commit -am "Some comment here." 
	$ git push origin source  # update the remote source branch 
	$ rake deploy             # update the remote master branch

Then on the other machine, you need to pull those changes.

	$ cd octopress
	$ git pull origin source  # update the local source branch
	$ cd ./_deploy
	$ git pull origin master  # update the local master branch