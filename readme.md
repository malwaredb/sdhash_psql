## Requirements:
* gcc
* Postgres installed with server development package

## Installation:
1. `git clone --recursive https://github.com/malwaredb/sdhash_psql.git`
2. Build SDHash:
    1. `cd sdhash`
    2. `make`
3. `make`
4. `sudo make install`

## Post installation
* Run `psql` as the admin user
* Run: `CREATE OR REPLACE FUNCTION sdhash_compare(TEXT, TEXT) RETURNS INTEGER AS 'sdhash_psql.so', 'pg_sdhash_compare' LANGUAGE 'c';`.

