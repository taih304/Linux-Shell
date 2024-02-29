# Freestyle project

[Freestyle projects on local Jenkins](https://www.youtube.com/watch?v=kFhf_MNS_d8)

* **Project: Simple Bash script**: Run a build for a simple bash script to print out a string
* **Project: GCC test**: Run a build to build a [GCC HTTP server](https://github.com/TranPhucVinh/C/blob/master/Application%20layer/HTTP%20server/simple_http_server.c) source code. 1st build fails as there is no GCC HTTP server source code inside the project folder, 2nd build passes and results in ``a.out`` file. Download that file then run it as the HTTP server.
# Pipeline
## Pipeline script
To setup a Pipeline: **New item** -> **Pipeline** -> **Advanced Project Options** -> **Pipeline**. In **Definition**, choose **Pipeline script**.

Take this script to print out a string when building that pipeline and run shell command pwd:

```groovy
pipeline {
    agent any
    stages {
        stage("test_pipeline"){
            steps{
                echo "Test pipeline"
                sh "pwd"
            }
        }
    }
}
```
``pwd`` will return ``/var/lib/jenkins/workspace/<pipeline_name>``
## Pipeline script with SCM
To call a local Github repo: 

**Step 1**: Allow Jenkins to call local Github repo

Edit ``/lib/systemd/system/jenkins.service`` file, add ``-Dhudson.plugins.git.GitSCM.ALLOW_LOCAL_CHECKOUT=true`` to **Arguments for the Jenkins JVM**, the whole **Environments** variable will be:

```sh
Environment="JAVA_OPTS=-Djava.awt.headless=true -Dhudson.plugins.git.GitSCM.ALLOW_LOCAL_CHECKOUT=true"
```

**Step 2**: In Repository URL, use path ``file:///<path_of_the_local_git_repository>``, e.g ``file:///home/username/github_repository``
