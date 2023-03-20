# RPi Cluster Head Software Setup #

In the following, information on the preparations, prerequisites and the setup of the Raspberry Pi-based cluster head software can be found.
Additionally, links to further information are given.


## Prerequisites ##

* Make sure you have Python 3 and the required packeges (i.e., `pip` and `libmysqlclient`) installed:  
    `sudo apt install python3-dev python3-pip default-libmysqlclient-dev`  
    (Note: the XBee Python library is currently only compatible with Python 3.)

* The following software components are required to run XBee Python applications:
    * [**PySerial 3**](https://pyserial.readthedocs.io/en/latest/pyserial.html):
        * For authentication of BLE devices.
        * This module is automatically downloaded when you install the XBee Python library.
        * Alternatively, it can be installed via `pip` with:  
            `python3 -m pip install pyserial`
    * **MySQL Connector**:
        * Python needs a MySQL driver to access the remote MySQL database.
        * In the provided scripts, the [`mysql-connector`](https://dev.mysql.com/doc/connector-python/en/connector-python-installation-binary.html) module is used:  
            `python3 -m pip install mysql-connector-python`
        * Alternatively, you can use [`mysqlclient`](https://pypi.org/project/mysqlclient/):  
            `python3 -m pip install mysqlclient`  
            or [`PyMySQL`](https://pypi.org/project/PyMySQL/):  
            `python3 -m pip install PyMySQL`
    * [**SRP** (Secure Remote Password protocol)](https://pypi.org/project/srp/):
        * This module is automatically downloaded when you install the XBee Python library.
        * Alternatively, it can be installed via `pip` with:  
            `python3 -m pip install srp`
    * [**XBee Python library software**](https://xbplib.readthedocs.io/en/latest/):
        * The library can be automatically downloaded and installed with:  
            `python3 -m pip install digi-xbee`
        * Alternatively, you can get the source code of the library from [Github](https://github.com/digidotcom/xbee-python).

However, if you use the Xbee for the first time and want to configure fresh modules, it is advisable to use Digi's [XCTU](https://www.digi.com/products/embedded-systems/digi-xbee/digi-xbee-tools/xctu) tool (available for Windows, Linux, Mac), see below.


## Program Execution

The cluster head software (i.e., Python script) is divided in four stages with different main objectives, each.
The general flow of program execution is as follows:  
![Cluster Head Flowchart](../../media/flowchart/ftdca_flowchart-ch.svg)
