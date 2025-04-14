/***************************************************************************
*
 * Copyright (C) Kevin Alavik <kevin@alavik.se>, and contributors
 *
 * Licensed under the Apache License, Version 2.0
 *
 ***************************************************************************/

#ifndef TINYDNS_COMMON_H
#define TINYDNS_COMMON_H

/*===============================================================
 * DNS Resource Records (RRs)
 *===============================================================*/

/* Standard Resource Record Types */
#define DNS_RECORD_TYPE_A              0x0001 /* Address record (IPv4) */
#define DNS_RECORD_TYPE_NS             0x0002 /* Name server */
#define DNS_RECORD_TYPE_CNAME          0x0005 /* Canonical name */
#define DNS_RECORD_TYPE_SOA            0x0006 /* Start of authority */
#define DNS_RECORD_TYPE_PTR            0x000C /* Domain name pointer */
#define DNS_RECORD_TYPE_HINFO          0x000D /* Host information */
#define DNS_RECORD_TYPE_MX             0x000F /* Mail exchange */
#define DNS_RECORD_TYPE_TXT            0x0010 /* Descriptive text */
#define DNS_RECORD_TYPE_RP             0x0011 /* Responsible person */
#define DNS_RECORD_TYPE_AFSDB          0x0012 /* AFS database location */
#define DNS_RECORD_TYPE_SIG            0x0018 /* Digital signature */
#define DNS_RECORD_TYPE_KEY            0x0019 /* Public key */
#define DNS_RECORD_TYPE_AAAA           0x001C /* Address record (IPv6) */
#define DNS_RECORD_TYPE_LOC            0x001D /* Geographic location */
#define DNS_RECORD_TYPE_SRV            0x0021 /* Service locator */
#define DNS_RECORD_TYPE_NAPTR          0x0023 /* Naming authority pointer */
#define DNS_RECORD_TYPE_KX             0x0024 /* Key exchange */
#define DNS_RECORD_TYPE_CERT           0x0025 /* Certificate record */
#define DNS_RECORD_TYPE_DNAME          0x0027 /* Delegation name */
#define DNS_RECORD_TYPE_APL            0x002A /* Address prefix list (experimental) */
#define DNS_RECORD_TYPE_DS             0x002B /* Delegation signer */
#define DNS_RECORD_TYPE_SSHFP          0x002C /* SSH public key fingerprint */
#define DNS_RECORD_TYPE_IPSECKEY       0x002D /* IPsec key */
#define DNS_RECORD_TYPE_RRSIG          0x002E /* RRset signature */
#define DNS_RECORD_TYPE_NSEC           0x002F /* Next secure record */
#define DNS_RECORD_TYPE_DNSKEY         0x0030 /* DNSSEC public key */
#define DNS_RECORD_TYPE_DHCID          0x0031 /* DHCP identifier */
#define DNS_RECORD_TYPE_NSEC3          0x0032 /* Hashed denial of existence */
#define DNS_RECORD_TYPE_NSEC3PARAM     0x0033 /* NSEC3 parameters */
#define DNS_RECORD_TYPE_TLSA           0x0034 /* TLSA certificate association */
#define DNS_RECORD_TYPE_SMIMEA         0x0035 /* S/MIME cert association */
#define DNS_RECORD_TYPE_HIP            0x0037 /* Host identity protocol */
#define DNS_RECORD_TYPE_CDS            0x003B /* Child DS */
#define DNS_RECORD_TYPE_CDNSKEY        0x003C /* Child DNSKEY */
#define DNS_RECORD_TYPE_OPENPGPKEY     0x003D /* OpenPGP public key */
#define DNS_RECORD_TYPE_CSYNC          0x003E /* Child-to-parent sync */
#define DNS_RECORD_TYPE_ZONEMD         0x003F /* Zone message digest */
#define DNS_RECORD_TYPE_SVCB           0x0040 /* Service binding */
#define DNS_RECORD_TYPE_HTTPS          0x0041 /* HTTPS binding (SVCB-compatible) */
#define DNS_RECORD_TYPE_EUI48          0x006C /* MAC address (EUI-48) */
#define DNS_RECORD_TYPE_EUI64          0x0067 /* MAC address (EUI-64) */
#define DNS_RECORD_TYPE_TKEY           0x00F9 /* Transaction key */
#define DNS_RECORD_TYPE_TSIG           0x00FA /* Transaction signature */
#define DNS_RECORD_TYPE_URI            0x0100 /* Uniform resource identifier */
#define DNS_RECORD_TYPE_CAA            0x0101 /* Certification authority authorization */
#define DNS_RECORD_TYPE_TA             0x8000 /* Trust anchor (DNSSEC) */
#define DNS_RECORD_TYPE_DLV            0x8001 /* DNSSEC lookaside validation */

/* Pseudo-RRs and Meta Queries */
#define DNS_RECORD_TYPE_OPT            0x0029 /* EDNS0 option */
#define DNS_RECORD_TYPE_AXFR           0x00FC /* Authoritative zone transfer */
#define DNS_RECORD_TYPE_IXFR           0x00FD /* Incremental zone transfer */
#define DNS_RECORD_TYPE_ANY            0x00FF /* ANY (wildcard query) */

