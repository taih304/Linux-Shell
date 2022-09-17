# Fundamental concepts

Consider that any device that runs a link-layer (i.e., layer 2) protocol as a **node**. Nodes include
hosts, routers, switches, and WiFi access points. We will also refer to the communication channels that connect adjacent nodes along the communication path as **links**.

![](../Environment/Images/link_layer.png)

As an example, in the company network shown at the bottom of Figure 5.1, consider sending a datagram from one of the wireless hosts to one of the servers. This datagram will actually pass through **six links**: a **WiFi link** between sending host and WiFi access point, an **Ethernet link** between the access point and a link-layer switch; a **link** between the link-layer switch and the router, a link between the two routers; an **Ethernet link** between the router and a link-layer switch; and finally an **Ethernet link** between the switch and the server. Over a given link, a transmitting node encapsulates the datagram in a **link-layer frame** and transmits the frame into the link.

## Where is the link layer implemented ?

We’ll focus here on an end system, since we learned that the link layer is implemented in **a router’s line card**.

Is **a host’s link layer** implemented in **hardware** or **software**? Is it implemented on a separate card or chip, and **how does it interface with the rest of a host’s hardware and operating system components**?

For the most part, the link layer is implemented in a **network adapter**, also sometimes known as a **network interface card** (NIC). At the heart of the **network adapter** is the **link-layer controller**, usually a **single, special-purpose chip** that implements many of the link-layer services (**framing, link access, error detection, and so on**). **Thus, much of a link-layer controller’s functionality is implemented in hardware**.

While most of the **link layer** is implemented in **hardware**, **part of the link layer** is implemented in **software** that runs on the host’s CPU. The **software** components of the link layer implement **higher-level link-layer** functionality such as **assembling link-layer addressing information** and **activating the controller hardware**. On the receiving side, **link-layer software** responds to **controller interrupts** (e.g., due to the receipt of one or more frames), **handling error conditions** and **passing a datagram up to the network layer**. Thus, **the link layer is a combination of hardware and software—the place in the protocol stack where software meets hardware**.

## Types of link layer channels

There are two fundamentally different types of link-layer channels: **broadcast** and **point to point**.

**Broadcast channels** connect **multiple hosts** in **wireless LANs**, **satellite networks**, and **hybrid fiber-coaxial cable (HFC) access networks**.

**Point-to-point** communication link is often found between **two routers connected by a long-distance link**, or between **a user’s office computer** and **the nearby Ethernet switch** to which it is connected.

# Protocols

## ARP

**ARP: Address Resolution Protocol**

The Address Resolution Protocol is a communication protocol used for discovering the link layer address, such as a MAC address, associated with a given internet layer address, typically an IPv4 address.

Install: ``sudo apt-get install arp-scan``

Scan all existed IP inside the network along with the MAC address: ``sudo arp-scan -l``
