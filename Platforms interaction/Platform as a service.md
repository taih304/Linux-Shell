# Heroku
Install: ``sudo snap install heroku``

Main file to run: ``Procfile``

**Example content in Procfile**: ``web: node index.js``

**Heroku CLI**

```sh
$ heroku login
$ heroku git:remote -a control-smart-switch-17032019 #login project
$ heroku run bash #enter CLI
```
# Blynk
Get project

```sh
curl -v blynk-cloud.com/rYt4dTj5QqvSNFRZeS_ccmAm13Dcx-DX/project
```

Get value of virtual pin ``V0``

```sh
curl -v http://blynk-cloud.com/rYt4dTj5QqvSNFRZeS_ccmAm13Dcx-DX/get/V0
```

Get value of digital pin GPIO0

```sh
curl -v http://blynk-cloud.com/rYt4dTj5QqvSNFRZeS_ccmAm13Dcx-DX/get/D0
```

Write value to virtual pin ``V1``

```sh
curl -v http://blynk-cloud.com/rYt4dTj5QqvSNFRZeS_ccmAm13Dcx-DX/update/V1?value=123
```

With ``blynk-server.com``, port ``8080``:

```sh
curl -v blynk-server.com:8080/mx0vpPtvd3BnillekvXj1CzQSFbUnd9o/project
```
# Firebase
Firebase is an alternative to Google Cloud for users who want to focus on building and deploying their applications in a highly opinionated framework.​ It is a separate product that Google Cloud bought in 2014, although it runs on Google Cloud and can be either managed from the Firebase platform OR the Google Cloud Console.

Firebase is Google’s fully-managed platform for rapidly developing and deploying web and mobile applications.​ It is a Platform as a Service utilizing Serverless technology
## Realtime Database

The **Firebase Realtime Database** is a cloud-hosted database. Data is stored as JSON and synchronized in realtime to every connected client.

Read data of ``test.json`` database

```sh
curl 'https://private-cloud-server-227507.firebaseio.com/test.json/?format=export'
```

Send data with PUT to ``test.json`` database
```sh
curl -X PUT -d '{"text": "Hello, World !"}'  https://firstapp-5ae54.firebaseio.com/test.json
```

Send data with POST to ``test.json`` database

```sh
curl -X POST -d '{"string": "display"}' https://private-cloud-server-227507.firebaseio.com/test.json  
```

## Firestore Database
**Firestore** or **Cloud Firestore** is a flexible, scalable database for mobile, web, and server development from Firebase and Google Cloud.  
### Implementations

**Step 1**: Start collection

Start a collection by enter a Collection ID

Rules that require authentication

```js
service cloud.firestore {
  match /databases/{database}/documents {
    match /{document=**} {
      allow read, write: if request.auth != null;
      <!-- allow read, write: if
          request.time < timestamp.date(2021, 7, 9); -->
    }
  }
}
```

Change the rule to allow all HTTP request from HTTP clients:

```js
// rules_version = '2';
service cloud.firestore {
  match /databases/{database}/documents {
    match /{document=**} {
	    allow read, write: if true;
      // allow read, write: if
      //     request.time < timestamp.date(2021, 7, 9);
    }
  }
}
```

**Step 2**: Forming HTTP request with ``v1beta1``

API to gets a single document:

```sh
GET /v1beta1/{name=projects/*/databases/*/documents/*/**}
```

## Implementations

Get all documents data of a project:

```sh
curl -X GET https://firestore.googleapis.com/v1beta1/projects/private-cloud-server-227507/databases/"(default)"/documents/NFC%20LOCK?&key=AIzaSyCAfDD1v8kG3dRVTDH3CPd9gXhhKPaNmy0
```

For data of a specific document, like ``uuid``:

```sh
curl -X GET https://firestore.googleapis.com/v1beta1/projects/private-cloud-server-227507/databases/"(default)"/documents/NFC%20LOCK/uuid?&key=AIzaSyCAfDD1v8kG3dRVTDH3CPd9gXhhKPaNmy0
```

Send data to a document of a project:

```sh
curl -X POST -H "Content-Type: application/json" -d '{"fields": {"Field1": {
"stringValue": "string value for field 1"},"Field2": {"stringValue": "string value for field 2"},"Field3": {
"stringValue": "string value for field 3"}}}' https://firestore.googleapis.com/v1beta1/projects/{project_name}/databases/"(default)"/documents/{document_name}?&key={Web_API_Key}
```

``{}`` is used for querying.

``Web_API_Key`` get from ``Project settings`` -> ``Web API Key``

```sh
curl -X POST -H "Content-Type: application/json" -d '{"fields": {"Field1": {"stringValue": "string value 1"},"Field2": {"stringValue": "string value 2"},"Field3": {
"stringValue": "string value 3"}}}' https://firestore.googleapis.com/v1beta1/projects/boarding-house-960ec/databases/"(default)"/documents/User?&key=AIzaSyB0Y1VLzTTN8AQ4lQlSadI_9VUziY4QfG8
```

For document that includes space, replace the space by ``%20``. E.g: Document ``User database`` will be ``User%20database``.
# Google Apps Script
## GET request

Script with Google Apps Script: **Example 2** in **HTTP requests.md: GET request** in ``JavaScript/Frameworks/Google Apps Script/``.

Send data with parameter ``id`` to Google Sheet with GET request: 

```sh
curl -X GET https://script.google.com/macros/s/AKfycby2CHiFSrC4tPpgKx1dscjO-wqM4zy0Px9X5OI3LPjqufQ4xNWdxiCC5U2oqniXrlBc/exec?id=13 
```

**Notice**: Google Apps Script is unable to handle the ``-d`` flag of ``curl``, sending like ``-d id=10`` will result in authentication error.

## POST request

Script with Google Apps Script: **Example 1** in **HTTP requests.md: POST request** in ``JavaScript/Frameworks/Google Apps Script/``.

Send data with parameter ``id`` to Google Sheet with POST request: 

```sh
curl -X POST https://script.google.com/macros/s/AKfycby2CHiFSrC4tPpgKx1dscjO-wqM4zy0Px9X5OI3LPjqufQ4xNWdxiCC5U2oqniXrlBc/exec -d id=13
```

**Notice**: Google Apps Script is unable to handle the querystring request with POST (like ``/exec?id=13``) as this will result in authentication error. POST request must be like ``-d id=10``.
