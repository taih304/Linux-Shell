# Freestyle project

[Freestyle projects on local Jenkins](https://www.youtube.com/watch?v=kFhf_MNS_d8)

* **Project: Simple Bash script**: Run a build for a simple bash script to print out a string
* **Project: GCC test**: Run a build to build a [GCC HTTP server](https://github.com/TranPhucVinh/C/blob/master/Application%20layer/HTTP%20server/simple_http_server.c) source code. 1st build fails as there is no GCC HTTP server source code inside the project folder, 2nd build passes and results in ``a.out`` file. Download that file then run it as the HTTP server.
# Pipeline

To setup a Pipeline: **New item** -> **Pipeline** -> **Advanced Project Options** -> **Pipeline**. In **Definition**, choose **Pipeline script**.

Take this script to print out a string when building that pipeline:

```groovy
pipeline {
    agent any
    stages {
        stage("test_pipeline"){
            steps{
                echo "Test pipeline"
            }
        }
    }
}
```
