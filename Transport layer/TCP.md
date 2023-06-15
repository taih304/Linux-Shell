TCP is said to be **connection-oriented** because before one application process can begin to send data to another, the two processes must first 
**“handshake”** with each other—that is, they must send some preliminary segments to each other to establish the parameters of the ensuing data transfer.

# Where does TCP connection work ?

The TCP “connection” **is not** an end-to-end TDM or FDM circuit as in a circuit-switched network. **Nor is it a virtual circuit (see Chapter 1), as the connection state resides entirely in the two end systems**. Because the TCP protocol **runs only in the end systems** and **not in the intermediate network elements** (routers and link-layer switches), the intermediate network elements do not maintain TCP connection state.

In fact, the **intermediate routers** are completely **oblivious to TCP connections**; they **see datagrams, not connections**.

For now it suffices to know that **the client first sends a special TCP segment**; **the server responds with a second special TCP segment**; and finally **the client responds again with a third special segment**.
The first two segments carry no payload, that is, no application-layer data; the third of these segments may carry a payload.
Because **three segments are sent between the two hosts**, this connection-establishment procedure is often referred to as a **three-way handshake**.

# Reliable Data Transfer

Recall that the Internet’s network-layer service (**IP service**) is **unreliable**. IP does not guarantee datagram delivery, does not guarantee in-order delivery of datagrams, and does not guarantee the integrity of the data in the datagrams.
 
With IP service, datagrams can overflow router buffers and never reach their destination, datagrams can arrive out of order, and bits in the datagram can get corrupted (flipped from 0 to 1 and vice versa). Because transport-layer segments are carried across the network by IP datagrams, transport-layer segments can suffer from these problems as well.

**TCP** creates a **reliable data transfer** service on top of IP’s unreliable best-effort service. **TCP’s reliable data transfer service** ensures that the data stream that a process reads out of its TCP receive buffer is **uncorrupted**, **without gaps**, **without duplication**, and **in sequence**; that is, the byte stream is exactly the same byte stream that was sent by the end system on the other side of the connection. **How TCP provides a reliable data transfer involves many of the principles that we studied** ?

Is **TCP** a **GBN** or an **SR** protocol? **TCP** looks a lot like a **GBN-style protocol**. But there are some striking differences between TCP and Go-Back-N.

**A proposed modification to TCP**, the so-called selective acknowledgment [RFC 2018], allows a TCP receiver to acknowledge out-of-order segments selectively rather than just cumulatively acknowledging the last correctly received, in-order segment.

Thus, **TCP’s error-recovery mechanism** is probably best categorized as a **hybrid of GBN and SR protocols**.

# Flow control in TCP: Why it is required ?

**Recall that the hosts on each side of a TCP connection set aside a receive buffer for the connection**. When the TCP connection receives bytes that are correct and in sequence, **it places the data in the receive buffer**. **The associated application process** will read data from this buffer, but **not necessarily at the instant the data arrives**. Indeed, **the receiving application may be busy with some other task and may not even attempt to read the data until long after it has arrived**. If **the application is relatively slow at reading the data**, the sender can very **easily overflow** the connection’s receive buffer by sending too much data too quickly.

TCP provides a **flow-control service** to its applications to eliminate the possibility of the sender overflowing the receiver’s buffer.

Flow control is thus **a speed-matching service**—**matching the rate at which the sender is sending against the rate at which the receiving application is reading**.

# Congestion control

Packet loss is typically results from **the overflowing of router buffers as the network becomes congested**. **Packet retransmission** thus treats a **symptom of network congestion (the loss of a specific transport-layer segment)** but **does not treat the cause of network congestion**—too many sources attempting to send data at too high a rate. 
To treat the cause of network congestion, **mechanisms are needed to throttle senders in the face of network congestion**.

• **End-to-end congestion control**: In an end-to-end approach to congestion control, **the network layer provides no explicit support to the transport layer for congestion-control purposes**. Even the presence of congestion in the network must be inferred by the end systems based only on observed network behavior (for example, packet loss and delay). 

• **Network-assisted congestion control**: With **network-assisted congestion control**, **network-layer components** (that is, routers) provide explicit feedback to the sender regarding the congestion state in the network. This feedback may be **as simple as a single bit indicating congestion** at a link. This approach was taken in the early **IBM SNA** [Schwartz 1982] and **DEC DECnet** [Jain 1989; Ramakrishnan 1990] **architectures**, was recently proposed for **TCP/IP networks** [Floyd TCP 1994; RFC 3168], and is used in **ATM available bit-rate (ABR) congestion control** as well.

For network-assisted congestion control, congestion information is typically **fed back from the network to the sender in one of two ways**.
Direct feedback may be sent from a network router to the sender. **This form of notification typically takes the form of a choke packet (essentially saying, “I’m congested!”)**. The second form of notification occurs when a router marks/updates a field in a packet flowing from sender to receiver to indicate congestion. Upon receipt of a marked packet, the receiver then notifies the sender of the congestion indication. **Note that this latter form of notification takes at least a full round-trip time**.

# TCP congestion control

As indicated in the previous section, **TCP must use end-to-end congestion control** rather than **network-assisted congestion control**, since the IP layer provides no explicit feedback to the end systems regarding network congestion.

**The approach taken by TCP** is to **have each sender limit the rate at which it sends traffic into its connection as a function of perceived network congestion**.

**If a TCP sender perceives that there is little congestion on the path between itself and the destination**, then the TCP sender **increases its send rate**;
 
**if the sender perceives that there is congestion along the path**, then the sender **reduces its send rate**. 

But this approach raises three questions. **First**, how does a TCP sender **limit the rate** at which it sends traffic into its connection? **Second**, how does a TCP sender **perceive that there is congestion** on the path between itself and the destination? And **third**, what algorithm should the sender use to change its send rate as a function of perceived end-to-end congestion?

**Let’s first examine how a TCP sender limits the rate at which it sends traffic into its connection**. In Section 3.5 we saw that each side of a TCP connection consists of a receive buffer, a send buffer, and several variables (LastByteRead, rwnd, and so on). The TCP congestion-control mechanism operating at the sender keeps track of an additional variable, the congestion window.

# Implement TCP with nc

``nc``: arbitrary TCP and UDP connections and listens

## Receives data from TCP trasmitters

``nc -l 8000``: Start listening on port 8000. This will listen for only one connection on port 8000. After receiving and finishing its first connection, the command will stop.

``nc -kl 8000``: Forces ``nc`` to stay listening for another connection after its current connection is completed.

Then other TCP transmitters can start sending data to it.

**TCP transmitter**:

* Terminal console

In other terminal console: ``nc 127.0.0.1 8000``. This will listen to the IP ``127.0.0.1`` on port 8000. 

Then every thing typed in every console will be broad cast to the others.

Send a string to TCP receiver: ``echo Hello, World ! | nc 192.168.107.219 8000`` 

* ESP8266: For a TCP client/transmitter that sends a string to netcat TCP client: Check ``TCP client.md`` in ``ESP8266-Arduino-framework/Application layer/``

* Web browser: Type ``localhost:8000`` on web browser, then ``nc -l 8000`` will print out the response.

## Sending data to another TCP client

``nc -l 8000 < data.csv``: TCP server sends ``data.csv`` to every TCP client which listens to it.

``nc 127.0.0.1 8000 < data.csv``: TCP client sends ``data.csv`` to every TCP client which it is listening to.

**Note**: Those commands just send the file only one time, even if putting with ``nc -kl``. To send the file forever:

```sh
while [ true ]
do
    nc -l 8000 < data.csv
done 
```
