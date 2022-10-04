/*
 * Copyright (c) 2010, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef PROJECT_ROUTER_CONF_H_
#define PROJECT_ROUTER_CONF_H_

#undef 	IEEE802154_CONF_PANID
#define IEEE802154_CONF_PANID		0xCAFE


#ifndef WITH_NON_STORING
#define WITH_NON_STORING 	1 			/* Set this to run with non-storing mode */
#endif /* WITH_NON_STORING */

#if WITH_NON_STORING
#undef RPL_NS_CONF_LINK_NUM
#define RPL_NS_CONF_LINK_NUM 	40 		/* Number of links maintained at the root default=40*/
#undef UIP_CONF_MAX_ROUTES
#define UIP_CONF_MAX_ROUTES 	0 		/* No need for routes */
#undef RPL_CONF_MOP
#define RPL_CONF_MOP RPL_MOP_NON_STORING /* Mode of operation*/
#endif /* WITH_NON_STORING */


#ifndef UIP_FALLBACK_INTERFACE
#define UIP_FALLBACK_INTERFACE rpl_interface
#endif

#ifndef QUEUEBUF_CONF_NUM
#define QUEUEBUF_CONF_NUM          4
#endif

#ifndef UIP_CONF_BUFFER_SIZE
#define UIP_CONF_BUFFER_SIZE    140
#endif

//#ifndef UIP_CONF_RECEIVE_WINDOW
//#define UIP_CONF_RECEIVE_WINDOW  60
//#endif

#ifndef WEBSERVER_CONF_CFS_CONNS
#define WEBSERVER_CONF_CFS_CONNS 2
#endif


//if using CC2592 PA, set this to 1
#define CC2538DK_WITH_CC2592 	1

/* RF parameters define*/
#define RF_CHANNEL 					26 		/**< Default RF channel */
//#define CC2538_RF_CONF_CHANNEL    	26
#define CC2538_RF_CONF_TX_POWER		0xFF	// +7dBm
#define CC2538_RF_CONF_AUTOACK 		1 


#undef 	NULLRDC_CONF_802154_AUTOACK
#define NULLRDC_CONF_802154_AUTOACK       1

// define security of LLSEC
#define SECURITY_EN		1

#if (SECURITY_EN)
/* software-based AES */
#if (!SLS_CC2538DK_HW)
#undef AES_128_CONF    
#define AES_128_CONF 	aes_128_driver
#endif 


#undef LLSEC802154_CONF_ENABLED
#define LLSEC802154_CONF_ENABLED          1

#undef NETSTACK_CONF_FRAMER
#define NETSTACK_CONF_FRAMER              noncoresec_framer

#undef NETSTACK_CONF_LLSEC
#define NETSTACK_CONF_LLSEC               noncoresec_driver

#undef NONCORESEC_CONF_SEC_LVL
#define NONCORESEC_CONF_SEC_LVL  1      
/* if using Level 7, it may cause delay in CC2538 and command not responding 
So optimum value: NONCORESEC_CONF_SEC_LVL=6 */

#define LLSEC_ANTIREPLAY_ENABLED 0 			/* disable anti-replay */
#define LLSEC_REBOOT_WORKAROUND_ENABLED 1
#define NONCORESEC_CONF_KEY { 0x00 , 0x01 , 0x02 , 0x03 , \
							  0x04 , 0x05 , 0x06 , 0x07 , \
							  0x08 , 0x09 , 0x0A , 0x0B , \
							  0x0C , 0x0D , 0x0E , 0x0F }

#endif /* SECURITY_EN */

#endif /* PROJECT_ROUTER_CONF_H_ */
