# Install and setup
Download long term support release
```sh
curl -fsSL https://pkg.jenkins.io/debian-stable/jenkins.io-2023.key | sudo tee \
  /usr/share/keyrings/jenkins-keyring.asc > /dev/null
echo deb [signed-by=/usr/share/keyrings/jenkins-keyring.asc] \
  https://pkg.jenkins.io/debian-stable binary/ | sudo tee \
  /etc/apt/sources.list.d/jenkins.list > /dev/null
sudo apt-get update
sudo apt-get install jenkins
```
# Installation of Java
Jenkins requires Java in order to run:
```sh
sudo apt update
sudo apt install openjdk-17-jre
```
``java -version`` will return
```
openjdk version "17.0.8" 2023-07-18
OpenJDK Runtime Environment (build 17.0.8+7-Ubuntu-120.04.2)
OpenJDK 64-Bit Server VM (build 17.0.8+7-Ubuntu-120.04.2, mixed mode, sharing)
```
# Start Jenkins

Enable the Jenkins service to start at boot:
```sh
sudo systemctl enable jenkins
```

You can start the Jenkins service with the command:

```sh
sudo systemctl start jenkins
```
You can check the status of the Jenkins service using the command:
```sh
sudo systemctl status jenkins
```
After successfully installing, go to ``localhost:8080`` on web browser. The **Getting Started**, **Unlock Jenkins** window is poped out:
![](../../Environment/Images/jenkins_1st_time_run_password.png)
Go to ``/var/lib/jenkins/secrets/initialAdminPassword`` to get the administrator password for this.

In Customize Jenkins, choose **Install suggested plugins**. Jenkins will then automatically install all suggested plugins.
# Environment setup
For Jenkins to run docker, add user jenkins to docker group: ``sudo usermod -a -G docker jenkins`` then restarts Jenkins service.

After installing, Jenkins is a new Linux account in your Linux PC as it can't access most of the resources lies on the $(USER) PC. By default, you won't be able to install any new package for that Jenkins account as error:

**jenkins is not in the sudoers file. This incident will be reported**

To solve that, add user jenkins to sudo group: **sudo usermod -aG sudo jenkins** then reboot the PC.

# Terminology
A **CI/CD pipeline** is a deployment pipeline integrated with automation tools.
