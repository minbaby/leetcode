# leet code use c

# hash

```bash
sudo apt install uthash-dev
```

## unit test

```bash
# https://github.com/Snaipe/Criterion
mkdir -p $HOME/code/repos
git clone https://github.com/Snaipe/Criterion.git $HOME/code/repos
sudo apt install -y build-essential \
    meson \
    nanopb \
    libgrpc++-dev \
    libgit2-dev \
    libffi-dev \
    libboxfort-dev \
    libnanomsg-dev \
    libboxfort-dev \
    libnanopb-dev

sudo meson build
sudo ninja -C build install

sudo ldconf
```


## build

```
cd build && cmake ../ && cd ../
```


## links 

- https://zhuanlan.zhihu.com/p/34568676