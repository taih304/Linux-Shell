# Overview

**An application-layer protocol** defines how an application’s processes, running on different end systems, pass messages to each other.

An application-layer protocol is distributed over multiple end systems, with the application in one end system using the protocol to exchange packets of information with the application in another end system. We’ll refer to this packet of information at the application layer as a message.

Let’s look at an example. **The Web** is a client-server application that allows users to obtain documents from Web servers on demand. The Web application consists of many components, including a standard for document formats (that is, HTML), Web browsers (for example, Firefox and Microsoft Internet Explorer), **Web servers** (for example, Apache and Microsoft servers), and an application-layer protocol.

The communication of applications/programs in multiple PCs or inside a single one, based on **their processes**. A **process** sends or receives messages through a software interface called a **socket**.

In addition to knowing the address of the host to which a message is destined, **the sending process must also identify the receiving process (more specifically, the receiving socket) running in the host**. This information is needed because in general a host could be running many network applications. **A destination port number** serves this purpose. Popular applications have been assigned specific port numbers. For example, a **Web server** is identified by port number 80. A mail server process (using the **SMTP** protocol) is identified by port number 25.

**Application layer protocol message** is a phrase indicating a **message formatted** according to the rules of an application layer protocol.

**Directory service**: a directory service or name service maps the names of network resources to their respective network addresses. A directory server or name server is a server that provides such a service. **Domain Name System** (**DNS**) is the first directory service on the Internet.

**VPS**, which stands for **virtual private server**, is a virtual machine sold as a service by an Internet hosting service.

A 16-bit computer means this computer can open up to 65536 port.

Types of server:
* Web server
* Apps server
* Mail server, FTP server
* [Proxy server](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Network%20layer/Proxy.md#forward-proxy)
* Telnet server
* IRC server

## Temporary URL 
A **temporary URL** can be **used when your domain name is not working**.
# [Mail protocols](Mail%20protocols.md)
* [FTP]()
* [SMTP]() and [web-based e-mail]()
# Wget

``Wget`` is a free software package for retrieving files using [HTTP](HTTP), HTTPS, FTP and FTPS.
# TFTP
Install TFTP server ``sudo apt install tftpd-hpa``. Just only when having FTP server, UDP port 69 will be available for it.

All TFTP server config are defined in ``/etc/default/tftpd-hpa``. All files for TFTP transfering are stored inside ``/var/lib/tftpboot``, users can change that to another location. In ``TFTP_OPTIONS``, add ``--create`` option to create or upload new files to the TFTP server.

```sh
TFTP_USERNAME="tftp"
TFTP_DIRECTORY="/var/lib/tftpboot"
TFTP_ADDRESS=":69"
TFTP_OPTIONS="--secure --create"
```

With those configuration, simply put for for transfering into the ``TFTP_DIRECTORY``. The TFTP client will then be able to get that file.

# [Desktop applications and GUI](GUI.md)
# Free software
**Free software** or **libre software** or **libreware** is computer software distributed under terms that allow users to run the software for any purpose as well as to study, change, and distribute it and any adapted versions. Free software is a matter of liberty, not price; all users are legally free to do what they want with their copies of a free software (including profiting from them) regardless of how much is paid to obtain the program.

Be not to confuse free software with [freeware](#freeware).
# Freeware
Freeware is software, most often proprietary, that is distributed at no monetary cost to the end user. There is no agreed-upon set of rights, license, or **EULA** (**End-user license agreement**) that defines freeware unambiguously; every publisher defines its own rules for the freeware it offers. For instance, modification, redistribution by third parties, and reverse engineering are permitted by some publishers but prohibited by others. Unlike with free and open-source software, which are also often distributed free of charge, the source code for freeware is typically not made available.
