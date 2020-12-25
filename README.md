# plucid
Automatically exported from code.google.com/p/plucid

I wanted to save off this source since Google Code is closing down. Lucid is a language that interests me and I would like to experiment with it as I have time. This seemed like a good place to start.

## Branch 32bit-build
My first attempt at getting the code running tried a straight up 64-bit build of things with lots of code changes to create prototypes and other stuff to silence warnings. This seemed to work through the various passes (pass1...) but failed when I got to the interpreter part. My hypothesis is that the final output from the passes (which is a file) has a strong dependency on int/pointer types both being 32-bit, but I didn't dig into that in any detail. Instead I switched to a new Debian WSL2 instance and installed an i386 qemu instance so I can run things via `qemu-i
386`.

```
markland@Dads-Laptop:~/git-repos/plucid$ apt list --installed | grep qemu

WARNING: apt does not have a stable CLI interface. Use with caution in scripts.

qemu-system-x86/stable,stable,now 1:3.1+dfsg-8+deb10u8 amd64 [installed]
qemu-user/stable,stable,now 1:3.1+dfsg-8+deb10u8 amd64 [installed]
```

## Status
### 12/25/2020
I have gotten `pass1`, `pass2`, `pass3`, and `pass4` to build (with tons of warnings) and data seems to flow correctly through to pass4 which issues an error. So that is where to start digging next.

```
markland@Dads-Laptop:~/git-repos/plucid/p4$ qemu-i386 ../p1/pass1 ../progs/sieve | qemu-i386 ../p2/pass2 | qemu-i386 ../p3/pass3 | qemu-i386 ./pass4
Compilation begins ......
syntax error
Fatal errors: no expression file written.
 [ valof  [ defn N 0 [ op [ fby 0  [ const [ numb 2.00000    ]  ] [ op [ plus 0  [ nullry N 0  ]  [ const [ numb 1.00000    ]  ]  ]  [ cxfile `../progs/sieve' 6 6 18 ]  ]  ]  [ cxfile `../progs/sieve' 6 6 12 ]  ]  ]  [ defn sieve 1  [ frmls  i  ]  [ valof  [ nglobal  i  sieve  ]  [ defn _result 0  [ nullry _1000 0  ]  ]  [ defn _1000 0 [ op [ fby 0  [ nullry i 0  ]  [ nonnullry sieve 1  [ valof  [ nglobal  i  ]  [ defn _result 0 [ op [ @t 0  [ nullry i 0  ]  [ nullry _1 0  ]  ]  [ cxfile `../progs/sieve' 8 8 24 ]  ]  ]  [ defn _1 0 [ op [ fby 0  [ nullry _0 0  ] [ op [ @t 0  [ nullry _0 0  ] [ op [ plus 0  [ nullry _1 0  ]  [ const [ numb 1.00000    ]  ]  ]  [ cxfile `../progs/sieve' 8 8 24 ]  ]  ]  [ cxfile `../progs/sieve' 8 8 24 ]  ]  ]  [ cxfile `../progs/sieve' 8 8 24 ]  ]  ]  [ defn _0 0 [ op [ if 0 [ op [ ne 0 [ op [ mod 0  [ nullry i 0  ] [ op [ first 0  [ nullry i 0  ]  ]  [ cxfile `../progs/sieve' 8 8 39 ]  ]  ]  [ cxfile `../progs/sieve' 8 8 35 ]  ]  [ const [ numb 0.00000    ]  ]  ]  [ cxfile `../progs/sieve' 8 8 47 ]  ] [ op [ now 0  [ const [ numb 1.00000    ]  ]  ]  [ cxfile `../progs/sieve' 8 8 24 ]  ] [ op [ next 0  [ nullry _0 0  ]  ]  [ cxfile `../progs/sieve' 8 8 24 ]  ]  ]  [ cxfile `../progs/sieve' 8 8 24 ]  ]  ]  ]  ]  ]  [ cxfile `../progs/sieve' 8 8 10 ]  ]  ]  ]  ]  [ defn _result 0  [ nonnullry sieve 1  [ nullry N 0  ]  ]  ]  ]
 ```
 