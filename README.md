# Repository overview
Documents in this repository is organized based on the Internet protocol stack which consists of five layers: [physical](Physical%20layer), [link](Link%20layer), [network](Network%20layer), transport, and [application layers](Application%20layer).

**Repository working environment**: Document and source code in this project are implemented mainly in Ubuntu 16.04. Some specific steps are implmented in Ubuntu 20.04

# Ubuntu 16.04 unresolvable issues till 3 June 2023
* Github: Unable to copy file by Copy button
* [GCC is fixed with 5.0 and is unable to upgrade to newer version, which causes issue when compiling device tree in Raspbian](https://github.com/TranPhucVinh/Raspberry-Pi-GNU/blob/main/Kernel/Device%20tree/Add%20a%20new%20node%20to%20device%20tree%20by%20dtsi%20file%20modification.md)
* [Linux kernel 4.15.0-142-generic which doesn't support epoll events like EPOLLET, EPOLLIN, EPOLLOUT, EPOLLHUP,... in kernel space](https://github.com/TranPhucVinh/C/tree/master/Kernel/Character%20device/Character%20device%20operations/Poll#epoll-handling-in-character-device)
* [STM32CubeIDE](https://github.com/TranPhucVinh/STM32-HAL-Layer-Framework/blob/main/Environment/Install%2C%20run%20and%20debug.md):
  * v1.4.1.: Live Expression can't be used to watch/debug the Global variable
  * v1.5.1: 
    * Can't flash firmware to STM32 board by STlink v2.
    * Can't import an existed project to workspace while STM32CubeIDE v1.4.0 can import it normally.
  * STM32CubeIDE v1.7.0: Can't import an existed project to workspace.

# Internet hardware and software components

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

A group of protocols designed to work together is known as a **protocol suite**; when implemented in software they are a **protocol stack**.

Given the importance of protocols to the Internet, it’s important that everyone agree on what each and every protocol does, so that people can create systems and products that interoperate. This is where standards come into play. **Internet standards** are developed by the **Internet Engineering Task Force (IETF)[IETF 2012]**.

The **IETF** standards documents are called **requests for comments (RFCs)**. RFCs started out as general requests for comments (hence the name) to resolve network and protocol design problems that faced the precursor to the Internet [Allman 2011]. **RFCs** tend to be quite technical and detailed. They define protocols such as **TCP**, **IP**, **HTTP** (for the Web), and **SMTP** (for e-mail). There are currently more than 6,000 RFCs.

Other bodies also specify standards for network components, most notably for network links. The **IEEE 802 LAN/MAN Standards Committee** [IEEE 802 2012], for example, specifies the Ethernet and wireless WiFi standards.

## A services description

We can also describe the Internet from an entirely different angle—namely, as an infrastructure that provides services to applications. These applications include **electronic mail**, **Web surfing**, **social networks**, **instant messaging**, **Voice-over-IP (VoIP)**, **video streaming**, **distributed games**, **peer-to-peer (P2P) file sharing**, **television over the Internet**, **remote login**, and much, much more.

Importantly, **Internet applications run on end systems—they do not run in the packet switches in the network core**.
Although packet switches facilitate the exchange of data among end systems, they are not concerned with the application that is the source or sink of data.

**And here we get to a central issue—one that leads to the alternative way of describing the Internet as a platform for applications. How does one program running on one end system instruct the Internet to deliver data to another program running on another end system ?**

End systems attached to the Internet provide an **Application Programming Interface (API)** that specifies how a program running on one end system asks the Internet infrastructure to deliver data to a specific destination program running on another end system.

This Internet API is a set of rules that the sending program must follow so that the Internet can deliver the data to the destination program.

## Addressing process

In the Internet, the host is identified by its **IP address**. An IP address is a 32-bit quantity that we can think of as uniquely identifying the host.

In addition to knowing the address of the host to which a message is destined, the sending process must also identify the **receiving process** (more specifically, the **receiving socket**) running in the host. This information is needed because in general a host could be running many network applications. **A destination port number** serves this purpose. Popular applications have been assigned **specific port numbers**. For example, a Web server is identified by **port number 80**. A mail server process (using the SMTP protocol) is identified by port number 25.

# Protocol Layers and Their Service Models

## A human analogy to computer network protocol

Consider what you do when you want to ask someone for the time of day.

One person offer a greeting (the first “Hi” in Figure 1.2) to initiate communication with someone else. The typical response to a “Hi” is a returned “Hi” message.

Implicitly, one then takes a **cordial** “Hi” response as an indication that one can proceed and ask for the time of day. A different response to the initial “Hi” (such as “Don’t bother me!” or “I don’t speak English,” or some unprintable reply) might indicate an unwillingness or inability to communicate.

In this case, the **human protocol** would be not to ask for the time of day. **Sometimes one gets no response at all to a question, in which case one typically gives up asking that person for the time**. Note that **in our human protocol**, there are **specific messages** we send, and **specific actions** we take in response to the received reply messages or other events (**such as no reply within some given amount of time**).

If people **run different protocols** (for example, if one person has manners but the other does not, or if one understands the concept of time and the other does not) the protocols do not interoperate and **no useful work can be accomplished**. The same is true in networking, it takes two (or more) communicating entities running the same protocol in order to accomplish a task.

## Commmunication protocol in computer network

A **protocol** defines the format and the order of messages exchanged between two or more communicating entities, as well as the actions taken on the transmission and/or receipt of a message or other event.

**All activity in the Internet that involves two or more communicating remote entities is governed by a protocol**. For example, **hardware-implemented protocols** in two physically connected computers control the flow of bits on the “wire” between the two network interface cards; **congestion-control protocols** in end systems control the rate at which packets are transmitted between sender and receiver; **protocols** in routers determine a packet’s path from source to destination.

A **protocol layer** can be implemented in **software**, in **hardware**, or in a combination of the two. **Application-layer protocols**—such as **HTTP** and **SMTP**—are almost always implemented in **software** in the **end systems**; so are **transport-layer protocols**.

Because the **physical layer** and **data link layers** are responsible for handling communication over a specific link, they are typically implemented in a **network interface card** (for example, Ethernet or WiFi interface cards) associated with a given link. The **network layer** is often a **mixed** implementation of **hardware** and **software**.

OSI model defines 7 layers with their protocol unit:

* Application layer: APDU (Application protocol data unit)
* Presentation layer: PPDU (Presentation protocol data unit)
* Session layer: SPDU (Session protocol data unit)
* Transport layer: Segment
* Network layer: Packet
* Data-link layer: Frame
* Physical layer: Bits

However, those protocol unit name sometimes can be used interchangeably, like Modbus, which is an application layer protocol, called its APDU as Modbus frame.