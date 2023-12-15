# Build and publish Greengrass component by gdk commands

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
# Publish a component with recipe.json

After calling ``gdk component init`` for the new component initialization, replace file ``recipe.yaml`` by ``recipe.json``. Use any online tool to convert the existed ``recipe.yaml`` file into ``recipe.json`` file.

File ``new_recipe_json_component`` for component ``new_recipe_json_component``:
```json
{
	"RecipeFormatVersion": "2020-01-25",
	"ComponentName": "{COMPONENT_NAME}",
	"ComponentVersion": "{COMPONENT_VERSION}",
	"ComponentDescription": "This is simple Hello World component written in Python.",
	"ComponentPublisher": "{COMPONENT_AUTHOR}",
	"ComponentConfiguration": {
		"DefaultConfiguration": {
		"Message": null
		}
	},
  	"Manifests": [
		{
			"Platform": {
				"os": "all"
			},
			"Artifacts": [
				{
				"URI": "s3://recipe-json-bucket/new_recipe_json_component/0.0.1/new_recipe_json_component.zip",
				"Unarchive": "ZIP"
				}
			],
			"Lifecycle": {
				"Run": "python3 -u {artifacts:decompressedPath}/new_recipe_json_component/main.py"
			}
		}
	]
}
```
``gdk-config.json`` for bucket ``recipe-json-bucket``
```json
{
  "component": {
    "new_recipe_json_component": {
      "author": "AUTHOR",
      "version": "NEXT_PATCH",
      "build": {
        "build_system": "zip",
        "options": {
          "zip_name": ""
        }
      },
      "publish": {
        "bucket": "recipe-json-bucket",
        "region": "ap-southeast-1"
      }
    }
  },
  "gdk_version": "1.3.0"
}
```
Then perform other steps like with ``recipe.yaml`` file.
