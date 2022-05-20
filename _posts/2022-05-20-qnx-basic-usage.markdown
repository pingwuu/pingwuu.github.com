---
layout: post
title:  "QNX Basic Usage"
date:   2020-12-11 09:30:00 +0800
categories: network libcap
comments: true
---

**Table of Content**
- [1. Reading a Kernel Dump](#1-reading-a-kernel-dump)
- [99. Reference URL](#99-reference-url)

# 1. Reading a Kernel Dump

If your application crashes with a kernel fault, the output tells you what happened at the time of the crash. Here's a sample:
```
Shutdown[0,0] S/C/F=11/1/11 C/D=f001517d/f00571ac state(c0)= now lock
[0]PID-TID= 1-1? P/T FL=00019001/08800000 "proc/boot/procnto-instr"
[0]ASPACE PID=7 PF=00001010 "proc/boot/devb-eide"
x86 context[efffcc28]:
0000: 08088cc8 b0359320 efff2c3c efffcc48 b0357f14 08088d10 efff2c10
000000f8
0020: b0323948 0000001d 00011296 efff2c24 00000099
instruction[b0323948]:
ff 08 75 0e 8b 02 83 c4 f4 83 c0 08 50 e8 8e f5 fe ff 8b 5d e8 c9 c3 90
55 89
stack[efff2c24]:
0000: b0357f14 00000003 08088cc8 b0317d3d b0357f14 b0359320 efff2c6c
b033f692
0000: 8088d10 b033f49c efff2c5c b033f678 b0357f14 00000003 00100102 00000003
```

Here's what each part means:

- `S/C/F=11/1/11`

  Signal, code, and fault codes; see these files:signal: `/usr/include/signal.h`code: `/usr/include/sys/siginfo.h`fault: `/usr/include/sys/fault.h`To find out what happened, search `signal.h` for the signal code. This tells you the name of the signal. Then, look in `siginfo.h` for the signal name. In this example, code 11 in `signal.h` is a SIGSEGV; in `siginfo.h`, code 1 in the SIGSEGV section is:`SEGV_MAPERR 1  // Address not mapped  `

- `C/D`

  Location of the kernel's code and data.

- `state`

  The state of the kernel:`now` — in the kernel`lock` — nonpreemptible`exit` — leaving kernel`specret` — special return processingany number — the interrupt nesting level.

- `[`*x*`]PID-TID=`*y*`-`*z*

  The process ID and thread ID. On CPU *x* (think SMP), process *y* was running thread *z* when the crash occurred.

- `P/T FL`

  Process and thread flags. To find out which flags are set, look in `/usr/nto/include/sys/neutrino.h`. The process flags are in the form `_NTO_PF_*`, and the thread flags are in the form `_NTO_TF_*`.

- `[`*x*`]ASPACE PID=`*y*

  On CPU *x*, the address space for process *y* was active. This line appears only when the process is different from the one in the `PID-TID` line.

- `PF`

  The process flags for the `ASPACE PID`. In the sample above, `devb-eide` wasn't running, but its address space was active.

- `context`

  The register set. You can find the list of registers in `/usr/nto/include/`*cpu*`/context.h`, where *cpu* is the appropriate CPU-specific directory.

- `instruction`

  The instruction on which the error occurred.

- `stack`

  The contents of the stack.





# 99. Reference URL

* 1) [Reading a Kernel Dump](http://support7.qnx.com/developers/docs/6.4.1/neutrino/technotes/proc_dump.html)

  
