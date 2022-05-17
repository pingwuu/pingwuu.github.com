---
layout: post
title:  "Jekyll Setup on Windows"
date:   2019-06-03 09:00:00 +0800
categories: jekyll
comments: true
---

**Table of Content**

- [1. Install rubyinstaller-devkit](#1-install-rubyinstaller-devkit)
- [2. Update Gem Sources](#2-update-gem-sources)
- [3. Install bundler & jekyll](#3-install-bundler---jekyll)
- [4. Create jekyll site](#4-create-jekyll-site)
- [5. Access your blog site](#5-access-your-blog-site)



# 1. Install rubyinstaller-devkit

- Package version : rubyinstaller-devkit-2.5.5-1-x64.exe

- Check ruby version

  ```
  > ruby-v
  ruby 2.5.1p57 (2018-03-29 revision 63029) [x64-mingw32]
  ```

# 2. Update Gem Sources

```
> gem sources --add https://gems.ruby-china.com/ --remove https://rubygems.org
> gem sources -l
	*** CURRENT SOURCES ***

    https://gems.ruby-china.com/
```

Setup network proxy as below if you behind a fireware

```
> set HTTP_PROXY=http://user:password@porxy_server:proxy_port
> do other command
```

# 3. Install bundler & jekyll

```
> gem install bundler
> gem install jekyll
```

# 4. Create jekyll site

* Create a gemfile in your local jekyll site root

  ```
  > dir
  Gemfile
  > Edit Gemfile as below
  ###
  source 'https://gems.ruby-china.com/'
  
  gem 'github-pages', group: :jekyll_plugins
  ###
  ```

* Install  jekyll and dependencies package

  ```
  > bundle install
  ```

* Generate a jekyll site

  ```
  > bundle exec jekyll _3.8.5_   new  NEW-JEKYLL-SITE-REPOSITY-NAME
  > cd NEW-JEKYLL-SITE-REPOSITY-NAME
  ```

  Edit gemfile and remove the following lines comments (#)

  ```
  source 'https://gems.ruby-china.com/'
      
  gem "jekyll", "~> 3.8.5"
      
  gem "github-pages", group: :jekyll_plugins
  ```

  Init your site directory as a Git reposity

  ```
  git init
  git remote add origin https://github.com/username-or-organization-name/your-remote-repository-name
  
  ```

  **Note:** this repo name must like username.github.com

  

* Create blog 

  add a new file like yyyy-mm-dd-newblog.markdown to NEW-JEKYLL-SITE-REPOSITY-NAME/_posts

* Build your blog

  ```
  > cd NEW-JEKYLL-SITE-REPOSITY-NAME
  > bundle exec jekyll build
  ```

* Test your blog on local

  ```
  bundle exec jekyll serve
  ```

  Test your blog site on local vial browser to access:

  [http://localhost:4000](http://localhost:4000)

  

* Push your repo changes to remote

  ```
  > git add .
  > git commit -s -m "change details xxxx"
  > git push origin master
  ```

# 5. Access your blog site

[http://username.github.io](http://username.github.io)

