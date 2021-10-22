# leet code use c

# warning

`set (CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")`
在 macos 下，这个配置会导致执行时间从 1s 左右变为接近 30s，在 linux 下 不明显

# hash

```bash
sudo apt install uthash-dev
```

## unit test

```bash
#ubuntu
# https://github.com/Snaipe/Criterion
mkdir -p $HOME/code/repos
git clone https://github.com/Snaipe/Criterion.git $HOME/code/repos
sudo apt install -y build-essential \
    meson \
    nanopb \
    libgrpc++-dev \
    libgit2-dev \
    libffi-dev \;
    libboxfort-dev \
    libnanomsg-dev \
    libboxfort-dev \
    libnanopb-dev

sudo meson build
sudo ninja -C build install

sudo ldconf
```
```bash
brew install snaipe/soft/criterion
```
brew tap nwoolls/xgminer

## build

```
1. make or make test # 执行测试
2. make one # 过滤执行
3. make main # 执行 main.c
```


## leetcode.php

```bash
./leetcode.php
```

## links 

- https://zhuanlan.zhihu.com/p/34568676