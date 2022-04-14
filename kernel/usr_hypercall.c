#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/init.h>
#include <linux/linkage.h>
//#include "usr_hypercall.h"
#include <uapi/linux/kvm_para.h>
#include <linux/cpumask.h>
#include <linux/sched.h>

//asmlinkage long sys_usr_hypercall(void){
/*
SYSCALL_DEFINE0(hello){
	printk("[sys_usr_hypercall] KVM_HC_USR_HYPERCALL %d\n", 12);
	//kvm_hypercall0(12);
	return 0;
}
*/
//asmlinkage long sys_hello(void){
//argument $1 : pid
//argument $2 : 0
SYSCALL_DEFINE2(hello, long int, high_addr, long int, low_addr){
	unsigned long long int tmp;
	unsigned long int h, l;
	pid_t curr_pid = high_addr;
	struct task_struct *t = find_task_by_vpid(high_addr);
	printk("hello world\n");
	tmp = (unsigned long long)t->mm->pgd / (1ULL<<32);
	h = (unsigned long)tmp;
	tmp = (unsigned long long)t->mm->pgd % (1ULL<<32);
	l = (unsigned long)tmp;
	kvm_hypercall3(13, h, l, curr_pid);	
	return 0;
}
