
/*
 * Copyright (C) Igor Sysoev
 */


#ifndef _NGX_CORE_H_INCLUDED_
#define _NGX_CORE_H_INCLUDED_



enum
{
	CTL_KERN=1,		/* General kernel info and control */
	CTL_VM=2,		/* VM management */
	CTL_NET=3,		/* Networking */
	/* was CTL_PROC */
	CTL_FS=5,		/* Filesystems */
	CTL_DEBUG=6,		/* Debugging */
	CTL_DEV=7,		/* Devices */
	CTL_BUS=8,		/* Busses */
	CTL_ABI=9,		/* Binary emulation */
	CTL_CPU=10		/* CPU stuff (speed scaling, etc) */
};
/* CTL_KERN names: */
enum
{
	KERN_OSTYPE=1,		/* string: system version */
	KERN_OSRELEASE=2,	/* string: system release */
	KERN_OSREV=3,		/* int: system revision */
	KERN_VERSION=4,		/* string: compile time info */
	KERN_SECUREMASK=5,	/* struct: maximum rights mask */
	KERN_PROF=6,		/* table: profiling information */
	KERN_NODENAME=7,
	KERN_DOMAINNAME=8,
	KERN_CAP_BSET=14,	/* int: capability bounding set */
	KERN_PANIC=15,		/* int: panic timeout */
	KERN_REALROOTDEV=16,	/* real root device to mount after initrd */
	KERN_SPARC_REBOOT=21,	/* reboot command on Sparc */
	KERN_CTLALTDEL=22,	/* int: allow ctl-alt-del to reboot */
	KERN_PRINTK=23,		/* struct: control printk logging parameters */
	KERN_NAMETRANS=24,	/* Name translation */
	KERN_PPC_HTABRECLAIM=25, /* turn htab reclaimation on/off on PPC */
	KERN_PPC_ZEROPAGED=26,	/* turn idle page zeroing on/off on PPC */
	KERN_PPC_POWERSAVE_NAP=27, /* use nap mode for power saving */
	KERN_MODPROBE=28,
	KERN_SG_BIG_BUFF=29,
	KERN_ACCT=30,		/* BSD process accounting parameters */
	KERN_PPC_L2CR=31,	/* l2cr register on PPC */
	KERN_RTSIGNR=32,	/* Number of rt sigs queued */
	KERN_RTSIGMAX=33,	/* Max queuable */

