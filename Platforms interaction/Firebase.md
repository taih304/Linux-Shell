## Realtime Database

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

**Step 2**: Forming HTTP request

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

**Reference**: [Firebase Firestore REST example](https://stackoverflow.com/questions/46762667/firebase-firestore-rest-example)