```
Database => table => row
```

E.g

```
Database: Book
Schema: bookschema
table: bookschema.table1
```

# Install CLI

```
sudo apt-get update
sudo apt-get install postgresql postgresql-contrib
```

``sudo -u postgres psql``: Login to PostgreSQL CLI

# Database operations
``\conninfo``: View connction information
```sh
postgres=# \conninfo
You are connected to database "postgres" as user "postgres" via socket in "/var/run/postgresql" at port "5432".
```
``\l``: list all databases
```sh
username@hostname~$ sudo -u postgres psql
psql (12.15 (Ubuntu 12.15-0ubuntu0.20.04.1))
Type "help" for help.
postgres=# \l
                                  List of databases
   Name    |  Owner   | Encoding |   Collate   |    Ctype    |   Access privileges   
-----------+----------+----------+-------------+-------------+-----------------------
 postgres  | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | 
 template0 | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | =c/postgres          +
           |          |          |             |             | postgres=CTc/postgres
 template1 | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | =c/postgres          +
           |          |          |             |             | postgres=CTc/postgres
(3 rows)

postgres=# 
```

``\c database_name``: connect to database ``database_name``
```sh
postgres=# \c template1
You are now connected to database "template1" as user "postgres".
template1=# 
```
**There is no disconnect syntax in PostgreSQL**, simply connect to another database:
```sh
postgres=# \c template1
You are now connected to database "template1" as user "postgres".
template1=# \c postgres
You are now connected to database "postgres" as user "postgres".
postgres=# 
```

Create a new database: ``create database database_name;`` (**There must be ; at the end**)
```sh
postgres=# create database new_psql;
CREATE DATABASE
postgres-# \l
                                  List of databases
   Name    |  Owner   | Encoding |   Collate   |    Ctype    |   Access privileges   
-----------+----------+----------+-------------+-------------+-----------------------
 new_psql  | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | 
 postgres  | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | 
 template0 | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | =c/postgres          +
           |          |          |             |             | postgres=CTc/postgres
 template1 | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | =c/postgres          +
           |          |          |             |             | postgres=CTc/postgres
(4 rows)

postgres-# 
```
Delete database: ``drop database database_name;`` (**There must be ; at the end**)
```sh
postgres=# drop database recipe;
DROP DATABASE
postgres=# \l
                                  List of databases
   Name    |  Owner   | Encoding |   Collate   |    Ctype    |   Access privileges   
-----------+----------+----------+-------------+-------------+-----------------------
 new_psql  | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | 
 postgres  | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | 
 template0 | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | =c/postgres          +
           |          |          |             |             | postgres=CTc/postgres
 template1 | postgres | UTF8     | en_US.UTF-8 | en_US.UTF-8 | =c/postgres          +
           |          |          |             |             | postgres=CTc/postgres
(4 rows)
```
# Schema and table operations

``\dt``: list all existed table

``create schema schemaName``: create schema

``create table table2 (id integer, name char, address char);``: example of creating a table

``name char, address char`` will be ``name char(1), address char(1)``

**Add column to table**:

```sql
ALTER TABLE table_name
ADD column_name column-definition;
```

e.g: ``alter table area add farmname varchar(30);``

**Edit datatype**

```sql
ALTER TABLE table_name
ALTER COLUMN column_name datatype;
```

``DROP TABLE tableName;``: delete table

``DELETE FROM table_name WHERE condition;``

**View settings**

```sql
SELECT *
FROM pg_settings
```

**View port**

```sql
SELECT *
FROM pg_settings
WHERE name = 'port';
```

### Error: password authentication failed for user “postgres”

Inside the psql shell you can give the DB user postgres a password:

```sql
ALTER USER postgres PASSWORD 'newPassword';
```

We have database ``userdatabase``, table ``userdata``. Table ``userdata`` include ``id``, ``name``, ``password``, ``email``.

## Export
### Export table psql to csv

Table ``username``, csv ``database.csv``

``copy username to '/home/username/Documents/database.csv' delimiter ',' csv header;``

### Export local database to ``.sql``

First, login as user postgres

``sudo su - postgres``

``pg_dump --no-owner userdatabase > userdatabase.sql``

Then in directory: ``/var/lib/postgresql`` there is a database ``userdatabase.sql``.
# Heroku PostgreSQL

Go to the heroku project folder with ``smarthome.sql`` inside

```sql
psql postgres://goxpiutrohcbvf:9cbc0e791e84cadbf284d1af213736e1b8a739dcbb73edbb749407dd1e12a9b5@ec2-54-225-68-133.compute-1.amazonaws.com:5432/dbsul0tk44pki2 < smarthome.sql
```

Push to master branch of Heroku

```sh
git add .
git commit -m "message" 
git push heroku master
```

**View log**: To view heroku log when having problem

```
heroku login
heroku logs -a control-smart-switch-17032019
```

**Reference**: [Deploying the Hasura GraphQL Engine on Heroku Part 2 - integrate with an existing database](https://www.youtube.com/watch?v=LcHr-xYygaI)