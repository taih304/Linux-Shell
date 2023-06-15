The Internet’s transport layer transports application-layer messages between application endpoints. **Transport-layer protocols** are implemented in the end systems, not in network routers. 

A **transport-layer protocol** provides for logical communication between application processes running on different hosts.

**Application processes** use the **logical communication** provided by the transport layer to send messages to each other, free from the worry of the details of the **physical infrastructure** used to carry these messages.

Whereas a **transport-layer protocol** provides **logical communication between processes** running on different **hosts**, a network-layer protocol provides **logical communication between hosts** (i.e PC).

# TCP and UDP

The Internet’s **network-layer protocol** has a name—IP, for **Internet Protocol**.

IP provides logical communication between hosts. The IP service model is a **best-effort delivery service**. This means that IP makes its **“best effort”** to deliver segments between communicating hosts, **but it makes no guarantees**. In particular, it does not guarantee segment delivery, it does not guarantee orderly delivery of segments, and it does not guarantee the integrity of the data in the segments. For these reasons, IP is said to be an unreliable service.

The most fundamental responsibility of **UDP** and **TCP** is to **extend IP’s delivery service** between two end systems to a delivery service between two processes running on the end systems.

Extending host-to-host delivery to process-to-process delivery is called **transport-layer multiplexing** and **demultiplexing**. **UDP** and **TCP** also provide **integrity checking** by including error-detection fields in their segments’ headers. These two minimal **transport-layer services**—**process-to-process data delivery** and **error checking**—are the only two services that **UDP** provides! In particular, like IP, **UDP** is an unreliable service—it does not guarantee that data sent by one process will arrive intact (or at all!) to the destination process.

TCP, on the other hand, offers several additional services to applications. First and foremost, it provides **reliable data transfer**. TCP also provides **congestion control**.

**TCP** provides a **connection-oriented service** to its applications. This service includes guaranteed delivery of application-layer messages to the destination and flow control (that is, sender/receiver speed matching). **TCP** also breaks long messages into shorter segments and provides a congestion-control mechanism, so that a source throttles its transmission rate when the network is congested.

The **UDP** protocol provides a **connectionless service** to its applications. This is a no-frills service that provides no reliability, no flow control, and no congestion control. In this book, we’ll refer to a transport-layer packet as a **segment**.

# Multiplexing vs demultiplexing

In this section, we discuss **transport-layer multiplexing** and **demultiplexing**, that is, extending the **host-to-host** delivery service provided by the network layer to a **process-to-process** delivery service for applications running on the hosts.

First recall that a **process** (as part of a network application) can have **one or more sockets**, **doors** through which data passes from the network to the process and through which data passes from the process to the network.

Thus, the **transport layer** in the receiving host **does not actually deliver data directly to a process**, but instead to **an intermediary socket**.

Because at any given time there can be **more than one socket** in the receiving host, each socket has **a unique identifier**. The format of the identifier depends on whether the socket is a **UDP or a TCP socket**.

**How a receiving host directs an incoming transport-layer segment to the appropriate socket ?**

Each **transport-layer segment** has **a set of fields in the segment** for this purpose. At the receiving end, the transport layer examines these fields to **identify the receiving socket** and then **directs the segment to that socket**. This job of delivering the data in a transport-layer segment to the correct socket is called **demultiplexing**.

The job of **gathering data chunks** at the source host from different sockets, **encapsulating each data chunk** with **header information** (that will later be used in **demultiplexing**) to **create segments**, and passing the segments to the network layer is called **multiplexing**.

From the discussion above, we know that **transport-layer multiplexing** requires (1) that **sockets have unique identifiers**, and (2) that **each segment have special fields** that indicate the socket to which the segment is to be delivered. These special fields, illustrated in Figure 3.3, are the **source port number field** and the **destination port number field**.

**Each port number is a 16-bit number, ranging from 0 to 65535. The port numbers ranging from 0 to 1023 are called well-known port numbers and are restricted, which means that they are reserved for use by well-known application protocols such as HTTP (which uses port number 80) and FTP (which uses port number 21)**.

When we develop a new application we **must assign the application a port number**.

It should now be clear how the transport layer could implement the demultiplexing service:

Each **socket** in the host could be assigned a **port number**, and when a segment arrives at the host, the transport layer **examines the destination port number in the segment** and **directs the segment to the corresponding socket**. The segment’s data then passes through the socket into the attached process. As we’ll see, **this is basically how UDP does it**. However, we’ll also see that multiplexing/demultiplexing in TCP is yet more subtle.

# TCP and UDP socket

It is important to note that a **UDP socket** is fully identified by a two-tuple consisting of a **destination IP address** and a **destination port number**. As a consequence, if **two UDP segments** have **different source IP addresses and/or source port numbers**, but have the **same destination IP address** and **destination port number**, then the two segments will be directed to the same destination process via the same destination socket.

