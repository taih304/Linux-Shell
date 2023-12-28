**Greengrass development kit** (**GDK**) is used to develop custom Greengrass components.
# Install Greengrass CLI
Install AWS Greengrass GDK CLI:
```sh
sudo python3 -m pip install -U git+https://github.com/aws-greengrass/aws-greengrass-gdk-cli.git@v1.1.0
```
After installing, ``gdk`` command and ``greengrass.service`` are available. Then proceed to [Set up one Greengrass core device](Shell%20commands%20to%20develop%20components%20locally.md#set-up-one-greengrass-core-device) steps as this will fully setup the Greengrass working environment.

**Uninstall Greengrass**
```sh
sudo systemctl stop greengrass.service
sudo systemctl disable greengrass.service
sudo rm /etc/systemd/system/greengrass.service
sudo systemctl daemon-reload && sudo systemctl reset-failed
sudo rm -rf /greengrass/v2
```
Greengrass also requires [Java](https://github.com/TranPhucVinh/Java).
# Terminologies

**Greengrass core device** is an **AWS IoT thing** which runs the AWS IoT Greengrass Core software on its operating system to process, filter, and aggregate data from **Greengrass client devices** that connect to it. It can be configured to relay MQTT messages between client devices, the AWS IoT Core cloud service, and Greengrass components. **Greengrass core device** can be single-board computer like Raspberry Pi or local Ubuntu PC.

**Greengrass client device** is an AWS IoT thing as a device that connects to and communicates with a Greengrass core device over MQTT. **Greengrass client device** can be a MCU like ESP8266, ESP32.

**AWS IoT thing group** is a group of Greengrass core devices which helps create and manage Greengrass multiple core devices.
# Greengrass component
**Greengrass component**: A component is a software module that runs on AWS IoT Greengrass core devices. A Greengrass component can runs locally on a core devices and be deploy to Greengrass.

**Greengrass nucleus component** (**aws.greengrass.Nucleus**) is a **mandatory** and **built-in component** and the **minimum requirement to run the AWS IoT Greengrass Core software on a device**. You can configure this component to customize and update your AWS IoT Greengrass Core software remotely. Deploy this component to configure settings such as proxy, device role, and AWS IoT thing configuration on your core devices. The Greengrass nucleus component facilitates communication between AWS IoT Greengrass components locally on an individual device. 

**Greengrass CLI component** (**aws.greengrass.Cli**) is a **built-in component** which provides a local command-line interface that you can use on core devices to develop and debug components locally.

**Recipes**: Every component contains a recipe file, which defines its metadata. The recipe also specifies the component's configuration parameters, component dependencies, lifecycle, and platform compatibility. The component lifecycle defines the commands that install, run, and shut down the component. Recipes are define in JSON or YAML format.

In component recipe file, e.g [gg_core_device_component.json](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/AWS/Greengrass/Components%20with%20shell%20commands.md#develop-a-local-python-component-then-deploy-to-aws), those are fields:

* ``Lifecycle``: An object or string that defines how to install and run the component on the platform that this manifest defines
* ``run`` (inside ``Lifecycle``): An object or string that defines the script to run when the component starts.

**Artifacts**: Components can have any number of artifacts, which are component binaries. Artifacts can include scripts, source code, compiled code/binaries, static resources, and any other files that a component consumes. Components can also consume artifacts from component dependencies.

## Implement Greengrass components

* Shell commands to deploy components on AWS to core device
* Shell commands to develop components locally
* C source code component

Components can also be build and publish with [GDK CLI](Components%20with%20GDK%20CLI.md).

**Communication locally between Greengrass components** use **AWS GG IPC**, refer to its [implementation on CPP](https://github.com/TranPhucVinh/Cplusplus/tree/master/Application%20layer/AWS%20Greengrass%20IPC)

**Communication between Greengrass components on different core devices via Internet** use **AWS GG MQTT**, refer to its [implementation on CPP](https://github.com/TranPhucVinh/Cplusplus/tree/master/Application%20layer/AWS%20Greengrass%20MQTT) and [Python](https://github.com/TranPhucVinh/Python/tree/master/Application%20layer/AWS%20Greengrass%20MQTT).
