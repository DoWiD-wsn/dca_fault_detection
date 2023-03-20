##### LIBRARIES #####
# time (for sleep method)
import time


##### GLOBAL VARIABLES #####
# Maximum number of read attempts
MAX_ATTEMPTS = 10


#####
# @class    DS18B20
# @brief    DS18B20 temperature sensor
#
# Class for the DS18B20 temperature sensor.
class DS18B20(object):
    ###
    # The constructor.
    #
    # @param[in] self The object pointer.
    # @param[in] path Path to the sensor file handle
    def __init__(self, path):
        # @var __path
        # Objects own sensor path
        self.__path = path


    ###
    # Read the raw sensor data from the file.
    #
    # @param[in] self The object pointer.
    # @param[out] Raw sensor value in case of success; otherwise False.
    def __read_raw(self) :
        # Open given system bus address
        data = False
        try:
            sens = open(self.__path, 'r')
            data = sens.readlines()
            sens.close()
        except:
            return False
        else:
            return data


    ###
    # Read the temperature value in degrees Celsius.
    #
    # @param[in] self The object pointer.
    # @param[out] Temperature value (°C) in case of success; otherwise False.
    def read_temperature(self):
        data = self.__read_raw()
        if data:
            # Check if sensor is ready
            attempts = 0
            while ((len(data) < 1) or (data[0].strip()[-3:] != "YES") or ("00 00 00 00 00 00 00 00 00" in data[0])):
                time.sleep(0.25)
                data = self.__read_raw()
                attempts = attempts + 1
                if attempts >= MAX_ATTEMPTS:
                    return False
            # Check for temperature reading suffix
            equals_pos = data[1].find('t=')
            if equals_pos != -1:
                return (float(data[1][equals_pos+2:]) / 1000.0)
        else:
            return False