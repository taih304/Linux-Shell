After having the [component developed locally](Shell%20commands%20to%20develop%20components%20locally.md), we have to create this same component on AWS Cloud, as the local component digital twin, so that this cloud component can be deployed to the core device.

# Create a component on AWS 

Create an S3 bucket on AWS cloud. Then upload the artifact folder (which includes source codes) of the [locally developed component on PC](Shell%20commands%20to%20develop%20components%20locally.md) to this newly created S3 bucket.

Then in the AWS IoT console, go to **Manage** -> **Greengrass devices** -> **Components** -> **Create components**. In **Component information**, for **Enter recipe as JSON** (choose recipe as a JSON file), copy the whole recipe JSON file from the [locally developed component](Shell%20commands%20to%20develop%20components%20locally.md).
 

# Deploy the cloud component back to core device 

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
