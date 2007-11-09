/*********************************************************************
 *                
 * Copyright (C) 2002-2004, 2006-2007,  Karlsruhe University
 *                
 * File path:     arch/ia32/tracebuffer.h
 * Description:   IA32 specific tracebuffer
 *                
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *                
 ********************************************************************/
#ifndef __ARCH__X86__X32__TRACEBUFFER_H__
#define __ARCH__X86__X32__TRACEBUFFER_H__

#include <tcb_layout.h>

#define TRACEBUFFER_MAGIC 	0x143acebf
#define TRACEBUFFER_SIZE	(4 * 1024 * 1024)

#define TRACEBUFFER_PGENTSZ        pgent_t::size_4m

#include INC_ARCH(tracebuffer.h)

/*
 * Access to stack pointer, timestamp, and performance monitoring counters
 */
#define TBUF_RDTSC  "	rdtsc					\n"	\
		    "	mov	%%eax, %%fs:2*%c9(%0)		\n"	
    
#define TBUF_SP     "	mov	%%esp, %%fs:3*%c9(%0)		\n"	\


#if defined(CONFIG_TBUF_PERFMON)
#define TBUF_RDPMC_0	"	rdpmc					\n"	\
			"	movl	%%eax, %%fs:4*%c9(%0)		\n"
#define TBUF_RDPMC_1	"	rdpmc					\n"	\
			"	movl	%%eax, %%fs:5*%c9(%0)		\n"
#endif

#endif /* !__ARCH__X86__X32__TRACEBUFFER_H__ */