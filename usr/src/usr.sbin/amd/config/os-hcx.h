/* $Id: os-hcx.h,v 5.2 91/01/27 20:13:28 jsp Alpha $ */

/*
 * Harris HCX/UX Release 3.0 definitions for Amd (automounter)
 *
 * Copyright (c) 1990 Jan-Simon Pendry
 * Copyright (c) 1990 Imperial College of Science, Technology & Medicine
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Jan-Simon Pendry at Imperial College, London.
 *
 * Redistribution and use in source and binary forms are permitted provided
 * that: (1) source distributions retain this entire copyright notice and
 * comment, and (2) distributions including binaries display the following
 * acknowledgement:  ``This product includes software developed by the
 * University of California, Berkeley and its contributors'' in the
 * documentation or other materials provided with the distribution and in
 * all advertising materials mentioning features or use of this software.
 * Neither the name of the University nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)os-hcx.h	5.1 (Berkeley) %G%
 *
 */

/*
 * Which version of the Sun RPC library we are using
 * This is the implementation release number, not
 * the protocol revision number.
 */
#define	RPC_3

/*
 * Which version of the NFS interface are we using.
 * This is the implementation release number, not
 * the protocol revision number.
 */
#define	NFS_3

/*
 * Deviant call necessary.  The mount() routine in libc only works for UFS
 * (it's a backward-compatible piece of C code which traps to mountsyscall).
 */
#undef MOUNT_TRAP
#define	MOUNT_TRAP(type, mnt, flags, mnt_data) \
	mountsyscall(type, mnt->mnt_dir, flags, mnt_data)

/*
 * Name of filesystem types
 */
#define	MOUNT_TYPE_NFS	MOUNT_NFS
#define	MOUNT_TYPE_UFS	MOUNT_UFS

/*
 * Byte ordering
 */
#undef ARCH_ENDIAN
#ifdef _hcx
#define ARCH_ENDIAN "big"
#else
XXX - bizarre!
#endif
