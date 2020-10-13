Install: ``sudo snap install heroku``

Main file to run: ``Procfile``

**Example content in Procfile**: ``web: node index.js``

### Working with Bash

```sh
$ heroku login
$ heroku git:remote -a control-smart-switch-17032019 #login project
$ heroku run bash #enter CLI
```
### Deploy

Deploy a Gitlab application on Heroku: Clone Gitlab repository then start deploying
