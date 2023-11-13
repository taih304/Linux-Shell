# Create an AWS EC2 instance

Afet logging as a root user, head to **Build a solution** then choose **Launch a virtual machine** (with EC2). In order to use Ubuntu package like **apt-get**, choose **Ubuntu** as **Application and OS Images**. If choosing **AWS Linux**, **apt-get** won't be available but just only **yum** instead. Then follow all steps in the tutorial. For large application like ThingsBoard, choose **m3 medium**

For the security setup to access by SSH, if choosing RSA key, a **.pem** key (for use with OpenSSH), e.g **ubuntu_rsa_key.pem**, will be created. After finishing security setup, simply launch EC2 instance/the virual machine.

For SSH access from PC to that newly created EC2 instance with the RSA key, must change mode of the key to **400**: ``chmod 400 ubuntu_rsa_key.pem``. Other modes like 777 are not acceptable which cause the EC2 isntance to refuse the connection.

Then SSH to the EC2 instance with that RSA key:

```sh
ssh -i "ubuntu_rsa_key.pem" ubuntu@ec2-18-212-189-52.compute-1.amazonaws.com
```
# Install ThingsBoard on AWS E2C instance

After [creating an AWS EC2 instance]() (choose Ubuntu image) and SSH to this instance, follow all [ThingsBoard installation step on Raspberry Pi]() as those installation steps are identical on AWS E2C Ubuntu image

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

Then access to this ThingsBoard webpage on port 9090, if the publicj IPv4 DNS is ``ec2-18-212-189-52.compute-1.amazonaws.com``, then the access link will be: ``http://ec2-18-212-189-52.compute-1.amazonaws.com:9090/``