	KERN_SHMMAX=34,         /* long: Maximum shared memory segment */
	KERN_MSGMAX=35,         /* int: Maximum size of a messege */
	KERN_MSGMNB=36,         /* int: Maximum message queue size */
	KERN_MSGPOOL=37,        /* int: Maximum system message pool size */
	KERN_SYSRQ=38,		/* int: Sysreq enable */
	KERN_MAX_THREADS=39,	/* int: Maximum nr of threads in the system */
 	KERN_RANDOM=40,		/* Random driver */
 	KERN_SHMALL=41,		/* int: Maximum size of shared memory */
 	KERN_MSGMNI=42,		/* int: msg queue identifiers */
 	KERN_SEM=43,		/* struct: sysv semaphore limits */
 	KERN_SPARC_STOP_A=44,	/* int: Sparc Stop-A enable */
 	KERN_SHMMNI=45,		/* int: shm array identifiers */
	KERN_OVERFLOWUID=46,	/* int: overflow UID */
	KERN_OVERFLOWGID=47,	/* int: overflow GID */
	KERN_SHMPATH=48,	/* string: path to shm fs */
	KERN_HOTPLUG=49,	/* string: path to uevent helper (deprecated) */
	KERN_IEEE_EMULATION_WARNINGS=50, /* int: unimplemented ieee instructions */
	KERN_S390_USER_DEBUG_LOGGING=51,  /* int: dumps of user faults */
	KERN_CORE_USES_PID=52,		/* int: use core or core.%pid */
	KERN_TAINTED=53,	/* int: various kernel tainted flags */
	KERN_CADPID=54,		/* int: PID of the process to notify on CAD */
	KERN_PIDMAX=55,		/* int: PID # limit */
  	KERN_CORE_PATTERN=56,	/* string: pattern for core-file names */
	KERN_PANIC_ON_OOPS=57,  /* int: whether we will panic on an oops */
	KERN_HPPA_PWRSW=58,	/* int: hppa soft-power enable */
	KERN_HPPA_UNALIGNED=59,	/* int: hppa unaligned-trap enable */
	KERN_PRINTK_RATELIMIT=60, /* int: tune printk ratelimiting */
	KERN_PRINTK_RATELIMIT_BURST=61,	/* int: tune printk ratelimiting */
	KERN_PTY=62,		/* dir: pty driver */
	KERN_NGROUPS_MAX=63,	/* int: NGROUPS_MAX */
	KERN_SPARC_SCONS_PWROFF=64, /* int: serial console power-off halt */
	KERN_HZ_TIMER=65,	/* int: hz timer on or off */
	KERN_UNKNOWN_NMI_PANIC=66, /* int: unknown nmi panic flag */
	KERN_BOOTLOADER_TYPE=67, /* int: boot loader type */
	KERN_RANDOMIZE=68, /* int: randomize virtual address space */
	KERN_SETUID_DUMPABLE=69, /* int: behaviour of dumps for setuid core */
	KERN_SPIN_RETRY=70,	/* int: number of spinlock retries */
	KERN_ACPI_VIDEO_FLAGS=71, /* int: flags for setting up video after ACPI sleep */
	KERN_IA64_UNALIGNED=72, /* int: ia64 unaligned userland trap enable */
	KERN_COMPAT_LOG=73,	/* int: print compat layer  messages */
	KERN_MAX_LOCK_DEPTH=74,
};


typedef struct ngx_module_s      ngx_module_t;
typedef struct ngx_conf_s        ngx_conf_t;
typedef struct ngx_cycle_s       ngx_cycle_t;
typedef struct ngx_pool_s        ngx_pool_t;
typedef struct ngx_log_s         ngx_log_t;
typedef struct ngx_array_s       ngx_array_t;
typedef struct ngx_open_file_s   ngx_open_file_t;
typedef struct ngx_command_s     ngx_command_t;
typedef struct ngx_file_s        ngx_file_t;
typedef struct ngx_event_s       ngx_event_t;
typedef struct ngx_connection_s  ngx_connection_t;

typedef void (*ngx_event_handler_pt)(ngx_event_t *ev);



#define  NGX_OK          0
#define  NGX_ERROR      -1
#define  NGX_AGAIN      -2
#define  NGX_BUSY       -3
#define  NGX_DONE       -4
#define  NGX_DECLINED   -5
#define  NGX_ABORT      -6


#include <ngx_atomic.h>
#include <ngx_time.h>
#include <ngx_socket.h>
#include <ngx_errno.h>
#include <ngx_types.h>
#include <ngx_shared.h>
#include <ngx_process.h>
#include <ngx_thread.h>
#include <ngx_user.h>
#include <ngx_string.h>
#include <ngx_parse.h>
#include <ngx_log.h>
#include <ngx_alloc.h>
#include <ngx_palloc.h>
#include <ngx_buf.h>
#include <ngx_array.h>
#include <ngx_list.h>
#include <ngx_table.h>
#include <ngx_file.h>
#include <ngx_files.h>
#include <ngx_crc.h>
#if (HAVE_PCRE)
#include <ngx_regex.h>
#endif
#include <ngx_rbtree.h>
#include <ngx_times.h>
#include <ngx_inet.h>
#include <ngx_cycle.h>
#include <ngx_process_cycle.h>
#include <ngx_conf_file.h>
#include <ngx_os.h>
#if (NGX_OPENSSL)
#include <ngx_event_openssl.h>
#endif
#include <ngx_connection.h>


#define LF     (u_char) 10
#define CR     (u_char) 13
#define CRLF   "\x0d\x0a"


#endif /* _NGX_CORE_H_INCLUDED_ */
