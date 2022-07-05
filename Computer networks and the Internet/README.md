# Fundamental concepts

The Internet protocol stack consists of five layers: the physical, link, network, transport, and application layers.

### Its hardware and software components

Devices connected to the Internet like PC, mobile, server are all called **host** or **end-system**.

End systems are connected together by a network of **communication links** and **packet switches**.

There are many types of **communication links**, which are made up of different types of physical media, including **coaxial**, **cable**, **copper wire**, **optical fiber**, and **radio spectrum**.

Different links can transmit data at different rates, with the transmission rate of a link measured in **bits/second**.

Packet switches come in many shapes and flavors, but the two most prominent types in today’s Internet are **routers** and **link-layer switches**.

End systems access the Internet through **Internet Service Providers (ISPs)**, including residential ISPs such as local cable or telephone companies; corporate ISPs; university ISPs; and ISPs that provide WiFi access in airports, hotels, coffee shops, and other public places.

Each ISP is in itself a network of **packet switches** and **communication links**. ISPs provide a variety of types of network access to the end systems, including **residential broadband access** such as **cable modem** or **DSL**, **high-speed local area network access**, **wireless access**, and **56 kbps dial-up modem access**.

These **lower-tier ISPs** are interconnected through national and international **upper-tier ISPs** such as Level 3 Communications, AT&T, Sprint, and NTT.

An upper-tier ISP consists of high-speed routers interconnected with high-speed fiber-optic links.

End systems, packet switches, and other pieces of the Internet run **protocols** that control the sending and receiving of information within the Internet. **The Transmission Control Protocol (TCP)** and **the Internet Protocol (IP)** are two of the most important protocols in the Internet.

Given the importance of protocols to the Internet, it’s important that everyone agree on what each and every protocol does, so that people can create systems and products that interoperate. This is where standards come into play. **Internet standards** are developed by the **Internet Engineering Task Force (IETF)[IETF 2012]**.

The **IETF** standards documents are called **requests for comments (RFCs)**. RFCs started out as general requests for comments (hence the name) to resolve network and protocol design problems that faced the precursor to the Internet [Allman 2011]. **RFCs** tend to be quite technical and detailed. They define protocols such as **TCP**, **IP**, **HTTP** (for the Web), and **SMTP** (for e-mail). There are currently more than 6,000 RFCs.

Other bodies also specify standards for network components, most notably for network links. The **IEEE 802 LAN/MAN Standards Committee** [IEEE 802 2012], for example, specifies the Ethernet and wireless WiFi standards.

### A services description

We can also describe the Internet from an entirely different angle—namely, as an infrastructure that provides services to applications. These applications include **electronic mail**, **Web surfing**, **social networks**, **instant messaging**, **Voice-over-IP (VoIP)**, **video streaming**, **distributed games**, **peer-to-peer (P2P) file sharing**, **television over the Internet**, **remote login**, and much, much more.

Importantly, **Internet applications run on end systems—they do not run in the packet switches in the network core**.
Although packet switches facilitate the exchange of data among end systems, they are not concerned with the application that is the source or sink of data.

**And here we get to a central issue—one that leads to the alternative way of describing the Internet as a platform for applications. How does one program running on one end system instruct the Internet to deliver data to another program running on another end system ?**

End systems attached to the Internet provide an **Application Programming Interface (API)** that specifies how a program running on one end system asks the Internet infrastructure to deliver data to a specific destination program running on another end system.

This Internet API is a set of rules that the sending program must follow so that the Internet can deliver the data to the destination program.

# IoT protocol stack

**Infrastructure**: IPv6 IPv4, 6LowPAN

**Identification**: IPv6, URIs, uCode

**Discovery** (Used to discover IoT devices): mDNS, Bonjour

**Semantic**: JSON-LD, Web Thing model

### Definitions

**uCode**: The ucode system (written in lower case "ucode") is an identification number system that can be used to identify things in the real world uniquely. The ucode system uses 128 bit code for unique naming of things so there are 340282366920938463463374607431768211455 or 3.4 x 10^38 different codes. ucode is supported by the uID center, which is a non-profit organisation.

**Web Thing**: A Web Thing (or simply Thing) is a digital representation of a physical object accessible via a RESTful Web API. An examples of Web Things is an MCU board which have TCP/IP suite.
