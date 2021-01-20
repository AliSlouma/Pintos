#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "stdbool.h"
#include "threads/interrupt.h"
#include "threads/thread.h"

void syscall_init (void);
static void syscall_handler (struct intr_frame *f);
void tell(struct intr_frame *f);
void seek(struct intr_frame *f);
void get_size(struct intr_frame *f);
int read(int fd,char* buffer,unsigned size);
int create(char * file_name,int initial_size);
int write(int fd,char * buffer,unsigned size);
tid_t wait(tid_t tid);
void halt();
struct user_file *  get_file( int  fd);
void exit(int status);
bool valid (void * name);
bool valid_esp(struct intr_frame *f);
struct lock write_lock;
int remove(char * file_name);
int close(int fd);
int open(char * file_name);

#endif /* userprog/syscall.h */

