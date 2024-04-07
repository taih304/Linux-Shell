# Hostname

Hostnames can be like ``cnn.com``, ``www.yahoo.com``, ``gaia.cs.umass.edu``, and ``cis.poly.edu``.

On the Internet, a **hostname** is a domain name assigned to a host computer. This is usually a combination of the host's local name with its parent domain's name. For example, ``en.wikipedia.org`` consists of a local hostname (en) and the domain name wikipedia.org.

Furthermore, because hostnames can consist of variable-length alphanumeric characters, they would be difficult to process by routers. For these reasons, hosts are also **identified** by so-called **IP addresses**.

To translate IP to hostname, we need DNS. The **DNS protocol** runs over UDP and uses port 53.

# How DNS works

DNS is commonly employed by other application-layer protocols—including **HTTP, SMTP, and FTP**—to translate user-supplied hostnames to IP addresses. As an example, consider what happens when a browser (that is, an HTTP client), running on some user’s host, requests the URL **www.someschool.edu/index.html**. In order for the user’s host to be able to send an HTTP request message to the Web server www.someschool.edu, the user’s host must first obtain the IP address of www.someschool.edu. This is done as follows.

1. The same user machine runs the client side of the DNS application.
2. The browser extracts the hostname, www.someschool.edu, from the URL and passes the hostname to the client side of the DNS application.
3. The DNS client sends a query containing the hostname to a DNS server.
4. The DNS client eventually receives a reply, which includes the IP address for the hostname.
5. Once the browser receives the IP address from DNS, it can initiate a TCP connection to the HTTP server process located at port 80 at that IP address.

# DNS configuration file

The **resolv.conf** file is a configuration file used by the Domain Name System (DNS) resolver in Unix-like operating systems, including Linux distributions. It is used to configure the DNS resolver library (**libresolv**) with information about the DNS servers to use and various DNS-related options.

File ``/etc/resolv.conf`` on Ubuntu 18.04 simply includes:
```sh
nameserver 127.0.0.53 # Along with other comments in the script
```
The IP address **127.0.0.53** is a loopback address, specifically assigned to the systemd-resolved DNS resolver service in some Linux distributions. 

**127.0.0.53** is used as the local DNS resolver address in Ubuntu systems running systemd-resolved. When a program on the system requests DNS resolution, it sends its DNS queries to this local address. systemd-resolved then handles the DNS resolution requests and forwards them to the appropriate DNS servers configured in **/etc/resolv.conf**.

# mDNS

DNS works great for normal sites on the Internet, but most local networks don't have their own DNS server. This means that you can't reach local devices using a domain name, and you're stuck using IP addresses ...

Fortunately, there's another way: multicast DNS, or mDNS.

**mDNS** uses domain names with the ``.local`` suffix, for example ``http://esp8266.local``. If your computer needs to send a request to a domain name that ends in ``.local``, it will send a multicast query to all other devices on the LAN that support mDNS, asking the device with that specific domain name to identify itself. The device with the right name will then respond with another multicast and send its IP address. Now that your computer knows the IP address of the device, it can send normal requests.