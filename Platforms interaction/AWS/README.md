# Create an AWS EC2 instance

Afet logging as a root user, head to **Build a solution** then choose **Launch a virtual machine** (with EC2). In order to use Ubuntu package like **apt-get**, choose **Ubuntu** as **Application and OS Images**. If choosing **AWS Linux**, **apt-get** won't be available but just only **yum** instead. Then follow all steps in the tutorial. For large application like ThingsBoard, choose **m3 medium**

For the security setup to access by SSH, if choosing RSA key, a **.pem** key (for use with OpenSSH), e.g **ubuntu_rsa_key.pem**, will be created. After finishing security setup, simply launch EC2 instance/the virual machine.

For SSH access from PC to that newly created EC2 instance with the RSA key, must change mode of the key to **400**: ``chmod 400 ubuntu_rsa_key.pem``. Other modes like 777 are not acceptable which cause the EC2 isntance to refuse the connection.

Then SSH to the EC2 instance with that RSA key:

```sh
ssh -i "ubuntu_rsa_key.pem" ubuntu@ec2-18-212-189-52.compute-1.amazonaws.com
```
# Port forwarding an HTTP server hosted on local PC to an EC2 domain
We will port forward an [HTTP server host on local PC](https://github.com/TranPhucVinh/C/blob/master/Application%20layer/HTTP%20server/multithread_http_server.c), port 8000 to EC2 domain ``ec2-18-212-189-52.compute-1.amazonaws.com``

```sh
ssh -i ubuntu_rsa_key.pem -R 1234:localhost:8000 ubuntu@ec2-18-212-189-52.compute-1.amazonaws.com
```
This will forward your local traffic on localhost, port 8000 to the EC2 domain ec2-18-212-189-52.compute-1.amazonaws.com. After running this command, you have accessed to the CLI of this EC2 successfully, with port ``1234`` is opened:

```sh
ubuntu@ip-172-31-91-123:~$ ss -ltun
Netid               State                Recv-Q                Send-Q                                    Local Address:Port                                Peer Address:Port               Process
tcp                 LISTEN               0                     128                                               [::1]:1234                                        [::]:*
```
Then run [socat](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Network%20layer/README.md#nat) to port forward from port 1234 of EC2 to the specified port, e.g ``9090`` in this case:
```sh
ubuntu@ip-172-31-91-123:~$ socat tcp-listen:9090,reuseaddr,fork tcp:localhost:1234
```
Then the webpage hosted by this [HTTP server](https://github.com/TranPhucVinh/C/blob/master/Application%20layer/HTTP%20server/multithread_http_server.c) can be viewed on ``ec2-18-212-189-52.compute-1.amazonaws.com:9090``.
# Install ThingsBoard on AWS E2C instance

After [creating an AWS EC2 instance](#create-an-aws-ec2-instance) (choose Ubuntu image) and SSH to this instance, follow all [ThingsBoard installation step on Raspberry Pi](https://github.com/TranPhucVinh/Raspberry-Pi-GNU/blob/main/Platforms%20interaction/ThingsBoard.md) as those installation steps are identical on AWS E2C Ubuntu image

**Note**: Current used password for PostgreSQL is ubuntuaws

After successfully install, check the opened ports by ``ss -ltun``, port 8080 and 1883 must be opened

Then peform port forwarding from localhost port 8080 (ThingsBoard) to port 9090 to be access on web browser:

```sh
socat tcp-listen:9090,reuseaddr,fork tcp:localhost:8080
```
After this step, ThingsBoard still can't be accessed. We must allow several ports to be accessible on the EC2, known as **Inbound rules**

On the Instance webpage like below, click on **Security groups**, then choose **Edit inbound rules** to start adding or editing the inbound rules. For ThingsBoard, we need ports 80, 1883, 443, (SSH port 22 is default) and the HTTP port to webpage access, in this case based on previous socat setup is 9090.

Finally, we will have the Inbound rules like below:

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/inbound_rules_security_groups.jpg)

Then access to this ThingsBoard webpage on port 9090, if the public IPv4 DNS is ``ec2-18-212-189-52.compute-1.amazonaws.com``, then the access link will be: ``http://ec2-18-212-189-52.compute-1.amazonaws.com:9090/``

After turning off the socat command run above, the ThingsBoard webpage will then go offline