/* Obsolete, Experimental, and Non-Standard */
#define DNS_RECORD_TYPE_MD             0x0003 /* Mail destination (obsolete) */
#define DNS_RECORD_TYPE_MF             0x0004 /* Mail forwarder (obsolete) */
#define DNS_RECORD_TYPE_MB             0x0007 /* Mailbox domain name (experimental) */
#define DNS_RECORD_TYPE_MG             0x0008 /* Mail group member (experimental) */
#define DNS_RECORD_TYPE_MR             0x0009 /* Mail rename domain (experimental) */
#define DNS_RECORD_TYPE_NULL           0x000A /* Null RR (obsolete) */
#define DNS_RECORD_TYPE_WKS            0x000B /* Well-known service (obsolete) */
#define DNS_RECORD_TYPE_MINFO          0x000E /* Mailbox information (experimental) */
#define DNS_RECORD_TYPE_MAILA          0x00FE /* Mail agent (obsolete) */
#define DNS_RECORD_TYPE_MAILB          0x00FD /* Mailbox records (obsolete) */
#define DNS_RECORD_TYPE_NB             0x0020 /* NetBIOS general name service (non-standard) */
#define DNS_RECORD_TYPE_NBSTAT         0x0021 /* NetBIOS node status (non-standard) */
#define DNS_RECORD_TYPE_A6             0x0026 /* IPv6 address (historic) */
#define DNS_RECORD_TYPE_NXT            0x001E /* Next domain (obsolete DNSSEC) */
#define DNS_RECORD_TYPE_X25            0x0013 /* X.25 address (obsolete) */
#define DNS_RECORD_TYPE_ISDN           0x0014 /* ISDN address (obsolete) */
#define DNS_RECORD_TYPE_RT             0x0015 /* Route through (obsolete) */
#define DNS_RECORD_TYPE_NSAP           0x0016 /* NSAP address (obsolete) */
#define DNS_RECORD_TYPE_NSAP_PTR       0x0017 /* NSAP pointer (obsolete) */
#define DNS_RECORD_TYPE_PX             0x001A /* X.400 mail mapping information */
#define DNS_RECORD_TYPE_EID            0x001F /* Endpoint identifier (experimental) */
#define DNS_RECORD_TYPE_NIMLOC         0x0020 /* Nimrod locator (experimental) */
#define DNS_RECORD_TYPE_ATMA           0x0022 /* ATM address (experimental) */
#define DNS_RECORD_TYPE_SINK           0x0028 /* Kitchen sink (experimental) */
#define DNS_RECORD_TYPE_GPOS           0x001B /* Geographical position (obsolete) */
#define DNS_RECORD_TYPE_UINFO          0x0064 /* User info (removed) */
#define DNS_RECORD_TYPE_UID            0x0065 /* User ID (removed) */
#define DNS_RECORD_TYPE_GID            0x0066 /* Group ID (removed) */
#define DNS_RECORD_TYPE_UNSPEC         0x0067 /* Unspecified (removed) */
#define DNS_RECORD_TYPE_SPF            0x0063 /* Sender Policy Framework */
#define DNS_RECORD_TYPE_NINFO          0x0038 /* Zone information (expired) */
#define DNS_RECORD_TYPE_RKEY           0x0039 /* Record key (expired) */
#define DNS_RECORD_TYPE_TALINK         0x003B /* Trust anchor link */
#define DNS_RECORD_TYPE_NID            0x0068 /* Node ID (experimental) */
#define DNS_RECORD_TYPE_L32            0x0069 /* Locator 32-bit (experimental) */
#define DNS_RECORD_TYPE_L64            0x006A /* Locator 64-bit (experimental) */
#define DNS_RECORD_TYPE_LP             0x006B /* Locator pointer (experimental) */
#define DNS_RECORD_TYPE_DOA            0x0103 /* Digital object architecture (experimental) */


/*===============================================================
 * DNS Class Types
 *===============================================================*/
#define DNS_CLASS_RESERVED             0x0000 /* Reserved       (RFC6895) */
#define DNS_CLASS_IN                   0x0001 /* Internet       (RFC1035) */
#define DNS_CLASS_UNASSIGNED_2         0x0002 /* Unassigned */
#define DNS_CLASS_CH                   0x0003 /* Chaos          (MIT AI Memo 628) */
#define DNS_CLASS_HS                   0x0004 /* Hesiod         (Project Athena) */
#define DNS_CLASS_NONE                 0x00FE /* QCLASS NONE    (RFC2136) */
#define DNS_CLASS_ANY                  0x00FF /* QCLASS * (ANY) (RFC1035) */

/* Reserved for Private Use */
#define DNS_CLASS_PRIVATE_USE_MIN      0xFF00
#define DNS_CLASS_PRIVATE_USE_MAX      0xFFFE

#endif /* TINYDNS_COMMON_H */
