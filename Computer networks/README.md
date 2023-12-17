# Internet hardware and software components

Devices connected to the Internet like PC, mobile, server are all called **host** or **end-system**.

End systems are connected together by a network of **communication links** and **packet switches**.

There are many types of **communication links**, which are made up of different types of physical media, including **coaxial**, **cable**, **copper wire**, **optical fiber**, and **radio spectrum**.

Different links can transmit data at different rates, with the transmission rate of a link measured in **bits/second**.

**Packet switches** come in many shapes and flavors, but the two most prominent types in today’s Internet are **routers** and **link-layer switches**. Generally, a packet switch will store then forward the packet it received.

The **circuit-switched networks** is another example of the **packet switches**. In circuit-switched networks, the resources needed along a path (buffers, link transmission rate) to provide for communication between the end systems are reserved for the duration of the communication session between the end systems. 

**Traditional telephone networks** are examples of circuit-switched networks. Consider what happens when one person wants to send information (voice or facsimile) to another over a telephone network. Before the sender can send the information, the network must establish a connection between the sender and the receiver. This is a bona fide connection for which the switches on the path between the sender and receiver maintain connection state for that connection. In the jargon of telephony, this connection is called **a circuit**. When the network establishes the circuit, it also reserves a constant transmission rate in the network’s links (representing a fraction of each link’s transmission capacity) for the duration of the connection. Since a given transmission rate has been reserved for this sender-to-receiver connection, the sender can transfer the data to the receiver at the guaranteed constant rate.

A circuit in a circuit-switched network is implemented with either **frequency-division multiplexing (FDM)** or **time division multiplexing (TDM)**.

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

One person offer a greeting. e.g “Hi”, to initiate communication with someone else. The typical response to a “Hi” is a returned “Hi” message.

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

# Internet accessing
The ISP can provide either wired or wireless connectivity for internet acccess, using an array of access technologies including DSL, cable, FTTH, Wi-Fi, and cellular.
## Broadband residential access
Today, the two most prevalent types of **broadband residential access** are **digital subscriber line** (**DSL**) and **cable**.

A residence typically obtains **DSL Internet** access from the same local telephone company (telco) that provides its wired local phone access.

Thus, when **DSL** is used, a customer’s telephone company (telco) is also its ISP. Each customer’s DSL modem uses the existing telephone line to exchange data with a **digital subscriber line access multiplexer (DSLAM)** located in the telco’s local central office (CO). The home’s DSL modem takes digital data and translates it to high frequency tones for transmission over telephone wires to the CO; the analog signals from many such houses are translated back into digital format at the DSLAM.

While DSL makes use of the telco’s existing local telephone infrastructure, **cable Internet access** makes use of the cable television company’s existing cable television infrastructure. A residence obtains cable Internet access from the same company that provides its cable television.
## Internet access in enterprise and home by Ethernet and WiFi

**A typical home network**

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/typical_network.png)

On corporate and university campuses, and increasingly in home settings, a **local area network (LAN)** is used to connect an end system to the edge router.

In a **wireless LAN** setting, wireless users transmit/receive packets to/from an access point that is connected into the enterprise’s network (most likely including wired Ethernet), which in turn is connected to the **wired Internet**. A **wireless LAN** user must typically be within **a few tens of meters** of the access point.

## Wide-area wireless access by cellular network

Devices, which employ the same wireless infrastructure used for **cellular telephony**, are able to access the Internet through a base station that is operated by the cellular network provider. Unlike WiFi, devies need only be within **a few tens of kilometers** (as opposed to a few tens of meters) of the base station to be able to access to that Internet services.
# Cloud provider

A **service level agreement** or **SLA** is a contractual commitment between the cloud service provider and the customer about the **expected level of service**. If customers get the service under SLA, customer will be eligible to receive the compensation, e.g financial or Service credits.

**Service Level Indicator** (**SLI**) is a **metric/measurement** that indicates what measure of performance a customer is receiving at a given time.

A **SLI metric** could be **uptime**, **performance**, **availability**, **throughput**, **latency**, **error rate**, **durability**, **correctness**,...

**Service level objective** or **SLO**: The objective that the provider has agreed to meet​/The goal for your cloud service performance level. SLOs are represented as a specific target percentage over a period of time, e.g SLO of latency is 0.1 ms, SLO of availability is 99.99%,...

When the service performance meets or exceeds the SLO, end users, customers, and internal stakeholders will be happy for sure

SLO is treated as a part of SLA

Why is the expectation for 100% service availability misleading ?

Because service maintenance is **inevitable** and **requires downtime**. In order to roll out updates, operators have to take a system offline. Ensuring 100% service availability is also incredibly expensive for any business.

Error budget is the space between SLA and SLO

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/error_budget.png)