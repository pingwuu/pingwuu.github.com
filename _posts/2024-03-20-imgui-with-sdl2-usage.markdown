---
layout: post
title:  "imgui with sdl2 usge"
date:   2024-03-20 16:00:00 +0800
categories: gui imgui sdl2
comments: true
---

# 1. dependencies package
* cmake - build tool
```
version:    cmake-3.28.3-windows-x86_64.zip
Link:       
```

* ninja
```
version:    ninja-win
Link:       
```

* mingw - compiler and make tools
```
version:    w64devkit-1.21.0
Link:       
```

* freetype - font library
```
version:    tag VER-2-13-2
link:       https://github.com/freetype/freetype

build cmd:
For a dynamic library, use

> cmake -G "MinGW Makefiles" -B build/Release -D CMAKE_BUILD_TYPE=Release -D BUILD_SHARED_LIBS=true

> cmake --build build/Release

A binary distribution can be made with

> cmake --build build/Release --config Release --target package

Now you get binary package freetype-2.13.2-win32.zip

2024/03/20  17:19           705,684 freetype-2.13.2-win32.zip
```

# 2. cpp-small-gui-project-sdl2
```
version:    branch without-cpack
link:       https://github.com/MartinHelmut/cpp-small-gui-project-sdl2

build cmd:

> cmake -G"MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -B build/release -DFREETYPE_INCLUDE_DIRS="D:\freetype-2.13.2-win32\include;D:\freetype-2.13.2-win32\include\freetype2" -DFREETYPE_LIBRARY="D:\freetype-2.13.2-win32\lib\libfreetype.dll.a"
// not worked now

> cmake -GNinja -DCMAKE_BUILD_TYPE=Release -B build/release -DFREETYPE_INCLUDE_DIRS="D:\freetype-2.13.2-win32\include;D:\freetype-2.13.2-win32\include\freetype2" -DFREETYPE_LIBRARY="D:\freetype-2.13.2-win32\lib\libfreetype.dll.a"

>  cmake --build build/release

```


# 99. reference link

* 1) [https://funicode.net/viewtopic.php?t=134](https://funicode.net/viewtopic.php?t=134)
* 2) [https://martin-fieber.de/blog/cmake-cpack-cross-platform-distributables/](https://martin-fieber.de/blog/cmake-cpack-cross-platform-distributables/)