**In contrast with UDP**, two arriving TCP segments with **different source IP addresses** or **source port numbers** will (with the exception of a TCP segment carrying the original connection-establishment request) be directed to **two different sockets**. .

The **destination host** will still be able to correctly **demultiplex** the two connections having the same source port number, since **the two connections have different source IP addresses**.

One subtle difference between a TCP socket and a UDP socket is that a TCP socket is identified by a four-tuple: **(source IP address, source port number, destination IP address, destination port number)**.

Thus, when a TCP segment arrives from the network to a host, the host uses all four values to direct (demultiplex) the segment to the appropriate socket. In particular, and in contrast with UDP, **two arriving TCP segments** with **different source IP addresses** or **source port numbers** will (**with the exception of a TCP segment carrying the original connection-establishment request**) be directed to **two different sockets**.

# How TCP server and TCP client work

• The **TCP server application** has a “welcoming socket,” that waits for connection-establishment requests from TCP clients on port number 12000.
• The **TCP client** creates a socket and sends a connection establishment request segment with the lines:

```c
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,12000))
```

• A connection-establishment request is nothing more than a TCP segment with destination port number 12000 and a special connection-establishment bit set in the TCP header (discussed in Section 3.5). The segment also includes a source port number that was chosen by the client.
• When the host operating system of the computer running the server process receives the incoming connection-request segment with destination port 12000, it locates the server process that is waiting to accept a connection on port number 12000. The server process then creates a new socket:

```c
connectionSocket, addr = serverSocket.accept()
```

Also, the transport layer at the server notes the following four values in the connection-request segment: **(1) the source port number in the segment, (2) the IP address of the source host, (3) the destination port number in the segment, and (4) its own IP address**. The newly created connection socket is identified by these four values; all subsequently arriving segments whose source port, source IP address, destination port, and destination IP address match these four values will be demultiplexed to this socket. With the TCP connection now in place, the client and server can now send data to each other.

**The server host may support many simultaneous TCP connection sockets**, with each socket attached to a process, and with each socket identified by its own four-tuple. When a TCP segment arrives at the host, all four fields **(source IP address, source port, destination IP address, destination port)** are used to direct (demultiplex) the segment to the appropriate socket.

# Port scanning

We’ve seen that a server process **waits patiently** on an open port for contact by a remote client. Some ports are reserved for **well-known applications** (e.g., Web, FTP, DNS, and SMTP servers); other ports are used by convention by **popular applications** (e.g., the Microsoft 2000 SQL server listens for requests on UDP port 1434). **Thus, if we determine that a port is open on a host, we may be able to map that port to a specific application running on the host**. This is very useful for **system administrators**, who are often interested in knowing which network applications are running on the hosts in their networks. But **attackers**, in order to “case the joint,” also want to know which ports are open on target hosts. **If a host is found to be running an application with a known security flaw (e.g., a SQL server listening on port 1434 was subject to a buffer overflow, allowing a remote user to execute arbitrary code on the vulnerable host**, a flaw exploited by the Slammer worm [CERT 2003–04]), then that host is ripe for attack.

**Determining which applications are listening on which ports is a relatively easy task**. Indeed there are a number of public domain programs, called port scanners, that do just that. Perhaps the most widely used of these is **nmap**, freely available at ``http://nmap.org`` and included in most Linux distributions. **For TCP, nmap sequentially scans ports, looking for ports that are accepting TCP connections**. For UDP, nmap again sequentially scans ports, looking for UDP ports that respond to transmitted UDP segments. In both cases, nmap returns a list of open, closed, or unreachable ports. A host running nmap can attempt to scan any target host anywhere in the Internet. We’ll revisit nmap in Section 3.5.6, when we discuss TCP connection management.

Base on what we learn above, **a Web server that spawns a new process for each connection**. Each of these processes has its own connection socket through which HTTP requests arrive and HTTP responses are sent. We mention, however, that **there is not always a one-to-one correspondence between connection sockets and processes**. In fact, today’s high-performing Web servers often **use only one process**, and **create a new thread with a new connection socket for each new client connection**. (**A thread can be viewed as a lightweight subprocess**.). **For such a server, at any given time there may be many connection sockets (with different identifiers) attached to the same process**.

**If the client and server are using persistent HTTP**, then throughout the duration of the persistent connection the client and server exchange HTTP messages via the same server socket. However, **if the client and server use non-persistent HTTP**, then **a new TCP connection is created and closed for every request/response**, and hence a new socket is created and later closed for every request/response. **This frequent creating and closing of sockets can severely impact the performance of a busy Web server** (although a number of operating system tricks can be used to mitigate the problem).