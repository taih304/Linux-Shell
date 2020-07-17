**``/getMe``**

```sh
curl -v -X GET https://api.telegram.org/bot1203028769:AAHsOT1BSv16Ds7WvZBGWy_-5oITZFlFcfA/getMe
```

**Send message with query string**

```sh
curl -X GET https://api.telegram.org/bot1203028769:AAHeZRPPItDZpSD-wTZIHZxEfBitWIA3YSw/sendMessage -d chat_id=998576382 -d text="Hello World"
```

**Send message with JSON data**

```sh
curl -X GET https://api.telegram.org/bot1203028769:AAHeZRPPItDZpSD-wTZIHZxEfBitWIA3YSw/sendMessage -d "{\"chat_id\": 998576382, \"text\": \"curl message\"}" --header "Content-Type:application/json"
```

``message.json`` 

```json
{
    "chat_id": 998576382,
    "text": "curl message"
}
```

```sh
curl -X GET https://api.telegram.org/bot1203028769:AAHeZRPPItDZpSD-wTZIHZxEfBitWIA3YSw/sendMessage -d @message.json --header "Content-Type:application/json"
```