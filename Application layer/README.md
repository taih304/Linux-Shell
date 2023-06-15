**An application-layer protocol** defines how an application’s processes, running on different end systems, pass messages to each other.

An application-layer protocol is distributed over multiple end systems, with the application in one end system using the protocol to exchange packets of information with the application in another end system. We’ll refer to this packet of information at the application layer as a message.

Let’s look at an example. **The Web** is a client-server application that allows users to obtain documents from Web servers on demand. The Web application consists of many components, including a standard for document formats (that is, HTML), Web browsers (for example, Firefox and Microsoft Internet Explorer), **Web servers** (for example, Apache and Microsoft servers), and an application-layer protocol.

The communication of applications/programs in multiple PCs or inside a single one, based on **their processes**. A **process** sends or receives messages through a software interface called a **socket**.

In addition to knowing the address of the host to which a message is destined, **the sending process must also identify the receiving process (more specifically, the receiving socket) running in the host**. This information is needed because in general a host could be running many network applications. **A destination port number** serves this purpose. Popular applications have been assigned specific port numbers. For example, a **Web server** is identified by port number 80. A mail server process (using the **SMTP** protocol) is identified by port number 25.

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

``Wget`` is a free software package for retrieving files using HTTP, HTTPS, FTP and FTPS.
# Text editor

By default, Linux support 2 terminal text editors, ``vim`` (with command ``vi``) and nano (with command ``nano``).

``vi`` is extremely light while ``nano`` has bigger size. In some lightweight OS, like some Xilinx OS deployed in the Automotive drive monitoring system, only ``vim`` is supported.

For nano, check [nano document](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Physical%20layer/File%20system/Write%20operations.md#nano).

# Desktop applications

Check [Desktop applications document](Desktop%20applications.md)
