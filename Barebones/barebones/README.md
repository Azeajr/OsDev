```bash
sudo pacman -Syu base-devel gmp libmpc mpfr


wget -P $HOME/src https://ftp.gnu.org/gnu/binutils/binutils-2.41.tar.gz

wget -P $HOME/src https://ftp.gnu.org/gnu/gcc/gcc-13.2.0/gcc-13.2.0.tar.gz


export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

cd $HOME/src


tar -xf binutils-2.41.tar.gz
tar -xf gcc-13.2.0.tar.gz

cd $HOME/src

mkdir build-binutils
cd build-binutils
../binutils-2.41/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install


cd $HOME/src
 
# The $PREFIX/bin dir _must_ be in the PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in the PATH
 
mkdir build-gcc
cd build-gcc
../gcc-13.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc


$HOME/opt/cross/bin/$TARGET-gcc --version

export PATH="$HOME/opt/cross/bin:$PATH"


$HOME/opt/cross/bin/i686-elf-as boot.s -o boot.o

$HOME/opt/cross/bin/i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$HOME/opt/cross/bin/i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

grub-file --is-x86-multiboot myos.bin

qemu-system-i386 -kernel myos.bin

```
