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