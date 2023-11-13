# Linux distributions
* Linux vs BSD
* CentOS
* Armbian with Orange Pi
* [mangOH](mangOH)

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
# Documents 
## Google drive
**Connect Ubuntu PC to Google drive**

**Step 1**: Open ``Online Accounts`` application. Choose **Google**

**Step 2**: Enter username and password. When implementing in 20th March 2022, there is error [Sign in with Google temporarily disabled for this app](https://askubuntu.com/questions/1164372/sign-in-with-google-temporarily-disabled-for-this-app#). This error is global and can't be fixed even when Turn on less secure apps in Google account settings.
## AsciiDoc
AsciiDoc document can be generated to any chosen format like HTML, PDF,... by CLI or by AsciiDoc extension on VS code.

### CLI

```sh
asciidoctor -o test test.adoc
```

Generate file ``test`` from ``test.adoc``. ``test`` will then have HTML type.

To generate PDF file, use ``asciidoctor-pdf``

Install 

```sh
sudo gem install rouge #Install rouge first
```

```sh
sudo apt install ruby-asciidoctor-pdf
```

**Note**: If ``rouge`` is not installed, when running ``asciidoctor-pdf`` command, there will be error:

```
asciidoctor: WARNING: optional gem 'rouge' is not available. Functionality disabled.
asciidoctor: FAILED: required gem 'rouge' is not available. Processing aborted.
  Use --trace for backtrace
```

To generate the PDF file:

```sh
asciidoctor-pdf test.adoc
```

File ``test.pdf`` will be generate and will have a format like a PDF book.

### AsciiDoc extension

The AsciiDoc extension on VScode allows user to preview the adoc file and generate it to the chosen format.

To generate a adoc file to a chonse format, like PDF, in that ``adoc`` file, press ``Ctr+Shift+P`` or ``F1``, then choose **Export document as PDF**.
