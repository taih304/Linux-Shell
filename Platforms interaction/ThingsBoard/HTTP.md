## curl

### Telemetry

Send data to Live Demo server:

```sh
curl -v -X POST -d "{\"temperature\": 25}" https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/telemetry --header "Content-Type:application/json"
```

Send data to local server:

```sh
curl -v -X POST -d "{\"temperature\": 25}" 192.168.1.22:8000 --header "Content-Type:application/json"
```

``message.json``

```json
{
    "temperature": 25
}
```

```sh
curl -v -X POST -d @message.json 192.168.1.22:8000 --header "Content-Type:application/json"
```

Send data in while loop

```sh
while [ true ]
do
	curl -v -X POST -d "{\"temperature\": 25}" https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/telemetry --header "Content-Type:application/json"	
	sleep 1
done	
```

### RPC

Get return value from control widget of ThingsBoard dashboard

```sh
while [ true ]
do
	curl -v -X GET https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/rpc
	sleep 1
done >> temp.md
```
**Result**

```
{"id":122,"method":"setValue","params":true}{"id":123,"method":"setValue","params":false}{"id":125,"method":"setValue","params":true}{"id":127,"method":"setValue","params":false}
```

Parse the return to get the button status

```sh
while [ true ]
do
	curl -s -v -X GET https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/rpc > temp.json
	params=$(cat temp.json|jq '.params')
	echo $params
	sleep 1
done
```

## netcat

**Telemetry**

```sh
data="{'number':100}"
http_request="POST /api/v1/O0kt6xUl6cTGv9RM7M9P/telemetry HTTP/1.1\r\n"
http_request+="Host:demo.thingsboard.io\r\n"
http_request+="Content-Type: application/json\r\n"
http_request+="Content-Length: "
http_request+=${#data}
http_request+="\r\n\r\n"
http_request+=$data
http_request+="\r\n"

echo -e $http_request | nc demo.thingsboard.io 80
```

**RPC**

```sh
http_request="GET /api/v1/O0kt6xUl6cTGv9RM7M9P/rpc HTTP/1.1\r\n"
http_request+="Host:demo.thingsboard.io\r\n\r\n"

while [ true ]
do
    echo -e $http_request | nc demo.thingsboard.io 80
done    
```

### openssl

Performing telemetry and RPC with HTTPS Live demo ThingsBoard.

**Telemetry**

```sh
number=0

form_https_request(){
   data="{'number':$number}"
   https_request="POST /api/v1/O0kt6xUl6cTGv9RM7M9P/telemetry HTTP/1.1\r\n"
   https_request+="Host:demo.thingsboard.io\r\n"
   https_request+="Content-Type: application/json\r\n"
   https_request+="Content-Length: "
   https_request+=${#data}
   https_request+="\r\n\r\n"
   https_request+=$data
   https_request+="\r\n"
}

while true;
do
   form_https_request
   echo $https_request
   echo -e $https_request | openssl s_client -connect demo.thingsboard.io:443
   number=$((number+1))
   sleep 1
done
```

**RPC**

```sh
https_request="GET /api/v1/O0kt6xUl6cTGv9RM7M9P/rpc HTTP/1.1\r\n"
https_request+="Host:demo.thingsboard.io\r\n\r\n"

while [ true ]
do
    echo -e $https_request | openssl s_client -quiet -connect demo.thingsboard.io:443
done   
```

**Note**: Add ``-quiet`` to avoid printing out the unused SSL data which effect the reading proccess of the returned RPC responses.