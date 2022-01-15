#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/init.h>
#include <linux/linkage.h>
//#include "usr_hypercall.h"
#include <uapi/linux/kvm_para.h>
#include <linux/cpumask.h>

//asmlinkage long sys_usr_hypercall(void){
/*
SYSCALL_DEFINE0(hello){
	printk("[sys_usr_hypercall] KVM_HC_USR_HYPERCALL %d\n", 12);
	//kvm_hypercall0(12);
	return 0;
}
*/
//asmlinkage long sys_hello(void){
SYSCALL_DEFINE0(hello){
	printk("hello world\n");
	return 0;
}
