/*	uucp.h	5.3	84/09/04	*/

#include "stdio.h"

/*
 * Determine local uucp name of this machine.
 * Define one of the following:
 *
 * For UCB 4.1A and later systems, you will have the gethostname(2) call.
 * If this call exists, define GETHOSTNAME.
 *
 * For USG 3.0 and later systems, you will have the uname(2) call.
 * If this call exists, define UNAME.
 *
 * Some systems have a line of the form '#define sysname "myuucpname",'
 * in the file /usr/include/whoami.h, to identify their machine.
 * If your site does that, define WHOAMI.
 *
 * If your site has <whoami.h>, but you do not want to read
 * that file every time uucp runs, you can compile sysname into uucp.
 * This is faster and more reliable, but binaries do not port.
 * If you want to do that, define CCWHOAMI.
 *
 * Some systems put the local uucp name in a single-line file
 * named /etc/uucpname or /local/uucpname.
 * If your site does that, define UUNAME.
 *
 * Systems running 3Com's UNET will have the getmyhname() call.
 * If you want to, define GETMYHNAME.
 *
 * You should also define MYNANE to be your uucp name.
 *
 * For each of the above that are defined, uucp checks them in order.
 * It stops on the first method that returns a non null name.
 * If everything fails, it uses "unknown" for the system name.
 */
#define	GETHOSTNAME
/* If the above fails ... */
#define	MYNAME	"erewhon"

/*
 * If you have it, include <sysexits.h> to use exit
 * codes that will be understood by sendmail.
 * Otherwise, define EX_NOHOST, EX_CANTCREAT, and EX_NOINPUT.
 */
#include <sysexits.h>
/*#define EX_NOHOST	101*/
/*#define EX_CANTCREAT	1*/
/*#define EX_NOINPUT	2*/

/* define UUDIR for uucp subdirectory kludge (recommended) */
#define	UUDIR

/*
 * Define the various kinds of connections to include.
 * The complete list is in the condevs array in condevs.c
 */
#define DN11		/* standard dialer */
/*#define DATAKIT		/* ATT's datakit */
/*#define PNET		/* Purdue network */
/*#define DF02		/* Dec's DF02/DF03 */
#define HAYES		/* Hayes' Smartmodem */
#define VENTEL		/* ventel dialer */
#define VADIC		/* Racal-Vadic 3450 */
/*#define RVMACS		/* Racal-Vadic MACS 831 */
#define TCPNET		/* 4.2 TCP Network */
/*#define UNET		/* 3Com's UNET */
/*#define MICOM		/* micom mux port */

#ifdef	VENTEL
/*
 * We need a timer to write slowly to ventels.
 * define INTERVALTIMER to use 4.2 bsd interval timer.
 * define FASTTIMER if you have the nap() system call.
 * define FTIME if you have the ftime() system call.
 * define BUSYLOOP if you must do a busy loop.
 * Look at uucpdelay() in condevs.c for details.
 */
#define	FTIME
#endif

/*
 * If your site is using "ndir.h" to retrofit the Berkeley
 * directory reading routines, define NDIR.
 * You will probably also have to set LIBNDIR in Makefile.
 * Otherwise, <dir.h> is assumed to have the Berkeley directory definitions.
 */
/*#define	NDIR*/

/*
 * If yours is a BTL system III, IV, or so-on site, define SYSIII.
 * Conditional compilations should produce the right code,
 * but if it doesn't (the compiler will probably complain loudly),
 * make the needed adjustments and guard the code with
 * #ifdef SYSIII, (code for system III), #else, (code for V7), #endif
 */
/*#define	SYSIII*/

/* define the last characters for ACU */
/* burl!lda, rti!trt, isn't "<" more widely used than "-"? */
/* rti!trt: use -< as is done in 4.1c uucp */
#define ACULAST "-<"

/* define the value of WFMASK - for umask call - used for all uucp work files */
#define WFMASK 0137

/* define the value of LOGMASK - for LOGFILE, SYSLOG, ERRLOG */
#define	LOGMASK	0133

/* All files are given at least the following at the final destination */
/* It is also the default mode, so '666' is recommended */
/* and 444 is minimal (minimally useful, maximally annoying) */
#define	BASEMODE	0666

/* All users with getuid() <= PRIV_UIDS are 'privileged'. */
/* Was 10, reduced to 3 as suggested by duke!dbl (David Leonard) */
#define	PRIV_UIDS	3

#define XQTDIR		"/usr/spool/uucp/XTMP"
#define SQFILE		"/usr/lib/uucp/SQFILE"
#define SQTMP		"/usr/lib/uucp/SQTMP"
#define SLCKTIME	5400	/* system/device timeout (LCK.. files) */
#define SEQFILE		"/usr/lib/uucp/SEQF"
#define SYSFILE		"/usr/lib/uucp/L.sys"
#define DEVFILE		"/usr/lib/uucp/L-devices"
#define DIALFILE	"/usr/lib/uucp/L-dialcodes"
#define USERFILE	"/usr/lib/uucp/USERFILE"
#define	CMDFILE		"/usr/lib/uucp/L.cmds"

