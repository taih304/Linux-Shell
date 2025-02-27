# Securing TCP and UDP

Neither **TCP nor UDP** provide any encryption—the data that the sending process passes into its socket is the same data that travels over the network to the destination process. So, for example, if the sending process sends a password in cleartext (i.e., unencrypted) into its socket, the cleartext password will travel over all the links between sender and receiver, potentially getting sniffed and discovered at any of the intervening links.

Because privacy and other security issues have become critical for many applications, the Internet community has developed an enhancement for TCP, called **Secure Sockets Layer (SSL)**. TCP-enhanced-with-SSL not only does everything that traditional TCP does but also provides critical process-to-process security services, including encryption, data integrity, and end-point authentication.

We emphasize that **SSL is not a third Internet transport protocol**, on the same level as TCP and UDP, but instead is an enhancement of TCP, with the enhancements being implemented in the **application layer**. In particular, if an application wants to use the services of SSL, it needs to include SSL code (existing, highly optimized libraries and classes) in both the client and server sides of the application. SSL has its own socket API that is similar to the traditional TCP socket API.

When an application uses SSL, the sending process passes cleartext data to the SSL socket; SSL in the sending host then encrypts the data and passes the encrypted data to the TCP socket. The encrypted data travels over the Internet to the TCP socket in the receiving process. The receiving socket passes the encrypted data to SSL, which decrypts the data. Finally, SSL passes the cleartext data through its SSL socket to the receiving process.

**Transport Layer Security (TLS)**, and its now-deprecated predecessor, **Secure Sockets Layer (SSL)**, are cryptographic protocols designed to provide communications security over a computer network. Both **TLS and SSL lies in the Application layer**.

# SSL/TLS encryption process

* **Step 1**: Client requests a SSL connection
* **Step 2**: Server responses with the SSL certificate (with includes the public key)
* **Step 3**: Client validates the certificate/public key
* **Step 4**: Client generates a symmetric key (session key) and transmit it to the server
* **Step 5**: SSL session is established
