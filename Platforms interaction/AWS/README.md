# AWS account creation

## Root user

Signin with username, password then enter MFA password. Get the MFA password from any authenticator mobile app which is previously setup to be mapped to your account, like Microsoft Authenticator. **Getting the password from this app doesn't require Internet connection**.

## IAM user

**Identity and Access Management** (**IAM**) lets administrators authorize who can take action on specific resources, giving you full control and visibility to manage AWS and Google Cloud resources centrally. An Identity Access Management policy, or **IAM policy**, is made of three parts: “Who”, “can do what”, and “on which resource”.

After you create an AWS accout, this is treated as a root account. This root account will then automatically have a 12-digit account ID along with a Sign-in URL for IAM users in this account. As the name infered, this sign-in URL for IAM users will be used for all IAM users created by this root account to login.

To get this IAM users sign-URL, go to the IAM service. The sign-in URL for IAM users will be: ``<12-digit-account-id>.signin.aws.amazon.com/console``

For example, if the account ID is 148349997011, then the sign-in URL for IAM users will be https://148349997011.signin.aws.amazon.com/console

The next step is to create an IAM user by root account. Still inside the IAM page, in IAM resources, click on the numbers display below **Users**. For the 1st time use root account, there is 0 IAM user.

Reference to video [Create AWS IAM account](https://www.youtube.com/watch?v=l17Ka8jeJ_4) for full implementations.

In order to access AWS API, IAM user must have an access key, which is ACCESS_KEY_ID and secret_access_key. Simply create this access key after creating the IAM user. That key (ACCESS_KEY_ID and secret_access_key) is only able to be viewed and downloaded one time after they're createad.

# AWS services
## AWS CLI
The **AWS Command Line Interface** (**AWS CLI**) is a unified tool to manage your AWS services. With AWS CLI, you can control multiple AWS services from the command line and automate them through scripts.

Install awscli: ``sudo apt install awscli``
## EC2
* [Create an AWS EC2 instance]()
* [Port forwarding an HTTP server hosted on local PC to an EC2 domain]()
* [Install ThingsBoard on AWS E2C instance]()
## Amazon S3
Amazon S3 is a storage service. Stored file are called **object**. All objects are stored inside a **bucket**. Bucket can have folders. In order to store file, user has to create bucket.
