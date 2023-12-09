# Set up one Greengrass core device
**Step 1**:
Get to AWS homepage, search for **Greengrass**. On **Getting started** → **Set up devices** → **Set up one core devices**. The whole clear cut tutorial with command to Set up one Greengrass core device is presented here.

**Step 2**:
Get the **AWS_ACCESS_KEY_ID** and **AWS_SECRET_ACCESS_KEY** of the root account. Those keys will help download and map the Greengrass packages installed on PC to the Greengrass core device on AWS cloud

Example of an AWS_ACCESS_KEY_ID and AWS_SECRET_ACCESS_KEY got from root account:
```sh
export AWS_ACCESS_KEY_ID=AKIASFCSZJ7J7HFXN4Y6
export AWS_SECRET_ACCESS_KEY=wWfe54MYX1NzsdntJ77zW7QPDpMgkaZjDpwLM2kC
```
Name the Greengrass core device, e.g **Greengrass_private_core_device**, For Thing group, choose **No group**.

**Step 3**: Download the installer for AWS IoT Greengrass Core software
```sh
curl -s https://d2s8p88vqu9w66.cloudfront.net/releases/greengrass-nucleus-latest.zip > greengrass-nucleus-latest.zip && unzip greengrass-nucleus-latest.zip -d GreengrassInstaller
```
**Step 4**: Run the installer for AWS IoT Greengrass Core software

```sh
sudo -E java -Droot="/greengrass/v2" -Dlog.store=FILE -jar ./GreengrassInstaller/lib/Greengrass.jar --aws-region us-east-1 --thing-name Greengrass_private_core_device  --component-default-user ggc_user:ggc_group --provision true --setup-system-service true --deploy-dev-tools true
```
The installation process takes a few minutes. When the installer completes, you can find your device in the list of Greengrass core devices on the Core devices page.
