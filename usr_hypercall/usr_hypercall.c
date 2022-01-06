#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/init.h>
#include <linux/linkage.h>
//#include "usr_hypercall.h"
#include <uapi/linux/kvm_para.h>
#include <linux/cpumask.h>
#define KVM_HC_USR_HYPERCALL            12

//asmlinkage long sys_usr_hypercall(void){
SYSCALL_DEFINE0(hypercall){
	printk("[sys_usr_hypercall] KVM_HC_USR_HYPERCALL %d\n", KVM_HC_USR_HYPERCALL);
	kvm_hypercall0(KVM_HC_USR_HYPERCALL);
	return 0;
}

//asmlinkage long sys_hello(void){
SYSCALL_DEFINE0(hello){
	printk("hello world\n");
	return 0;
}
