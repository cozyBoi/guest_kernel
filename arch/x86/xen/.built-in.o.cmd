cmd_arch/x86/xen/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/xen/built-in.o arch/x86/xen/enlighten.o arch/x86/xen/setup.o arch/x86/xen/multicalls.o arch/x86/xen/mmu.o arch/x86/xen/irq.o arch/x86/xen/time.o arch/x86/xen/xen-asm.o arch/x86/xen/xen-asm_64.o arch/x86/xen/grant-table.o arch/x86/xen/suspend.o arch/x86/xen/platform-pci-unplug.o arch/x86/xen/p2m.o arch/x86/xen/trace.o arch/x86/xen/smp.o arch/x86/xen/spinlock.o arch/x86/xen/pci-swiotlb-xen.o ; scripts/mod/modpost arch/x86/xen/built-in.o
