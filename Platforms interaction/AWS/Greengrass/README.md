**Greengrass development kit** (**GDK**) is used to develop custom Greengrass components.
# Install Greengrass CLI
Install AWS Greengrass GDK CLI:
```sh
sudo python3 -m pip install -U git+https://github.com/aws-greengrass/aws-greengrass-gdk-cli.git@v1.1.0
```
After installing, ``gdk`` command is available.
Uninstall Greengrass
```sh
sudo systemctl stop greengrass.service
sudo systemctl disable greengrass.service
sudo rm /etc/systemd/system/greengrass.service
sudo systemctl daemon-reload && sudo systemctl reset-failed
sudo rm -rf /greengrass/v2
```
# Terminologies

**Greengrass core device** is an **AWS IoT thing** which runs the AWS IoT Greengrass Core software on its operating system to process, filter, and aggregate data from **Greengrass client devices** that connect to it. It can be configured to relay MQTT messages between client devices, the AWS IoT Core cloud service, and Greengrass components. **Greengrass core device** can be single-board computer like Raspberry Pi or local Ubuntu PC.

**Greengrass client device** is an AWS IoT thing as a device that connects to and communicates with a Greengrass core device over MQTT. **Greengrass client device** can be a MCU like ESP8266, ESP32.

**Greengrass component**: A component is a software module that runs on AWS IoT Greengrass core devices. A Greengrass component can be deployed to single or multiple core devices.

**Recipes**: Every component contains a recipe file, which defines its metadata. The recipe also specifies the component's configuration parameters, component dependencies, lifecycle, and platform compatibility. The component lifecycle defines the commands that install, run, and shut down the component. Recipes are define in JSON or YAML format.

**Artifacts**: Components can have any number of artifacts, which are component binaries. Artifacts can include scripts, source code, compiled code/binaries, static resources, and any other files that a component consumes. Components can also consume artifacts from component dependencies.

**AWS IoT thing group** is a group of Greengrass core devices which helps create and manage Greengrass multiple core devices.