#define SPOOL		"/usr/spool/uucp"
#define SQLOCK		"/usr/spool/uucp/LCK.SQ"
#define SYSLOG		"/usr/spool/uucp/SYSLOG"
#define PUBDIR		"/usr/spool/uucppublic"

#define SEQLOCK		"LCK.SEQL"
#define CMDPRE		'C'
#define DATAPRE		'D'
#define XQTPRE		'X'

#define LOGFILE	"/usr/spool/uucp/LOGFILE"
#define ERRLOG	"/usr/spool/uucp/ERRLOG"

#define RMTDEBUG	"AUDIT"
#define SQTIME		60
#define TRYCALLS	2	/* number of tries to dial call */

/*define PROTODEBUG = 1 if testing protocol - introduce errors */
#define DEBUG(l, f, s) if (Debug >= l) fprintf(stderr, f, s); else

#define ASSERT(e, s1, s2, i1) if (!(e)) {\
assert(s1, s2, i1);\
cleanup(FAIL);} else


#define SAME 0
#define ANYREAD 04
#define ANYWRITE 02
#define FAIL -1
#define SUCCESS 0
#define CNULL (char *) 0
#define STBNULL (struct sgttyb *) 0
#define MASTER 1
#define SLAVE 0
#define MAXFULLNAME 250
#define MAXMSGTIME 45
#define NAMESIZE 15
#define EOTMSG "\04\n\04\n"
#define CALLBACK 1

	/*  commands  */
#define SHELL		"/bin/sh"
#define MAIL		"mail"
#define UUCICO		"/usr/lib/uucp/uucico"
#define UUXQT		"/usr/lib/uucp/uuxqt"
#define UUCP		"uucp"

	/*  call connect fail stuff  */
#define CF_SYSTEM	-1
#define CF_TIME		-2
#define CF_LOCK		-3
#define	CF_NODEV	-4
#define CF_DIAL		-5
#define CF_LOGIN	-6

#define F_NAME 0
#define F_TIME 1
#define F_LINE 2
#define F_CLASS 3	/* an optional prefix and the speed */
#define F_PHONE 4
#define F_LOGIN 5

#define MAXPH	60	/* maximum length of a phone number */

	/* This structure tells how to get to a device */
struct condev {
	char *CU_meth;		/* method, such as 'ACU' or 'DIR' */
	char *CU_brand;		/* brand, such as 'Hayes' or 'Vadic' */
	int (*CU_gen)();	/* what to call to search for brands */
	int (*CU_open)();	/* what to call to open brand */
	int (*CU_clos)();	/* what to call to close brand */
};

	/* This structure tells about a device */
struct Devices {
	char D_type[20];
	char D_line[20];
	char D_calldev[20];
	char D_class[20];
	int D_speed;
	char D_brand[20];	/* brand name, as 'Hayes' or 'Vadic' */
};

	/*  system status stuff  */
#define SS_OK		0
#define SS_FAIL		4
#define SS_NODEVICE	1
#define SS_CALLBACK	2
#define SS_INPROGRESS	3
#define SS_BADSEQ	5

	/*  fail/retry parameters  */
#define RETRYTIME 3300
#define MAXRECALLS 20

	/*  stuff for command execution  */
#define X_RQDFILE	'F'
#define X_STDIN		'I'
#define X_STDOUT	'O'
#define X_CMD		'C'
#define X_USER		'U'
#define X_SENDFILE	'S'
#define	X_NONOTI	'N'
#define	X_NONZERO	'Z'
#define X_LOCK		"LCK.XQT"
#define X_LOCKTIME	3600

#define WKDSIZE 100	/*  size of work dir name  */

extern int Ifn, Ofn;
extern char Rmtname[];
extern char User[];
extern char Loginuser[];
extern char *Spool;
extern char Myname[];
extern int Debug;
extern int Pkdebug;
extern int Pkdrvon;
extern int Bspeed;
extern char Wrkdir[];
extern long Retrytime;
extern int Unet;
extern char Progname[];
extern int (*CU_end)();
extern struct condev condevs[];

#ifdef	UUDIR
#define	subfile(s)	SubFile(s)
#define	subdir(d, p)	SubDir(d, p)
#define	subchdir(d)	SubChDir(d)
extern	char DLocal[], DLocalX[], *SubFile(), *SubDir();
#else
#define	subfile(s)	s
#define	subdir(d, p)	d
#define	subchdir(d)	chdir(d)
#endif

/* Commonly called routines which return non-int value */
extern	char *ttyname(), *strcpy(), *strcat(), *index(), *rindex(),
		*fgets(), *calloc(), *malloc(),
		*cfgets();
extern	long lseek();
extern	FILE *rpopen();
