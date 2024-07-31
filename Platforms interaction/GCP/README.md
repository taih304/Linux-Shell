# [Platform as a service](Platform%20as%20a%20service.md)
* App Engine
* [Cloud Run]()
* [Cloud Function]()
* Firebase
* [Google Apps Script]()

**Serverless computing** is a cloud computing execution model in which **the cloud provider allocates machine resources on demand**, taking care of the servers on behalf of their customers. Businesses provide code for the function they want to run and the cloud provider handles all infrastructure management. Resources such as computing power are automatically provisioned behind the scenes as needed.

**Serverless computing**, also known as **Function as a service**, are managed VMs running managed containers.

**App Engine**, **Cloud Functions** and **Cloud Run** are all **Serverless computing**.

**Anthos** is a **managed application platform** that allows organization to build an application once and **run it anywhere**, across **on-premises data centers** and **multiple public clouds**. Anthos enables you to run **Kubernetes clusters** anywhere, in both cloud and on-premises environments.

Anthos is the core enterprise technology that empowers Google Kubernetes Engine (GKE) and Google Distributed Cloud (GDC). (edited) 

For AWS, Anthos clusters on AWS (GKE on AWS) lets you manage GKE clusters running on AWS infrastructure through the Anthos Multi-Cloud API.

# Software as a service
## Google drive
**Connect Ubuntu PC to Google drive**

**Step 1**: Open ``Online Accounts`` application. Choose **Google**

**Step 2**: Enter username and password. When implementing in 20th March 2022, there is error [Sign in with Google temporarily disabled for this app](https://askubuntu.com/questions/1164372/sign-in-with-google-temporarily-disabled-for-this-app#). This error is global and can't be fixed even when Turn on less secure apps in Google account settings.
# Storage services
**Storage Transfer Service** or **Cloud Storage Transfer Service**: Transfer data between cloud storage services such as AWS S3 and Cloud Storage. Example: An organization has large amounts of data residing on Amazon S3 and they want to migrate that data into Google Cloud so they can visualization it using Looker. They have to use **Storage Transfer Service**.

# AI services of GCP

**TensorFlow**: An end-to-end open source platform for machine learning with a comprehensive, flexible ecosystem of tools, libraries and community resources, originally created by Google.

**Vertex AI**: A unified platform for building end-to-end ML solutions which helps build, deploy, and scale ML models faster, with pre-trained and custom tooling within a unified artificial intelligence.

**Vision API**:
* Offers powerful pre-trained machine learning models through **REST** and **RPC APIs**.
* **Detect objects** and **faces**, **read printed** and **handwritten text**, and build valuable metadata into your image catalog. E.g **Vision product search** - **Find products of interest within images and visually search product catalogs using Vision API**

**AutoML**/**AutoML Vision**:
* Easily train high-quality, custom **ML models**
* You upload your data, choose what you want to predict and it does the rest

**AutoML Vision**: Automate the training of your own custom machine learning models. Simply upload images and train custom image models with AutoML Vision’s easy-to-use graphical interface; optimize your models for accuracy, latency, and size; and export them to your application in the cloud or to an array of devices at the edge. 

**AutoML Tables**: Build and deploy machine learning models on structured data.

**Dataprep by Trifacta**: An intelligent cloud data service to visually explore, clean, and prepare data for analysis and machine learning.

Refer to [GCP database services](https://github.com/TranPhucVinh/Node.js/tree/master/Platforms%20interaction/Database#database-services-of-gcp) for GCP data analytical specific databases services.
