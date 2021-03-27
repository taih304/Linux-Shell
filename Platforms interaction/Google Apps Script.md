### GET request

Script with Google Apps Script: **Example 2** in [HTTP requests.md: GET request](https://github.com/TranPhucVinh/JavaScript/blob/master/JavaScript%20frameworks/Google%20Apps%20Script/HTTP%20requests.md) in JavaScript.

Send data with parameter ``id`` to Google Sheet with GET request: 

```sh
curl -X GET https://script.google.com/macros/s/AKfycby2CHiFSrC4tPpgKx1dscjO-wqM4zy0Px9X5OI3LPjqufQ4xNWdxiCC5U2oqniXrlBc/exec?id=13 
```

**Notice**: Google Apps Script is unable to handle the ``-d`` flag of ``curl``, sending like ``-d id=10`` will result in authentication error.

### POST request

Script with Google Apps Script: **Example 1** in [HTTP requests.md: POST request](https://github.com/TranPhucVinh/JavaScript/blob/master/JavaScript%20frameworks/Google%20Apps%20Script/HTTP%20requests.md) in JavaScript.

Send data with parameter ``id`` to Google Sheet with POST request: 

```sh
curl -X POST https://script.google.com/macros/s/AKfycby2CHiFSrC4tPpgKx1dscjO-wqM4zy0Px9X5OI3LPjqufQ4xNWdxiCC5U2oqniXrlBc/exec -d id=13
```

**Notice**: Google Apps Script is unable to handle the querystring request with POST (like ``/exec?id=13``) as this will result in authentication error. POST request must be like ``-d id=10``.
