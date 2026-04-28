#include <signal.h>
#include <stddef.h>

#define tasklist_lock ((int){0})

struct task_struct {
    int exit_signal;
    int parent_exec_id;
    int self_exec_id;
    int exit_state;
    struct task_struct *group_leader;
    struct task_struct *real_parent;
    struct signal_struct *signal;
};

struct signal_struct {
    struct task_struct *group_exit_task;
    int notify_count;
};

#define DEATH_REAP 0
#define EXIT_DEAD 0
#define EXIT_ZOMBIE 0
#define CAP_KILL 0

static int task_detached(struct task_struct *tsk) { return 0; }
static int capable(int cap) { return 0; }
static int thread_group_leader(struct task_struct *tsk) { return 0; }
static void wake_up_process(struct task_struct *tsk) {}
static void release_task(struct task_struct *tsk) {}
static void forget_original_parent(struct task_struct *tsk) {}
static void exit_task_namespaces(struct task_struct *tsk) {}
static void kill_orphaned_pgrp(struct task_struct *leader, void *arg) {}
static int tracehook_notify_death(struct task_struct *tsk, void **cookie, int group_dead) { return 0; }
static int do_notify_parent(struct task_struct *tsk, int signal) { return 0; }
static void tracehook_report_death(struct task_struct *tsk, int signal, void *cookie, int group_dead) {}
static void write_lock_irq(int *lock) {}
static void write_unlock_irq(int *lock) {}