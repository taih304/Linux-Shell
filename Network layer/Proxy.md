# Forward proxy

A **proxy server** - also called **a Web cache** or **forward proxy** - is a network entity that satisfies HTTP requests on the behalf of an origin Web server. The Web cache has its own disk storage and keeps copies of recently requested objects in this storage. A user’s browser can be configured so that all of the user’s HTTP requests are first directed to the Web cache.

## How it works ?

As an example, suppose a browser is requesting the object ``http://www.someschool.edu/campus.gif``. Here is what happens:

1. The browser establishes a TCP connection to the Web cache and sends an HTTP request for the object to the Web cache/proxy.
2. The Web cache/proxy checks to see if it has a copy of the object stored locally. If it does, the Web cache returns the object within an HTTP response message to the client browser.
3. If the Web cache does not have the object, the Web cache opens a TCP connection to the origin server, that is, to www.someschool.edu. The Web cache then sends an HTTP request for the object into the cache-to-server TCP connection. After receiving this request, the origin server sends the object within an HTTP response to the Web cache.
4. When the Web cache receives the object, it stores a copy in its local storage and sends a copy, within an HTTP response message, to the client browser (over the existing TCP connection between the client browser and the Web cache).

Note that **a proxy is both a server and a client at the same time**. When it receives requests from and sends responses to a browser, it is a server. When it sends requests to and receives responses from an origin server, it is a client.

The forward proxy/web cache is deployed in the client side computer network:

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/forward_proxy.png)

Forward proxy has seen deployment in the Internet for **two reasons**:
* **Reduce the response time for a client request**, Web caches can substantially **reduce traffic on an institution’s access link to the Internet**. By reducing traffic, the institution (for example, a company or a university) does not have to upgrade bandwidth as quickly, thereby reducing costs.
* **Reduce Web traffic in the Internet as a whole**, thereby improving performance for all applications.

