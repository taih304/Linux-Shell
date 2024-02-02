On-premise storage:
* DAS (Direct Attached Storage): Store data by direct attached storage media
* NAS (Network Attached Storage): Store data into storage device by IP network
* SAN (Storage Area Network): Store data by dedicated storage network

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/on_premise_storage.png)

# DAS (Direct attached storage)

* DAS (Direct attached storage) is a storage mechanism with attached storaged device to PC. DAS is a classical storage mechanism used by many enterprises. With DAS, every PC will have a separated storage system and software to manage this storage system.
* DAS is easy to deploy with low-cost and high availability. However DAS is limited to expand. When the data to be stored increase along with the increasement, system will face the risk of defragmentation. System admin will need to reconfigure those storage data, this has to be performed on each server separately. This will increase the cost for the storage system. This will also be difficult for saving and protect the defragmentated storage system.
# NAS (Network Attached Storage)
* NAS (Network Attached Storage) is a storage mechanism with storage devices are attached on LAN network, and is treated as other devices inside the system like a PC, switch or router. NAS devices have fixed IP and can be accessed by other PC inside the LAN network. For security purpose, system admin has to setup access priviledge for the NAS devices, along with username and password, for specific users

NAS advantages:
* Scalability: Easy to attach new NAS devices to the network
* As accessing through LAN network, NAS supports access data when there is error on one host device among the device groups stored the data.

NAS disadvantages:
* As sharing the network infrastructure with other host devices, NAS can slow down the LAN network, especially when the stored data is big
* For database like SQL and NoSQL, NAS is not efficient as those database are stored as block, not file.

# SAN (Storage Area Network)

SAN (Storage Area Network) is a high speed private network dedicated for data transfering between hosts or storage devices inside a storage system. SAN allows centralize control and sharing storage data and resource. Most of nowadays SAN based on optical fiber, which is easy to expand, increase performance and availability.

SAN are divided into 2 level: physcial and logic
* Physical level: refer to the connection inside the SAN network which creates a monolithic system and is available at the same time for multiple users and application
* Logic level: including applications, management tools and services built on "physical level devices" which supports controlling the SAN system.

SAN advantages:
* Able to copy data with big size regularly without affecting the network traffic.
* SAN is suitable for high speed, low-latency applications, like banking, finance applications.
* High availability data.
* Monolithic data storage and centralize. Be able to recover when having issue.
* Support many protocols and storage standards: iSCSI, FCIP, DWDM...
* Able to expand the number of storage devices, storage capacity as well as physical distance.
* Support multiple OS

With those advantages, SAN are mainly used in big data center.

# Comparison between storage solutions
* NAS and SAN both solve the disadvantages of DAS. With NAS and SAN, the storing process is seperated from server and merged into the network which allows a wide range to access for server, users and applications to access and transfer data. Maintaining the system will then be easier, and decreasing system cost. NAS is available for file sharing but is limited in the working environment with databases. Sharing the same network infrastructure with other applications will cause NAS to slow down the network speed and also decrease the system performance.
* SAN solves NAS disadvantages and is best for high speed, low-latency applications. Moreover, SAN is high reliability to change request in the network infrastructure. However, SAN is high cost compared to DAS and NAS. 
