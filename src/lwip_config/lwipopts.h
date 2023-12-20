/*
* lwipopts.h -- LwIP example
*
* Copyright (C) 2013-2016 Christian Amsüss <chrysn@fsfe.org>
* Copyright (C) 2018-2023 Jon Shallow <supjps-libcoap@jpshallow.com>
*
* SPDX-License-Identifier: BSD-2-Clause
*
* This file is part of the CoAP library libcoap. Please see README for terms
* of use.
*/

#define NO_SYS                     1
#define LWIP_SOCKET                (NO_SYS==0)
#define LWIP_NETCONN               (NO_SYS==0)
#define LWIP_NETIF_API             (NO_SYS==0)

#define LWIP_IPV4                       1

#define LWIP_IPV6                       0
#define LWIP_IPV6_REASS                 0

#define LWIP_IPV6_MLD                   0
#define LWIP_ICMP6                 (LWIP_IPV6==1)

#ifndef netif_get_index
#define netif_get_index(netif)      ((u8_t)((netif)->num + 1))
#endif

#if NO_SYS
#define LOCK_TCPIP_CORE()
#define UNLOCK_TCPIP_CORE()
#endif

/*
* Set to display (with COAP_LOG_DEBUG) custom pools information
* (Needs MEMP_STATS set) when coap_free_context() is called.
*/
#define LWIP_STATS_DISPLAY              1

#define LWIP_HAVE_SLIPIF 1
#define SLIP_MAX_SIZE 1500