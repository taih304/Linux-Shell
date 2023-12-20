# Set up one Greengrass core device
**Step 1**:
Get the **AWS_ACCESS_KEY_ID** and **AWS_SECRET_ACCESS_KEY** of the root account. Those keys will help download and map the Greengrass packages installed on PC to the Greengrass core device on AWS cloud

Example of an AWS_ACCESS_KEY_ID and AWS_SECRET_ACCESS_KEY got from root account:
```sh
export AWS_ACCESS_KEY_ID=AKIASFCSZJ7J7HFXN4Y6
export AWS_SECRET_ACCESS_KEY=wWfe54MYX1NzsdntJ77zW7QPDpMgkaZjDpwLM2kC
```

**Step 2**:
Get to AWS homepage, search for **Greengrass**. On **Getting started** → **Set up devices** → **Set up one core devices**. The whole clear cut tutorial with command to Set up one Greengrass core device is presented here.

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

# Develop a local Python component then deploy to AWS

**Step 1**: Export AWS access keys **AWS_ACCESS_KEY_ID** and **AWS_SECRET_ACCESS_KEY** of the root account. 

**Step 2**: Create ``recipes`` and ``artifacts`` folders:
```sh
username@hostname:~/private_greengrass_core_device$ mkdir {recipes,artifacts}
```
**Step 3**:
Add the component recipes JSON file:
```sh
username@hostname:~/private_greengrass_core_device$ touch recipes/gg_core_device_component.json
```
```json
{
    "RecipeFormatVersion": "2020-01-25",
    "ComponentName": "gg_core_device_component",
    "ComponentVersion": "0.0.1",
    "ComponentDescription": "Greengrass core device test component description",
    "ComponentPublisher": "No one",
    "ComponentConfiguration": {
      "DefaultConfiguration": {
        "Message": "Default config message"
      }
    },
    "Manifests": [
      {
        "Platform": {
          "os": "linux"
        },
        "Lifecycle": {
          "run": "python3 -u {artifacts:path}/main.py"
        }
      }
    ]
  }
```
**RecipeFormatVersion**: RecipeFormatVersion is **a fixed number defined by AWS**, must not change it.

Add component artifacts. You must use the following format for the artifact folder path. Include the component name and version that you specify in the recipe:

```sh
artifacts/componentName/componentVersion/
```
```sh
username@hostname:~/private_greengrass_core_device$ mkdir -p artifacts/gg_core_device_component/0.0.1
```
Then add source code for the component:

```sh
username@hostname:~/private_greengrass_core_device$ nano artifacts/gg_core_device_component/0.0.1/main.py
```
Where ``main.py`` simply print out a string

**Step 4**: Run the following command to locally deploy the component to the AWS IoT Greengrass core
```sh
username@hostname:~/private_greengrass_core_device$ sudo /greengrass/v2/bin/greengrass-cli deployment create --recipeDir $(pwd)/recipes --artifactDir $(pwd)/artifacts --merge "gg_core_device_component=0.0.1"
[sudo] password for username:
Local deployment submitted! Deployment Id: b5c0f11c-e6e5-48f0-8ee0-abb57c0682f3 #Result
```
``--merge``: add or update the component and version that you specify

**Result**: The AWS IoT Greengrass Core software saves stdout from component process to log files in the logs folder. Run the following command to verify that the deploy component runs and prints messages.

```sh
sudo tail -f /greengrass/v2/logs/gg_core_device_component.log
```
If successfully deployed locally, component **gg_core_device_component** will be available on this Greengrass core device as a local component:

![](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Environment/Images/greegrass_local_deploy.png)

**View all deployed components**:
```sh
sudo /greengrass/v2/bin/greengrass-cli component list
```
**Deploy this local component to the core device**: ``deployment.json`` for that deployment:

```json
{
    "targetArn": "arn:aws:iot:ap-southeast-2:275507326469:thing/private_greengrass_core_device", //Get private_greengrass_core_device thing's ARN link
    "deploymentName": "deployment_for_gg_core_device_component",
    "components": {
        "gg_core_device_component": {
            "componentVersion": "0.0.1",
            "configurationUpdate": {
                "reset": []
            }
        }
    }
}
```
```sh
username@hostname:~/wip/gg_cli_components$ aws greengrassv2 create-deployment --region ap-southeast-2 --cli-input-json file://deployment.json
{
    "deploymentId": "4514dd91-8784-4b87-a280-fa5bafd8dd26"
}
```
``get-deployment`` from that ``deploymentId``: ``aws greengrassv2 get-deployment --region ap-southeast-2 --deployment-id 4514dd91-8784-4b87-a280-fa5bafd8dd26``

**Remove a deployed component**: ``sudo /greengrass/v2/bin/greengrass-cli deployment create --remove="gg_core_device_component"``
