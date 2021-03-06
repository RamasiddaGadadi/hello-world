#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/hrtimer.h>
#include <linux/sched.h>
static struct hrtimer htimer;
static ktime_t kt_periode;
static enum hrtimer_restart timer_function(struct hrtimer * timer)
{
        asm ("int $50");
        hrtimer_forward_now(timer, kt_periode);
        
		printk(KERN_INFO "about to restart timer \n");
        
		return HRTIMER_RESTART;
}
static int __init init_proc(void)
{
        printk(KERN_INFO "my trigger module is initialized \n");

        kt_periode = ktime_set(10, 0); //seconds,nanoseconds
        hrtimer_init (& htimer, CLOCK_REALTIME, HRTIMER_MODE_REL);
        htimer.function = timer_function;
        hrtimer_start(& htimer, kt_periode, HRTIMER_MODE_REL);
        return 0;
}
static void __exit exit_proc(void)
{
        hrtimer_cancel(& htimer);
        printk(KERN_INFO "handler module destroyed \n");
}
module_init(init_proc);
module_exit(exit_proc);
MODULE_LICENSE("GPL");
