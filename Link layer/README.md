# Fundamental concepts

There are two fundamentally different types of **link-layer channels**. The **first type** are **broadcast channels**, which connect **multiple hosts** in **wireless LANs**, **satellite networks**, and **hybrid fiber-coaxial cable (HFC) access networks**. The **second type** of link-layer channel is the **point-to-point** communication link, such as that often found between **two routers connected by a long-distance link**, or between **a user’s office computer** and **the nearby Ethernet switch** to which it is connected.

We’ll find it convenient in this chapter to refer to any device that runs a link-layer (i.e., layer 2) protocol as a **node**. Nodes include
hosts, routers, switches, and WiFi access points. We will also refer to the communication channels that connect adjacent nodes along the communication path as **links**.

![](../Environment/Images/link_layer.png)

As an example, in the company network shown at the bottom of Figure 5.1, consider sending a datagram from one of the wireless hosts to one of the servers. This datagram will actually pass through **six links**: a **WiFi link** between sending host and WiFi access point, an **Ethernet link** between the access point and a link-layer switch; a **link** between the link-layer switch and the router, a link between the two routers; an **Ethernet link** between the router and a link-layer switch; and finally an **Ethernet link** between the switch and the server. Over a given link, a transmitting node encapsulates the datagram in a **link-layer frame** and transmits the frame into the link.

# Protocols

## ARP

**ARP: Address Resolution Protocol**

The Address Resolution Protocol is a communication protocol used for discovering the link layer address, such as a MAC address, associated with a given internet layer address, typically an IPv4 address.

Install: ``sudo apt-get install arp-scan``

Scan all existed IP inside the network along with the MAC address: ``sudo arp-scan -l``
