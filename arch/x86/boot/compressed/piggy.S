.section ".rodata..compressed","a",@progbits
.globl z_input_len
z_input_len = 6549813
.globl z_output_len
z_output_len = 34723460
.globl input_data, input_data_end
input_data:
.incbin "arch/x86/boot/compressed/vmlinux.bin.gz"
input_data_end:
