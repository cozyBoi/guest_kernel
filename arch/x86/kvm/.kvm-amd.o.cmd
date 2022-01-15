cmd_arch/x86/kvm/kvm-amd.o := ld -m elf_x86_64   -r -o arch/x86/kvm/kvm-amd.o arch/x86/kvm/svm.o arch/x86/kvm/pmu_amd.o ; scripts/mod/modpost arch/x86/kvm/kvm-amd.o
