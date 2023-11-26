# Overview

**An application-layer protocol** defines how an application’s processes, running on different end systems, pass messages to each other.

An application-layer protocol is distributed over multiple end systems, with the application in one end system using the protocol to exchange packets of information with the application in another end system. We’ll refer to this packet of information at the application layer as a message.

Let’s look at an example. **The Web** is a client-server application that allows users to obtain documents from Web servers on demand. The Web application consists of many components, including a standard for document formats (that is, HTML), Web browsers (for example, Firefox and Microsoft Internet Explorer), **Web servers** (for example, Apache and Microsoft servers), and an application-layer protocol.

The communication of applications/programs in multiple PCs or inside a single one, based on **their processes**. A **process** sends or receives messages through a software interface called a **socket**.

In addition to knowing the address of the host to which a message is destined, **the sending process must also identify the receiving process (more specifically, the receiving socket) running in the host**. This information is needed because in general a host could be running many network applications. **A destination port number** serves this purpose. Popular applications have been assigned specific port numbers. For example, a **Web server** is identified by port number 80. A mail server process (using the **SMTP** protocol) is identified by port number 25.

**Directory service**: a directory service or name service maps the names of network resources to their respective network addresses. A directory server or name server is a server that provides such a service. Domain Name System (DNS) is the first directory service on the Internet.

**VPS**, which stands for **virtual private server**, is a virtual machine sold as a service by an Internet hosting service.

A 16-bit computer means this computer can open up to 65536 port.

# DNS

## Hostname

Hostnames can be like ``cnn.com``, ``www.yahoo.com``, ``gaia.cs.umass.edu``, and ``cis.poly.edu``.

On the Internet, a **hostname** is a domain name assigned to a host computer. This is usually a combination of the host's local name with its parent domain's name. For example, ``en.wikipedia.org`` consists of a local hostname (en) and the domain name wikipedia.org.

Furthermore, because hostnames can consist of variable-length alphanumeric characters, they would be difficult to process by routers. For these reasons, hosts are also **identified** by so-called **IP addresses**.

To translate IP to hostname, we need DNS. The **DNS protocol** runs over UDP and uses port 53.

## How DNS works

DNS is commonly employed by other application-layer protocols—including **HTTP, SMTP, and FTP**—to translate user-supplied hostnames to IP addresses. As an example, consider what happens when a browser (that is, an HTTP client),
running on some user’s host, requests the URL **www.someschool.edu/index.html**. In order for the user’s host to be able to send an HTTP request message to the Web server www.someschool.edu, the user’s host must first obtain the IP address of www.someschool.edu. This is done as follows.

1. The same user machine runs the client side of the DNS application.
2. The browser extracts the hostname, www.someschool.edu, from the URL and passes the hostname to the client side of the DNS application.
3. The DNS client sends a query containing the hostname to a DNS server.
4. The DNS client eventually receives a reply, which includes the IP address for the hostname.
5. Once the browser receives the IP address from DNS, it can initiate a TCP connection to the HTTP server process located at port 80 at that IP address.

**Change DNS**

```shell
sudo nano /etc/resolv.conf
```

## mDNS

DNS works great for normal sites on the Internet, but most local networks don't have their own DNS server. This means that you can't reach local devices using a domain name, and you're stuck using IP addresses ...

Fortunately, there's another way: multicast DNS, or mDNS.

**mDNS** uses domain names with the ``.local`` suffix, for example ``http://esp8266.local``. If your computer needs to send a request to a domain name that ends in ``.local``, it will send a multicast query to all other devices on the LAN that support mDNS, asking the device with that specific domain name to identify itself. The device with the right name will then respond with another multicast and send its IP address. Now that your computer knows the IP address of the device, it can send normal requests.
# [Mail protocols](Mail%20protocols.md)
* [FTP]()
* [SMTP]() and [web-based e-mail]()
# Wget

``Wget`` is a free software package for retrieving files using [HTTP](HTTP), HTTPS, FTP and FTPS.

# [Desktop applications and GUI](GUI.md)
# Free software
**Free software** or **libre software** or **libreware** is computer software distributed under terms that allow users to run the software for any purpose as well as to study, change, and distribute it and any adapted versions. Free software is a matter of liberty, not price; all users are legally free to do what they want with their copies of a free software (including profiting from them) regardless of how much is paid to obtain the program.

Be not to confuse free software with [freeware](#freeware).
# Freeware
Freeware is software, most often proprietary, that is distributed at no monetary cost to the end user. There is no agreed-upon set of rights, license, or **EULA** (**End-user license agreement**) that defines freeware unambiguously; every publisher defines its own rules for the freeware it offers. For instance, modification, redistribution by third parties, and reverse engineering are permitted by some publishers but prohibited by others. Unlike with free and open-source software, which are also often distributed free of charge, the source code for freeware is typically not made available.
