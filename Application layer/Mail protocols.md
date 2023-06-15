# FTP

**FTP** uses **two parallel TCP connections** to transfer a file, a **control connection** and a **data connection**.

**FTP**: TCP **control connection port 21**, TCP **data connection port 20**

When a user starts an FTP session with a remote host, the client side of FTP (user) first initiates a control TCP connection with the server side (remote host) on server **port number 21**. The **client side** of FTP sends the user identification and password over this control connection. The client side of FTP also sends, over the control connection, commands to change the remote directory. When the **server side receives** a command for a file transfer over the control connection (either to, or from, the remote host), the server side **initiates a TCP data connection** to the **client side**. **FTP sends exactly one file over the data connection and then closes the data connection**. **If, during the same session, the user wants to transfer another file, FTP opens another data connection**. Thus, with FTP, the control connection **remains open** throughout the duration of the user session, but **a new data connection is created for each file transferred within a session** (that is, the data connections are **non-persistent**).

FTP is a **state protocol** as it keep track of state information for each ongoing user session significantly to  **constrain** the total number of sessions that FTP can maintain simultaneously.

Like HTTP and other application layer protcols, FTP has command and status code.

# SMTP

**SMTP** is the **principal application-layer protocol** for Internet electronic mail. It uses the reliable data transfer service of TCP to transfer mail from the sender’s mail server to the recipient’s mail server. 

As with most application-layer protocols, **SMTP** has two sides: **a client side**, which executes on **the sender’s mail server**, and **a server side**, which executes on the recipient’s mail server. Both the client and server sides of SMTP run on every mail server. When a mail server sends mail to other mail servers, it acts as an **SMTP client**. When a mail server receives mail from other **mail servers**, it acts as an **SMTP server**.

## SMTP is much older than HTTP

To illustrate the basic operation of SMTP, let’s walk through a common scenario. Suppose Alice wants to send Bob a simple ASCII message.

1. Alice invokes her user agent for e-mail, provides Bob’s e-mail address (for example, bob@someschool.edu), composes a message, and instructs the user agent to send the message.

2. Alice’s user agent sends the message to her mail server, where it is placed in a
message queue.

3. The **client side of SMTP**, running on Alice’s mail server, sees the message in the message queue. It opens a TCP connection to an **SMTP server**, running on Bob’s mail server.

4. After some initial SMTP handshaking, the SMTP client sends Alice’s message into the TCP connection.

5. At Bob’s mail server, the **server side of SMTP** receives the message. Bob’s mail server then places the message in Bob’s mailbox.

6. Bob invokes his user agent to read the message at his convenience.

We mention here that SMTP uses **persistent connections**: If the sending mail server has several messages to send to the same receiving mail server, it can send all of the messages over the same TCP connection.

## Comparison with HTTP

Let’s now briefly compare **SMTP** with **HTTP**. Both protocols are used to transfer files from one host to another: **HTTP** transfers files (also called objects) from a **Web server** to a **Web client** (typically a browser); **SMTP** transfers files (that is, e-mail messages) from **one mail server** to **another mail server**.

## Mail Access protocol

SMTP is a push protocol as it push mail to the server, to read or retrieve the email, you need to have the pull protocol like POP3, IMAP.

Once SMTP delivers the message from Alice’s mail server to Bob’s mail server, the message is placed in Bob’s mailbox. Throughout this discussion we have tacitly **assumed that** Bob **reads his mail by logging onto the server host and then executing a mail reader that runs on that host**. **Up until the early 1990s this was the standard way of doing things**. But today, mail access uses a **client-server architecture**—the typical user reads e-mail with a client that executes on the user’s end system, for example, on an office PC, a laptop, or a smartphone. By executing a mail client on a local PC, users enjoy a rich set of features, including the ability to view multimedia messages and attachments.

There are currently a number of popular mail access protocols, including **Post Office Protocol—Version 3 (POP3)**, **Internet Mail Access Protocol (IMAP)**, and **HTTP**.

## Web-Based E-Mail

More and more users today are sending and accessing their e-mail through their Web browsers. Hotmail introduced Web-based access in the mid 1990s. Now **Web-based e-mail** is also provided by Google, Yahoo!, as well as just about every major university and corporation. With this service, the user agent is an ordinary Web browser, and the user communicates with its remote mailbox via HTTP. When a recipient, such as Bob, wants to access a message in his mailbox, **the e-mail message is sent from Bob’s mail server to Bob’s browser using the HTTP protocol** rather than the **POP3 or IMAP protocol**. When a sender, such as Alice, wants to send an e-mail message, **the e-mail message is sent from her browser to her mail server over HTTP rather than over SMTP**. Alice’s mail server, however, still sends messages to, and receives messages from, other mail servers **using SMTP**.