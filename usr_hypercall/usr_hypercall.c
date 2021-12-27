#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/init.h>
#include <linux/linkage.h>
#include "usr_hypercall.h"
#include <uapi/linux/kvm_para.h>
#include <linux/cpumask.h>


asmlinkage long sys_usr_hypercall(void){
	kvm_hypercall0(9);
	return 0;
}
