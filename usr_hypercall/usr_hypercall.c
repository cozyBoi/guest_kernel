#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/init.h>
#include <linux/linkage.h>
#include "usr_hypercall.h"
#include <uapi/linux/kvm_para.h>
#include <linux/cpumask.h>
#define KVM_HC_USR_HYPERCALL            12

asmlinkage long sys_usr_hypercall(void){
	kvm_hypercall0(KVM_HC_USR_HYPERCALL);
	return 0;
}
