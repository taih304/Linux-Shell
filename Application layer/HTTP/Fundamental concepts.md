# Implementations of HTTP
**HTTP** is implemented in two programs: a **client** program and a **server** program.

The client program and server program, executing on different end systems, talk to each other by exchanging HTTP messages. HTTP defines the structure of these messages and how the client and server exchange the messages.

**Web servers**, which implement the server side of HTTP, house Web objects, each addressable by a URL. Popular Web servers include **Apache** and **Microsoft Internet Information Server**.

**HTTP** uses **TCP** as its underlying transport protocol (rather than running on top of **UDP**). The HTTP client first initiates a TCP connection with the server. Once the connection is established, the browser and the server processes access TCP through their socket interfaces. However, **HTTP** can be adapted to use unreliable protocols such as the **UDP**, for example in **HTTPU** and **Simple Service Discovery Protocol** (**SSDP**).

**On the client side**, **the socket interface** is the door between the **client process** and the **TCP connection**; on the server side it is the door between the **server process** and the **TCP connection**.

It is important to note that the server sends requested files to clients without storing any state information about the client. **If a particular client asks for the same object twice in a period of a few seconds, the server does not respond by saying that it just served the object to the client; instead, the server resends the object, as it has completely forgotten what it did earlier**. Because an HTTP server maintains no information about the clients, HTTP is said to be a **stateless** protocol. We also remark that the Web uses the client-server application architecture. **A Web server is always on**, with a **fixed IP address**, and it services requests from potentially millions of different browsers.

# HTTP with Non-Persistent Connections

Every request for a HTML file include: time to initiate TCP connection (RTT), time to request a file (RTT), time to send back a file

``total time for a html file = 2RTT + time transmit a file``

``n file html file (abc.html, abc.jpg,...) = n x total time for a html file``

# HTTP with Persistent Connections

With persistent connections, the server **leaves the TCP connection open** after sending a response. Subsequent requests and responses between the same client and server **can be sent over the same connection**. In particular, **an entire Web page** (in the example above, the base HTML file and the 10 images) can be sent over a single persistent TCP connection.

Moreover, multiple Web pages residing on the same server **can be sent from the server to the same client over a single persistent TCP connection**. These requests for objects can be made back-to-back, without waiting for replies to pending requests (pipelining). Typically, the HTTP server closes a connection when it isn’t used for a certain time (a configurable timeout interval). 

When the server receives the back-to-back requests, it sends the objects back-to-back. **The default mode of HTTP uses persistent connections with pipelining**.

# HTTP Message Format

```
GET /somedir/page.html HTTP/1.1
Host: www.someschool.edu
Connection: close
User-agent: Mozilla/5.0
Accept-language: fr
```

We would be remiss if we didn’t mention that **a request generated with a form does not necessarily use the POST method**. Instead, HTML forms often use the GET method and include the inputted data (in the form fields) in the requested URL.

**For example, if a form uses the GET method, has two fields, and the inputs to the two fields are monkeys and bananas, then the URL will have the structure www.somesite.com/animalsearch?monkeys&bananas**. In your day-to-day Web surfing, you have probably noticed extended URLs of this sort.

# Cookie

Cookies, defined in [RFC 6265], allow sites to keep track of users.

cookie technology has **four components**: (1) a cookie header line in the HTTP response message; (2) a cookie header line in the HTTP request message; (3) a cookie file kept on the user’s end system and managed by the user’s browser; and (4) a back-end database at the Web site.

# Web cache

**A Web cache** - also called **a proxy server** or **forward proxy** - is a network entity that satisfies HTTP requests on the behalf of an origin Web server. The Web cache has its own disk storage and keeps copies of recently requested objects in this storage. A user’s browser can be configured so that all of the user’s HTTP requests are first directed to the Web cache.

## How it works ?

As an example, suppose a browser is requesting the object ``http://www.someschool.edu/campus.gif``. Here is what happens:

1. The browser establishes a TCP connection to the Web cache and sends an HTTP request for the object to the Web cache.
2. The Web cache checks to see if it has a copy of the object stored locally. If it does, the Web cache returns the object within an HTTP response message to the client browser.
3. If the Web cache does not have the object, the Web cache opens a TCP connection to the origin server, that is, to www.someschool.edu. The Web cache then sends an HTTP request for the object into the cache-to-server TCP connection. After receiving this request, the origin server sends the object within an HTTP response to the Web cache.
4. When the Web cache receives the object, it stores a copy in its local storage and sends a copy, within an HTTP response message, to the client browser (over the existing TCP connection between the client browser and the Web cache).

Note that **a cache is both a server and a client at the same time**. When it receives requests from and sends responses to a browser, it is a server. When it sends requests to and receives responses from an origin server, it is a client.

Web caching has seen deployment in the Internet for **two reasons**:
* **Reduce the response time for a client request**, Web caches can substantially **reduce traffic on an institution’s access link to the Internet**. By reducing traffic, the institution (for example, a company or a university) does not have to upgrade bandwidth as quickly, thereby reducing costs.
* **Reduce Web traffic in the Internet as a whole**, thereby improving performance for all applications.

# REST

REST is a representational state transfer architectural style designed as a request/response model that communicates over HTTP. 

**When to use REST, instead [MQTT](../MQTT/) ?**

In these scenarios, it is useful to use REST calls to update or retrieve data from a HTTP server:

* You need to retrieve any historical data, such as data within a defined time range.
* You want to perform Create, Read, Update and Delete on the database
* You need a response for your GET or POST request.
