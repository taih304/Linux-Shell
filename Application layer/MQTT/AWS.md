The MQTT broker hostname for AWS IoT typically follows the pattern: ``<endpoint>.iot.<region>.amazonaws.com``, which is known as the ``endpoint``.,

In order to get that hostname, go the **IoT Core** -> **MQTT test client** -> **Connection details**. The **endpoint** will be like ``a2llk1hj3zrb56-ats.iot.us-east-1.amazonaws.com``.

AWS IoT MQTT broker uses TLS/SSL which runs on port 8883. In order for an MQTT client to publish/subscribe to it, there are 2 options: 
* X.509 certificate
* AWS Signature Version 4 (SigV4) with IAM credentials (access key, secret key, and session token) 

With X.509, the following are needed:
* CA file, e.g AmazonRootCA1.pem
* certifcate, e.g *-certificate.pem.crt 
* Private key, e.g *-private.pem.key

To achieve those, a new AWS certificate is needed to be created as creating a new certificate gives developer a unique chance to download all those certificates and keys. Beside that, the newly created certificate must have those 2 policies which allow MQTT communications:
* 	GreengrassV2IoTThingPolicy
* 	GreengrassTESCertificatePolicyGreengrassCoreTokenExchangeRoleAlias

In order to add those policies to the newly certificated, the AWS account must be **root**. 

To create a new certificate: **AWS IoT** -> **Security** -> **Certificates** -> **Add certificate** -> **Auto-generate new certificate (recommended)** and **Active**. After pressing **Create**, download all CA files (AmazonRootCA1.pem, AmazonRootCA3.pem), certificate (*-certificate.pem.crt), public and private keys (``*-public.pem.key`` and ``*-private.pem.key``).
