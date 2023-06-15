The Internet’s network layer is responsible for moving network-layer packets known as datagrams from one host to another. The Internet transport-layer protocol (TCP or UDP) in a source host passes a transport-layer segment and a destination address to the network layer, just as you would give the postal service a letter with a destination address. The network layer then provides the service of delivering the segment to the transport layer in the destination host.

The Internet’s network layer includes the celebrated IP Protocol, which defines the fields in the datagram as well as how the end systems and routers act on these fields. There is only one IP protocol, and all Internet components that have a network layer must run the IP protocol. The Internet’s network layer also contains **routing protocols** that determine the routes that datagrams take between sources and destinations. The Internet has many routing protocols. As we saw in Section 1.3, the Internet is a network of networks, and within a network, **the network administrator** can run any routing protocol desired. Although the network layer contains both the IP protocol and numerous routing protocols, it is often simply referred to as the IP layer, reflecting the fact that IP is the glue that binds the Internet together.

![](../Environment/Images/network_layer.png)

The Internet’s network layer has three major components:
* The first component is the IP protocol.
* The second major component is the **routing component**, which determines the path a datagram follows from source to destination. We mentioned earlier that **routing protocols** compute the forwarding tables that are used to forward packets through the network.
* The final component of the network layer is a facility to report errors in datagrams and respond to requests for certain network-layer information: the **[Internet Control Message Protocol (ICMP)](#ICMP)**

# Network Service Models

Let’s now consider some possible services that the network layer could provide. In the sending host, **when the transport layer passes a packet to the network layer**, specific services that could be provided by the network layer include:

• **Guaranteed delivery**: This service guarantees that the packet will eventually arrive at its destination.

• **Guaranteed delivery with bounded delay**. This service not only guarantees delivery of the packet, but delivery within a specified host-to-host delay bound (for example, within 100 msec).

Furthermore, the following services could be provided to a flow of packets between a given source and destination:

• **In-order packet delivery**: This service guarantees that packets arrive at the destination in the order that they were sent.

• **Guaranteed minimal bandwidth**: This network-layer service emulates the behavior of a transmission link of a specified bit rate (for example, 1 Mbps) between sending and receiving hosts. As long as the sending host transmits bits (as part of packets) at a rate below the specified bit rate, then no packet is lost and each packet arrives within a prespecified host-to-host delay (for example, within 40 msec).

• **Guaranteed maximum jitter**: This service guarantees that the amount of time between the transmission of two successive packets at the sender is equal 
to the amount of time between their receipt at the destination (or that this spacing changes by no more than some specified value).

• **Security services**. Using a **secret session** key known only by a source and destination host, the network layer in the source host could **encrypt** the payloads of all datagrams being sent to the destination host. The network layer in the destination host would then be responsible for decrypting the payloads. With such a service, confidentiality would be provided to all transport-layer segments (TCP and UDP) between the source and destination hosts. In addition to confidentiality, the network layer could provide data integrity and source authentication services.

# ICMP

**ICMP**, specified in [RFC 792], is used by hosts and routers to communicate network-layer information to each other. The most typical use of ICMP is for **error reporting**. For example, when running a Telnet, FTP, or HTTP session, you may have encountered an **error message** such as “Destination network unreachable.” This message had its origins in **ICMP**.

**ICMP** is often considered part of IP but architecturally **it lies just above IP**, as **ICMP messages are carried inside IP datagrams**. That is, ICMP messages are carried **as IP payload**, just as **TCP or UDP segments are carried as IP payload**. Similarly, **when a host receives an IP datagram with ICMP specified as the upper-layer protocol**, it **demultiplexes** the datagram’s contents to ICMP, **just as it would demultiplex a datagram’s content to TCP or UDP**.

# Proxy

Error when installing other package on Linux or Linux Docker

For example, install ``Node.js`` on Debian docker container

```
E: Failed to fetch http://deb.debian.org/debian/pool/main/n/nodejs/nodejs_4.8.2~dfsg-1_amd64.deb
Hash Sum mismatch
```

This might be a proxy error

To set up proxy from terminal

```shell
export http_proxy=http://10.10.10.10:8080
```

To unset proxy: ``unset http_proxy`` (follow the command above)

# XCP

XCP (or) "Universal Measurement and Calibration Protocol" is a **network protocol** originating from **ASAM** (Association for Standardisation of Automation and Measuring Systems) for connecting calibration systems to electronic control units, ECUs. It enables read and write access to variables and memory contents of microcontroller systems at runtime. Entire datasets can be acquired or stimulated synchronous to events triggered by timers or operating conditions. In addition, XCP also supports programming of flash memory.
