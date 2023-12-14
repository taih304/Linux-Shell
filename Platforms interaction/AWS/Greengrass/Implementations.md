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

# Greengrass components
## Greengrass nucleus component
The Greengrass nucleus component (**aws.greengrass.Nucleus**) is a **mandatory component** and the **minimum requirement to run the AWS IoT Greengrass Core software on a device**. You can configure this component to customize and update your AWS IoT Greengrass Core software remotely. Deploy this component to configure settings such as proxy, device role, and AWS IoT thing configuration on your core devices. The Greengrass nucleus component facilitates communication between AWS IoT Greengrass components locally on an individual device. 
## Develop and test a component locally with Python source code

**Step 1**: Create ``recipes`` and ``artifacts`` folders:
```sh
username@hostname:~/private_greengrass_core_device$ mkdir {recipes,artifacts}
```
**Step 2**:
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

**Step 3**: Run the following command to locally deploy the component to the AWS IoT Greengrass core
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
aws greengrassv2 create-deployment --region ap-southeast-2 --cli-input-json file://deployment.json
```
## Develop and test a component locally with C source code

With main.c inside ``artifacts/gg_core_device_component/0.0.1/main.c``, change ``Lifecycle`` of ``gg_core_device_component.json`` of ``recipes`` to:

```json
"Lifecycle": {
    "run": "gcc {artifacts:path}/main.c && ./a.out"
}
```
**Note**: In ``run``, after ``gcc {artifacts:path}/main.c``, the working directory of this subshell is ``/greengrass/v2/work/gg_core_device_component/`` (not ``{artifacts:path}``) and the built file ``a.out`` is also located inside that location. **a.out doesn't built into {artifacts:path}**
# Build and deploy Greengrass component by gdk commands

At first, export **AWS_ACCESS_KEY_ID** and **AWS_SECRET_ACCESS_KEY** to the current terminal session.

Inisde working folder ``gdk_component``, init a component named ``python_component`` by using the template ``HelloWorld``:

```sh
vinhtran@DESKTOP-34VG5H3:~/wip/gdk_component$ gdk component init --template HelloWorld --language python -n python_component
```
Then folder ``python_component`` will be available:
```sh
vinhtran@DESKTOP-34VG5H3:~/wsl_core_device_vinh/gdk_component$ ls
python_component
```

Inside ``python_component``, specially care for ``main.py``, ``recipe.yaml`` and ``gdk-config.json``.

``main.py``
```py
print("Hello, World !")
```
``gdk-config.json``

```json
{
  "component": {
    "python_component": {
      "author": "AUTHOR_NAME",
      "version": "0.0.1",
      "build": {
        "build_system": "zip"
      },
      "publish": {
        "bucket": "bucket-name",
        "region": "ap-southeast-1"
      }
    }
  },
  "gdk_version": "1.0.0"
}
```
* **Version**: 
  *	The version of the component (in the AWS IoT Greengrass cloud service) to use when the GDK CLI publishes the Greengrass component to the AWS IoT Greengrass cloud service. Must be fixed with the version naming convention.
  *	Default: 1.0.0
  *	``NEXT_PATCH`` specifies to choose the next patch version after the latest version available in the AWS IoT Greengrass cloud service.
* **Region**:	AWS region where your core device operates. The GDK CLI publishes the component in this AWS Region.
* **Bucket**:	Prefix for the S3 bucket where the GDK CLI uploads the component's artifacts.

``recipe.yaml``
```yaml
---
RecipeFormatVersion: "2020-01-25"
ComponentName: "{COMPONENT_NAME}"
ComponentVersion: "{COMPONENT_VERSION}"
ComponentDescription: "This is a simple component written in Python"
ComponentPublisher: "{COMPONENT_AUTHOR}"
ComponentConfiguration:
  DefaultConfiguration:
    Message: NULL
Manifests:
  - Platform:
      os: all
    Artifacts:
      - URI: "s3://bucket-name/python_component/0.0.1/python_component.zip"
        Unarchive: ZIP
    Lifecycle:
      Run: "python3 -u {artifacts:decompressedPath}/python_component/main.py {configuration:/Message}"
```
Then go to the component folder ``python_component`` to build it:

```sh
vinhtran@DESKTOP-34VG5H3:~/wsl_core_device_vinh/gdk_component/python_component$ gdk component build
```
``gdk component build`` will:
* Creates a recipe and artifacts based on the GDK CLI configuration file
* Creates a ZIP file that contains the component's source code
Then publish the component:

```sh
vinhtran@DESKTOP-34VG5H3:~/wsl_core_device_vinh/gdk_component/python_component$ gdk component publish
```

``gdk component publish`` uploads the component's ZIP file artifact to an S3 bucket. Then, it updates the ZIP file's S3 URI in the component recipe and uploads the recipe to the AWS IoT Greengrass service. In this process, the GDK CLI checks what version of the component is already available in the AWS IoT Greengrass cloud service, so it can choose the NEXT_PATCH version after that version. If the component doesn't exist yet, the GDK CLI uses version ``1.0.0``.

If successfully publishing, a new bucket ``bucket-name-ap-southeast-1-148349997011`` is automatically created. The newly created bucket's name follows the AWS naming convention ``{PLACEHOLDER_BUCKET}-{PLACEHOLDER_REGION}-{account_id}``
