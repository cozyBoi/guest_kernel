cmd_arch/x86/kernel/acpi/built-in.o :=  ld -m elf_x86_64   -r -o arch/x86/kernel/acpi/built-in.o arch/x86/kernel/acpi/boot.o arch/x86/kernel/acpi/sleep.o arch/x86/kernel/acpi/wakeup_64.o arch/x86/kernel/acpi/cppc_msr.o arch/x86/kernel/acpi/cstate.o ; scripts/mod/modpost arch/x86/kernel/acpi/built-in.o
