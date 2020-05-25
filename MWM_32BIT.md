# How I'm doing 32-bit build and run.

So after working on my other porting branch and having issues
(interpreter core dumps on compiled code) I got to thinking that the
problem might be an expectation that `int` and `char *` were the same size, which wouldn't be true in a 64-bit build.

I soon discovered that `gcc -m32` doesn't work by default; you have to do some hoops. So I created a new WSL instance of plain debian and went to work. First I installed the `gcc-multiarch` package. This got me the compilers/libs and got me to a point where I could build a 32-bit ELF executable but I couldn't run it. I didn't really want to do a full-bore VM emulation of an i386, but I found the qemu user space emulation:

[QEMU User-space emulator](https://www.qemu.org/docs/master/user/main.html)

I installed the `qemu-user-static` package and now I have a `qemu-i386` command that can run my stuff. I've tested with a build of the `pass1` pass and it appears to be working.

`qemu-i1386 ./pass1 ../progs/sieve`

I had to tweak a few things to make the code compile and I turned off all warnings `-w` just to reduce the noise.
